#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
        Node* Head;
        Node* Tail;
    public:
        // Инициализация указателя на вершину очереди
        void init() {
            Head = NULL;
            Tail = NULL;
        }

        void enQueue(int value) {
            Node* newNode = new Node();  // Создание нового узла
            newNode->data = value;       // Запись данных в узел
            newNode->next = NULL;     // Новый элемент будет последним, значит next = nullptr 
            if (Head == NULL) {
                Head = Tail = newNode;
            } else {
                Tail->next = newNode;
                Tail = newNode;
            }
        }

        int frontDequeue() {
            if (Head == NULL) {
                return 0;
            }
            Node* temp = Head;  // Сохраняем текущий верхний элемент
            int dequeuedValue = temp->data;
            Head = Head->next;  // Вершинной очереди становится следующий элемент
            if (Head == NULL) {
                Tail = NULL;
            }
            delete temp;  // Удаляем старый верхний элемент
            return dequeuedValue;
        }
        // Проверка, пуст ли очередь
        bool isEmpty() {
            if (Head == NULL)
                return true;
            else 
                return false;
        }

        void clear() {
            while (!isEmpty()) {
                frontDequeue();
            }
        }

        ~Queue() {
            clear();
        }
};

int main () {
    Queue queue;
    queue.init();
    int operationQnt;
    cin >> operationQnt;
    int x;
    string opers;
    string dequeuedPpl = "";
    for (int i = 0; i < operationQnt; i++) {
        cin >> opers;
        if (opers == "+") {
            cin >> x;
            queue.enQueue(x);
        } else if (opers == "-") {
            if (!queue.isEmpty()) {
                dequeuedPpl += "\n";
            }
            dequeuedPpl += to_string(queue.frontDequeue());   
        }
    }

    cout << dequeuedPpl << "\n";
    return 0;
}


