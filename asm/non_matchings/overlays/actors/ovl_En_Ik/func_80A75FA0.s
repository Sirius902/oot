glabel func_80A75FA0
/* 01C90 80A75FA0 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 01C94 80A75FA4 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 01C98 80A75FA8 AFB10020 */  sw      $s1, 0x0020($sp)           
/* 01C9C 80A75FAC AFB0001C */  sw      $s0, 0x001C($sp)           
/* 01CA0 80A75FB0 8CAE1C44 */  lw      $t6, 0x1C44($a1)           ## 00001C44
/* 01CA4 80A75FB4 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01CA8 80A75FB8 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 01CAC 80A75FBC AFAE0034 */  sw      $t6, 0x0034($sp)           
/* 01CB0 80A75FC0 908F02FB */  lbu     $t7, 0x02FB($a0)           ## 000002FB
/* 01CB4 80A75FC4 0C29D70E */  jal     func_80A75C38              
/* 01CB8 80A75FC8 A08F02FA */  sb      $t7, 0x02FA($a0)           ## 000002FA
/* 01CBC 80A75FCC 8618001C */  lh      $t8, 0x001C($s0)           ## 0000001C
/* 01CC0 80A75FD0 5700000B */  bnel    $t8, $zero, .L80A76000     
/* 01CC4 80A75FD4 8E190304 */  lw      $t9, 0x0304($s0)           ## 00000304
/* 01CC8 80A75FD8 921900AF */  lbu     $t9, 0x00AF($s0)           ## 000000AF
/* 01CCC 80A75FDC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01CD0 80A75FE0 2B21000B */  slti    $at, $t9, 0x000B           
/* 01CD4 80A75FE4 50200006 */  beql    $at, $zero, .L80A76000     
/* 01CD8 80A75FE8 8E190304 */  lw      $t9, 0x0304($s0)           ## 00000304
/* 01CDC 80A75FEC 0C29E073 */  jal     func_80A781CC              
/* 01CE0 80A75FF0 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 01CE4 80A75FF4 1000006A */  beq     $zero, $zero, .L80A761A0   
/* 01CE8 80A75FF8 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 01CEC 80A75FFC 8E190304 */  lw      $t9, 0x0304($s0)           ## 00000304
.L80A76000:
/* 01CF0 80A76000 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01CF4 80A76004 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 01CF8 80A76008 0320F809 */  jalr    $ra, $t9                   
/* 01CFC 80A7600C 00000000 */  nop
/* 01D00 80A76010 9202037C */  lbu     $v0, 0x037C($s0)           ## 0000037C
/* 01D04 80A76014 8FA30034 */  lw      $v1, 0x0034($sp)           
/* 01D08 80A76018 30480002 */  andi    $t0, $v0, 0x0002           ## $t0 = 00000000
/* 01D0C 80A7601C 11000021 */  beq     $t0, $zero, .L80A760A4     
/* 01D10 80A76020 00000000 */  nop
/* 01D14 80A76024 8E0A0370 */  lw      $t2, 0x0370($s0)           ## 00000370
/* 01D18 80A76028 3049FFFD */  andi    $t1, $v0, 0xFFFD           ## $t1 = 00000000
/* 01D1C 80A7602C A209037C */  sb      $t1, 0x037C($s0)           ## 0000037C
/* 01D20 80A76030 146A001C */  bne     $v1, $t2, .L80A760A4       
/* 01D24 80A76034 00000000 */  nop
/* 01D28 80A76038 80620A78 */  lb      $v0, 0x0A78($v1)           ## 00000A78
/* 01D2C 80A7603C 1C40000E */  bgtz    $v0, .L80A76078            
/* 01D30 80A76040 A3A20033 */  sb      $v0, 0x0033($sp)           
/* 01D34 80A76044 2841FFD9 */  slti    $at, $v0, 0xFFD9           
/* 01D38 80A76048 10200003 */  beq     $at, $zero, .L80A76058     
/* 01D3C 80A7604C 3C190001 */  lui     $t9, 0x0001                ## $t9 = 00010000
/* 01D40 80A76050 10000009 */  beq     $zero, $zero, .L80A76078   
/* 01D44 80A76054 A0600A78 */  sb      $zero, 0x0A78($v1)         ## 00000A78
.L80A76058:
/* 01D48 80A76058 A0600A78 */  sb      $zero, 0x0A78($v1)         ## 00000A78
/* 01D4C 80A7605C 0331C821 */  addu    $t9, $t9, $s1              
/* 01D50 80A76060 8F391D58 */  lw      $t9, 0x1D58($t9)           ## 00011D58
/* 01D54 80A76064 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01D58 80A76068 2405FFC0 */  addiu   $a1, $zero, 0xFFC0         ## $a1 = FFFFFFC0
/* 01D5C 80A7606C 0320F809 */  jalr    $ra, $t9                   
/* 01D60 80A76070 00000000 */  nop
/* 01D64 80A76074 A20002FE */  sb      $zero, 0x02FE($s0)         ## 000002FE
.L80A76078:
/* 01D68 80A76078 3C014100 */  lui     $at, 0x4100                ## $at = 41000000
/* 01D6C 80A7607C 44810000 */  mtc1    $at, $f0                   ## $f0 = 8.00
/* 01D70 80A76080 8607008A */  lh      $a3, 0x008A($s0)           ## 0000008A
/* 01D74 80A76084 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01D78 80A76088 44060000 */  mfc1    $a2, $f0                   
/* 01D7C 80A7608C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 01D80 80A76090 0C00BDC7 */  jal     func_8002F71C              
/* 01D84 80A76094 E7A00010 */  swc1    $f0, 0x0010($sp)           
/* 01D88 80A76098 93AB0033 */  lbu     $t3, 0x0033($sp)           
/* 01D8C 80A7609C 8FAC0034 */  lw      $t4, 0x0034($sp)           
/* 01D90 80A760A0 A18B0A78 */  sb      $t3, 0x0A78($t4)           ## 00000A78
.L80A760A4:
/* 01D94 80A760A4 0C00B638 */  jal     Actor_MoveForward
              
