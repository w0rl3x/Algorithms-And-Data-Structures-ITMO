// Студенты всегда хотят спать
// Студенты всегда хотят спать, поэтому на факультете придумали особую систему подсчёта оптимального дня для сна.
// Каждому тяжелому дню сопоставим отрицательное число, каждому простому - положительное. Оптимальный день для сна - тот день, сумма чисел до которого и после которого совпадают.
// Входные данные
// В первой строке задается единственное число N (1 ≤ N ≤ 8∗10^6) - количество дней. Во второй строке задается N целых чисел xi (−10^7 ≤ xi ≤ 10^6) - сопоставленные числа. 

// Выходные данные
// В единственной строке выведите индекс оптимального дня для сна или -1, если такового не существует. Индексация начинается с 0.
// Если таких несколько, выведите самый первый индекс.

// Оценка сложности - O(n)
#include <iostream>

int main()
{
    //vvod peremennih
    int daysquantity;
    int allsum = 0;
    int leftsum = 0;
    //int cnt = 0;
    std::cin >> daysquantity;
    int index[daysquantity];

    //cikl dlya allsum
    for (int i = 0; i < daysquantity; i++)
    {
        std::cin >> index[i];
        allsum = allsum + index[i];
    }

    // opisivayu exception case - vozvrashaet 0
    // upd 21.09. - нашел ошибку логики, вместо проверки на 0, можно просто начать
    // поиск с первого дня (индекс 0)
    // оставляю код для наглядности
    //if (allsum - index[0] == 0)
    //{
    //    std::cout << 0;
    //    return 0;
    //}

    // output indexa optimalnogo dnya dlya sna
    for (int i = 0; i < daysquantity; i++)
    {
        //leftsum = leftsum + index[i - 1];
        if (leftsum == allsum - index[i] - leftsum)
        {
            std::cout << i;
            //cnt ++;
            return 0;
        }
        //else {continue;}
        leftsum += index[i]; // апдейт суммы слева
    }

    // case, kogda optimalnogo dnya ne sushestvuet p.s. rip :^(
    //if (cnt == 0)
    //{
    //    std::cout << -1;
    //}

    std::cout << -1;
    return 0;
}