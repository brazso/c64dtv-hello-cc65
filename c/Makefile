ALL_C = $(wildcard *.c) $(wildcard *.h)

all: $(ALL_C)
	cl65 -t c64 --cpu 6502dtv -o helloc.prg -l hello.list hello.c

clean:
	rm -f *.prg *.list *.o
