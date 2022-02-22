#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

bool isProbablyPrime;

bool isPrimeNaive(int number) {
    if (number < 2) {
        return false;
    }
    if (number == 2) {
        return true;
    }
    if (number % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= sqrt(number) / 2.0; i++) {
        if (number % (2 * i + 1) == 0) {
            return false;
        }
    }
    return true;
}

/* computes a^p mod n and checks during the computation 
whether there is an x with x^2 mod n = 1 and x != 1, n-1 */
int power(int a, int p, int n) {
    if (p == 0) {
        return 1;
    }

    int x = power(a, p / 2, n);
    int result = (x * x) % n;

    /* Check whether x^2 mod n = 1 and x!= 1, n-1 */
    if ((result == 1) && (x != 1) && (x != n - 1)) {
        isProbablyPrime = false;
    }

    if (p % 2 == 1) {
        result = (a * result) % n;
    }

    return result;
}

/* executes the randomized primality test for a chosen at random */
bool isPrimeRandomized2(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    }

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(2, n - 1);

    int a = dist(rng);
    isProbablyPrime = true;

    int result = power(a, n - 1, n);

    if (result != 1 || !isProbablyPrime) {
        return false;
    } else {
        return true;
    }
}

int main() {
    vector<int> numbers = {1, 3, 17, 4, 8};

    cout << "Naive method" << endl;
    for (const auto &number : numbers) {
        if (isPrimeNaive(number)) {
            cout << "Number: " << number << " is a prime number." << endl;
        } else {
            cout << "Number: " << number << " is not a prime number." << endl;
        }
    }

    cout << endl;

    cout << "Randomized2 method" << endl;
    for (const auto &number : numbers) {
        if (isPrimeRandomized2(number)) {
            cout << "Number: " << number << " is a prime number." << endl;
        } else {
            cout << "Number: " << number << " is not a prime number." << endl;
        }
    }

    return 0;
}
