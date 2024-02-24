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

string debug = "ans: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

//////////////////////////////////////////////////////////////////////////////////////

list<pii> q[1000001];
int DP[1000001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


    int mod = 1000000007;

    int N;
    cin >> N;
    DP[0] = 1;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        int idx = it - v.begin() + 1;
        while (!q[idx - 1].empty() && q[idx - 1].front().first >= x) {
            DP[idx - 1] += mod;
            DP[idx - 1] -= q[idx - 1].front().second;
            DP[idx - 1] %= mod;
            q[idx - 1].pop_front();
        }
        q[idx].push_back({ x,DP[idx - 1] });
        DP[idx] += DP[idx - 1];
        DP[idx] %= mod;
        if (it == v.end()) {
            v.push_back(x);
        }
        else {
            *it = x;
        }
    }
    cout << v.size() << " " << DP[v.size()];
    return 0;
}