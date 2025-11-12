### 44️⃣ **ln** – créer des liens (symboliques ou physiques)

* `ln target linkname` → créer lien physique
* `ln -s target linkname` → créer lien symbolique (symlink)
* `ln -f target linkname` → écraser lien existant
* `ln --help` → afficher l'aide

---

### 45️⃣ **alias** – définir des alias de commande

* `alias ll='ls -la'` → créer un alias temporaire pour la session
* `alias` → lister les alias définis
* `unalias ll` → supprimer un alias
* Ajouter à `~/.bashrc` ou `~/.zshrc` pour alias permanents

---

### 46️⃣ **echo** – afficher du texte sur la sortie standard

* `echo "Bonjour"` → affiche Bonjour
* `echo $HOME` → affiche la valeur d'une variable d'environnement
* `echo -n "Sans saut de ligne"` → pas de saut de ligne final
* `echo -e "Ligne1\nLigne2"` → interpréter les échappements

---

### 47️⃣ **date** – afficher ou définir la date et l'heure

* `date` → afficher la date/heure courante
* `date "+%Y-%m-%d %H:%M:%S"` → format personnalisé
* `sudo date -s "2025-11-12 10:00"` → définir la date (nécessite privilèges)
* `date --help` → aide

---

### 48️⃣ **clear** – effacer l'écran du terminal

* `clear` → effacer l'affichage courant
* `Ctrl+L` → raccourci équivalent dans beaucoup de shells

---

### 49️⃣ **nmap** – scanner de ports et découverte réseau

* `nmap --help` → aide et options
* `nmap -sS 192.168.1.0/24` → découverte basique (scan SYN)
* `nmap -p 22,80 host` → scanner ports spécifiques
* `nmap -A host` → détection avancée (OS/services) — utilisation responsable requise

---

### 50️⃣ **dig** – requêtes DNS et diagnostics

* `dig example.com` → résolution A par défaut
* `dig @8.8.8.8 example.com MX` → utiliser un serveur DNS précis et interroger MX
* `dig +short example.com` → sortie condensée
* `dig --help` → aide

---

### 51️⃣ **whois** – requête WHOIS pour informations de domaine

* `whois example.com` → informations d'enregistrement du domaine
* `whois --help` → options disponibles

---

### 52️⃣ **host** – résolution DNS simple (lookup)

* `host example.com` → obtenir enregistrements A/AAAA
* `host -t MX example.com` → demander type d'enregistrement spécifique
* `host --help` → aide

---

### 53️⃣ **traceroute** – afficher le chemin réseau vers une destination

* `traceroute example.com` → tracer la route réseau
* `traceroute -I host` → utiliser ICMP au lieu d'UDP
* `traceroute --help` → aide

---

### 54️⃣ **route** – voir/modifier la table de routage IP

* `route -n` → afficher table de routage (numérique)
* `sudo route add -net 10.0.0.0/24 gw 192.168.1.1` → ajouter une route (privilèges requis)
* `route --help` → aide

---

### 55️⃣ **iptables** – configuration du pare-feu et filtrage de paquets

* `sudo iptables -L -v` → lister les règles actuelles
* `sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT` → ajouter règle (exemple)
* `sudo iptables-save` → sauvegarder règles
* `iptables --help` → aide (man iptables pour détails)

---

### 56️⃣ **tcpdump** – capture et analyse de paquets en ligne de commande

* `sudo tcpdump -i eth0` → capturer paquets sur interface eth0
* `sudo tcpdump -n host 1.2.3.4` → filtrer par hôte (pas de résolution DNS)
* `sudo tcpdump -w capture.pcap` → écrire capture dans un fichier pcap
* `tcpdump --help` → aide

---

### 57️⃣ **wireshark** – analyseur de paquets réseau (interface graphique)

* `wireshark` → lancer l'interface graphique (nécessite environnement graphique)
* `wireshark -r capture.pcap` → ouvrir un fichier pcap
* Utiliser prudemment et légalement (données sensibles)

---

### 58️⃣ **nc** (netcat) – connexions TCP/UDP et redirections

* `nc -l 1234` → écouter sur le port 1234 (TCP)
* `nc host 80` → se connecter au port 80
* `echo "hello" | nc -q 1 host 1234` → envoyer données et quitter
* `nc --help` → aide

---

### 59️⃣ **metasploit** – framework d’exploitation et tests d’intrusion

* `msfconsole` → lancer l'interface Metasploit
* `msfconsole --help` → options
* Outil avancé pour tests de sécurité dans un cadre légal et contrôlé

---

### 60️⃣ **hydra** – outil de force brute pour authentifications réseau

* `hydra --help` → options et aide
* Utilisation uniquement dans un contexte légal (audits autorisés)

---

### 61️⃣ **john** (John the Ripper) – craquage de mots de passe

* `john --help` → options
* `john --wordlist=rockyou.txt hashfile` → exemple d'utilisation (usage éthique seulement)

---

### 62️⃣ **aircrack-ng** – suite pour audit et cassage de clés Wi-Fi

* `airmon-ng` → outils de gestion d'interface sans fil (suite aircrack)
* `aircrack-ng --help` → aide et options
* Usage légitime uniquement (tests sur vos propres réseaux ou avec autorisation)

---

### 63️⃣ **reaver** – attaques contre WPS pour récupérer le PIN

* `reaver --help` → options (outil sensible, utilisé pour tests de sécurité)
* À utiliser uniquement dans un cadre légal et éthique

---

### 64️⃣ **sqlmap** – automatisation des tests d'injection SQL

* `sqlmap --help` → options et documentation
* `sqlmap -u "http://example.com/page.php?id=1" --batch` → exemple d'exécution (usage légal seulement)

