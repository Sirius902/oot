.late_rodata
glabel D_80AEA890
    .float 2500.0

.text
glabel func_80AE8744
/* 00304 80AE8744 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 00308 80AE8748 A0800370 */  sb      $zero, 0x0370($a0)         ## 00000370
/* 0030C 80AE874C 3C0180AF */  lui     $at, %hi(D_80AEA890)       ## $at = 80AF0000
/* 00310 80AE8750 E4800364 */  swc1    $f0, 0x0364($a0)           ## 00000364
/* 00314 80AE8754 C424A890 */  lwc1    $f4, %lo(D_80AEA890)($at)  
/* 00318 80AE8758 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 0031C 80AE875C 44811000 */  mtc1    $at, $f2                   ## $f2 = 1.00
/* 00320 80AE8760 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 00324 80AE8764 00027180 */  sll     $t6, $v0,  6               
/* 00328 80AE8768 008E1821 */  addu    $v1, $a0, $t6              
/* 0032C 80AE876C E4800250 */  swc1    $f0, 0x0250($a0)           ## 00000250
/* 00330 80AE8770 E4800258 */  swc1    $f0, 0x0258($a0)           ## 00000258
/* 00334 80AE8774 E4800228 */  swc1    $f0, 0x0228($a0)           ## 00000228
/* 00338 80AE8778 E48401FC */  swc1    $f4, 0x01FC($a0)           ## 000001FC
/* 0033C 80AE877C E4820240 */  swc1    $f2, 0x0240($a0)           ## 00000240
/* 00340 80AE8780 E4820238 */  swc1    $f2, 0x0238($a0)           ## 00000238
/* 00344 80AE8784 E4600310 */  swc1    $f0, 0x0310($v1)           ## 00000310
/* 00348 80AE8788 E4600318 */  swc1    $f0, 0x0318($v1)           ## 00000318
/* 0034C 80AE878C E46002E8 */  swc1    $f0, 0x02E8($v1)           ## 000002E8
/* 00350 80AE8790 E46002D0 */  swc1    $f0, 0x02D0($v1)           ## 000002D0
/* 00354 80AE8794 E46002D8 */  swc1    $f0, 0x02D8($v1)           ## 000002D8
/* 00358 80AE8798 E46002A8 */  swc1    $f0, 0x02A8($v1)           ## 000002A8
/* 0035C 80AE879C E4600290 */  swc1    $f0, 0x0290($v1)           ## 00000290
/* 00360 80AE87A0 E4600298 */  swc1    $f0, 0x0298($v1)           ## 00000298
/* 00364 80AE87A4 E4600268 */  swc1    $f0, 0x0268($v1)           ## 00000268
/* 00368 80AE87A8 E4600228 */  swc1    $f0, 0x0228($v1)           ## 00000228
/* 0036C 80AE87AC E4600250 */  swc1    $f0, 0x0250($v1)           ## 00000250
/* 00370 80AE87B0 E4600258 */  swc1    $f0, 0x0258($v1)           ## 00000258
/* 00374 80AE87B4 E46202F8 */  swc1    $f2, 0x02F8($v1)           ## 000002F8
/* 00378 80AE87B8 E4620300 */  swc1    $f2, 0x0300($v1)           ## 00000300
/* 0037C 80AE87BC E46202B8 */  swc1    $f2, 0x02B8($v1)           ## 000002B8
/* 00380 80AE87C0 E46202C0 */  swc1    $f2, 0x02C0($v1)           ## 000002C0
/* 00384 80AE87C4 E4620278 */  swc1    $f2, 0x0278($v1)           ## 00000278
/* 00388 80AE87C8 E4620280 */  swc1    $f2, 0x0280($v1)           ## 00000280
/* 0038C 80AE87CC E4620238 */  swc1    $f2, 0x0238($v1)           ## 00000238
/* 00390 80AE87D0 E4620240 */  swc1    $f2, 0x0240($v1)           ## 00000240
/* 00394 80AE87D4 908F0375 */  lbu     $t7, 0x0375($a0)           ## 00000375
/* 00398 80AE87D8 3C0980AF */  lui     $t1, %hi(func_80AE95B0)    ## $t1 = 80AF0000
/* 0039C 80AE87DC 2408003C */  addiu   $t0, $zero, 0x003C         ## $t0 = 0000003C
/* 003A0 80AE87E0 11E00007 */  beq     $t7, $zero, .L80AE8800     
/* 003A4 80AE87E4 252995B0 */  addiu   $t1, $t1, %lo(func_80AE95B0) ## $t1 = 80AE95B0
/* 003A8 80AE87E8 3C1980AF */  lui     $t9, %hi(func_80AE9C88)    ## $t9 = 80AF0000
/* 003AC 80AE87EC 24180064 */  addiu   $t8, $zero, 0x0064         ## $t8 = 00000064
/* 003B0 80AE87F0 27399C88 */  addiu   $t9, $t9, %lo(func_80AE9C88) ## $t9 = 80AE9C88
/* 003B4 80AE87F4 A49801EA */  sh      $t8, 0x01EA($a0)           ## 000001EA
/* 003B8 80AE87F8 03E00008 */  jr      $ra                        
/* 003BC 80AE87FC AC99014C */  sw      $t9, 0x014C($a0)           ## 0000014C
.L80AE8800:
/* 003C0 80AE8800 A48801EA */  sh      $t0, 0x01EA($a0)           ## 000001EA
/* 003C4 80AE8804 AC89014C */  sw      $t1, 0x014C($a0)           ## 0000014C
/* 003C8 80AE8808 03E00008 */  jr      $ra                        
/* 003CC 80AE880C 00000000 */  nop