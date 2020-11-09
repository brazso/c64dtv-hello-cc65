ALL_ASM = $(wildcard *.asm) $(wildcard *.inc)
ALL_C = $(wildcard *.c) $(wildcard *.h)

ALL_OBJS = $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.asm,%.obj,$(wildcard *.asm))

all: $(ALL_OBJS)
	cl65 -t c64 --cpu 6502dtv -o hellomix.prg -m hello.mmap $(ALL_OBJS)

%.o: %.c
	cc65 -t c64 --cpu 6502dtv -o $(patsubst %.o,%.s,$@) $<
	ca65 -t c64 --cpu 6502dtv -o $@ $(patsubst %.o,%.s,$@)

%.obj: %.asm
	ca65 -t c64 --cpu 6502dtv -o $@ $<

clean:
	rm -f *.prg *.mmap *.o *.obj *.s
