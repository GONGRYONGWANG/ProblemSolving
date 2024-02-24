#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<map>
map<int, int> m;
map<int, int> rm;

int parent[500001];
bool call[500001];
bool loop[500001];
bool extra[500001];

int FIND(int x) {
	if (parent[x] == 0) { return x; }
	return parent[x] = FIND(parent[x]);
}

void merge(int a, int b) {
	a = FIND(a);
	b = FIND(b);
	if (rm[a] > rm[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
	return;
}





int N;
long long result;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N;
	result = 0;

	int idx = 1;
	int s, t;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		if (m.find(s) == m.end()) {
			m.insert({ s,idx });
			rm.insert({ idx,s });
			idx++;
		}
		if (m.find(t) == m.end()) {
			m.insert({ t,idx });
			rm.insert({ idx,t });
			idx++;
		}

		s = m[s];
		t = m[t];
		if (!call[s]) {
			call[s] = 1;
		}
		else {
			result += rm[s];
		}
		if (!call[t]) {
			call[t] = 1;
		}
		else {
			result += rm[t];
		}

		if(FIND(s)!=FIND(t)){
			if (loop[FIND(s)] || loop[FIND(t)]) {
				merge(s, t);
				loop[FIND(s)] = 1;
			}
			else merge(s, t);
		}
		else {
			loop[FIND(s)] = 1;
		}
	}
	
	for (int i = 1; i <= m.size(); i++) {
		if (FIND(i) != i && !extra[FIND(i)] && !loop[FIND(i)]) {
			result += rm[FIND(i)];
			extra[FIND(i)] = 1;
		}
	}
	
	cout << result;

	return 0;
}

