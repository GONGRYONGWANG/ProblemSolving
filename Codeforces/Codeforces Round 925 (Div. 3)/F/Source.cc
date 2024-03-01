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


void solve() {
    
    int N, K;
    cin >> N >> K;
    if (N == 1) {
        int x;
        cin >> x;
        cout << "yes" << endl;
        return;
    }
    vector<ll> arr(N+1);
    ll x;
    cin >> x;
    arr[x] = 0;
    for (int i = 1; i < N; i++) {
        cin >> x;
        arr[x] = i * 2;
    }
    K -= 1;
    bool ans = true;
    while(K--) {
        cin >> x;
        cin >> x;
        if (arr[x] == 0) arr[x] = 2;
        ll prv = arr[x];
        for (int i = 2; i < N; i++) {
            cin >> x;
            if (arr[x] == 0) {
                arr[x] = prv + 2;
            }
            if (arr[x] == prv) {
                arr[x] += 1;
            }
            if (arr[x] < prv) {
                ans = false;
            }
            prv = arr[x];
        }
    }
    if (ans) cout << "yes" << endl;
    else cout << "no" << endl;

}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
