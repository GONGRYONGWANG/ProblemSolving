#include <iostream>
#include <math.h>

using namespace std;


bool isPrime(int A);

int main() {
    int n;
    int NOP;
    while (cin >> n && n != 0) {
        NOP = 0;
        for (int i = n+1; i <= 2*n; i++) {
            if (isPrime(i)) { NOP++; }
        }
        cout << NOP << "\n";
    }
}

bool isPrime(int A) {
    if (A == 1) { return 0; }
    for (int i = 2; i <= (int)sqrt(A); i++) {
        if (A % i == 0) { return 0; }
    }
    return 1;
}