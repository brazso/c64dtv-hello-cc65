;
; Based on https://raw.githubusercontent.com/floooh/emu-info/master/cbm/mapping-c64.txt, https://www.pagetable.com/c64ref/c64disasm/ and http://unusedino.de/ec64/technical/project64/memory_maps.html
;

.ifndef C64_INC
C64_INC  = 1

;
; Page 0 (zero page)
;

D6510           := $0 ; 6510 On-Chip I/O DATA Direction Register
R6510           := $1 ; Memory mapper and datasette controller
P0_FREE1_1      := $2 ; Unused
ZP_FREE1_1      := P0_FREE1_1
ADRAY1          := $3 ; Vector: Routine to Convert a Number from Floating Point to Signed Integer (2 bytes)
ZP_PTR_3        := ADRAY1
ADRAY2          := $5 ; Vector: Routine to Convert a Number from Integer to Floating Point (2 bytes)
ZP_PTR_4        := ADRAY2
CHARAC          := $7 ; Search Character for Scanning BASIC Text Input
ENDCHR          := $8 ; Search Character for BASIC Statement Termination or Quote
TRMPOS          := $9 ; Column position of the Cursor before the Last TAB or SPC
VERCK           := $A ; Flag: LOAD or VERIFY
COUNT           := $B ; Index into the Text Input Buffer/Number of Array Subscripts
DIMFLG          := $C ; Flags for the Routines That Locate or Build an Array
VALTYP          := $D ; Flag: Type of Data (String or Numeric)
INTFLG          := $E ; Flat: Type of Numeric Data (Integer or Floating Point)
GARBFL          := $F ; Flag for LIST, Garbage Collection, and Program Tokenization
SUBFLG          := $10 ; Flag: Subscript Reference to an Array or User-Defined Function Call (FN) 
INPFLG          := $11 ; Flag: Is Data Input to GET, READ or INPUT?
TANSGN          := $12 ; Flag: Sign of the Result of the TAN or SIN Function
CHANNL          := $13 ; Current I/O Channel (CMD Logical File) Number
LINNUM          := $14 ; Integer Line Number Value (2 bytes)
TEMPPT          := $16 ; Pointer to the Next Available Space in the Temporary String Stack
LASTPT          := $17 ; Pointer to the Address of the Last String in the Temporary String Stack (2 bytes)
TEMPST          := $19 ; Descriptor Stack for Temporary Strings (9 bytes)
INDEX           := $22 ; Miscellaneous Temporary Pointers and Save Area (4 bytes)
RESHO           := $26 ; Floating Point Multiplication Work Area (5 bytes)
TXTTAB          := $2B ; Pointer to the Start of BASIC Program Text (2 bytes)
VARTAB          := $2D ; Pointer to the Start of the BASIC Variable Storage Area (2 bytes)
ARYTAB          := $2F ; Pointer to the Start of the BASIC Array Storage Area (2 bytes)
STREND          := $31 ; Pointer to End of the BASIC Array Storage Area (+1), and the Start of Free RAM (2 bytes)
FREETOP         := $33 ; Pointer to the Bottom of the String Text Storage Area (2 bytes)
FRESPC          := $35 ; Temporary Pointer for Strings (2 bytes)
MEMSIZ          := $37 ; Pointer to the Highest Address Used by BASIC (2 bytes)
CURLIN          := $39 ; Current BASIC Line Number (2 bytes)
OLDLIN          := $3B ; Previous BASIC Line Number (2 bytes)
OLDTXT          := $3D ; Pointer to the Address of the Current BASIC Statement (2 bytes)
DATLIN          := $3F ; Current DATA Line Number (2 bytes)
DATPTR          := $41 ; Pointer to the Address of the Current DATA Item (2 bytes)
INPPTR          := $43 ; Pointer in the Source of GET, READ, or INPUT Information (2 bytes)
VARNAM          := $45 ; Current BASIC Variable Name (2 bytes)
VARPNT          := $47 ; Pointer to the Current BASIC Variable Value (2 bytes)
FORPNT          := $49 ; Temporary Pointer to the Index Variable Used by FOR (2 bytes)
OPPTR           := $4B ; Math Operator Table Displacement (2 bytes)
OPMASK          := $4D ; Mask for Comparison Operation
DEFPNT          := $4E ; Pointer to the Current FN Descriptor (2 bytes)
DSCPNT          := $50 ; Temporary Pointer to the Current String Descriptor (3 bytes)
FOUR6           := $53 ; Constant for Garbage Collection
JMPER           := $54 ; Jump to Function Instruction
NUMWORKAREA     := $57 ; BASIC Numeric Work Area (9 bytes)
FAC1            := $61 ; Floating Point Accumulator #1 (6 bytes)
FACEXP          := $61 ; Floating Point Accumulator #1: Exponent
FACHO           := $62 ; Floating Point Accumulator #1: Mantissa (4 bytes)
FACSGN          := $66 ; Floating Point Accumulator #1: Sign 
SGNFLG          := $67 ; Number of Terms in a Series Evaluation 
BITS            := $68 ; Floating Point Accumulator #1: Overflow Digit
FAC2            := $69 ; Floating Point Accumulator #2, similar to FAC1 (6 bytes)
ARGEXP          := $69 ; Floating Point Accumulator #2: Exponent
ARGHO           := $6A ; Floating Point Accumulator #2: Mantissa (4 bytes)
ARGSGN          := $6E ; Floating Point Accumulator #2: Sign
ARISGN          := $6F ; Result of a Signed Comparison of Accumulator #1 to Accumulator #2
FACOV           := $70 ; Low Order Mantissa Byte of Floating Point Accumulator #1 (For Rounding)
FBUFPT          := $71 ; Series Evaluation Pointer (2 bytes)
CHRGET          := $73 ; Subroutine: Get Next BASIC Text Character (24 bytes)
RNDX            := $8B ; RND Function Seed Value
KERNALAREA      := $90 ; Kernal Work Storage Area (112 bytes)
STATUS          := $90 ; Kernal I/O Status Word (ST)
STKEY           := $91 ; Flag: Was STOP Key Pressed?
SVXT            := $92 ; Timing Constant for Tape Reads
VERCK2          := $93 ; Flag for Load Routine: 0=LOAD, 1=VERIFY (Same as VERCK , use that one)
C3PO            := $94 ; Flag: Serial Bus--Output Character Was Buffered
BSOUR           := $95 ; Buffered Character for Serial Bus
SYNO            := $96 ; Cassette Block Synchronization Number
XSAV            := $97 ; Temporary .X Register Save Area
LDTND           := $98 ; Number of Open I/O Files/Index to the End of File Tables
DFLTN           := $99 ; Default Input Device (Set to 0 for Keyboard)
DFLTO           := $9A ; Default Output (CMD) Device (Set to 3 for the Screen)
PRTY            := $9B ; Tape Character Parity
DPSW            := $9C ; Flag: Tape Byte Received
MSGFLG          := $9D ; Flag: Kernal Message Control
PTR1            := $9E ; Tape Pass 1 Error Log Index
PTR2            := $9F ; Tape Pass 2 Error Log Correction Index
TIME            := $A0 ; Software Jiffy Clock (3 bytes)
TMPDATAAREA     := $A3 ; Temporary Data Storage Area (2 bytes)
CNTDN           := $A5 ; Cassette Synchronization Character Countdown 
BUFPNT          := $A6 ; Count of Characters in Tape I/O Buffer
INBIT           := $A7 ; RS-232 Input Bits/Cassette Temporary Storage Area
BITCI           := $A8 ; RS-232 Input Bit Count/Cassete Temporary Storage
RINONE          := $A9 ; RS-232 Flag: Check for Start Bit
RIDATA          := $AA ; RS-232 Input Byte Buffer/Cassette Temporary Storage
RIPRTY          := $AB ; RS-232 Input Parity/Cassete Leader Counter
SAL             := $AC ; Pointer to the Starting Address of a Load/Screen Scrolling (2 bytes)
EAL             := $AE ; Pointer to Ending Address of Load (End of Program) (2 bytes)
CMP0            := $B0 ; Tape Timing
TAPE1           := $B2 ; Pointer: Start of Tape Buffer (2 bytes)
BITTS           := $B4 ; RS-232 Output Bit Count/Cassette Temporary Storage
NXTBIT          := $B5 ; RS-232 Next Bit to Send/Tape EOT Flag
RODATA          := $B6 ; RS-232 Output Byte Buffer
FNLEN           := $B7 ; Length of Current Filename
LA              := $B8 ; Current Logical File Number
SA              := $B9 ; Current Secondary Address
FA              := $BA ; Current Device Number
FNADR           := $BB ; Pointer: Current Filename (2 bytes)
ROPRTY          := $BD ; RS-232 Output Parity/Cassette Temporary Storage
FSBLK           := $BE ; Cassette Read/Write Block Count
MYCH            := $BF ; Tape Input Byte Buffer
CAS1            := $C0 ; Tape Motor Interlock
STAL            := $C1 ; I/O Start Address (2 bytes)
STAL2           := $C3 ; I/O Secondary Start Address (2 bytes)
LSTX            := $C5 ; Matrix Coordinate of Last Key Pressed, 64=None Pressed
NDX             := $C6 ; Number of Characters in Keyboard Buffer (Queue)
RVS             := $C7 ; Flag: Print Reverse Characters? 0=No
INDX            := $C8 ; Pointer: End of Logical Line for Input
LXSP            := $C9 ; Cursor X,Y Position at Start of Input (2 bytes)
SFDX            := $CB ; Matrix Coordinate of Current Key Pressed
BLNSW           := $CC ; Cursor Blink Enable: 0=Flash Cursor
BLNCT           := $CD ; Timer: Countdown to Blink Cursor
GDBLN           := $CE ; Character Under Cursor
BLNON           := $CF ; Flag: Was Last Curson Blink on or off?
CRSW            := $D0 ; Flag: Input from Keyboard or Screen
PNT             := $D1 ; Pointer to the Address of the Current Screen Line (2 bytes)
PNTR            := $D3 ; Cursor Column on Current Line
QTSW            := $D4 ; Flag: Editor in Quote Mode? 0=No 
LNMX            := $D5 ; Maximum Length of Physical Screen Line
TBLX            := $D6 ; Current Cursor Physical Line Number
LASTASCII       := $D7 ; The ASCII value of the last character printed to the screen is held here temporarily
INSRT           := $D8 ; Flag: Insert Mode (Any Number Greater Than 0 Is the Number of Inserts)
LDTB1           := $D9 ; Screen Line Link Table/Editor Temporary Storage (26 bytes)
USER            := $F3 ; Pointer to the Address of the Current Screen Color RAM Location (2 bytes)
KEYTAB          := $F5 ; Vector: Keyboard Decode Table (2 bytes)
RIBUF           := $F7 ; Pointer: RS-232 Input Buffer (2 bytes)
ROBUF           := $F9 ; Pointer: RS-232 Output Buffer (2 bytes)
P0_FREE2_2      := $FB ; Two Free Bytes of Zero Page for User Programs (2 bytes)
ZP_FREE2_2      := P0_FREE2_2
ZP_PTR_1        := P0_FREE2_2
P0_FREE3_2      := $FD ; Two Free Bytes of Zero Page for User Programs (2 bytes)
ZP_FREE3_2      := P0_FREE3_2
ZP_PTR_2        := P0_FREE3_2
BASZPT          := $FF ; BASIC Temporary Data for Floating Point to ASCII Conversion (12 bytes)

