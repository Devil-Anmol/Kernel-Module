# Kernel-Module
Kernel Module that takes in process name as input and returns the process id, group id, and user id.
#### Imp:
*Do install linux-headers*
## To compile
    make
## To load
    insmod kernelmodule.ko input = process_name
give the process you want details of in place of *process_name*
## To print
    dmesg
## To unload
    rmmod kernelmodule.ko
