#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1000

// Ham sang Eratosthenes de tim cac so nguyen to nho hon n
void sieveOfEratosthenes(int n, bool primes[]) {
    for (int i = 0; i <= n; i++) {
        primes[i] = true;
    }
    primes[0] = primes[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (primes[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }
}

// Ham tao cac so Blum nho hon N
int generateBlumNumbers(int N, int blumNumbers[]) {
    bool primes[MAX];
    sieveOfEratosthenes((int)sqrt(N) + 1, primes);

    int count = 0;
    // Sinh cac so Blum bang cach nhan cac cap so nguyen to le khac nhau
    for (int i = 3; i < MAX; i += 2) {
        if (primes[i]) {
            for (int j = i + 2; j < MAX; j += 2) {
                if (primes[j]) {
                    int blumNum = i * j;
                    if (blumNum < N) {
                        blumNumbers[count++] = blumNum;
                    }
                }
            }
        }
    }
    return count;
}

// Ham tim cac cap so Blum co tong cung la mot so Blum
void findBlumPairs(int blumNumbers[], int count) {
    printf("Cac cap so Blum co tong cung la so Blum:\n");
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            int sum = blumNumbers[i] + blumNumbers[j];
            for (int k = 0; k < count; k++) {
                if (blumNumbers[k] == sum) {
                    printf("(%d, %d)\n", blumNumbers[i], blumNumbers[j]);
                    break;
                }
            }
        }
    }
}

// Ham kiem tra xem mot so Blum M co ton tai trong mang so Blum khong
bool isBlumNumber(int blumNumbers[], int count, int M) {
    for (int i = 0; i < count; i++) {
        if (blumNumbers[i] == M) {
            return true;
        }
    }
    return false;
}

int main() {
    int N, M;
    printf("Nhap N: ");
    scanf("%d", &N);
    printf("Nhap M: ");
    scanf("%d", &M);

    int blumNumbers[MAX];
    int count = generateBlumNumbers(N, blumNumbers);

    printf("Cac so Blum nho hon N:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", blumNumbers[i]);
    }
    printf("\n");

    findBlumPairs(blumNumbers, count);

    if (isBlumNumber(blumNumbers, count, M)) {
        printf("So %d la so Blum.\n", M);
    } else {
        printf("So %d khong phai la so Blum.\n", M);
    }

    return 0;
}

