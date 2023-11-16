#include <stdio.h>
#include "types.h"
#include "typedio.h"

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
}

void print_num(void *num, char *type)
{
  switch (get_type_code(type))
  {
  case INT:
    printf("%d", (int *)num);
    break;
  case FLOAT:
    printf("%f", (float *)num);
    break;
  }
}