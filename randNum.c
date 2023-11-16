#define DEBUG 0

#include <stdio.h>
#include <stdlib.h>

#ifndef NUMGEN_H_
#include "numgen.h"
#endif
#ifndef TYPES_H_
#include "types.h"
#endif
#ifndef TYPEDIO_H_
#include "typedio.h"
#endif

int main() {
  seed_rand();
  int repeat = 0;
  char in_type[25];
  void *min;
  void *max;

  do {
    if (repeat != 1) {
      fflush(stdin);
      printf("randNum(type, min, max)");
      printf("\ntype: ");
      fgets(in_type, sizeof(in_type)/sizeof(*in_type), stdin);
      in_type[strcspn(in_type,"\n")] = 0;

      size_t size = type_size[get_type_code(in_type)];
      min = malloc(size);
      max = malloc(size);

      printf("min: ");
      scan_num(min, in_type);

      printf("max: ");
      scan_num(max, in_type);
    }

    void* random = rand_num(in_type, min, max);
    printf("\nRandom %s number: ", in_type);
    print_num(random, in_type);
    free(random);

    printf("\nGenerate more random numbers?\n[0-no, 1-(use same range), 2-(new range)]\n>> ");
    scanf("%d", &repeat);

    if (repeat != 1) {
      free(min);
      free(max);
    }
  } while (repeat);

  return 0;
}