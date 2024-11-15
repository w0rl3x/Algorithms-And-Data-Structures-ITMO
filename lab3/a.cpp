#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* Head;  // Указатель на верхний элемент стека

public:
    // Инициализация указателя на вершину стека
    void init() {
        Head = NULL;
    }

    // Проверка, пуст ли стек
    bool isEmpty() {
        if (Head == NULL)
            return true;
        else 
            return false;
    }

    // Добавление элемента в стек
    void push(int value) {
        Node* newNode = new Node();  // Создание нового узла
        newNode->data = value;       // Запись данных в узел
        newNode->next = Head;     // Указатель на текущий верхний элемент
        Head = newNode;           // Новый узел становится верхним элементом
    }

    // Удаление верхнего элемента из стека
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty, cannot pop.\n";
            return 1;
        }
        Node* temp = Head;  // Сохраняем текущий верхний элемент
        Head = Head->next;  // Вершиной стека становится следующий элемент
        int poppedValue = temp->data; //записываем значение верхнего элемента
        delete temp;  // Удаляем старый верхний элемент
        return poppedValue; // врзват верхнего элема
    }

    // Получение значения верхнего элемента стека
    int top() {
        if (isEmpty()) {
            std::cout << "Stack is empty, no top element.\n";
            return -1;  // Можно вернуть специальное значение или выбросить исключение
        }
        return Head->data;
    }

    // Очистка стека
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    // авто деструктор
    ~Stack() {
        clear();
    }

};

int main() {
    int operationQnt;
    cin >> operationQnt;
    int x;
    string opers;
    string pops = "";
    Stack stack;
    stack.init();

    for (int i = 0; i < operationQnt; i++) {
        cin >> opers;
        if (opers == "+") {
            cin >> x;
            stack.push(x);
        } else if (opers == "-") {
            if (!stack.isEmpty()) {
                pops += "\n";
            }
            pops += to_string(stack.pop());
        }
    }
    cout << pops << "\n";
    return 0;
}
