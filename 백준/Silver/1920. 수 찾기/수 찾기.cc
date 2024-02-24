//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

#include<unordered_set>
unordered_set<int> uset;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        uset.insert(x);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x;
        if (uset.find(x) == uset.end()) {
            cout << 0;
        }
        else {
            cout << 1;
        }
        cout << endl;
    }

    return 0;
}

