# [Platinum V] 정훈이는 민트초코맛 짜장라면이 먹고 싶다 - 23975 

[문제 링크](https://www.acmicpc.net/problem/23975) 

### 성능 요약

메모리: 78760 KB, 시간: 1244 ms

### 분류

자료 구조, 데이크스트라, 분리 집합, 그래프 이론, 최단 경로, 트리

### 제출 일자

2024년 7월 31일 03:57:44

### 문제 설명

<p>정훈이는 민트초코맛 짜장라면을 좋아한다.</p>

<p>그러나 민트초코맛 짜장라면을 찾는 사람은 정훈이밖에 없기 때문에 친절한 정훈이는 편의점 사장님들을 위해 자신이 언제, 어떤 편의점을 방문할지 미리 알려주려고 한다.</p>

<p>앞으로 <em>K</em>일 동안, 정훈이는 집에 가는 길에 있는 편의점 중에서 재고가 있는 첫 편의점에 방문해 민트초코맛 짜장라면을 1개씩 구매할 예정이다. 민트초코맛을 좋아하는 정훈이도 하루에 2개 이상 먹는 것은 힘들기 때문에 하루에 구매하는 라면은 한 개를 넘지 않는다.</p>

<p>편의점은 1번부터 <em>N</em>번까지 규모 순으로 번호가 매겨져 있으며, 정훈이네 집은 규모가 가장 작은 1번 편의점이 위치한 곳에 있다. 정훈이는 편의점을 잇는 <em>M</em>개의 양방향 길로만 다니면서 항상 최단 경로로 집에 간다. 단, 최단 경로가 여러 개라면 바로 다음에 보이는 편의점의 규모가 더 큰 쪽을 선택한다.</p>

<p><em>K</em>일 동안 정훈이가 위치한 곳의 편의점 번호가 주어질 때, 어떤 편의점에서 민트초코맛 짜장라면을 구매할지 구하여라.</p>

### 입력 

 <p>첫 줄에 <em>N</em>, <em>M</em>, <em>K</em>가 공백으로 구분되어 주어진다. (1 ≤ <em>N, M, K</em> ≤ 1,000,000)</p>

<p>둘째 줄에 각 편의점에 남아있는 민트초코맛 짜장라면의 개수 <em>A<sub>i</sub></em>가 주어진다. (0 ≤ <em>A</em><sub><em>i</em> </sub>≤ 100)</p>

<p>셋째 줄부터 <em>M</em>+2번째 줄까지 두 편의점의 번호와 두 편의점을 잇는 길의 거리인 정수 <em>C</em>가 주어진다. (1 ≤ <em>C</em> ≤ 1,000) </p>

<p><em>M</em>+3번째 줄부터 <em>M</em>+2+<em>K</em>번째 줄까지 정훈이가 있는 곳의 편의점 번호가 주어진다.</p>

### 출력 

 <p><em>K</em>일 동안 정훈이가 민트초코맛 짜장라면을 구매할 편의점 번호를 출력한다.</p>

<p>집으로 가는 길이 없거나 라면을 구매할 수 없다면 -1을 출력한다.</p>

