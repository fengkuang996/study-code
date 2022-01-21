default:
	arm-none-linux-gnueabi-as start.S -o start.o
	arm-none-linux-gnueabi-gcc -c test.c -o test.o -nostdlib
	arm-none-linux-gnueabi-gcc -c do_swi.c -o do_swi.o -nostdlib
	arm-none-linux-gnueabi-gcc -c do_irq.c -o do_irq.o -nostdlib
	arm-none-linux-gnueabi-ld do_irq.o start.o test.o key.o do_swi.o -o test.elf -Ttext 0x50000000
	arm-none-linux-gnueabi-objcopy -O binary test.elf test.bin
	arm-none-linux-gnueabi-objdump -D test.elf > test.dis

clean:
	rm -rf *.o *.bin *.dis *.elf
