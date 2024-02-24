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

vector<string> v;
struct trie {
    map<string, trie*>m;
    void push(int x) {
        if (x == v.size()) return;
        if (m.find(v[x])==m.end()) {
            m[v[x]] = new trie;
        }
        m[v[x]]->push(x + 1);
    }
    void tour(int depth) {
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            for (int i = 0; i < depth; i++) {
                cout << "--";
            }
            cout << iter->first << endl;
            iter->second->tour(depth + 1);
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;

    trie T;

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        T.push(0);
        v.clear();
    }
    T.tour(0);
    return 0;
}