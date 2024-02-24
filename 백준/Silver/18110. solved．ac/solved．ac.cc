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
    int N;
    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x); 
    }
    sort(v.begin(), v.end());
    int trim = N*15;
    if (trim % 100 >= 50) {
        trim = trim / 100 + 1;
    }
    else trim = trim / 100;

    int total = 0;
    for (int i = trim; i < N - trim; i++) {
        total += v[i];
    }
    cout << (int)round((double)total/(N-2*trim));

    return 0;
}

