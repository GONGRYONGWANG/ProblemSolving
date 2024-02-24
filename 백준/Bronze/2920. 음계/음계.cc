#pragma warning(disable:4996) 
#include<iostream>
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

    vector<int> as = { 1,2,3,4,5,6,7,8 };
    vector<int> de = { 8,7,6,5,4,3,2,1 };
    vector<int> v(8);
    for (int i = 0; i < 8; i++) {
        cin >> v[i];
    }
    if (v == as) cout << "ascending";
    else if (v == de) cout << "descending";
    else cout << "mixed";

    return 0;
}