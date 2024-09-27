To connect to a network on Ubuntu using only the command line, you'll be using `nmcli` or `netplan`, depending on the situation. Below are the steps to connect to both **Wi-Fi** and **Ethernet (wired)** networks via the command line interface (CLI) only.

---

### **1. Connecting to a Wi-Fi Network via CLI:**

You'll use `nmcli` (Network Manager Command Line Interface) for this process.

#### Step-by-Step:

1. **List available Wi-Fi networks:**
   ```bash
   nmcli device wifi list
   ```
   This command will show the available Wi-Fi networks (SSIDs).

2. **Connect to a specific Wi-Fi network:**
   ```bash
   nmcli device wifi connect <SSID> password <password>
   ```
   Replace `<SSID>` with the name of your Wi-Fi network and `<password>` with the Wi-Fi password.

   For example:
   ```bash
   nmcli device wifi connect "MyWiFiNetwork" password "mypassword"
   ```

3. **Check connection status:**
   After connecting, you can verify the connection by checking your device status:
   ```bash
   nmcli device status
   ```

4. **View IP Address (optional):**
   To check if you have successfully obtained an IP address, use:
   ```bash
   ip a
   ```
   This will show the network interfaces and their IP addresses.

---

### **2. Connecting to a Wired (Ethernet) Network via CLI:**

Connecting to a wired Ethernet network is usually automatic, but if it’s not connecting automatically, you can manually bring up the network interface using `nmcli`.

#### Step-by-Step:

1. **Check the status of your Ethernet interface:**
   ```bash
   nmcli device status
   ```
   This will show all network devices (both wired and wireless). Your Ethernet interface is likely `eth0` or similar.

2. **Bring up the Ethernet interface:**
   ```bash
   nmcli device connect eth0
   ```
   Replace `eth0` with the correct interface name if it's different.

3. **Check connection status:**
   ```bash
   nmcli device status
   ```

4. **View IP Address (optional):**
   To ensure you have an IP address:
   ```bash
   ip a
   ```

---

### **3. Manual Configuration for a Static IP using `netplan` (optional):**

If you need to configure a static IP address for either Wi-Fi or Ethernet, you'll need to edit the Netplan configuration file.

#### Step-by-Step:

1. **Open the Netplan configuration file:**
   ```bash
   sudo nano /etc/netplan/00-installer-config.yaml
   ```

2. **Edit the file for a static IP (Ethernet example):**
   Here's a sample configuration to assign a static IP address for `eth0`:
   ```yaml
   network:
     version: 2
     ethernets:
       eth0:
         dhcp4: false
         addresses: [192.168.1.100/24]
         gateway4: 192.168.1.1
         nameservers:
           addresses: [8.8.8.8, 8.8.4.4]
   ```

   For Wi-Fi, you need to modify the `wifis` section similarly.

3. **Apply the changes:**
   ```bash
   sudo netplan apply
   ```

4. **Verify the connection:**
   ```bash
   ip a
   ```

This should complete your network connection setup using CLI only on Ubuntu.