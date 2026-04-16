#include <iostream>
#include <cmath>

using namespace std;




int main() {

    int PrimeNumbers[10001];

    for (int i = 1; i < 10001; i++) {
        PrimeNumbers[i] = 1;
    }
    PrimeNumbers[1] = 0;
    int tmp;
    for (int i = 2; i < 10001; i++) {
        tmp = i;
        while (1) {
            tmp += i;
            if (tmp > 10000) { break; }
            PrimeNumbers[tmp] = 0;
        }
    }

    
    int M, N;
    cin >> M >>N;
    int total = 0;
    int min;
    for (int i = N; i >=M; i--) {
        if (PrimeNumbers[i]) {
            total += i;
            min = i;
        }
    }
    if (total == 0) { cout << -1; return 0; }
    cout << total<<"\n"<<min;
}