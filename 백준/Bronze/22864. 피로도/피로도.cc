//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int A, B, C, M;
    cin >> A >> B >> C >> M;
    int ans = 0;
    int fatigue = 0;
    for (int i = 0; i < 24; i++) {
        if (fatigue + A <= M) {
            fatigue += A;
            ans += B;
        }
        else fatigue -= C;
        if (fatigue < 0) fatigue = 0;
    }
    cout << ans;
    return 0;
}