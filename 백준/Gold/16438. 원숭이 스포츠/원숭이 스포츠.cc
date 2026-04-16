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

bool mon[8][99];

void dm(int left, int right, int t) {
    if (t == 8) return;
    int mid = (left + right) / 2;
    for (int i = left; i <= mid; i++) {
        mon[t][i] = mon[t - 1][i];
    }
    for (int i = mid+1; i <= right; i++) {
        mon[t][i] = !mon[t - 1][i];
    }
    dm(left, mid, t + 1);
    dm(mid + 1, right, t + 1);
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        mon[0][i] = 1;
    }

    dm(0, N - 1, 1);

    for (int i = 1; i <= 7; i++) {
        for (int j = 0; j < N; j++) {
            if (mon[i][j]) cout << "A";
            else cout << "B";
        }
        cout << endl;
    }
    return 0;
}