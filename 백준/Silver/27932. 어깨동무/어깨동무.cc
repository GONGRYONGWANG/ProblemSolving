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






int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    K = N - K;
    vector<int> stu;
    int h;
    cin >> h;
    stu.push_back(h);
    stu.push_back(h);
    for (int i = 1; i < N; i++) {
        cin >> h;
        stu.push_back(h);
    }
    stu.push_back(h);
    vector<int> hd;
    for (int i = 1; i <= N; i++) {
        hd.push_back(max(abs(stu[i] - stu[i - 1]), abs(stu[i] - stu[i + 1])));
    }
    sort(hd.begin(), hd.end());
    int start, end;
    start = 0; end = 1e9;
    int idx = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (idx == N) idx -= 1;
        while (idx>0 && hd[idx] > mid) idx--;
        while (idx<N && hd[idx] <= mid) idx++;
        if (idx < K) start = mid + 1;
        else end = mid - 1;
    }
    cout << start;

    return 0;
}