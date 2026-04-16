//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int cnt;
int L, P, V;

void TEST() {
    cnt++;
    int ans = (V / P) * L;
    V %= P;
    if (V < L) {
        ans += V;
    }
    else {
        ans += L;
    }
    cout << "Case " << cnt << ": " << ans<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cnt = 0;
    while (1) {
        cin >> L >> P >> V;
        if (L == 0) { return 0; }
        TEST();
    }

    return 0;
}

