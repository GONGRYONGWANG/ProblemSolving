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

unordered_set<string> us;
string s;
struct trie {
    map <char, trie*> m;
    bool f=0;
    void push(int i) {
        if (i == s.size()) f = 1;
        else {
            char c = s[i];
            if (!m.count(c)) m[c] = new trie;
            m[c]->push(i + 1);
        }
    }
    int q(int i) {
        if (!m.count(s[i]) || i == s.size()) return 0;
        if (m[s[i]]->f && us.count(s.substr(i + 1))) return 1;
        return m[s[i]]->q(i + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int C, N;
    cin >> C >> N;
    trie col;
    for (int i = 0; i < C; i++) {
        cin >> s;
        col.push(0);
    }
    for (int i = 0; i < N; i++) {
        cin >> s;
        us.insert(s);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> s;
        if (col.q(0)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }

    return 0;
}