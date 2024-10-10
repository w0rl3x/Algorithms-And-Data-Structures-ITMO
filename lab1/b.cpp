// Покупка друзей
// Пока Гарри ехал на поезде в Хогвартс, он долго думал о том, как же ему завоевать расположение других учеников. Вдруг в проходе появилась тележка со сладостями, и Гарри пришла в голову гениальная идея - нужно угостить как можно больше ребят в поезде, чтобы поднять свой социальный рейтинг.
// Гарри понравились сладости двух видов - икотные конфеты и обморочные орешки. Оказалось, что в тележке было всего A конфет и B орешков, Гарри решил купить их все, потому что у него было много денег.
// Чтобы ребята не обиделись, Гарри хочет раздать всем одинаковое количество конфет и одинаковое количество орешков (другими словами, каждому студенту достанется ровно x орешков и y конфет, при этом ничейных конфет или орешков остаться не должно).

// Входные данные
// Два натуральных числа A и B ( 1 ≤ A, B ≤ 10⁹), разделенных пробелом.

// Выходные данные
// Натуральное число - сколько максимум ребят сможет угостить Гарри

// Сложность - O(1)
#include <iostream>

int main()
{
    int a;
    int b;
    std::cin >> a >> b;
    while (a != b) {
        if (a>b) {
            a = a - b;
        }
        else {
            b = b - a; 
        }
    }
    std::cout << a;
}