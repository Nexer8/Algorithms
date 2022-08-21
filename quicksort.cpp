#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec) {
    for (const auto &element : vec) {
        cout << element << '\t';
    }
    cout << endl;
}

int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i], vec[low]);
    return i;
}

void quickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {
    vector<int> numbers = {6, 10, 13, 5, 8, 3, 2, 11};
    quickSort(numbers, 0, static_cast<int>(numbers.size()) - 1);

    printVector(numbers);

    return 0;
}
