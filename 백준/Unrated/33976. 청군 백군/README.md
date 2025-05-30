# [Unrated] 청군 백군 - 33976 

[문제 링크](https://www.acmicpc.net/problem/33976) 

### 성능 요약

메모리: 9608 KB, 시간: 504 ms

### 분류

분류 없음

### 제출 일자

2025년 5월 25일 15:39:18

### 문제 설명

<p>서울대학교 운동회에 $N$명의 학생이 참가하여, 청군과 백군으로 나뉘어 게임을 하고자 한다. 이때 각 학생들은 친한 친구들끼리 같은 팀에 속하고 싶어 하기 때문에, 원하는 인원수의 조를 만들어 함께 운동회를 신청하였다. $N$명의 학생들은 각각 정확히 하나의 조에 소속되며, 각 조는 청군과 백군 중 하나를 선택해 신청하였다.</p>

<p>$N$명의 학생들은 각각 서로 친한 정도가 존재한다. 편의상 학생들을 $1$, $\cdots$, $N$으로 번호를 매기면, 모든 $i$, $j$ $(1 \le i, j \le N;$ $i \neq j)$에 대해, 학생 $i$와 학생 $j$는 $F_{i,j}$만큼 친하다. 팀원 전체가 게임에서 단합하려면 그 팀에 속한 모든 학생들이 서로 친해야 하므로, 청군과 백군 각 팀의 단합력은 그 팀에 속한 서로 다른 학생들 $i$, $j$ $(i \neq j)$에 대한 $F_{i,j}$의 최솟값으로 정의된다. 단, 팀원의 수가 $0$ 또는 $1$일 경우 그 팀의 단합력은 $\infty$로 정의된다.</p>

<p>운동회의 진행자인 지환이는 운동회에 신청한 학생들을 각각 청군과 백군 중 하나의 팀에 배정해야 한다. 지환이는 청군과 백군 모두가 단합이 잘 되는 명경기를 만들고 싶으므로 두 팀의 단합력 중 작은 값이 최대가 되게 하려고 한다. 이때 지환이는 다수를 위한 소수의 희생이 불가피하다고 판단하였고, 신청할 때 만들었던 각 조별로 최대 $1$명을 신청한 팀이 아닌 팀에 배정하기로 했다.</p>

<p>위 조건을 만족하면서 지환이의 목표가 이루어지도록 참가자들을 배정할 때, 두 팀의 단합력 중 작은 값을 구해보자!</p>

### 입력 

 <p>첫째 줄에 전체 학생 수 $N$, 청군으로 신청한 조의 수 $M$, 백군으로 신청한 조의 수 $K$가 공백으로 구분되어 주어진다. $(2 \le N \le 500;$ $1 \le M;$ $1 \le K;$ $M+K \le N)$</p>

<p>둘째 줄부터 $M$개의 줄에 걸쳐, 청군으로 신청한 각 조에 대해 그 조에 속한 학생 수 $B_i$과 $B_i$개의 학생 번호가 공백으로 구분되어 주어진다.</p>

<p>$M+2$번째 줄부터 $K$개의 줄에 걸쳐, 백군으로 신청한 각 조에 대해 그 조에 속한 학생 수 $W_i$과 $W_i$개의 학생 번호가 공백으로 구분되어 주어진다.</p>

<p>$M+K+2$번째 줄부터 $N$개의 줄에 걸쳐, $F_{i,j}$를 나타내는 $N \times N$ 행렬이 주어진다. 구체적으로 $M+K+1+i$번째 줄에는 $F_{i,1}$, $\cdots$, $F_{i,N}$이 공백으로 구분되어 주어진다. 이때 $1\le i, j\le N$인 각 $i$, $j$에 대해 $F_{i,i} = 0, F_{i,j} = F_{j,i}$임이 보장된다. $(0 ≤ F_{i,j} ≤ 10^9)$</p>

<p>입력으로 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>두 팀의 단합력 중 작은 값을 나타내는 정수를 출력한다. 단, 그 값이 $\infty$라면 <code><span style="color:#e74c3c;">INFINITY</span></code>를 출력한다.</p>

