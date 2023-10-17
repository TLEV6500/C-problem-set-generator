#include <math.h>
#define DEC 10
#define BIN 2
#define OCT 8
#define HEX 16

int extractdigit(double x, int d, int b);
int extractFracPart(double f, int d, int b);
int todecint(int x, int b);
double todecimal(double x, int b);


int todecint(int x, int b) {
  if (b == 10) return x;
  if (b <= 0) return 0;
  
  
  return x;
}

int extractdigit(double x, int d, int b) {
  int digit;
  if (d >= 0) {
    digit = ((int)x % (int)(pow(b, d+1) + 1e-9) - (int)x % (int)(pow(b, d) + 1e-9));
  } else {
    digit = extractFracPart(x, d, b);
  }
  return digit;
}

int extractFracPart(double f, int d, int b) {
  int digit = f/pow((double)b,d);
  digit -= (int)((int)f/pow((double)b,d));
  digit -= (d < 0) ? extractFracPart(f,d+1,b)*b : 0;
  return digit;
}