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


int A[102];
int B[102];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    int a, b;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        A[a] += 1;
        B[b] += 1;
        a = 0; b = 101;
        int cnt = i;
        int acnt = 0; int bcnt = 0;
        int ans = 0;
        while (cnt) {
            while (acnt == 0) {
                a++;
                acnt = A[a];
            }
            while (bcnt == 0) {
                b--;
                bcnt = B[b];
            }
            ans = max(ans, a + b);
            if (acnt > bcnt) {
                cnt -= bcnt;
                acnt -= bcnt;
                bcnt = 0;
            }
            else if (acnt == bcnt) {
                cnt -= bcnt;
                acnt = bcnt = 0;
            }
            else {
                cnt -= acnt;
                bcnt -= acnt;
                acnt = 0;
            }
        }
        cout << ans<<endl;
    }
    return 0;
}
// #2923