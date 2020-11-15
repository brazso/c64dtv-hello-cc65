ALL_ASM = $(wildcard *.asm) $(wildcard *.inc)

all: $(ALL_ASM)
	cl65 -t c64 --cpu 6502dtv -o helloasm.prg -l hello.list hello.asm

clean:
	rm -f *.prg *.list *.o
