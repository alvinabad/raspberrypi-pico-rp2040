## Install Tools

Install ampy

```
sudo pip3 install --user adafruit-ampy
```

Install rshell

```
sudo pip3 install --user rshell
```

## Flash Micropython Firmware

Download Micropython firmware for Raspberry Pi Pico.

Browse Micropython site and look for Raspberry Pi Pico.

https://micropython.org/download/rp2-pico/

Download firmware to local directory.

Example:
```
wget --no-check-certificate -c https://micropython.org/resources/firmware/rp2-pico-20210902-v1.17.uf2
```

Perform a boot select.

While pressing the bootsel button, connect a USB cable from Linux to pico

Verify new disk is connected

```
cat /proc/partitions
```

Create a mount directory

```
mkdir /pico
```

Mount /dev/sda1 to /pico

```
sudo mount /dev/sda1 /pico
```

Copy Micropython firmware to /pico

```
sudo cp rp2-pico-20210902-v1.17.uf2 /pico
```

Unmount /pico

```
sudo umount /pico
```

Upload python files into Pico

```
ampy -p /dev/ttyACM0 put main.py
```


## References

* https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-python-sdk.pdf
* https://github.com/scientifichackers/ampy
* https://pypi.org/project/rshell/
* https://learn.adafruit.com/micropython-basics-load-files-and-run-code/file-operations
