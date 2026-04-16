//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e9

int freq[8001];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N);
    int total = 0;
    int maxi = -1e9;
    int mini = 1e9;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        total += v[i];
        freq[v[i] + 4000] += 1;
        maxi = max(maxi, v[i]);
        mini = min(mini, v[i]);
    }
    cout << (int)(round((float)total / N) + 0.0) << endl;
    sort(v.begin(), v.end());
    cout << v[N / 2]<<endl;
    int mode1 = 8000; int mode2 = 8000;
    for (int i = 7999; i >=0; i--) {
        if (freq[i] > freq[mode1]) {
            mode1 = i;
        }
        else if (freq[i] == freq[mode1]) {
            mode2 = mode1;
            mode1 = i;
        }
    }
    if (freq[mode1] == freq[mode2]) {
        cout << mode2-4000 << endl;
    }
    else cout << mode1-4000 << endl;

    cout << maxi - mini;

    return 0;
}