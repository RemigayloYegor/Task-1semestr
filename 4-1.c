#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Функция расчета формулы
 * @param x,y,z значения параметров
 * @return значение вычеслений
 */
int fun_scan();

int arr_add_1(int n);

int arr_add_2(int n);

int arr_add_choice(int n);

int fun_replaceElement(int arr_int[], int n);

int fun_quantity(int arr_int[], int n);

int fun_findNumber(int arr_int[], int n);

int main() {
  srand(time(NULL));
  int n, arr_int[n];
  printf("%s\n", "Введите количество символов. ");
  n = fun_scan();
  arr_int[n] = arr_add_choice(n);
  return 0;
}

int arr_add_1(int n) {
  int arr_int[n];
  for (int i = 0; i < n; i++) {
    arr_int[i] = -30 + rand() % 101;
  }
  fun_replaceElement(arr_int, n);
  fun_quantity(arr_int, n);
  fun_findNumber(arr_int, n);
  return 0;
}

int arr_add_2(int n) {
  int arr_int[n];
  for (int i = 0; i < n; i++) {
    arr_int[i] = fun_scan();
  }
  fun_replaceElement(arr_int, n);
  fun_quantity(arr_int, n);
  fun_findNumber(arr_int, n);
  return 0;
}

int arr_add_choice(int n) {
  int choice;
  printf(
      "%s\n",
      "Заполнение массива автоматически - 1. Заполнение массива вручную - 2. ");
  choice = fun_scan();
  if (choice == 1) {
    return arr_add_1(n);
  } else if (choice == 2) {
    return arr_add_2(n);
  } else {
    abort();
  }
}

int fun_replaceElement(int arr_int[], int n) {
  int temp = 0;
  for (int i = 0; i < n; i = i + 1) {
    if (abs(arr_int[i]) > temp) {
      temp = arr_int[i];
    }
  }
  arr_int[n - 1] = temp;
  printf("%s - %d\n", "1. Предпоследнее число из массива", temp);
  return 0;
}

int fun_quantity(int arr_int[], int n) {
  printf("%s\n", "Введите число на которое должно делится без остатка");
  int number, temp = 0;
  number = fun_scan();
  for (int i = 0; i < n; i = i + 1) {
    if (arr_int[i] % number == 0) {
      temp += 1;
    }
  }
  printf("%s %d - %d\n", "2. Кол-во элементов которые делятся на", number,
         temp);
  return 0;
}

int fun_findNumber(int arr_int[], int n) {
  int temp = 0;
  for (int i = 0; i < n; i = i + 1) {
    if (arr_int[i] >= 0 && arr_int[i + 1] < 0 ||
        arr_int[i] > 0 && arr_int[i + 1] <= 0) {
      temp = 1;
      printf("%s - %d\n",
             "3. Номер первой пары соседних элементов с разными знаками", i);
      break;
    }
  }
  if (temp == 0) {
    printf("%s", "Число не найдено");
  }
  return 0;
}

int fun_scan() {
  int a;
  int ret;
  a = scanf("%d", &ret);
  if (a != 1) {
    abort();
  }
  return ret;
}
