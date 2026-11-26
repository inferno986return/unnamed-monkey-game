
int FUN_00427ba0(int param_1,int param_2,int param_3,void *param_4,undefined4 param_5,char param_6,
                byte param_7,byte param_8,byte param_9)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar3 = *(int *)(param_3 + 8) * *(int *)(param_3 + 0xc);
  SDL_LockSurface(param_3);
  if (uVar3 == 0) {
LAB_00427d58:
    SDL_UnlockSurface(param_3);
    free(param_4);
    return param_3;
  }
  pbVar4 = (byte *)(param_1 + param_2);
  uVar8 = (uint)*pbVar4;
  iVar9 = param_2;
  uVar12 = 0;
  if (uVar8 == 0xff) goto LAB_00427cbc;
LAB_00427c44:
  if (param_6 == '\0') {
    uVar7 = uVar8 & param_8;
    uVar8 = (int)(uVar8 & param_9) >> (8 - param_7 & 0x1f) & 0xff;
    param_2 = param_2 + 1;
  }
  else {
    uVar7 = (uint)*(byte *)(param_1 + param_2 + 1);
    param_2 = param_2 + 2;
  }
  uVar7 = uVar7 + 1 + uVar12;
  if (uVar3 < uVar7) {
LAB_00427dd4:
    SDL_UnlockSurface(param_3);
    free(param_4);
    SDL_FreeSurface(param_3);
    return 0;
  }
  do {
    uVar6 = *(uint *)(param_3 + 8);
    uVar13 = uVar12 / uVar6;
    uVar14 = uVar12 % uVar6;
    if (uVar6 == 0) {
      trap(7);
    }
    uVar12 = uVar12 + 1;
    FUN_00427930(param_3,uVar14,uVar13,*(undefined4 *)((int)param_4 + uVar8 * 4));
  } while (uVar7 != uVar12);
LAB_00427ca0:
  while (uVar3 != uVar7) {
    while( true ) {
      pbVar4 = (byte *)(param_1 + param_2);
      uVar8 = (uint)*pbVar4;
      iVar9 = param_2;
      uVar12 = uVar7;
      if (uVar8 != 0xff) goto LAB_00427c44;
LAB_00427cbc:
      param_2 = iVar9 + 1;
      cVar1 = *(char *)(param_1 + param_2);
      if (cVar1 == -1) {
        uVar8 = 0xff;
        goto LAB_00427c44;
      }
      if (cVar1 == '\x01') break;
      if (cVar1 == '\0') goto LAB_00427e3c;
      if (cVar1 != '\x02') goto LAB_00427dd4;
      uVar8 = (uint)pbVar4[2];
      if (uVar3 < pbVar4[3] + 1 + uVar12) goto LAB_00427dd4;
      uVar7 = uVar12 + 1 + (uint)pbVar4[3];
      uVar6 = uVar12 + 1;
      while( true ) {
        uVar13 = uVar6;
        uVar6 = *(uint *)(param_3 + 8);
        iVar5 = uVar8 * 4;
        if (uVar6 == 0) {
          trap(7);
        }
        uVar8 = uVar8 + 1 & 0xff;
        FUN_00427930(param_3,uVar12 % uVar6,uVar12 / uVar6,*(undefined4 *)((int)param_4 + iVar5));
        if (uVar13 == uVar7) break;
        uVar6 = uVar13 + 1;
        uVar12 = uVar13;
      }
      param_2 = iVar9 + 4;
      if (uVar3 == uVar7) goto LAB_00427d58;
    }
    bVar2 = pbVar4[2];
    if (uVar3 < *(ushort *)(pbVar4 + 3) + 1 + uVar12) goto LAB_00427dd4;
    uVar7 = uVar12 + 1 + (uint)*(ushort *)(pbVar4 + 3);
    uVar8 = uVar12 + 1;
    while( true ) {
      uVar6 = uVar8;
      uVar8 = *(uint *)(param_3 + 8);
      if (uVar8 == 0) {
        trap(7);
      }
      FUN_00427930(param_3,uVar12 % uVar8,uVar12 / uVar8,
                   *(undefined4 *)((int)param_4 + (uint)bVar2 * 4));
      if (uVar6 == uVar7) break;
      uVar8 = uVar6 + 1;
      uVar12 = uVar6;
    }
    param_2 = iVar9 + 5;
  }
  goto LAB_00427d58;
LAB_00427e3c:
  if (param_6 == '\0') goto LAB_00427dd4;
  uVar8 = (uint)pbVar4[2];
  if (uVar3 < uVar8 + 1 + uVar12) goto LAB_00427dd4;
  iVar5 = 0;
  uVar7 = uVar12;
  iVar10 = 1;
  do {
    uVar6 = *(uint *)(param_3 + 8);
    uVar13 = uVar7 / uVar6;
    uVar14 = uVar7 % uVar6;
    if (uVar6 == 0) {
      trap(7);
    }
    uVar7 = uVar7 + 1;
    FUN_00427930(param_3,uVar14,uVar13,
                 *(undefined4 *)((int)param_4 + (uint)*(byte *)(param_1 + iVar5 + iVar9 + 3) * 4));
    iVar11 = iVar10 + 1;
    iVar5 = iVar10;
    iVar10 = iVar11;
  } while (iVar11 != uVar8 + 2);
  uVar7 = uVar12 + 1 + uVar8;
  param_2 = uVar8 + 1 + iVar9 + 3;
  goto LAB_00427ca0;
}

