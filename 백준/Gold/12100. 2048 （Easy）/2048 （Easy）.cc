#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<vector>
#include<cmath>

int N;

vector<vector<int>> swipeleft(vector<vector<int>> map) {
    for (int i = 0; i < N; i++) {
        vector<int> v;
        bool fix = 0;
        for (int j = 0; j < N; j++) {
            if (map[i][j] != 0) {
                if (!fix && !v.empty() && v[v.size() - 1] == map[i][j]) {
                    v[v.size() - 1] *= 2;
                    fix = 1;
                }
                else {
                    v.push_back(map[i][j]);
                    fix = 0;
                }
            }
        }
        for (int j = 0; j < v.size(); j++) {
            map[i][j] = v[j];
        }
        for (int j = v.size(); j < N; j++) {
            map[i][j] = 0;
        }
    }
    return map;
}
vector<vector<int>> swiperight(vector<vector<int>> map) {
    for (int i = 0; i < N; i++) {
        vector<int> v;
        bool fix = 0;
        for (int j = N-1; j >=0; j--) {
            if (map[i][j] != 0) {
                if (!fix && !v.empty() && v[v.size() - 1] == map[i][j]) {
                    v[v.size() - 1] *= 2;
                    fix = 1;
                }
                else {
                    v.push_back(map[i][j]);
                    fix = 0;
                }
            }
        }
        for (int j = 0; j < v.size(); j++) {
            map[i][N-1-j] = v[j];
        }
        for (int j = v.size(); j < N; j++) {
            map[i][N-1-j] = 0;
        }
    }
    return map;
}
vector<vector<int>> swipeup(vector<vector<int>> map) {
    for (int i = 0; i < N; i++) {
        vector<int> v;
        bool fix = 0;
        for (int j = 0; j < N; j++) {
            if (map[j][i] != 0) {
                if (!fix && !v.empty() && v[v.size() - 1] == map[j][i]) {
                    v[v.size() - 1] *= 2;
                    fix = 1;
                }
                else {
                    v.push_back(map[j][i]);
                    fix = 0;
                }
            }
        }
        for (int j = 0; j < v.size(); j++) {
            map[j][i] = v[j];
        }
        for (int j = v.size(); j < N; j++) {
            map[j][i] = 0;
        }
    }
    return map;
}
vector<vector<int>> swipedown(vector<vector<int>> map) {
    for (int i = 0; i < N; i++) {
        vector<int> v;
        bool fix = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (map[j][i] != 0) {
                if (!fix && !v.empty() && v[v.size() - 1] == map[j][i]) {
                    v[v.size() - 1] *= 2;
                    fix = 1;
                }
                else {
                    v.push_back(map[j][i]);
                    fix = 0;
                }
            }
        }
        for (int j = 0; j < v.size(); j++) {
            map[N-1-j][i] = v[j];
        }
        for (int j = v.size(); j < N; j++) {
            map[N-1-j][i] = 0;
        }
    }
    return map;
}





int tzfe(int t, vector<vector<int>> map) {
    if (t == 0) {
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result = max(result, map[i][j]);
            }
        }
        return result;
    }
    vector<vector<int>> map1 = swipeleft(map);
    vector<vector<int>> map2 = swiperight(map);
    vector<vector<int>> map3 = swipeup(map);
    vector<vector<int>> map4 = swipedown(map);
    t--;
    int result = tzfe(t, map1);
    result = max(result, tzfe(t, map2));
    result = max(result, tzfe(t, map3));
    result = max(result, tzfe(t, map4));
    return result;
}






int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    vector<vector<int>> map;
    int tmp;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            v.push_back(tmp);
        }
        map.push_back(v);
    }
    cout << tzfe(5, map);





    return 0;
}