#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr[1000];
bool visited[2001];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    string s;
    cin >> s;
    if (s == "yes") {
        for (int i = 1; i <= N / 2; i++) {
            bool flag = true;
            for (int j = 0; j < i; j++) {
                if (arr[j] != 0 && arr[N - i + j] != 0 && arr[j] != arr[N - i + j]) flag = false;
            }
            if (!flag) continue;
            for (int j = 0; j < i; j++) {
                arr[j] = max(arr[j], arr[N - i + j]);
                arr[N - i + j] = arr[j];
            }
            for (int j = 0; j < N; j++) {
                if (arr[j] == 0) cout << 1;
                else cout << arr[j];
                cout << " ";
            }
            return 0;
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            visited[arr[i]] = true;
        }
        vector<int> v;
        for (int i = 1; i <= 2000; i++) {
            if (!visited[i]) v.push_back(i);
        }

        for (int i = 0; i < N; i++) {
            if (arr[i] == 0) {
                arr[i] = v.back();
                v.pop_back();
            }
            cout << arr[i] << " ";
        }

    }





    return 0;
}
