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

void mergeSort(vector<int> &vec) {
    if (vec.size() == 1) return;

    vector<int> v1;
    vector<int> v2;

    for (size_t i = 0; i < vec.size() / 2; i++) {
        v1.push_back(vec[i]);
    }

    for (size_t i = vec.size() / 2; i < vec.size(); i++) {
        v2.push_back(vec[i]);
    }

    mergeSort(v1);
    mergeSort(v2);

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vec.begin());
}

int main() {
    vector<int> numbers = {5, 4, 3, 2, 1};
    mergeSort(numbers);

    printVector(numbers);

    return 0;
}