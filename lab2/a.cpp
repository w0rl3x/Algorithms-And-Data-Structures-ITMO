#include <iostream>

void insertsort(int arr[], int len) {
  // идем с со второго элемента массива (A[1])
  for (int j = 1; j < len; j++) {
    int key = arr[j]; // записываю в кей элемент массива
    int i = j - 1; // идем с предыдущего элемента массива
    while (i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i]; // сдвигаю вправа
      i = i - 1; // переход к предыдущему
    }
    arr[i + 1] = key; // вставляю в нужное место после всех сдвигов
  }
}

int main() {
  int count = 0;
  std::cin >> count;
  int arr[count];

  for (int i = 0; i < count; i++) {
    std::cin >> arr[i];
  }

  insertsort(arr, count);

  for (int i = 0; i < count; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}