//#pragma warning(disable:4996) #include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int N;
#include<vector>
vector<vector<char>> map;
vector<vector<char>> ans;

void observe_x(int x, int y) {
    ans[x][y] = 'X';

    int a, b;

    a = x - 1;
    while (a >= 0 && map[a][y] == '.') {
        ans[a][y] = 'B';
        a--;
    }

    a = x + 1;
    while (a < N && map[a][y] == '.') {
        ans[a][y] = 'B';
        a++;
    }

    b = y - 1;
    while (b >= 0 && map[x][b] == '.') {
        ans[x][b]='B';
        b--;
    }

    b = y + 1;
    while (b < N && map[x][b] == '.') {
        ans[x][b] = 'B';
        b++;
    }

    return;
}

void observe_o(int x, int y) {
    ans[x][y] = 'O';
    int a, b;

    a = x - 1;
    while (a >= 0 && map[a][y] == '.') {
        ans[a][y] = '.';
        a--;
    }

    a = x + 1;
    while (a < N && map[a][y] == '.') {
        ans[a][y] = '.';
        a++;
    }

    b = y - 1;
    while (b >= 0 && map[x][b] == '.') {
        ans[x][b] = '.';
        b--;
    }

    b = y + 1;
    while (b < N && map[x][b] == '.') {
        ans[x][b] = '.';
        b++;
    }

    return;
}


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    map.resize(N);
    char x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            cin >> x;
            map[i].push_back(x);
        }
    }

    ans.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans[i].push_back('.');
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j]=='X') {
                observe_x(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'O') {
                observe_o(i, j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}

