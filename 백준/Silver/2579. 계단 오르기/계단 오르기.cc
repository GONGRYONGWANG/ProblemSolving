#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
using namespace std;

int N;
long long MaxScores[301][2];
int Stairs[301];

long long Large(long long a, long long b) {
	if (a > b) { return a; }
	return b;
}


long long Maxscore(int i1, int i2) {
	if (i1 == N) { 
		MaxScores[i1][i2] = Stairs[i1];
		return MaxScores[i1][i2]; 
	}
	if (i1 > N) { return 0; }
	if (MaxScores[i1][i2] == 0) {
		if (i1 == N - 2) {
			MaxScores[i1][i2] = Stairs[i1] + Maxscore(i1 + 2, 1);
			return MaxScores[i1][i2];
		}
		if (i2 == 0) { 
			MaxScores[i1][i2] = Stairs[i1] + Maxscore(i1 + 2,1);
		}
		else if(i2 == 1){
			MaxScores[i1][i2] = Stairs[i1] + Large(Maxscore(i1 + 1, 0), Maxscore(i1 + 2, 1));
		}
		return MaxScores[i1][i2];
	}
	return MaxScores[i1][i2];
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Stairs[i];
	}
	cout << Large(Maxscore(2,1),Maxscore(1,1));
}