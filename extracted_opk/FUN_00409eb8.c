
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00409eb8(char *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  size_t sVar9;
  char *__dest;
  size_t sVar10;
  undefined4 *puVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  double dVar17;
  undefined4 local_1420 [12];
  undefined4 local_13f0 [988];
  char acStack_480 [1000];
  char local_98 [16];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  int local_78 [2];
  int local_70;
  undefined4 *local_6c;
  int *local_68;
  int *local_64;
  undefined4 *local_60;
  int local_5c;
  int local_58;
  int local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  char *local_30;
  FILE *local_2c;
  
  local_88 = 0x61642f2e;
  local_84 = 0x672f6174;
  local_80 = 0x2f7866;
  builtin_strncpy(local_98,"./data/maps/",0xd);
  local_2c = fopen(param_1,"r");
  if (local_2c == (FILE *)0x0) {
    fprintf(_stderr,"Can\'t open %s\n",param_1);
    return true;
  }
  DAT_00448784 = 0.1;
  DAT_0044877c = 0;
  DAT_00448780 = 0;
  DAT_00448788 = 0;
  DAT_004487b4 = (undefined4 *)0x0;
  DAT_0044878c = 0;
  pcVar1 = FUN_004089d0(param_1);
  strcpy(&DAT_004486b8,pcVar1);
  local_30 = acStack_480;
  local_3c = 0;
  local_48 = 0;
  local_34 = 0;
  local_5c = 0;
  local_4c = 0;
  local_54 = 0;
  local_40 = 0x6c6f632e;
LAB_00409fc8:
  do {
    iVar2 = fgetLine(local_2c,(int)local_30,1000);
    while( true ) {
      if (iVar2 == -1) {
        fclose(local_2c);
        iVar2 = generatePlatformArray();
        return iVar2 == 1;
      }
      local_60 = local_1420;
      local_44 = getWords(local_30,(int)local_60,1000);
      if (local_44 < 1) goto LAB_00409fc8;
      local_6c = local_1420;
      local_70 = 1;
      local_58 = 0;
      local_38 = local_34 ^ 1;
      while( true ) {
        iVar2 = local_70;
        iVar14 = local_70 + -1;
        if (local_5c == 0) {
          pcVar1 = (char *)*local_6c;
          piVar7 = EnemyListHead;
        }
        else {
          if (local_3c == 0) {
            initMapArray(&DAT_0044874c);
            fillMapArray(&DAT_0044874c,0);
            initMapArray(&DAT_00448758);
            fillMapArray(&DAT_00448758,0);
            local_3c = 1;
          }
          pcVar1 = (char *)*local_6c;
          iVar3 = strcmp(pcVar1,"LAYER0");
          if (iVar3 == 0) {
            local_34 = 0;
            goto LAB_00409fc8;
          }
          iVar3 = strcmp(pcVar1,"LAYER1");
          if (iVar3 == 0) {
            local_34 = 1;
            goto LAB_00409fc8;
          }
          iVar3 = strcmp(pcVar1,"OBJECTS:");
          if (iVar3 == 0) {
            local_5c = 0;
            goto LAB_00409fc8;
          }
          if (local_34 == 0) {
            local_50 = &DAT_0044874c;
          }
          else if (local_38 == 0) {
            local_50 = &DAT_00448758;
          }
          iVar3 = *(int *)(*local_50 + local_54 * 4);
          iVar15 = local_4c * 4;
          iVar4 = atoi(pcVar1);
          *(int *)(iVar3 + iVar15) = iVar4;
          local_54 = local_54 + 1;
          if (local_50[1] <= local_54) {
            local_54 = 0;
            local_4c = local_4c + 1;
          }
          piVar7 = EnemyListHead;
          if (local_50[2] <= local_4c) {
            local_4c = 0;
            if (local_38 == 0) {
              local_5c = 0;
            }
            local_54 = 0;
          }
        }
        EnemyListHead = piVar7;
        if (local_48 != 0) break;
        iVar14 = strcmp(pcVar1,"NAME:");
        iVar2 = 1;
        if (iVar14 != 0) {
          iVar2 = local_58;
        }
        local_58 = iVar2;
        iVar2 = strcmp(pcVar1,"TILESET:");
        if (iVar2 == 0) {
          local_64 = &local_7c;
          pcVar1 = (char *)local_6c[1];
          local_68 = local_78;
          local_78[0] = 0;
          local_7c = 0;
          iVar2 = 1;
          while( true ) {
            sVar10 = strlen(pcVar1);
            pcVar13 = malloc(sVar10 + 10);
            sprintf(pcVar13,"tileset%s%02d",pcVar1,iVar2);
            pcVar13[7] = (char)*(undefined2 *)(___ctype_toupper + pcVar13[7] * 2);
            sVar10 = strlen((char *)&local_88);
            sVar9 = strlen(pcVar13);
            __dest = malloc(sVar10 + sVar9 + 1);
            memcpy(__dest,&local_88,sVar10);
            memcpy(__dest + sVar10,pcVar13,sVar9 + 1);
            iVar14 = loadImage(__dest);
            if (iVar14 == 0) break;
            iVar2 = iVar2 + 1;
            free(__dest);
            listInsertLast(local_78,pcVar13);
            listInsertLast(local_64,iVar14);
          }
          free(__dest);
          free(pcVar13);
          iVar2 = listGetCount(local_78);
          sVar10 = iVar2 << 2;
          DAT_00448740 = 0;
          DAT_00448744 = 0x14;
          DAT_0044873c = iVar2;
          DAT_00448734 = malloc(sVar10);
          if (DAT_00448734 == (int *)0x0) {
            fwrite("ERROR: out of memory!\n",1,0x16,_stderr);
            sVar10 = DAT_0044873c << 2;
            iVar2 = DAT_0044873c;
          }
          DAT_00448730 = malloc(sVar10);
          if (DAT_00448730 == (void *)0x0) {
            fwrite("ERROR: out of memory!\n",1,0x16,_stderr);
            iVar2 = DAT_0044873c;
          }
          iVar14 = 0;
          if (0 < iVar2) {
            do {
              *(undefined4 *)((int)DAT_00448730 + iVar14 * 4) = *(undefined4 *)(local_78[0] + 4);
              DAT_00448734[iVar14] = *(int *)(local_7c + 4);
              listDeleteFirst(local_78);
              iVar14 = iVar14 + 1;
              listDeleteFirst(&local_7c);
            } while (iVar14 < DAT_0044873c);
          }
          iVar2 = *(int *)(*DAT_00448734 + 0xc);
          if (iVar2 < 0) {
            iVar2 = iVar2 + 0xf;
          }
          iVar14 = (iVar2 >> 4) << 4;
          DAT_00448748 = iVar14;
          DAT_00448738 = malloc((iVar2 >> 4) << 7);
          if (DAT_00448738 == (void *)0x0) {
            fwrite("ERROR: out of memory!\n",1,0x16,_stderr);
            iVar14 = DAT_00448748;
          }
          else {
          }
          clipImage((int)DAT_00448738,0x10,0x10,0x10,iVar14);
          sVar10 = strlen(local_98);
          sVar9 = strlen(pcVar1);
          pcVar13 = malloc(sVar10 + sVar9 + 5);
          if (pcVar13 == (char *)0x0) {
            fwrite("ERROR: out of memory!\n",1,0x16,_stderr);
            goto LAB_00409fc8;
          }
          memcpy(pcVar13,local_98,sVar10);
          pcVar1 = stpcpy(pcVar13 + sVar10,pcVar1);
          *(undefined4 *)pcVar1 = local_40;
          pcVar1[4] = '\0';
          FUN_00409c40(pcVar13);
          printf("PATH: %s\n",pcVar13);
          free(pcVar13);
          pcVar1 = (char *)*local_6c;
        }
        iVar2 = local_70;
        iVar14 = strcmp(pcVar1,"LAYER0_SIZE:");
        if (iVar14 == 0) {
          DAT_00448750 = atoi((char *)local_1420[local_70]);
          DAT_00448754 = atoi((char *)local_6c[2]);
        }
        iVar14 = strcmp(pcVar1,"LAYER1_SIZE:");
        if (iVar14 == 0) {
          DAT_0044875c = atoi((char *)local_1420[local_70]);
          DAT_00448760 = atoi((char *)local_6c[2]);
        }
        iVar14 = strcmp(pcVar1,"START:");
        if (iVar14 == 0) {
          DAT_00448764 = atoi((char *)local_1420[local_70]);
          DAT_00448768 = atoi((char *)local_6c[2]);
        }
        iVar14 = strcmp(pcVar1,"EXIT:");
        if (iVar14 == 0) {
          DAT_0044876c = atoi((char *)local_1420[local_70]);
          DAT_00448770 = atoi((char *)local_6c[2]);
        }
        iVar3 = strcmp(pcVar1,"MPSPAWN:");
        iVar14 = local_44;
        if (iVar3 == 0) {
          DAT_00448774 = (int *)0x0;
          if (local_70 < local_44) {
            puVar11 = local_1420 + local_70;
            do {
              piVar7 = malloc(0xc);
              iVar2 = iVar2 + 2;
              if (piVar7 == (int *)0x0) {
                fwrite("Out of memory!\n",1,0xf,_stderr);
                return true;
              }
              iVar3 = atoi((char *)*puVar11);
              pcVar1 = (char *)puVar11[1];
              *piVar7 = iVar3;
              iVar3 = atoi(pcVar1);
              piVar7[1] = iVar3;
              piVar7[2] = (int)DAT_00448774;
              puVar11 = puVar11 + 2;
              DAT_00448774 = piVar7;
            } while (iVar2 < iVar14);
          }
          goto LAB_00409fc8;
        }
        iVar2 = strcmp(pcVar1,"WRAP:");
        if (iVar2 == 0) {
          DAT_0044877c = atoi((char *)local_1420[local_70]);
          DAT_00448780 = atoi((char *)local_6c[2]);
        }
        iVar2 = strcmp(pcVar1,"GRAVITY:");
        if (iVar2 == 0) {
          dVar17 = atof((char *)local_1420[local_70]);
          DAT_00448784 = (float)dVar17;
        }
        iVar2 = strcmp(pcVar1,"BGD_EFFECT:");
        if (iVar2 == 0) {
          pcVar13 = (char *)local_1420[local_70];
          iVar2 = strcmp(pcVar13,"EFFECT_NONE");
          if (iVar2 == 0) {
            DAT_00448788 = 0;
          }
          else {
            iVar2 = strcmp(pcVar13,"EFFECT_RAIN");
            if (iVar2 == 0) {
              DAT_00448788 = 1;
            }
            else {
              iVar2 = strcmp(pcVar13,"EFFECT_THUNDERSTORM");
              if (iVar2 == 0) {
                DAT_00448788 = 2;
              }
              else {
                iVar2 = strcmp(pcVar13,"EFFECT_SNOW");
                if (iVar2 == 0) {
                  DAT_00448788 = 3;
                }
                else {
                  fprintf(_stdout,
                          "WARNING (loadMap): %s - unknown effect! Defaulting to EFFECT_NONE.\n",
                          pcVar13);
                  pcVar1 = (char *)*local_6c;
                  DAT_00448788 = 0;
                }
              }
            }
          }
        }
        iVar2 = strcmp(pcVar1,"MUSIC:");
        if (iVar2 == 0) {
          DAT_004487b4 = musicManagerGetMusicNode((char *)local_1420[local_70]);
          pcVar1 = (char *)*local_6c;
        }
        iVar14 = strcmp(pcVar1,"MAP:");
        iVar2 = 1;
        if (iVar14 != 0) {
          iVar2 = local_5c;
        }
        local_5c = iVar2;
        iVar2 = strcmp(pcVar1,"OBJECTS:");
        if (iVar2 == 0) {
          if (EnemyListHead != (int *)0x0) {
            fwrite("WARNING (loadMap): EnemyListHead is not NULL. This shouldn\'t happen. Setting it to NULL now.\n"
                   ,1,0x5d,_stdout);
            cleanList(EnemyListHead);
            EnemyListHead = (int *)0x0;
          }
          if (gameplayType == 4) {
            EnemyListHead = prependElement(EnemyListHead,0,0,"M_CAGE",0,0,0);
            pcVar1 = (char *)*local_6c;
            EnemyListHead[0xc] = 9;
            local_48 = 1;
          }
          else {
            pcVar1 = (char *)*local_6c;
            local_48 = 1;
          }
        }
        iVar2 = strcmp(pcVar1,"SCRIPT:");
        if (iVar2 == 0) {
          strcpy(&DAT_0044878c,(char *)local_1420[local_70]);
        }
        if (local_44 <= local_70) goto LAB_00409fc8;
        if (local_58 != 0) {
          strcat(&curLvl,(char *)local_1420[local_70]);
          sVar10 = strlen(&curLvl);
          (&curLvl)[sVar10] = 0x20;
          (&DAT_00448691)[sVar10] = 0;
        }
        local_6c = local_6c + 1;
        local_70 = local_70 + 1;
      }
      iVar3 = atoi((char *)local_1420[iVar2]);
      iVar4 = atoi((char *)local_1420[iVar2 + 1]);
      iVar15 = atoi((char *)local_1420[iVar2 + 2]);
      iVar5 = atoi((char *)local_1420[iVar2 + 3]);
      iVar6 = atoi((char *)local_1420[iVar2 + 4]);
      piVar7 = prependElement(piVar7,iVar3,iVar4,pcVar1,iVar15,iVar5,iVar6);
      iVar3 = piVar7[0x296];
      EnemyListHead = piVar7;
      if (iVar3 == 4) {
        puVar11 = saveGameGetScore(&DAT_004486b8,0);
        piVar7 = EnemyListHead;
        if ((puVar11[1] & 1) != 0) {
          EnemyListHead[0xc] = 9;
        }
        iVar3 = piVar7[0x296];
      }
      if (iVar3 == 5) {
        puVar11 = saveGameGetScore(&DAT_004486b8,0);
        piVar7 = EnemyListHead;
        iVar3 = EnemyListHead[0x296];
        if ((puVar11[1] & 2) != 0) {
          EnemyListHead[0xc] = 9;
        }
      }
      if (iVar3 == 6) {
        puVar11 = saveGameGetScore(&DAT_004486b8,0);
        piVar7 = EnemyListHead;
        iVar3 = EnemyListHead[0x296];
        if ((puVar11[1] & 4) != 0) {
          EnemyListHead[0xc] = 9;
        }
      }
      if (iVar3 == 7) {
        puVar11 = saveGameGetScore(&DAT_004486b8,0);
        piVar7 = EnemyListHead;
        if ((puVar11[1] & 8) != 0) {
          EnemyListHead[0xc] = 9;
        }
      }
      if (local_44 < 7) {
        piVar7[0x294] = 0;
        goto LAB_00409fc8;
      }
      if (piVar7[0x296] == 3) {
        iVar3 = atoi((char *)local_1420[iVar2 + 5]);
        piVar7[0x2a1] = iVar3;
        puVar11 = saveGameGetScore(&DAT_004486b8,0);
        piVar7 = EnemyListHead;
        uVar12 = 1 << (EnemyListHead[0x2a1] - 1U & 0x1f);
        if (uVar12 == (uVar12 & puVar11[1])) {
          EnemyListHead[0xc] = 9;
        }
      }
      if (local_44 == 7) {
        piVar7[0x294] = 0;
        goto LAB_00409fc8;
      }
      iVar3 = atoi((char *)local_1420[iVar2 + 6]);
      iVar4 = atoi((char *)local_1420[iVar2 + 7]);
      iVar15 = atoi((char *)local_1420[iVar2 + 8]);
      iVar5 = atoi((char *)local_1420[iVar2 + 9]);
      iVar6 = atoi((char *)local_1420[iVar2 + 10]);
      iVar8 = allocatePath((int)(piVar7 + 1),iVar6);
      if (iVar8 == 0) break;
      piVar7 = (int *)EnemyListHead[0x294];
      piVar7[7] = iVar3;
      piVar7[8] = iVar4;
      piVar7[3] = iVar15;
      piVar7[9] = iVar5;
      if (0 < iVar6) {
        iVar4 = piVar7[1];
        iVar3 = piVar7[2];
        iVar15 = 0;
        puVar11 = local_1420 + iVar2 + 0xb;
        do {
          puVar16 = puVar11 + 2;
          iVar2 = atoi((char *)*puVar11);
          pcVar1 = (char *)puVar11[1];
          *(int *)(iVar4 + iVar15) = iVar2;
          iVar2 = atoi(pcVar1);
          *(int *)(iVar3 + iVar15) = iVar2;
          iVar15 = iVar15 + 4;
          puVar11 = puVar16;
        } while (puVar16 != local_13f0 + iVar6 * 2 + iVar14);
      }
      piVar7[4] = 0;
      piVar7[5] = 0;
      piVar7[6] = 1;
      printf("Path has %d nodes\n",*piVar7);
      iVar2 = fgetLine(local_2c,(int)local_30,1000);
    }
    fprintf(_stderr,"ERROR: out of memory when allocating path for %s!\n",(char *)local_1420[iVar14]
           );
  } while( true );
}

