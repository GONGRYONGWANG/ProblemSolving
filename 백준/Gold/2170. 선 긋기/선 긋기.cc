//#pragma warning(disable:4996) 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define inf 1e18




int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;

    vector<pii> line;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        line.push_back({ x,y });
    }
    sort(line.begin(), line.end());

    int ans = 0;
    int s = line[0].first; int e = line[0].second;
    for (int i = 1; i < N; i++) {
        x = line[i].first;
        y = line[i].second;
        if (x > e) {
            ans += e - s;
            s = x;
        }
        e = max(e, y);
    }
    ans += e - s;
    cout << ans;
    return 0;
}
