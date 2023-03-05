#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this function will take the comparisons and hail the results from Linker into configs

// could make a file too called minus prefixes to be simply added to suffix one

int main(void)
{
  FILE *inp;
  FILE *opt;
  FILE *ref;
  FILE *preRead;
  FILE *rlen;
  inp = fopen("LINKER.txt", "r");
  opt = fopen("CONTIG.txt", "w");
  ref = fopen("READ.txt", "r");
  preRead = fopen("LINKPRE.txt", "r");

  // this is for the lengths of some of the guys
  rlent = fopen("readLen.txt", "w");
  
  int startInt;
  int endInt;
  long s;
  long e;
  char *rtp;
  int k = 1;
  unsigned int lenK = 40;
  
  while (!feof(inp))
  {
    fscanf(inp, "%i %i\n", &startInt, &endInt);
    // once for the startRead
    for (int i = 0; i < startInt; i++)
    {
      fscanf(preRead, "%*[^\n]\n");
    }
    s = ftell(preRead);
    fscanf(preRead, "%*[^&]");
    e = ftell(preRead);
    fseek(preRead, s, SEEK_SET);
    rtp = malloc(sizeof(char) * (e - s));
    fread(rtp, sizeof(char), e-s, preRead); 
    printf(">contig%i\n", k);
    printf("%s", rtp);
    free(rtp);
    rewind(preRead);
    
    // once for the endRead
    
    for (int i = 0; i < endInt; i++)
    {
      fscanf(ref, "%*[^\n]\n");
    }
    s = ftell(ref);
    fscanf(ref, "%*[^\n]");
    e = ftell(ref);
    fseek(ref, s, SEEK_SET);
    rtp = malloc(sizeof(char) * (e - s + 1));
    fread(rtp, sizeof(char), e-s - 1, ref); 
    printf("%s\n", rtp);
    free(rtp);
    rewind(ref);
    k++;
  }
  
  fclose(inp);
  fclose(opt);
  fclose(ref);
  fclose(rlent);
  fclose(preRead);
}
