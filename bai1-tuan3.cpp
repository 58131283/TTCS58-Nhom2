#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initRandomArray(int *A, int n, int k) {
    srand(time(NULL));
    int randNum = 0;
    for (int i = 0; i < n; i++) {
        randNum = rand() % k;
        A[i] = randNum;
    }
}

int main() {
    int *A;
    int n = 10; /* so luong phan tu  */
    int k = 100; /* Moi phan tu có giá tri ngau nhiên nam trong khoang tu 0 den k */

    A = new int[n]; // Cap phát bo nho cho mang A

    initRandomArray(A, n, k);

    /* Xu?t m?ng */
    for (int i = 0; i < n; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");

    delete[]A; // Free vùng nh? sau khi s? d?ng
    return 0;
}
