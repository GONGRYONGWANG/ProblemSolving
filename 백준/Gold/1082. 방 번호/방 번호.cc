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

vector<pii> p;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        while (!p.empty() && p.back().second >= x) {
            p.pop_back();
        }
        p.push_back({ i,x });
    }


    cin >> M;

    vector<int> ans;
    if (p[0].first == 0 && (p.size()==1 ||M < p[1].second)) {
        cout << 0;
        return 0;
    }

    if (p[0].first == 0) {
        ans.push_back(1);
        M -= p[1].second;
    }


    while (M >= p[0].second) {
        ans.push_back(0);
        M -= p[0].second;
    }
    for (int i = 0; i < ans.size(); i++) {
        while (ans[i] < p.size() - 1 && M + p[ans[i]].second >= p[ans[i] + 1].second) {
            M += p[ans[i]].second - p[ans[i] + 1].second;
            ans[i] = ans[i] + 1;
        }
        cout << p[ans[i]].first;
    }
    return 0;
}