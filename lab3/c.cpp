#include <iostream>
#include <string>
using namespace std;

void countingSort(string arr[], int n, int pos) {
    string output[n];  // временное хранение отсортированных строк
    int count[256] = {0};  // подсчет символов ascii

    // Подсчет количества каждого символа на позиции (pos)
    for (int i = 0; i < n; i++) {
        count[arr[i][pos]]++;
    }

    // преобразование count в позиционный массив
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    // построение отсортированного массива
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i][pos]] - 1] = arr[i];
        count[arr[i][pos]]--;
    }

    // Копирование отсортированных строк обратно в ориг массив
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// ф-ия для сортировки сообщений по последним t символам
void radixSort(string arr[], int n, int k, int t) {
    // Сортировка начиная с последнего символа
    for (int i = k - 1; i >= k - t; i--) {
        countingSort(arr, n, i);
    }
}

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    string msgs[n];

    for (int i = 0; i < n; i++) {
        cin >> msgs[i];
    }

    radixSort(msgs, n, k, t);

    for (int i = 0; i < n; i++) {
        cout << msgs[i] << endl;
    }

    return 0;
}
