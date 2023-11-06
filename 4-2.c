#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fun_scan();

int arr_add_1(int n);

int arr_add_2(int n);

int arr_add_choice(int n);

int fun_replaceElement(int arr_int[], int n);

int fun_replaceEven(int arr_int[], int n);

int fun_new_arr(int arr_int[], int n);

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
  arr_int[n - 1] = fun_replaceElement(arr_int, n);
  fun_replaceEven(arr_int, n);
  fun_new_arr(arr_int, n);
  return 0;
}

int arr_add_2(int n) {
  int arr_int[n];
  for (int i = 0; i < n; i++) {
    arr_int[i] = fun_scan();
  }
  arr_int[n - 1] = fun_replaceElement(arr_int, n);
  fun_replaceEven(arr_int, n);
  fun_new_arr(arr_int, n);
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
  for (int i = 0; i < n; i++) {
    if (abs(arr_int[i]) > temp) {
      temp = arr_int[i];
    }
  }
  arr_int[n - 1] = temp;
  printf("%s - %d\n", "1. Предпоследнее число из массива", temp);
  return temp;
}

int fun_replaceEven(int arr_int[], int n) {
  int number;
  printf("%s\n", "Введите число, которое должно стоять после всех четных "
                 "оканчивающихся на ноль");
  number = fun_scan();
  printf("%s\n", "Task2");
  for (int i = 0; i < n; i++) {
    if (arr_int[i] % 10 == 0) {
      printf("%d\t", arr_int[i]);
      printf("%d\t", number);
    } else {
      printf("%d\t", arr_int[i]);
    }
  }
  return 0;
}

int fun_new_arr(int arr_int[], int n) {
  printf("\n%s\n", "Task3");
  int temp = 0, arr_new[n];
  for (int i = 0; i < n; i++) {
    if (i == 0 || i == n - 1) {
      printf("%d\t", 0);
    } else {
      temp = arr_int[i] * pow(i, 2);
      printf("%d\t", temp);
    }
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
