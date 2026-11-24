#include <iostream>
#include <list>
#include <iterator> 

using namespace std;

void printList(const list<double>& lst) {
    if (lst.empty()) {
        cout << "Список порожній." << endl;
        return;
    }
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << "  ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Введіть кількість елементів списку N (N > 0): ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: кількість елементів має бути додатним числом!" << endl;
        return 1;
    }

    list<double> numbers;
    cout << "Введіть " << n << " дійсних чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        double val;
        cin >> val;
        numbers.push_back(val);
    }

    cout << "\nПочатковий список: ";
    printList(numbers);

    int deletedCount = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        // Перевіряємо, чи число в діапазоні [10; 20] і чи існує попередній елемент
        if (*it >= 10.0 && *it <= 20.0 && it != numbers.begin()) {
            numbers.erase(std::prev(it));
            deletedCount++;
        }
    }

    cout << "Кількість вилучених елементів: " << deletedCount << endl;
    cout << "Список після внесення змін: ";
    printList(numbers);

    return 0;
}