
int FUN_00427f48(char *param_1)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  byte bVar9;
  uint uVar10;
  byte bVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  int local_34;
  byte local_30;
  
  if (param_1 != (char *)0x0) {
    uVar14 = (uint)(byte)param_1[5];
    cVar1 = param_1[3];
    bVar9 = param_1[4];
    if ((((*param_1 == 'H') && (param_1[1] == 'I')) && (param_1[2] == 'F')) &&
       (cVar3 = -((char)bVar9 >> 7), (byte)(cVar1 - 1U) < 2)) {
      if (cVar1 == '\x01') {
        if ((bVar9 & 0xf) != 0) {
          return 0;
        }
        bVar11 = 1;
      }
      else {
        bVar11 = bVar9 >> 3 & 1;
      }
      if (((bVar9 & 7) == 0) || (cVar1 != '\x02')) {
        if (cVar3 == '\0') {
          local_34 = (int)(bVar9 & 0x70) >> 4;
          if (local_34 == 0) {
            return 0;
          }
          uVar10 = 0;
          uVar4 = 0;
          do {
            uVar2 = uVar4 & 0x1f;
            uVar4 = uVar4 + 1;
            uVar10 = 1 << uVar2 & 0xffU | uVar10;
            bVar9 = (byte)uVar10;
          } while (uVar4 != 8U - local_34);
          local_30 = ~bVar9;
        }
        else {
          local_30 = 0;
          bVar9 = 0;
          local_34 = 0;
        }
        iVar5 = SDL_CreateRGBSurface
                          (0,*(undefined2 *)(param_1 + 6),*(undefined2 *)(param_1 + 8),0x20,0,0,0,0)
        ;
        if (iVar5 != 0) {
          uVar4 = uVar14 + 1;
          puVar6 = malloc(uVar4 * 4);
          if (puVar6 != (undefined4 *)0x0) {
            uVar10 = 0;
            iVar13 = 10;
            puVar12 = puVar6;
            do {
              while( true ) {
                pcVar7 = param_1 + iVar13;
                if (bVar11 != 0) break;
                uVar10 = uVar10 + 1;
                uVar8 = SDL_MapRGB(*(undefined4 *)(iVar5 + 4),pcVar7[2],pcVar7[1],*pcVar7);
                *puVar12 = uVar8;
                iVar13 = iVar13 + 3;
                puVar12 = puVar12 + 1;
                if (uVar4 <= uVar10) goto LAB_00428144;
              }
              uVar8 = SDL_MapRGBA(*(undefined4 *)(iVar5 + 4),pcVar7[2],pcVar7[1],*pcVar7,pcVar7[3]);
              uVar10 = uVar10 + 1;
              *puVar12 = uVar8;
              iVar13 = iVar13 + 4;
              puVar12 = puVar12 + 1;
            } while (uVar10 < uVar4);
LAB_00428144:
            if (cVar1 == '\x01') {
              iVar5 = FUN_004279b8((int)param_1,iVar13,iVar5,puVar6,uVar14,cVar3,(byte)local_34,
                                   bVar9,local_30);
              return iVar5;
            }
            iVar5 = FUN_00427ba0((int)param_1,iVar13,iVar5,puVar6,uVar14,cVar3,(byte)local_34,bVar9,
                                 local_30);
            return iVar5;
          }
          SDL_FreeSurface(iVar5);
        }
      }
    }
  }
  return 0;
}

