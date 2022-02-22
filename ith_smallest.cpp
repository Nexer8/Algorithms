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

int ithSmallest(vector<int> &vec, int low, int high, int i) {
    if (low == high) {
        return vec[low];
    } else if (low < high) {
        int pi = partition(vec, low, high);
        int k = pi - low + 1;

        if (i == k) {
            return vec[pi];
        } else if (i < k) {
            return ithSmallest(vec, low, pi - 1, i);
        } else {
            return ithSmallest(vec, pi + 1, high, i - k);
        }
    } else {
        return -1;
    }
}

int main() {
    vector<int> numbers = {6, 10, 13, 5, 8, 3, 2, 11};

    for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
        int idx = i + 1;
        int ith_smallest = ithSmallest(numbers, 0, static_cast<int>(numbers.size()) - 1, idx);
        cout << idx << ". smallest element is: " << ith_smallest << endl;
    }

    return 0;
}