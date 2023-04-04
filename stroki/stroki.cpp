#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    string s[7]; // ввод 7 строк
    for (int i = 0; i < 7; i++) {
        cout << "Введите строку " << i + 1 << ": ";
        getline(cin, s[i]);
    }

    // вывод списка
    cout << endl << "Количество слов в первой строке: " << count(s[0].begin(), s[0].end(), ' ') + 1 << endl;
    for (int i = 0; i < s[0].size(); i++) {
        if (s[0][i] == ' ') {
            cout << endl;
        }
        else {
            cout << s[0][i];
        }
    }


    // 2. вывод номера телефона из второй строки
    cout << "Номер телефона: ";
    for (int i = 0; i < s[1].size(); i++) {
        if (isdigit(s[1][i])) {
            cout << s[1][i];
        }
    }
    cout << endl;

    // 3. сравнение третьей и четвёртой строк без учёта регистра
    if (s[2].size() != s[3].size()) {
        cout << "Строки не равны" << endl;
    }
    else {
        transform(s[2].begin(), s[2].end(), s[2].begin(), ::tolower);
        transform(s[3].begin(), s[3].end(), s[3].begin(), ::tolower);
        if (s[2] == s[3]) {
            cout << "Строки равны" << endl;
        }
        else {
            cout << "Строки не равны" << endl;
        }
    }

    // 4. замена подстроки в пятой строке на седьмую
    string sub = s[5];
    string rep = s[6];
    size_t pos = s[4].find(sub);
    if (pos != string::npos) {
        s[4].replace(pos, sub.length(), rep);
        cout << "Новая строка: " << s[4] << endl;
    }
    else {
        cout << "Подстрока не найдена" << endl;
    }

    return 0;
}