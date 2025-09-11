# [Platinum I] 간선 파괴 - 11897 

[문제 링크](https://www.acmicpc.net/problem/11897) 

### 성능 요약

메모리: 72236 KB, 시간: 620 ms

### 분류

그래프 이론, 자료 구조, 분리 집합

### 제출 일자

2025년 9월 11일 22:14:01

### 문제 설명

<p>승현이는 곧 개최되는 KOI 전국본선을 대비하기 위해 그래프 이론을 공부하고 있습니다. 요즘 승현이는 깊이우선탐색(DFS)과 너비우선탐색(BFS)의 매력에 푹 빠져 있고, 이를 이용한 문제들을 풀고 있다고 합니다. 지금 승현이는 V개 정점과 E개 간선으로 구성된 무향 그래프가 주어질 때 컴포넌트의 수를 세는 문제를 풀고 있습니다. 문제에서는 편의상 정점들에는 1,2,⋯,V의 번호를, 간선들에는 1,2,⋯,E의 번호를 붙이고, 중복된 간선은 없다고 가정했습니다.</p>

<p>참고: 여기서 무향 그래프가 간선으로 서로 연결되지 않은 몇 개의 그룹으로 나뉘어 있을 때, 각 연결된 정점들의 부분집합을 컴포넌트라고 합니다. 예로 들어, 아래 [그림 1]에서는 {1,2,5,8}, {3}, {4,6,7}이 각각 하나의 컴포넌트를 이루고 있습니다. [그림 2]와 같이 그래프 전체가 하나의 컴포넌트로 구성되어 있을 수도 있습니다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11897/1.png" style="height:169px; width:541px"></p>

<p>승현이는 당연히 문제를 보자마자 코딩을 시작하여 DFS를 사용한 올바른 코드를 작성했지만 0점을 받았습니다. 승현이의 선생님께서 코드를 보고 "재귀 함수를 사용했다"면서 채점조차 하지 않았기 때문입니다.(?) 화가 난 승현이는 주어진 그래프에서 <code>l</code>, <code>l+1</code>, <code>l+2</code>, ..., <code>r-1</code>, <code>r</code>번 간선들을 <code>destroy(l, r)</code> 함수로 파괴하기 시작합니다. (번호가 연속적인 이유는 파괴하기 편해서라고 합니다.)</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11897/2.png" style="height:188px; width:576px"></p>

<p style="text-align: center;">[그림 3] 위 그림에서 간선 위에 쓰인 빨간색 번호는 그 간선의 번호를 의미합니다. 승현이가 <code>destroy(3, 5)</code>를 호출하여 3, 4, 5번 간선이 파괴되었습니다.</p>

<p>그러나 승현이보다 유능한 프로그래머인 여러분은 재귀 함수를 이용하지 않고 컴포넌트의 수를 구할 수 있기 때문에, 간선이 파괴된 그래프의 컴포넌트 수를 구한 뒤 <code>recover(l, r)</code> 함수를 호출해 파괴된 <code>l</code>, <code>l+1</code>, <code>l+2</code>, ..., <code>r-1</code>, <code>r</code>번 간선들을 복구하여 승현이를 약올리고자 합니다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11897/3.png" style="height:208px; width:589px"></p>

<p style="text-align: center;">[그림 4] 위 그림에서 여러분은 파괴된 그래프의 컴포넌트 수(2)를 구한 뒤 <code>recover(3, 5)</code> 함수를 호출하여 간선을 복원했습니다.</p>

<p>그러자 승현이는 <code>destroy</code> 함수를 계속 호출했고, 이에 일일이 대응하기에 지친 여러분은 프로그램을 작성하여 이 복잡한 작업을 대신 하게 하려고 합니다. 이제 프로그램을 작성하면 되겠네요! :)</p>

### 입력 

 <p>첫째 줄에 주어진 그래프의 정점의 수 V, 간선의 수 E가 공백을 사이로 두고 주어집니다. 이후 E개 줄에 간선들의 정보가 주어집니다. 이 중 i (1 ≤ i ≤ E)번째 줄에는 두 개의 정수 u<sub>i</sub>,v<sub>i</sub> (1 ≤ u<sub>i</sub>, v<sub>i</sub> ≤ V)가 공백을 사이로 두고 주어지는데, 이는 그래프에서 두 정점 u<sub>i</sub>와 v<sub>i</sub> 사이에 i번 간선이 그여 있다는 것을 의미합니다. 위에서 명시했듯이, 그래프에서 두 노드 사이에 간선은 최대 1개 존재하며, 주어진 그래프는 무향 그래프입니다.</p>

<p>그 다음 줄에 승현이가 <code>destroy</code> 함수를 호출한 횟수 Q가 주어집니다. 이후 Q개 줄에 <code>destroy</code> 함수의 파라미터 l과 r (1 ≤ l ≤ r ≤ E)이 공백을 사이로 두고 주어집니다. (5 ≤ V ≤ 700, 1 ≤ E ≤ 123,456, 1 ≤ Q ≤ 50,000)</p>

### 출력 

 <p>여러분은 승현이가 <code>destroy</code> 함수를 호출할 때마다 파괴된 그래프의 컴포넌트 수를 구하여 한 줄에 하나씩 출력한 뒤, 그래프를 다시 복원해야 합니다. 승현이는 자비롭기 때문에 여러분이 그래프를 복구한 후에야 <code>destroy</code> 함수를 호출합니다.</p>

<p> </p>

