.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purpose registers

.section .data

.balign 16

glabel Obj_Switch_InitVars
 .word 0x012A0000, 0x00000010, 0x00030000, 0x00000258
.word ObjSwitch_Init
.word ObjSwitch_Destroy
.word ObjSwitch_Update
.word ObjSwitch_Draw
glabel D_80B9EC20
 .word 0x41200000
glabel D_80B9EC24
 .word 0x41200000
glabel D_80B9EC28
 .word 0x00000000
glabel D_80B9EC2C
 .word 0x41F00000
glabel D_80B9EC30
 .word 0x41F00000
glabel D_80B9EC34
 .word 0x00000000, 0x00000000, 0x00000000, 0x40000040, 0x00000000, 0x00010000, 0xC1A00000, 0x41980000, 0xC1A00000, 0xC1A00000, 0x41980000, 0x41A00000, 0x41A00000, 0x41980000, 0x41A00000, 0x00000000, 0x00000000, 0x00000000, 0x40000040, 0x00000000, 0x00010000, 0x41A00000, 0x41980000, 0x41A00000, 0x41A00000, 0x41980000, 0xC1A00000, 0xC1A00000, 0x41980000, 0xC1A00000
glabel D_80B9ECAC
 .word 0x0A000900, 0x00020000, 0x00000002
.word D_80B9EC34
glabel D_80B9ECBC
 .word 0x04000000, 0x00000000, 0x00000000, 0x0001F824, 0x00000000, 0x00010000, 0x00000000, 0x41B80000, 0x41080000, 0xC1B80000, 0x00000000, 0x41080000, 0x00000000, 0xC1B80000, 0x41080000, 0x00000000, 0x00000000, 0x00000000, 0x0001F824, 0x00000000, 0x00010000, 0x00000000, 0x41B80000, 0x41080000, 0x00000000, 0xC1B80000, 0x41080000, 0x41B80000, 0x00000000, 0x41080000
glabel D_80B9ED34
 .word 0x0A000900, 0x00020000, 0x00000002
.word D_80B9ECBC
glabel D_80B9ED44
 .word 0x00000000, 0x00000000, 0x00000000, 0xEFC1FFFE, 0x00000000, 0x00010100, 0x00000000, 0x012C0000, 0x00140064
glabel D_80B9ED68
 .word 0x09000939, 0x20000000, 0x00000001
.word D_80B9ED44
glabel D_80B9ED78
 .word 0xC8500064, 0xB0F407D0, 0xB0F80190, 0x30FC07D0
glabel D_80B9ED88
 .word 0x05005800, 0x05006170, 0x05005D50, 0x05005D50
glabel D_80B9ED98
 .word 0x0500A8A0, 0x050098A0, 0x0500A0A0, 0x050090A0, 0x0500B0A0, 0x0500B8A0, 0x0500C0A0, 0x0500C0A0
glabel D_80B9EDB8
 .word 0x05006610, 0x05006810
glabel D_80B9EDC0
 .word 0x05006E60
glabel D_80B9EDC4
 .word 0x05007488, 0x00000000, 0x00000000, 0x05006E60
glabel D_80B9EDD4
 .word 0x05006D10, 0x05007340, 0x00000000, 0x00000000, 0x05006D10
glabel D_80B9EDE8
 .word func_80B9E748
.word func_80B9E788
.word func_80B9E7B4
.word func_80B9E904
.word func_80B9E904
.word 0x00000000
