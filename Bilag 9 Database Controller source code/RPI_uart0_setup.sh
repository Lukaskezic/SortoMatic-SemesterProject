#!/bin/
# Guide at: https://redmine.ase.au.dk/devs/projects/raspberry-zero/wiki/TtyS0

# Enable the serial0 / ttyS0 UART on RPIzw
# This disable the serial terminal, but enable general purpose UART

# Tx: Pin 8; Rx: Pin 10;
# Can be found on J7 on ase_fhat

# =====================
# This script MUST be run, before using the 
#   Database Controller program
# =====================

# BAUD_RATE = 9600

# Disbale console putput
echo "dwc_otg.lpm_enable=0 root=/dev/mmcblk0p2 rootfstype=ext4 rootwait modules-load=dwc2,g_ether" > /boot/cmdline.txt
# Set baud rate
stty -F /dev/ttyS0 $BAUD_RATE
# Disbale login functionality
systemctl disable serial-getty@ttyS0.service
# Reboot system to enable changes
echo "UART setup complete - system rebooting"
reboot