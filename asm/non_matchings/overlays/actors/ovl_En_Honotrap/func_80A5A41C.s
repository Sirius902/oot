glabel func_80A5A41C
/* 007EC 80A5A41C 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 007F0 80A5A420 44812000 */  mtc1    $at, $f4                   ## $f4 = 1.00
/* 007F4 80A5A424 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 007F8 80A5A428 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 007FC 80A5A42C 240E0028 */  addiu   $t6, $zero, 0x0028         ## $t6 = 00000028
/* 00800 80A5A430 00802825 */  or      $a1, $a0, $zero            ## $a1 = 00000000
/* 00804 80A5A434 A48E0228 */  sh      $t6, 0x0228($a0)           ## 00000228
/* 00808 80A5A438 E4840060 */  swc1    $f4, 0x0060($a0)           ## 00000060
/* 0080C 80A5A43C 84840032 */  lh      $a0, 0x0032($a0)           ## 00000032
/* 00810 80A5A440 0C01DE1C */  jal     Math_SinS
              ## sins?
/* 00814 80A5A444 AFA50018 */  sw      $a1, 0x0018($sp)           
/* 00818 80A5A448 46000180 */  add.s   $f6, $f0, $f0              
/* 0081C 80A5A44C 8FA50018 */  lw      $a1, 0x0018($sp)           
/* 00820 80A5A450 E4A6005C */  swc1    $f6, 0x005C($a1)           ## 0000005C
/* 00824 80A5A454 0C01DE0D */  jal     Math_CosS
              ## coss?
/* 00828 80A5A458 84A40032 */  lh      $a0, 0x0032($a1)           ## 00000032
/* 0082C 80A5A45C 46000200 */  add.s   $f8, $f0, $f0              
/* 00830 80A5A460 8FA50018 */  lw      $a1, 0x0018($sp)           
/* 00834 80A5A464 3C0F80A6 */  lui     $t7, %hi(func_80A5A484)    ## $t7 = 80A60000
/* 00838 80A5A468 25EFA484 */  addiu   $t7, $t7, %lo(func_80A5A484) ## $t7 = 80A5A484
/* 0083C 80A5A46C E4A80064 */  swc1    $f8, 0x0064($a1)           ## 00000064
/* 00840 80A5A470 ACAF014C */  sw      $t7, 0x014C($a1)           ## 0000014C
/* 00844 80A5A474 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00848 80A5A478 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 0084C 80A5A47C 03E00008 */  jr      $ra                        
/* 00850 80A5A480 00000000 */  nop