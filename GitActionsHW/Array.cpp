#include <iostream>
#include "Array.h"
using namespace std;
int* mass_insert(int* mass, int size, int elem, int index) {
    const int n = size + 1;
    int* new_mass = (int*)malloc((n) * sizeof(int));
    if (new_mass == nullptr) return nullptr;
    for (int i = 0; i < index; ++i) {
        new_mass[i] = mass[i];
    }
    new_mass[index] = elem;
    for (int i = index; i < size; ++i) {
        new_mass[i + 1] = mass[i];
    }
    return new_mass;
}

int* mass_delete(int* mass, int size, int elem) {
    int* new_mass = (int*)malloc((size - 1) * sizeof(int));
    if (new_mass == nullptr) return nullptr;
    bool delete_indicator = false;
    int j = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (mass[i] == elem) {
            i++;
            delete_indicator = true;
        }
        new_mass[j] = mass[i];
        j++;
    }
    if (!delete_indicator) {
        return mass;
    }
    return new_mass;
}

int* mass_search(int* mass, int size, int elem) {
    int* new_mass = (int*)malloc((size) * sizeof(int));
    if (new_mass == nullptr) return nullptr;
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (mass[i] == elem) {
            new_mass[j] = i;
            j++;
        }
    }
    return new_mass;
}

void mass_out(int* mass, int size) {
    for (int i = 0; i < size; ++i) {
        cout << mass[i] << endl;
    }
}

void ArrayTest() {
    // - Массивы это структура данных, представляющая собой набор элементов одного типа, расположенных в памяти последовательно.
    // - Элементы одномерного массива размещаются последовательно в памяти, так что для доступа к любому элементу известен его адрес. Адрес элемента A[i] вычисляется по формуле:
    // - Адрес(A[i]) = Базовый адрес(A) + i * Размер элемента
    // - Алгоритмическая сложность вставки поиска и удаления O(n)
    // 1) Вставка
    cout << "Вставка" << endl;
    int mass_for_insert[3] = { 0, 1, 2 };
    cout << mass_for_insert[2] << endl;
    int* new_mass1 = mass_insert(mass_for_insert, 3, 8, 2);
    cout << new_mass1[2] << " end" << endl << endl;

    mass_out(mass_for_insert, 3);
    free(new_mass1);

    // 2) Удаление
    cout << "Удаление" << endl;
    int mass_for_delete[3] = { 0, 1, 2 };
    cout << mass_for_delete[1] << endl;
    int* new_mass2 = mass_delete(mass_for_delete, 3, 1);
    cout << new_mass2[1] << " end" << endl;
    free(new_mass2);

    // 3) Поиск
    cout << "Поиск" << endl;
    int mass_for_search[3] = { 0, 10, 2 };
    int* new_mass3 = mass_search(mass_for_search, 3, 10);
    cout << new_mass3[0] << " end" << endl;
    free(new_mass3);
}