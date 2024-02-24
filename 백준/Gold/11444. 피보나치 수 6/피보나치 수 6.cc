#pragma warning(disable:4996) 
#include<iostream>
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
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
#define pb push_back
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

ll mod = 1000000007;
unordered_map<ll, ll> F;

ll f(ll x) {
    if (F.count(x)) return F[x];
    ll n = (x-1) / 2;
    if (x % 2) {
        return F[x] = (f(n + 1) * f(n + 1) + f(n) * f(n)) % mod;
    }
    n = x / 2;
    return F[x]=f(n) * (2 * f(n - 1) + f(n)) % mod;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll N;
    cin >> N;
    F[0] = 0;
    F[1] = 1;
    F[2] = 1;
    cout << f(N);
    return 0;
}