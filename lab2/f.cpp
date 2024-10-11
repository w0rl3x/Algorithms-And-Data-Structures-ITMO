#include <iostream>
using namespace std;

long long merge_n_CountPairs(int arr[], int l, int pivot, int r) {
    int leftArrSize = pivot - l + 1; // сайз левого подмассива
    int rightArrSize = r - pivot;     // сайз правого подмассива

    long long insersionCount = 0; // kolvo пар

    // темп вариаблы для левого и правого подмассивов
    int L[leftArrSize]; // массив фбк (левый)
    int R[rightArrSize]; // ультрарайт вайт супримаси массив (шутко)

    // ктрл с во временные массивы
    for (int i = 0; i < leftArrSize; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < rightArrSize; j++)
        R[j] = arr[pivot + 1 + j];

    // мердж временных массивов обратно в arr[]
    int i = 0; // индекс L 
    int j = 0; // индекс R массива
    int k = l; // индекс конечного массива arr[]
    while (i < leftArrSize && j < rightArrSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            insersionCount += (leftArrSize - i);
        }
        k++;
    }

    // ктрл с оставшиеся элементы из левого массива если остались
    while (i < leftArrSize) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ктрл с оставшиеся элементы из правого если остались
    while (j < rightArrSize) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return insersionCount;
}

// ф-ия сорта мерджом для сорта подмассива arr[]
long long mergeSort(int arr[], int l, int r) {
    long long inversionCount = 0;
    if (l < r) {
        int pivot = l + (r - l) / 2; // средний элем / пайвот

        // рекурсия - сортируем два подмассива
        inversionCount += mergeSort(arr, l, pivot);
        inversionCount += mergeSort(arr, pivot + 1, r);

        // мерджим два отсортченные массива
        inversionCount += merge_n_CountPairs(arr, l, pivot, r);
    }

    return inversionCount;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << mergeSort(arr, 0, n - 1) << "\n";
    return 0;
}