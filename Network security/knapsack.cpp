#include <iostream>
#include <vector>
using namespace std;

long long modInverse(long long t, long long m) {
    long long t0 = 0, t1 = 1, r0 = m, r1 = t;
    while (r1 != 0) {
        long long q = r0 / r1;
        t0 = t0 - q * t1; swap(t0, t1);
        r0 = r0 - q * r1; swap(r0, r1);
    }
    if (t0 < 0) t0 = (t0 % m + m) % m; // safe normalization
    return t0;
}

int main() {
    // Superincreasing private key
    vector<long long> W = {2, 3, 7, 14, 30, 57, 120, 251};
    int n = W.size();

    long long m = 491; // m > sum(W)
    long long t = 41;  // gcd(t, m) = 1

    // Generate public key
    vector<long long> B(n);
    for (int i = 0; i < n; i++)
        B[i] = (t * W[i]) % m;

    cout << "Public Key B: ";
    for (long long b : B) cout << b << " ";
    cout << endl;

    // Plaintext as binary string
    string plaintext;
    cout << "Enter plaintext bits (8 bits, e.g. 11001010): ";
    cin >> plaintext;
    if (plaintext.size() != n) {
        cout << "Error: plaintext must be exactly " << n << " bits." << endl;
        return 1;
    }

    // Encryption
    long long C = 0;
    for (int i = 0; i < n; i++)
        if (plaintext[i] == '1') C += B[i];

    cout << "Encrypted Output: " << C << endl;

    // Decryption
    long long invT = modInverse(t, m);
    long long Cprime = (invT * C) % m;
    cout << "C' (after multiplying by inverse): " << Cprime << endl;

    string recovered = "";
    for (int i = n - 1; i >= 0; i--) {
        if (Cprime >= W[i]) {
            recovered = "1" + recovered;
            Cprime -= W[i];
        } else {
            recovered = "0" + recovered;
        }
    }

    cout << "Decrypted Output: " << recovered << endl;

    return 0;
}
