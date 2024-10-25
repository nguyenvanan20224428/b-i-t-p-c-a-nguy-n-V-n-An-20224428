#include <stdio.h>
#include <stdlib.h>

void sortColors(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) { // màu do
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } else if (arr[mid] == 1) { // màu trang
            mid++;
        } else { // màu xanh
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Nhap so luong phan tu
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    // Khoi tao mang vi 
    int arr[n];

    // Nhap các phan tu 
    printf("Nhap các phan t? (0 - do, 1 - trang, 2 - xanh):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    sortColors(arr, n);

    
    printf("Mang sau khi sap xap: ");
    printArray(arr, n);

    return 0;
}


