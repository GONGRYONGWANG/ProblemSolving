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
    int N, M;
    cin >> N >> M;
    vector<int> col = { 0,N };
    vector<int> row = { 0,M };
    int a;
    cin >> a;
    while (a--) {
        bool x;
        cin >> x;
        int c;
        cin >> c;
        if (x) {
            col.push_back(c);
        }
        else {
            row.push_back(c);
        }
    }
    sort(col.begin(), col.end());
    sort(row.begin(), row.end());
    int maxcol = 0;
    int maxrow = 0;
    for (int i = 1; i < col.size(); i++) {
        maxcol = max(maxcol, col[i] - col[i - 1]);
    }
    for (int i = 1; i < row.size(); i++) {
        maxrow = max(maxrow, row[i] - row[i - 1]);
    }
    cout << maxcol * maxrow;

    return 0;
}