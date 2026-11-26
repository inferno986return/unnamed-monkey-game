
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void extractCollisionData(char *param_1,char *param_2)

{
  uint *puVar1;
  uint uVar2;
  int *__ptr;
  void *pvVar3;
  void *pvVar4;
  int *piVar5;
  short *psVar6;
  uint uVar7;
  undefined4 *puVar8;
  int param1;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  
  puVar1 = (uint *)loadImage(param_1);
  uVar2 = puVar1[3];
  if ((int)uVar2 < 0) {
    uVar2 = uVar2 + 0xf;
  }
  iVar9 = (int)uVar2 >> 4;
  param1 = iVar9 << 4;
  printf("numOfTiles: %d\n",param1);
  __ptr = malloc(iVar9 << 6);
  if (__ptr == (int *)0x0) {
    fwrite("[ERROR] extractCollisionData: Out of memory!\n",1,0x2d,_stderr);
    psVar6 = malloc(iVar9 << 7);
  }
  else {
    if (0 < param1) {
      iVar12 = 0;
      piVar11 = __ptr;
      do {
        while( true ) {
          pvVar3 = malloc(0x40);
          *piVar11 = (int)pvVar3;
          if (pvVar3 != (void *)0x0) break;
          fwrite("[ERROR] extractCollisionData: Out of memory!\n",1,0x2d,_stderr);
          iVar12 = iVar12 + 1;
          piVar11 = piVar11 + 1;
          if (iVar12 == param1) goto LAB_0041f584;
        }
        iVar10 = 0;
        while( true ) {
          pvVar4 = malloc(0x40);
          *(void **)((int)pvVar3 + iVar10) = pvVar4;
          piVar5 = (int *)(*piVar11 + iVar10);
          iVar10 = iVar10 + 4;
          if (*piVar5 == 0) {
            fwrite("[ERROR] extractCollisionData: Out of memory!\n",1,0x2d,_stderr);
          }
          if (iVar10 == 0x40) break;
          pvVar3 = (void *)*piVar11;
        }
        iVar12 = iVar12 + 1;
        piVar11 = piVar11 + 1;
      } while (iVar12 != param1);
    }
LAB_0041f584:
    psVar6 = malloc(iVar9 << 7);
  }
  if (psVar6 == (short *)0x0) {
    fwrite("[ERROR] extractCollisionData: Out of memory!\n",1,0x2d,_stderr);
  }
  clipImage((int)psVar6,0x10,0x10,0x10,param1);
  if ((puVar1[6] != 0) || ((*puVar1 & 0x4005) != 0)) {
    SDL_LockSurface(puVar1);
  }
  if (param1 < 1) {
    uVar2 = puVar1[6];
  }
  else {
    iVar9 = 0;
    piVar11 = __ptr;
    do {
      uVar2 = (uint)(ushort)psVar6[2];
      if (uVar2 != 0) {
        uVar7 = (uint)(ushort)psVar6[3];
        iVar12 = 0;
        do {
          if (uVar7 != 0) {
            iVar13 = 0;
            iVar10 = 0;
LAB_0041f664:
            do {
              uVar2 = getPixel((int)puVar1,*psVar6 + iVar12,psVar6[1] + iVar10);
              if (uVar2 == 0xa800) {
                *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 6;
              }
              else if (uVar2 < 0xa801) {
                if (uVar2 == 0x400) {
                  *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 2;
                }
                else if (uVar2 < 0x401) {
                  if (uVar2 == 0) {
                    *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 1;
                  }
                  else {
                    if (uVar2 != 0x1f) goto LAB_0041f8b0;
                    *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 3;
                  }
                }
                else if (uVar2 == 0x841f) {
                  *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 8;
                }
                else {
                  if (uVar2 != 0x87f0) goto LAB_0041f8b0;
                  *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 10;
                }
              }
              else if (uVar2 == 0xfc10) {
                *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 9;
              }
              else if (uVar2 < 0xfc11) {
                if (uVar2 == 0xf800) {
                  *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 5;
                }
                else {
                  if (uVar2 == 0xfc00) {
                    iVar10 = iVar10 + 1;
                    *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 4;
                    uVar7 = (uint)(ushort)psVar6[3];
                    iVar13 = iVar13 + 4;
                    if ((int)uVar7 <= iVar10) break;
                    goto LAB_0041f664;
                  }
LAB_0041f8b0:
                  printf("WARNING: TILE:%d x:%d y:%d contains incorrect color (%d) for the collision layer. Ignoring...\n"
                         ,iVar9,iVar10,iVar12,uVar2);
                  *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 0;
                }
              }
              else if (uVar2 == 0xffe0) {
                *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 7;
              }
              else {
                if (uVar2 != 0xffff) goto LAB_0041f8b0;
                *(undefined1 *)(*(int *)(*piVar11 + iVar13) + iVar12) = 0;
              }
              uVar7 = (uint)(ushort)psVar6[3];
              iVar10 = iVar10 + 1;
              iVar13 = iVar13 + 4;
            } while (iVar10 < (int)uVar7);
            uVar2 = (uint)(ushort)psVar6[2];
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)uVar2);
      }
      iVar9 = iVar9 + 1;
      psVar6 = psVar6 + 4;
      piVar11 = piVar11 + 1;
    } while (iVar9 != param1);
    uVar2 = puVar1[6];
  }
  if ((uVar2 != 0) || ((*puVar1 & 0x4005) != 0)) {
    SDL_UnlockSurface(puVar1);
  }
  saveCollisionLayer(__ptr,param1,param_2);
  if (0 < param1) {
    iVar9 = 0;
    piVar11 = __ptr;
    do {
      iVar12 = 0;
      do {
        puVar8 = (undefined4 *)(*piVar11 + iVar12);
        iVar12 = iVar12 + 4;
        free((void *)*puVar8);
      } while (iVar12 != 0x40);
      iVar9 = iVar9 + 1;
      free((void *)*piVar11);
      piVar11 = piVar11 + 1;
    } while (iVar9 != param1);
  }
  free(__ptr);
                    /* WARNING: Could not recover jumptable at 0x0041f7dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SDL_FreeSurface(puVar1);
  return;
}

