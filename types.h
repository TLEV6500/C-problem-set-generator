#include <string.h>

#ifndef TYPES_H_
#define TYPES_H_

typedef enum types {VOID = 0, INT, FLOAT} types;

types get_type_code(char *type);

union _var
{
  int i;
  float f;
} var;

size_t type_size[] = {0, sizeof(int), sizeof(float)};

types get_type_code(char *type)
{
  if (!strcmp(type, "int"))
    return INT;
  else if (!strcmp(type, "float"))
    return FLOAT;
  return VOID;
}

#endif