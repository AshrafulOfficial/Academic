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

long long modInverse(long long a, long long m) {
    long long t = 0, newT = 1, r = m, newR = a;
    while (newR != 0) {
        long long q = r / newR;
        t = t - q * newT; swap(t, newT);
        r = r - q * newR; swap(r, newR);
    }
    if (t < 0) t = (t % m + m) % m; // safe normalization
    return t;
}

int main() {
    // Simplified DSA parameters (small values for demonstration)
    long long p = 23, q = 11, g = 4;
    long long x = 6; // Private key
    long long y = power(g, x, p); // Public key

    cout << "DSA Parameters:" << endl;
    cout << "p = " << p << ", q = " << q << ", g = " << g << endl;
    cout << "Private Key x = " << x << endl;
    cout << "Public Key y = " << y << endl;

    long long H = 9; // Hash of the message (simplified)
    long long k = 7; // Random per-signature value

    // Signing
    long long r = power(g, k, p) % q;
    long long kInv = modInverse(k, q);
    long long s = (kInv * (H + x * r)) % q;

    cout << "\nMessage Hash H = " << H << endl;
    cout << "Signature: (r = " << r << ", s = " << s << ")" << endl;

    // Verification
    long long w = modInverse(s, q);
    long long u1 = (H * w) % q;
    long long u2 = (r * w) % q;
    long long v = (power(g, u1, p) * power(y, u2, p)) % p % q;

    cout << "\nVerification steps:" << endl;
    cout << "w = " << w << ", u1 = " << u1 << ", u2 = " << u2 << endl;
    cout << "Verification value v = " << v << endl;

    if (v == r)
        cout << "Signature is VALID." << endl;
    else
        cout << "Signature is INVALID." << endl;

    return 0;
}
