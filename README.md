# Raspberry Pi Pico Using PlatformIO Development

Sample Programs

## Build the Application

```shell
make clean compile
```

## Upload Application to Microcontroller

```shell
make upload
```

## Development Environment Setup

### Install PlatformIO

#### Mac OSX

Options:
  1. Brew Install

        ```shell
        brew install platformio
        ```

  2. Download and run get-platformio.py

        ```shell
        # Download get-platformio.py
        curl -O https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py

        # Install PlatformIO
        python3 get-platformio.py

        # Set PATH
        export PATH=$PATH:~/.platformio/penv/bin
        ```

#### Ubuntu Linux

##### Install Prerequisite Packages

```shell
apt-get install python3-venv
```

Install `99-platformio-udev.rules`.
See : https://docs.platformio.org/page/faq.html#platformio-udev-rules

```shell
sudo service udev restart
```

#### Grant user access to USB device

```shell
sudo usermod -a -G dialout $USER
sudo usermod -a -G plugdev $USER
```
Log out and log back in for change to take effect

#### Install PlatformIO

```shell
curl -O https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
python3 get-platformio.py
```

#### Set PATH to PlatformIO

```shell
# Add to ~/.bashrc

export PATH=$PATH:~/.platformio/penv/bin
```

## Application Settings

#### Port Assignment

Edit platformio.ini file

Linux:
```shell
upload_port = /dev/ttyUSB*
```

Mac OSX:
```shell
upload_port = /dev/tty.usbserial-*
```

#### Port Monitor Speed

```shell
monitor_speed = 115200
```

## References

- https://docs.platformio.org/
- https://docs.platformio.org/en/latest/tutorials/espressif32/arduino_debugging_unit_testing.html
