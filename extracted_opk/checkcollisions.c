
uint checkCollision(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  undefined3 extraout_var_00;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  char *pcVar14;
  char *pcVar15;
  int iVar16;
  float fVar17;
  float fVar18;
  undefined8 uVar19;
  int local_c0;
  int local_bc;
  float local_b8;
  float local_b4;
  int local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int *local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  uint local_78;
  int local_74;
  int *local_70;
  int *local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  uint local_50;
  int *local_4c;
  int local_48;
  int local_44;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  int local_34;
  
  if ((((param_1 < 0) && (DAT_0044877c == 0)) ||
      ((local_98 = param_3[4], DAT_00448750 * 0x10 - local_98 < param_1 && (DAT_0044877c == 0)))) ||
     (((param_2 < 0 && (DAT_00448780 == 0)) ||
      ((local_94 = param_3[5], (int)(DAT_00448754 * 0x10 - local_94) < param_2 &&
       (DAT_00448780 == 0)))))) {
    return 1;
  }
  iVar11 = param_2 + 0xf;
  if (-1 < param_2) {
    iVar11 = param_2;
  }
  local_78 = iVar11 >> 4;
  local_64 = param_1 + 0xf;
  if (-1 < param_1) {
    local_64 = param_1;
  }
  local_64 = local_64 >> 4;
  local_a8 = 0x10;
  local_a4 = 0x10;
  local_a0 = param_1;
  local_9c = param_2;
  local_8c = local_94;
  local_84 = DAT_00448750;
  local_5c = DAT_00448754;
  if ((int)local_78 < (int)DAT_00448754) {
    local_80 = DAT_0044876c;
    local_50 = DAT_00448770;
    local_54 = local_64 << 4;
    local_7c = DAT_004484b4;
    local_4c = (int *)(DAT_0044874c + local_64 * 4);
    local_68 = DAT_004484b8;
    uVar13 = 0;
    if (local_64 < DAT_00448750) {
      iVar11 = param_1 + local_98;
      iVar12 = param_2 + local_94;
      local_6c = &local_a0;
      local_70 = &local_b0;
      uVar19 = 0;
      uVar13 = 0;
      do {
        local_88 = local_78 << 4;
        local_74 = local_78 << 2;
        local_58 = local_50 ^ local_78;
        local_90 = local_4c;
        iVar5 = local_64;
        iVar6 = local_54;
        do {
          local_ac = local_88;
          local_b0 = iVar6;
          bVar2 = boxesCollide(local_6c,local_70);
          if (CONCAT31(extraout_var_00,bVar2) == 0) break;
          if (local_80 == iVar5) {
            if (local_58 == 0) {
              uVar13 = uVar13 | 8;
            }
          }
          iVar4 = *(int *)(*local_90 + local_74) * 0x100;
          if (*(char *)(local_7c + *(int *)(*local_90 + local_74)) == '\0') {
            pcVar8 = (char *)(local_68 + iVar4);
            pcVar15 = pcVar8 + 0x100;
            iVar4 = iVar6;
            iVar16 = local_88;
            local_60 = iVar5;
            do {
              bVar2 = param_2 <= iVar16;
              uVar7 = (uint)(iVar16 < iVar12);
              iVar10 = iVar4;
              pcVar14 = pcVar8;
              do {
                iVar5 = local_60;
                if ((((*pcVar14 != '\0') && (param_1 <= iVar10)) && (bVar2)) &&
                   ((iVar10 < iVar11 && (uVar7 != 0)))) {
                  switch(*pcVar14) {
                  case '\x01':
switchD_004203ac_caseD_1:
                    uVar13 = uVar13 | 1;
                    break;
                  case '\x02':
                    if ((float)uVar19 <= (float)param_3[7]) {
                      local_48 = iVar4;
                      local_44 = param_2;
                      local_40 = param_3;
                      local_3c = uVar7;
                      local_38 = iVar11;
                      local_34 = iVar12;
                      fVar18 = floorf((float)param_3[1]);
                      iVar11 = local_38;
                      uVar7 = local_3c;
                      param_3 = local_40;
                      iVar4 = local_48;
                      param_2 = local_44;
                      iVar12 = local_34;
                      if (iVar16 < local_8c + (int)fVar18) {
                        uVar13 = uVar13 | 0x200;
                        iVar5 = local_60;
                        break;
                      }
                      uVar13 = uVar13 | 0x201;
                    }
                  default:
                    iVar5 = local_60;
                    break;
                  case '\x03':
                    uVar13 = uVar13 | 2;
                    break;
                  case '\x04':
                    uVar13 = uVar13 | 4;
                    break;
                  case '\x05':
                    uVar13 = uVar13 | 0x10;
                    break;
                  case '\x06':
                    uVar13 = uVar13 | 0x20;
                    break;
                  case '\a':
                    if (((param_3 == &Player1) || (param_3 == &Player2)) ||
                       ((param_3 == &Player3 || (param_3 == &Player4))))
                    goto switchD_004203ac_caseD_1;
                    break;
                  case '\b':
                    uVar13 = uVar13 | 0x40;
                    break;
                  case '\t':
                    uVar13 = uVar13 | 0x80;
                    break;
                  case '\n':
                    uVar13 = uVar13 | 0x100;
                  }
                }
                pcVar14 = pcVar14 + 1;
                iVar10 = iVar10 + 1;
                local_60 = iVar5;
              } while (iVar6 + 0x10 != iVar10);
              pcVar8 = pcVar8 + 0x10;
              iVar16 = iVar16 + 1;
            } while (pcVar8 != pcVar15);
          }
          else {
            switch(*(undefined1 *)(local_68 + iVar4)) {
            case 1:
switchD_004201fc_caseD_1:
              uVar13 = uVar13 | 1;
              break;
            case 2:
              fVar18 = floorf((float)param_3[1]);
              if (local_88 < local_8c + (int)fVar18) {
                uVar13 = uVar13 | 0x200;
              }
              else {
                uVar13 = uVar13 | 0x201;
              }
              break;
            case 3:
              uVar13 = uVar13 | 2;
              break;
            case 4:
              uVar13 = uVar13 | 4;
              break;
            case 5:
              uVar13 = uVar13 | 0x10;
              break;
            case 6:
              uVar13 = uVar13 | 0x20;
              break;
            case 7:
              if ((((param_3 == &Player1) || (param_3 == &Player2)) || (param_3 == &Player3)) ||
                 (param_3 == &Player4)) goto switchD_004201fc_caseD_1;
              break;
            case 8:
              uVar13 = uVar13 | 0x41;
              break;
            case 9:
              uVar13 = uVar13 | 0x81;
              break;
            case 10:
              uVar13 = uVar13 | 0x101;
            default:
            }
          }
          iVar6 = iVar6 + 0x10;
          local_90 = local_90 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 != local_84);
      } while ((iVar5 != local_64) && (local_78 = local_78 + 1, local_78 != local_5c));
    }
  }
  else {
    uVar13 = 0;
  }
  piVar1 = platforms;
  if (0 < numberOfPlatforms) {
    iVar12 = numberOfPlatforms * 4;
    iVar11 = 0;
    local_90 = platforms + numberOfPlatforms;
    piVar3 = platforms;
    do {
      pfVar9 = (float *)*piVar3;
      if (pfVar9 != (float *)0x0) {
        fVar18 = pfVar9[1];
        local_b8 = pfVar9[4];
        local_c0 = (int)*pfVar9;
        local_b4 = pfVar9[5];
        local_bc = (int)fVar18;
        bVar2 = boxesCollide(&local_a0,&local_c0);
        if ((CONCAT31(extraout_var,bVar2) != 0) &&
           (fVar17 = floorf((float)param_3[1]), (float)(local_8c + (int)fVar17) <= fVar18)) {
          fVar18 = pfVar9[0x293];
          if (fVar18 == 0.0) {
            pfVar9[0x299] = 1.4013e-45;
          }
          else if (*(int *)((int)fVar18 + 0x1c) == 0) {
            fVar17 = pfVar9[0x29f];
            *(undefined4 *)((int)fVar18 + 0x1c) = 1;
            if ((int)fVar17 < 1) {
LAB_00420064:
              pfVar9[0x299] = 1.4013e-45;
            }
            else {
              piVar3 = piVar1;
              do {
                while (iVar5 = *piVar3, *(float *)(iVar5 + 0xa7c) == fVar17) {
                  piVar3 = piVar3 + 1;
                  *(undefined4 *)(*(int *)(iVar5 + 0xa4c) + 0x1c) = 1;
                  if (piVar3 == local_90) goto LAB_00420064;
                }
                piVar3 = piVar3 + 1;
              } while (piVar3 != local_90);
              pfVar9[0x299] = 1.4013e-45;
            }
          }
          else {
            pfVar9[0x299] = 1.4013e-45;
          }
          uVar13 = uVar13 | 1;
        }
      }
      iVar11 = iVar11 + 4;
      piVar3 = (int *)((int)piVar1 + iVar11);
    } while (iVar11 != iVar12);
  }
  return uVar13;
}

