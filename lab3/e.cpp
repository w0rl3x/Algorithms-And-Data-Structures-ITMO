#include <iostream>
using namespace std;

// Счетчик количества дробей меньше mid и нахождение наибольшей дроби, меньшей mid
int countFracsLessThanMid(int arr[], int n, double mid, int& bestNum, int& bestDen) {
    int count = 0;
    double maxFraction = 0.0;

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            double fraction = (double)arr[i] / arr[j];
            if (fraction < mid) {
                count++;
                if (fraction > maxFraction) { // Запоминаем ближайшую дробь к mid
                    maxFraction = fraction;
                    bestNum = arr[i];
                    bestDen = arr[j];
                }
            } else {
                break; // Дальше дроби не будут меньше mid
            }
        }
    }
    return count;
}

// Бинарный поиск для нахождения k-й наименьшей дроби
void kBinSearch(int arr[], int n, int k) {
    double left = 0.0, right = 1.0; // Установка правой границы
    int bestNum = 0, bestDen = 1;

    while (right - left > 1e-8) { // Сужаем диапазон поиска
        double mid = (left + right) / 2;

        bestNum = 0; // Сброс значений
        bestDen = 1;

        int count = countFracsLessThanMid(arr, n, mid, bestNum, bestDen);

        if (count < k) {
            left = mid; // Увеличиваем минимум
        } else {
            right = mid; // Уменьшаем максимум
        }
    }

    // Печатаем k-ю наименьшую дробь
    cout << bestNum << " " << bestDen << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    int array[100000]; // Задаем максимально возможный размер массива

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    kBinSearch(array, n, k);
    return 0;
}
