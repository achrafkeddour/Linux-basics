### 1️⃣ **ls** – list directory contents

- `ls -l` → long listing with details
- `ls -a` → show hidden files
- `ls -h` → human-readable file sizes
- `ls -R` → recursive list of directories

---

### 2️⃣ **cd** – change current directory

- `cd /path` → go to specified directory
- `cd ..` → move one level up
- `cd ~` → go to home directory
- `cd -` → switch to previous directory

---

### 3️⃣ **pwd** – print working directory

- `pwd` → show current path
- `pwd -L` → logical path (resolves symlinks)
- `pwd -P` → physical path (no symlinks)
- `pwd --help` → show usage information

---

### 4️⃣ **mkdir** – make new directories

- `mkdir dir1` → create directory
- `mkdir -p a/b/c` → create nested directories
- `mkdir -v dir` → show created directories
- `mkdir -m 755 dir` → set permissions on creation

---

### 5️⃣ **rm** – remove files or directories

- `rm file` → delete file
- `rm -r dir` → delete directory recursively
- `rm -f file` → force delete without prompt
- `rm -i file` → ask before deleting

---

### 6️⃣ **cp** – copy files or directories

- `cp file1 file2` → copy file
- `cp -r dir1 dir2` → copy recursively
- `cp -i file` → prompt before overwrite
- `cp -v file` → show progress of copy

---

### 7️⃣ **mv** – move or rename files

- `mv file dir/` → move file
- `mv -i old new` → confirm overwrite
- `mv -v src dst` → show moved files
- `mv file newname` → rename file

---

### 8️⃣ **cat** – view file contents

- `cat file` → display file content
- `cat -n file` → show line numbers
- `cat -b file` → number nonempty lines
- `cat file1 file2 > merged` → combine files

---

### 9️⃣ **grep** – search text patterns

- `grep word file` → search for word
- `grep -i word file` → case-insensitive search
- `grep -r word dir` → search recursively
- `grep -n word file` → show line numbers

---

### 🔟 **chmod** – change file permissions

- `chmod 755 file` → set rwxr-xr-x
- `chmod +x script.sh` → add execute permission
- `chmod -R 644 dir` → recursive change
- `chmod u+w file` → add write for user

---

### 11️⃣ **chown** – change file ownership

- `chown user file` → change owner
- `chown user:group file` → change both
- `chown -R user dir` → recursive change
- `chown --reference=file1 file2` → match permissions

---

### 12️⃣ **chgrp** – change group ownership

- `chgrp group file` → change group
- `chgrp -R group dir` → recursive group change
- `chgrp --reference=file1 file2` → match group
- `chgrp -v group file` → verbose mode

---

### 13️⃣ **sudo** – run as superuser

- `sudo command` → run with root privileges
- `sudo -i` → open root shell
- `sudo -u user cmd` → run as another user
- `sudo visudo` → edit sudoers file safely

---

### 14️⃣ **apt** – Debian package manager

- `apt update` → refresh package lists
- `apt upgrade` → upgrade installed packages
- `apt install pkg` → install package
- `apt remove pkg` → uninstall package

---

### 15️⃣ **yum** – RedHat package manager

- `yum install pkg` → install package
- `yum remove pkg` → remove package
- `yum update` → update all packages
- `yum search term` → search for package

---

### 16️⃣ **ps** – show running processes

- `ps` → current shell processes
- `ps -e` → all processes
- `ps -f` → full format listing
- `ps aux` → detailed all users’ processes

---

### 17️⃣ **kill** – terminate processes

- `kill PID` → stop specific process
- `kill -9 PID` → force kill process
- `kill -l` → list all signals
- `killall name` → kill by process name

---

### 18️⃣ **top** – real-time process monitor

- `top` → launch monitor
- `top -u user` → filter by user
- `top -n 1` → single update only
-`top -o %MEM` → sort by memory usage

---

### 19️⃣ **df** – show disk space usage

- `df` → display all mounted disks
- `df -h` → human-readable sizes
- `df -T` → show filesystem types
- `df -i` → show inode usage

---

### 20️⃣ **du** – show directory usage
- `du` → disk usage by directory
- `du -h` → human-readable sizes
- `du -s` → summary only
- `du -a` → include files

---

### 21️⃣ **man** – show manual pages

- `man ls` → help for command
- `man -k keyword` → search manuals
- `man -f cmd` → brief description
- `man 5 config` → view specific section

---

### 22️⃣ **ssh** – connect to remote host

- `ssh user@host` → connect via SSH
- `ssh -p 2222 host` → custom port
- `ssh -i key.pem host` → use identity file
- `ssh -v host` → verbose connection info

