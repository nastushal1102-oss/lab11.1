#include <iostream>
#include <list>
#include <string>
#include <iomanip>

using namespace std;


struct Medicine {
    string name;        // назва
    string manufacturer;// виробник
    int expiryYear;     // рік придатності
    double price;       // ціна
};


void printMedicines(const list<Medicine>& meds) {
    if (meds.empty()) {
        cout << "Список препаратів порожній.\n" << endl;
        return;
    }

    cout << string(72, '-') << endl;
    cout << left << setw(22) << "Назва"
         << setw(20) << "Виробник"
         << setw(18) << "Рік придатності"
         << setw(12) << "Ціна (грн)" << endl;
    cout << string(72, '-') << endl;

    for (const auto& m : meds) {
        cout << left << setw(22) << m.name
             << setw(20) << m.manufacturer
             << setw(18) << m.expiryYear
             << fixed << setprecision(2) << setw(12) << m.price << endl;
    }
    cout << string(72, '-') << "\n" << endl;
}

int main() {

    list<Medicine> pharmacy = {
        {"Нурофен", "Reckitt", 2027, 185.50},
        {"Цитрамон-Дарниця", "Дарниця", 2025, 42.00},
        {"Амізон", "Фармак", 2026, 134.80},
        {"Німесил", "Berlin-Chemie", 2028, 290.00},
        {"Корвалол", "Фармак", 2024, 58.20}
    };

    cout << "1. Початковий список препаратів:" << endl;
    printMedicines(pharmacy);

    
    pharmacy.push_front({"Парацетамол", "Дарниця", 2027, 35.00});
    pharmacy.push_back({"Ібупрофен", "Борщагівський ХФЗ", 2025, 76.40});

    cout << "2. Список після додавання на початок і в кінець:" << endl;
    printMedicines(pharmacy);

   
    string targetManufacturer = "Фармак";
    cout << "3. Фільтрація — препарати виробника \"" << targetManufacturer << "\":" << endl;
    list<Medicine> filtered;
    for (const auto& m : pharmacy) {
        if (m.manufacturer == targetManufacturer) {
            filtered.push_back(m);
        }
    }
    printMedicines(filtered);

    
    int controlYear = 2026;
    cout << "4. Видалення препаратів з роком придатності < " << controlYear << ":" << endl;
    

    for (auto it = pharmacy.begin(); it != pharmacy.end(); ) {
        if (it->expiryYear < controlYear) {
            it = pharmacy.erase(it); // erase повертає ітератор на наступний елемент
        } else {
            ++it;
        }
    }
    printMedicines(pharmacy);


    pharmacy.sort([](const Medicine& a, const Medicine& b) {
        return a.name < b.name;
    });

    cout << "5. Список після сортування за назвою (за алфавітом):" << endl;
    printMedicines(pharmacy);

    return 0;
}