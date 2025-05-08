#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_X 50
#define SIZE_Y 60

void fill_array_random(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 201) - 100; // Генерує числа від -100 до 100
    }
}

void calculate_sums(int arr_x[], int size_x, int arr_y[], int size_y, long long *s1, long long *s2) {
    *s1 = 0;
    *s2 = 0;

    for (int i = 0; i < size_x; i++) {
        if (arr_x[i] > 0) {
            *s1 += arr_x[i];
        }
    }

    for (int i = 0; i < size_y; i++) {
        if (arr_y[i] < 0) {
            *s2 += arr_y[i];
        }
    }
}

int main() {
    srand(time(NULL));

    int x[SIZE_X];
    int y[SIZE_Y];

    fill_array_random(x, SIZE_X);
    fill_array_random(y, SIZE_Y);

    long long s1, s2;

    calculate_sums(x, SIZE_X, y, SIZE_Y, &s1, &s2);

    double z = (double)(s1 + s2) / 2.0;

    printf("Масив x:\n");
    for (int i = 0; i < SIZE_X; i++) {
        printf("%d ", x[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");

    printf("Масив y:\n");
    for (int i = 0; i < SIZE_Y; i++) {
        printf("%d ", y[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");

    printf("s1 (сума додатних елементів масиву x): %lld\n", s1);
    printf("s2 (сума від'ємних елементів масиву y): %lld\n", s2);
    printf("z = (s1 + s2) / 2 = %.2f\n", z);

    return 0;
}