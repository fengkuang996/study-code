#!/bin/bash
obj-m += platform_device_info.o 

KDIR := /home/wz/4412/iTop4412_Kernel_3.0

PWD ?= $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
		
clean:
	rm -rf *.o *.symvers *.ko *.mod.c *.order
