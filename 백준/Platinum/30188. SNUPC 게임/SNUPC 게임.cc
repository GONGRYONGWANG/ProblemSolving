//#pragma warning(disable:4996) 
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<utility>
#include<string>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pq priority_queue
typedef unsigned long long ull;
typedef unsigned int uint;
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int S, N, U, P, C;
        cin >> S >> N >> U >> P >> C;
        if (S != 0 || N != 0 || U >= 2) {
            cout << "hanbyeol" << endl;
        }
        else if (U == 1) {
            if (P % 2) {
                cout << "geometry" << endl;
            }
            else {
                cout << "hanbyeol" << endl;
            }
        }
        else {
            if (P % 2) {
                cout << "geometry" << endl;
            }
            else {
                cout << "number_theory" << endl;
            }
        }
    }



    return 0;
}