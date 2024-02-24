//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N, C;
#include<vector>
vector<int> v1,v2;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> C;
    v1.push_back(0);
    v2.push_back(0);
    int x;
    for (int i = 0; i < N / 2; i++) {
        cin >> x;
        int s = v1.size();
        for (int j = 0; j < s; j++) {
            if (v1[j] + x <= C) {
                v1.push_back(v1[j] + x);
            }
        }
    }
    for (int i = N/2; i < N; i++) {
        cin >> x;
        int s = v2.size();
        for (int j = 0; j < s; j++) {
            if (v2[j] + x <= C) {
                v2.push_back(v2[j] + x);
            }
        }
    }
 
    int ans = 0;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] + v2[j] <= C) {
                ans++;
            }
        }
    }
    cout << ans;


    return 0;
}

