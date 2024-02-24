#include <iostream>
using namespace std;

int Hanoi(int N);
void printMoves(int N , int start, int end);

int main() {
    int N;
    cin >> N;
    cout << Hanoi(N) << "\n";
    printMoves(N, 1, 3);
}

int Hanoi(int N) {
    if (N == 1) { return 1; }
    return 2 * Hanoi(N - 1) + 1;
}

void printMoves(int N, int start, int end) {

    if (N == 1) {
        cout << start << " " << end << "\n";
        return;
    }

    int tmp;
    if (start != 1 && end != 1) { tmp = 1; }
    else if (start != 2 && end != 2) { tmp = 2; }
    else { tmp = 3; }
    printMoves(N - 1, start, tmp);
    cout << start << " " << end << "\n";
    printMoves(N - 1, tmp, end);
    return;

}