#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Merge two sorted subarrays into one sorted array
void merge(vector<int> &arr, int left, int middle, int right, bool isSortDesc) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    // Merge the temporary arrays back into arr[]
    int i = 0;     // Initial index of first subarray
    int j = 0;     // Initial index of second subarray
    int k = left;  // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (isSortDesc == true) {
            if (L[i] > R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        } else {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right, bool isSortDesc) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid, isSortDesc);
        mergeSort(arr, mid + 1, right, isSortDesc);

        // Merge the sorted halves
        merge(arr, left, mid, right, isSortDesc);
    }
}

string solve(vector<int> &arr) {
    int sum = 0;

    for (int i : arr) {
        sum += i;
    }
    string s = "";
    if (sum % 3 == 0) {
        mergeSort(arr, 0, arr.size() - 1, true);
        for (int i : arr) {
            s += to_string(i);
        }
        return s;
    }

    mergeSort(arr, 0, arr.size() - 1, false);
    for (int i : arr) {
        if (i % 3 == 0) {
            s += i;
        } else {
            continue;
        }
    }
    vector<int> tempV;
    for (auto i = 0; i < s.length(); i++) {
        int x = s[i] - '0';
        tempV.push_back(x);
    }
    mergeSort(tempV, 0, tempV.size() - 1, true);
    for (int i : tempV) {
        s += to_string(i);
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    vector<int> v1;

    getline(cin, s);

    if (s.length() < 2) {
        cout << "Invalid";
        return 0;
    }

    for (auto i = 0; i < s.length(); i++) {
        int x = s[i] - '0';
        v1.push_back(x);
    }

    string ans = solve(v1);

    cout << ans;

    return 0;
}