---

### 23️⃣ **scp** – secure copy over SSH

- `scp file user@host:/path` → upload file
- `scp user@host:file .` → download file
- `scp -r dir host:/path` → recursive copy
- `scp -P 2222 file host:` → specify port

---

### 24️⃣ **tar** – archive files

`tar -cvf file.tar dir/` → create archive
`tar -xvf file.tar` → extract files
`tar -tvf file.tar` → list contents
`tar -czvf file.tar.gz dir/` → compress archive

---

### 25️⃣ **gzip** – compress files

`gzip file` → compress file
`gzip -d file.gz` → decompress
`gzip -v file` → verbose mode
`gzip -r dir` → compress recursively

---

### 26️⃣ **gunzip** – decompress gzip files

`gunzip file.gz` → extract file
`gunzip -v file.gz` → verbose
`gunzip -c file.gz > out` → output to file
`gunzip -k file.gz` → keep original file

---

### 27️⃣ **ping** – test network connectivity

`ping host` → send packets
`ping -c 4 host` → 4 packets only
`ping -i 2 host` → interval 2s
`ping -t host` → continuous (Windows)

---

### 28️⃣ **ifconfig** – network interface info

`ifconfig` → show interfaces
`ifconfig eth0 up` → enable interface
`ifconfig eth0 down` → disable interface
`ifconfig eth0 192.168.1.10` → assign IP

---

### 29️⃣ **netstat** – network statistics

`netstat -t` → TCP connections
`netstat -u` → UDP connections
`netstat -l` → listening ports
`netstat -r` → routing table

---

### 30️⃣ **wget** – download from web

`wget URL` → download file
`wget -c URL` → resume download
`wget -r URL` → recursive download
`wget -O file URL` → save with name

---

### 31️⃣ **curl** – transfer data URLs

`curl URL` → fetch content
`curl -O URL` → save file
`curl -I URL` → show headers
`curl -d data URL` → send POST request

---

### 32️⃣ **history** – show command history

`history` → show all commands
`history -c` → clear history
`!n` → rerun command number n
`history | grep word` → search history

---

### 33️⃣ **find** – search files/directories

`find /path -name file` → search by name
`find . -type d` → find directories
`find . -size +10M` → larger than 10 MB
`find . -exec cmd {} \;` → execute on results

---

### 34️⃣ **locate** – quick file search

`locate file` → find paths fast
`locate -i name` → case-insensitive search
`locate -c name` → count results
`updatedb` → refresh locate database

---

### 35️⃣ **tail** – show end of file

`tail file` → last 10 lines
`tail -n 20 file` → last 20 lines
`tail -f file` → follow live updates
`tail -q file1 file2` → suppress headers

---

### 36️⃣ **head** – show beginning of file

`head file` → first 10 lines
`head -n 5 file` → first 5 lines
`head -c 100 file` → first 100 bytes
`head -q file1 file2` → suppress headers

---

### 37️⃣ **sort** – sort text lines

`sort file` → sort alphabetically
`sort -r file` → reverse order
`sort -n file` → numeric sort
`sort -u file` → remove duplicates

---

### 38️⃣ **ssh-keygen** – generate SSH key pairs

`ssh-keygen` → start key creation
`ssh-keygen -t rsa` → RSA key type
`ssh-keygen -b 4096` → key length
`ssh-keygen -f keyfile` → specify filename

---

### 39️⃣ **sed** – stream text editor

`sed 's/a/b/' file` → replace first a→b
`sed -i 's/a/b/g' file` → replace in place
`sed -n '5p' file` → print line 5
`sed '/pattern/d' file` → delete matching lines

---

### 40️⃣ **awk** – text pattern scanner

`awk '{print $1}' file` → print first column
`awk '/pat/ {print $0}' file` → match pattern
`awk -F: '{print $1}' file` → custom delimiter
`awk '{sum+=$2} END {print sum}' file` → sum field

---

### 41️⃣ **cut** – extract text fields

`cut -d':' -f1 file` → first field
`cut -c1-5 file` → first 5 chars
`cut -f2 file` → second tab field
`cut -d',' -f1,3 file` → select columns

---

### 42️⃣ **wc** – word, line, char count

`wc file` → show counts
`wc -l file` → line count
`wc -w file` → word count
`wc -c file` → byte count

---

### 43️⃣ **diff** – compare files line by line

`diff file1 file2` → show differences
`diff -y f1 f2` → side-by-side view
`diff -q f1 f2` → brief output
`diff -r dir1 dir2` → compare directories

