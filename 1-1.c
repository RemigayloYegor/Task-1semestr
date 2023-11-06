#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Функция расчета формулы
 * @param x,y,z значения параметров
 * @return значение вычеслений
 */
double FunctionA(double x, double y, double z);
/**
 * @brief Функция расчета формулы
 * @param x,y,z значения параметров
 * @return значение вычеслений
 */
double FunctionB(double x, double y, double z);

int main() {
  double x = 0.29, y = 3.7, z = -1;
  printf("x = %4.2f\n y = %4.2f\n z = %4.2f\n", x, y, z);
  printf("a = %f\n b = %f\n", FunctionA(x, y, z), FunctionB(x, y, z));
}

double FunctionA(double x, double y, double z) {
  return 3 * pow(x, y) * log10(y) + exp(z * x);
}

double FunctionB(double x, double y, double z) {
  return fabs(2 * y * z) / pow(sin(x), 2) - pow(x, 2) / 3;
}
