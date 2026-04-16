#include <iostream>
#include <cmath>

using namespace std;




int main() {

    int PrimeNumbers[1001];

    for (int i = 1; i < 1001; i++) {
        PrimeNumbers[i] = 1;
    }
    PrimeNumbers[1] = 0;
    int tmp;
    for (int i = 2; i < 1001; i++) {
        tmp = i;
        while (1) {
            tmp += i;
            if (tmp > 1000) { break; }
            PrimeNumbers[tmp] = 0;
        }
    }

    
    int N;
    cin >> N;
    int NOP=0;
    int A;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (PrimeNumbers[A]) NOP++;
    }
    cout << NOP<<"\n";
}
