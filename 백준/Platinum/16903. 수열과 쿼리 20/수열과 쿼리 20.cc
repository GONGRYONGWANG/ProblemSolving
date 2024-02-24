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

struct trie {
    map<bool, trie*> m;
    int cnt = 0;
    void push(int x) {
        if (x == v.size()) return;
        if (m.find(v[x]) == m.end()) {
            m[v[x]] = new trie;
        }
        m[v[x]]->cnt += 1;
        m[v[x]]->push(x + 1);
    }
    void pop(int x) {
        if (x == v.size()) return;
        m[v[x]]->cnt -= 1;
        if (m[v[x]]->cnt == 0) {
            m.erase(v[x]);
            return;
        }
        m[v[x]]->pop(x + 1);
    }
    void find(int x) {
        if (x == v.size()) return;
        if (m.find(!v[x]) != m.end()) {
            ans += 1 << (31 - x);
            m[!v[x]]->find(x + 1);
            return;
        }
        if (m.find(v[x]) != m.end()) {
            m[v[x]]->find(x + 1);
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int M;
    cin >> M;

    trie T;
    T.push(0);

    while (M--) {
        int q,x;
        cin >> q>>x;
        for (int i = 0; i < 32; i++) {
            v[i] = ((x & (1 << (31 - i))) == (1 << (31 - i)));
        }
        if (q == 1) {
            T.push(0);
        }
        else if (q == 2) {
            T.pop(0);
        }
        else {
            ans = 0;
            T.find(0);
            cout << ans << endl;
        }
    }
    return 0;
}