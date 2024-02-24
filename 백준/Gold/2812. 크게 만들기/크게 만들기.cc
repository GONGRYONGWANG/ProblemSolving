//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<char> v;
    v.push_back('9');
    for (int i = 0; i < N; i++) {
        char x;
        cin >> x;
        while (K && x > v.back()) {
            v.pop_back();
            K -= 1;
        }
        v.push_back(x);
    }
    while (K) {
        v.pop_back();
        K -= 1;
    }
    for (int i = 1; i < v.size(); i++) {
        cout << v[i];
    }
    return 0;
}