# Linux Permissions Course
---

## Table of Contents

1. [Understanding `ls -l` Output](#understanding-ls-l-output)
2. [Users, Groups, and Others](#users-groups-and-others)
3. [Managing Groups](#managing-groups)
4. [Changing Permissions with `chmod`](#changing-permissions-with-chmod)
    - [Symbolic Mode](#symbolic-mode)
    - [Numeric Mode](#numeric-mode)
5. [Changing Ownership with `chown` and `chgrp`](#changing-ownership-with-chown-and-chgrp)
6. [Special Permissions](#special-permissions)
    - [Set User ID (SUID)](#set-user-id-suid)
    - [Set Group ID (SGID)](#set-group-id-sgid)
7. [Understanding User IDs](#understanding-user-ids)
    - [Real User ID (RUID)](#real-user-id-ruid)
    - [Effective User ID (EUID)](#effective-user-id-euid)
    - [Saved Set User ID (SUID)](#saved-set-user-id-suid)
8. [Practical Examples and Use Cases](#practical-examples-and-use-cases)
9. sticky-bit
---

## Understanding `ls -l` Output

The `ls -l` command provides a detailed list of files and directories, displaying their permissions, ownership, and other attributes.

### Example Output

```bash
$ ls -l
drwxr-xr-x 2 pete penguins 4096 Dec 1 11:45 Desktop/
-rw-r--r-- 1 achraf achraf  123 Sep 19 11:39 file.txt
```

### Breakdown of Permissions

```
d | rwx | r-x | r-x
```

- **d**: Indicates the item is a directory. A `-` instead of `d` denotes a file.
- **rwx**: Permissions for the **owner** (user) — Read, Write, Execute.
- **r-x**: Permissions for the **group** — Read and Execute.
- **r-x**: Permissions for **others** — Read and Execute.

### Ownership Details

- **Owner (User)**: The person who created the file or directory or to whom it is assigned.
- **Group**: A collection of users. Each file is assigned to a specific group, and group members share permissions.
- **Others**: Refers to all other users on the system who are neither the owner nor part of the group.

---

## Users, Groups, and Others

Understanding the distinction between users, groups, and others is fundamental to managing permissions in Linux.

- **User (Owner)**: The primary owner of the file or directory.
- **Group**: A set of users who share the same access permissions.
- **Others**: All other users not classified as the owner or part of the group.

---

## Managing Groups

Groups allow you to manage permissions for multiple users efficiently.

### 1. Create a Group

To create a new group named `developers`:

```bash
sudo groupadd developers
```

### 2. Add Users to the Group

Add users `achraf` and `lakhour` to the `developers` group:

```bash
sudo usermod -aG developers achraf
sudo usermod -aG developers lakhour
```

### 3. Remove Users from the Group

Remove user `achraf` from the `developers` group:

```bash
sudo deluser achraf developers
```

*Alternatively, you can manually edit the `/etc/group` file to manage group memberships.*

### 4. Change Group Ownership of a File

Change the group ownership of `file.txt` to `developers`:

```bash
sudo chgrp developers file.txt
```

### 5. Change Owner and Group Ownership Simultaneously

Change both the user and group ownership of a file:

```bash
sudo chown newuser:newgroup filename
```

---

## Changing Permissions with `chmod`

The `chmod` command is used to modify the permissions of files and directories.

### Symbolic Mode

- **Syntax**: `chmod [who][operator][permissions] filename`
- **Who**: `u` (user), `g` (group), `o` (others), `a` (all)
- **Operator**: `+` (add), `-` (remove), `=` (set exactly)
- **Permissions**: `r` (read), `w` (write), `x` (execute)

#### Examples

1. **Add Execute Permission for User**

    ```bash
    chmod u+x myfile
    ```

    *Adds execute permission for the user on `myfile`.*

2. **Remove All Permissions for User, Group, and Others**

    ```bash
    chmod ugo-rwx testing
    ls -l testing
    ```

    **Output:**
    ```
    ---------- 1 achraf achraf 19 سبتمبر 11 11:39 testing
    ```

3. **Add Read, Write, Execute Permissions for User and Group**

    ```bash
    chmod ug+rwx testing
    ls -l testing
    ```

    **Output:**
    ```
    -rwxrwx--- 1 achraf achraf 19 سبتمبر 11 11:39 testing
    ```

4. **Add Read, Write, Execute Permissions for Others**

    ```bash
    chmod o+rwx testing
    ls -l testing
    ```

    **Output:**
    ```
    -rwxrwxrwx 1 achraf achraf 19 سبتمبر 11 11:39 testing
    ```

### Numeric Mode

- **Syntax**: `chmod [permissions] filename`
- **Permissions**: Represented by three digits, each ranging from 0 to 7.
    - `r` = 4
    - `w` = 2
    - `x` = 1

Each digit represents the permissions for **user**, **group**, and **others**, respectively.

#### Examples

1. **Set Permissions to 777 (rwxrwxrwx)**

    ```bash
    chmod 777 testing
    ls -l testing
    ```

    **Output:**
    ```
    -rwxrwxrwx 1 achraf achraf 19 سبتمبر 11 11:39 testing
    ```

2. **Set Permissions to 000 (----------)**

    ```bash
    chmod 000 testing
    ls -l testing
    ```

    **Output:**
    ```
    ---------- 1 achraf achraf 19 سبتمبر 11 11:39 testing
    ```

---

## Changing Ownership with `chown` and `chgrp`

### `chown` - Change Ownership

The `chown` command changes the ownership of a file or directory.

#### Change User Ownership

```bash
sudo chown mario script
ls -l script
```

**Output:**
```
-rwxrw-r-- 1 mario achraf 23 سبتمبر 11 12:01 script
```

### `chgrp` - Change Group Ownership

The `chgrp` command changes the group ownership of a file or directory.

#### Change Group Ownership

```bash
sudo chgrp developers script
ls -l script
```

**Output:**
```
-rwxrw-r-- 1 mario developers 23 سبتمبر 11 12:01 script
```

### Change Both User and Group Ownership

```bash
sudo chown patty:whales myfile
```

---

## Special Permissions

Linux provides special permission bits that offer enhanced control over file and directory access.

### Set User ID (SUID)

**SUID** allows users to execute a file with the permissions of the file owner rather than their own.

#### Setting SUID

```bash
sudo chmod u+s file
```

#### Verifying SUID

```bash
ls -l file
```

**Possible Output:**
```
-rwSr-xr-x 1 root root 1234 Dec 1 11:45 file
```

- **Upper `S`** indicates that the execute bit is **not** set.
- **Lower `s`** indicates that the execute bit is set.

To set both SUID and execute permission:

```bash
sudo chmod u+x file
ls -l file
```

**Output:**
```
-rwsr-xr-x 1 root root 1234 Dec 1 11:45 file
```

#### What SUID Means

When a file has the SUID bit set, executing the file runs it with the permissions of the file owner. This is useful for tasks that require elevated privileges.

**Example: `passwd` Command**

The `passwd` command modifies the `/etc/shadow` file, which is owned by `root`. To allow users to change their passwords without granting them full root access, the `passwd` executable has the SUID bit set.

```bash
ls -l /usr/bin/passwd
```

**Output:**
```
-rwsr-xr-x 1 root root 47032 Dec 1 11:45 /usr/bin/passwd
```

### Set Group ID (SGID)

**SGID** allows users to execute a file with the permissions of the group owner.

#### Setting SGID

```bash
sudo chmod g+s myfile
```

#### Verifying SGID

```bash
ls -l myfile
```

**Possible Output:**
```
-rwxr-sr-x 1 root tty 19024 Dec 14 11:45 myfile
```

#### Modifying SGID

- **Add SGID:**
    ```bash
    sudo chmod g+s myfile
    sudo chmod 2555 myfile
    ```
- **Remove SGID:**
    ```bash
    sudo chmod g-s myfile
    ```

---

## Understanding User IDs

Every process in Linux is associated with three User IDs that determine its privileges.

### 1. Real User ID (RUID)

- **Definition**: Identifies the user who created or owns the process.
- **Behavior**: Remains constant unless altered by specific system calls like `setuid()`.

### 2. Effective User ID (EUID)

- **Definition**: Determines the permissions for accessing or modifying files.
- **Behavior**: If running a setuid program, the EUID changes to the file owner's UID.

### 3. Saved Set User ID (SUID)

- **Definition**: Stores the previous EUID when privileges are temporarily changed.
- **Behavior**: Allows a process to drop and regain elevated privileges securely.

#### Example: Managing User IDs in C

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    // Get and print the real, effective, and saved user IDs
    int real_uid = getuid();
    int effective_uid = geteuid();
    printf("Initial Real UID: %d\n", real_uid); // e.g., 1000
    printf("Initial Effective UID: %d\n", effective_uid); // e.g., 0

    // Drop privileges by setting the effective UID to the real UID 
    seteuid(real_uid); 
    printf("After dropping privileges (Effective UID): %d\n", geteuid()); // e.g., 1000

    // Regain privileges by setting the effective UID back to original
    seteuid(effective_uid);  
    printf("After regaining privileges (Effective UID): %d\n", geteuid()); // e.g., 0

    return 0;
}
```

---

## Practical Examples and Use Cases

### Example 1: Restricting Access to a Directory

1. **Create a Group:**

    ```bash
    sudo groupadd developers
    ```

2. **Add Users to the Group:**

    ```bash
    sudo usermod -aG developers achraf
    sudo usermod -aG developers lakhour
    ```

3. **Change Group Ownership of the Directory:**

    ```bash
    sudo chgrp developers /path/to/directory
    ```

4. **Set Permissions:**

    ```bash
    sudo chmod 770 /path/to/directory
    ```

    *This grants full permissions to the user and group, and no permissions to others.*

### Example 2: Using SUID for Elevated Tasks

1. **Set SUID on a Script:**

    ```bash
    sudo chmod u+s /usr/local/bin/myscript
    ```

2. **Verify SUID:**

    ```bash
    ls -l /usr/local/bin/myscript
    ```

    **Output:**
    ```
    -rwsr-xr-x 1 root root 1234 Dec 1 11:45 myscript
    ```

    *Now, when any user executes `myscript`, it runs with the permissions of the file owner (`root`).*

---

## Modify sticky bit

```
$ sudo chmod +t mydir
$ sudo chmod 1755 mydir
```

## result :

```
$ ls -ld /mydir
drwxrwxrwxt 6 root root 4096 Dec 15 11:45 /mydir
```

**You'll see a special permission bit at the end here t,
this means everyone can add files, write files, modify files in the /mydir directory, 
but only root (owner) can delete the /mydir directory.**

---
