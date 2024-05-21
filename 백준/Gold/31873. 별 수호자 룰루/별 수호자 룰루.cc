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
#include<bitset>
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

const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

const string debug = "output: ";

struct VectorHasher {
    int operator()(const vector<int>& V) const {
        int hash = V.size();
        for (auto& i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

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

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}

ll modinv(ll x, ll mod) {
    return powmod(x, mod - 2, mod);
}

ll factorial(ll x) {
    ll ret = 1;
    // ret = F[x];
    return ret;
}

ll combination(ll n, ll r, ll mod) {
    return factorial(n) * modinv(factorial(n - r), mod) % mod * modinv(factorial(r), mod) % mod;
}

//int dx[4] = { 0,1,0,-1};
//int dy[4] = { 1,0,-1,0 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////




void solve() {
    int N, K;
    cin >> N >> K;
    if (K % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < N / K; i++) {
            for (int j = 1; j <= K; j++) {
                cout << i * K + j << " ";
            }
            cout << endl;
        }
        return;
    }
    if (N == K || K==1) {
        cout << "NO";
        return;
    }

    cout << "YES" << endl;

    if (N / K % 2 == 0) {
        for (int i = 0; i < N / K; i++) {
            if (i % 2) {
                cout << i * K + 1 << " " << (i - 1) * K + 1 << " ";
                for (int j = 3; j <= K; j++) {
                    cout << i * K + j << " ";
                }
            }
            else {
                cout << (i + 1) * K + 2 << " ";
                for (int j = 2; j <= K; j++) {
                    cout << i * K + j << " ";
                }
            }
            cout << endl;
        }
    }
    else {
        cout << K + 2 << " ";
        for (int j = 2; j <= K; j++) {
            cout << j << " ";
        }
        cout << endl;
        cout << K + 1 << " " << 2 * K + 3 << " ";
        for (int j = 3; j <= K; j++ ) {
            cout << K + j << " ";
        }
        cout << endl;
        cout << 2 * K + 1 << " " << 2 * K + 2 << " " << 1 << " ";
        for (int j = 4; j <= K; j++) {
            cout << 2 * K + j << " ";
        }
        cout << endl;
        for (int i = 3; i < N / K; i++) {
            if (i % 2) {
                cout << i * K + 1 << " " << (i + 1) * K + 1 << " ";
                for (int j = 3; j <= K; j++) {
                    cout << i * K + j << " ";
                }
            }
            else {
                cout << (i - 1) * K + 2 << " ";
                for (int j = 2; j <= K; j++) {
                    cout << i * K + j << " ";
                }
            }
            cout << endl;
        }
    }


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
