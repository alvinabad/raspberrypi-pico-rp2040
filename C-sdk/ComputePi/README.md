# rp2040-computepi
## Happy Pi Day!

Compute for Pi in C using Raspberry Pi Pico Microcontroller

## Prerequisites

### pico-sdk

Install pico-sdk.
See: https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-c-sdk.pdf

### Set PICO_SDK_PATH environment

Example:
```
export PICO_SDK_PATH=/home/pi/pico-sdk
```

### picotool

Install picotool and save to /usr/local/bin/picotool

## Build program

```
make clean all
```

## Load program to Pico Microcontroller

Press select button while connecting power to pico. Release select button.

```
make load
```

## Reboot Pico

```
make reboot
```
