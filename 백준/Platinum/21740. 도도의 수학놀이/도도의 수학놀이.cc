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

string rv(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '6') s[i] = '9';
        else if (s[i] == '9') s[i] = '6';
    }
    return s;
}

bool cmp1(string a, string b) {
    if (a.length() != b.length()) return a.length() > b.length();
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i]) continue;
        else return (int)a[i] > (int)b[i];
    }
    return 0;
}

bool cmp2(string a, string b) {
    ull A = stol(a);
    ull B = stol(b);
    ull ab = A * pow(10,b.length()) + B;
    ull ba = B * pow(10,a.length()) + A;
    return ab > ba;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<string> v;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(rv(s));
    }
    sort(v.begin(), v.end(), cmp1);
    v.push_back(v[0]);
    sort(v.begin(), v.end(), cmp2);
    for (int i = N; i >=0; i--) {
        cout << rv(v[i]);
    }
    return 0;
}