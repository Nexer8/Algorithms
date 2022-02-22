#include <iostream>
#include <vector>

using namespace std;

int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base;
    }

    int half = power(base, exp / 2);
    int result = half * half * power(base, exp % 2);

    return result;
}

int main() {
    vector<int> numbers = {1, 3, 17, 4, 8};

    for (const auto &number : numbers) {
        cout << number << "^4 = " << power(number, 4) << endl;
        cout << number << "^3 = " << power(number, 3) << endl;
        cout << number << "^7 = " << power(number, 7) << endl;
        cout << endl;
    }

    return 0;
}
