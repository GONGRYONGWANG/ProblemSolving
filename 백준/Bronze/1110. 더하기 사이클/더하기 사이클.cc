#include<iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a, b;
    b = N % 10;
    a = N / 10;
    int tmp;
    int cycle = 0;
    while (1) {
        cycle++;
        tmp = a;
        a = b;
        b = (tmp + b) % 10;
        if (10 * a + b == N) { break; }
    }
    cout << cycle;
}
