
---

## Linux Terminal Commands Cheat Sheet

## 1. `echo`
- Displays a line of text or a string passed to it.
```bash
$ echo "hello"
```

## 2. `pwd` 
- Prints the current working directory.
```bash
$ pwd
```

## 3. `cd`
- Changes the directory.
  - `cd ..` : Move to the parent directory.
  - `cd ~` : Return to the home directory.
  - `cd -` : Switch to the previous directory.

```bash
$ cd ..     # parent directory
$ cd ~      # home directory
$ cd -      # previous directory
```

## 4. `ls`
- Lists files and directories.
  - `ls -a` : Shows all files, including hidden ones.
  - `ls -l` : Shows detailed file information.
  - `ls -la` : Shows detailed information for all files, including hidden ones.
  - `ls -R` : Recursively lists all files in directories and subdirectories.

```bash
$ ls
$ ls -a      # show hidden files
$ ls -l      # show detailed file info
$ ls -la     # detailed info including hidden files
$ ls -R      # recursively show all files
```

## 5. `touch`
- Creates a new file or updates the timestamp of an existing file.
```bash
$ touch newfile.txt
```

## 6. `file`
- Identifies the type of a file by analyzing its contents.
```bash
$ file server.js
```

## 7. `cat`
- Concatenates and displays the content of one or more files.
```bash
$ cat file1.txt
$ cat file1.txt file2.txt
```

## 8. `less`
- Opens a file for viewing and allows for scrolling through it.
- Navigation commands within `less`:  
  - `q` : Quit.
  - `g` : Go to the beginning.
  - `G` : Go to the end.
  - `/search` : Search within the file.
  - `h` : Help menu.
```bash
$ less /path/to/file.txt
```

## 9. `history`
- Displays the list of previously executed commands in the current terminal session.
```bash
$ history
```

## 10. `cp`
- Copies files or directories.
  - `cp -r` : Recursively copies directories.
  - `cp -i` : Interactive mode, asks before overwriting a file.
  - `*` : Wildcard to copy multiple files.

```bash
$ cp file1.txt /path/to/destination
$ cp -r dir1 /path/to/destination
$ cp -i file.txt /path/to/destination   # interactive copy
$ cp *.jpg /path/to/destination         # copy all jpg files
```

## 11. `mv`
- Moves or renames files or directories.
  - `mv -i` : Interactive mode, prompts before overwriting.

```bash
$ mv oldname.txt newname.txt   # rename file
$ mv file.txt /new/directory   # move file to new directory
$ mv -i file.txt /path         # interactive move
```

## 12. `mkdir`
- Creates directories.
  - `mkdir -p` : Creates parent and child directories in one command.

```bash
$ mkdir newdir                # create single directory
$ mkdir -p parentdir/subdir    # create parent and subdirectories
```

## 13. `rm`
- Removes files or directories.
  - `rm -f` : Forces removal without prompting.
  - `rm -r` : Recursively removes directories and their contents.

```bash
$ rm file.txt
$ rm -f file.txt          # force delete without prompt
$ rm -r directoryname     # recursive delete directory
```

## 14. `find`
- Searches for files and directories.
  - `find /path -name filename` : Finds a file by name.
  - `find /path -type d -name directoryname` : Finds a directory by name.

```bash
$ find /home -name "filename.txt"     # search for file by name
$ find /home -type d -name "dirname"  # search for directory
```

## 15. `help`
- Shows help for built-in bash commands.
```bash
$ help echo
$ echo --help
```

## 16. `man`
- Displays the manual page for a command.
```bash
$ man ls   # get manual for ls
```

## 17. `whatis`
- Provides a brief description of a command.
```bash
$ whatis cat
```

## 18. `alias`
- Creates a shortcut for a command.
  - `unalias` : Removes an alias.
```bash
$ alias ll='ls -la'
$ unalias ll
```

## 19. `exit`
- Exits the current shell session.
```bash
$ exit
```

---
