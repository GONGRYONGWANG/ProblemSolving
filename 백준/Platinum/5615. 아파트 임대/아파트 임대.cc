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

ull prime[12] = { 2,3,5,7,11,13,17,19,23,29,31, 37 };


ull fastpow(ull x, ull y, ull mod) {
    if (y == 0) return 1;
    if (y % 2) return fastpow(x, y - 1, mod) * x % mod;
    ll half = fastpow(x, y / 2, mod);
    return half * half % mod;
}

bool mr(ull n, ull p) {
    if (n % p == 0) return 1;
    ull d = n - 1;
    while (d % 2 == 0) d /= 2;
    ull tmp = fastpow(p, d, n);
    if (tmp == 1 || tmp == n - 1) return 1;
    while (d * 2 < n - 1) {
        d *= 2;
        tmp = tmp * tmp % n;
        if (tmp == n - 1) return 1;
    }
    return 0;
}

bool isprime(ull n) {
    if (n % 2 == 0) return 0;
    for (int i = 0; i < 12; i++) {
        if (n == prime[i]) return 1;
        if(!mr(n,prime[i])) return 0;
    }
    return 1;
}



int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    int ans = 0;
    while (N--) {
        ull x;
        cin >> x;
        if (isprime(2*x+1)) ans += 1;
    }
    cout << ans;

    return 0;
}