/* 01D98 80A760A8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01D9C 80A760AC 3C0141F0 */  lui     $at, 0x41F0                ## $at = 41F00000
/* 01DA0 80A760B0 44810000 */  mtc1    $at, $f0                   ## $f0 = 30.00
/* 01DA4 80A760B4 240D001D */  addiu   $t5, $zero, 0x001D         ## $t5 = 0000001D
/* 01DA8 80A760B8 AFAD0014 */  sw      $t5, 0x0014($sp)           
/* 01DAC 80A760BC 44070000 */  mfc1    $a3, $f0                   
/* 01DB0 80A760C0 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01DB4 80A760C4 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 01DB8 80A760C8 3C064296 */  lui     $a2, 0x4296                ## $a2 = 42960000
/* 01DBC 80A760CC 0C00B92D */  jal     func_8002E4B4              
/* 01DC0 80A760D0 E7A00010 */  swc1    $f0, 0x0010($sp)           
/* 01DC4 80A760D4 8E0E0028 */  lw      $t6, 0x0028($s0)           ## 00000028
/* 01DC8 80A760D8 3C014234 */  lui     $at, 0x4234                ## $at = 42340000
/* 01DCC 80A760DC 8E0F0024 */  lw      $t7, 0x0024($s0)           ## 00000024
/* 01DD0 80A760E0 AE0E003C */  sw      $t6, 0x003C($s0)           ## 0000003C
/* 01DD4 80A760E4 C604003C */  lwc1    $f4, 0x003C($s0)           ## 0000003C
/* 01DD8 80A760E8 44813000 */  mtc1    $at, $f6                   ## $f6 = 45.00
/* 01DDC 80A760EC AE0F0038 */  sw      $t7, 0x0038($s0)           ## 00000038
/* 01DE0 80A760F0 8E0F002C */  lw      $t7, 0x002C($s0)           ## 0000002C
/* 01DE4 80A760F4 46062200 */  add.s   $f8, $f4, $f6              
/* 01DE8 80A760F8 26050320 */  addiu   $a1, $s0, 0x0320           ## $a1 = 00000320
/* 01DEC 80A760FC AE0F0040 */  sw      $t7, 0x0040($s0)           ## 00000040
/* 01DF0 80A76100 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01DF4 80A76104 E608003C */  swc1    $f8, 0x003C($s0)           ## 0000003C
/* 01DF8 80A76108 0C0189B7 */  jal     Collider_CylinderUpdate
              
