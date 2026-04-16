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

int N, M;
int complete;
int arr[10];
int bf(int idx, int team) {
    if (team == complete) {
        return 0;
    }
    if (idx == M) return inf;
    return min(bf(idx + 1, team | arr[idx]) + 1, bf(idx + 1, team));
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> N >> M;
    complete = 0;
    for (int i = 0; i < M; i++) {
        int o;
        cin >> o;
        for (int j = 0; j < o; j++) {
            int x;
            cin >> x;
            x -= 1;
            arr[i] += (1 << x);
            complete |= arr[i];
        }
    }
    if (complete != (1 << N) - 1) {
        cout << -1;
        return 0;
    }
    cout<< bf(0, 0);

    return 0;
}