;
; Page 1
;
BAD             := $100 ; Tape Input Error Log (63 bytes)
CPUSTACK        := $100 ; Microprocessor Stack for BASIC usage (193 bytes)

;
; Page 2 and 3 - BASIC and Kernal Working Storage
;

BUF             := $200 ; BASIC Line Editor Input Buffer (89 bytes)
LAT             := $259 ; Kernal Table of Active Logical File Numbers (10 bytes)
FAT             := $263 ; Kernal Table of Device Numbers for Each Logical File (10 bytes)
SAT             := $26D ; Kernal Table of Secondary Addresses for Each Logical File (10 bytes)
KEYD            := $277 ; Keyboard Buffer (Queue) (10 bytes)
MEMSTR          := $281 ; Pointer: O.S. Start of Memory (2 bytes)
MEMEND          := $283 ; Pointer: O.S. End of Memory (2 bytes)
TIMOUT          := $285 ; Flag: Kernal Variable for IEEE Time-Out
COLOR           := $286 ; Current Foreground Color for Text
GDCOL           := $287 ; Color of Character under Cursor
HIBASE          := $288 ; Top Page of Screen Memory
XMAX            := $289 ; Maximum Keyboard Buffer Size
RPTFLAG         := $28A ; Flag: Which Keys Will Repeat?
KOUNT           := $28B ; Counter for Timing the Delay Between Key Repeats
DELAY           := $28C ; Counter for Timing the Delay Until the First Key Repeat Begins
SHFLAG          := $28D ; Flag: SHIFT/CTRL/Logo Keypress
LSTSHF          := $28E ; Last Pattern of SHIFT/CTRL/Logo Keypress
KEYLOG          := $28F ; Vector to Keyboard Table Setup Routine (2 bytes)
MODE            := $291 ; Flag: Enable or Disable Changing Character Sets with SHIFT/Logo Keypress
AUTODN          := $292 ; Flag: Screen Scrolling Enabled
M51CTR          := $293 ; RS-232 Pseudo 6551 Registers
M51CDR          := $294 ; RS-232: Mock 6551 Command Register
M51AJB          := $295 ; RS-232: Nonstandard Bit Timing
RSSTAT          := $297 ; RS-232: Mock 6551 Status Register
BITNUM          := $298 ; RS-232: Number of Bits Left to be Sent/Received
BAUDOF          := $299 ; Time Required to Send a Bit
RIDBE           := $29B ; RS-232: Index to End of Receive Buffer
RIDBS           := $29C ; RS-232: Index to Start of Receive Buffer
RODBS           := $29D ; RS-232: Index to Start of Transmit Buffer
RODBE           := $29E ; RS-232: Index to End of Transmit Buffer
IRQTMP          := $29F ; Save Area for IRQ Vector During Cassette I/O (2 bytes)
ENABL           := $2A1 ; RS-232 Interrupts Enabled
CIA2NMIFLAG     := ENABL;
CIA1TIMER       := $2A2 ; Indicator of CIA #1 Control Register Activity During Cassette I/O
CIA1INTFLAG     := $2A3 ; Save Area for CIA #1 Interrupt Control Register During Cassette Read
CIA1TIMERFLG    := $2A4 ; Save Area for CIA #1 Control Register During Cassette Read
SCRNXTCOL       := $2A5 ; Temporary Index to the Next 40-Column Line for Screen Scrolling
PALNTSCFLG      := $2A6 ; PAL/NTSC Flag
P2_FREE1_59     := $2A7 ; Unused (89 bytes)

