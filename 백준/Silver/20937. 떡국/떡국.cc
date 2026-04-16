//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9


int N;
int reg[50001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int x;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        reg[x]++;
        if (reg[x] > ans) {
            ans = reg[x];
        }
    }
    cout << ans;
    return 0;
}

