obj-m += bus.o drv.o dev.o 

KDIR := /home/wz/4412/iTop4412_Kernel_3.0
#KDIR := /lib/modules/5.4.0-91-generic/build

PWD ?= $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
		
clean:
	rm -rf *.mod.c *.o *.order *.ko *.mod.o *.symvers *.mod
