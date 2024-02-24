#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    ll mod = 1000000007;
    while (T--) {
        int N;
        cin >> N;
        ll ans = 1;
        pq<ll, vector<ll>, greater<ll>> q;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            q.push(x);
        }
        while (q.size() != 1) {
            ll a = q.top();
            q.pop();
            ll b = q.top();
            q.pop();
            q.push(a * b);
            a %= mod;
            b %= mod;
            ans = ans * ((a * b) % mod) % mod;
        }
        cout << ans << endl;
    }



    return 0;
}