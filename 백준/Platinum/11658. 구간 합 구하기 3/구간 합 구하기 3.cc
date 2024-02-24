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


int psum[1025][1025];
int arr[1025][1025];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        psum[i][0] = 0;
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            psum[i][j] = arr[i][j] + psum[i][j - 1];
        }
    }

    while (M--) {
        bool w;
        cin >> w;
        if (!w) {
            int x, y, c;
            cin >> x >> y >> c;
            c = c - arr[x][y];
            for (int i = y; i <= N; i++) {
                psum[x][i] += c;
            }
            arr[x][y] += c;
        }
        else {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int ret = 0;
            for (int i = x1; i <= x2; i++) {
                ret += psum[i][y2] - psum[i][y1 - 1];
            }
            cout << ret << endl;
        }
    }

    return 0;
}