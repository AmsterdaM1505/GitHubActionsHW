#include <iostream>
#include <assert.h>
#include "../GitActionsHW/Array.h"

void test_mass_insert() {
    int arr[3] = { 0, 1, 2 };
    int* res = mass_insert(arr, 3, 8, 1);

    assert(res != NULL);
    assert(res[0] == 0);
    assert(res[1] == 8);
    assert(res[2] == 1);
    assert(res[3] == 2);

    free(res);
}

void test_mass_delete() {
    int arr[3] = { 0, 1, 2 };
    int* res = mass_delete(arr, 3, 1);

    assert(res != NULL);
    assert(res[0] == 0);
    assert(res[1] == 2);

    free(res);
}

void test_mass_search() {
    int arr[5] = { 3, 8, 5, 8, 1 };
    int* res = mass_search(arr, 5, 8);

    assert(res != NULL);
    assert(res[0] == 1);
    assert(res[1] == 3);

    free(res);
}

int tests() {
    test_mass_insert();
    test_mass_delete();
    test_mass_search();

    printf("All tests passed!\n");
    return 0;
}