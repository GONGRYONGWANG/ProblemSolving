//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N,K;
#include<vector>
#include<utility>
#include<algorithm>

vector<pair<int, int>> prob;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}



void solve(int L) {
    vector<int> load;
    load.resize(N + 1, 0);
    long long ans = 0;
    int remain = K;
    int idx = 0;
    while (remain != 0 && idx != N) {
        if (load[prob[idx].first] < L) {
            load[prob[idx].first]++;
            remain--;
            ans += prob[idx].second;
        }
        idx++;
    }
    if (remain != 0) {
        ans = -1;
    }
    cout << ans<<" ";
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N>>K;
    prob.resize(N);

    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        prob[i].first = x;
    }
    for (int i = 0; i < N; i++) {
        cin >> x;
        prob[i].second = x;
    }
    sort(prob.begin(), prob.end(), cmp);
    for (int L = 1; L <= N; L++) {
        solve(L);
    }
    return 0;
}

