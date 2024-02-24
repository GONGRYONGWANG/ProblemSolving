#pragma warning(disable:4996) 
#include<iostream>
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
#include<ctime>
#include<regex>
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

bool cmp(ull a, ull b) {
    ull ab, ba;
    ull aa = a;
    ull bb = b;
    int alen = 0;
    int blen = 0;
    while (aa) {
        aa /= 10;
        alen += 1;
    }
    while (bb) {
        bb /= 10;
        blen += 1;
    }
    ab = (a * pow(10,blen)) + b;
    ba = (b * pow(10, alen)) + a;
    return ab > ba;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> K >> N;
    vector<ull> v(K);
    for (int i = 0; i < K; i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N - K; i++) {
        v.push_back(v.back());
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << v[i];
    }
    return 0;
}