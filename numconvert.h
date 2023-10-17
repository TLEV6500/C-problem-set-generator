#include <stdio.h>
#include <math.h>
#define DEC 10
#define BIN 2
#define OCT 8
#define HEX 16

int extractdigit(double x, int d, int b);
double getlesserdigits(double x, int d, int b);
int todecint(int x, int b);
double todecimal(double x, int b);


int todecint(int x, int b) {
  if (b == 10) return x;
  if (b <= 0) return 0;
  
  
  return x;
}

int extractdigit(double x, int d, int b) {
  double digit;
  digit = (getlesserdigits(x,d+1,b) - getlesserdigits(x,d,b))/pow(b, d);
  printf("(%f - %f)/(%f)\n", getlesserdigits(x,d+1,b), getlesserdigits(x,d,b), pow(b, d));
  return (int)digit;
}

double getlesserdigits(double x, int d, int b) {
  return remainder(x, pow(b, d));
}