/* 01DFC 80A7610C AFA50028 */  sw      $a1, 0x0028($sp)           
/* 01E00 80A76110 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 01E04 80A76114 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 01E08 80A76118 02212821 */  addu    $a1, $s1, $at              
/* 01E0C 80A7611C AFA5002C */  sw      $a1, 0x002C($sp)           
/* 01E10 80A76120 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01E14 80A76124 0C017713 */  jal     CollisionCheck_SetOC
              ## CollisionCheck_setOT
/* 01E18 80A76128 8FA60028 */  lw      $a2, 0x0028($sp)           
/* 01E1C 80A7612C 921800AF */  lbu     $t8, 0x00AF($s0)           ## 000000AF
/* 01E20 80A76130 5B00000D */  blezl   $t8, .L80A76168            
/* 01E24 80A76134 820A02FE */  lb      $t2, 0x02FE($s0)           ## 000002FE
/* 01E28 80A76138 92080114 */  lbu     $t0, 0x0114($s0)           ## 00000114
/* 01E2C 80A7613C 5500000A */  bnel    $t0, $zero, .L80A76168     
/* 01E30 80A76140 820A02FE */  lb      $t2, 0x02FE($s0)           ## 000002FE
/* 01E34 80A76144 920902F8 */  lbu     $t1, 0x02F8($s0)           ## 000002F8
/* 01E38 80A76148 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01E3C 80A7614C 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 01E40 80A76150 29210002 */  slti    $at, $t1, 0x0002           
/* 01E44 80A76154 54200004 */  bnel    $at, $zero, .L80A76168     
/* 01E48 80A76158 820A02FE */  lb      $t2, 0x02FE($s0)           ## 000002FE
/* 01E4C 80A7615C 0C01767D */  jal     CollisionCheck_SetAC
              ## CollisionCheck_setAC
/* 01E50 80A76160 8FA60028 */  lw      $a2, 0x0028($sp)           
/* 01E54 80A76164 820A02FE */  lb      $t2, 0x02FE($s0)           ## 000002FE
.L80A76168:
/* 01E58 80A76168 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01E5C 80A7616C 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 01E60 80A76170 59400004 */  blezl   $t2, .L80A76184            
/* 01E64 80A76174 921902F8 */  lbu     $t9, 0x02F8($s0)           ## 000002F8
/* 01E68 80A76178 0C0175E7 */  jal     CollisionCheck_SetAT
              ## CollisionCheck_setAT
/* 01E6C 80A7617C 2606036C */  addiu   $a2, $s0, 0x036C           ## $a2 = 0000036C
/* 01E70 80A76180 921902F8 */  lbu     $t9, 0x02F8($s0)           ## 000002F8
.L80A76184:
/* 01E74 80A76184 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
/* 01E78 80A76188 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01E7C 80A7618C 17210003 */  bne     $t9, $at, .L80A7619C       
/* 01E80 80A76190 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 01E84 80A76194 0C01767D */  jal     CollisionCheck_SetAC
              ## CollisionCheck_setAC
/* 01E88 80A76198 260603EC */  addiu   $a2, $s0, 0x03EC           ## $a2 = 000003EC
.L80A7619C:
/* 01E8C 80A7619C 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80A761A0:
/* 01E90 80A761A0 8FB0001C */  lw      $s0, 0x001C($sp)           
/* 01E94 80A761A4 8FB10020 */  lw      $s1, 0x0020($sp)           
/* 01E98 80A761A8 03E00008 */  jr      $ra                        
/* 01E9C 80A761AC 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000