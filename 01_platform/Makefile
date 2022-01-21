#!/bin/bash
obj-m += platform_device_test.o 

KDIR := /home/wz/4412/iTop4412_Kernel_3.0
PWD ?= $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
		
clean:
	rm -rf *.o *.order *.symvers *.ko *.mod.c