;
; Page 3
;

IERROR          := $300 ; Vector to the Print BASIC Error Message Routine (2 bytes)
IMAIN           := $302 ; Vector to the Main BASIC Program Loop (2 bytes)
ICRNCH          := $304 ; Vector to the Routine That Crunches the ASCII Text of Keywords into Tokens (2 bytes)
IQPLOP          := $306 ; Vector to the Routine That Lists BASIC Program Token as ASCII Text (2 bytes)
IGONE           := $308 ; Vector to the Routine That Executes the Next BASIC Program Token (2 bytes)
IEVAL           := $30A ; Vector to the Routine That Evaluates a Single-Term Arithmetic Expression
SAREG           := $30C ; Storage Area for .A Register (Accumulator)
SXREG           := $30D ; Storage Area for .X Index Register
SYREG           := $30E ; Storage Area for .Y Index Register
SPREG           := $30F ; Storage Area for .P (Status) Register
USRPOK          := $310 ; Jump Instruction for User Function ($4C)
USRADD          := $311 ; Address of USR Routine (Low Byte First) (2 bytes)
P3_BYTE_1       := $313 ; Unused
CINV            := $314 ; Vector to IRQ Interrupt Routine (2 bytes)
CBINV           := $316 ; Vector: BRK Instruction Interrupt (2 bytes)
NMINV           := $318 ; Vector: Non-Maskable Interrupt (2 bytes)
IOPEN           := $31A ; Vector to Kernal OPEN Routine (Currently at 62282 ($F34A)) (2 bytes)
ICLOSE          := $31C ; Vector to Kernal CLOSE Routine (Currently at 62097 ($F291)) (2 bytes)
ICHKIN          := $31E ; Vector to Kernal CHKIN Routine (Currently at 61966 ($F20E)) (2 bytes)
ICKOUT          := $320 ; Vector to Kernal CKOUT Routine (Currently at 62032 ($F250)) (2 bytes)
ICLRCH          := $322 ; Vector to Kernal CLRCHN Routine (Currently at 62259 ($F333)) (2 bytes)
IBASIN          := $324 ; Vector to Kernal CHRIN Routine (Currently at 61783 ($F157)) (2 bytes)
IBSOUT          := $326 ; Vector to Kernal CHROUT Routine (Currently at 61898 ($F1CA)) (2 bytes)
ISTOP           := $328 ; Vector to Kernal STOP Routine (Currently at 63213 ($F6ED)) (2 bytes)
IGETIN          := $32A ; Vector to Kernal GETIN Routine (Currently at 61758 ($F13E)) (2 bytes)
ICLALL          := $32C ; Vector to Kernal CLALL Routine (Currently at 62255 ($F32F)) (2 bytes)
USRCMD          := $32E ; Vector to User-Defined Command (Currently Points to BRK at 65126 ($FE66)) (2 bytes)
ILOAD           := $330 ; Vector to Kernal LOAD Routine (Currently at 62622 ($F49E)) (2 bytes)
ISAVE           := $332 ; Vector: Kernal SAVE Routine (Currently at 62941 ($F5DD)) (2 bytes)
P3_FREE1_8      := $334 ; Unused (8 bytes)
TBUFFER         := $33C ; Cassette I/O Buffer (192 bytes)
P3_FREE2_4      := $3FC ; Unused (4 bytes)

;
; 1K to 40K - Screen Memory, Sprinte Pointers and BASIC Program Text
;

VICSCN          := $400 ; Video Screen Memory Area (25 Lines by 40 Columns) (1000 bytes)
SPRSHAPEPTR     := $7F8 ; Sprite Shape Data Pointers (8 bytes)
BASICPRGTEXT    := $800 ; (-$9FFF) BASIC Program Text (38912 bytes)
CHRROMIMAGE0    := $1000 ; (-$1FFF) Character ROM Image for VIC-II Chip When Using Memory Bank 0 (Default) (4K)
AUTOROMCART     := $8000 ; Autostart ROM Cartridge (8K or 16K)
CHRROMIMAGE2    := $9000 ; (-$9FFF) Character ROM Image for VIC-II Chip When Using Memory Bank 2 (4K)

;
; 8K BASIC ROM and 4K Free RAM
; $A000-$CFFF
;

