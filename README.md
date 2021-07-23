# rot_cipher
A 100% Sekur PHP Module for ROT encoding text.

# Installing and debugging
Note: This has only been tested on a fresh install of Ubuntu Server 20.04.2 LTS.

1) Update the system
```bash
sudo apt update
sudo apt upgrade
```

2) Install required dependencies
```bash
sudo apt install php php-dev apache2 libapache2-mod-php build-essential gdb git
```

3) Disable ASLR (Randomly deciding what memory addresses to use is just *really* silly and may lead to unexpected behaviour)
```bash
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
echo "kernel.randomize_va_space = 0" | sudo tee /etc/sysctl.d/01-disable-aslr.conf
```

4) Clone and install the rot_cipher repository
```bash
git clone https://github.com/gaberust/rot_cipher.git
cd rot_cipher
make
sudo make install
```

5) Enable the rot_cipher extension by appending the following line to `/etc/php/7.4/cli/php.ini` and `/etc/php/7.4/apache2/php.ini`
```
extension=rot_cipher.so
```

6) Debugging Apache with multiple threads is a pain (if not straight up impossible), so add the following lines to `/etc/apache2/apache2.conf`
```
StartServers 1
MaxRequestWorkers 1
MaxConnectionsPerChild 0
ServerLimit 1
```

7) Remove `/var/www/html/index.html` and add the following file for testing (`/var/www/html/index.php`). Replace `X` with any ROT key of your choice.
```php
<!DOCTYPE html>
<html>
    <head>
        <title>Rot Test</title>
    </head>
    <body>
        <?php
            echo rot($_POST['text'], X);
        ?>
    </body>
</html>
```

8) Reboot the machine to ensure everything is loaded correctly with new configurations
