#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec) {
    for (const auto &element : vec) {
        cout << element << '\t';
    }
    cout << endl;
}

void countingSort(vector<int> &vec) {
    int max = *max_element(vec.begin(), vec.end());
    vector<int> aux(vec.size());
    vector<int> counts(max);

    for (const auto &elem : vec) {
        counts[elem]++;
    }

    for (size_t i = 1; i < counts.size(); i++) {
        counts[i] += counts[i - 1];
    }

    for (const auto &elem : vec | views::reverse) {
        aux[counts[elem] - 1] = elem;
        counts[elem]--;
    }

    vec = aux;
}

int main() {
    vector<int> numbers = {5, 4, 4, 12, 235, 3, 2, 1};
    countingSort(numbers);

    printVector(numbers);

    return 0;
}