COLDSTARTPTR    := $A000 ; Cold Start Vector (2 bytes)
WARMSTARTPTR    := $A002 ; Warm Start Vector (2 bytes)
CBMBASIC        := $A004 ; ASCII Text characters CBMBASIC (8 bytes)
STMDSP          := $A00C ; Statement Dispatch Vector Table (70 bytes)
FUNDSP          := $A052 ; Function Dispatch Vector Table (46 bytes)
OPTAB           := $A080 ; Operator Dispatch Vector Table (31 bytes)
RESLST          := $A09E ; List of Keywords (1K)
ERRTAB          := $A19E ; ASCII Text of BASIC Error Messages (394 bytes)
ERRVECTAB       := $A328 ; Error Message Vector Table (60 bytes)
MISCMSGTAB      := $A365 ; Miscellaneous Messages (36 bytes)
FNDFOR          := $A38A ; Find FOR on Stack
BLTU            := $A3B8 ; Open a Space in Memory for a New Program Line or Variable
GETSTK          := $A3FB ; Check for Space on Stack
REASON          := $A408 ; Check for Space in Memory
OMERR           := $A435 ; OUT OF MEMORY Error Handler
ERROR           := $A437 ; General Error Handler
READY           := $A474 ; Print READY
MAIN            := $A480 ; Main Loop, Receives Input and Executes Immediately or Stores as Program Line
MAIN1           := $A49C ; Add or Replace a Line of Program Text
LINKPRG         := $A533 ; Relink Lines of Tokenized Program Text
INLIN           := $A560 ; Input a Line to Buffer from Keyboard
CRUNCH          := $A579 ; Tokenize Line in Input Buffer
FINDLN          := $A613 ; Search for Line Number
SCRTCH          := $A642 ; Perform NEW
CLEAR           := $A65E ; Perform CLR
RUNC            := $A68E ; Reset Pointer to Current Text Character to the Beginning of Program Text
LIST            := $A69C ; Perform LIST
QPLOP           := $A717 ; Print BASIC Tokens as ASCII Characters
FOR             := $A742 ; Perform FOR
NEWSTT          := $A7AE ; Set Up Next Statement for Execution
GONE            := $A7E4 ; Read and Execute the Next Statement
RESTORE         := $A81D ; Perform RESTORE
TESTSTOPKEY     := $A82C ; Test STOP Key for Break in Program
END             := $A831 ; Perform END
CONT            := $A857 ; Perform CONT
RUN             := $A871 ; Perform RUN
GOSUB           := $A883 ; Perform GOSUB
GOTO            := $A8A0 ; Perform GOTO
RETURN          := $A8D2 ; Perform RETURN
DATA            := $A8F8 ; Perform DATA
DATAN           := $A906 ; Search Program Text for the End of the Current BASIC Statement
IF              := $A928 ; Perform IF
REM             := $A93B ; Perform REM
ONGOTO          := $A94B ; Perform ON GOTO or ON GOSUB
LINGET          := $A96B ; Convert an ASCII Decimal Number to a Two-Byte Binary Line Number
LET             := $A9A5 ; Perform LET
PRINTN          := $AA80 ; Perform PRINT#
CMD             := $AA86 ; Perform CMD
PRINT           := $AAA0 ; Perform PRINT
STROUT          := $AB1E ; Print Message from a String Whose Address Is in the .Y and .A Registers
DOAGIN          := $AB4D ; Error Message Formatting Routines for GET, INPUT, and READ
GET             := $AB7B ; Perform GET and GET#
INPUTN          := $ABA5 ; Perform INPUT#
INPUT           := $ABBF ; Perform INPUT
READ            := $AC06 ; Perform READ
EXIGNT          := $ACFC ; ASCII Text for Input Error Messages
NEXT            := $AD1E ; Perform NEXT
FRMNUM          := $AD8A ; Evaluate a Numeric Expression and/or Check for Data Type Mismatch 
FRMEVAL         := $AD9E ; Evaluate Expression
EVAL            := $AE83 ; Convert a Single Numeric Term from ASCII Text to a Floating Point Number
PIVAL           := $AEA8 ; PI Expressed as a Five-Byte Floating Point Number
PARCHK          := $AEF1 ; Evaluate Expression Within Parentheses
CHKCLS          := $AEF7 ; Check for and Skip Closing Parentheses
CHKOPN          := $AEFA ; Check for and Skip Opening Parentheses
CHKCOM          := $AEFF ; Check for and Skip Comma
SNERR           := $AF08 ; Print Syntax Error Message
ISVAR           := $AF2B ; Get the Value of a Variable
ISFUN           := $AFA7 ; Dispatch and Evaluate a Function
OROP            := $AFE6 ; Perform OR
ANDOP           := $AFE9 ; Perform AND
DORE1           := $B016 ; Perform Comparisons
DIM             := $B018 ; Perform DIM
PTRGET          := $B08B ; Search for a Variable and Set It Up If It Is Not Found
CHKVALIDVAR     := $B113 ; Check If .A Register Holds Alphabetic ASCII Character
NOTFNS          := $B11D ; Create a New BASIC Variable
FINPTR          := $B185 ; Return the Address of the Variable That Was Found or Created
ARYGET          := $B194 ; Allocate Space for Array Descriptors
N32768          := $B1A5 ; The Constant -32768 in Five-Byte Floating Point Format
FLOAT2SIGNEDINT := $B1AA ; Convert a Floating Point Number to a Signed Integer in .A and .Y Registers
INTIDX          := $B1B2 ; Input and Convert a Floating Point Subscript to a Positive Integer
AYINT           := $B1BF ; Convert a Floating Point Number to a Signed Integer
ISARY           := $B1D1 ; Find Array Element or Create New Array in RAM
BSERR           := $B245 ; Print BAD SUBSCRIPT Error Message
FCERR           := $B248 ; Print ILLEGAL QUANTITY Error Message
UMULT           := $B34C ; Compute the Size of a Multidimensional Array
FRE             := $B37D ; Perform FRE
GIVAYF          := $B391 ; Convert 16-Bit Signed Integer to Floating Point
POS             := $B39E ; Perform POS
ERRDIR          := $B3A6 ; Check If the Program is Running in Direct Mode, and If So Issue an Error
DEF             := $B3B3 ; Perform DEF
GETFNM          := $B3E1 ; Check DEF and FN Syntax
FNDOER          := $B3F4 ; Perform FN
STRD            := $B465 ; Perform STR$
STRLIT          := $B487 ; Scan and Set Up Pointers to a String in Memory
GETSPA          := $B4F4 ; Allocate Space in Memory for String
GARBAG          := $B526 ; String Garbage Collection
CHKELIGIBLESTR  := $B5BD ; Check for Most Eligible String to Collect
COLLECTSTR      := $B606 ; Collect a String
CAT             := $B63D ; Concatenate Two Strings
MOVINS          := $B67A ; Move a String in Memory
FRESTR          := $B6A3 ; Discard a Temporary String
FRETMS          := $B6DB ; Remove an Entry from the String Descriptor Stack
CHRD            := $B6EC ; Perform CHR$
LEFTD           := $B700 ; Perform LEFT$
RIGHTD          := $B72C ; Perform RIGHT$
MIDD            := $B737 ; Perform MID$
PREAM           := $B761 ; Pull String Function Parameters from Stack for LEFT$, RIGHT$, and MID$
LEN             := $B77C ; Perform LEN
ASC             := $B78B ; Perform ASC
GETBYTC         := $B79B ; Input a Parameter Whose Value Is Between 0 and 255
VAL             := $B7AD ; Perform VAL
GETNUM          := $B7EB ; Get a 16-Bit Address Parameter and an 8-Bit Parameter (for POKE and WAIT)
GETADR          := $B7F7 ; Convert a Floating Point Number to an Unsigned Two-Byte Integer
PEEK            := $B80D ; Perform PEEK
POKE            := $B824 ; Perform POKE
FUWAIT          := $B82D ; Perform WAIT
FADDH           := $B849 ; Add .5 to Contents of Floating Point Accumulator #1
FSUB            := $B850 ; Subtract FAC1 from a Number in Memory
FSUBT           := $B853 ; BASIC's Subtraction Operation
FADD            := $B867 ; Add FAC1 to a Number in Memory
FADDT           := $B86A ; Perform BASIC's Addition Operation
FADD4           := $B8A7 ; Make the Result Negative If a Borrow Was Done
NORMAL          := $B8FE ; Normalize Floating Point Accumulator #1
NEGFAC          := $B947 ; Replace FAC1 with Its 2's Complement
OVERR           := $B97E ; Print Overflow Error Message
MULSHF          := $B983 ; SHIFT Routine
FONE            := $B9BC ; Floating Point Constant with a Value of 1
LOGCN2          := $B9C1 ; Table of Floating Point Constants for the LOG Function
LOG             := $B9EA ; Perform LOG to Base E
FMULT           := $BA28 ; Multiply FAC1 with FAC2
MLTPLY          := $BA59 ; Multiply a Byte Subroutine
CONUPK          := $BA8C ; Move a Floating Point Number from Memory into FAC2
MULDIV          := $BAB7 ; Add Exponent of FAC1 to Exponent of FAC2
MLDVEX          := $BAD4 ; Handle Underflow or Overflow
MUL10           := $BAE2 ; Multiply FAC1 by 10
TENC            := $BAF9 ; The Constant 10 in Five-Byte Floating Format
DIV10           := $BAFE ; Divide FAC1 by 10
FDIV            := $BB0F ; Divide a Number in Memory by FAC1
FDIVT           := $BB12 ; Divide FAC2 by FAC1
MOVFM           := $BBA2 ; Move a Floating Point Number from Memory to FAC1
MOV2F           := $BBC7 ; Move a Floating Point Number from FAC1 to Memory
MOVFA           := $BBFC ; Move a Floating Point Number from FAC2 to FAC1
MOVAF           := $BC0C ; Round and Move a Floating Point Number from FAC1 to FAC2
MOVEF           := $BC0F ; Copy FAC1 to FAC2 Without Rounding
ROUND           := $BC1B ; Round Accumulator #1 by Adjusting the Rounding Byte
SIGN            := $BC2B ; Put the Sign of Accumulator #1 into .A Register
SGN             := $BC39 ; Perform SGN
ABS             := $BC58 ; Perform ABS
FCOMP           := $BC5B ; Compare FAC1 to Memory
QINT            := $BC9B ; Convert FAC1 into Integer Within FAC1
INT             := $BCCC ; Perform INT
FIN             := $BCF3 ; Convert an ASCII String to a Floating Point Number FAC1
FINLOG          := $BD7E ; Add Signed Integer to FAC1
NO999           := $BDB3 ; Table of floating point constants holds the values 99,999,999.5, 999,999,999.5 and 1,000,000,000 (13 bytes)
INPRT           := $BDC0 ; Print IN Followed by a Line Number
LINPRT          := $BDCD ; Output a Number in ASCII Decimal Digits
FOUT            := $BDDD ; Convert Contents of FAC1 to ASCII String
FHALF           := $BF11 ; The Constant Value 1/2 in Five-Byte Floating Point Notation
FOUTBL          := $BF1C ; Powers of Minus Ten Constants Table
FDCEND          := $BF3A ; Table of Constants for TI$ Conversion
PBF_FREE1_1F    := $BF52 ; Unused area (31 bytes)
SQR             := $BF71 ; Perform SQR
FPWRT           := $BF7B ; Performs Exponentation (Power Calculation Called for by UPARROW)
NEGOP           := $BFB4 ; Perform NOT and >
EXPCON          := $BFBF ; Table of Constants for EXP and LOG in Five-Byte Floating Point Format
EXP             := $BFED ; Perform EXP (Part 1 - to be continued on $E000)

