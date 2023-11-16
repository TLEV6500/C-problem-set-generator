#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifndef TYPES_H_
#include "types.h"
#endif

#ifndef NUMGEN_H_
#define NUMGEN_H_

void *rand_num(char *type, void *min, void *max);
int *rand_int(int min, int max);
float *rand_float(float min, float max);

void seed_rand(){
  srand(time(0));
}

void *rand_num(char *type, void *min, void *max)
{
  int raw_rand = rand();

  #if DEBUG == 1
    printf("\ncode=%d, type=%s", get_type_code(type), type);
  #endif

  switch (get_type_code(type))
  {
  case INT: return (void *)rand_int(*(int*)min, *(int*)max);
  case FLOAT: return (void *)rand_float(*(float*)min, *(float*)max);
  }

  #if DEBUG == 1
    printf("\nWent passed expected switch cases.\n");
  #endif
  return NULL;
}

int *rand_int(int min, int max) {
  int *randnum = (int*)malloc(sizeof(int));
  *randnum = (rand()*rand()) % (max - min) + min;

  #if DEBUG == 1
  printf("\nrand_int(min=%d, max=%d){*randnum=%d}\n", min, max, *randnum);
  #endif

  return (void *)randnum;
}

float *rand_float(float min, float max) {
  float* randnum = (float*)malloc(sizeof(float));
  *randnum = fmodf(((float)rand()*(float)rand())/rand(), (max - min)) + min;

  #if DEBUG == 1
  printf("\nrand_float(min=%f, max=%f){*randnum=%f}\n", min, max, *randnum);
  #endif

  return (void *)randnum;
}

#endif