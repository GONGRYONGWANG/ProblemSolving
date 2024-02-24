//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<algorithm>
int N;
int happiness[100];
int cost[20];
int val[20];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    for (int i = 0; i <=99; i++) {
        happiness[i] = -INF;
    }
    happiness[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 99; j >= 0; j--) {
            if (j + cost[i] < 100) {
                happiness[j + cost[i]] = max(happiness[j + cost[i]], happiness[j] + val[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        ans = max(ans, happiness[i]);
    }
    cout << ans;
    return 0;
}

