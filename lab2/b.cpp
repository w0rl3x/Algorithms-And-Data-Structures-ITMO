#include <cstdlib>
#include <iostream>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void quicksort(int a[], int l, int r) {
  // ексепшн кейс когда границы равны или пересекаются
  if (l >= r) {
    return;
  }

  int i = l;  // индекс левой границы
  int j = r;  // индекс правой границы
  int mid = a[rand() % (r - l + 1) + l];  // рандомный пивот из диапазона [l, r]

  // разделяй и властвуй Ж)
  while (i <= j) {
    // индекс вправо
    while (a[i] < mid) {
      i++;
    }
    // индекс влево
    while (a[j] > mid) {
      j--;
    }
    // меняем местами если индексы не пересекаются
    if (i <= j) {
      swap(a[i], a[j]);
      i++;  // вправо
      j--;  // влево
    }
  }

  // рекурсивный вызов квиксорта для левой части
  if (l < j) {
    quicksort(a, l, j);
  }
  // рекурсивный вызов квиксорта для правой части
  if (r > i) {
    quicksort(a, i, r);
  }
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  quicksort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  return 0;
}
