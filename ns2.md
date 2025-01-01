To install Network Simulator 2 (NS2) version 2.35 on Ubuntu 22.04, follow these organized steps:

!! use vim as a text editor

**1. Download NS2.35 Package**

Download the NS2.35 all-in-one package from SourceForge:

```bash
wget http://sourceforge.net/projects/nsnam/files/allinone/ns-allinone-2.35/ns-allinone-2.35.tar.gz/download -O ns-allinone-2.35.tar.gz
```

**2. Extract the Package**

Extract the downloaded package to your home directory:

```bash
tar zxvf ns-allinone-2.35.tar.gz -C ~/
```

**3. Install Required Dependencies**

NS2.35 requires specific versions of GCC and other libraries. Install them as follows:

- Open the sources list file:

  ```bash
  sudo vim /etc/apt/sources.list
  ```

- Add the following line to the file:

  ```
  deb http://in.archive.ubuntu.com/ubuntu/ bionic main universe
  ```

- Update the package list:

  ```bash
  sudo apt update
  ```

- If you encounter a GPG error, resolve it by adding the key:

  ```bash
  sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 3B4FE6ACC0B21F32
  sudo apt update
  ```

- error again ?
  
  ```
  sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3B4FE6ACC0B21F32
  ```
  

- Install the required packages:

  ```bash
  sudo apt install gcc-4.8 g++-4.8 build-essential autoconf automake libxmu-dev gawk
  ```

**4. Modify Configuration Files**

Navigate to the NS2.35 directory:

```bash
cd ~/ns-allinone-2.35/ns-2.35
```

Edit the following files to replace 
  - `@CC@` with `gcc-4.8` 
  - and `@CPP@` or `@CXX@` with `g++-4.8`:

- `~/ns-allinone-2.35/ns-2.35/Makefile.in`
- `~/ns-allinone-2.35/otcl-1.14/Makefile.in`
- `~/ns-allinone-2.35/nam-1.15/Makefile.in`
- `~/ns-allinone-2.35/xgraph-12.2/Makefile.in`

Additionally, in `~/ns-allinone-2.35/ns-2.35/linkstate/ls.h`, at line 137, change:

```cpp
void eraseAll() { erase(baseMap::begin(), baseMap::end()); }
```

to:

```cpp
void eraseAll() { this->erase(baseMap::begin(), baseMap::end()); }
```

**5. Install NS2**

From the `ns-allinone-2.35` directory, run:

```bash
cd ~/ns-allinone-2.35
sudo ./install
```

**6. Set Environment Variables**

Add the following lines to your `~/.bashrc` file to set the necessary environment variables (replace `/home/your_username` with your actual home directory path):

```bash
export PATH=$PATH:/home/your_username/ns-allinone-2.35/bin:/home/your_username/ns-allinone-2.35/tcl8.5.10/unix:/home/your_username/ns-allinone-2.35/tk8.5.10/unix
export LD_LIBRARY_PATH=/home/your_username/ns-allinone-2.35/otcl-1.14:/home/your_username/ns-allinone-2.35/lib
```

Apply the changes:

```bash
source ~/.bashrc
```

**7. Verify the Installation**

Test the installation by running:

```bash
ns
```

If the installation is successful, you should see the `%` prompt of the NS interpreter.

For a visual guide, you can refer to the following video tutorial:

 
