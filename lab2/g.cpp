#include <iostream>
using namespace std;

// переписанный квиксорт для сортировки интересующих элементов, игнорируя неотсорттрованные и менее важные части массива
// таким образом и находим к максимальных стоимостей мито
void qSort(int a[], int l, int r, int k) {
  while (r > l) {
    int i = l;  // индекс левой границы
    int j = r;  // индекс правой границы
    int mid = a[k];  // опорник

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
    // если к находится слева от текущей позиции ш
    if (k < i) {
        r = j; //новая права граница
    }

    // если к находится справа от текущей позиции j
    if (j < k) {
        l = i; // новая левая граница
    }
    }
}

// формула для вычисления курса МИТО
void formula(int A, int B, int C, int n, int exchangeRate[]) {
    for (int i = 2; i < n; i++) {
        exchangeRate[i] = exchangeRate[i - 2] * A + exchangeRate[i - 1] * B + C;
    }
}

int main() {
    int resultVar = 0; //ответ
    int n; // колво дней наблюдения
    int k; // количество максимальных стоимостей
    cin >> n >> k;
    int *exchangeRate = new int[n]; // массив курса

    int A,B,C,a1,a2;
    cin >> A >> B >> C >> a1 >> a2;

    // тк курс в первые два дня известен, заполняем
    exchangeRate[0] = a1;
    exchangeRate[1] = a2;

    formula(A, B, C, n, exchangeRate); // прогон массива курса по формуле
    qSort(exchangeRate, 0, n - 1, n - k); //

    for (int i = n - k; i < n; i++) {
        resultVar ^= exchangeRate[i];
    }

    cout << resultVar << "\n";

    // очистка памяти
    delete[] exchangeRate;
    return 0;
}