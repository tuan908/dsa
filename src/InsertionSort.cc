#include <iostream>

void insertionSort(int* array, int n) {
    for (int i = 1; i < n; ++i) {
        int key = array[i];
        int j = i - 1;

        // Di chuyển các phần tử của mảng đã sắp xếp lớn hơn key
        // tới một vị trí phía sau vị trí hiện tại của chúng
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        // Chèn key vào vị trí đã xác định
        array[j + 1] = key;
        for (int i = 0; i < n; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    int* array = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    insertionSort(array, n);

    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}
