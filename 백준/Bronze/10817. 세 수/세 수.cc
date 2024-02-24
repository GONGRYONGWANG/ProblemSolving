#include<iostream>
using namespace std;

void swap(int& a, int& b);

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A > B) { swap(A, B); }
    if (B > C) { swap(B, C); }
    if (A > B) { swap(A, B); }
    cout << B;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}