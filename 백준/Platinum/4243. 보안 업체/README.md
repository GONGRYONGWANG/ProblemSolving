# [Platinum III] 보안 업체 - 4243 

[문제 링크](https://www.acmicpc.net/problem/4243) 

### 성능 요약

메모리: 2104 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 4월 13일 17:16:58

### 문제 설명

<p>명우는 보안 업체의 직원이고, 강남역에 있는 상점 여러 개를 도보로 순찰하는 업무를 맡고 있다. </p>

<p>강남역은 선분으로 나타낼 수 있고, 명우의 회사와 상점은 왼쪽부터 순서대로 선분 위의 점 p<sub>i</sub>로 나타낼 수 있다. 회사는 p<sub>a</sub>에 있고, s로 나타낸다. 명우는 s에서 순찰을 시작해서, 모든 상점 p<sub>i</sub>를 적어도 한 번 방문해야 한다. 각각의 i에 대해서, p<sub>i</sub>와 p<sub>i+1</sub>사이를 오가는데 걸리는 시간은 t[p<sub>i</sub>,p<sub>i+1</sub>]이다. p<sub>i</sub>의 대기 시간 ℓ<sub>i</sub>는 s를 출발해서 p<sub>i</sub>에 처음 도착하기 까지 걸린 시간이다. 시작점 s = p<sub>a</sub>의 대기 시간 ℓ<sub>a</sub>는 0이다. 명우는 모든 상점의 대기 시간의 합이 최소가 되게 하기 위해 순찰을 해야 한다.</p>

<p>아래 그림에는 총 6개의 상점 p<sub>1</sub>부터 p<sub>6</sub>까지가 있고, 시작점 s는 p<sub>3</sub>이다. 또, t[p<sub>1</sub>,p<sub>2</sub>] = 7, t[p<sub>2</sub>,p<sub>3</sub>] = 4, t[p<sub>3</sub>,p<sub>4</sub>] = 1, t[p<sub>4</sub>,p<sub>5</sub>] = 2, t[p<sub>5</sub>,p<sub>6</sub>] = 9이다. 명우가 s에서 오른쪽으로 걷기 시작한다면, 대기 시간 ℓ<sub>4</sub>와 ℓ<sub>5</sub>는 1과 3이 된다. 아래 그림에 나와있는 순서대로 순찰을 한다면, 대기 시간의 합은 71이 된다. 71보다 대기 시간의 합을 줄이는 방법은 없다.</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images/security.png" style="height:100px; width:415px"></p>

<p>점의 수 N과, p<sub>i</sub>와 p<sub>i+1</sub> 사이를 오가는데 걸리는 시간 t[p<sub>i</sub>,p<sub>i+1</sub>] (t = 1,...,N-1)이 주어졌을 때, 대기 시간을 최소로 하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 상점의 수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에는 시작점의 위치 a (1 ≤ a ≤ N)가 주어진다. a번째 점, p<sub>a</sub> = s가 시작점이 된다. 다음 N-1개 줄의 i번째 줄에는 t[p<sub>i</sub>,p<sub>i+1</sub>]가 주어진다. (1 ≤ t[p<sub>i</sub>,p<sub>i+1</sub>] ≤ 15,000,000)</p>

### 출력 

 <p>각 테스트 케이스 마다, 모든 가게를 순찰하는 모든 순찰 방법 중 대기 시간의 최솟값을 출력한다.</p>

