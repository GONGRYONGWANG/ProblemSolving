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
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { -1,0,1,0 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
//const double pi = 3.14159265358979323846;

string s;
int idx;
ll mod = 1000000007;

struct trie {

    vector<pair<char, trie*>> m;
    bool f = 0;
    void push() {
        if (idx == s.length()) {
            f = 1;
            return;
        }
        idx += 1;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if ((*iter).first == s[idx - 1]) {
                (*iter).second->push();
                return;
            }
        }
        m.push_back({ s[idx - 1], new trie });
        m.back().second->push();
    }
    ll get() {
        ll ret = 1;
        int cnt = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            ret = ret * (*iter).second->get() % mod;
            ret = ret * cnt % mod;
            cnt += 1;
        }
        if (f) ret = ret * cnt % mod;
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    trie t;
    int N;
    cin >> N;
    while (N--) {
        cin >> s;
        idx = 0;
        t.push();
    }
    cout << t.get();


    return 0;

}