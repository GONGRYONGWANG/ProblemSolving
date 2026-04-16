#include<iostream>
using namespace std;

void printstar(int i);

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        printstar(i);
    }
    for (int i = N - 1; i > 0; i--) {
        printstar(i);
    }
}


void printstar(int i) {
    for (int k = 0; k < i; k++) {
        cout << "*";
    }
    cout << "\n";
}