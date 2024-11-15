#include <iostream>
#include <string>
using namespace std;

struct StackNode {
    int value;
    StackNode* next;
};

class Stack {
public:
    Stack() : top(nullptr) {} // конструктор, верхний узел пустой

    // метод добавления элемента в стэк
    void push(int val) {
        StackNode* newNode = new StackNode{val, top};
        top = newNode;
    }

    // удаление верхнего элема в стэке
    void pop() {
        if (top) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // получение значения верхнего элемента
    int peek() const {
        return top ? top->value : 1;
    }

    // проврка на пустоту стэка
    bool empty() const {
        return top == nullptr;
    }

    // деструктор освобождаюищий память
    ~Stack() {
        while (top) {
            pop();
        }
    }

private:
    StackNode* top; // указатель на верхний узел стэка
};

// функция проверки, является ли символ цифрой
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// функция проверки, является ли символ буквой
bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    string chemForm;
    cin >> chemForm;

    int elements[26] = {0}; // храним колво каждого элема
    Stack multipStack; // стэк для хранения текущего множителя
    multipStack.push(1);
    int curMulti = 1; // переменная для хранения текущего жлема

    // идем справа налево тк множители известны до самого элема
    for (int i = chemForm.length() - 1; i >= 0; --i) {
        if (isDigit(chemForm[i])) {
            int num = 0, pwr = 1; // вары для числового значения
            while (i >= 0 && isDigit(chemForm[i])) { // обработка всех цифр
                num += (chemForm[i] - '0') * pwr; // сборка полного числа
                pwr *= 10; // увеличение степени
                --i; // переход к следущему элему (справа налева)
            }
            ++i; // коррекция позиции после обработки
            curMulti = num; // установка текущего множителя
        }
        else if (chemForm[i] == ')') {
            multipStack.push(curMulti * multipStack.peek()); // умножение на верхний элем стэка и помешение в стэк
            curMulti = 1; // сброс тек множителя
        }
        else if (chemForm[i] == '(') {
            multipStack.pop(); // удаляем верхний элемент стэка
        }
        else if (isAlpha(chemForm[i])) { // чек на латинскую букву
            // увеличение колва текущего элема на произведение текущего множителя и верхнего элемента стека
            int elemMulti = curMulti * multipStack.peek();
            elements[chemForm[i] - 'A'] += elemMulti; // увеличение колва элема
            curMulti = 1; // сброс тек множителя
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (elements[i] > 0) { 
            cout << char('A' + i); 
            if (elements[i] > 1) { 
                cout << elements[i]; 
            }
        }
    }
    cout << "\n";

    return 0;
}
