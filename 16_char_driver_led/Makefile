obj-m += char_driver_led.o 

KDIR := /home/wz/4412/iTop4412_Kernel_3.0

PWD ?= $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
		
clean:
	rm -rf *.mod.c *.o *.order *.ko *.mod.o *.symvers
