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


int slot[50];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    int l = 1;
    int r = N;

    for (int i = 0; i < K; i++) {
        cin >> slot[i];
    }
    while (l <= r) {
        int m = (l + r) / 2;
        int ret = 0;
        int e = 0;
        for (int i = 0; i < K; i++) {
            if (slot[i] >= e) {
                e = slot[i] + m;
                ret += 1;
            }
        }
        if (ret < M) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    int e = 0;
    int cnt = 0;
    for (int i = 0; i < K; i++) {
        if (cnt!=M && slot[i] >= e) {
            e = slot[i] + r;
            cout << 1;
            cnt += 1;
        }
        else cout << 0;
    }

    return 0;
}