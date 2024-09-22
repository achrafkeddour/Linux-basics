```
sudo apt update
sudo apt install gdm3
sudo dpkg-reconfigure gdm3 //making it as default display manager
sudo reboot 
```

### to start it :
```
sudo systemctl enable gdm3
sudo systemctl start gdm3
```

### to stop it :
```
sudo systemctl disable gdm3
sudo systemctl stop gdm3
```
