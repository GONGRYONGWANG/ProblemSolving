//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9


long long N;
long long K;
#include<vector>
#include<algorithm>
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> N >> K;
    double x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long maxvel = 0;
    for (int i = 1; i < N; i++) {
        maxvel = max(maxvel, i * v[0] + (N - i) * v[i]);
    }
    long long ans = K / maxvel;
    if (K % maxvel != 0) ans++;
    cout << ans;


    return 0;
}

