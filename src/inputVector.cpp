#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size, data;
    cin >> size;

    vector<int> arr;

    for (int i = 0; i < size; i++)
    {
        cin >> data;
        arr.push_back(data);
    }

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}