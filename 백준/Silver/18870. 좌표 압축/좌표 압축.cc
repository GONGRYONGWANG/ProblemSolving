#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
int N;

vector<int> v;
vector<int> v2;
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
        v2.push_back(x);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for (int i : v2) {
        cout << lower_bound(v.begin(), v.end(), i) - v.begin()<<" ";
    }
    return 0;
}

