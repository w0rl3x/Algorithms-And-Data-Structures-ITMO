#include <iostream>
using namespace std;

// Функция для проверки соответствия preorder и inorder обходов
bool check_Pre_In(int* preorder, int* inorder, int& pre_index, int in_start, int in_end) 
{
    if (in_start > in_end) {
        return true;
    }

    // Значение текущего корня из preorder
    int root_value = preorder[pre_index++];
    
    // Поиск корня в inorder обходе
    int in_index = in_start;
    while (in_index <= in_end && inorder[in_index] != root_value) {
        in_index++;
    }

    // Если не нашли значение, возвращаем false
    if (in_index > in_end) {
        return false;
    }

    // Проверяем левое и правое поддеревья
    int leftNRightSubTreesCheck = check_Pre_In(preorder, inorder, pre_index, in_start, in_index - 1) && check_Pre_In(preorder, inorder, pre_index, in_index + 1, in_end);
    return leftNRightSubTreesCheck;
}

// Функция для проверки соответствия postorder и inorder обходов
bool check_Post_In(int* postorder, int* inorder, int& post_index, int in_start, int in_end) 
{
    if (in_start > in_end) {
        return true;
    }

    // Значение текущего корня из postorder
    int root_value = postorder[post_index--];

    // Поиск корня в inorder обходе
    int in_index = in_start;
    while (in_index <= in_end && inorder[in_index] != root_value) {
        in_index++;
    }

    // Если не нашли значение, возвращаем false
    if (in_index > in_end) {
        return false;
    }

    // Проверяем правое и левое поддеревья (сначала правое, затем левое)
    return check_Post_In(postorder, inorder, post_index, in_index + 1, in_end) && check_Post_In(postorder, inorder, post_index, in_start, in_index - 1);
}

int main() 
{
    int n;
    cin >> n;

    int* preorder = new int[n];
    int* inorder = new int[n];
    int* postorder = new int[n];

    // Считываем обходы
    for (int i = 0; i < n; ++i)
    { 
        cin >> preorder[i];
    }
    for (int i = 0; i < n; ++i)
    { 
        cin >> inorder[i];
    }
    for (int i = 0; i < n; ++i)
    { 
        cin >> postorder[i];
    }

    // Инициализируем индексы
    int pre_index = 0, post_index = n - 1;

    // Проверяем валидность обходов
    if (check_Pre_In(preorder, inorder, pre_index, 0, n - 1) && check_Post_In(postorder, inorder, post_index, 0, n - 1)) 
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
 
    delete[] preorder;
    delete[] inorder;
    delete[] postorder;

    return 0;
}
