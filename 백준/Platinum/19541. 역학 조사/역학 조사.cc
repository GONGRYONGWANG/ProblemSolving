#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<vector>

vector<int> meeting[100001]; 
vector<int> scedule[100001];
bool issafemeeting[100001];
bool wasinfected[100001];
vector<int> inflast;
bool infectionstep[100001];

int N, M;

void checksafe(int p, int m);

void safe(int m) { 
	for (int i = 0; i < meeting[m].size(); i++) {
		checksafe(meeting[m][i], m-1);
	}
}


void checksafe(int p, int m) {   
	for (int i = 0; i < scedule[p].size(); i++) {
		if (scedule[p][i] > m) { break; }
		if (!issafemeeting[scedule[p][i]]) {
			issafemeeting[scedule[p][i]] = 1;
			safe(scedule[p][i]);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	cin >> N >> M;
	int k;
	int person;
	for (int meet = 1; meet <= M; meet++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> person;
			meeting[meet].push_back(person);
			scedule[person].push_back(meet);
		}
	}

	bool isinfected;
	for (int i = 1; i <= N; i++) {
		cin >> isinfected;
		if (!isinfected) {
			checksafe(i, M);
		}
		else {
			inflast.push_back(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		infectionstep[i] = 0;
	}

	for (int i = 1; i <= M; i++) {
		if (issafemeeting[i]) {
			for (int j = 0; j < meeting[i].size(); j++) {
				infectionstep[meeting[i][j]] = 1; 
			}
		}
		else {
			bool state = 1;
			for (int j = 0; j < meeting[i].size(); j++) {
				if (!infectionstep[meeting[i][j]]) {
					state = 0;
				}
			}
			if (state) {
				issafemeeting[i] = 1;
			}
			else {
				for (int j = 0; j < meeting[i].size(); j++) {
					infectionstep[meeting[i][j]] = 0;
				}
			}
		}
	}



	for (int i = 0; i <inflast.size(); i++) {
		wasinfected[inflast[i]] = 1;
		bool infectionoccured = 0;
		for (int j = 0; j < scedule[inflast[i]].size(); j++) {
			if (!issafemeeting[scedule[inflast[i]][j]]) {
				infectionoccured = 1;
			}
			else {
				wasinfected[inflast[i]] = 0;
			}
		}
		if (scedule[inflast[i]].size()!=0 && !infectionoccured) {
			cout << "NO"; return 0;
		}
	}


	cout << "YES" << endl;
	for (int i = 1; i <= N; i++) {
		cout << wasinfected[i] << " ";
	}


	return 0;
}

