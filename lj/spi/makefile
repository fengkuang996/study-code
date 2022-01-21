default:
	arm-none-linux-gnueabi-as start.S -o start.o
	arm-none-linux-gnueabi-gcc -c test.c -o test.o -nostdlib
	arm-none-linux-gnueabi-ld start.o test.o -o test.elf -Ttext 0x50000000
	arm-none-linux-gnueabi-objcopy -O binary test.elf test.bin
	arm-none-linux-gnueabi-objdump -D test.elf > test.dis

clean:
	rm -rf *.o *.bin *.dis *.elf
