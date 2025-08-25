Understanding the /etc/shadow File
The /etc/shadow file is used to store information about user authentication. It requires superuser read permissions.
$ sudo cat /etc/shadow
root:MyEPTEa$6Nonsense:15000:0:99999:7:::
#username:password_hash:last_change:min_age:max_age:warning:inactive:expire

In the password field, you'll see an encrypted password. The fields are separated by colons.
Field Descriptions

Username
Encrypted password
Date of last password changed - Expressed as the number of days since Jan 1, 1970. If there is a 0, that means the user should change their password the next time they login.
Minimum password age - Days that a user will have to wait before being able to change their password again.
Maximum password age - Maximum number of days before a user has to change their password.
Password warning period - Number of days before a password is going to expire.
Password inactivity period - Number of days after a password has expired to allow login with their password.
Account expiration date - Date that user will not be able to login.
Reserved field for future use

Additional Notes
In most distributions today, user authentication doesn't rely on just the /etc/shadow file. There are other mechanisms in place, such as PAM (Pluggable Authentication Modules), that replace authentication.
