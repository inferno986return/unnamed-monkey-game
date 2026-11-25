## Reverse-engineering the .opk

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game$ unsquashfs -d extracted_opk *.opk
Parallel unsquashfs: Using 8 processors
170 inodes (178 blocks) to write

[=======================================================================================================-] 348/348 100%

created 170 files
created 9 directories
created 0 symlinks
created 0 devices
created 0 fifos
created 0 sockets
created 0 hardlinks

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game$ ls
00058300.gif  extracted_opk      umg-gcw-exclusive-preview-0.4.opk
README.md     extracted_opk.zip  umg-tum2011-30-12-11-din-lin-win

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game$ cd extracted_opk/
user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ ls
data  default.gcw0.desktop  umg.elf  umg.png

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ file extracted_opk/umg.elf
extracted_opk/umg.elf: cannot open `extracted_opk/umg.elf' (No such file or directory)

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ file umg.elf
umg.elf: ELF 32-bit LSB executable, MIPS, MIPS32 rel2 version 1 (SYSV), dynamically linked, interpreter /lib/ld-uClibc.so.0, stripped

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ readelf -d extracted_opk/umg.elf | grep NEEDED
readelf: Error: 'extracted_opk/umg.elf': No such file

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ readelf -d umg.elf | grep NEEDED
 0x00000001 (NEEDED)                     Shared library: [libSDL_mixer-1.2.so.0]
 0x00000001 (NEEDED)                     Shared library: [libSDL-1.2.so.0]
 0x00000001 (NEEDED)                     Shared library: [libmodplug.so.1]
 0x00000001 (NEEDED)                     Shared library: [libm.so.0]
 0x00000001 (NEEDED)                     Shared library: [libpthread.so.0]
 0x00000001 (NEEDED)                     Shared library: [libgcc_s.so.1]
 0x00000001 (NEEDED)                     Shared library: [libc.so.0]

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ strings umg.elf | grep -E "SDL|hif|us
c|tracks\.dat|data/" | head -n 40
SDL_GetTicks
SDL_Delay
SDL_FreeSurface
SDL_MapRGB
SDL_FillRect
SDL_LockSurface
SDL_UnlockSurface
SDL_CreateRGBSurface
SDL_MapRGBA
SDL_UpperBlit
SDL_SetColorKey
hif_load
SDL_DisplayFormat
SDL_RWFromFile
SDL_LoadBMP_RW
SDL_Flip
SDL_PollEvent
SDL_GetMouseState
SDL_WarpMouse
SDL_Init
SDL_NumJoysticks
SDL_JoystickOpen
SDL_JoystickName
SDL_JoystickNumAxes
SDL_JoystickNumHats
SDL_JoystickNumButtons
SDL_JoystickEventState
SDL_SetVideoMode
SDL_ShowCursor
SDL_WM_SetCaption
SDL_JoystickClose
SDL_GetError
SDL_Quit
libSDL_mixer-1.2.so.0
libSDL-1.2.so.0
ERROR: Failed to init SDL
LIB_SDL
./data/lang/
./data/config.cfg
./data/gfx/

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ cat default.gcw0.desktop
[Desktop Entry]
Name=UMG
Comment=Unnamed Monkey Game - exclusive preview
Exec=umg.elf
Terminal=false
Type=Application
StartupNotify=true
Icon=umg
Categories=games;

user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ strings -n 4 umg.elf | grep -E "hif|mob|map|col|usc|track|font|config|lang|ERROR|WARN|DEBUG"
remappingKeys
mobManagerDeleteMobs
colLayerSet
mapFileNext
colLayerGet
remapMenu
mapSelMenu
mapFile
fontFat
fontThin
st_font_create
mobManagerLoadMobs
st_font_load_table
mapHintNum
mobManagerGetPlayer
mapHintText
mobManagerGetMob
mobManagerGetMobByInt
st_font_draw_text
st_font_draw_text_ascii
st_font_draw_text_center
st_font_draw_text_ascii_center
hif_load
st_font_destroy
/config.cfg
Failed to read any config, loading hardcoded values
ERROR: Failed to init SDL
-map
Loading map: %s
0@ERROR: (loadTranslation) Out of memory!
./data/lang/
Loading config from: %s
./data/config.cfg
Attempting to open the default config
WARNING: Config in version %d.%d.r%d, while game in version %d.%d.r%d
WARNING: (loadConfig) Unknown color palette: %s. Loading default (0).
WARNING: Joystick deadzone value must be greater than 0
WARNING: J_REVERSE_AXIS_X value must be in range 0 - 1
WARNING: J_REVERSE_AXIS_Y value must be in range 0 - 1
ERROR: out of memory when allocating path for %s!
ERROR: out of memory!
.col
WARNING (loadMap): %s - unknown effect! Defaulting to EFFECT_NONE.
WARNING (loadMap): EnemyListHead is not NULL. This shouldn't happen. Setting it to NULL now.
./data/maps/
ERROR (loadMobConfig): Out of memory!
ERROR: (loadText) out of memory!
ERROR: (loadText) *outputStr is not NULL
ERROR: (loadText) Couldn't find string "%s" in %s
Failed to load level select map data in %s
./data/music/tracks.dat
ERROR: (saveConfig) Can't open %s
Saving config
WARNING: (saveConfig) Unknown color palette. Saving default (0).
#Button configuration:
ERROR: (saveMap) Can't open %s
Saving map
ERROR: (saveCollisionLayer) Can't open %s
Saving collision layer
ERROR: (getKeyFromString) Invalid key %s
ERROR: (loadScript) Can't open %s
ERROR: (loadScript) Invalid line %i in %s
ERROR: (loadScript) Out of memory while allocating an array of %i elements
=ERROR: Not enough memory for loading the map!
ERROR: (_menuCreateMenuItem) Out of memory
demo01.map
demo02.map
demo03.map
demo04.map
demo05.map
demo06.map
demo07.map
ERROR: (menuRemap) Incorrect player: player %d
./data/maps/unnamed.map
?./data/gfx/fontFat00
./data/gfx/fontThin00
intro.map
e1m1.map
dm01.map
dm02.map
dm03.map
dm04.map
[ERROR] extractCollisionData: Out of memory!
WARNING: TILE:%d x:%d y:%d contains incorrect color (%d) for the collision layer. Ignoring...
ERROR (prependElement): Out of memory!
ERROR (prependElement): Didn't find the specified mob (%s)!
ERROR (prependElement): Didn't find the specified mob (%d)!
./data/mobs/
MobManager found %d mob dats (enemies)!
./data/mobs/part/
MobManager found %d mob dats (particles)!
/mobs/part/
./data/mobs/monkeySmall.dat
ERROR: (saveGameProgress) Can't open %s
WARNING: (dMap) Empty array. Aborting.
ERROR: (dMap) Negative tile coordinates!
ERROR (dLock): invalid key value
ERROR: (loadImage) Filename is null!
ERROR: (loadImage) Memory allocation failed
.hif
ERROR: (loadImage) Failed to load image: %s
ERROR: (loadImage) Failed to optimize image: %s
ERROR: (flip) Failed to flip the screen
ERROR: (changeSplitScreenRes) Unable to create split-screen surfaces
ERROR: (initSDL) Unable to initialize SDL: %s
ERROR: Out of memory!
ERROR: (initSDL) Unable to initialize audio
ERROR: (initSDL) Unable to set the resolution: %dx%d %dbpp
ERROR: (initSDL) Unable to set the resolution: %dx%d %dbpp (x%d scale)
ERROR: (changeVideoMode) Unable to set new resolution: %dx%d %dbpp
ERROR: (changeVideoMode) Unable to set new resolution: %dx%d %dbpp (x%d scale)
ERROR: (loadMod) Unable to load file: %s
ERROR: (loadMod) buffer allocation failed
ERROR: (loadMod) Read from file failed
ERROR: (playSfx) No such audio file: %d
Save map
Load map
Change mob groups
.rld_map
user@laptop:/mnt/c/Users/user/Documents/GitHub/unnamed-monkey-game/extracted_opk$ readelf -s umg.elf 2>/dev/null || true

Symbol table '.dynsym' contains 582 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND
     1: 00448104     0 NOTYPE  GLOBAL DEFAULT  ABS _fbss
     2: 0042ef40   352 FUNC    GLOBAL DEFAULT   10 countFps
     3: 00431e70   548 FUNC    GLOBAL DEFAULT   10 loadMod
     4: 0042fb20   328 FUNC    GLOBAL DEFAULT   10 setMouseArea
     5: 0040bd68  1024 FUNC    GLOBAL DEFAULT   10 loadText
     6: 00448104     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign12
     7: 004489b8  2952 OBJECT  GLOBAL DEFAULT   23 Player1
     8: 00448494    16 OBJECT  GLOBAL DEFAULT   23 numOfBots
     9: 0040f534    96 FUNC    GLOBAL DEFAULT   10 fillMapArray
    10: 00448108     4 OBJECT  GLOBAL DEFAULT   22 textIngameYourTime
    11: 004476f8     4 OBJECT  GLOBAL DEFAULT   18 newNumOfPlayers
    12: 004487b8    24 OBJECT  GLOBAL DEFAULT   23 mainMenu
    13: 0042b1d0    16 FUNC    GLOBAL DEFAULT   10 saveGameDisableSaving
    14: 0042c6d4   344 FUNC    GLOBAL DEFAULT   10 dBackgroundAnim
    15: 004477d4     4 OBJECT  GLOBAL DEFAULT   18 splitScreenHeight
    16: 0042bc10   136 FUNC    GLOBAL DEFAULT   10 musicManagerUnload
    17: 0040fd28  4352 FUNC    GLOBAL DEFAULT   10 menuCreate
    18: 0042d99c    76 FUNC    GLOBAL DEFAULT   10 dText
    19: 0042b0bc    12 FUNC    GLOBAL DEFAULT   10 saveCorruptGetOption
    20: 00448674     4 OBJECT  GLOBAL DEFAULT   23 screen
    21: 0044830c     4 OBJECT  GLOBAL DEFAULT   22 sfxJump
    22: 004284dc   296 FUNC    GLOBAL DEFAULT   10 mobManagerGetMob
    23: 0044810c     4 OBJECT  GLOBAL DEFAULT   22 textEditorSetEdi[...]
    24: 0040f400   308 FUNC    GLOBAL DEFAULT   10 initMapArray
    25: 00448110     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelArena04
    26: 0041c218   548 FUNC    GLOBAL DEFAULT   10 playerStateUpdate
    27: 0040997c   708 FUNC    GLOBAL DEFAULT   10 loadDefaultConfig
    28: 004477d8     4 OBJECT  GLOBAL DEFAULT   18 splitScreenWidth
    29: 00448114     4 OBJECT  GLOBAL DEFAULT   22 textIngameContinue
    30: 004292c8    96 FUNC    GLOBAL DEFAULT   10 listDeleteAll
    31: 0041fdfc  1920 FUNC    GLOBAL DEFAULT   10 checkCollision
    32: 0042c8d8   776 FUNC    GLOBAL DEFAULT   10 dBorder
    33: 0044863c     4 OBJECT  GLOBAL DEFAULT   23 bgdControlsIMG
    34: 004487d0    24 OBJECT  GLOBAL DEFAULT   23 inGameMenu
    35: 0044838c     4 OBJECT  GLOBAL DEFAULT   23 debugMode
    36: 0044862c     4 OBJECT  GLOBAL DEFAULT   23 bgdEffDarkIMG
    37: 00448118     4 OBJECT  GLOBAL DEFAULT   22 textMenuBotP4On
    38: 0044811c     4 OBJECT  GLOBAL DEFAULT   22 textMenuAspectRatio
    39: 00449540  2952 OBJECT  GLOBAL DEFAULT   23 Player3
    40: 00413110   176 FUNC    GLOBAL DEFAULT   10 ticksToClock
    41: 0042a6b8    84 FUNC    GLOBAL DEFAULT   10 orderDraw
    42: 00448120     4 OBJECT  GLOBAL DEFAULT   22 textMenuSfxVol4
    43: 004175a0   120 FUNC    GLOBAL DEFAULT   10 drawLoading
    44: 00431dc8   168 FUNC    GLOBAL DEFAULT   10 initLibmodplug
    45: 004484d0     4 OBJECT  GLOBAL DEFAULT   23 ParticleListHead
    46: 00430994   180 FUNC    GLOBAL DEFAULT   10 checkMouseMoved
    47: 0042d9e8    60 FUNC    GLOBAL DEFAULT   10 dTextCenteredStFont
    48: 00431760   628 FUNC    GLOBAL DEFAULT   10 changeVideoMode
    49: 0042d698   712 FUNC    GLOBAL DEFAULT   10 dLifebar
    50: 00448124     4 OBJECT  GLOBAL DEFAULT   22 textMenuSetPlayer4
    51: 00448128     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelArena02
    52: 0044812c     4 OBJECT  GLOBAL DEFAULT   22 textMenuScale2x
    53: 0042f7c0   856 FUNC    GLOBAL DEFAULT   10 drawFade
    54: 00447758    16 OBJECT  GLOBAL DEFAULT   18 pGrayscale
    55: 00000001     0 SECTION GLOBAL DEFAULT  ABS _DYNAMIC_LINKING
    56: 0041fc20    36 FUNC    GLOBAL DEFAULT   10 colLayerGet
    57: 0044b7d8  2648 OBJECT  GLOBAL DEFAULT   23 selectPlayer
    58: 00448130     4 OBJECT  GLOBAL DEFAULT   22 textMenuSetPlayer2
    59: 00448134     4 OBJECT  GLOBAL DEFAULT   22 textEditorTileEdit
    60: 00448310     4 OBJECT  GLOBAL DEFAULT   22 sfxWallJump
    61: 0042a4e8    72 FUNC    GLOBAL DEFAULT   10 scriptFree
    62: 00448138     4 OBJECT  GLOBAL DEFAULT   22 textMenuNumOfPlayers4
    63: 0044813c     4 OBJECT  GLOBAL DEFAULT   22 textMenuGameplay[...]
    64: 0041b808  2576 FUNC    GLOBAL DEFAULT   10 playerTryMove
    65: 0042b030   140 FUNC    GLOBAL DEFAULT   10 saveCorruptUpdate
    66: 0040f86c   432 FUNC    GLOBAL DEFAULT   10 getRespawnPosition
    67: 004321f8   152 FUNC    GLOBAL DEFAULT   10 toggleReverb
    68: 0044860c    20 OBJECT  GLOBAL DEFAULT   23 orderIMG
    69: 00448314     4 OBJECT  GLOBAL DEFAULT   22 sfxHit
    70: 004256d4   152 FUNC    GLOBAL DEFAULT   10 enemyDelete
    71: 00448140     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelLevel01
    72: 0041238c    24 FUNC    GLOBAL DEFAULT   10 menuSetParentMenu
    73: 00448144     4 OBJECT  GLOBAL DEFAULT   22 textMenuBotP2Off
    74: 0041fa00   276 FUNC    GLOBAL DEFAULT   10 allocateCollisionData
    75: 00448148     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelLevel05
    76: 004477b4     4 OBJECT  GLOBAL DEFAULT   18 musicVol
    77: 0042c82c   172 FUNC    GLOBAL DEFAULT   10 dBackground
    78: 0041b5cc   552 FUNC    GLOBAL DEFAULT   10 playerInit
    79: 00448620     4 OBJECT  GLOBAL DEFAULT   23 bgdEffSnow2IMG
    80: 00427204   144 FUNC    GLOBAL DEFAULT   10 st_font_destroy
    81: 004477b0     4 OBJECT  GLOBAL DEFAULT   18 sfxVol
    82: 0044846c     4 OBJECT  GLOBAL DEFAULT   23 transitionIn
    83: 00448304     4 OBJECT  GLOBAL DEFAULT   22 introController
    84: 004476b0     4 OBJECT  GLOBAL DEFAULT   18 editorState
    85: 0044814c     4 OBJECT  GLOBAL DEFAULT   22 textMenuBotP4Off
    86: 00448150     4 OBJECT  GLOBAL DEFAULT   22 textMenuMusicVol4
    87: 0041b058   244 FUNC    GLOBAL DEFAULT   10 setCamera
    88: 00448154     4 OBJECT  GLOBAL DEFAULT   22 textCheatNoclipOn
    89: 004482e4     4 OBJECT  GLOBAL DEFAULT   22 gameMode
    90: 0042501c   644 FUNC    GLOBAL DEFAULT   10 enemyDrawAll
    91: 004487e8    24 OBJECT  GLOBAL DEFAULT   23 inEditorMobMenu
    92: 004131c0    88 FUNC    GLOBAL DEFAULT   10 intToClock
    93: 004482d0     4 OBJECT  GLOBAL DEFAULT   22 drawTitle
    94: 004485c0     4 OBJECT  GLOBAL DEFAULT   23 mouseRight
    95: 00448158     4 OBJECT  GLOBAL DEFAULT   22 textMenuVideo
    96: 0042ccbc   392 FUNC    GLOBAL DEFAULT   10 dTileList2
    97: 004485f8     4 OBJECT  GLOBAL DEFAULT   23 isFullscreen
    98: 0040dd18   364 FUNC    GLOBAL DEFAULT   10 saveGameProgress
    99: 00432e00    28 FUNC    GLOBAL DEFAULT   12 _fini
   100: 00432290   772 FUNC    GLOBAL DEFAULT   10 loadSfx
   101: 00429100   128 FUNC    GLOBAL DEFAULT   10 listInsertLast
   102: 00448658     4 OBJECT  GLOBAL DEFAULT   23 gameLogoIMG
   103: 0041cee0  9296 FUNC    GLOBAL DEFAULT   10 playerUpdate
   104: 0042079c   224 FUNC    GLOBAL DEFAULT   10 generatePlatformArray
   105: 0044815c     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign03
   106: 00448160     4 OBJECT  GLOBAL DEFAULT   22 textEditorBackgr[...]
   107: 004476e4     4 OBJECT  GLOBAL DEFAULT   18 drawCaptions
   108: 004477c0     4 OBJECT  GLOBAL DEFAULT   18 audioSampleRate
   109: 00406fc0    16 FUNC    GLOBAL DEFAULT   10 resetFrameSkip
   110: 00448164     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign07
   111: 00448800    24 OBJECT  GLOBAL DEFAULT   23 audOptMenu
   112: 00448168     4 OBJECT  GLOBAL DEFAULT   22 textMenuSample11025
   113: 00448668     4 OBJECT  GLOBAL DEFAULT   23 screenSplitP1
   114: 004482dc     4 OBJECT  GLOBAL DEFAULT   22 tmpTile
   115: 0042df90   120 FUNC    GLOBAL DEFAULT   10 clipImage
   116: 0044c304   160 OBJECT  GLOBAL DEFAULT   23 windowBordersClip
   117: 004271ac    88 FUNC    GLOBAL DEFAULT   10 st_font_create
   118: 0042a4c8    32 FUNC    GLOBAL DEFAULT   10 scriptReset
   119: 0041b7f4     8 FUNC    GLOBAL DEFAULT   10 playerFree
   120: 0042bbf4     8 FUNC    GLOBAL DEFAULT   10 timerIsStarted
   121: 0044816c     4 OBJECT  GLOBAL DEFAULT   22 textMenuScale4x
   122: 0041afd0   136 FUNC    GLOBAL DEFAULT   10 initCamera
   123: 00448318     4 OBJECT  GLOBAL DEFAULT   22 sfxBump
   124: 00448170     4 OBJECT  GLOBAL DEFAULT   22 textMenuBotP3On
   125: 004260a0   972 FUNC    GLOBAL DEFAULT   10 particlePrepend
   126: 00448650     4 OBJECT  GLOBAL DEFAULT   23 locksIMG
   127: 00448174     4 OBJECT  GLOBAL DEFAULT   22 textMenuBack
   128: 00447800     0 OBJECT  GLOBAL DEFAULT  ABS _GLOBAL_OFFSET_TABLE_
   129: 00448600     4 OBJECT  GLOBAL DEFAULT   23 fakeScreenWidth
   130: 004482fc     8 OBJECT  GLOBAL DEFAULT   22 KeyPicked
   131: 0044c4fc    56 OBJECT  GLOBAL DEFAULT   23 libmodplugSettings
   132: 004473d4     4 OBJECT  GLOBAL DEFAULT   18 reverbTestDepth
   133: 0040eb44   536 FUNC    GLOBAL DEFAULT   10 saveCollisionLayer
   134: 0042b598   424 FUNC    GLOBAL DEFAULT   10 saveGameWriteToFile
   135: 00426c10   156 FUNC    GLOBAL DEFAULT   10 introUpdate
   136: 0042de70   288 FUNC    GLOBAL DEFAULT   10 dBoundaryBox
   137: 00448690   296 OBJECT  GLOBAL DEFAULT   23 curLvl
   138: 004327b8    20 FUNC    GLOBAL DEFAULT   10 changeVolume
   139: 0040e078  2764 FUNC    GLOBAL DEFAULT   10 saveMap
   140: 0042b7c4   616 FUNC    GLOBAL DEFAULT   10 saveGameLoadFromFile
   141: 0044837c     4 OBJECT  GLOBAL DEFAULT   23 randomTextMode
   142: 0044831c     4 OBJECT  GLOBAL DEFAULT   22 sfxItem
   143: 00448454     4 OBJECT  GLOBAL DEFAULT   23 gameplayType
   144: 00448320     4 OBJECT  GLOBAL DEFAULT   22 musicPos
   145: 00425800  1968 FUNC    GLOBAL DEFAULT   10 enemyUpdateAll
   146: 00448178     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign11
   147: 00448818    24 OBJECT  GLOBAL DEFAULT   23 delProgrMenu
   148: 0044817c     4 OBJECT  GLOBAL DEFAULT   22 textEditorMobEdit
   149: 00448954    16 OBJECT  GLOBAL DEFAULT   23 tileList
   150: 00448180     4 OBJECT  GLOBAL DEFAULT   22 textMenuBotP2On
   151: 00448184     4 OBJECT  GLOBAL DEFAULT   22 textEditorForegr[...]
   152: 00429180    84 FUNC    GLOBAL DEFAULT   10 listInsertFirst
   153: 0044c3a4   128 OBJECT  GLOBAL DEFAULT   23 playerCaptionsClip
   154: 0042bd08   148 FUNC    GLOBAL DEFAULT   10 musicManagerGetM[...]
   155: 004274ec   388 FUNC    GLOBAL DEFAULT   10 st_font_draw_text
   156: 0041b220   324 FUNC    GLOBAL DEFAULT   10 updateCamera
   157: 00448188     4 OBJECT  GLOBAL DEFAULT   22 textMenuScale1x
   158: 004150d0    68 FUNC    GLOBAL DEFAULT   10 changeGameMode
   159: 00411ad4  2232 FUNC    GLOBAL DEFAULT   10 menuHandleAction
   160: 0044818c     4 OBJECT  GLOBAL DEFAULT   22 textCheatGodmodeOff
   161: 004485b8     8 OBJECT  GLOBAL DEFAULT   23 MousePos
   162: 004482e8     4 OBJECT  GLOBAL DEFAULT   22 quit
   163: 0042cfe0    72 FUNC    GLOBAL DEFAULT   10 updateMapAnimation
   164: 004477b8     4 OBJECT  GLOBAL DEFAULT   18 enableSfx
   165: 0044864c     4 OBJECT  GLOBAL DEFAULT   23 editorMenuIMG
   166: 004272dc   344 FUNC    GLOBAL DEFAULT   10 st_font_load_table
   167: 0042bbfc     8 FUNC    GLOBAL DEFAULT   10 timerIsPaused
   168: 0042e40c  2868 FUNC    GLOBAL DEFAULT   10 drawAnim
   169: 0044c240    16 OBJECT  GLOBAL DEFAULT   23 AreaJumpMid
   170: 0042f20c   648 FUNC    GLOBAL DEFAULT   10 loadImage
   171: 0044a0c8  2952 OBJECT  GLOBAL DEFAULT   23 Player2
   172: 00447490     6 OBJECT  GLOBAL DEFAULT   18 hiscoreStr
   173: 0044c250    16 OBJECT  GLOBAL DEFAULT   23 AreaWalkRight
   174: 0042dd48   296 FUNC    GLOBAL DEFAULT   10 dTextScroll
   175: 0040eebc   920 FUNC    GLOBAL DEFAULT   10 loadScript
   176: 00432140    44 FUNC    GLOBAL DEFAULT   10 setMusicVolume
   177: 004484b0     4 OBJECT  GLOBAL DEFAULT   23 showText
   178: 00448190     4 OBJECT  GLOBAL DEFAULT   22 textMenuKeyboard
   179: 00448640     4 OBJECT  GLOBAL DEFAULT   23 bgdStarsIMG
   180: 00448194     4 OBJECT  GLOBAL DEFAULT   22 textMenuShowFpsOff
   181: 0044c260    16 OBJECT  GLOBAL DEFAULT   23 AreaWait
   182: 004477cc     4 OBJECT  GLOBAL DEFAULT   18 scale
   183: 0042d028   728 FUNC    GLOBAL DEFAULT   10 dMap
   184: 00448974    16 OBJECT  GLOBAL DEFAULT   23 levelTime
   185: 00448198     4 OBJECT  GLOBAL DEFAULT   22 textMenuSfxVol1
   186: 0044819c     4 OBJECT  GLOBAL DEFAULT   22 textMenuSfxVol5
   187: 0044c270    16 OBJECT  GLOBAL DEFAULT   23 AreaWalkLeft
   188: 00448408     4 OBJECT  GLOBAL DEFAULT   23 selectedEditLayer
   189: 004481a0     4 OBJECT  GLOBAL DEFAULT   22 textMenuSetPlayer3
   190: 00407c9c  3324 FUNC    GLOBAL DEFAULT   10 unloadTranslation
   191: 00427714    36 FUNC    GLOBAL DEFAULT   10 st_font_draw_tex[...]
   192: 0042a928   104 FUNC    GLOBAL DEFAULT   10 levelSelectUnload
   193: 0044c280    16 OBJECT  GLOBAL DEFAULT   23 AreaMenu
   194: 004481a4     4 OBJECT  GLOBAL DEFAULT   22 textMenuSetPlayer1
   195: 004481a8     4 OBJECT  GLOBAL DEFAULT   22 textIngameGameOver
   196: 004481ac     4 OBJECT  GLOBAL DEFAULT   22 textMenuNumOfPlayers3
   197: 0042b740   132 FUNC    GLOBAL DEFAULT   10 saveGameResetScores
   198: 004482ec     4 OBJECT  GLOBAL DEFAULT   22 skipMenus
   199: 0042bac8    12 FUNC    GLOBAL DEFAULT   10 stopTimer
   200: 004481b0     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign09
   201: 0042bd9c    80 FUNC    GLOBAL DEFAULT   10 musicManagerPlayTrack
   202: 004481b4     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelLevel07
   203: 00426f04   536 FUNC    GLOBAL DEFAULT   10 cchar_convert_fr[...]
   204: 0041ade0   492 FUNC    GLOBAL DEFAULT   10 draw
   205: 0040c294  1548 FUNC    GLOBAL DEFAULT   10 loadCampaign
   206: 00448394     4 OBJECT  GLOBAL DEFAULT   23 gameLang
   207: 0041120c  2248 FUNC    GLOBAL DEFAULT   10 menuUpdateLevelS[...]
   208: 0041b370   188 FUNC    GLOBAL DEFAULT   10 upscale2
   209: 004481b8     4 OBJECT  GLOBAL DEFAULT   22 textMenuSfxVolOff
   210: 00448458     4 OBJECT  GLOBAL DEFAULT   23 tagModeWarmup
   211: 00447704     4 OBJECT  GLOBAL DEFAULT   18 scrollPos
   212: 004481bc     4 OBJECT  GLOBAL DEFAULT   22 textMenuQuitToMenu
   213: 00432594   220 FUNC    GLOBAL DEFAULT   10 playSfx
   214: 004483c8     4 OBJECT  GLOBAL DEFAULT   23 remappingKeys
   215: 00448920    50 OBJECT  GLOBAL DEFAULT   23 levelCompletionTime
   216: 0041f3a4   128 FUNC    GLOBAL DEFAULT   10 cleanAnim
   217: 0040bc0c   348 FUNC    GLOBAL DEFAULT   10 loadTextStFont
   218: 004481c0     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelLevel04
   219: 004482f0     4 OBJECT  GLOBAL DEFAULT   22 ingameState
   220: 0044f7f0     0 NOTYPE  GLOBAL DEFAULT  ABS _gp
   221: 00408b48   224 FUNC    GLOBAL DEFAULT   10 getWords
   222: 004481c4     4 OBJECT  GLOBAL DEFAULT   22 textMenuMusicVol1
   223: 0042822c   316 FUNC    GLOBAL DEFAULT   10 hif_load
   224: 00432670   328 FUNC    GLOBAL DEFAULT   10 closeAudio
   225: 004484c8     4 OBJECT  GLOBAL DEFAULT   23 EnemyListHead
   226: 0041f430  1476 FUNC    GLOBAL DEFAULT   10 extractCollisionData
   227: 004481c8     4 OBJECT  GLOBAL DEFAULT   22 textMenuGameplay[...]
   228: 004481cc     4 OBJECT  GLOBAL DEFAULT   22 textMenuPaletteO[...]
   229: 0041fc90   100 FUNC    GLOBAL DEFAULT   10 boxesCollide
   230: 0044865c     4 OBJECT  GLOBAL DEFAULT   23 screenSplitP4
   231: 004477c4     4 OBJECT  GLOBAL DEFAULT   18 splitScreen
   232: 004481d0     4 OBJECT  GLOBAL DEFAULT   22 textMenuMusicVol5
   233: 00448830    24 OBJECT  GLOBAL DEFAULT   23 contMenu
   234: 004319d4   804 FUNC    GLOBAL DEFAULT   10 cleanLib
   235: 0040f3a4    92 FUNC    GLOBAL DEFAULT   10 updateConfigAtExit
   236: 0044c290    20 OBJECT  GLOBAL DEFAULT   23 event
   237: 00448624     4 OBJECT  GLOBAL DEFAULT   23 bgdEffSnowIMG
   238: 004481d4     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign02
   239: 0042a5d0   232 FUNC    GLOBAL DEFAULT   10 orderUpdate
   240: 00447768    16 OBJECT  GLOBAL DEFAULT   18 pFaded
   241: 0040cb00  4632 FUNC    GLOBAL DEFAULT   10 saveConfig
   242: 004481d8     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign06
   243: 00448848    24 OBJECT  GLOBAL DEFAULT   23 othOptMenu
   244: 0040de84   500 FUNC    GLOBAL DEFAULT   10 loadGameProgress
   245: 0042d610   136 FUNC    GLOBAL DEFAULT   10 dLock
   246: 004481dc     4 OBJECT  GLOBAL DEFAULT   22 textIngameBestTime
   247: 004481e0     4 OBJECT  GLOBAL DEFAULT   22 textCheatGodmodeOn
   248: 004481e4     4 OBJECT  GLOBAL DEFAULT   22 textMenuControls
   249: 00430090  2196 FUNC    GLOBAL DEFAULT   10 input
   250: 0042bb34    84 FUNC    GLOBAL DEFAULT   10 unpauseTimer
   251: 0042b37c   216 FUNC    GLOBAL DEFAULT   10 saveGameSetScore
   252: 004481e8     4 OBJECT  GLOBAL DEFAULT   22 textMenuBotP3Off
   253: 00447488     4 OBJECT  GLOBAL DEFAULT   18 menuValue
   254: 0042a82c   252 FUNC    GLOBAL DEFAULT   10 levelSelectLoadC[...]
   255: 0042fc68  1064 FUNC    GLOBAL DEFAULT   10 changeKeyMapping
   256: 0042ae1c   520 FUNC    GLOBAL DEFAULT   10 levelSelectDraw
   257: 0044c424    32 OBJECT  GLOBAL DEFAULT   23 locksClip
   258: 00420750    76 FUNC    GLOBAL DEFAULT   10 freePlatformArray
   259: 00406fd0  3276 FUNC    GLOBAL DEFAULT   10 loadTranslation
   260: 00412984  1928 FUNC    GLOBAL DEFAULT   10 menuDraw
   261: 004481ec     4 OBJECT  GLOBAL DEFAULT   22 textMenuPlay
   262: 00448450     4 OBJECT  GLOBAL DEFAULT   23 newGameplayType
   263: 004477dc     4 OBJECT  GLOBAL DEFAULT   18 screenHeight
   264: 00448324     4 OBJECT  GLOBAL DEFAULT   22 sfxThunder
   265: 004481f0     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign14
   266: 004482d4     4 OBJECT  GLOBAL DEFAULT   22 drawTitleNextTurn
   267: 00448860    24 OBJECT  GLOBAL DEFAULT   23 extrasMenu
   268: 004485cc     4 OBJECT  GLOBAL DEFAULT   23 joyDevice
   269: 00448878    24 OBJECT  GLOBAL DEFAULT   23 vidOptMenu
   270: 004218bc   336 FUNC    GLOBAL DEFAULT   10 prependElement
   271: 004481f4     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign10
   272: 0042da24    60 FUNC    GLOBAL DEFAULT   10 dTextCentered
   273: 00448644     4 OBJECT  GLOBAL DEFAULT   23 playerCaptionsIMG
   274: 0040f254   336 FUNC    GLOBAL DEFAULT   10 scanDirectoryAnd[...]
   275: 00415154  4224 FUNC    GLOBAL DEFAULT   10 performChangeGameMode
   276: 0042d300   784 FUNC    GLOBAL DEFAULT   10 dMapWrap
   277: 0040fa20    64 FUNC    GLOBAL DEFAULT   10 menuLogo
   278: 00426cac   496 FUNC    GLOBAL DEFAULT   10 introDraw
   279: 0044c444   128 OBJECT  GLOBAL DEFAULT   23 editorMenuClip
   280: 004484c0     4 OBJECT  GLOBAL DEFAULT   23 numberOfPlatforms
   281: 00425fb0   228 FUNC    GLOBAL DEFAULT   10 allocatePath
   282: 00448890    24 OBJECT  GLOBAL DEFAULT   23 optMenu
   283: 00447498     6 OBJECT  GLOBAL DEFAULT   18 currentTimeStr
   284: 00428604   196 FUNC    GLOBAL DEFAULT   10 mobManagerGetMobByInt
   285: 004481f8     4 OBJECT  GLOBAL DEFAULT   22 textMenuCaptionsFull
   286: 004481fc     4 OBJECT  GLOBAL DEFAULT   22 textMenuMusicVolOff
   287: 00448648     4 OBJECT  GLOBAL DEFAULT   23 windowBordersIMG
   288: 00448328     4 OBJECT  GLOBAL DEFAULT   22 sfxFrog
   289: 004482f4     4 OBJECT  GLOBAL DEFAULT   22 newGameMode
   290: 004473c0     0 NOTYPE  GLOBAL DEFAULT   18 _fdata
   291: 00448398     4 OBJECT  GLOBAL DEFAULT   23 mapHintNum
   292: 0040c8a0   608 FUNC    GLOBAL DEFAULT   10 loadMusicTrackIndexes
   293: 00448200     4 OBJECT  GLOBAL DEFAULT   22 textEditorSave
   294: 004473e0   112 OBJECT  GLOBAL DEFAULT   18 mapHintText
   295: 00447778    16 OBJECT  GLOBAL DEFAULT   18 pOriginal
   296: 00448204     4 OBJECT  GLOBAL DEFAULT   22 textMenuExit
   297: 0042f6f8   188 FUNC    GLOBAL DEFAULT   10 updateScreen
   298: 0041b560   108 FUNC    GLOBAL DEFAULT   10 createPlayerList
   299: 00448208     4 OBJECT  GLOBAL DEFAULT   22 textMenuSfxVol2
   300: 004483b0     4 OBJECT  GLOBAL DEFAULT   23 levelSelected
   301: 00448378     4 OBJECT  GLOBAL DEFAULT   23 randomTextStr
   302: 00448964    15 OBJECT  GLOBAL DEFAULT   23 curTile
   303: 0044820c     4 OBJECT  GLOBAL DEFAULT   22 textMenuOther
   304: 0042cbe0   220 FUNC    GLOBAL DEFAULT   10 dBorderLine
   305: 00448380     4 OBJECT  GLOBAL DEFAULT   23 mapFileNext
   306: 00448210     4 OBJECT  GLOBAL DEFAULT   22 textMenuSample22050
   307: 00448214     4 OBJECT  GLOBAL DEFAULT   22 textMenuFullscreenOn
   308: 00448218     4 OBJECT  GLOBAL DEFAULT   22 textMenuGameplay[...]
   309: 00408a2c   284 FUNC    GLOBAL DEFAULT   10 fgetLine
   310: 004482f8     4 OBJECT  GLOBAL DEFAULT   22 ignoreBoundaries
   311: 0044c2a4    48 OBJECT  GLOBAL DEFAULT   23 inputTest
   312: 004488a8    24 OBJECT  GLOBAL DEFAULT   23 mapSelMenu
   313: 0041fb78   132 FUNC    GLOBAL DEFAULT   10 buildCollisionDa[...]
   314: 004485f0     4 OBJECT  GLOBAL DEFAULT   23 inSplitScreen
   315: 004482d8     4 OBJECT  GLOBAL DEFAULT   22 curMenu
   316: 004297f4    36 FUNC    GLOBAL DEFAULT   10 botReleaseControls
   317: 00448384     4 OBJECT  GLOBAL DEFAULT   23 mapFile
   318: 0044832c     4 OBJECT  GLOBAL DEFAULT   22 sfxThrow
   319: 0044821c     4 OBJECT  GLOBAL DEFAULT   22 textMenuNumOfPlayers2
   320: 004310e8  1656 FUNC    GLOBAL DEFAULT   10 initLib
   321: 004476f4     4 OBJECT  GLOBAL DEFAULT   18 numOfPlayers
   322: 00448220     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign08
   323: 00448330     4 OBJECT  GLOBAL DEFAULT   22 sfxPickup
   324: 004488c0    24 OBJECT  GLOBAL DEFAULT   23 remapMenu
   325: 0041b14c   212 FUNC    GLOBAL DEFAULT   10 centerCameraOnCoords
   326: 00448540     4 OBJECT  GLOBAL DEFAULT   23 newPalette
   327: 004473d0     4 OBJECT  GLOBAL DEFAULT   18 reverbTestDelay
   328: 0042b0c8   264 FUNC    GLOBAL DEFAULT   10 saveCorruptDraw
   329: 004477e0     4 OBJECT  GLOBAL DEFAULT   18 screenWidth
   330: 00448224     4 OBJECT  GLOBAL DEFAULT   22 textMenuAudio
   331: 00426ea0    48 FUNC    GLOBAL DEFAULT   10 cchar_strlen
   332: 00448334     4 OBJECT  GLOBAL DEFAULT   22 sfxKey
   333: 00448228     4 OBJECT  GLOBAL DEFAULT   22 textMenuPressStart
   334: 0042a9c4  1112 FUNC    GLOBAL DEFAULT   10 levelSelectUpdate
   335: 0044822c     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelLevel03
   336: 00413218   224 FUNC    GLOBAL DEFAULT   10 clockToInt
   337: 0044c2d4    16 OBJECT  GLOBAL DEFAULT   23 AreaJumpRight
   338: 00448374     4 OBJECT  GLOBAL DEFAULT   23 fontFat
   339: 00448470     4 OBJECT  GLOBAL DEFAULT   23 transitionOut
   340: 00448104     0 NOTYPE  GLOBAL DEFAULT  ABS __bss_start
   341: 00448230     4 OBJECT  GLOBAL DEFAULT   22 textEditorSetEdi[...]
   342: 004485f4     4 OBJECT  GLOBAL DEFAULT   23 showFps
   343: 0040b3bc  2128 FUNC    GLOBAL DEFAULT   10 loadMobConfig
   344: 00426b58   176 FUNC    GLOBAL DEFAULT   10 particleUpdateAll
   345: 00448234     4 OBJECT  GLOBAL DEFAULT   22 textCheatToggleKey
   346: 00448238     4 OBJECT  GLOBAL DEFAULT   22 textMenuMusicVol2
   347: 00448308     4 OBJECT  GLOBAL DEFAULT   22 screenFlags
   348: 00429328    32 FUNC    GLOBAL DEFAULT   10 listGetCount
   349: 00448984    36 OBJECT  GLOBAL DEFAULT   23 si
   350: 004286c8   264 FUNC    GLOBAL DEFAULT   10 mobManagerGetPlayer
   351: 004257a4    92 FUNC    GLOBAL DEFAULT   10 removeElement
   352: 00448604     8 OBJECT  GLOBAL DEFAULT   23 menuIconIMG
   353: 00448338     4 OBJECT  GLOBAL DEFAULT   22 sfxSquirrel
   354: 00411050    32 FUNC    GLOBAL DEFAULT   10 menuDestroy
   355: 0044823c     4 OBJECT  GLOBAL DEFAULT   22 textMenuGameplay[...]
   356: 0044866c     4 OBJECT  GLOBAL DEFAULT   23 gameWindow
   357: 00448638     4 OBJECT  GLOBAL DEFAULT   23 bgdVideoIMG
   358: 0042576c    56 FUNC    GLOBAL DEFAULT   10 cleanList
   359: 00448240     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign05
   360: 0041f330    20 FUNC    GLOBAL DEFAULT   10 initAnim
   361: 00448244     4 OBJECT  GLOBAL DEFAULT   22 textMenuFullscreenOff
   362: 004482e0     4 OBJECT  GLOBAL DEFAULT   22 newTile
   363: 00448468     4 OBJECT  GLOBAL DEFAULT   23 transitionOutMax
   364: 00448660     4 OBJECT  GLOBAL DEFAULT   23 screenSplitP3
   365: 00448248     4 OBJECT  GLOBAL DEFAULT   22 textEditorBackgr[...]
   366: 0042dc34   276 FUNC    GLOBAL DEFAULT   10 dTextScrollStFont
   367: 00415114    64 FUNC    GLOBAL DEFAULT   10 changeGameModeEx
   368: 0044833c     4 OBJECT  GLOBAL DEFAULT   22 sfxStomp
   369: 004477c8     4 OBJECT  GLOBAL DEFAULT   18 framesPerSecond
   370: 0044824c     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign01
   371: 00405d30     0 NOTYPE  GLOBAL DEFAULT   10 _ftext
   372: 004488d8    24 OBJECT  GLOBAL DEFAULT   23 cheatMenu
   373: 00448250     4 OBJECT  GLOBAL DEFAULT   22 textCheatDebugOff
   374: 00448254     4 OBJECT  GLOBAL DEFAULT   22 textEditorForegr[...]
   375: 0042bc98   112 FUNC    GLOBAL DEFAULT   10 musicManagerLoad
   376: 00448390     4 OBJECT  GLOBAL DEFAULT   23 translationFile
   377: 00447790     4 OBJECT  GLOBAL DEFAULT   18 curPalette
   378: 0044c4c4    56 OBJECT  GLOBAL DEFAULT   23 lifebarClip
   379: 00429350   128 FUNC    GLOBAL DEFAULT   10 getRandomInt
   380: 00448340     4 OBJECT  GLOBAL DEFAULT   22 sfxDamage
   381: 00427738   284 FUNC    GLOBAL DEFAULT   10 st_font_draw_tex[...]
   382: 00412920    24 FUNC    GLOBAL DEFAULT   10 menuSetLevel
   383: 0042927c    76 FUNC    GLOBAL DEFAULT   10 listDeleteFirst
   384: 0040b100   348 FUNC    GLOBAL DEFAULT   10 loadMap
   385: 00448258     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign13
   386: 0042da60   468 FUNC    GLOBAL DEFAULT   10 dKeyPickupMessage
   387: 0042a300   328 FUNC    GLOBAL DEFAULT   10 botPerformAction
   388: 0042ba54    24 FUNC    GLOBAL DEFAULT   10 saveGameGetErrorText
   389: 0042e048   144 FUNC    GLOBAL DEFAULT   10 getPixel
   390: 0041369c  5260 FUNC    GLOBAL DEFAULT   10 editorLogic
   391: 0044825c     4 OBJECT  GLOBAL DEFAULT   22 textIngameLevelC[...]
   392: 00448260     4 OBJECT  GLOBAL DEFAULT   22 textMenuOptions
   393: 004483a0     4 OBJECT  GLOBAL DEFAULT   23 homeDir
   394: 0041fbfc    36 FUNC    GLOBAL DEFAULT   10 colLayerSet
   395: 00448264     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelArena01
   396: 00448268     4 OBJECT  GLOBAL DEFAULT   22 textMenuCaptions[...]
   397: 0044c534     0 NOTYPE  GLOBAL DEFAULT  ABS _end
   398: 004476e8     4 OBJECT  GLOBAL DEFAULT   18 showForeground
   399: 0042842c   176 FUNC    GLOBAL DEFAULT   10 mobManagerDeleteMobs
   400: 00448628     4 OBJECT  GLOBAL DEFAULT   23 bgdEffRainIMG
   401: 0040b25c   352 FUNC    GLOBAL DEFAULT   10 lookupMobConfigID
   402: 00448344     4 OBJECT  GLOBAL DEFAULT   22 musicFile
   403: 0042a450   120 FUNC    GLOBAL DEFAULT   10 scriptLoad
   404: 0044826c     4 OBJECT  GLOBAL DEFAULT   22 textIngameNewRecord
   405: 00448270     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelArena05
   406: 00448274     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelLevel
   407: 004488f0    24 OBJECT  GLOBAL DEFAULT   23 inEditorTileMenu
   408: 00408c28   236 FUNC    GLOBAL DEFAULT   10 getHomeDir
   409: 0044ac50  2952 OBJECT  GLOBAL DEFAULT   23 Player4
   410: 0044c2e4    16 OBJECT  GLOBAL DEFAULT   23 AreaJumpLeft
   411: 00448278     4 OBJECT  GLOBAL DEFAULT   22 textMenuSfxVol3
   412: 00448634     4 OBJECT  GLOBAL DEFAULT   23 bgdAudioIMG
   413: 0042bdf0   448 FUNC    GLOBAL DEFAULT   10 drawPlayerCaption
   414: 004477f0     0 OBJECT  GLOBAL DEFAULT   19 __RLD_MAP
   415: 004485c8     4 OBJECT  GLOBAL DEFAULT   23 mouseLeft
   416: 0044827c     4 OBJECT  GLOBAL DEFAULT   22 textMenuPaletteFaded
   417: 00448280     4 OBJECT  GLOBAL DEFAULT   22 textMenuSample44100
   418: 00448418     4 OBJECT  GLOBAL DEFAULT   23 editorMode
   419: 00448484     4 OBJECT  GLOBAL DEFAULT   23 monkeysSaved
   420: 00448284     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelArena03
   421: 00427904    36 FUNC    GLOBAL DEFAULT   10 st_font_draw_tex[...]
   422: 0042bb88   108 FUNC    GLOBAL DEFAULT   10 timerGetTicks
   423: 00448488     4 OBJECT  GLOBAL DEFAULT   23 doorLocked
   424: 00412494   916 FUNC    GLOBAL DEFAULT   10 menuUpdate
   425: 0042ba84    68 FUNC    GLOBAL DEFAULT   10 startTimer
   426: 004476ec     4 OBJECT  GLOBAL DEFAULT   18 showBackground
   427: 00448288     4 OBJECT  GLOBAL DEFAULT   22 textMenuBotP1On
   428: 0044828c     4 OBJECT  GLOBAL DEFAULT   22 textMenuNumOfPlayers1
   429: 0041b42c   296 FUNC    GLOBAL DEFAULT   10 upscale4
   430: 00448290     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelLevel02
   431: 0042a530   156 FUNC    GLOBAL DEFAULT   10 scriptUpdate
   432: 0041c43c  2264 FUNC    GLOBAL DEFAULT   10 playerDraw
   433: 00448294     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelCustom
   434: 00448654     4 OBJECT  GLOBAL DEFAULT   23 lifebarIMG
   435: 00448414     4 OBJECT  GLOBAL DEFAULT   23 editGroup
   436: 00417474   292 FUNC    GLOBAL DEFAULT   10 logic
   437: 00448298     4 OBJECT  GLOBAL DEFAULT   22 textLevelSelLevel06
   438: 0044829c     4 OBJECT  GLOBAL DEFAULT   22 textMenuCaptionsOff
   439: 0042b2c0   188 FUNC    GLOBAL DEFAULT   10 saveGameGetScore
   440: 00417618    96 FUNC    GLOBAL DEFAULT   10 drawSaving
   441: 00448104     0 NOTYPE  GLOBAL DEFAULT  ABS _edata
   442: 0044c2f4    16 OBJECT  GLOBAL DEFAULT   23 AreaAction
   443: 004484c4     4 OBJECT  GLOBAL DEFAULT   23 platforms
   444: 00414d34   924 FUNC    GLOBAL DEFAULT   10 editorDraw
   445: 0040f61c   408 FUNC    GLOBAL DEFAULT   10 freeMap
   446: 00447700     4 OBJECT  GLOBAL DEFAULT   18 scrollReset
   447: 004482a0     4 OBJECT  GLOBAL DEFAULT   22 textMenuMusicVol3
   448: 00448460     4 OBJECT  GLOBAL DEFAULT   23 transitionOutRunning
   449: 004482a4     4 OBJECT  GLOBAL DEFAULT   22 textIngameRescued
   450: 004482a8     4 OBJECT  GLOBAL DEFAULT   22 textMenuPaletteG[...]
   451: 0042f494   592 FUNC    GLOBAL DEFAULT   10 flip
   452: 004482ac     4 OBJECT  GLOBAL DEFAULT   22 textTutorialSign04
   453: 004482b0     4 OBJECT  GLOBAL DEFAULT   22 textCheatNoclipOff
   454: 00448908    24 OBJECT  GLOBAL DEFAULT   23 gameModeMenu
   455: 00448630     4 OBJECT  GLOBAL DEFAULT   23 bgdCogsIMG
   456: 004482b4     4 OBJECT  GLOBAL DEFAULT   22 textMenuCheats
   457: 004482b8     4 OBJECT  GLOBAL DEFAULT   22 textMenuJoystick
   458: 00448348     4 OBJECT  GLOBAL DEFAULT   22 sfxWin
   459: 004482bc     4 OBJECT  GLOBAL DEFAULT   22 textMenuBotP1Off
   460: 00432094   172 FUNC    GLOBAL DEFAULT   10 playTrack
   461: 0042bad4    96 FUNC    GLOBAL DEFAULT   10 pauseTimer
   462: 004482c0     4 OBJECT  GLOBAL DEFAULT   22 textMenuEditor
   463: 0042e008    64 FUNC    GLOBAL DEFAULT   10 applySurface
   464: 004482c4     4 OBJECT  GLOBAL DEFAULT   22 textMenuShowFpsOn
   465: 00448464     4 OBJECT  GLOBAL DEFAULT   23 transitionInMax
   466: 004477bc     4 OBJECT  GLOBAL DEFAULT   18 enableMusic
   467: 00428370   188 FUNC    GLOBAL DEFAULT   10 mobManagerLoadMobs
   468: 00448664     4 OBJECT  GLOBAL DEFAULT   23 screenSplitP2
   469: 00408d14  3176 FUNC    GLOBAL DEFAULT   10 loadConfig
   470: 004482c8     4 OBJECT  GLOBAL DEFAULT   22 textCheatDebugOn
   471: 004482cc     4 OBJECT  GLOBAL DEFAULT   22 textIngameLocked
   472: 0044845c     4 OBJECT  GLOBAL DEFAULT   23 newHiscore
   473: 00405d30  4184 FUNC    GLOBAL DEFAULT   10 main
   474: 0042bfb0  1828 FUNC    GLOBAL DEFAULT   10 dBackgroundEffect
   475: 004483e0     4 OBJECT  GLOBAL DEFAULT   23 isTutorial
   476: 00405cb8    28 FUNC    GLOBAL DEFAULT    9 _init
   477: 004485fc     4 OBJECT  GLOBAL DEFAULT   23 fakeScreenHeight
   478: 00448370     4 OBJECT  GLOBAL DEFAULT   23 fontThin
   479: 0041fcf4   264 FUNC    GLOBAL DEFAULT   10 checkSignCollision
   480: 00432de0     0 FUNC    GLOBAL DEFAULT  UND strcpy
   481: 00432dd0     0 FUNC    GLOBAL DEFAULT  UND SDL_WarpMouse
   482: 00432dc0     0 FUNC    GLOBAL DEFAULT  UND puts
   483: 00432db0     0 FUNC    GLOBAL DEFAULT  UND printf
   484: 00432da0     0 FUNC    GLOBAL DEFAULT  UND srand
   485: 00432d90     0 FUNC    GLOBAL DEFAULT  UND Mix_HookMusic
   486: 00432d80     0 FUNC    GLOBAL DEFAULT  UND strchr
   487: 00432d70     0 FUNC    GLOBAL DEFAULT  UND SDL_GetError
   488: 00432d60     0 FUNC    GLOBAL DEFAULT  UND SDL_JoystickClose
   489: 00432d50     0 FUNC    GLOBAL DEFAULT  UND readdir
   490: 00432d40     0 FUNC    GLOBAL DEFAULT  UND SDL_JoystickNumHats
   491: 00432d30     0 FUNC    GLOBAL DEFAULT  UND atoi
   492: 00432d20     0 FUNC    GLOBAL DEFAULT  UND free
   493: 00432d10     0 FUNC    GLOBAL DEFAULT  UND ftell
   494: 00432d00     0 FUNC    GLOBAL DEFAULT  UND strcmp
   495: 00432cf0     0 FUNC    GLOBAL DEFAULT  UND SDL_Quit
   496: 00432ce0     0 FUNC    GLOBAL DEFAULT  UND SDL_Flip
   497: 00432cd0     0 FUNC    GLOBAL DEFAULT  UND SDL_Delay
   498: 00432cc0     0 FUNC    GLOBAL DEFAULT  UND exit
   499: 00432cb0     0 FUNC    GLOBAL DEFAULT  UND Mix_HaltMusic
   500: 00432ca0     0 FUNC    GLOBAL DEFAULT  UND SDL_LoadBMP_RW
   501: 00432c90     0 FUNC    GLOBAL DEFAULT  UND rand
   502: 00432c80     0 FUNC    GLOBAL DEFAULT  UND Mix_PlayChannelTimed
   503: 00432c70     0 FUNC    GLOBAL DEFAULT  UND fseek
   504: 00432c60     0 FUNC    GLOBAL DEFAULT  UND SDL_DisplayFormat
   505: 00432c50     0 FUNC    GLOBAL DEFAULT  UND sprintf
   506: 00432c40     0 FUNC    GLOBAL DEFAULT  UND fprintf
   507: 00432c30     0 FUNC    GLOBAL DEFAULT  UND SDL_GetMouseState
   508: 00432c20     0 FUNC    GLOBAL DEFAULT  UND floorf
   509: 00432c10     0 FUNC    GLOBAL DEFAULT  UND memset
   510: 00000000     0 OBJECT  GLOBAL DEFAULT  UND __ctype_b
   511: 00432c00     0 FUNC    GLOBAL DEFAULT  UND Mix_CloseAudio
   512: 00432bf0     0 FUNC    GLOBAL DEFAULT  UND SDL_CreateRGBSurface
   513: 00432be0     0 FUNC    GLOBAL DEFAULT  UND atof
   514: 00432bd0     0 FUNC    GLOBAL DEFAULT  UND Mix_Volume
   515: 00432bc0     0 FUNC    GLOBAL DEFAULT  UND ModPlug_SetSettings
   516: 00432bb0     0 FUNC    GLOBAL DEFAULT  UND strncpy
   517: 00432ba0     0 FUNC    GLOBAL DEFAULT  UND ModPlug_GetSettings
   518: 00432b90     0 FUNC    GLOBAL DEFAULT  UND fputc
   519: 00432b80     0 FUNC    GLOBAL DEFAULT  UND closedir
   520: 00000000     0 OBJECT  GLOBAL DEFAULT  UND stderr
   521: 00432b70     0 FUNC    GLOBAL DEFAULT  UND fgetc
   522: 00432b60     0 FUNC    GLOBAL DEFAULT  UND time
   523: 00432b50     0 FUNC    GLOBAL DEFAULT  UND fopen
   524: 00432b40     0 FUNC    GLOBAL DEFAULT  UND Mix_FreeChunk
   525: 00432b30     0 FUNC    GLOBAL DEFAULT  UND ModPlug_SetMaste[...]
   526: 00432b20     0 FUNC    GLOBAL DEFAULT  UND fread
   527: 00432b10     0 FUNC    GLOBAL DEFAULT  UND fclose
   528: 00432b00     0 FUNC    GLOBAL DEFAULT  UND SDL_Init
   529: 00432af0     0 FUNC    GLOBAL DEFAULT  UND SDL_UpperBlit
   530: 00432ae0     0 FUNC    GLOBAL DEFAULT  UND __fgetc_unlocked
   531: 00000000     0 OBJECT  GLOBAL DEFAULT  UND stdout
   532: 00432ad0     0 FUNC    GLOBAL DEFAULT  UND SDL_MapRGB
   533: 00432ac0     0 FUNC    GLOBAL DEFAULT  UND ModPlug_Read
   534: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMC[...]
   535: 00432ab0     0 FUNC    GLOBAL DEFAULT  UND SDL_JoystickNumB[...]
   536: 00000000     0 OBJECT  GLOBAL DEFAULT  UND __ctype_toupper
   537: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterT[...]
   538: 00432aa0     0 FUNC    GLOBAL DEFAULT  UND strtol
   539: 00432a90     0 FUNC    GLOBAL DEFAULT  UND SDL_NumJoysticks
   540: 00432a80     0 FUNC    GLOBAL DEFAULT  UND SDL_SetVideoMode
   541: 00432a70     0 FUNC    GLOBAL DEFAULT  UND SDL_JoystickEven[...]
   542: 00432a60     0 FUNC    GLOBAL DEFAULT  UND opendir
   543: 00432a50     0 FUNC    GLOBAL DEFAULT  UND strlen
   544: 00432a40     0 FUNC    GLOBAL DEFAULT  UND SDL_FillRect
   545: 00432a30     0 FUNC    GLOBAL DEFAULT  UND SDL_SetColorKey
   546: 00432a20     0 FUNC    GLOBAL DEFAULT  UND __uClibc_main
   547: 00432a10     0 FUNC    GLOBAL DEFAULT  UND SDL_LockSurface
   548: 00432a00     0 FUNC    GLOBAL DEFAULT  UND ModPlug_Seek
   549: 004329f0     0 FUNC    GLOBAL DEFAULT  UND SDL_JoystickNumAxes
   550: 004329e0     0 FUNC    GLOBAL DEFAULT  UND strncmp
   551: 004329d0     0 FUNC    GLOBAL DEFAULT  UND strrchr
   552: 004329c0     0 FUNC    GLOBAL DEFAULT  UND SDL_PollEvent
   553: 004329b0     0 FUNC    GLOBAL DEFAULT  UND malloc
   554: 004329a0     0 FUNC    GLOBAL DEFAULT  UND mkdir
   555: 00432990     0 FUNC    GLOBAL DEFAULT  UND SDL_UnlockSurface
   556: 00432980     0 FUNC    GLOBAL DEFAULT  UND SDL_GetTicks
   557: 00432970     0 FUNC    GLOBAL DEFAULT  UND strcasecmp
   558: 00000000     0 FUNC    WEAK   DEFAULT  UND __[...]@GLIBC_2.0 (2)
   559: 00432960     0 FUNC    GLOBAL DEFAULT  UND SDL_RWFromFile
   560: 00432950     0 FUNC    GLOBAL DEFAULT  UND Mix_LoadWAV_RW
   561: 00432940     0 FUNC    GLOBAL DEFAULT  UND strcat
   562: 00432930     0 FUNC    GLOBAL DEFAULT  UND ModPlug_Unload
   563: 00432920     0 FUNC    GLOBAL DEFAULT  UND SDL_ShowCursor
   564: 00432910     0 FUNC    GLOBAL DEFAULT  UND putchar
   565: 00432900     0 FUNC    GLOBAL DEFAULT  UND realloc
   566: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _Jv_RegisterClasses
   567: 004328f0     0 FUNC    GLOBAL DEFAULT  UND SDL_MapRGBA
   568: 004328e0     0 FUNC    GLOBAL DEFAULT  UND SDL_WM_SetCaption
   569: 004328d0     0 FUNC    GLOBAL DEFAULT  UND stpcpy
   570: 004328c0     0 FUNC    GLOBAL DEFAULT  UND SDL_JoystickName
   571: 004328b0     0 FUNC    GLOBAL DEFAULT  UND memcpy
   572: 004328a0     0 FUNC    GLOBAL DEFAULT  UND ModPlug_Load
   573: 00432890     0 FUNC    GLOBAL DEFAULT  UND fwrite
   574: 00432880     0 FUNC    GLOBAL DEFAULT  UND getenv
   575: 00432870     0 FUNC    GLOBAL DEFAULT  UND ModPlug_SeekOrder
   576: 00432860     0 FUNC    GLOBAL DEFAULT  UND __errno_location
   577: 00432850     0 FUNC    GLOBAL DEFAULT  UND Mix_OpenAudio
   578: 00432840     0 FUNC    GLOBAL DEFAULT  UND rewind
   579: 00000000     0 FUNC    WEAK   DEFAULT  UND __[...]@GLIBC_2.0 (2)
   580: 00432830     0 FUNC    GLOBAL DEFAULT  UND SDL_JoystickOpen
   581: 00432820     0 FUNC    GLOBAL DEFAULT  UND SDL_FreeSurface