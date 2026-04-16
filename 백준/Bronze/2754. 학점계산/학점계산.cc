//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int ret = 0;
    char x;
    cin >> x;
    if (x == 'A') ret += 4;
    else if (x == 'B')ret += 3;
    else if (x == 'C') ret += 2;
    else if (x == 'D') ret += 1;
    else {
        cout << "0.0"; return 0;
    }

    cin >> x;
    if (x == '+') cout << ret << ".3";
    else if (x == '-') cout << ret - 1 << ".7";
    else cout << ret << ".0";

    return 0;
}