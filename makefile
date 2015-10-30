all: hello

hello: putchar.rel crt0.rel
	sdcc -mz80 --code-loc 0x0100 --data-loc 0 --no-std-crt0 crt0.rel putchar.rel hello.c
	makebin -p hello.ihx hello.bin

putchar.rel:
	sdasz80 -o putchar.s

crt0.rel:
	sdasz80 -o crt0.s

clean:
	rm -f *.asm *.rel *.bin *.ihx *.lk *.lst *.map *.noi *.sym
