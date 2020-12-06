.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purpose registers

.section .data

.balign 16

glabel D_80ADD6F0
 .word 0xFFAAFFFF, 0xFFC800FF, 0x00AAFFFF, 0xAAFF00FF
glabel D_80ADD700
 .word 0x6400FFFF, 0xFF0000FF, 0x0000FFFF, 0x009600FF
glabel En_Po_Sisters_InitVars
 .word 0x00910500, 0x00005215, 0x00990000, 0x00000338
.word EnPoSisters_Init
.word EnPoSisters_Destroy
.word EnPoSisters_Update
.word EnPoSisters_Draw
glabel D_80ADD730
 .word 0x03110939, 0x10010000, 0x00000000, 0xFFCFFFFF, 0x00080000, 0x4FC7FFEA, 0x00000000, 0x01050100, 0x0012003C, 0x000F0000, 0x00000000
glabel D_80ADD75C
 .word 0x0A000019, 0x003C2800
glabel D_80ADD764
 .word 0xF0020102, 0x00020202, 0xE1E2E402, 0x02020202, 0x02000000, 0x0000E1E4, 0xE2E2E8E4, 0x00000400
glabel D_80ADD784
 .word 0x00000000
glabel D_80ADD788
 .word 0xC8500007, 0x304C1770
glabel D_80ADD790
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80ADD79C
 .word 0xB000D000, 0x50003000
glabel D_80ADD7A4
 .word 0xFFEA0151, 0xF958FE51, 0x036FF2AE, 0x0225036F, 0xF2AE06B5, 0x0203FAC4
glabel D_80ADD7BC
 .word 0x42F00000, 0x437A0000, 0xC4B18000
glabel D_80ADD7C8
 .word 0x06001DE0, 0x06002F88, 0x06003628, 0x06003DC8
glabel D_80ADD7D8
 .word 0x06001CB0, 0x06002EB8, 0x06003880, 0x06004020
glabel D_80ADD7E8
 .word 0x50006400, 0x500F0000, 0x00463200, 0x46460000
glabel D_80ADD7F8
 .word 0x447A0000, 0xC4D48000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
