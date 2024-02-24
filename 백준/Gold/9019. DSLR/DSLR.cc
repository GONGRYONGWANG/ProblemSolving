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
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;


int visited[10000];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        queue<pair<int,string>> q;
        q.push({ A, "" });
        fill(visited, visited + 10000, false);
        visited[A] = true;
        while (!q.empty()) {
            int x = q.front().first;
            string s = q.front().second;
            q.pop();
            if (x == B) {
                for (int i = 0; i < s.length(); i++) {
                    cout << s[i];
                }
                cout << endl;
                break;
            }
            int D = x * 2 % 10000;
            int S = (x + 9999) % 10000;
            int L = x % 1000 * 10 + x / 1000;
            int R = x / 10 + x % 10 * 1000;
            if (!visited[D]) q.push({D,s+'D'});
            visited[D] = 1;
            if (!visited[S]) q.push({S,s+'S'});
            visited[S] = 1;
            if (!visited[L]) q.push({L,s+'L'});
            visited[L] = 1;
            if (!visited[R]) q.push({R,s+'R'});
            visited[R] = 1;
        }
    }
    
    return 0;
}

