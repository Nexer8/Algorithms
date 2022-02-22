#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

bool isProbablyPrime;

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

int gcdExtended(int a, int b, int *x, int *y) {
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;// To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// modular multiplicative inverse taken from geeksforgeeks.com
int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else {
        // m is added to handle negative x
        int res = (x % m + m) % m;
        return res;
    }
}

void rsa() {
    const int max = 500;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(2, max);

    int p = dist(rng);
    while (!isPrimeRandomized2(p)) {
        p = dist(rng);
    }

    int q = dist(rng);
    while (!isPrimeRandomized2(q) || q == p) {
        q = dist(rng);
    }

    double n = static_cast<double>(p) * static_cast<double>(q);

    double totient = static_cast<double>(p - 1) * static_cast<double>(q - 1);

    double e = 7;
    while (e < totient) {
        if (gcd(static_cast<int>(e), static_cast<int>(totient)) == 1) {
            break;
        } else {
            e++;
        }
    }

    double d = fmod(1.0 / e, totient);

    double msg = dist(rng);

    // Encryption c = (msg ^ e) % n
    // Decryption m = (c ^ d) % n
    double c = pow(msg, e);
    double m = pow(c, d);
    c = fmod(c, n);
    m = fmod(m, n);

    cout << "Original Message: " << msg << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "n: " << n << endl;
    cout << "totient: " << totient << endl;
    cout << "e: " << e << endl;
    cout << "d: " << d << endl;
    cout << "Encrypted message: " << c << endl;
    cout << "Decrypted message: " << m << endl;
}

int main() {
    rsa();

    return 0;
}
