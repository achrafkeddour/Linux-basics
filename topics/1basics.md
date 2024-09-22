In Linux, commands are used to interact with the system and perform various tasks. Here are some fundamental categories and examples of basic Linux commands:

### 1. **File and Directory Management Commands**
   These commands help you navigate and manipulate files and directories.

   - `pwd` (Print Working Directory): Shows the current directory.
     ```bash
     $ pwd
     ```
   - `ls` (List): Lists the contents of a directory.
     ```bash
     $ ls
     $ ls -l   # Detailed list
     $ ls -a   # Includes hidden files
     ```
   - `cd` (Change Directory): Changes the current working directory.
     ```bash
     $ cd /path/to/directory
     $ cd ..   # Go up one directory
     ```
   - `mkdir` (Make Directory): Creates a new directory.
     ```bash
     $ mkdir new_folder
     ```
   - `rmdir` (Remove Directory): Removes an empty directory.
     ```bash
     $ rmdir empty_folder
     ```
   - `touch`: Creates a new empty file or updates the timestamp of an existing file.
     ```bash
     $ touch file.txt
     ```
   - `cp` (Copy): Copies files or directories.
     ```bash
     $ cp file1.txt file2.txt
     $ cp -r dir1/ dir2/  # Copies directories recursively
     ```
   - `mv` (Move): Moves or renames files or directories.
     ```bash
     $ mv old_name.txt new_name.txt
     ```
   - `rm` (Remove): Deletes files or directories.
     ```bash
     $ rm file.txt
     $ rm -r directory   # Deletes a directory recursively
     ```

### 2. **File Viewing and Editing**
   These commands allow you to view and manipulate file content.

   - `cat` (Concatenate): Displays the content of a file.
     ```bash
     $ cat file.txt
     ```
   - `less` and `more`: Scrolls through a file one page at a time.
     ```bash
     $ less file.txt
     $ more file.txt
     ```
   - `head`: Shows the first few lines of a file.
     ```bash
     $ head -n 10 file.txt   # Show first 10 lines
     ```
   - `tail`: Shows the last few lines of a file.
     ```bash
     $ tail -n 10 file.txt   # Show last 10 lines
     ```
   - `nano`, `vi`, `vim`: Simple text editors to edit files from the command line.
     ```bash
     $ nano file.txt
     $ vi file.txt
     ```

### 3. **File Permissions**
   These commands help you change and view file permissions.

   - `chmod` (Change Mode): Changes file permissions.
     ```bash
     $ chmod 755 file.txt   # Assigns read/write/execute permissions
     ```
   - `chown` (Change Owner): Changes the ownership of a file or directory.
     ```bash
     $ chown user:group file.txt
     ```

### 4. **Process Management**
   Commands for handling running processes.

   - `ps` (Process Status): Displays currently running processes.
     ```bash
     $ ps aux
     ```
   - `top`: Real-time display of system processes.
     ```bash
     $ top
     ```
   - `kill`: Terminates a process by its ID (PID).
     ```bash
     $ kill PID
     ```
   - `htop`: An enhanced version of `top` (may require installation).
     ```bash
     $ htop
     ```

### 5. **System Information**
   Commands to display system info like disk usage, memory, etc.

   - `df` (Disk Free): Shows disk space usage.
     ```bash
     $ df -h
     ```
   - `du` (Disk Usage): Displays disk usage of files and directories.
     ```bash
     $ du -sh folder/
     ```
   - `free`: Shows memory usage.
     ```bash
     $ free -h
     ```
   - `uname`: Displays system information.
     ```bash
     $ uname -a
     ```
   - `uptime`: Shows how long the system has been running.
     ```bash
     $ uptime
     ```

### 6. **Networking Commands**
   Commands to manage networking and connectivity.

   - `ping`: Sends a ping request to test network connectivity.
     ```bash
     $ ping google.com
     ```
   - `ifconfig` or `ip a`: Shows network interfaces.
     ```bash
     $ ifconfig
     $ ip a
     ```
   - `netstat`: Displays network connections.
     ```bash
     $ netstat -tuln
     ```
   - `curl` or `wget`: Fetches content from URLs.
     ```bash
     $ curl http://example.com
     $ wget http://example.com
     ```

### 7. **Search and Filter Commands**
   Commands to search for files or patterns within files.

   - `find`: Searches for files in a directory hierarchy.
     ```bash
     $ find /path -name "filename"
     ```
   - `grep`: Searches for patterns within files.
     ```bash
     $ grep "pattern" file.txt
     ```
   - `locate`: Quickly finds files by name (requires an updated database).
     ```bash
     $ locate filename
     ```
   - `sort`: Sorts lines in a file.
     ```bash
     $ sort file.txt
     ```
   - `wc` (Word Count): Counts lines, words, and characters in a file.
     ```bash
     $ wc file.txt
     ```

### 8. **Archiving and Compression**
   Commands to compress or extract files.

   - `tar`: Archives files and directories.
     ```bash
     $ tar -cvf archive.tar folder/   # Create archive
     $ tar -xvf archive.tar           # Extract archive
     ```
   - `gzip` and `gunzip`: Compresses and decompresses files.
     ```bash
     $ gzip file.txt
     $ gunzip file.txt.gz
     ```

### 9. **Package Management**
   Commands to install, remove, and manage software packages.

   - For **Debian-based** systems (e.g., Ubuntu):
     - `apt-get` or `apt`:
       ```bash
       $ sudo apt update
       $ sudo apt install package_name
       $ sudo apt remove package_name
       ```
   - For **Red Hat-based** systems (e.g., CentOS, Fedora):
     - `yum` or `dnf`:
       ```bash
       $ sudo yum install package_name
       $ sudo yum remove package_name
       ```

### 10. **User Management**
   Commands for managing users and groups.

   - `adduser`: Adds a new user.
     ```bash
     $ sudo adduser username
     ```
   - `passwd`: Changes a user's password.
     ```bash
     $ passwd username
     ```
   - `usermod`: Modifies user account settings.
     ```bash
     $ sudo usermod -aG groupname username
     ```
   - `deluser`: Deletes a user account.
     ```bash
     $ sudo deluser username
     ```

### 11. **Permissions and Ownership**
   Commands related to file access and user privileges.

   - `sudo`: Runs commands as superuser.
     ```bash
     $ sudo command
     ```
   - `chmod`: Modifies file permissions.
     ```bash
     $ chmod 755 file.txt
     ```
   - `chown`: Changes the ownership of files and directories.
     ```bash
     $ sudo chown user:group file.txt
     ```

### 12. **Other Useful Commands**
   - `history`: Shows command history.
     ```bash
     $ history
     ```
   - `alias`: Creates command shortcuts.
     ```bash
     $ alias ll='ls -la'
     ```
   - `clear`: Clears the terminal screen.
     ```bash
     $ clear
     ```

These are some of the essential Linux commands you’ll use frequently.