---

### 65️⃣ **enum4linux** – énumération d’informations SMB/Windows

* `enum4linux -a target` → exécute plusieurs checks SMB (informations)
* `enum4linux --help` → aide

---

### 66️⃣ **nikto** – scanner de vulnérabilités pour serveurs web

* `nikto -h http://example.com` → scan basique
* `nikto --help` → options

---

### 67️⃣ **dirb** – recherche de répertoires/fichiers web par wordlists

* `dirb http://example.com /path/to/wordlist.txt` → lancer un scan basique
* `dirb --help` → aide

---

### 68️⃣ **wpscan** – scanner de vulnérabilités pour WordPress

* `wpscan --help` → options et usage
* `wpscan --url http://example.com --enumerate u` → exemple (usage autorisé seulement)

---

### 69️⃣ **burp** – proxy d’interception et suite de tests web

* Lancer Burp Suite via son interface graphique (`burpsuite`)
* Configurer le navigateur pour utiliser le proxy local (127.0.0.1:8080)
* Outil puissant pour tests d'application web en environnement contrôlé

---

### 70️⃣ **sqlninja** – exploitation d’injections SQL ciblant MS SQL

* `sqlninja --help` → options (outil spécialisé)
* À utiliser uniquement dans des audits autorisés

---

### 71️⃣ **ettercap** – attaques MITM et interception sur LAN (outil d’analyse/interception)

* `ettercap -G` → interface graphique
* `ettercap --help` → options
* Usage restreint et légal seulement (sur vos réseaux ou avec permission)

---

### 72️⃣ **snort** – système de détection d'intrusion (IDS)

* `snort -c /etc/snort/snort.conf -i eth0` → démarrer Snort avec config sur interface
* `snort --help` → aide et options

---

### 73️⃣ **openvas** – scanner d’évaluation de vulnérabilités

* `openvas-start` / interface web (selon installation)
* Utilisé pour audits de vulnérabilités dans un cadre autorisé

---

### 74️⃣ **armitage** – interface graphique pour Metasploit

* `armitage` → lancer GUI (si installé)
* Fournit visualisation et gestion d’activités Metasploit

---

### 75️⃣ **xsser** – framework d’exploitation XSS (Cross-Site Scripting)

* `xsser --help` → options
* Outil pour recherche/évaluation de vulnérabilités XSS (usage éthique)

---

### 76️⃣ **dirbuster** – découverte de répertoires/fichiers web par brute force

* Lancer via interface graphique ou `dirbuster` selon installation
* Utiliser des wordlists adaptées; usage légitime requis

---

### 77️⃣ **hashcat** – craquage de hachages (GPU/CPU)

* `hashcat --help` → options et modes
* `hashcat -m 0 -a 0 hashfile wordlist` → exemple (usage légal seulement)

---

### 78️⃣ **volatility** – analyse forensique de la mémoire vive (RAM)

* `volatility -f memdump.raw --profile=Win7SP1x64 pslist` → exemple d'utilisation (profil à adapter)
* `volatility --help` → aide

---

### 79️⃣ **autopsy** – interface graphique pour investigations forensiques

* `autopsy` → lancer l'interface web/GUI
* Interface pour analyser disques, fichiers et artefacts forensiques

---

### 80️⃣ **gobuster** – scanner de répertoires et sous-domaines par wordlists

* `gobuster dir -u http://example.com -w wordlist.txt` → scan de répertoires
* `gobuster dns -d example.com -w subdomains.txt` → recherche de sous-domaines
* `gobuster --help` → options

---

### 81️⃣ **dnsrecon** – reconnaissance et audit DNS

* `dnsrecon -d example.com` → scan DNS basique
* `dnsrecon --help` → aide

---

### 82️⃣ **steghide** – cacher/extraire des données (stéganographie)

* `steghide embed -cf cover.jpg -ef secret.txt` → cacher `secret.txt` dans `cover.jpg`
* `steghide extract -sf cover.jpg` → extraire (mot de passe requis si utilisé)
* `steghide --help` → options

---

### 83️⃣ **stegcracker** – attaque par force brute sur fichiers stéganographiés

* `stegcracker cover.jpg wordlist.txt` → tenter bruteforce (usage éthique)
* `stegcracker --help` → aide

---

### 84️⃣ **sshuttle** – tunnel VPN léger via SSH (proxy réseau)

* `sshuttle -r user@sshserver 0/0` → rediriger le trafic via le serveur SSH
* `sshuttle --help` → options

---

### 85️⃣ **mitmproxy** – proxy d’interception HTTP/HTTPS en ligne de commande

* `mitmproxy` → interface interactive en terminal
* `mitmweb` → interface web
* `mitmproxy --help` → options

---

### 86️⃣ **hash-identifier** – identifier le type de hachage

* `hash-identifier` → lancer l’outil interactif (selon installation)
* Utilisé pour reconnaître format de hachage (MD5, SHA1, etc.)

---

### 87️⃣ **samdump2** – extraction des hachages SAM (Windows)

* `samdump2 SYSTEM SAM > hashes.txt` → extraire hachages (nécessite accès)
* Outil pour analystes forensiques et audits autorisés

---

### 88️⃣ **radare2** – framework de reverse engineering et analyse binaire

* `r2 -h` → aide
* `r2 -A binary` → analyser un binaire (commande d'exemple)
* Puissant pour l’analyse binaire et reverse engineering

---

### 89️⃣ **airgeddon** – outil d’audit sans fil multi-fonction (Wi-Fi)

* `airgeddon` → lancer l'interface textuelle
* Fournit plusieurs modules pour audit Wi-Fi (usage responsable)

