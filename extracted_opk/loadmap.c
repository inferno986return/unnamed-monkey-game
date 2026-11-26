
bool loadMap(char *param_1)

{
  bool bVar1;
  char *pcVar2;
  size_t __n;
  size_t sVar3;
  char cVar4;
  char local_28 [20];
  
  cVar4 = *param_1;
  if (cVar4 != '\0') {
    pcVar2 = param_1;
    do {
      if (cVar4 == '\\') {
        *pcVar2 = '/';
      }
      pcVar2 = pcVar2 + 1;
      cVar4 = *pcVar2;
    } while (cVar4 != '\0');
  }
  pcVar2 = strchr(param_1,0x2f);
  if (pcVar2 == (char *)0x0) {
    builtin_strncpy(local_28 + 8,"aps/",5);
    builtin_strncpy(local_28,"./data/m",8);
    __n = strlen(local_28);
    sVar3 = strlen(param_1);
    pcVar2 = malloc(__n + sVar3 + 1);
    memcpy(pcVar2,local_28,__n);
    strcpy(pcVar2 + __n,param_1);
    bVar1 = FUN_00409eb8(pcVar2);
    free(pcVar2);
    return bVar1;
  }
  bVar1 = FUN_00409eb8(param_1);
  return bVar1;
}

