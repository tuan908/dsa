#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tạo các mảng tạm thời
    vector<int> L(n1), R(n2);

    // Sao chép dữ liệu vào các mảng tạm thời L[] và R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // Trộn các mảng tạm thời lại với nhau
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Sao chép phần còn lại của các mảng tạm thời L[] hoặc R[] vào mảng arr[]
    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Sắp xếp nửa đầu và nửa sau
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Trộn các nửa đã sắp xếp lại với nhau
        merge(arr, l, m, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCount;
    cin >> testCount;

    for (int t = 0; t < testCount; t++)
    {
        int n1, n2;
        int data;
        cin >> n1 >> n2;

        vector<int> arr1;
        vector<int> arr2;

        for (int index1 = 0; index1 < n1; index1++)
        {
            cin >> data;
            arr1.push_back(data);
        }

        for (int index2 = 0; index2 < n2; index2++)
        {
            cin >> data;
            arr2.push_back(data);
        }

        vector<int> mergedArr(n1 + n2);

        // Merge hai mảng đã được sắp xếp
        for (int i = 0; i < n1; ++i)
            mergedArr[i] = arr1[i];
        for (int i = 0; i < n2; ++i)
            mergedArr[n1 + i] = arr2[i];

        mergeSort(mergedArr, 0, n1 + n2 - 1);

        for (int num : mergedArr)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
