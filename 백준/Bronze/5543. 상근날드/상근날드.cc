#include<iostream>
using namespace std;

int main() {
    int H1, H2, H3;
    int D1, D2;
    cin >> H1 >> H2 >> H3 >> D1 >> D2;
    if (H1 > H2) { H1 = H2; }
    if (H1 > H3) { H1 = H3; }
    if (D1 > D2) { D1 = D2; }
    cout << H1 + D1 - 50;
}