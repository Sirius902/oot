glabel BgGanonOtyuka_Update
/* 007C8 808760E8 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 007CC 808760EC AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 007D0 808760F0 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 007D4 808760F4 8C990164 */  lw      $t9, 0x0164($a0)           ## 00000164
/* 007D8 808760F8 0320F809 */  jalr    $ra, $t9                   
/* 007DC 808760FC 00000000 */  nop
/* 007E0 80876100 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 007E4 80876104 908E016D */  lbu     $t6, 0x016D($a0)           ## 0000016D
/* 007E8 80876108 84820168 */  lh      $v0, 0x0168($a0)           ## 00000168
/* 007EC 8087610C 25CF0001 */  addiu   $t7, $t6, 0x0001           ## $t7 = 00000001
/* 007F0 80876110 10400003 */  beq     $v0, $zero, .L80876120     
/* 007F4 80876114 A08F016D */  sb      $t7, 0x016D($a0)           ## 0000016D
/* 007F8 80876118 2458FFFF */  addiu   $t8, $v0, 0xFFFF           ## $t8 = FFFFFFFF
/* 007FC 8087611C A4980168 */  sh      $t8, 0x0168($a0)           ## 00000168
.L80876120:
/* 00800 80876120 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00804 80876124 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00808 80876128 03E00008 */  jr      $ra                        
/* 0080C 8087612C 00000000 */  nop