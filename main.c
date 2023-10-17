#include <stdio.h>
#include "numconvert.h"

int main() {
  // Testing extractdigit()
  double num;
  int digit, base, result;
  int repeat;
  do {
  repeat = 0;
  printf("extractdigit(x,d,b) << ");
  scanf("%lf %d %d", &num, &digit, &base);
  result = extractdigit(num, digit, base);
  printf("\nDigit #%d of %g is >> %d", digit, num, result);
  printf("\n\nContinue? (0-NO, 1-YES): ");
  scanf("%d", &repeat);
  } while (repeat);
  // Testing extractdigit()

  return 0;
}