#include <iostream>

// реализация квиксорт в убывающем порядке
void quicksort(int a[], int l, int r) {
  if (l >= r) {
    return;
  }
  int pivot = a[l + (r - l) / 2];
  int i = l, j = r;

  while (i <= j) {
    while (a[i] > pivot) {
      i++;
    }
    while (a[j] < pivot) {
      j--;
    }

    if (i <= j) {
      std::swap(a[i], a[j]);
      i++;
      j--;
    }
  }

  if (l < j) {
    quicksort(a, l, j);
  }
  if (i < r) {
    quicksort(a, i, r);
  }
}

int main() {
  int x; //колво веток
  std::cin >> x;

  int branchLengths[x]; // длины веток
  for (int i = 0; i < x; i++) {
    std::cin >> branchLengths[i];
  }

  quicksort(branchLengths, 0, x - 1);

  __int64_t s = 0; //площадь
  __int64_t rebro1, rebro2 = 0; //стороны

  for (int i = 0; i < x - 1; i++) {
    //чек на равность соседних веток или на отличие в единицу
    if (branchLengths[i] == branchLengths[i + 1] ||
        branchLengths[i] - 1 == branchLengths[i + 1]) {
      // создаем ребро х если только начали/после сброса
      if (rebro1 == 0) {
        rebro1 += branchLengths[i + 1];
      } else { // создаем ребро у и считаем площадь
        rebro2 = branchLengths[i + 1];
        s += rebro1 * rebro2;
        rebro1 = 0; //сброс для некст пары
      }
      i++; //переход к некст паре
    }
  }

  std::cout << s << "\n";
  return 0;
}