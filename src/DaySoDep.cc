#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int minimumStepsToBeautifulArray(vector<int>& A) {
    // Initialize an empty hash table to store the frequency of each element
    unordered_map<int, int> frequency;

    // Calculate the frequency of each element in the array A
    for (int element : A) {
        frequency[element]++;
    }

    // Initialize the counter for minimum steps
    int steps = 0;

    // Iterate through the hash table
    for (auto pair : frequency) {
        int element = pair.first;
        int count = pair.second;

        // Check if the element is not already "beautiful" (count != element)
        if (count != element) {
            // Calculate the difference between the desired frequency and the
            // actual frequency
            int diff = element - count;

            // Update the minimum steps if necessary
            if (diff < 0) {
                steps = 1;
            } else {
                steps = diff;
            }
        }
    }

    return steps;
}

int main() {
    int N;  // Number of elements in the array
    cin >> N;

    vector<int> A(N);  // Array A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int minimumSteps =
        minimumStepsToBeautifulArray(A);  // Calculate minimum steps
    cout << minimumSteps << endl;         // Print the minimum steps

    return 0;
}
