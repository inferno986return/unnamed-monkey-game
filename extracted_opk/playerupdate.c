
void playerUpdate(float *param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  float fVar4;
  undefined3 extraout_var;
  float *pfVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  float fVar16;
  float fVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  int local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  float local_50;
  float local_4c;
  int local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  
  if (param_1 == (float *)&Player1) {
    local_48 = 1;
  }
  else if (param_1 == (float *)&Player2) {
    local_48 = 2;
  }
  else if (param_1 == (float *)&Player3) {
    local_48 = 3;
  }
  else {
    local_48 = 4;
    if (param_1 != (float *)&Player4) {
      local_48 = 0;
    }
  }
  if ((int)param_1[8] < 0) {
    param_1[8] = 0.0;
  }
  if (gameplayType == 3) {
    if (param_1[0x2d4] == 0.0) {
      fVar7 = param_1[0x2d2];
LAB_0041db0c:
      if (0 < (int)fVar7) goto LAB_0041cf74;
      param_1[8] = 0.0;
    }
    else {
      fVar7 = param_1[0x2d3];
      param_1[0x2d3] = (float)((int)fVar7 + -1);
      if ((float)((int)fVar7 + -1) != 0.0) {
        fVar7 = param_1[0x2d2];
        goto LAB_0041db0c;
      }
      fVar7 = param_1[0x2d2];
      param_1[0x2d2] = (float)((int)fVar7 + -1);
      param_1[0x2d3] = 8.40779e-44;
      if (0 < (int)fVar7 + -1) goto LAB_0041cf74;
      param_1[8] = 0.0;
    }
    param_1[0x2d2] = 0.0;
  }
LAB_0041cf74:
  if (isTutorial != 0) {
    checkSignCollision(param_1);
  }
  fVar7 = param_1[0x2d6];
  if (fVar7 == 0.0) {
    param_1[7] = param_1[7] + DAT_00448784;
  }
  iVar3 = 0;
  if (0 < numOfPlayers) {
    do {
      iVar3 = iVar3 + 1;
      if ((DAT_004489d8 == 0) && (DAT_004494e8 != 0)) {
        DAT_004494e8 = 0;
        puVar15 = &Player1;
        iVar3 = 1;
        goto LAB_0041d2fc;
      }
    } while (iVar3 != numOfPlayers);
  }
  goto LAB_0041cfcc;
LAB_0041d2fc:
  puVar15 = (undefined4 *)puVar15[0x2e1];
  if (iVar3 != numOfPlayers) {
    if ((int)puVar15[8] < 1) {
      iVar3 = iVar3 + 1;
    }
    else {
      if (puVar15[0x2cc] == 0) {
        puVar15[0x2cc] = 1;
        goto LAB_0041cfcc;
      }
      iVar3 = iVar3 + 1;
    }
    goto LAB_0041d2fc;
  }
LAB_0041cfcc:
  if (param_1[8] != 0.0) {
    fVar7 = param_1[9];
LAB_0041d264:
    if (fVar7 == 1.4013e-45) {
      fVar7 = param_1[0x14];
      goto LAB_0041d02c;
    }
LAB_0041d274:
    param_1[6] = param_1[6] * 0.99;
    goto LAB_0041d284;
  }
  if (param_1[0x2d7] == 0.0) {
    if (fVar7 != 0.0) {
      param_1[0x2d6] = 0.0;
    }
  }
  else {
    botPerformAction(param_1);
    if (param_1[0x2d6] != 0.0) {
      param_1[0x2d6] = 0.0;
    }
  }
  if (gameplayType != 0) {
    if (gameplayType - 2 < 3) {
      if (param_1[0x2d1] == 0.0) {
        ParticleListHead =
             particlePrepend(ParticleListHead,(int)(*param_1 + -4.0 + (float)((int)param_1[4] / 2)),
                             (int)param_1[1],"P_GIBS",0,0);
        fVar7 = param_1[4];
        fVar17 = *param_1;
        fVar9 = param_1[1];
        uVar14 = 0xbf800000;
        ParticleListHead[7] = 0xbf800000;
        ParticleListHead[8] = 0xbf800000;
        ParticleListHead =
             particlePrepend(ParticleListHead,(int)(fVar17 + 4.0 + (float)((int)fVar7 / 2)),
                             (int)fVar9,"P_GIBS",0,0);
        fVar7 = param_1[0x2d7];
        ParticleListHead[7] = 0x3f800000;
        ParticleListHead[8] = uVar14;
        param_1[0x2d1] = 1.4013e-45;
        if (fVar7 != 0.0) {
          param_1[0x2d8] = 4.2039e-43;
        }
        iVar3 = numOfPlayers;
        if (gameplayType != 3) {
          fVar7 = param_1[0x29a];
          goto LAB_0041dd54;
        }
        puVar15 = &Player1;
        if (0 < numOfPlayers) {
          iVar10 = 0;
          do {
            iVar10 = iVar10 + 1;
            puVar15[0x2d4] = 0;
            puVar15 = (undefined4 *)puVar15[0x2e1];
          } while (iVar10 != iVar3);
          fVar7 = param_1[0x29a];
          goto LAB_0041dd54;
        }
      }
      fVar7 = param_1[0x29a];
LAB_0041dd54:
      if (fVar7 != 1.4013e-45) {
        return;
      }
      param_1[0x29a] = 0.0;
      getRespawnPosition(&local_68);
      puVar15 = ParticleListHead;
      *param_1 = (float)(local_68 << 4);
      param_1[1] = (float)(local_64 << 4);
      param_1[8] = 4.2039e-45;
      param_1[6] = 0.0;
      param_1[7] = 0.0;
      param_1[0xb] = 0.0;
      param_1[0x2d1] = 0.0;
      ParticleListHead =
           particlePrepend(puVar15,(int)(float)(local_68 << 4),(int)(float)(local_64 << 4),
                           "P_SPARKLE",0,0);
      ParticleListHead =
           particlePrepend(ParticleListHead,(int)(*param_1 + -5.0 + (float)(int)param_1[4]),
                           (int)(param_1[1] + -5.0 + (float)(int)param_1[5]),"P_SPARKLE",0,0);
      iVar3 = numOfPlayers;
      if (gameplayType != 3) {
        return;
      }
      tagModeWarmup = 1;
      if (numOfPlayers < 1) {
        tagModeWarmup = 1;
        return;
      }
      puVar15 = &Player1;
      iVar10 = 0;
      do {
        iVar10 = iVar10 + 1;
        puVar15[8] = 3;
        puVar15[0x2d2] = 100;
        puVar15[0x2d3] = 0x3c;
        puVar15 = (undefined4 *)puVar15[0x2e1];
      } while (iVar10 != iVar3);
      return;
    }
    fVar7 = param_1[9];
    goto LAB_0041d264;
  }
  if (param_1[9] == 0.0) goto LAB_0041d274;
  bVar1 = DAT_004476f0 < 1;
  DAT_004476f0 = DAT_004476f0 + -1;
  if (bVar1) {
    ingameState = 1;
    DAT_004476f0 = 99;
  }
  if (param_1[9] != 1.4013e-45) goto LAB_0041d274;
  fVar7 = param_1[0x14];
LAB_0041d02c:
  if (fVar7 == 0.0) {
    if (param_1[0x16] == 0.0) {
      if (param_1[0x17] != 0.0) {
        param_1[6] = param_1[6] * 0.5 + 0.3;
        goto LAB_0041d284;
      }
      fVar7 = param_1[6] * 0.5;
      param_1[6] = fVar7;
      if (0.1 <= fVar7) goto LAB_0041d284;
      if (-0.1 < fVar7) {
        param_1[6] = 0.0;
        goto LAB_0041d284;
      }
      fVar7 = param_1[0x2d7];
    }
    else {
      param_1[6] = param_1[6] * 0.5 - 0.3;
LAB_0041d284:
      fVar7 = param_1[0x2d7];
    }
    if (fVar7 != 0.0) goto LAB_0041d0b4;
LAB_0041d290:
    if (0 < (int)param_1[8]) goto LAB_0041d29c;
    fVar7 = param_1[7];
LAB_0041d0cc:
    fVar8 = param_1[0x12];
    fVar4 = param_1[0x13];
LAB_0041d0d4:
    fVar16 = param_1[6];
    puVar15 = (undefined4 *)*param_1;
    puVar11 = (undefined4 *)param_1[1];
    fVar9 = fVar8;
    fVar17 = fVar4;
  }
  else {
    fVar7 = param_1[6];
    if (fVar7 == 0.0) {
      fVar7 = param_1[0x15];
      if (fVar7 != 0.0) {
        if (param_1[0xc] == 0.0) {
          fVar7 = (float)-(int)fVar7;
        }
        else if (param_1[0xc] != 1.4013e-45) {
          param_1[6] = 0.0;
          goto LAB_0041d0a4;
        }
        fVar7 = (float)(int)fVar7;
        goto LAB_0041d070;
      }
      param_1[6] = 0.0;
LAB_0041d0a4:
      fVar7 = param_1[0x2d7];
    }
    else {
LAB_0041d070:
      fVar7 = fVar7 * 0.95;
      param_1[6] = fVar7;
      if (0.1 <= fVar7) goto LAB_0041d0a4;
      if (-0.1 < fVar7) {
        param_1[6] = 0.0;
        goto LAB_0041d0a4;
      }
      fVar7 = param_1[0x2d7];
    }
    param_1[0x15] = 0.0;
    if (fVar7 == 0.0) goto LAB_0041d290;
LAB_0041d0b4:
    botPerformAction(param_1);
    if ((int)param_1[8] < 1) {
      fVar7 = param_1[7];
      goto LAB_0041d0cc;
    }
LAB_0041d29c:
    if (param_1[0x2d6] == 0.0) {
      if (param_1[0x2c7] != 0.0) {
        fVar8 = param_1[0x12];
        fVar4 = param_1[0x13];
        param_1[0x2c7] = (float)((int)param_1[0x2c7] + -1);
        if (param_1[0x29a] != 0.0) {
          fVar7 = param_1[9];
          fVar9 = fVar8;
          fVar17 = fVar4;
          goto LAB_0041dc80;
        }
LAB_0041d2e8:
        fVar7 = param_1[7];
        goto LAB_0041d0d4;
      }
      if (param_1[0x297] == 1.4013e-45) {
        if (param_1[0x298] == 1.4013e-45) {
          fVar8 = param_1[0x12];
          fVar4 = param_1[0x13];
          fVar9 = fVar8;
          fVar17 = fVar4;
        }
        else {
          fVar7 = param_1[6];
          if (fVar7 < 0.0) {
            param_1[0xc] = 0.0;
          }
          if (param_1[9] == 1.4013e-45) {
            fVar8 = param_1[0x12];
            fVar4 = param_1[0x13];
            fVar9 = fVar8;
            fVar17 = fVar4;
            if (fVar8 == 0.0) {
              if (fVar4 == 0.0) {
                if (param_1[0x14] == 0.0) {
                  if (param_1[0x16] == 0.0) {
                    if (param_1[0x17] == 0.0) {
                      fVar7 = fVar7 - 0.6;
                      param_1[6] = fVar7;
                      fVar9 = 0.0;
                      fVar17 = 0.0;
                    }
                    else {
                      param_1[0xc] = 0.0;
                      fVar9 = 0.0;
                      fVar7 = fVar7 - 0.6;
                      param_1[6] = fVar7;
                      fVar17 = 0.0;
                    }
                  }
                  else {
                    param_1[0xc] = 0.0;
                    fVar7 = fVar7 - 0.6;
                    param_1[6] = fVar7;
                    fVar9 = 0.0;
                    fVar17 = 0.0;
                  }
                }
                else {
                  fVar9 = 0.0;
                  fVar7 = fVar7 - 0.15;
                  param_1[6] = fVar7;
                }
              }
              else {
                fVar7 = fVar7 - 0.2;
                param_1[6] = fVar7;
              }
            }
            else {
              fVar7 = fVar7 - 0.4;
              param_1[6] = fVar7;
            }
          }
          else {
            fVar8 = param_1[0x12];
            fVar4 = param_1[0x13];
            fVar7 = fVar7 - 0.1;
            param_1[6] = fVar7;
            fVar9 = fVar8;
            fVar17 = fVar4;
          }
          if (-1.2 <= fVar7) {
            fVar7 = param_1[0x29a];
            goto LAB_0041d2e0;
          }
          param_1[6] = -1.2;
        }
LAB_0041d2dc:
        fVar7 = param_1[0x29a];
      }
      else {
        fVar8 = param_1[0x12];
        fVar4 = param_1[0x13];
        fVar9 = fVar8;
        fVar17 = fVar4;
        if (param_1[0x298] != 1.4013e-45) goto LAB_0041d2dc;
        fVar7 = param_1[6];
        if (0.0 < fVar7) {
          param_1[0xc] = 1.4013e-45;
        }
        if (param_1[9] == 1.4013e-45) {
          if (fVar8 == 0.0) {
            if (fVar4 == 0.0) {
              if (param_1[0x14] == 0.0) {
                if (param_1[0x16] == 0.0) {
                  if (param_1[0x17] == 0.0) {
                    fVar7 = fVar7 + 0.6;
                    param_1[6] = fVar7;
                    goto LAB_0041e974;
                  }
                  param_1[0xc] = 1.4013e-45;
                }
                else {
                  param_1[0xc] = 1.4013e-45;
                }
                fVar7 = fVar7 + 0.6;
                param_1[6] = fVar7;
              }
              else {
                fVar7 = fVar7 + 0.15;
                param_1[6] = fVar7;
              }
            }
            else {
              fVar7 = fVar7 + 0.2;
              param_1[6] = fVar7;
            }
          }
          else {
            fVar7 = fVar7 + 0.4;
            param_1[6] = fVar7;
          }
        }
        else {
          fVar7 = fVar7 + 0.1;
          param_1[6] = fVar7;
        }
LAB_0041e974:
        if (1.2 < fVar7) {
          param_1[6] = 1.2;
          goto LAB_0041d2dc;
        }
        fVar7 = param_1[0x29a];
      }
LAB_0041d2e0:
      if (fVar7 == 0.0) goto LAB_0041d2e8;
      fVar7 = param_1[9];
LAB_0041dc80:
      if (fVar7 == 1.4013e-45) {
        if (fVar9 == 1.4013e-45) {
LAB_0041ebb0:
          fVar7 = -2.0;
          param_1[7] = -2.0;
        }
        else if (fVar17 == 1.4013e-45) {
LAB_0041ec20:
          fVar7 = -1.0;
          fVar17 = 1.4013e-45;
          param_1[7] = -1.0;
        }
        else {
          param_1[0x29a] = 0.0;
          param_1[7] = -2.6;
          if (param_1[6] != 0.0) {
            if (param_1[0xc] == 0.0) {
              puVar15 = particlePrepend(ParticleListHead,
                                        (int)(*param_1 + -7.0 + (float)(int)param_1[4]),
                                        (int)(param_1[1] + -4.0 + (float)(int)param_1[5]),"P_DUST_H"
                                        ,0,0);
              ParticleListHead = puVar15;
              puVar15[7] = 0x3e99999a;
              puVar15[0xd] = 1;
            }
            else if (param_1[0xc] == 1.4013e-45) {
              puVar15 = particlePrepend(ParticleListHead,(int)*param_1,
                                        (int)(param_1[1] + -4.0 + (float)(int)param_1[5]),"P_DUST_H"
                                        ,0,0);
              ParticleListHead = puVar15;
              puVar15[7] = 0xbe99999a;
              puVar15[0xd] = 0;
            }
          }
          playSfx(0);
          fVar7 = param_1[7];
          fVar17 = param_1[0x13];
          fVar9 = param_1[0x12];
        }
        param_1[9] = 0.0;
        fVar16 = param_1[6];
        puVar15 = (undefined4 *)*param_1;
        puVar11 = (undefined4 *)param_1[1];
      }
      else {
        if (fVar9 == 1.4013e-45) goto LAB_0041ebb0;
        if (fVar17 == 1.4013e-45) goto LAB_0041ec20;
        fVar7 = param_1[7];
        if (1.65 < fVar7) goto LAB_0041d0d4;
        local_3c = (undefined4 *)*param_1;
        fVar4 = floorf((float)local_3c);
        local_40 = (undefined4 *)param_1[1];
        fVar8 = floorf((float)local_40);
        if (param_1[0x297] == 1.4013e-45) {
          uVar6 = checkCollision((int)fVar4 + 2,(int)fVar8,param_1);
          if ((uVar6 & 1) == 0) goto LAB_0041e858;
          param_1[0x2c7] = 1.4013e-44;
          param_1[7] = -2.0;
          puVar15 = ParticleListHead;
          param_1[6] = -1.2;
          param_1[0x29a] = 0.0;
          param_1[0xc] = 0.0;
          param_1[0x290] = 0.0;
          param_1[0x291] = 0.0;
          ParticleListHead =
               particlePrepend(puVar15,(int)(*param_1 + -4.0 + (float)(int)param_1[4]),
                               (int)(param_1[1] + -7.0 + (float)(int)param_1[5]),"P_DUST_V",0,0);
          ParticleListHead[0xd] = 0;
          ParticleListHead[8] = 0x3e99999a;
LAB_0041ef94:
          playSfx(1);
          fVar9 = param_1[0x12];
        }
        else {
          if (param_1[0x298] != 1.4013e-45) {
            fVar16 = param_1[6];
            puVar15 = local_3c;
            puVar11 = local_40;
            goto LAB_0041d0ec;
          }
          uVar6 = checkCollision((int)fVar4 + -2,(int)fVar8,param_1);
          if ((uVar6 & 1) != 0) {
            param_1[0x2c7] = 1.4013e-44;
            param_1[7] = -2.0;
            puVar15 = ParticleListHead;
            param_1[6] = 1.2;
            param_1[0xc] = 1.4013e-45;
            param_1[0x29a] = 0.0;
            param_1[0x290] = 0.0;
            param_1[0x291] = 0.0;
            ParticleListHead =
                 particlePrepend(puVar15,(int)*param_1,
                                 (int)(param_1[1] + -7.0 + (float)(int)param_1[5]),"P_DUST_V",0,0);
            ParticleListHead[0xd] = 1;
            ParticleListHead[8] = 0x3e99999a;
            goto LAB_0041ef94;
          }
LAB_0041e858:
          fVar9 = param_1[0x12];
        }
        fVar7 = param_1[7];
        fVar17 = param_1[0x13];
        puVar15 = (undefined4 *)*param_1;
        puVar11 = (undefined4 *)param_1[1];
        fVar16 = param_1[6];
      }
    }
    else {
      fVar16 = param_1[6];
      if (fVar16 == 0.0) {
        fVar7 = param_1[7];
      }
      else {
        fVar16 = 0.0;
        param_1[6] = 0.0;
        fVar7 = param_1[7];
      }
      if (fVar7 != 0.0) {
        fVar7 = 0.0;
        param_1[7] = 0.0;
      }
      puVar13 = (undefined4 *)*param_1;
      if ((0.0 <= (float)puVar13) || (DAT_0044877c != 0)) {
        puVar15 = (undefined4 *)(float)(DAT_00448750 << 4);
        if ((float)puVar15 < (float)puVar13) {
          if (DAT_0044877c == 0) {
            *param_1 = (float)puVar15;
            goto LAB_0041d39c;
          }
          puVar11 = (undefined4 *)param_1[1];
          puVar15 = puVar13;
        }
        else {
          puVar11 = (undefined4 *)param_1[1];
          puVar15 = puVar13;
        }
      }
      else {
        *param_1 = 0.0;
        puVar15 = (undefined4 *)0x0;
LAB_0041d39c:
        puVar11 = (undefined4 *)param_1[1];
      }
      if ((0.0 <= (float)puVar11) || (DAT_00448780 != 0)) {
        puVar13 = (undefined4 *)(float)(DAT_00448754 << 4);
        if ((float)puVar11 <= (float)puVar13) goto LAB_0041d3d4;
        if (DAT_00448780 == 0) {
          param_1[1] = (float)puVar13;
          puVar11 = puVar13;
          goto LAB_0041d3d4;
        }
        fVar9 = param_1[0x297];
      }
      else {
        param_1[1] = 0.0;
        puVar11 = (undefined4 *)0x0;
LAB_0041d3d4:
        fVar9 = param_1[0x297];
      }
      if (fVar9 == 1.4013e-45) {
        param_1[0xc] = 0.0;
        puVar15 = (undefined4 *)((float)puVar15 - 1.0);
        *param_1 = (float)puVar15;
      }
      if (param_1[0x298] == 1.4013e-45) {
        param_1[0xc] = 1.4013e-45;
        puVar15 = (undefined4 *)((float)puVar15 + 1.0);
        *param_1 = (float)puVar15;
      }
      if (param_1[0x295] == 1.4013e-45) {
        puVar11 = (undefined4 *)((float)puVar11 - 1.0);
        param_1[1] = (float)puVar11;
      }
      if (param_1[0x296] == 1.4013e-45) {
        fVar9 = param_1[0x12];
        fVar17 = param_1[0x13];
        param_1[1] = (float)puVar11 + 1.0;
        puVar11 = (undefined4 *)((float)puVar11 + 1.0);
      }
      else {
        fVar9 = param_1[0x12];
        fVar17 = param_1[0x13];
      }
    }
  }
LAB_0041d0ec:
  if (fVar9 != 0.0) {
    if (fVar16 < -0.4) {
      param_1[6] = -0.4;
      param_1[0xc] = 0.0;
      fVar16 = -0.4;
    }
    else if (0.4 < fVar16) {
      param_1[6] = 0.4;
      param_1[0xc] = 1.4013e-45;
      fVar16 = 0.4;
    }
    if (fVar7 < -0.5) {
      param_1[7] = -0.5;
      fVar7 = -0.5;
    }
    else if (0.4 < fVar7) {
      param_1[7] = 0.4;
      fVar7 = 0.4;
    }
  }
  if (fVar17 != 0.0) {
    if (fVar16 < -0.2) {
      param_1[6] = -0.2;
      param_1[0xc] = 0.0;
      fVar16 = -0.2;
    }
    else if (0.2 < fVar16) {
      param_1[6] = 0.2;
      param_1[0xc] = 1.4013e-45;
      fVar16 = 0.2;
    }
    if (fVar7 < -0.3) {
      param_1[7] = -0.3;
      fVar7 = -0.3;
    }
    else if (0.2 < fVar7) {
      param_1[7] = 0.2;
      fVar7 = 0.2;
    }
  }
  playerTryMove(param_1,(float)puVar15 + fVar16,fVar7 + (float)puVar11,0);
  if (param_1[0x12] == 0.0) {
    fVar7 = param_1[0x2cf];
    param_1[0x2ce] = 2.10195e-43;
    if (fVar7 == 0.0) goto LAB_0041d1dc;
    if (fVar7 == (float)(((int)fVar7 / 0x3c) * 0x3c)) {
      if (param_1[0xc] == 2.8026e-45) {
        fVar17 = param_1[1];
        fVar7 = *param_1 + -8.0 + (float)(int)param_1[4];
        fVar9 = 6.0;
        goto LAB_0041e7cc;
      }
      iVar3 = (int)(*param_1 + 8.0);
      iVar10 = (int)(param_1[1] + 6.0);
LAB_0041d988:
      ParticleListHead = particlePrepend(ParticleListHead,iVar3,iVar10,"P_WATERDROP",0,0);
      fVar7 = param_1[0x2cf];
    }
    else {
      if (fVar7 == (float)(((int)fVar7 / 0x28) * 0x28)) {
        if (param_1[0xc] != 2.8026e-45) {
          iVar3 = (int)(*param_1 + 4.0);
          iVar10 = (int)(param_1[1] + 4.0);
          goto LAB_0041d988;
        }
        fVar17 = param_1[1];
        fVar7 = *param_1 + -4.0 + (float)(int)param_1[4];
        fVar9 = 4.0;
LAB_0041e7cc:
        iVar3 = (int)fVar7;
        iVar10 = (int)(fVar17 + fVar9);
        goto LAB_0041d988;
      }
      if (fVar7 == (float)(((int)fVar7 / 0x14) * 0x14)) {
        if (param_1[0xc] != 2.8026e-45) {
          ParticleListHead =
               particlePrepend(ParticleListHead,(int)(*param_1 + 2.0),(int)(param_1[1] + 5.0),
                               "P_WATERDROP",0,0);
          param_1[0x2cf] = (float)((int)param_1[0x2cf] + -1);
          goto LAB_0041d1dc;
        }
        fVar17 = param_1[1];
        fVar7 = *param_1 + -2.0 + (float)(int)param_1[4];
        fVar9 = 5.0;
        goto LAB_0041e7cc;
      }
    }
    param_1[0x2cf] = (float)((int)fVar7 + -1);
LAB_0041d1dc:
    fVar7 = param_1[0x13];
  }
  else {
    fVar7 = param_1[0x2ce];
    param_1[9] = 1.4013e-45;
    param_1[0x2c7] = 0.0;
    if (0 < (int)fVar7) {
      fVar7 = (float)((int)fVar7 + -1);
      param_1[0x2ce] = fVar7;
    }
    if (fVar7 == 0.0) {
      if (param_1[0xc] == 0.0) {
        fVar9 = param_1[1];
        fVar7 = *param_1 - 4.0;
      }
      else {
        if (param_1[0xc] != 1.4013e-45) {
          param_1[0x2ce] = 2.10195e-43;
          goto LAB_0041d1dc;
        }
        fVar9 = param_1[1];
        fVar7 = *param_1 + -3.0 + (float)(int)param_1[4];
      }
      ParticleListHead =
           particlePrepend(ParticleListHead,(int)fVar7,(int)(fVar9 + 5.0),"P_BUBBLE",0,0);
      param_1[0x2ce] = 2.10195e-43;
      goto LAB_0041d1dc;
    }
    fVar7 = param_1[0x13];
  }
  if (fVar7 == 0.0) {
    fVar7 = param_1[0x18];
  }
  else {
    param_1[9] = 1.4013e-45;
    param_1[0x2c7] = 0.0;
    fVar7 = param_1[0x18];
  }
  if (fVar7 == 0.0) {
    fVar7 = param_1[0x12];
  }
  else if (param_1[0x2cb] == 0.0) {
    param_1[0x2cb] = 1.68156e-43;
    if (param_1[0x2d5] == 0.0) {
      if ((gameplayType & 0xfffffffd) == 0) {
        fVar7 = param_1[8];
LAB_0041d42c:
        param_1[8] = (float)((int)fVar7 + -1);
LAB_0041d434:
        fVar7 = param_1[6];
      }
      else {
        if (gameplayType == 4) {
          fVar7 = param_1[8];
          goto LAB_0041d42c;
        }
        if (gameplayType == 3) {
          param_1[0x2d2] = (float)((int)param_1[0x2d2] + -5);
          goto LAB_0041d434;
        }
        fVar7 = param_1[6];
      }
      if (0.0 < fVar7) {
LAB_0041d44c:
        param_1[6] = -1.5;
      }
      else if (fVar7 < 0.0) {
LAB_0041eb70:
        param_1[6] = 1.5;
      }
      else if (fVar7 == 0.0) {
        if (param_1[0xc] == 1.4013e-45) goto LAB_0041d44c;
        if (param_1[0xc] == 0.0) goto LAB_0041eb70;
      }
      param_1[0x2c7] = 1.4013e-44;
      param_1[7] = -0.5;
    }
    playSfx(3);
    if (gameplayType == 2) {
      if (0 < (int)param_1[8]) {
        fVar7 = param_1[0x12];
        goto LAB_0041d488;
      }
      param_1[0x2d0] = (float)((int)param_1[0x2d0] + -1);
    }
    fVar7 = param_1[0x12];
  }
  else {
    fVar7 = param_1[0x12];
  }
LAB_0041d488:
  if (fVar7 == 0.0) {
    if (param_1[0x13] != 0.0) {
      fVar7 = param_1[0x2c9];
      goto LAB_0041d744;
    }
    if (param_1[0x18] != 0.0) {
      fVar7 = param_1[0x2c9];
      goto LAB_0041d744;
    }
  }
  else {
    fVar7 = param_1[0x2c9];
LAB_0041d744:
    if (fVar7 == 0.0) {
      fVar7 = param_1[0x2c8];
      goto LAB_0041d4ac;
    }
    FUN_0041cd14((int)param_1);
    fVar7 = param_1[0x2c9];
    fVar9 = param_1[0x18];
    *(undefined4 *)((int)fVar7 + 0xa70) = 0;
    *(undefined4 *)((int)fVar7 + 0xa78) = 0;
    param_1[0x2c9] = 0.0;
    if (fVar9 == 0.0) {
      param_1[0x2ca] = 8.40779e-44;
    }
    else {
      param_1[0x2ca] = param_1[0x2cb];
    }
  }
  fVar7 = param_1[0x2c8];
LAB_0041d4ac:
  if (fVar7 == 0.0) {
    fVar7 = param_1[0x2c9];
  }
  else {
    if (param_1[0x2cc] == 0.0) {
      doorLocked = 1;
    }
    else {
      changeGameMode(6);
      playSfx(9);
      musicManagerPlayTrack("LEVEL_COMPLETE");
    }
    fVar7 = param_1[0x2c9];
  }
  if (fVar7 == 0.0) {
    fVar7 = param_1[0x2ca];
  }
  else {
    if (*(int *)((int)fVar7 + 0xa70) == 0) {
      param_1[0x2c9] = 0.0;
    }
    fVar7 = param_1[0x2ca];
  }
  if (0 < (int)fVar7) {
    param_1[0x2ca] = (float)((int)fVar7 + -1);
  }
  if (0 < (int)param_1[0x2cb]) {
    param_1[0x2cb] = (float)((int)param_1[0x2cb] + -1);
  }
  fVar7 = floorf(*param_1);
  local_58 = (int)fVar7;
  fVar7 = floorf(param_1[1]);
  local_50 = param_1[4];
  local_4c = param_1[5];
  local_54 = (int)fVar7;
  if (EnemyListHead == (undefined4 *)0x0) {
    bVar1 = false;
    fVar7 = param_1[8];
  }
  else {
    uVar19 = 0xbf000000;
    uVar18 = 0x3fc00000c0a00000;
    bVar1 = false;
    puVar15 = EnemyListHead;
    do {
      fVar7 = floorf((float)puVar15[1]);
      local_68 = (int)fVar7;
      fVar7 = floorf((float)puVar15[2]);
      local_64 = (int)fVar7;
      local_60 = puVar15[5];
      local_5c = puVar15[6];
      bVar2 = boxesCollide(&local_58,&local_68);
      puVar11 = ParticleListHead;
      if (CONCAT31(extraout_var,bVar2) == 0) {
LAB_0041d59c:
        puVar15 = (undefined4 *)*puVar15;
      }
      else {
        fVar7 = param_1[8];
        if ((int)fVar7 < 1) goto LAB_0041d59c;
        iVar3 = puVar15[0x296];
        if (iVar3 == 0x21) {
          puVar15 = (undefined4 *)*puVar15;
          goto LAB_0041d5a0;
        }
        if (iVar3 == 0) {
          fVar7 = param_1[6];
          if (fVar7 < 0.0) {
            puVar15[0xd] = 0;
            puVar15[0xc] = 1;
          }
          if (0.0 < fVar7) {
            puVar15[0xd] = 1;
            puVar15[0xc] = 1;
          }
          goto LAB_0041d59c;
        }
        if (iVar3 == 2) {
          fVar7 = (float)puVar15[1];
          fVar9 = (float)puVar15[2];
          local_3c = &ParticleListHead;
          puVar15[0x29c] = 1;
          param_1[0x2cc] = 1.4013e-45;
          KeyPicked = (undefined4 *)0x5;
          DAT_00448300 = 0x96;
          local_40 = (undefined4 *)0x430000;
          puVar11 = particlePrepend(puVar11,(int)fVar7,(int)fVar9,"P_SPARKLE",0,0);
          fVar9 = (float)puVar15[1];
          fVar7 = (float)puVar15[2];
          iVar3 = puVar15[5];
          iVar10 = puVar15[6];
          *local_3c = puVar11;
          puVar11 = particlePrepend(puVar11,(int)(fVar9 + (float)uVar18 + (float)iVar3),
                                    (int)(fVar7 + (float)uVar18 + (float)iVar10),
                                    (char *)(local_40 + 0x189e),0,0);
          *local_3c = puVar11;
          playSfx(8);
          goto LAB_0041d59c;
        }
        if (iVar3 == 1) {
          if (2 < (int)fVar7) {
            puVar15 = (undefined4 *)*puVar15;
            goto LAB_0041d5a0;
          }
          puVar15[0x29c] = 1;
          param_1[8] = (float)((int)fVar7 + 1);
          playSfx(0xc);
          goto LAB_0041d59c;
        }
        if (iVar3 == 3) {
          if (gameplayType == 4) {
            if ((puVar15[0x21] == 0) && (puVar15[0x29c] == 0)) {
              fVar7 = param_1[0x2d0];
              puVar15[0x21] = 0x78;
              puVar15[0x2a1] = 0;
              param_1[0x2d0] = (float)((int)fVar7 + 1);
              playSfx(8);
              iVar3 = puVar15[0x296];
              goto LAB_0041d640;
            }
          }
          else {
            iVar10 = puVar15[0x2a1];
            if (((0 < iVar10) && (((int)param_1[0x2cd] >> (iVar10 + 3U & 0x1f) & 1U) != 0)) &&
               (puVar15[0x21] == 0)) {
              monkeysSaved = 1 << (iVar10 - 1U & 0x1f) | monkeysSaved;
              puVar15[0x21] = 0x78;
              puVar15[0x2a1] = 0;
              playSfx(8);
              iVar3 = puVar15[0x296];
              goto LAB_0041d640;
            }
          }
        }
        else {
LAB_0041d640:
          if (iVar3 == 4) {
            fVar7 = param_1[0x2cd];
            puVar15[0x29c] = 1;
            param_1[0x2cd] = (float)((uint)fVar7 | 0x10);
            local_3c = (undefined4 *)0x1;
            playSfx(8);
            iVar3 = puVar15[0x296];
            KeyPicked = local_3c;
            DAT_00448300 = 0x96;
          }
          if (iVar3 == 5) {
            fVar7 = param_1[0x2cd];
            puVar15[0x29c] = 1;
            param_1[0x2cd] = (float)((uint)fVar7 | 0x20);
            playSfx(8);
            iVar3 = puVar15[0x296];
            KeyPicked = (undefined4 *)0x2;
            DAT_00448300 = 0x96;
          }
          if (iVar3 == 6) {
            fVar7 = param_1[0x2cd];
            puVar15[0x29c] = 1;
            param_1[0x2cd] = (float)((uint)fVar7 | 0x40);
            playSfx(8);
            iVar3 = puVar15[0x296];
            KeyPicked = (undefined4 *)0x3;
            DAT_00448300 = 0x96;
          }
        }
        if (iVar3 == 7) {
          fVar7 = param_1[0x2cd];
          puVar15[0x29c] = 1;
          param_1[0x2cd] = (float)((uint)fVar7 | 0x80);
          playSfx(8);
          KeyPicked = (undefined4 *)0x4;
          DAT_00448300 = 0x96;
        }
        uVar6 = gameplayType;
        if (puVar15[0x20] == 0) {
          puVar15 = (undefined4 *)*puVar15;
          goto LAB_0041d5a0;
        }
        puVar11 = puVar15 + 1;
        if (puVar15[0xc] == 9) goto LAB_0041d59c;
        local_44 = puVar11;
        if ((int)puVar15[0x29b] < 1) {
          if ((float)puVar15[8] < param_1[7]) {
            if ((float)(int)param_1[5] + param_1[1] <
                (float)((int)puVar15[6] / 2) + (float)puVar15[2]) {
              if (puVar15[0x20] == 2) {
                fVar7 = param_1[0x2d7];
                puVar15[0x29b] = 300;
                puVar15[7] = 0;
                puVar15[8] = 0;
                puVar15[0x2a0] = 0;
                if (fVar7 != 0.0) {
                  param_1[0x2dd] = (float)puVar11;
                }
                playSfx(2);
                bVar1 = true;
                goto LAB_0041d59c;
              }
              fVar7 = param_1[0x2cb];
            }
            else {
              fVar7 = param_1[0x2cb];
            }
          }
          else {
            fVar7 = param_1[0x2cb];
          }
          if (fVar7 == 0.0) {
            iVar3 = puVar15[0x1f];
            if (iVar3 == 0) {
              iVar3 = puVar15[0x296];
            }
            else {
              uVar12 = gameplayType & 0xfffffffd;
              param_1[0x2cb] = 1.68156e-43;
              if (uVar12 == 0) {
                fVar7 = param_1[0x2d5];
LAB_0041ec64:
                if (fVar7 == 0.0) {
                  param_1[8] = (float)((int)param_1[8] - iVar3);
                }
              }
              else if (uVar6 == 4) {
                fVar7 = param_1[0x2d5];
                goto LAB_0041ec64;
              }
              playSfx(3);
              if (param_1[0x2c9] != 0.0) {
                FUN_0041cd14((int)param_1);
                fVar7 = param_1[0x2c9];
                fVar9 = param_1[0x2cb];
                *(undefined4 *)((int)fVar7 + 0xa70) = 0;
                *(undefined4 *)((int)fVar7 + 0xa78) = 0;
                param_1[0x2c9] = 0.0;
                param_1[0x2ca] = fVar9;
              }
              fVar7 = param_1[6];
              if (0.0 < fVar7) {
LAB_0041e12c:
                param_1[6] = -1.5;
              }
              else if (fVar7 < 0.0) {
LAB_0041eebc:
                param_1[6] = (float)((ulonglong)uVar18 >> 0x20);
              }
              else if (fVar7 == 0.0) {
                if ((float)puVar15[7] < 0.0) goto LAB_0041e12c;
                if (0.0 < (float)puVar15[7]) goto LAB_0041eebc;
              }
              uVar6 = gameplayType;
              param_1[0x2c7] = 1.4013e-44;
              param_1[7] = (float)uVar19;
              if (uVar6 == 2) {
                if ((int)param_1[8] < 1) {
                  param_1[0x2d0] = (float)((int)param_1[0x2d0] + -1);
                  goto LAB_0041e168;
                }
                iVar3 = puVar15[0x296];
              }
              else if (uVar6 == 3) {
                param_1[0x2d2] = (float)((int)param_1[0x2d2] + -5);
LAB_0041e168:
                iVar3 = puVar15[0x296];
              }
              else {
                iVar3 = puVar15[0x296];
              }
            }
          }
          else {
            iVar3 = puVar15[0x296];
          }
          if (iVar3 == 0x14) {
            puVar15[0xc] = 9;
            goto LAB_0041d59c;
          }
          puVar15 = (undefined4 *)*puVar15;
        }
        else {
          if (gameplayType == 2) {
            if (puVar15[0x29e] == 0) {
              fVar7 = param_1[0x2c9];
            }
            else {
              if (puVar15[0x29f] != local_48) {
                if (param_1[0x2cb] != 0.0) {
                  uVar6 = 2;
                  puVar15[0xc] = 9;
                  goto LAB_0041d6b8;
                }
                param_1[0x2cb] = 1.68156e-43;
                if (param_1[0x2d5] == 0.0) {
                  param_1[8] = (float)((int)param_1[8] + -1);
                }
                playSfx(3);
                if (param_1[0x2c9] != 0.0) {
                  FUN_0041cd14((int)param_1);
                  fVar7 = param_1[0x2c9];
                  fVar9 = param_1[0x2cb];
                  *(undefined4 *)((int)fVar7 + 0xa70) = 0;
                  *(undefined4 *)((int)fVar7 + 0xa78) = 0;
                  param_1[0x2c9] = 0.0;
                  param_1[0x2ca] = fVar9;
                }
                fVar7 = param_1[6];
                if (0.0 < fVar7) {
LAB_0041e5c4:
                  param_1[6] = -1.5;
                }
                else if (fVar7 < 0.0) {
LAB_0041f060:
                  param_1[6] = 1.5;
                }
                else if (fVar7 == 0.0) {
                  if ((float)puVar15[7] < 0.0) goto LAB_0041e5c4;
                  if (0.0 < (float)puVar15[7]) goto LAB_0041f060;
                }
                param_1[7] = -0.5;
                param_1[0x2c7] = 1.4013e-44;
                uVar6 = gameplayType;
                if ((int)param_1[8] < 1) {
                  iVar3 = puVar15[0x29f];
                  if (iVar3 == 2) {
                    DAT_0044ac08 = DAT_0044ac08 + 1;
                    puVar15[0xc] = 9;
                  }
                  else if (iVar3 < 3) {
                    if (iVar3 != 1) goto LAB_0041e5ec;
                    DAT_004494f8 = DAT_004494f8 + 1;
                    puVar15[0xc] = 9;
                  }
                  else if (iVar3 == 3) {
                    DAT_0044a080 = DAT_0044a080 + 1;
                    puVar15[0xc] = 9;
                  }
                  else {
                    if (iVar3 != 4) goto LAB_0041e5ec;
                    DAT_0044b790 = DAT_0044b790 + 1;
                    puVar15[0xc] = 9;
                  }
                }
                else {
LAB_0041e5ec:
                  uVar6 = gameplayType;
                  puVar15[0xc] = 9;
                }
                goto LAB_0041d6b8;
              }
              fVar7 = param_1[0x2c9];
            }
            goto LAB_0041e5f8;
          }
          if (gameplayType == 3) {
            if (puVar15[0x29e] == 0) {
              fVar7 = param_1[0x2c9];
            }
            else {
              if (puVar15[0x29f] != local_48) {
                if (tagModeWarmup == 0) {
                  puVar11 = &Player1;
                  if (0 < numOfPlayers) {
                    iVar3 = 1;
                    do {
                      if ((puVar11[0x2d4] != 0) && (puVar15[0x29f] == iVar3)) {
                        fVar7 = param_1[0x2cb];
                        puVar11[0x2d4] = 0;
                        param_1[0x2d4] = 1.4013e-45;
                        if (fVar7 == 0.0) {
                          param_1[0x2cb] = 1.68156e-43;
                          playSfx(3);
                          if (param_1[0x2c9] != 0.0) {
                            FUN_0041cd14((int)param_1);
                            fVar7 = param_1[0x2c9];
                            fVar9 = param_1[0x2cb];
                            *(undefined4 *)((int)fVar7 + 0xa70) = 0;
                            *(undefined4 *)((int)fVar7 + 0xa78) = 0;
                            param_1[0x2c9] = 0.0;
                            param_1[0x2ca] = fVar9;
                          }
                          fVar7 = param_1[6];
                          if (0.0 < fVar7) goto LAB_0041ee14;
                          if (fVar7 < 0.0) goto LAB_0041f21c;
                          if (fVar7 != 0.0) goto LAB_0041ee20;
                          fVar7 = (float)puVar15[7];
                          if (fVar7 < 0.0) goto LAB_0041ee14;
                          goto joined_r0x0041f210;
                        }
                        break;
                      }
                      bVar2 = iVar3 < numOfPlayers;
                      puVar11 = (undefined4 *)puVar11[0x2e1];
                      iVar3 = iVar3 + 1;
                    } while (bVar2);
                  }
                  goto LAB_0041d59c;
                }
                tagModeWarmup = 0;
                bVar2 = 0 < numOfPlayers;
                param_1[0x2d4] = 1.4013e-45;
                if (bVar2) {
                  puVar11 = &Player1;
                  puVar13 = (undefined4 *)0x0;
                  do {
                    puVar13 = (undefined4 *)((int)puVar13 + 1);
                    if (puVar11[0x2c9] != 0) {
                      local_40 = puVar11;
                      local_3c = puVar13;
                      FUN_0041cd14((int)puVar11);
                      iVar3 = local_40[0x2c9];
                      uVar14 = local_40[0x2cb];
                      *(undefined4 *)(iVar3 + 0xa70) = 0;
                      *(undefined4 *)(iVar3 + 0xa78) = 0;
                      local_40[0x2c9] = 0;
                      local_40[0x2ca] = uVar14;
                      puVar11 = local_40;
                      puVar13 = local_3c;
                    }
                    puVar11 = (undefined4 *)puVar11[0x2e1];
                  } while ((int)puVar13 < numOfPlayers);
                }
                if (param_1[0x2cb] != 0.0) {
                  uVar6 = gameplayType;
                  goto LAB_0041d6b8;
                }
                param_1[0x2cb] = 1.68156e-43;
                playSfx(3);
                fVar7 = param_1[6];
                if (0.0 < fVar7) {
LAB_0041ee14:
                  param_1[6] = -1.5;
                }
                else if (fVar7 < 0.0) {
LAB_0041f21c:
                  param_1[6] = 1.5;
                }
                else if (fVar7 == 0.0) {
                  fVar7 = (float)puVar15[7];
                  if (fVar7 < 0.0) goto LAB_0041ee14;
joined_r0x0041f210:
                  if (0.0 < fVar7) goto LAB_0041f21c;
                }
LAB_0041ee20:
                param_1[0x2c7] = 1.4013e-44;
                param_1[7] = -0.5;
                uVar6 = gameplayType;
                goto LAB_0041d6b8;
              }
              fVar7 = param_1[0x2c9];
            }
            if (fVar7 == 0.0) {
              if (puVar15[0x29d] == 0) {
                if (param_1[0x2ca] == 0.0) {
                  if (param_1[0x12] == 0.0) {
                    if (param_1[0x13] == 0.0) {
                      if ((tagModeWarmup != 0) || (param_1[0x2d4] != 0.0)) goto LAB_0041e634;
                      puVar15 = (undefined4 *)*puVar15;
                    }
                    else {
                      puVar15 = (undefined4 *)*puVar15;
                    }
                  }
                  else {
                    puVar15 = (undefined4 *)*puVar15;
                  }
                }
                else {
                  puVar15 = (undefined4 *)*puVar15;
                }
              }
              else {
                puVar15 = (undefined4 *)*puVar15;
              }
            }
            else {
              puVar15 = (undefined4 *)*puVar15;
            }
          }
          else if (gameplayType == 4) {
            if (puVar15[0x29e] == 0) {
              fVar7 = param_1[0x2c9];
            }
            else {
              if (puVar15[0x29f] != local_48) {
                if (param_1[0x2cb] == 0.0) {
                  param_1[0x2cb] = 1.68156e-43;
                  if (param_1[0x2d5] == 0.0) {
                    param_1[8] = (float)((int)param_1[8] + -1);
                  }
                  playSfx(3);
                  if (param_1[0x2c9] != 0.0) {
                    FUN_0041cd14((int)param_1);
                    fVar7 = param_1[0x2c9];
                    fVar9 = param_1[0x2cb];
                    *(undefined4 *)((int)fVar7 + 0xa70) = 0;
                    *(undefined4 *)((int)fVar7 + 0xa78) = 0;
                    param_1[0x2c9] = 0.0;
                    param_1[0x2ca] = fVar9;
                  }
                  fVar7 = param_1[6];
                  if (0.0 < fVar7) {
LAB_0041e71c:
                    param_1[6] = -1.5;
                  }
                  else if (fVar7 < 0.0) {
LAB_0041f0b4:
                    param_1[6] = 1.5;
                  }
                  else if (fVar7 == 0.0) {
                    if ((float)puVar15[7] < 0.0) goto LAB_0041e71c;
                    if (0.0 < (float)puVar15[7]) goto LAB_0041f0b4;
                  }
                  param_1[0x2c7] = 1.4013e-44;
                  param_1[7] = -0.5;
                  goto LAB_0041e5ec;
                }
                puVar15[0xc] = 9;
                uVar6 = 4;
                goto LAB_0041d6b8;
              }
              fVar7 = param_1[0x2c9];
            }
LAB_0041e5f8:
            if (fVar7 == 0.0) {
              if (puVar15[0x29d] == 0) {
                if (param_1[0x2ca] == 0.0) {
                  if (param_1[0x12] == 0.0) {
                    if (param_1[0x13] == 0.0) {
LAB_0041e634:
                      param_1[0x2c9] = (float)puVar11;
                      puVar15[0x29d] = 1;
                      puVar15[0x29e] = 0;
                      puVar15[7] = 0;
                      puVar15[8] = 0;
                      puVar15[0x29f] = local_48;
                      playSfx(4);
                      uVar6 = gameplayType;
                      goto LAB_0041d6b8;
                    }
                    puVar15 = (undefined4 *)*puVar15;
                  }
                  else {
                    puVar15 = (undefined4 *)*puVar15;
                  }
                }
                else {
                  puVar15 = (undefined4 *)*puVar15;
                }
              }
              else {
                puVar15 = (undefined4 *)*puVar15;
              }
            }
            else {
              puVar15 = (undefined4 *)*puVar15;
            }
          }
          else {
LAB_0041d6b8:
            if (uVar6 == 0) {
              if (param_1[0x2c9] == 0.0) {
                if (puVar15[0x29d] == 0) {
                  if (puVar15[0xc] == 9) {
                    puVar15 = (undefined4 *)*puVar15;
                  }
                  else if (param_1[0x2ca] == 0.0) {
                    if (param_1[0x12] == 0.0) {
                      if (param_1[0x13] == 0.0) {
                        param_1[0x2c9] = (float)local_44;
                        puVar15[0x29d] = 1;
                        puVar15[0x29e] = 0;
                        puVar15[7] = 0;
                        puVar15[8] = 0;
                        puVar15[0x29f] = local_48;
                        playSfx(4);
                        goto LAB_0041d59c;
                      }
                      puVar15 = (undefined4 *)*puVar15;
                    }
                    else {
                      puVar15 = (undefined4 *)*puVar15;
                    }
                  }
                  else {
                    puVar15 = (undefined4 *)*puVar15;
                  }
                }
                else {
                  puVar15 = (undefined4 *)*puVar15;
                }
              }
              else {
                puVar15 = (undefined4 *)*puVar15;
              }
            }
            else {
              puVar15 = (undefined4 *)*puVar15;
            }
          }
        }
      }
LAB_0041d5a0:
    } while (puVar15 != (undefined4 *)0x0);
    fVar7 = param_1[8];
  }
  if (fVar7 == 0.0) {
    if (gameplayType == 0) {
      if (param_1[0xb] == 1.26117e-44) {
        pfVar5 = (float *)param_1[0x2c9];
      }
      else {
        fVar7 = param_1[0x2c9];
        param_1[0xb] = 1.26117e-44;
        if (fVar7 != 0.0) {
          *(undefined4 *)((int)fVar7 + 0xa68) = 0x168;
          *(undefined4 *)((int)fVar7 + 0xa70) = 0;
          param_1[0x2ca] = 2.8026e-44;
          param_1[0x2c9] = 0.0;
        }
        musicManagerPlayTrack("GAMEOVER");
        pfVar5 = (float *)param_1[0x2c9];
      }
    }
    else if (((gameplayType == 2) || (gameplayType == 4)) || (gameplayType == 3)) {
      fVar7 = param_1[0x2c9];
      pfVar5 = (float *)0x0;
      if (fVar7 != 0.0) {
        *(undefined4 *)((int)fVar7 + 0xa70) = 0;
        *(undefined4 *)((int)fVar7 + 0xa68) = 0x168;
        param_1[0x2ca] = 2.8026e-44;
        param_1[0x2c9] = 0.0;
        pfVar5 = (float *)0x0;
      }
    }
    else {
      pfVar5 = (float *)param_1[0x2c9];
    }
  }
  else {
    pfVar5 = (float *)param_1[0x2c9];
  }
  if (bVar1) {
    param_1[0x2ca] = 7.00649e-45;
    param_1[7] = -1.3;
  }
  if (pfVar5 == (float *)0x0) {
    fVar7 = param_1[0x299];
  }
  else {
    if (param_1[0xc] == 0.0) {
      fVar7 = -1.0;
    }
    else {
      fVar7 = 1.0;
    }
    fVar9 = param_1[4];
    fVar17 = param_1[5];
    fVar4 = *param_1;
    fVar8 = param_1[1];
    pfVar5[0xc] = param_1[0xc];
    *pfVar5 = (((float)((int)fVar9 / 2) + fVar4) - (float)((int)pfVar5[4] / 2)) + fVar7;
    pfVar5[1] = (fVar8 - (float)((int)fVar17 / 2)) - (float)((int)pfVar5[5] / 2);
    fVar7 = param_1[0x299];
  }
  if (fVar7 != 0.0) {
    param_1[0x299] = 0.0;
    toggleReverb();
    pfVar5 = (float *)param_1[0x2c9];
    if (pfVar5 != (float *)0x0) {
      local_40 = (undefined4 *)floorf(*pfVar5);
      fVar7 = floorf(pfVar5[1]);
      uVar6 = checkCollision((int)(float)local_40,(int)fVar7,pfVar5);
      if ((uVar6 & 1) == 0) {
        fVar7 = param_1[0x2c9];
        fVar9 = param_1[0xc];
        *(undefined4 *)((int)fVar7 + 0xa70) = 0;
        *(undefined4 *)((int)fVar7 + 0xa68) = 0x168;
        if (fVar9 == 0.0) {
          fVar9 = -1.0;
        }
        else {
          fVar9 = 1.0;
        }
        fVar4 = param_1[6];
        fVar17 = param_1[7];
        *(undefined4 *)((int)fVar7 + 0xa74) = 1;
        *(float *)((int)fVar7 + 0x18) = fVar9 + fVar4;
        *(float *)((int)fVar7 + 0x1c) = fVar17 - 1.0;
        param_1[0x2c9] = 0.0;
        param_1[0x2ca] = 2.8026e-44;
        playSfx(5);
      }
    }
  }
  playerStateUpdate((int)param_1);
  return;
}

