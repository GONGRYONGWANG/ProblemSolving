# [Platinum IV] 정상 - 3697 

[문제 링크](https://www.acmicpc.net/problem/3697) 

### 성능 요약

메모리: 24412 KB, 시간: 388 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2025년 7월 10일 01:27:09

### 문제 설명

<p>상근이는 큰 지도를 만드는 회사에서 일하고 있다. 상근이가 맡은 일은 풍경에서 산의 정상을 찾는 일이다. 정상을 찾는 일은 매우 어렵다. 다음과 같은 예제를 이용해서 입력 예제로 주어진 풍경에서 정상을 찾는 방법을 알아보자.</p>

<p>입력으로 주어진 예제에서 높이가 3보다 높은 곳은 없기 때문에 높이가 3인 곳은 정상이다. 높이가 3인 정상의 왼쪽에는 높이가 2인 점이 있지만, 이 곳은 정상이 아니다. 그 이유는 땅 (높이 0)으로 내려가지 않고 다시 높이가 3인 곳으로 올라갈 수 있기 때문이다. 높이 3 정상의 오른쪽에 있는 높이가 2인 곳은 정상이다. 그 이유는 높이가 3인 곳으로 올라가기 위해서 높이가 0으로 내려갔다가 다시 올라가야 하기 때문이다.</p>

<p>위의 예를 응용해서 상근이는 d-정상이라는 개념을 도입했다. 높이가 h인 어떤 점이 d-정상이 되려면, 그 점에서 출발해서 높이가 h-d보다 작거나 같은 곳을 방문하지 않고 더 높은 곳을 갈 수 없어야 한다.</p>

<p>각 점의 높이가 주어졌을 때, d-정상의 수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수가 주어지며, 테스트 케이스의 수는 100개를 넘지 않는다. 각 테스트 케이스의 첫째 줄에 지도의 크기 n, m와 d가 주어진다. (1 ≤ n, m ≤ 500, 1 ≤ d ≤ 1,000,000,000) 다음 n개 줄에는 (x, y)의 높이 h가 주어진다. (0 ≤ h ≤ 1,000,000,000)</p>

### 출력 

 <p>각 테스트 케이스마다 d-정상의 수를 출력한다.</p>

