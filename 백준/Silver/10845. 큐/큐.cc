#pragma warning(disable:4996) 
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
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    deque<int> q;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            q.push_back(x);
            continue;
        }
        else if (s == "pop") {
            if (q.empty()) cout << -1;
            else {
                cout << q.front();
                q.pop_front();
            }
        }
        else if (s == "size") {
            cout << q.size();
        }
        else if (s == "empty") {
            cout << q.empty();
        }
        else if (s == "front") {
            if (q.empty()) cout << -1;
            else cout << q.front();
        }
        else {
            if (q.empty()) cout << -1;
            else cout << q.back();
        }
        cout << endl;
    }

    return 0;
}

