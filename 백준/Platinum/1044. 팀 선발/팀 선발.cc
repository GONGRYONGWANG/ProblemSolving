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

ll arr[2][36];
map<ll, string> l[19];
map<ll, string> r[19];
int N;


void makeL(int idx, int cnt, ll val, string s) {
    if (idx == N / 2) {
        if (l[cnt].count(val)) {
            l[cnt][val] = min(l[cnt][val], s);
        }
        else l[cnt][val] = s;
        return;
    }
    makeL(idx + 1, cnt + 1, val + arr[0][idx], s + '1');
    makeL(idx + 1, cnt, val - arr[1][idx], s + '2');
}

void makeR(int idx, int cnt, ll val, string s) {
    if (idx == N) {
        if (r[cnt].count(val)) {
            r[cnt][val] = min(r[cnt][val], s);
        }
        else r[cnt][val] = s;
        return;
    }
    makeR(idx + 1, cnt + 1, val + arr[0][idx], s + '1');
    makeR(idx + 1, cnt, val - arr[1][idx], s + '2');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    cin >> N;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    makeL(0, 0, 0, "");
    makeR(N / 2, 0, 0, "");
    for (int i = 0; i <= N / 2; i++) {
        r[i].insert({ INF,"" });
        r[i].insert({ -INF,"" });
    }

    ll ans = INF;
    string outs;


    for (int i = 0; i <= N / 2; i++) {
        for (auto lit = l[i].begin(); lit != l[i].end(); lit++) {
            auto rit = r[N / 2 - i].lower_bound(-(*lit).first);
            if (abs((*rit).first + (*lit).first) < ans) {
                ans = abs((*rit).first + (*lit).first);
                outs = (*lit).second + (*rit).second;
            }
            else if (abs((*rit).first + (*lit).first) == ans) {
                outs = min(outs, (*lit).second + (*rit).second);
            }
            rit--;
            if (abs((*rit).first + (*lit).first) < ans) {
                ans = abs((*rit).first + (*lit).first);
                outs = (*lit).second + (*rit).second;
            }
            else if (abs((*rit).first + (*lit).first) == ans) {
                outs = min(outs, (*lit).second + (*rit).second);
            }

        }
    }

    for (int i = 0; i < outs.length(); i++) {
        cout << outs[i] << " ";
    }
    return 0;
}