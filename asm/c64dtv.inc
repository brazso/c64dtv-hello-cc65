;
; Based on https://www.c64-wiki.com/wiki/C64DTV_Programming_Guide#ROM_LAYOUT
;

.include "c64.inc"

.ifndef C64DTV_INC
C64DTV_INC  = 1

;
; Extended VIC registers
; $D036-$D04F
;
COLRBANKLO      := $D036 ; Color Bank Low
COLRBANKHI      := $D037 ; Color Bank Low
LINCNTAMODULOLO := $D038 ; Linear Count A modulo low
LINCNTAMODULOHI := $D039 ; Linear Count A modulo high
LINCNTASTARTLO  := $D03A ; Linear Count A Start low
LINCNTASTARTMI := $D03B ; Linear Count A Start middle
LINEARADDR      := $D03C ; Linear addressing flag and others
GRAPHICSBANKA   := $D03D ; Graphics fetch bank (used for all classic VIC graphics fetches)
GRAPHICSBANKB   := $D03E ; Graphics fetch bank (used for all classic VIC graphics fetches)
EXTENDESMODE    := $D03F ; Extendes modes flag
BURSTPHASE      := $D040 ; Burst phase alternate flag and others
BURSTRATEHI     := $D041 ; Burst rate modulus high, default = 28
BURSTRATEMI     := $D042 ; Burst rate modulus middle, default = 19
BURSTRATELO     := $D043 ; Burst rate modulus low, default = 120
CPUORIRQCYCLE   := $D044 ; CPU Cycle at reading, IRQ trigger cycle at writing, default = 64
LINCNTASTARTHI  := $D045 ; Linear Count A Start high
LINCNTASTEP     := $D046 ; Linear Count A Step
LINCNTBMODULOLO := $D047 ; Linear Count B modulo low
LINCNTBMODULOHI := $D048 ; Linear Count B modulo high
LINCNTBSTARTLO  := $D049 ; Linear Count B start low
LINCNTBSTARTMI  := $D04A ; Linear Count B start middle
LINCNTBSTARTHI  := $D04B ; Linear Count B start high
LINPLANEBSTEP   := $D04C ; Linear Plane B Step
SPRITEBANK      := $D04D ; Sprite Bank
SCANLINETIMING  := $D04E ; Scan line timing adjust. Adds about 25ns per count
SATURATION      := $D04F ; Saturation mode and Burst lock to line

.endif
