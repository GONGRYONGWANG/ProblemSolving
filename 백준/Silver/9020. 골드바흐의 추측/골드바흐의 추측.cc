#include <iostream>
#include <math.h>

using namespace std;

void GP(int n);

bool isPrime(int A);

int main() {
    int T;
    cin >> T;
    int n;
    for (int i = 0; i < T; i++) {
        cin >> n;
        GP(n);
    }
}

bool isPrime(int A) {
    if (A == 1) { return 0; }
    for (int i = 2; i <= (int)sqrt(A); i++) {
        if (A % i == 0) { return 0; }
    }
    return 1;
}

void GP(int n) {
    for (int i = n / 2; i > 1; i--) {
        if (isPrime(i) && isPrime(n - i)) {
            cout << i << " " << n - i << "\n";
            return;
        }
    }
}