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
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

bool isprime[3163];
vector<int> prime;

vector<pll> facto(ll x) {
    vector<pll> ret;
    for (int i = 0; i < prime.size(); i++) {
        ll pnum = prime[i];
        if (x < pnum * pnum) break;
        if (x % pnum == 0) ret.push_back({ pnum,0 });
        while (x % pnum == 0) {
            x /= pnum;
            ret.back().second += 1;
        }
    }
    if (x != 1) {
        ret.push_back({ x,1 });
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll mod = (int)1e9 + 7;
    fill(isprime, isprime + 3163, true);
    for (int i = 2; i <= 3162; i++) {
        if (!isprime[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j <= 3162; j += i) {
            isprime[j] = false;
        }
    }
    int N;
    cin >> N;
    map<int, int> AB;
    while (N--) {
        ll x, y;
        cin >> x >> y;
        vector<pll> a, b;
        a = facto(y - x);
        b = facto(y);
        for (int i = 0; i < a.size(); i++) {
            AB[a[i].first] += a[i].second;
        }
        for (int i = 0; i < b.size(); i++) {
            AB[b[i].first] -= b[i].second;
        }
    }
    ll A = 1;
    ll B = 1;
    for ( auto iter = AB.begin(); iter != AB.end(); iter++) {
        if (iter->second < 0) {
            for (int i = 0; i < -(iter->second); i++) {
                B = B * (iter->first) % mod;
            }
        }
        else {
            for (int i = 0; i < iter->second; i++) {
                A = A * (iter->first) % mod;
            }
        }
    }
    cout << A << " " << B;
    return 0;
}

