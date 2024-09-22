---

# Linux Terminal Commands Cheat Sheet - Part 2

## Table of Contents
1. [Input and Output Redirection](#input-and-output-redirection)
   - [1. Standard Output (`stdout`)](#1-standard-output-stdout)
   - [2. Standard Input (`stdin`)](#2-standard-input-stdin)
   - [3. Standard Error (`stderr`)](#3-standard-error-stderr)
   - [4. Combining `stdout` and `stderr`](#4-combining-stdout-and-stderr)
   - [5. `/dev/null`](#5-devnull)
   - [6. Pipes (`|`)](#6-pipes)
   - [7. `tee`](#7-tee)
2. [Environment Variables](#environment-variables)
   - [1. Viewing Environment Variables](#1-viewing-environment-variables)
   - [2. Modifying the `PATH` Variable](#2-modifying-the-path-variable)
3. [Text Processing Commands](#text-processing-commands)
   - [1. `join`](#1-join)
   - [2. `split`](#2-split)
   - [3. `sort`](#3-sort)
   - [4. `tr` (Translate)](#4-tr-translate)
   - [5. `uniq`](#5-uniq)
   - [6. `wc` (Word Count)](#6-wc-word-count)
   - [7. `nl` (Number Lines)](#7-nl-number-lines)
   - [8. `grep`](#8-grep)
   - [9. `cut`](#9-cut)
   - [10. `paste`](#10-paste)
   - [11. `head`](#11-head)
   - [12. `tail`](#12-tail)
   - [13. `expand`](#13-expand)
4. [Additional Tips](#additional-tips)

---

## Input and Output Redirection

### 1. Standard Output (`stdout`)
- **Description:** Redirects the output of a command to a file.
- **Overwrite Content:**
  ```bash
  $ echo "Hello World" > file.txt
  ```
  *Writes "Hello World" to `file.txt`, overwriting existing content.*

- **Append Content:**
  ```bash
  $ echo "Hello again" >> file.txt
  ```
  *Appends "Hello again" to `file.txt` without overwriting.*

### 2. Standard Input (`stdin`)
- **Description:** Redirects input from a file to a command.
- **Example:**
  ```bash
  $ cat < file.txt > index.html
  ```
  *Copies content from `file.txt` to `index.html` (same as `cp file.txt index.html`).*

### 3. Standard Error (`stderr`)
- **Description:** Redirects error messages separately from standard output.
- **Examples:**
  ```bash
  $ ls /home/nonexistent > output.txt
  ```
  *No content in `output.txt` because `ls` failed.*

  ```bash
  $ ls /home/nonexistent 2> error.txt
  ```
  *Error message is saved in `error.txt`.*

### 4. Combining `stdout` and `stderr`
- **Redirect both to the same file:**
  ```bash
  $ ls /home/nonexistent > all_output.txt 2>&1
  ```
- **Shorthand in Bash:**
  ```bash
  $ ls /fake/directory &> peanuts.txt
  ```
  *Redirects both `stdout` and `stderr` to `peanuts.txt`.*

### 5. `/dev/null`
- **Description:** A special file that discards all data written to it.
- **Usage:**
  ```bash
  $ command &> /dev/null
  ```
  *Suppresses all output and errors.*

### 6. Pipes (`|`)
- **Description:** Passes the output of one command as input to another.
- **Examples:**
  ```bash
  $ ls /etc/nginx | less
  ```
  *Views the contents of `/etc/nginx` one page at a time.*

  ```bash
  $ ls | tee mylist.txt
  ```
  *Displays the output of `ls` on the screen and saves it to `mylist.txt`.*

### 7. `tee`
- **Description:** Reads from `stdin` and writes to both `stdout` and files.
- **Example:**
  ```bash
  $ ls | tee mylist.txt
  ```
  *Displays the output of `ls` and saves it to `mylist.txt`.*

---

## Environment Variables

### 1. Viewing Environment Variables
- **Command:**
  ```bash
  $ env
  ```
  *Displays all current environment variables.*

- **Common Variables:**
  - `PATH`: Directories the system searches for executable files.
  - `PWD`: Current working directory.
  - `USER`: Current user name.

- **Accessing Variables:**
  ```bash
  $ echo $USER
  $ echo $HOME
  $ echo $PATH
  ```

### 2. Modifying the `PATH` Variable
- **Manual Installation Consideration:**
  - Programs installed manually may reside in non-standard directories not listed in `PATH`.
  - Adding these directories to `PATH` allows you to run the programs from anywhere.

- **Steps to Modify `PATH`:**
  1. **Open `.bashrc` with a text editor:**
     ```bash
     $ sudo nano ~/.bashrc
     ```
  2. **Add the following line at the end of the file:**
     ```bash
     export PATH="$PATH:/path/to/your/directory"
     ```
  3. **Save and Exit:**
     - Press `Ctrl+O` to save.
     - Press `Ctrl+X` to exit.
  4. **Apply Changes:**
     ```bash
     $ source ~/.bashrc
     ```
  5. **Verify `PATH`:**
     ```bash
     $ echo $PATH
     ```
     *Example Output:*
     ```
     /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/path/to/your/directory
     ```

---

## Text Processing Commands

### 1. `join`
- **Description:** Joins lines of two files on a common field.
- **Example Files:**
  - `file1.txt`:
    ```
    1 John
    2 Jane
    3 Mary
    ```
  - `file2.txt`:
    ```
    1 Doe
    2 Doe
    3 Sue
    ```
- **Command:**
  ```bash
  $ join file1.txt file2.txt
  ```
- **Output:**
  ```
  1 John Doe
  2 Jane Doe
  3 Mary Sue
  ```

### 2. `split`
- **Description:** Splits a file into smaller files based on the number of lines.
- **Example:**
  ```bash
  $ split -l 5 example.txt
  ```
  *Splits `example.txt` into files each containing 5 lines.*

### 3. `sort`
- **Description:** Sorts the lines of a file.
- **Basic Sort:**
  ```bash
  $ sort file1.txt
  ```
- **Reverse Sort:**
  ```bash
  $ sort -r file1.txt
  ```
- **Numeric Sort:**
  ```bash
  $ sort -n file1.txt
  ```

### 4. `tr` (Translate)
- **Description:** Translates or deletes characters.
- **Convert to Uppercase:**
  ```bash
  $ echo "hello world" | tr 'a-z' 'A-Z'
  ```
  *Output: `HELLO WORLD`*

- **From File to Uppercase:**
  ```bash
  $ tr 'a-z' 'A-Z' < file.txt > uppercase.txt
  ```

### 5. `uniq`
- **Description:** Removes duplicate lines. Only adjacent duplicates are removed.
- **Example File (`reading.txt`):**
  ```
  book
  book
  paper
  paper
  magazine
  ```
- **Basic Usage:**
  ```bash
  $ uniq reading.txt
  ```
  *Output:*
  ```
  book
  paper
  magazine
  ```

- **Count Occurrences:**
  ```bash
  $ uniq -c reading.txt
  ```
  *Output:*
  ```
  2 book
  2 paper
  1 magazine
  ```

- **Only Unique Lines:**
  ```bash
  $ uniq -u reading.txt
  ```
  *Output:*
  ```
  magazine
  ```

- **Handling Non-Adjacent Duplicates:**
  ```bash
  $ sort reading.txt | uniq
  ```
  *Ensures all duplicates are adjacent before removing.*

### 6. `wc` (Word Count)
- **Description:** Counts lines, words, and bytes in a file.
- **Basic Usage:**
  ```bash
  $ wc filename.txt
  ```
  *Output format: `lines words bytes filename.txt`*

- **Options:**
  - `-l`: Lines
  - `-w`: Words
  - `-c`: Bytes
  - `-m`: Characters
  - `-L`: Length of the longest line

- **Examples:**
  ```bash
  $ wc -l filename.txt    # Count lines
  $ wc -w filename.txt    # Count words
  $ wc -c filename.txt    # Count bytes
  ```

### 7. `nl` (Number Lines)
- **Description:** Adds line numbers to a file.
- **Example:**
  - **File (`file1.txt`):**
    ```
    i
    like
    turtles
    ```
  - **Command:**
    ```bash
    $ nl file1.txt
    ```
  - **Output:**
    ```
         1  i
         2  like
         3  turtles
    ```

### 8. `grep`
- **Description:** Searches for patterns within files or input streams.
- **Basic Search:**
  ```bash
  $ grep "word" filename.txt
  ```
- **Case-Insensitive Search:**
  ```bash
  $ grep -i "word" filename.txt
  ```
- **Combining with Other Commands:**
  ```bash
  $ env | grep -i USER
  $ ls /somedir | grep '\.txt$'
  ```
  *Finds all `.txt` files in `/somedir`.*

### 9. `cut`
- **Description:** Cuts out sections from each line of a file.
- **Extract 5th Character:**
  - **File (`sample.txt`):**
    ```
    jo is happy
    smith is a name
    how are you
    ```
  - **Command:**
    ```bash
    $ cut -c 5 sample.txt
    ```
  - **Output:**
    ```
    s
    h
    a
    ```

- **Extract Second Field (Default Delimiter: TAB):**
  - **File (`sample.txt`):**
    ```
    apple   banana   cherry
    dog     cat      mouse
    ```
  - **Command:**
    ```bash
    $ cut -f 2 sample.txt
    ```
  - **Output:**
    ```
    banana
    cat
    ```

- **Specify a Custom Delimiter:**
  ```bash
  $ cut -f 1 -d "e" sample.txt
  ```
  *Output:*
  ```
  appl
  dog     cat      mous
  ```

### 10. `paste`
- **Description:** Merges lines of files.
- **Basic Usage:**
  ```bash
  $ paste sample.txt
  ```
  *Same as `cat sample.txt`.*

- **Serial Mode (`-s`):**
  ```bash
  $ paste -s sample.txt
  ```
  *Combines all lines into a single line separated by tabs.*

- **Custom Delimiter (`-d`):**
  ```bash
  $ paste -d 'w' -s sample.txt
  ```
  *Uses 'w' as the delimiter.*

  ```bash
  $ paste -d '' -s sample.txt
  ```
  *No delimiter; lines are concatenated directly.*

### 11. `head`
- **Description:** Displays the first part of a file.
- **Basic Usage:**
  ```bash
  $ head file.txt
  ```
  *Shows the first 10 lines by default.*

- **Specify Number of Lines:**
  ```bash
  $ head -n 15 file.txt
  ```
  *Displays the first 15 lines.*

- **Common Use Case:**
  ```bash
  $ head /var/log/syslog
  ```

### 12. `tail`
- **Description:** Displays the last part of a file.
- **Basic Usage:**
  ```bash
  $ tail file.txt
  ```
  *Shows the last 10 lines by default.*

- **Specify Number of Lines:**
  ```bash
  $ tail -n 10 file.txt
  ```

- **Follow Mode (`-f`):**
  ```bash
  $ tail -f /var/log/syslog
  ```
  *Continuously monitors the file for new lines.*

- **Common Use Case:**
  ```bash
  $ tail /var/log/syslog
  ```

### 13. `expand`
- **Description:** Converts tabs to spaces, modifying TAB distance.
- **Basic Usage:**
  ```bash
  $ expand file.txt
  ```
- **Specify TAB Width (`-t`):**
  ```bash
  $ expand -t 50 file.txt
  ```
  *Sets TAB width to 50 spaces.*

- **Redirect Output to a File:**
  ```bash
  $ expand -t 30 file.txt > result.txt
  $ cat result.txt
  ```
  *Displays the expanded content.*

---

## Additional Tips

- **Combining Commands:**
  - Use pipes (`|`) to combine multiple commands for powerful text processing.
  - Example:
    ```bash
    $ cat file.txt | grep "search_term" | sort | uniq
    ```

- **Using Wildcards:**
  - Wildcards like `*` and `?` can be used with commands like `cp`, `mv`, and `rm` for batch operations.
  - Example:
    ```bash
    $ cp *.jpg /home/pete/Pictures
    ```

- **Safety with `rm`:**
  - Always double-check paths and filenames when using `rm` to prevent accidental data loss.
  - Use the `-i` flag for interactive deletion:
    ```bash
    $ rm -i file.txt
    ```

- **Creating Aliases:**
  - Simplify long commands by creating aliases in your `~/.bashrc` file.
  - Example:
    ```bash
    $ alias ll='ls -la'
    ```
  - **Remove an Alias:**
    ```bash
    $ unalias ll
    ```

- **Accessing Help:**
  - Use `man`, `whatis`, or `--help` to get more information about commands.
  - Example:
    ```bash
    $ man grep
    $ grep --help
    $ whatis grep
    ```

---