PC0_FREE1_4K    := $C000 ; (-$CFFF) 4K Free RAM (4K)

;
; VIC-II, SID, I/O Devices, Color RAM, and Character ROM
; $D000-$DFFF
;

; VIC-II registers $D000-$D02E
SP0X            := $D000 ; Sprite 0 Horizontal Position
SP0Y            := $D001 ; Sprite 0 Vertical Position
SP1X            := $D002 ; Sprite 1 Horizontal Position
SP1Y            := $D003 ; Sprite 1 Vertical Position
SP2X            := $D004 ; Sprite 2 Horizontal Position
SP2Y            := $D005 ; Sprite 2 Vertical Position
SP3X            := $D006 ; Sprite 3 Horizontal Position
SP3Y            := $D007 ; Sprite 3 Vertical Position
SP4X            := $D008 ; Sprite 4 Horizontal Position
SP4Y            := $D009 ; Sprite 4 Vertical Position
SP5X            := $D00A ; Sprite 5 Horizontal Position
SP5Y            := $D00B ; Sprite 5 Vertical Position
SP6X            := $D00C ; Sprite 6 Horizontal Position
SP6Y            := $D00D ; Sprite 6 Vertical Position
SP7X            := $D00E ; Sprite 7 Horizontal Position
SP7Y            := $D00F ; Sprite 7 Vertical Position
MSIGX           := $D010 ; Most Significant Bits of Sprites 0-7 Horizontal Position
SCROLY          := $D011 ; Vertical Fine Scrolling and Control Register
RASTER          := $D012 ; Read Current Raster Scan Line/Write Line to Compare for Raster IRQ
LPENX           := $D013 ; Light Pen Horizontal Position
LPENY           := $D014 ; Light Pen Vertical Position
SPENA           := $D015 ; Sprite Enable Register
SCROLX          := $D016 ; Horizontal Fine Scrolling and Control Register
YXPAND          := $D017 ; Sprite Vertical Expansion Register
VMCSB           := $D018 ; VIC-II Chip Memory Control Register
VICIRQ          := $D019 ; VIC Interrupt Flag Register
IRQMASK         := $D01A ; IRQ Mask Register
SPBGPR          := $D01B ; Sprite to Foreground Display Priority Register
SPMC            := $D01C ; Sprite Multicolor Registers
XXPAND          := $D01D ; Sprite Horizontal Expansion Register
SPSPCL          := $D01E ; Sprite to Sprite Collision Register
SPBGCL          := $D01F ; Sprite to Foreground Collision Register
; VIC-II Color Registers $D020-$D02E
EXTCOL          := $D020 ; Border Color Register
BGCOL0          := $D021 ; Background Color 0
BGCOL1          := $D022 ; Background Color 1
BGCOL2          := $D023 ; Background Color 2
BGCOL3          := $D024 ; Background Color 3
SPMC0           := $D025 ; Sprite Multicolor Register 0
SPMC1           := $D026 ; Sprite Multicolor Register 1
; Sprite Color Registers $D027-$D02E
SP0COL          := $D027 ; Sprite 0 Color Register (the default color value is 1, white)
SP1COL          := $D028 ; Sprite 1 Color Register (the default color value is 2, red)
SP2COL          := $D029 ; Sprite 2 Color Register (the default color value is 3, cyan)
SP3COL          := $D02A ; Sprite 3 Color Register (the default color value is 4, purple)
SP4COL          := $D02B ; Sprite 4 Color Register (the default color value is 5, green)
SP5COL          := $D02C ; Sprite 5 Color Register (the default color value is 6, blue)
SP6COL          := $D02D ; Sprite 6 Color Register (the default color value is 7, yellow)
SP7COL          := $D02E ; Sprite 7 Color Register (the default color value is 8, medium gray)
; Unusable $D02F-$D03F
; Unusable (VIC-II Register Images) $D040-$D3FF

; Sound Interface Device (SID) Registers registers $D400-$D41C
FRELO1          := $D400 ; Voice 1 Frequency Control (low byte)
FREHI1          := $D401 ; Voice 1 Frequency Control (high byte)
PWLO1           := $D402 ; Voice 1 Pulse Waveform Width (low byte)
PWHI1           := $D403 ; Voice 1 Pulse Waveform Width (high byte)
VCREG1          := $D404 ; Voice 1 Control Register
ATDCY1          := $D405 ; Voice 1 Attack/Decay Register
SUREL1          := $D406 ; Voice 1 Sustain/Release Control Register
FRELO2          := $D407 ; Voice 2 Frequency Control (low byte)
FREHI2          := $D408 ; Voice 2 Frequency Control (high byte)
PWLO2           := $D409 ; Voice 2 Pulse Waveform Width (low byte)
PWHI2           := $D40A ; Voice 2 Pulse Waveform Width (high byte)
VCREG2          := $D40B ; Voice 2 Control Register
ATDCY2          := $D40C ; Voice 2 Attack/Decay Register
SUREL2          := $D40D ; Voice 2 Sustain/Release Control Register
FRELO3          := $D40E ; Voice 3 Frequency Control (low byte)
FREHI3          := $D40F ; Voice 3 Frequency Control (high byte)
PWLO3           := $D410 ; Voice 3 Pulse Waveform Width (low byte)
PWHI3           := $D411 ; Voice 3 Pulse Waveform Width (high byte)
VCREG3          := $D412 ; Voice 3 Control Register
ATDCY3          := $D413 ; Voice 3 Attack/Decay Register
SUREL3          := $D414 ; Voice 3 Sustain/Release Control Register

; Filter Controls $D415-$D418
CUTLO           := $D415 ; Filter Cutoff Frequency (low byte)
CUTHI           := $D416 ; Filter Cutoff Frequency (high byte)
RESON           := $D417 ; Filter Resonance Control Register
SIGVOL          := $D418 ; Volume and Filter Select Register

