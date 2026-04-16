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


int mindiv[5000001];


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    for (int i = 2; i <= 2236; i++) {
        if (mindiv[i] != 0) continue;
        for (int j = i * i; j <= 5000000; j += i) {
            if (mindiv[j] == 0) mindiv[j] = i;
        }
    }
    int N;
    cin >> N;
    while (N--) {
        int K;
        cin >> K;
        while (mindiv[K]!=0) {
            cout << mindiv[K]<<" ";
            K /= mindiv[K];
        }
        cout << K;
        cout << endl;
    }
    return 0;
}


