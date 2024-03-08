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

string debug = "output: ";

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ll  n = a % b;
        a = b;
        b = n;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

/*
int COMB[100][100];
int comb(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;
    if (COMB[n][r]) return COMB[n][r];
    return COMB[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}
*/

//////////////////////////////////////////////////////////////////////////////////////

int tree[4000000];

void add(int node, int start, int end, int target, int val) {
    if (target > end || target < start) return;
    if (start == end) {
        tree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    add(node * 2, start, mid, target, val);
    add(node * 2 + 1, mid + 1, end, target, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int get(int node, int start, int end, int k) {
    tree[node] -= 1;
    if (start == end) {
        return start;
    }
    int mid = (start + end) / 2;
    if (tree[node * 2] >= k) {
        return get(node * 2, start, mid, k);
    }
    else {
        return get(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
    }
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A;
        if (A == 1) {
            cin >> B;
            cout << get(1, 1, 1000000, B) << endl;
        }
        else {
            cin >> B >> C;
            add(1, 1, 1000000, B, C);
        }

    }

}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }

    return 0;
}