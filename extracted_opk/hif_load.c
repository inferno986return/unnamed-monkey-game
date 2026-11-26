
int hif_load(char *param_1)

{
  FILE *__stream;
  size_t __size;
  char *__ptr;
  size_t sVar1;
  int iVar2;
  
  __stream = fopen(param_1,"rb");
  if (__stream == (FILE *)0x0) {
    return 0;
  }
  fseek(__stream,0,2);
  __size = ftell(__stream);
  fseek(__stream,0,0);
  __ptr = malloc(__size);
  if (__ptr != (char *)0x0) {
    sVar1 = fread(__ptr,1,__size,__stream);
    if (__size == sVar1) {
      fclose(__stream);
      iVar2 = FUN_00427f48(__ptr);
      free(__ptr);
      return iVar2;
    }
    free(__ptr);
  }
  fclose(__stream);
  return 0;
}

