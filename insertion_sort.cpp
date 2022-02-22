#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec) {
    for (const auto &element: vec) {
        cout << element << '\t';
    }
    cout << endl;
}

void insertionSort(vector<int> &vec) {
    int i, key, j;
    for (i = 1; i < vec.size(); i++) {
        key = vec[i];
        j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

int main() {
    vector<int> numbers = {5, 4, 3, 2, 1};
    insertionSort(numbers);

    printVector(numbers);

    return 0;
}