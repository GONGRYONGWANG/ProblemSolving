#pragma warning(disable:4996) 
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<utility>
#include<string>
#include<set>
#include<unordered_set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

#define inf 1e9

string s;
struct trie {
    map <char, trie*> m;
    int nxt=0;
    void push(int i) {
        if (i == s.size()) { nxt += 1; }
        else {
            char c = s[i];
            if (!m.count(c)) {
                m[c] = new trie;
                nxt += 1;
            }
            m[c]->push(i + 1);
        }
    }
    int find(int i) {
        if (i == s.length()) {
            return 0;
        }
        char c = s[i];
        if (nxt == 1) {
            if (i == 0) return m[c]->find(i + 1) + 1;
            return m[c]->find(i + 1);
        }
        else {
            return m[c]->find(i + 1) + 1;
        }
    }
};
int N;
void solve() {
    trie t;
    vector<string> v;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        v.push_back(s);
        t.push(0);
    }
    double total = 0;
    for (int i = 0; i < N; i++) {
        s = v[i];
        total += t.find(0);
    }
    cout << fixed;
    cout.precision(2);
    cout << total / N << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    while (1) {
        cin >> N;
        if (cin.eof()) break;
        solve();
    }


    return 0;
}