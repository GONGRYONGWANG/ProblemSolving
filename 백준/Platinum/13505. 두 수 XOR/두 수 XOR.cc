#pragma warning(disable:4996) 
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
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
#include<ctime>
#include<regex>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };


vector<bool> v(32);
int ans;
int ret;

struct trie {
    map<bool, trie*> m;
    void push(int x) {
        if (x == v.size()) return;
        if (m.find(v[x]) == m.end()) {
            m[v[x]] = new trie;
        }
        m[v[x]]->push(x + 1);
    }
    void find(int x) {
        if (x == v.size()) return;
        if (m.find(!v[x]) != m.end()) {
            ret += 1 << (31 - x);
            m[!v[x]]->find(x + 1);
            return;
        }
        if (m.find(v[x]) != m.end()) {
            if ((ans & 1 << (31 - x)) == 1 << (31 - x)) return;
            m[v[x]]->find(x + 1);
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    trie T;
    for (int i = 0; i < N; i++) {
        int x = A[i];
        for (int j = 0; j < 32; j++) {
            v[j] = ((x & (1 << (31 - j))) == (1 << (31 - j)));
        }
        T.push(0);
    }
    ans = 0;
    for (int i = 0; i < N; i++) {
        int x = A[i];
        for (int j = 0; j < 32; j++) {
            v[j] = ((x & (1 << (31 - j))) == (1 << (31 - j)));
        }
        ret = 0;
        T.find(0);
        ans = max(ans, ret);
    }
    cout << ans;
    return 0;
}