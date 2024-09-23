---

# Linux User and Group Management

In a Linux system, **users** and **groups** are fundamental to controlling access to files, directories, and system settings. User and group management is crucial for both security and organization, especially in multi-user environments.

## Table of Contents
1. [User IDs (UID) and Group IDs (GID)](#uid-gid)
2. [Understanding Root and Superuser Privileges](#root-superuser)
3. [User Information - `/etc/passwd`](#etc-passwd)
4. [Password Information - `/etc/shadow`](#etc-shadow)
5. [Group Information - `/etc/group`](#etc-group)
6. [User Management Commands](#user-management-commands)
   - [Adding Users](#adding-users)
   - [Removing Users](#removing-users)
   - [Changing User Passwords](#changing-user-passwords)
7. [Advanced Concepts](#advanced-concepts)
   - [PAM (Pluggable Authentication Modules)](#pam)
   
---

<a name="uid-gid"></a>
## 1. User IDs (UID) and Group IDs (GID)
- Each user on the system has a **UID** (User ID), and each group has a **GID** (Group ID). While usernames and group names are human-friendly, the system uses these numeric identifiers internally.
- Users can belong to multiple groups, but each user has a primary group that controls file permissions by default.

### System vs Regular Users
- System users (UID < 1000) are typically services (e.g., `daemon`, `nobody`) that help run background processes.
- Regular users (UID ≥ 1000) are actual people with login capabilities.

---

<a name="root-superuser"></a>
## 2. Understanding Root and Superuser Privileges
- The **root** user has the highest level of access on the system. Root can read/write any file, execute any command, and manage any process.
- **`sudo`** allows a regular user to execute commands with root privileges, based on the `/etc/sudoers` file.

### Accessing Root Privileges:
- To run commands as root:  
  ```bash
  sudo <command>
  ```
- To switch to the root user:
  ```bash
  sudo su
  ```

### Switching Between Users:
To switch to another user (if the user exists):
```bash
su <username>
```

### Sudoers Configuration:
The `/etc/sudoers` file defines which users can run `sudo`. Use the `visudo` command to safely edit it:
```bash
sudo visudo
```

---

<a name="etc-passwd"></a>
## 3. User Information - `/etc/passwd`

The `/etc/passwd` file contains basic information about system users. Each line represents a user account and contains seven colon-separated fields:

```
username:x:UID:GID:GECOS:home_directory:shell
```

### Key Fields:
- **`username`**: The user's login name.
- **`x`**: Placeholder for the password (actual password is stored in `/etc/shadow`).
- **`UID`**: User's unique ID.
- **`GID`**: Group ID for the user's primary group.
- **`GECOS`**: User's full name or comment (optional).
- **`home_directory`**: The user's home directory (e.g., `/home/username`).
- **`shell`**: The user's default shell (e.g., `/bin/bash`).

### Example for Regular User:
```
john:x:1001:1001:John Doe:/home/john:/bin/bash
```

### Example for System Account:
```
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
```

> **Tip:** You can use the `vipw` tool to safely edit the `/etc/passwd` file if necessary.

---

<a name="etc-shadow"></a>
## 4. Password Information - `/etc/shadow`

The `/etc/shadow` file stores password and account expiration information for each user. It requires root permissions to read and edit. The fields in `/etc/shadow` are colon-separated:

```
username:password_hash:last_change:min_age:max_age:warning:inactive:expire
```

### Key Fields:
1. **Username**: User's login name.
2. **Password hash**: Encrypted password (or `!` for disabled accounts).
3. **Last password change**: Days since Jan 1, 1970, when the password was last changed.
4. **Minimum password age**: Minimum days before a user can change their password again.
5. **Maximum password age**: Maximum days before the user is required to change their password.
6. **Warning period**: Days before the password expires to warn the user.
7. **Inactivity period**: Days after password expiration to lock the account.
8. **Expiration date**: Date when the account will be locked.

### Example Entry:
```
john:$6$KfJ...:15000:0:99999:7:::
```

> **Note:** It's best to avoid manually editing `/etc/shadow`. Use commands like `passwd` or `chage` to update this file.

---

<a name="etc-group"></a>
## 5. Group Information - `/etc/group`

The `/etc/group` file defines user groups and contains four colon-separated fields:

```
group_name:password:GID:user_list
```

### Key Fields:
- **Group name**: Name of the group.
- **Password**: Group password (optional, rarely used, `*` by default).
- **GID**: Group ID.
- **User list**: Comma-separated list of users in the group.

### Example:
```
sudo:x:27:john,mary
```

> **Tip:** Modify group memberships with the `usermod` or `gpasswd` command.

---

<a name="user-management-commands"></a>
## 6. User Management Commands

### Adding Users:
There are two primary ways to add users:  
1. **`useradd`**: Basic user creation command.
   ```bash
   sudo useradd bob
   ```
2. **`adduser`**: Higher-level command that automatically creates home directories and assigns default settings.
   ```bash
   sudo adduser bob
   ```

### Removing Users:
To delete a user:
```bash
sudo userdel bob
```
Optionally, delete the user's home directory as well:
```bash
sudo userdel -r bob
```

### Changing User Passwords:
To change the password of a user:
```bash
passwd bob
```

---

<a name="advanced-concepts"></a>
## 7. Advanced Concepts

<a name="pam"></a>
### PAM (Pluggable Authentication Modules)
Modern Linux distributions use **PAM** to handle authentication. PAM provides a flexible framework for authentication methods, so that you can manage passwords, 2-factor authentication, and even biometric systems.

- PAM configuration files are located in `/etc/pam.d/`.
- Authentication is modular and can be extended without altering the core system.

> **Note:** In many cases, changes to authentication (such as login methods) will involve editing or configuring PAM.

---

### Summary Tips:
- Use `sudo` for administrative tasks to avoid logging in as root.
- Use the `passwd` and `chage` commands to manage passwords and account expiration.
- Edit `/etc/sudoers` with the `visudo` command for secure sudo management.
- Groups allow you to easily manage permissions for multiple users.

---
