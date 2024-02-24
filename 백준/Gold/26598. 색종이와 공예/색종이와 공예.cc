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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
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

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}


int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

//////////////////////////////////////////////////////////////////////////////////////


char arr[1000][1000];
bool visited[1000][1000];

void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    } 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char color = arr[i][j];
            if (!visited[i][j]) {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] && arr[nx][ny] == color) {
                        cout << "BaboBabo";
                        return;
                    }
                }
                int jj = j;
                while (jj < M && arr[i][jj] == color) {
                    jj += 1;
                }
                jj -= 1;

                int ii = i;
                while (ii < N && arr[ii][j] == color) {
                    ii += 1;
                }
                ii -= 1;

                for (int iii = ii; iii >= i; iii--) {
                    for (int jjj = jj; jjj >= j; jjj--) {
                        if (visited[iii][jjj]) {
                            cout << "BaboBabo";
                            return;
                        }
                        visited[iii][jjj] = true;
                        if (arr[iii][jjj] != color) {
                            cout << "BaboBabo";
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "dd";
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}