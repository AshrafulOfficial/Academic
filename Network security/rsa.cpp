#include <iostream>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base % mod;
        exp /= 2;
        base = base * base % mod;
    }
    return result;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long modInverse(long long e, long long phi) {
    long long t = 0, newT = 1, r = phi, newR = e;
    while (newR != 0) {
        long long q = r / newR;
        t = t - q * newT; swap(t, newT);
        r = r - q * newR; swap(r, newR);
    }
    if (t < 0) t = (t % phi + phi) % phi; // safe normalization
    return t;
}

int main() {
    long long p, q;
    cout << "Enter prime p: ";
    cin >> p;
    cout << "Enter prime q: ";
    cin >> q;

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e = 2;
    while (e < phi && gcd(e, phi) != 1) e++;

    long long d = modInverse(e, phi);

    cout << "\nPublic Key: (" << e << ", " << n << ")" << endl;
    cout << "Private Key: (" << d << ", " << n << ")" << endl;

    long long M;
    cout << "Enter message (integer < " << n << "): ";
    cin >> M;

    long long C = power(M, e, n);
    long long decrypted = power(C, d, n);

    cout << "Encrypted Output: " << C << endl;
    cout << "Decrypted Output: " << decrypted << endl;

    return 0;
}
