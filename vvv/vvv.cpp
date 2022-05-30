#include <iostream>
#include <vector>
#include <memory>
#include <time.h> 
#include <algorithm>
#include <cmath>
#include "Rabbit.h"
#include "WolfGirl.h"
#include "WolfMan.h"
#include "Constants.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "---------- Краткое руководство ----------\n\n" << endl;
    cout << "Приветствую вас в экологической модели “Волчий остров”.\nПожалуйста, ознакомьтесь с моделью для дальнейшей работы.\nЕё суть проста: имеется остров размером 20 на 20, который заселён дикими волками и кроликами. \nКаждый ход кролик ходит в случайную сторону(ограниченную береговой линией) или создаёт ещё одного  кролика. \nВолки же наоборот должны искать в пределах своего поля зрения кроликов или волчиц и гнаться за ними. \nЕсли волк и волчица окажутся в одном месте, то они создадут ещё одного представителя своего рода случайного пола.\nВолки изначально имеют 1 очко «жизни» и теряют 0.1 очко каждый ход. " << endl;
    vector<shared_ptr<Rabbit>> all_rabbits;
    vector<shared_ptr<WolfGirl>> all_wolfgirl;
    vector<shared_ptr<WolfMan>> all_wolfman;
    int count_rabbits;
    int count_wolfgirl;
    int count_wolfman;
    cout << "\n\n" << endl;
    cout << "Введите количество кроликов на поле: ";
    cin >> count_rabbits;
    if (count_rabbits >= 400 || count_rabbits < 0) {
        cout << "Количество кроликов должно быть в предлах от 0 до 400\n";
        system("pause");
    }
    cout << "Введите количество волчиц на поле: ";
    cin >> count_wolfgirl;
    if (count_wolfgirl >= 400 || count_wolfgirl < 0) {
        cout << "Количество волчиц должно быть в предлах от 0 до 400\n";
        system("pause");
    }
    cout << "Введите количество волков на поле: ";
    cin >> count_wolfman;
    if (count_wolfman >= 400 || count_wolfman < 0) {
        cout << "Количество волков должно быть в предлах от 0 до 400\n";
        system("pause");
    }
    for (size_t i = 0; i < count_rabbits; i++) {
        int x = 0;
        int y = 0;
        cout << "----------" << endl;
        cout << "Кролик по номеру " << i + 1 << endl;
        cout << "Введите координату Х в диапазоне от  " << FIELD_X_m << " До " << FIELD_X_M << ": ";
        cin >> x;
        if (x > 20 || x < 1) {
            cout << "Координаты введены неправильно, перепроверьте их и попробуйте ещё раз позднее\n";
            system("pause");
        }
        else {
            cout << "Введите координату У в диапазоне от  " << FIELD_Y_m << " до " << FIELD_Y_M << ": ";
            cin >> y;
            if (y > 20 || y < 1) {
                cout << "Координаты введены неправильно, перепроверьте их и попробуйте ещё раз позднее\n";
                system("pause");
            }
            else {
                shared_ptr<Rabbit> new_rabbit(new Rabbit(x, y, &all_rabbits));
                all_rabbits.push_back(new_rabbit);
            }
        }
    }
    for (size_t i = 0; i < count_wolfgirl; i++) {
        int x = 0;
        int y = 0;
        cout << "----------" << endl;
        cout << "Волчица по номеру " << i + 1 << endl;
        cout << "Введите координату Х в диапазоне от  " << FIELD_X_m << " До " << FIELD_X_M << ": ";
        cin >> x;
        if (x > 20 || x < 1) {
            cout << "Координаты введены неправильно, перепроверьте их и попробуйте ещё раз позднее\n";
            system("pause");
        }
        else {
            cout << "Введите координату У в диапазоне от  " << FIELD_Y_m << " до " << FIELD_Y_M << ": ";
            cin >> y;
            if (y > 20 || y < 1) {
                cout << "Координаты введены неправильно, перепроверьте их и попробуйте ещё раз позднее\n";
                system("pause");
            }
            else {
                shared_ptr<WolfGirl> new_wolfgirl(new WolfGirl(x, y, &all_rabbits, &all_wolfgirl));
                all_wolfgirl.push_back(new_wolfgirl);
            }
        }
    }
    for (size_t i = 0; i < count_wolfman; i++) {
        int x = 0;
        int y = 0;
        cout << "----------" << endl;
        cout << "Волк по номеру  " << i + 1 << endl;
        cout << "Введите координату Х в диапазоне от  " << FIELD_X_m << " до " << FIELD_X_M << ": ";
        cin >> x;
        if (x > 20 || x < 1) {
            cout << "Координаты введены неправильно, перепроверьте их и попробуйте ещё раз позднее\n";
            system("pause");
        }
        else {
            cout << "Введите координату У в диапазоне от  " << FIELD_Y_m << " до " << FIELD_Y_M << ": ";
            cin >> y;
            if (y > 20 || y < 1) {
                cout << "Координаты введены неправильно, перепроверьте их и попробуйте ещё раз позднее\n";
                system("pause");
            }
            else {
                shared_ptr<WolfMan> new_wolfman(new WolfMan(x, y, &all_rabbits, &all_wolfman, &all_wolfgirl));
                all_wolfman.push_back(new_wolfman);
            }
        }
    }
    cout << "\n\n";
    cout << "---------- НАЧАЛО СИМУЛЯЦИИ ----------" << endl;
    while (all_rabbits.size() != 0 && all_rabbits.size() + all_wolfgirl.size() + all_wolfman.size() < 400) {
        vector<shared_ptr<Rabbit>> rabbits_copy(all_rabbits);
        vector<shared_ptr<WolfGirl>> wolfgirl_copy(all_wolfgirl);
        vector<shared_ptr<WolfMan>> wolfman_copy(all_wolfman);
        for (auto rabb : rabbits_copy) {
            (*rabb).tick();
        }
        for (auto wolf_girl : wolfgirl_copy) {
            (*wolf_girl).tick();
            cout << "Количество очков определенной волчицы: " << (*wolf_girl).life_points << endl;
        }
        for (auto wolf_man : wolfman_copy) {
            (*wolf_man).tick();
            cout << "Количество всех кроликов: " << all_rabbits.size() << endl;
            cout << "Количество очков определенного волка: " << (*wolf_man).life_points << endl;
        }
        cout << "Количество всех кроликов: " << all_rabbits.size() << endl;
        cout << "Количество всех волчиц: " << all_wolfgirl.size() << endl;
        cout << "Количество всех волков: " << all_wolfman.size() << endl;
        cout << "-----------------------------------" << endl;
    }
    cout << "---------- КОНЕЦ СИМУЛЯЦИИ ----------" << endl;
    cout << endl;
    cout << "---------- ИТОГИ ----------" << endl;
    cout << "Количество всех кроликов: " << all_rabbits.size() << endl;
    cout << "Количество всех волчиц: " << all_wolfgirl.size() << endl;
    cout << "Количество всех волков: " << all_wolfman.size() << endl;
    all_rabbits.clear();
    cout << "Игра окончена" << endl;
    system("pause");
}
