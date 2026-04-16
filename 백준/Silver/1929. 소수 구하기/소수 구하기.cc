#include <iostream>
#include <math.h>

using namespace std;


bool isPrime(int A);

int main() {

    int M, N;
    cin >> M >> N;
    for (int i = M; i < N + 1; i++) {
        if (isPrime(i)) { cout << i << "\n"; }
    }
}

bool isPrime(int A) {
    if (A == 1) { return 0; }
    for (int i = 2; i <= (int)sqrt(A); i++) {
        if (A % i == 0) { return 0; }
    }
    return 1;
}