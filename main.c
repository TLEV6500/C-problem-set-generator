#include <stdio.h>
#include "libraries\numconvert.h"

int main() {
  // Testing extractdigit()
  double num;
  int digit, base, result;
  printf("extractdigit(x,d,b) << ");
  scanf("%lf %d %d", &num, &digit, &base);
  result = extractdigit(num, digit, base);
  printf("\nDigit #%d of %g is >> %d", digit, num, result);
  // Testing extractdigit()

  return 0;
}