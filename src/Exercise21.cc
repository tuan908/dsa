#include <iostream>

using std::cin;
using std::cout;
using std::ios_base;

void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo các mảng tạm thời
    int *L = new int[n1];
    int *R = new int[n2];

    // Sao chép dữ liệu vào các mảng tạm thời L[] và R[]
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];

    for (int i = 0; i < n1; i++) {
        cout << L[i] << " ";
    }

    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];

    for (int i = 0; i < n2; i++) {
        cout << R[i] << " ";
    }

    // Trộn các mảng tạm thời lại với nhau
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Sao chép phần còn lại của các mảng tạm thời L[] hoặc R[] vào mảng arr[]
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int *A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;

        // Sắp xếp nửa đầu và nửa sau
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        // Trộn các nửa đã sắp xếp lại với nhau
        merge(A, p, q, r);
        for (int i = p; i < r; i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *arr1 = new int[n];

    for (int index1 = 0; index1 < n; index1++) {
        cin >> arr1[index1];
    }

    mergeSort(arr1, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    delete[] arr1;

    return 0;
}
