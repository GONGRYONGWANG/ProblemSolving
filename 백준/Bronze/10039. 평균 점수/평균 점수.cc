#include<iostream>
using namespace std;

int main() {
    int total = 0;
    int a;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        if (a < 40) { a = 40; }
        total += a;
    }
    cout << total / 5;
}
