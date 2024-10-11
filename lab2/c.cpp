#include <iostream>

const int maxn = 70000;
int res[maxn];

//реалзация свапа двух переменных по ссылке
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//генерация контртеста квиксорту
void antiQsort(int n) {
    for (int i = 0; i < n; i++) {
        res[i] = i + 1;
    }

    // перемещение значений по дереву
    for (int i = 2; i < n; i++) { //начинаем с элемента у которого есть родитель
        swap(res[i], res[i / 2]);
    }
}

int main() {
    int n;
    std::cin >> n;

    antiQsort(n);
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
