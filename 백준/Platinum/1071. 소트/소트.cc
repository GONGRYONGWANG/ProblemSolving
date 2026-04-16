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


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    vector<int> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<pii> A;
    int prv = -1;
    for (int i = 0; i < N; i++) {
        if (v[i] == prv) {
            A.back().second += 1;
        }
        else A.push_back({ v[i],1 });
        prv = v[i];
    }
    vector<pii> ans = { {-2,0} };
    for (int i = 0; i < A.size(); i++) {
        if (A[i].second == 0) continue;
        if (A[i].first != prv + 1) {
            ans.push_back(A[i]);
            prv = A[i].first;
        }
        else {
            if (i == A.size() - 1) {
                ans.push_back(A[i]);
                swap(ans[ans.size()-2], ans[ans.size()-1]);
            }
            else {
                ans.push_back({ A[i + 1].first,1 });
                A[i + 1].second -= 1;
                prv = A[i + 1].first;
                i -= 1;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].second; j++) {
            cout << ans[i].first << " ";
        }
    }
    cout << endl;

    return 0;
}