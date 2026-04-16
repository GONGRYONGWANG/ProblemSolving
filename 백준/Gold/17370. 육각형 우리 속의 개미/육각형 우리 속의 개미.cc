#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
int N;
bool visited[100][100][100];
int DFS(vector<int> position, int direction, int move) {
	if (visited[position[0] + 50][position[1] + 50][position[2] + 50]) {
		if (move == 0) { return 1; }
		else return 0;
	}
	if (move == 0) { return 0; }
	visited[position[0] + 50][position[1] + 50][position[2] + 50] = 1;
	int result = 0;
	if (direction == 0) {
		position[1] += 1;
		result += DFS(position, 1, move - 1);
		position[1] -= 1;
		position[2] -= 1;
		result += DFS(position, 5, move - 1);
		position[2] += 1;
	}
	else if (direction == 1) {
		position[0] += 1;
		result += DFS(position, 0, move - 1);
		position[0] -= 1;
		position[2] += 1;
		result += DFS(position, 2, move - 1);
		position[2] -= 1;
	}
	else if (direction == 2) {
		position[1] += 1;
		result += DFS(position, 1, move - 1);
		position[1] -= 1;
		position[0] -= 1;
		result += DFS(position, 3, move - 1);
		position[0] += 1;
	}
	else if (direction == 3) {
		position[1] -= 1;
		result += DFS(position, 4, move - 1);
		position[1] += 1;
		position[2] += 1;
		result += DFS(position, 2, move - 1);
		position[2] -= 1;
	}
	else if (direction == 4) {
		position[0] -= 1;
		result += DFS(position, 3, move - 1);
		position[0] += 1;
		position[2] -= 1;
		result += DFS(position, 5, move - 1);
		position[2] += 1;
	}
	else if (direction == 5) {
		position[0] += 1;
		result += DFS(position, 0, move - 1);
		position[0] -= 1;
		position[1] -= 1;
		result += DFS(position, 4, move - 1);
		position[1] += 1;
	}
	visited[position[0] + 50][position[1] + 50][position[2] + 50] = 0;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	visited[50][50][50] = 1;
	cout << DFS({ 1,0,0 }, 0, N);

	return 0;
}

