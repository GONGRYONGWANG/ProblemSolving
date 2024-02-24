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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> crain(N);
    for (int i = 0; i < N; i++) {
        cin >> crain[i];
    }
    sort(crain.begin(), crain.end());
    int M;
    cin >> M;
    vector<int> cargo(M);
    for (int i = 0; i < M; i++) {
        cin >> cargo[i];
    }
    sort(cargo.begin(), cargo.end());
    if (cargo[M-1] > crain[N-1]) {
        cout << -1; return 0;
    }


    vector<int> burden(N);
    int idx = 0;
    for (int i = 0; i < M; i++) {
        while (crain[idx] < cargo[i]) {
            idx++;
        }
        burden[idx] += 1;
    }
    int ans = 0;
    int total = 0;
    for (int i = 1; i <=N; i++) {
        total += burden[N-i];
        ans = max(ans, total / i + !(total % i == 0));
    }
    cout << ans;
    return 0;
}