#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void printvector(vector<int> v);

int Fibo[50][2] = { {1,0},{0,1}, };

vector<int> Fibonacci(int N){
    vector<int> result(2);
    result.push_back(0);
    result.push_back(0);
    if (N == 0) {
        result[0] += 1;
        return result;
    }
    if (N == 1) {
        result[1] += 1;
        return result;
    }
    if (Fibo[N][0] == 0 && Fibo[N][1]==0) {
        Fibo[N][0] = Fibonacci(N - 1)[0] + Fibonacci(N - 2)[0];
        Fibo[N][1] = Fibonacci(N - 1)[1] + Fibonacci(N - 2)[1];
    }
    result[0] += Fibo[N][0];
    result[1] += Fibo[N][1];
    return result;
}

int main() {
    int T;
    cin >> T;
    int N;
    for (int i = 0; i < T; i++) {
        cin >> N;
        printvector(Fibonacci(N));
    }
}

void printvector(vector<int> v) {
    cout << v[0] << " " << v[1] << "\n";
}