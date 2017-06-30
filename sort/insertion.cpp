#include <iostream>
#include <string>

void sort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int j = i - 1;
        while (j >= 0) {
            if (arr[i] < arr[j]) {
                int copy = arr[i];
                arr[i] = arr[j];
                arr[j] = copy;
            }
            j--;
        }
    }
}

void print_arr(int arr[], int len, const char *txt) {
    std::cout << txt;
    for (int i = 0; i < len - 1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[len - 1] << std::endl;
}

int main() {
    int arr[5] = {1, 3, 2, 6, 4};
    int len = sizeof(arr) / sizeof(*arr);
    print_arr(arr, len, "Input array: ");
    sort(arr, len);
    print_arr(arr, len, "Sorted array: ");
    return 0;
}

