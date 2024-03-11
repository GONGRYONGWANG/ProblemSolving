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


void solve() {

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(M);
    vector<bool> type(M);

    set<int> st;
    for (int i = 1; i <= 2 * N; i++) {
        st.insert(i);
    }

    for (int i = 0; i < M; i++) {
        char x;
        cin >> x;
        type[i] = (x =='A');
        string block;
        cin >> block;
        int d;
        cin >> d;
        arr[i].push_back(d);
        st.erase(st.find(d));
    }
    if (st.count(1)) {
        cout << "NO";
        return;
    }

    type.push_back(type[0]);


    for (int i = 0; i < M; i++) {
        if (type[i] == type[i + 1]) {
            auto it = st.upper_bound(arr[i][0]);
            if ( it == st.end()) {
                cout << "NO";
                return;
            }
            arr[i].push_back(*it);
            st.erase(it);
        }
    }

    cout << "YES" << endl;

    for (int i = 0; i < M; i++) {
        if (arr[i][0] == 1) {
            for (auto iter = st.begin(); iter != st.end(); iter++) {
                arr[i].push_back(*iter);
            }
        }

        bool t = type[i];
        for (int j = 0; j < arr[i].size(); j++) {
            if (t) {
                cout << "A ";
            }
            else cout << "B ";

            if (j == 0) {
                cout << "BLOCK ";
            }
            else cout << "CHAIN ";

            cout << arr[i][j] << endl;
            t = !t;
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