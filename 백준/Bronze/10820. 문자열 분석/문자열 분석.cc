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
#include<complex> // complex number
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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;




int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while (!cin.eof()) {
        string s;
        getline(cin, s);
        if (cin.eof()) return 0;
        int A = 0;
        int a = 0;
        int N = 0;
        int S = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') a += 1;
            else if (s[i] >= 'A' && s[i] <= 'Z') A += 1;
            else if (s[i] == ' ') S += 1;
            else N += 1;
        }
        cout << a << " " << A << " " << N << " " << S << endl;
    }



    return 0;
}