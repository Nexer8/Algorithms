#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

#define TEN 10

void printVector(const vector<int> &vec) {
    for (const auto &element : vec) {
        cout << element << '\t';
    }
    cout << endl;
}

void countingSort(vector<int> &vec, int divisor) {
    static const int no_of_digits = 10;
    vector<int> aux(vec.size());
    vector<int> counts(no_of_digits);

    for (const auto &elem : vec) {
        counts[(elem / divisor) % TEN]++;
    }

    for (size_t i = 1; i < counts.size(); i++) {
        counts[i] += counts[i - 1];
    }

    for (const auto &elem : vec | views::reverse) {
        aux[counts[(elem / divisor) % TEN] - 1] = elem;
        counts[(elem / divisor) % TEN]--;
    }

    vec = aux;
}

void radixSort(vector<int> &vec) {
    int max = *max_element(vec.begin(), vec.end());

    for (int divisor = 1; max / divisor > 0; divisor *= TEN) {
        countingSort(vec, divisor);
    }
}

int main() {
    vector<int> numbers = {53, 423, 415, 122, 235, 312, 23, 1};
    radixSort(numbers);

    printVector(numbers);

    return 0;
}
