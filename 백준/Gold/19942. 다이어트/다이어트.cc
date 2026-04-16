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
#include<complex> // complex
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
const int inf = 1e9;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

vector<int> arr[16];
vector<int> ansv;
vector<int> curv;
vector<int> thrs(4);
vector<int> cur(4);
int mn;
int ret;

int N;

void bf(int x) {
    if (x > N) return;

    curv.push_back(x);
    for (int i = 0; i < 4; i++) {
        cur[i] += arr[x][i];
    }
    ret += arr[x][4];

    bool b = 1;
    for (int i = 0; i < 4; i++) {
        if (cur[i] < thrs[i]) b = 0;
    }
    if (b) {
        if (ret < mn) {
            ansv = curv;
            mn = ret;
        }
    }
    else {
        bf(x + 1);
    }

    curv.pop_back();
    for (int i = 0; i < 4; i++) {
        cur[i] -= arr[x][i];
    }
    ret -= arr[x][4];

    bf(x + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int mp, mf, ms, mv;
    cin >> mp >> mf >> ms >> mv;
    thrs = { mp,mf,ms,mv };
    for (int i = 1; i <= N; i++) {
        int p, f, s, v, c;
        cin >> p >> f >> s >> v >> c;
        arr[i] = { p, f,s,v,c };
    }
    mn = inf;
    ret = 0;
    bf(1);
    if (mn == inf) {
        cout << -1;
        return 0;
    }
    cout << mn << endl;
    for (int i = 0; i < ansv.size(); i++) {
        cout << ansv[i] << " ";
    }
    return 0;
}