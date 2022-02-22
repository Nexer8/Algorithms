#include <iostream>

using namespace std;

long bpow(long a, long n) {
    long half;
    if (n == 0)
        return 1;
    if (n % 2 == 0) {
        half = bpow(a, n / 2);
        return half * half;
    } else {
        half = bpow(a, (n - 1) / 2);
        return half * half * a;
    }
}

int main() {
    const long a = 3;
    for (int exponent = 0; exponent < 10; exponent++) {
        long result = bpow(a, exponent);
        cout << "a^" << exponent << " = " << result << endl;
    }
}