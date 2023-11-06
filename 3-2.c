#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Функция расчета формулы
 * @param x,y,z значения параметров
 * @return значение вычеслений
 */
int fun_scan();

float fun_summa(int kol);

float fun_summa_limit(int kol, int limit);

int factorial(int k);

int main() {
  int quantity, limit;
  quantity = fun_scan();
  limit = fun_scan();
  printf("%f\n", fun_summa(quantity));
  printf("%f\n", fun_summa_limit(quantity, limit));
  return 0;
}

float fun_summa(int quantity) {
  float summa;
  for (int i = 1; i <= quantity; i++) {
    summa +=
        pow(-1, factorial(i)) * (i / (pow(factorial(i), 2) + factorial(i + 1)));
  }
  return summa;
}

float fun_summa_limit(int quantity, int limit) {
  float summa;
  for (int i = limit; i <= quantity; i++) {
    summa +=
        pow(-1, factorial(i)) * (i / (pow(factorial(i), 2) + factorial(i + 1)));
  }
  return summa;
}

int factorial(int k) {
  int result = 1;
  for (int i = 1; i <= k; i++)
    result = result * i;
  return result;
}

int fun_scan() {
  int a;
  int b;
  a = scanf("%d", &b);
  if (a != 1) {
    abort();
  } else {
    return b;
  }
}
