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


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> score = {0};
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        score.push_back(x);
    }
    sort(score.begin(), score.end());

    int total = 0;
    for (int i = 1; i <= N; i++) {
        total += score[i];
        if (total < i * (i - 1) / 2) {
            cout << -1;
            return 0;
        }
    }
    if (total != N * (N - 1) / 2) {
        cout << -1;
        return 0;
    }
    cout << 1;

    return 0;
}