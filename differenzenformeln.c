#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define ZAHLENTYP float
// #define ZAHLENTYP double

ZAHLENTYP f(ZAHLENTYP x) {
  ZAHLENTYP val = 0.0;
  val = cos(x);
  return val;
  //#  return
}

ZAHLENTYP df(ZAHLENTYP x) {
  ZAHLENTYP val = 0.0;
  val = -(sin(x));
  return val;
}

ZAHLENTYP Dplus(ZAHLENTYP x0, ZAHLENTYP h) {
  ZAHLENTYP val = 0.0;
  val = (f(x0 + h) - f(x0)) / h;
  return val;
}

ZAHLENTYP Dminus(ZAHLENTYP x0, ZAHLENTYP h) {
  ZAHLENTYP val = 0.0;
  val = (f(x0) - f(x0 - h)) / h;
  return val;
}

ZAHLENTYP Dzentral(ZAHLENTYP x0, ZAHLENTYP h) {
  ZAHLENTYP val = 0.0;
  val = 0.5 * ((f(x0 + h) - f(x0 - h)) / h);
  return val;
}

int main() {
  ZAHLENTYP x0 = 1.0;
  ZAHLENTYP h = 1e-1;

  // TODO Ausgabe des Fehlers von D+,D- und D für unterschiedliche h
  printf("       h\tFehler D+\tFehler D-\tFehler D\n");
  for (int i = 0; i < 10; i++) {
    h = h / 10;
    printf("        %.1e\t%.16f      \t %.16f     \t%.16f\n", h,
           (Dplus(x0, h) - df(x0)), (Dminus(x0, h) - df(x0)),
           (Dzentral(x0, h) - df(x0)));
  }

  /* TIPP:
   * Für die Ausgabe der Nachkommastellen nutzen Sie die
   * Formatierungsmöglichkeiten von printf für den ZAHLENTYP Der Datentyp
   * float hat 7 Nachkommastellen und double 16 Beispiel: float
   * var1=3.1415926; printf("%.7f\n",var1);  // gibt 7 Nachkommastellen aus
   *  double var2=3.14159265358979323846
   *  printf("%.16lf\n",var1); // gibt 16 Nachkommastellen aus
   */

  return 0;
}