POTX            := $D419 ; Read Game Paddle 1 (or 3) Position
POTY            := $D41A ; Read Game Paddle 2 (or 4) Position
RANDOM          := $D41B ; Read Oscillator 3/Random Number Generator
ENV3            := $D41C ; Envelope Generator 3 Output
; Unusable $D41D-$D41F
; Unusable (SID Register Images) $D420-$D7FF

; Color RAM
COLORRAM        := $D800 ; (-$DBFF) Color RAM (1K, however actually only 1000 bytes used)

; Complex Interface Adapter (CIA) #1 Registers $DC00-$DC0F
CIAPRA          := $DC00 ; Data Port Register A
CIAPRB          := $DC01 ; Data Port Register B
CIDDRA          := $DC02 ; Data Direction Register A
CIDDRB          := $DC03 ; Data Direction Register B
TIMALO          := $DC04 ; Timer A (low byte)
TIMAHI          := $DC05 ; Timer A (high byte)
TIMBLO          := $DC06 ; Timer B (low byte)
TIMBHI          := $DC07 ; Timer B (high byte)
TODTEN          := $DC08 ; Time of Day Clock Tenths of Seconds
TODSEC          := $DC09 ; Time of Day Clock Seconds
TODMIN          := $DC0A ; Time of Day Clock Minutes
TODHRS          := $DC0B ; Time of Day Clock Hours
CIASDR          := $DC0C ; Serial Data Port
CIAICR          := $DC0D ; Interrupt Control Register
CIACRA          := $DC0E ; Control Register A
CIACRB          := $DC0F ; Control Register B
; Unusable $DC10-$DCFF
; Unusable (CIA #1 Register Images) $DC10-$DCFF

; Complex Interface Adapter (CIA) #2 Registers $DD00-$DD0F
CIA2PRA         := $DD00 ; Data Port Register A
CIA2PRB         := $DD01 ; Data Port Register B
C2DDRA          := $DD02 ; Data Direction Register A
C2DDRB          := $DD03 ; Data Direction Register B
TI2ALO          := $DD04 ; Timer A (low byte)
TI2AHI          := $DD05 ; Timer A (high byte)
TI2BLO          := $DD06 ; Timer B (low byte)
TI2BHI          := $DD07 ; Timer B (high byte)
TO2TEN          := $DD08 ; Time of Day Clock Tenths of Seconds
TO2SEC          := $DD09 ; Time of Day Clock Seconds
TO2MIN          := $DD0A ; Time of Day Clock Minutes
TO2HRS          := $DD0B ; Time of Day Clock Hours
CI2SDR          := $DD0C ; Serial Data Port
CI2ICR          := $DD0D ; Interrupt Control Register
CI2CRA          := $DD0E ; Control Register A
CI2CRB          := $DD0F ; Control Register B
; Unusable $DD10-$DDFF
; Unusable (CIA #2 Register Images) $DF00-$DFFF

; Character Generator ROM $D000-$DFFF
CHRGENROM      := $D000 ; Character Generator ROM

;
; 8K Operating System Kernal ROM
; $E000-$FFFF
;

EXPCONT         := $E000 ; Continuation of EXP Routine from the end of the BASIC ROM
POLY1           := $E043 ; Function Series Evaluation Subroutine 1
POLY2           := $E059 ; Function Series Evaluation Subroutine 2
RMULC           := $E08D ; Multiplicative Constant for RND
RADDC           := $E092 ; Additive Constant for RND
RND             := $E097 ; Perform RND
IOROUTINES      := $E0F9 ; Call Kernal I/O Routines 
SYST            := $E12A ; Perform SYS
SAVET           := $E156 ; Perform SAVE
VERIFYT         := $E165 ; Perform VERIFY
LOADT           := $E168 ; Perform LOAD
OPENT           := $E1BE ; Perform OPEN
CLOSET          := $E1C7 ; Perform CLOSE
SETIOPARAMS     := $E1D4 ; Set Parameters for LOAD, VERIFY, and SAVE
GETINTBYCOMMA   := $E200 ; Skip Comma and Get Integer in .X
FETCHCURRCHR    := $E206 ; Fetch Current Character and Check for End of Line
CHKCOMMA        := $E20E ; Check for Comma
SETIOPARAMS2    := $E219 ; Set Parameters for OPEN and CLOSE
COS             := $E264 ; Perform COS
SIN             := $E268 ; Perform SIN
TAN             := $E2B4 ; Perform TAN
; Table of Constants for Evaluation of SIN, COS, and TAN $E2E0-$E30D
PI2             := $E2E0 ; The Five-Byte Floating Point Representation of the Constant PI/2
TWOPI           := $E2E5 ; The Five-Byte Floating Point Representation of the Constant 2*PI
FR4             := $E2EA ; The Five-Byte Floating Point Representation of the Constant 1/4
SINCON          := $E2EF ; Polynomial Table Constants for Evaluation of SIN, COS, and TAN
ATN             := $E30E ; Perform ATN
ATNCON          := $E33E ; Table of Constants for ATN Evaluation
BASSFT          := $E37B ; Warm Start BASIC
ERRMSGHANDLER   := $E38B ; Error Message Handler
COLDSTARTBASIC  := $E394 ; Cold Start BASIC
INITAT          := $E3A2 ; Text of the CHRGET Routine Which Runs at 115 ($73)
INITRNDSEED     := $E3BA ; Initial RND Seed Value
INIT            := $E3BF ; Initialize BASIC
STARTUPMSG      := $E422 ; Print BASIC Start-Up Messages
BASICROUTINES   := $E447 ; Table of Vectors to Important BASIC Routines
CPYBASVECS2RAM  := $E453 ; Copy BASIC Vectors to RAM
WORDS           := $E460 ; Power-Up Messages
CHKOUTPATCH     := $E4AD ; Patch for BASIC Call of CHKOUT
UNUSEDPATCH     := $E4B7 ; Unused Bytes For Future Patches (35 bytes)
RESETCHRCOL     := $E4DA ; Clear Color RAM to the Color in Background Color Register 0
PAUSECASETTE    := $E4E0 ; Pause after Finding a File on Cassette
BAUDTABLEPAL    := $E4EC ; Baud Rate Table for European (PAL) Standard Monitors
IOBASE0         := $E500 ; Store Base Address of Memory-Mapped I/O Devices in .X and .Y Registers
SCREEN0         := $E505 ; Store Number of Screen Rows and Columns in .Y and .X
PLOT0           := $E50A ; Read/Set Location of the Cursor
INITSCRKEYB     := $E518 ; Initialize Screen and Keyboard
CLRSCR          := $E544 ; Initialize the Screen Line Link Table and Clear the Screen 
HOMECRS         := $E566 ; Home the Cursor
SET2CURSCRLINE  := $E56C ; Set Pointer to Current Screen Line
RESETVICII      := $E5A0 ; Set Default I/O Devices and Set Default Values for VIC-II Chip Registers
LP2             := $E5B4 ; Get a Character from the Keyboard Buffer 
KBDREAD         := LP2
WAITFORRETURN   := $E5CA ; Wait for a Carriage Return from the Keyboard
INPUTCHR        := $E632 ; Input a Character from Screen or Keyboard
TESTQUOTE       := $E684 ; Test for Quote Marks
ADDCHR2SCR      := $E691 ; Add a Character to the Screen
CHROUTEXIT      := $E6A8 ; Return from Outputting a Character to the Screen
ADVANCECRS      := $E6B6 ; Advance the Cursor
RETREATCRS      := $E6ED ; Retreat the Cursor
BACKPREVLINCRS  := $E701 ; Back on to Previous Line
CHROUTMAIN      := $E716 ; Output to the Screen
NEXTLINCRS      := $E87C ; Move Cursor to Next Line
CROUT           := $E891 ; Output a Carriage Return
CHKLINDEC       := $E8A1 ; If at the Beginning of a Screen Line, Move Cursor to Previous Line
CHKLININC       := $E8B3 ; If at the End of a Screen Line, Move Cursor to the Next Line
CHKCOLCHG       := $E8CB ; Check for a Color Change
COLCODEQU       := $E8D1 ; PETASCII Color Code Equivalent Table (16 bytes)
SCROLLSCR       := $E8EA ; Scroll Screen
INSBLANKLIN     := $E965 ; Insert a Blank Line on the Screen
MOVSCRLIN       := $E9C8 ; Move Screen Line
SYNCCOLTRANS    := $E9E0 ; Set Temporary Color Pointer for Scrolling
SETSTARTLIN     := $E9F0 ; Set Pointer to Screen Address of Start of Line
CLRSCRLINE      := $E9FF ; Clear Screen Line
PRNT2SCR        := $EA13 ; Set Cursor Blink Timing and Color Memory Address for Print to Screen
STORE2SCR       := $EA1C ; Store to Screen
SYNCCOLPTR      := $EA24 ; Synchronize Color RAM Pointer to Screen Line Pointer 
UPDCRAMPTR      := SYNCCOLPTR
IRQENTRY        := $EA31 ; IRQ Interrupt Entry
IRQENTRYPTR     := IRQENTRY
SCNKEY0         := $EA87 ; Read the Keyboard
INPUTKEY        := $EAE0 ; Decode the Keystroke and Place its ASCII Value in the Keyboard Buffer
SETUPKEYBDEC    := $EB48 ; Set Up the Proper Keyboard Decode Table
KEYBDECVECS     := $EB79 ; Keyboard Decode Table Vectors (8 bytes)
KEYBOARD        := $EB81 ; Standard Keyboard Matrix Decode Table (65 bytes)
KEYBOARDSHIFT   := $EBC2 ; SHIFTed Keyboard Matrix Decode Table (65 bytes)
KEYBOARDCOMM    := $EC03 ; Commodore Logo Keyboard Matrix Decode Table (65 bytes)
SEYCHRSET       := $EC44 ; Set Lowercase/Uppercase or Uppercase/Graphics Character Set
SWITCHCHRSET    := $EC5E ; Set Flag to Enable or Disable Switching Character Sets
KEYBOARDCTRL    := $EC78 ; Control Keyboard Matrix Decode Table (65 bytes)
VICDEFAULTREGS  := $ECB9 ; Video Chip Register Default Table
MSGSHIFTRUN     := $ECE7 ; Text for Keyboard Buffer When SHIFT/RUN is Pressed
SCRLINEADRS     := $ECF0 ; Low Byte Table of Screen Line Addresses
TALK0           := $ED09 ; Send TALK to a Device on the Serial Bus
LISTEN0         := $ED0C ; Send LISTEN to a Device on the Serial Bus
CODE            := $ED11 ; Send Command Code to a Device on the Serial Bus
BYTE            := $ED40 ; Send a Byte on the Serial Bus
TIMOUTERR       := $EDB0 ; Time-Out Error on Serial Bus
SECOND0         := $EDB9 ; Send a Secondary Address to a Device on the Serial Bus after LISTEN
TKSA0           := $EDC7 ; Send a Secondary Address to a Device on the Serial Bus after TALK
CIOUT0          := $EDDD ; Send a Byte to an I/O Device over the Serial Bus
UNTLK0          := $EDEF ; Send UNTALK to a Device on the Serial Bus
UNLSN0          := $EDFE ; Send UNLISTED to a Device on the Serial Bus
ACPTR0          := $EE13 ; Receive a Byte of Data from a Device on the Serial Bus
SETCLKLINELOW   := $EE85 ; Set the Serial Clock Line Low (Active)
SETCLKLINEHIGH  := $EE8E ; Set the Serial Clock Line High (Inactive)
SERIALOUTPUT1   := $EE97 ; Set Serial Bus Data Output Line Low
SERIALOUTPUT0   := $EEA9 ; Get Serial Bus Data Input Bit and Clock Pulse Input Bit
DELAY1MS        := $EEB3 ; Perform a One-Millisecond Delay
SENDRS232BIT    := $EEBB ; Send Next RS-232 Bit (NMI)
NODSRCTSERR     := $EF2E ; Handle RS-232 Errors
COMPUTEBITCNT   := $EF4A ; Set the Word Length For the Current RS-232 Character
RECVRS232BIT    := $EF59 ; Receive Next RS-232 Bit (NMI)
SETUPRECEIVE    := $EF7E ; Setup to Receive a New Byte from RS-232
PROCRS232BYTE   := $EF90 ; Test If Start Bit Received from RS-232
CHKRCVBUFOVRUN  := $EF97 ; Put a Byte of Received Data into RS-232 Receive Buffer
CHKOUTRS232     := $EFE1 ; CHKOUT for the RS-232 device
CHROUTRS232     := $F014 ; CHROUT for the RS-232 Device
CHKINRS232      := $F04D ; CHKIN for the RS-232 Device
GETINRS232      := $F086 ; GETIN for the RS-232 Device
SERIALBUSIDLE   := $F0A4 ; Stop CIA #2 RS-232 NMIs for Serial/Cassette Routines
KERNALIOMSGS    := $F0BD ; Kernal Control Messages
PRNMSGIFDIRECT  := $F12B ; Print Kernal Error Message if in Direct Mode
GETIN0          := $F13E ; Get One Byte from the Input Device
CHRIN0          := $F157 ; Input a Character from the Current Device
CHROUT0         := $F1CA ; Output a Byte
CHKIN0          := $F20E ; Designate a Logical File As the Current Input Channel
CHKOUT0         := $F250 ; Designate a Logical File As the Current Output Channel
CLOSE0          := $F291 ; Close a Logical I/O File
FINDFILE        := $F30F ; Find the File in the Logical File Table
SETFILEVALUES   := $F31F ; Set Current Logical File, Current Device, and Current Seconday Address
CLALL0          := $F32F ; Close All Logical I/O Files
CLRCHN0         := $F333 ; Restore Current Input and Output Devices to the Default Devices
OPEN0           := $F34A ; Open a Logical I/O File
LOAD0           := $F49E ; Load RAM from a Device
PRINTSEARCHING  := $F5A5 ; Print SEARCHING Message if in Direct Mode
PRNLOADVERIFY   := $F5D2 ; Print LOADING or VERIFYING
SAVE0           := $F5DD ; Save RAM to a Device
PRINTSAVING     := $F68F ; If in Direct Mode, Print SAVING and Filename
UDTIM0          := $F69B ; Update the Software Clock and Check for the STOP Key
RDTIM0          := $F6DD ; Read the Time From the Software Clock into the .A, .X, and .Y Registers
SETTIM0         := $F6E4 ; Set the Software Clock from the .A, .X, and .Y Registers
STOP0           := $F6ED ; Test STOP Key
OUTIOERRMSGS    := $F6FB ; Set Kernal I/O Error Messages
FINDTAPEHEADER  := $F72C ; Get Next Tape File Header from Cassette
WRITETAPEHEAD   := $F76A ; Write Tape File Header Block
GETBUFADDR      := $F7D0 ; Put Pointer to Tape Buffer in .X and .Y Registers
SETBUFSTARTEND  := $F7D7 ; Set I/O Area Start and End Pointers to Tape Buffer Start and End Address
FINDTAPEFNAME   := $F7EA ; Search Tape for a Filename
PRNPRESSPLAYTA  := $F817 ; Test Cassette Buttons and Handle Messages for Tape Read
CHKTAPESTATUS   := $F82E ; Check Cassette Switch
PRNPRESSRECORD  := $F838 ; Test Cassette Buttons and Handle Messages for Tape Write
INITTAPEREAD    := $F841 ; Start Reading a Block of Data from the Cassette
INITTAPEWRITE   := $F864 ; Start Writing a Block of Data to the Cassette
COMMONTAPECODE  := $F875 ; Common Code for Reading a Data Block from Tape and Writing a Block to Tape
CHKTAPESTOP     := $F8D0 ; Test the STOP Key during Cassette I/O Operations
SETREADTIMING   := $F8E2 ; Adjust CIA #1 Timer A for Tape Bit Timing
READTAPEDATA    := $F92C ; Read Tape Data (IRQ)
STORETAPECHRS   := $FA60 ; Receive and Store the Next Character from Cassette
RESETTAPEPTR    := $FB8E ; Move the Tape SAVE/LOAD Address into the Pointer at 172
NEWCHRSETUP     := $FB97 ; Reset Counters for Reading or Writing a New Byte of Cassette Data
SENDTONE2TAPE   := $FBA6 ; Toggle the Tape Data Output Line
WRITEDATA2TAP2  := $FBC8 ; Write Data to Cassette--Part 2 (IRQ)
WRITEDATA2TAP1  := $FC6A ; Write Data fo Cassette--Part 1 (IRQ)
RESTOREDEFIRQ   := $FC93 ; Restores the Default IRQ Routine
RESETIRQVECTOR  := $FCB8 ; At the end of the tape I/O operations, it turns the screen back on and stops the cassette motor.
TURNOFFTAPE     := $FCCA ; Turn Off the Tape Motor
CHKREADWRITE    := $FCD1 ; Check the Tape Read/Write Pointer
SETREADWRITE    := $FCDB ; Advance the Tape Read/Write Pointer
RESET0          := $FCE2 ; Power-On Reset Routine
CHKAUTOCARTR    := $FD02 ; Check for an Autostart Cartridge
AUTOCARTMSG     := $FD10 ; Text for Autostart Cartridge Check (5 bytes)
RESTOR0         := $FD15 ; Restore RAM Vectors for Default I/O Routines
VECTOR0         := $FD1A ; Set the RAM Vector Table from the Table Pointed to by .X and .Y
RESETVECTORS    := $FD30 ; Table of RAM Vectors to the Default I/O Routines
RAMTAS0         := $FD50 ; Perform RAM Test and Set Pointers to the Top and Bottom of RAM
IRQVECTORS      := $FD9B ; Table of IRQ Vectors
IOINIT0         := $FDA3 ; Initialize CIA I/O Devices
SETNAM0         := $FDF9 ; Set Filename Parameters
SETLFS0         := $FE00 ; Set Logical File Number, Device Number, and Secondary Address
READST0         := $FE07 ; Read the I/O Status Word
SETMSG0         := $FE18 ; Set the Message Control Flag
SETTMO0         := $FE21 ; Set Time-Out Flag for IEEE Bus
MEMTOP0         := $FE25 ; Read/Set Top of RAM Pointer
MEMBOT0         := $FE34 ; Read/Set Bottom of RAM Pointer
NMI0            := $FE43 ; NMI Interrupt Entry Point
WARMSTARTBASIC  := $FE66 ; BRK, Warm Start Routine
NMIRS232HANDL   := $FE72 ; NMI RS-232 Handler
NMIEXIT         := $FEBC ; Exit Interrupt
RSR232TIMINGS   := $FEC2 ; RS-232 Baud Rate Tables for U.S. Television Standard (NTSC)
NMIRS232IN      := $FED6 ; RS-232 Receive the Next Bit (NMI)
LOADTIMER       := $FF1A ; Load the Timer with Prescaler Values from the Baud Rate Lookup Table
IRQENTRY0       := $FF48 ; Main IRQ/BRK Interrupt Entry Point
CINT0           := $FF5B ; Initialize Screen Editor and VIC-II Chip
TIMERPATCH      := $FF6E ; End of Routine to Set Timer for Sixtieth of a Second IRQ
KERNALVERSION   := $FF80 ; Kernal Version Identifier Byte
; Kernal Jump Table
CINT            := $FF81 ; initialize screen editor and video chip
IOINIT          := $FF84 ; initialize I/O devices
RAMTAS          := $FF87 ; initialize RAM, tape buffer, screen
RESTOR          := $FF8A ; restore default I/O vectors
VECTOR          := $FF8D ; read/set I/O vector table
SETMSG          := $FF90 ; set Kernal message control flag
SECOND          := $FF93 ; send secondary address after LISTEN
TKSA            := $FF96 ; send secondary address after TALK
MEMTOP          := $FF99 ; read/set top of memory pointer
MEMBOT          := $FF9C ; read/set bottom of memory pointer
SCNKEY          := $FF9F ; scan the keyboard
SETTMO          := $FFA2 ; set time-out flag for IEEE bus
ACPTR           := $FFA5 ; input byte from serial bus
CIOUT           := $FFA8 ; output byte to serial bus
UNTLK           := $FFAB ; command serial bus device to UNTALK
UNLSN           := $FFAE ; command serial bus device to UNLISTEN
LISTEN          := $FFB1 ; command serial bus device to LISTEN
TALK            := $FFB4 ; command serial bus device to TALK
READST          := $FFB7 ; read I/O status word
SETLFS          := $FFBA ; set logical file parameters
SETNAM          := $FFBD ; set filename parameters
OPEN            := $FFC0 ; open a logical file
CLOSE           := $FFC3 ; close a logical file
CHKIN           := $FFC6 ; define an input channel
CHKOUT          := $FFC9 ; define an output channel
CLRCHN          := $FFCC ; restore default devices
CHRIN           := $FFCF ; input a character
CHROUT          := $FFD2 ; output a character
LOAD            := $FFD5 ; load from device
SAVE            := $FFD8 ; save to a device
SETTIM          := $FFDB ; set the software clock
RDTIM           := $FFDE ; read the software clock
STOP            := $FFE1 ; check the STOP key
GETIN           := $FFE4 ; get a character
CLALL           := $FFE7 ; close all files
UDTIM           := $FFEA ; update the software clock
SCREEN          := $FFED ; read number of screen rows and columns
PLOT            := $FFF0 ; read/set position of cursor on screen
IOBASE          := $FFF3 ; read base address of I/O devices
; 6510 Hardware Vectors
NMI             := $FFFA ; NMI Interrupt Entry Point
RESET           := $FFFC ; Power-on Reset Routine
IRQ             := $FFFE ; Main IRQ/BRK Interrupt Entry Point

.endif
