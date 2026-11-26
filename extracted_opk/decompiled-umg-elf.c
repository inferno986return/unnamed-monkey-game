
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 main(int param_1,int param_2)

{
  FILE *param0;
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char *__nptr;
  char *pcVar9;
  int iVar10;
  undefined4 *puVar11;
  char *__nptr_00;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  
  uVar2 = time((time_t *)0x0);
  srand(uVar2);
  skipMenus = 0;
  quit = 0;
  homeDir = getHomeDir(homeDir);
  bVar1 = loadConfig(homeDir,"/config.cfg");
  if (CONCAT31(extraout_var,bVar1) != 0) {
    fwrite("Failed to read any config, loading hardcoded values\n",1,0x34,_stderr);
    loadDefaultConfig();
  }
  if (1 < param_1) {
    iVar3 = 1;
LAB_00405e04:
    iVar10 = iVar3 << 2;
    iVar4 = iVar3;
LAB_00405e08:
    puVar8 = (undefined4 *)(param_2 + iVar10);
    pcVar7 = (char *)*puVar8;
    iVar3 = strcmp(pcVar7,"-res");
    if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-r"), iVar3 == 0)) {
      if (((param_1 <= iVar4 + 2) || (*(char *)puVar8[1] == '-')) ||
         (pcVar9 = (char *)puVar8[2], *pcVar9 == '-')) {
LAB_004061c8:
        fprintf(_stderr,"Not enough arguments for %s\n",pcVar7);
        quit = 1;
        goto LAB_00405f14;
      }
      screenWidth = atoi((char *)puVar8[1]);
      screenHeight = atoi(pcVar9);
    }
    else {
      iVar3 = strcmp(pcVar7,"-scale");
      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-s"), iVar3 == 0)) {
        iVar3 = iVar4 + 1;
        if ((param_1 <= iVar3) || (*(char *)puVar8[1] == '-')) {
          fprintf(_stderr,"Not enough arguments for %s\n",pcVar7);
          quit = 1;
          goto LAB_00406168;
        }
        iVar10 = iVar3 * 4;
        scale = atoi((char *)puVar8[1]);
        iVar4 = iVar3;
        goto LAB_00405e08;
      }
      iVar3 = strcmp(pcVar7,"-extract");
      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-e"), iVar3 == 0)) {
        if ((iVar4 + 2 < param_1) &&
           ((puVar8 = (undefined4 *)(param_2 + iVar10 + 4), *(char *)*puVar8 != '-' &&
            (puVar11 = (undefined4 *)(param_2 + iVar10 + 8), *(char *)*puVar11 != '-')))) {
          iVar3 = initLib();
          if (iVar3 != 0) {
            fwrite("ERROR: Failed to init SDL\n",1,0x1a,_stderr);
          }
          extractCollisionData((char *)*puVar8,(char *)*puVar11);
          cleanLib();
          quit = 1;
          goto LAB_00405f14;
        }
        goto LAB_004061c8;
      }
      iVar3 = strcmp(pcVar7,"-map");
      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-m"), iVar3 == 0)) {
        iVar3 = iVar4 + 1;
        if (param_1 <= iVar3) {
LAB_00406648:
          fprintf(_stderr,"Not enough arguments for %s\n",pcVar7);
          goto LAB_00406168;
        }
        puVar8 = (undefined4 *)(param_2 + iVar10 + 4);
        pcVar9 = (char *)*puVar8;
        if (*pcVar9 == '-') goto LAB_00406648;
        iVar10 = iVar3 * 4;
        sVar5 = strlen(pcVar9);
        mapFile = malloc(sVar5 + 1);
        pcVar7 = strcpy(mapFile,(char *)*puVar8);
        printf("Loading map: %s\n",pcVar7);
        skipMenus = 1;
        iVar4 = iVar3;
        goto LAB_00405e08;
      }
      iVar3 = strcmp(pcVar7,"-players");
      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-p"), iVar3 == 0)) {
        iVar3 = iVar4 + 1;
        if ((param_1 <= iVar3) || (pcVar9 = (char *)puVar8[1], *pcVar9 == '-')) goto LAB_00406648;
        iVar4 = atoi(pcVar9);
        switch(iVar4) {
        case 0:
        case 1:
          newNumOfPlayers = 1;
          break;
        case 2:
          newNumOfPlayers = 2;
          break;
        case 3:
          newNumOfPlayers = 3;
          break;
        case 4:
          newNumOfPlayers = 4;
          break;
        default:
          fprintf(_stderr,"Too many players: %s. Must be in range: 1-4\n",pcVar9);
          quit = 1;
        }
        goto LAB_00405e04;
      }
      iVar3 = strcmp(pcVar7,"-bots");
      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-b"), iVar3 == 0)) {
        if (((iVar4 + 4 < param_1) &&
            (((*(char *)puVar8[1] != '-' && (pcVar9 = (char *)puVar8[2], *pcVar9 != '-')) &&
             (__nptr_00 = (char *)puVar8[3], *__nptr_00 != '-')))) &&
           (__nptr = (char *)puVar8[4], *__nptr != '-')) {
          numOfBots = atoi((char *)puVar8[1]);
          DAT_00448498 = atoi(pcVar9);
          DAT_0044849c = atoi(__nptr_00);
          DAT_004484a0 = atoi(__nptr);
        }
        else {
          fprintf(_stderr,"Not enough arguments for %s\n",pcVar7);
        }
      }
      else {
        iVar3 = strcmp(pcVar7,"-debug");
        if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-d"), iVar3 == 0)) {
          debugMode = (uint)(debugMode == 0);
          if (debugMode == 0) {
            puts("Debug mode disabled");
          }
          else {
            puts("Debug mode enabled");
            putchar(10);
            puts("Program compiled with the following flags:");
            printf("VERSION_REVISION=%d\n",0x4da);
            puts("VERSION_DEMO");
            puts("LIB_SDL");
            puts("PLATFORM_GCW");
            puts("IS_HANDHELD");
            puts("WITH_LOADING_SCREEN");
            puts("HAVE_JOYSTICK");
            puts("WITH_HWSURFACE");
            puts("WITH_HOME_DIR");
            puts("HAVE_SOUND");
            puts("HAVE_MUSIC");
            putchar(10);
          }
        }
        else {
          iVar3 = strcmp(pcVar7,"-dres");
          if ((iVar3 != 0) && (iVar3 = strcmp(pcVar7,"-dr"), iVar3 != 0)) {
            iVar3 = strcmp(pcVar7,"-gamemode");
            if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-gm"), iVar3 == 0)) {
              param0 = _stderr;
              iVar3 = iVar4 + 1;
              if ((param_1 <= iVar3) || (*(char *)puVar8[1] == '-')) {
                iVar3 = atoi((char *)puVar8[1]);
                fprintf(param0,"Invalid value for game mode: %d\n",iVar3);
                goto LAB_00406168;
              }
              newGameplayType = atoi((char *)puVar8[1]);
              if ((newGameplayType != 2) &&
                 ((newGameplayType < 3 || ((newGameplayType != 3 && (newGameplayType != 4)))))) {
                newGameplayType = 0;
              }
              goto LAB_00405e04;
            }
            iVar3 = strcmp(pcVar7,"-help");
            if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-h"), iVar3 == 0)) {
              printf("Unnamed Monkey Game version %d.%d.%d (GCW0 preview 0.2)\n",0,4,0x4da);
              puts("-r or -res [w h]\t\t\tsets the resolution to the given values (default 320 240)"
                  );
              puts("-s or -scale [1-3]\t\t\tscales the screen the given times (default 1)");
              puts("-v or -version\t\t\t\tdisplays the program version");
              pcVar7 = "-h or -help\t\t\t\tthis screen";
LAB_00406a40:
              puts(pcVar7);
              quit = 1;
            }
            else {
              iVar3 = strcmp(pcVar7,"-version");
              if ((iVar3 == 0) || (iVar3 = strcmp(pcVar7,"-v"), iVar3 == 0)) {
                printf("Unnamed Monkey Game version %d.%d.%d (GCW0 preview 0.2)\n",0,4,0x4da);
                pcVar7 = 
                "(c) 2010-2013 Artur Rojek, Andreas Bjerkeholt, Thorin Hopkins, Daniel Kvarfordt";
                goto LAB_00406a40;
              }
              iVar3 = strcmp(pcVar7,"-string");
              if (iVar3 == 0) {
                iVar3 = iVar4 + 1;
                if (param_1 <= iVar3) {
                  fwrite("Not enough parameters for -string\n",1,0x22,_stderr);
                  quit = 1;
                  goto LAB_00405f2c;
                }
                randomTextMode = 1;
                iVar4 = iVar3;
                do {
                  pcVar7 = randomTextStr;
                  if (randomTextStr == (char *)0x0) {
                    sVar5 = strlen((char *)puVar8[1]);
                    randomTextStr = malloc(sVar5 + 1);
                    if (randomTextStr == (char *)0x0) goto LAB_00406c88;
                    strcpy(randomTextStr,(char *)puVar8[1]);
                  }
                  else {
                    sVar5 = strlen(randomTextStr);
                    sVar6 = strlen((char *)puVar8[1]);
                    pcVar7 = realloc(pcVar7,sVar5 + sVar6 + 2);
                    if (pcVar7 == (char *)0x0) {
LAB_00406c88:
                      fwrite("Out of memory",1,0xd,_stderr);
                      quit = 1;
                      goto LAB_00405e04;
                    }
                    randomTextStr = pcVar7;
                    sVar5 = strlen(pcVar7);
                    pcVar7[sVar5] = ' ';
                    (pcVar7 + sVar5)[1] = '\0';
                    strcat(randomTextStr,(char *)puVar8[1]);
                  }
                  iVar4 = iVar4 + 1;
                  puVar8 = puVar8 + 1;
                } while (iVar4 != param_1);
                iVar10 = iVar3 * 4;
                iVar4 = iVar3;
                goto LAB_00405e08;
              }
              iVar3 = strcmp(pcVar7,"--key");
              if (iVar3 == 0) {
                printf("%d\n",0x31723);
                quit = 1;
                goto LAB_00406168;
              }
              iVar3 = strcmp(pcVar7,"-reverbtest");
              if (iVar3 == 0) {
                if (((param_1 <= iVar4 + 2) || (*(char *)puVar8[1] == '-')) ||
                   (pcVar9 = (char *)puVar8[2], *pcVar9 == '-')) goto LAB_004061c8;
                uVar2 = atoi((char *)puVar8[1]);
                reverbTestDepth = uVar2;
                reverbTestDelay = atoi(pcVar9);
                if (100 < uVar2) {
                  fwrite("reverb depth must be in the range 0-100\n",1,0x28,_stderr);
                  quit = 1;
                  goto LAB_00406168;
                }
              }
              else if (*pcVar7 == '-') {
                printf("Unknown command \"%s\", try -help for the list of available commands\n",
                       pcVar7);
                quit = 1;
                goto LAB_00406168;
              }
            }
