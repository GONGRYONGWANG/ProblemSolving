//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

vector<int> d;
vector<int> pi;
void solve() {
    int M,N;
    cin >> M>>N;
    d.resize(N);
    int x,y;
    cin >> x;
    d[N - 1] = x;
    for (int i = 0; i < N - 1; i++) {
        cin >> y;
        d[i] = y - x;
        x = y;
    }
    d[N - 1] += M - x;
    pi.clear();
    pi.resize(N);
    int j = 0;
    for (int i = 1; i < N; i++) {
        while (j > 0 && d[i] != d[j]) {
            j = pi[j - 1];
        }
        if (d[i] == d[j]) {
            j++;
            pi[i] = j;
        }
    }


    if (N % (N - pi[N - 1])) {
        cout << M;
    }
    else {
        int rt = 0;
        for (int i = 0; i < N - pi[N - 1]; i++) {
            rt += d[i];
        }
        cout << rt;
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) { solve(); }
    return 0;
}