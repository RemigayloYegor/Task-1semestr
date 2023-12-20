#include <stdio.h>
#include <float.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Функция присваивает целочисленное значение переменной
 * @param - сообщение для пользователя
 * @return целочисленная цифра
*/
int scan_f(const char* const message);
/**
* @brief Функция расчитывающая сумму членов последовательности.
* @param length - количество членов последовательности.
* @return cумма последовательности.
*/
double Suma(int length);
/**
* @brief Функция расчитывающая сумму членов последовательностиначиная с begin.
* @param length - количество членов последовательности.
* @param begin - начальный член последовательности.
* @return cумма последовательности.
*/
double SumaBegin(int begin, int length);
/**
* @brief Функция расчитывающая рекурентный член последовательности.
* @param number - номер члена последовательности.
* @return Значение рекурентного члена последовательности.
*/
double recurent(int number);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
  int length = scan_f("Введите длину последовательности: ");
  printf("Сумма до %d равна %lf \n", length, Suma(length));
  int begin = scan_f("Введите число от которого начнем считать: ");
  printf("Сумма с %d до %d = %lf \n", begin, length, SumaBegin(begin, length));
  return 0;
}

int scan_f(const char* const message)
{
  int length;
  printf("%s", message);
  int result = scanf("%d", &length);
  if (result != 1 || length < 1)
  {
    errno = EIO;
    perror("Error :");
    abort();
  }
  return length;
}

double Suma(int length)
{
  double current = 1;
  double result = 0;
  for(int k = 0; k < length; k++)
  {
      current *= recurent(k);
      result += current;
  }
  return result;
}

double SumaBegin(int begin, int length)
{
  double current = 1;
  double result = 0;
  int k = begin;
  while(length - k >= -DBL_EPSILON)
  {
      current *= recurent(k);
      result += current;
      k++;
  }
  return result;
}
double recurent(int number)
{
  return 1.0 / (4 * pow(number, 2) + 6 * number + 2);
}
