#define _CRT_SECURE_NO_WARNINGS      //abc,-def,-ghi
#include <iostream>
#include <cstring>
using namespace std;

int Count(const char* str) {
    if (strlen(str) < 2)
        return 0;
    int k = 0;
    for (int i = 0; str[i + 1] != 0; i++) {
        if (str[i] == ',' && str[i + 1] == '-') // Перевірка на ",-"
            k++;
    }
    return k;
}

char* Change(const char* str) {
    size_t len = strlen(str);
    if (len < 2)
        return _strdup(str); // Копіюємо рядок, якщо його довжина менша за 2

    // Виділяємо достатньо місця для можливого збільшення довжини рядка
    char* tmp = new char[len * 2 + 1];
    char* t = tmp;

    size_t i = 0;
    while (i < len) {
        if (str[i] == ',' && str[i + 1] == '-') { // Знаходимо ",-" і замінюємо на "*"
            *t++ = '*';
            i += 2;
        }
        else {
            *t++ = str[i++];
        }
    }
    *t = '\0';
    return tmp;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Підраховуємо кількість груп ",-"
    cout << "String contained " << Count(str) << " groups of ',-'" << endl;

    // Заміна ",-" на "*"
    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;  // Початковий рядок
    cout << "Modified string (result): " << dest << endl; // Змінений рядок

    delete[] dest; // Звільняємо пам'ять
    return 0;
}
