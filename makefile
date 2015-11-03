all: hello

hello: putchar.rel crt0.rel
	sdcc -V -mz80 --std-sdcc99 --code-loc 0x100 --no-std-crt0 --portmode=z80 crt0.rel putchar.rel hello.c
	makebin -p -s 65536 hello.ihx hello.bin

putchar.rel:
	sdasz80 -o putchar.s

crt0.rel:
	sdasz80 -o crt0.s

clean:
	rm -f *.asm *.rel *.bin *.ihx *.lk *.lst *.map *.noi *.sym
