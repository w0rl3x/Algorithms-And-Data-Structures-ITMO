#include <iostream>
using namespace std;

//  заполнение массива н
void inputArray(int* arr, int N) {
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

//  проверка можно ли посадить челика н
bool isManPlacable(int* chairs, int tablePlaces, int manAmount, int distance) {
    int chairNum = 1;
    int firstPos = chairs[0];

    for (int i = 1; i < tablePlaces; i++) {
        if (chairs[i] - firstPos >= distance) {
            firstPos = chairs[i];
            chairNum++;
            if (chairNum == manAmount) {
                return true;
            }
        }
    }
    return false;
}

//  бинарный поиск минимального максимального расстояния н лог д
int binarySearch(int* chairs, int tablePlaces, int manAmount) {
    int left = 0;
    int right = chairs[tablePlaces - 1] - chairs[0];
    int finValue = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isManPlacable(chairs, tablePlaces, manAmount, mid) == true) {
            finValue = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return finValue;
}

int main() {
    int tablePlaces, manAmount;
    cin >> tablePlaces >> manAmount;

    int* chairs = new int [tablePlaces];

    inputArray(chairs, tablePlaces);

    cout << binarySearch(chairs, tablePlaces, manAmount) << "\n";

    delete [] chairs;
    return 0;
}