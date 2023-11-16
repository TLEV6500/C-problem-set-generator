#include <stdio.h>

#ifndef TYPES_H_
#include "types.h"
#endif

#ifndef TYPEDIO_H_
#define TYPEDIO_H_

void scan_num(void *num, char *type);
void print_num(void *num, char *type);

void scan_num(void *num, char *type)
{
  switch (get_type_code(type))
  {
  case INT:
    scanf(" %d", (int *)num);
    break;
  case FLOAT:
    scanf(" %f", (float *)num);
    break;
  }

  
  // #if DEBUG == 1
  //   printf("\nscan_num(*num=%lf, type=%s)", *(double*)num, type);
  // #endif
}

void print_num(void *num, char *type)
{
  switch (get_type_code(type))
  {
  case INT:
    printf("%d", *(int *)num);
    break;
  case FLOAT:
    printf("%f", *(float *)num);
    break;
  }

  // #if DEBUG == 1
  //   printf("\nprint_num(*num=%lf, type=%s)", *(double*)num, type);
  // #endif
}

#endif