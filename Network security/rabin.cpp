#include <iostream>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        exp >>= 1;
        base = base * base % mod;
    }
    return result;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    long long p, q;
    cout << "Enter prime p (p % 4 == 3): ";
    cin >> p;
    cout << "Enter prime q (q % 4 == 3): ";
    cin >> q;

    long long n = p * q;
    cout << "Public Key n = " << n << endl;

    long long M;
    cout << "Enter message M (0 <= M < " << n << "): ";
    cin >> M;

    // Encryption
    long long C = (M * M) % n;
    cout << "Encrypted Output (C): " << C << endl;

    // Square roots modulo p and q
    long long r = power(C, (p + 1) / 4, p);
    long long s = power(C, (q + 1) / 4, q);

    // Extended Euclidean Algorithm
    long long a, b;
    extGCD(p, q, a, b);

    // Normalize coefficients modulo n
    a = (a % n + n) % n;
    b = (b % n + n) % n;

    // Combine roots using CRT
    long long x = ( (a * p % n) * s % n + (b * q % n) * r % n ) % n;
    long long y = ( ( (a * p % n) * s % n - (b * q % n) * r % n ) % n + n ) % n;

    cout << "\nFour possible plaintexts:" << endl;
    cout << x << ", " << (n - x) % n << ", " << y << ", " << (n - y) % n << endl;

    return 0;
}
