#include <iostream>

const int maxFriends = 100000;
__int64_t start[maxFriends]; // массив начал досок
__int64_t end[maxFriends]; // массив концов досок

//реализация квиксорт
void quicksort(__int64_t a[], __int64_t b[], int l, int r) {
    if (l >= r) {
        return;
    }
    int i = l;
    int j = r;
    int mid = a[rand() % (r - l + 1) + l];
    while (i <= j) {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j) {
            std::swap(a[i], a[j]);
            std::swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quicksort(a, b, l, j);
    if (r > i)
        quicksort(a, b, i, r);
}

int main() {
    int friends;

    std::cin >> friends;

    for (int i = 0; i < friends; i++) {
        std::cin >> start[i] >> end[i];
    }

    quicksort(start, end, 0, friends - 1);
    
    //текущие начала и концы досок
    __int64_t cStart = start[0];
    __int64_t cEnd = end[0];

    __int64_t resultVar = 0;

    for (int i = 1; i < friends; i++) {
        //чек покрасил ли друг новые доски которые уже покрашены
        if (start[i] <= cEnd + 1) {
            cEnd = std::max(cEnd, end[i]); // расширяем границы покрашенных досок между текущим концом и последней покрашенной в новом интервале
        } else { // если не пересекаются с покрашенными
            resultVar += cEnd - cStart + 1; //добавляем колво покрашенных досок от текушего начала до конца
            cStart = start[i]; //апдейт к новому интервалу
            cEnd = end[i]; 
        }
    }

    // учет последней группы покрашенных досок мб они не были добавлены внутри цикла
    resultVar += cEnd - cStart + 1;

    std::cout << resultVar << "\n";
    return 0;
}