LAB_00405f14:
            iVar4 = iVar4 + 1;
            if (param_1 <= iVar4) goto LAB_00405f24;
            iVar10 = iVar4 * 4;
            goto LAB_00405e08;
          }
          if ((param_1 <= iVar4 + 2) ||
             ((*(char *)puVar8[1] == '-' || (pcVar9 = (char *)puVar8[2], *pcVar9 == '-'))))
          goto LAB_004061c8;
          fakeScreenWidth = atoi((char *)puVar8[1]);
          fakeScreenHeight = atoi(pcVar9);
        }
      }
    }
LAB_00406168:
    iVar4 = iVar4 + 1;
    if (param_1 <= iVar4) goto LAB_00405f24;
    iVar10 = iVar4 * 4;
    goto LAB_00405e08;
  }
LAB_00405f24:
  if ((quit == 0) && (iVar3 = initLib(), iVar3 != 0)) {
    quit = 1;
    fwrite("ERROR: Failed to init SDL\n",1,0x1a,_stderr);
  }
LAB_00405f2c:
  gameMode = 0;
  newGameMode = 0;
  changeGameModeEx(1,0,0);
  dVar12 = 0.0;
  iVar3 = SDL_GetTicks();
  dVar15 = 16.666666666666668;
  dVar16 = dVar15;
  do {
    while( true ) {
      if (quit != 0) {
        updateConfigAtExit();
        drawSaving();
        saveConfig(homeDir,"/config.cfg");
        if (quit != 0) {
          mobManagerDeleteMobs();
          cleanLib();
          if (mapFile != (char *)0x0) {
            free(mapFile);
            mapFile = (char *)0x0;
            free(mapFileNext);
            mapFileNext = (void *)0x0;
          }
          unloadTranslation();
          menuDestroy();
          levelSelectUnload();
          musicManagerUnload();
          if (homeDir != (char *)0x0) {
            free(homeDir);
          }
        }
        return 0;
      }
      iVar4 = SDL_GetTicks();
      if (DAT_00448388 == 0) break;
      DAT_00448388 = 0;
      dVar12 = dVar16;
LAB_00405fac:
      dVar13 = 16.666666666666668;
      dVar14 = dVar13;
      do {
        while (dVar12 = dVar12 - dVar13, transitionOutRunning == 0) {
          iVar3 = transitionIn + -1;
          if (transitionIn < 1) goto LAB_00405fe4;
          transitionIn = iVar3;
          if (remappingKeys != 0) goto LAB_00405ff4;
LAB_00406034:
          input();
          logic();
          if (dVar12 < dVar14) goto LAB_00406058;
        }
        if (transitionOut < transitionOutMax) {
          transitionOut = transitionOut + 1;
        }
        else {
          performChangeGameMode();
        }
LAB_00405fe4:
        if (remappingKeys == 0) goto LAB_00406034;
LAB_00405ff4:
        logic();
      } while (dVar14 <= dVar12);
LAB_00406058:
      draw();
      iVar3 = iVar4;
    }
    dVar12 = dVar12 + (double)(iVar4 - iVar3);
    if (dVar15 <= dVar12) goto LAB_00405fac;
    SDL_Delay(1);
    iVar3 = iVar4;
  } while( true );
}