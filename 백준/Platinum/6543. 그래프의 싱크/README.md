# [Platinum IV] 그래프의 싱크 - 6543 

[문제 링크](https://www.acmicpc.net/problem/6543) 

### 성능 요약

메모리: 3248 KB, 시간: 20 ms

### 분류

그래프 이론, 방향 비순환 그래프, 강한 연결 요소

### 제출 일자

2025년 7월 23일 14:28:10

### 문제 설명

<p>방향 그래프 <em>G</em> = (<em>V</em>, <em>E</em>)가 주어져 있다.</p>

<p>임의의 노드 <em>u</em>, <em>v</em> ∈ <em>V</em>에 대해서 <em>u</em>에서 <em>v</em>로 E에 포함된 간선만을 이용해 갈 수 있는 경로가 있으면 <em>u</em>→<em>v</em>로 표현한다.</p>

<p>만약 어떤 노드 <em>v</em> ∈ <em>V</em>가 자신으로부터 도달할 수 있는 모든 노드로부터 돌아오는 경로가 있다면, 즉 다음 조건을 만족한다면 노드 <em>v</em> ∈ <em>V</em>를 싱크라고 부른다.</p>

<ul>
	<li>조건: ∀<em>w</em> ∈ <em>V</em>, (<em>v</em>→<em>w</em>) ⇒ (<em>w</em>→<em>v</em>)</li>
</ul>

<p>또한, 그래프 <em>G</em>의 싱크를 모아놓은 집합을 bottom(G)로 표현한다.</p>

<ul>
	<li>bottom(<em>G</em>) = {<em>v</em> ∈ <em>V</em>: ∀<em>w</em> ∈ <em>V</em>, (<em>v</em>→<em>w</em>) ⇒ (<em>w</em>→<em>v</em>)}</li>
</ul>

<p>주어진 그래프 <em>G</em>=(<em>V</em>, <em>E</em>)의 bottom(<em>G</em>)를 구하시오.</p>

### 입력 

 <p>입력은 여러 개의 테스트 케이스로 구분되어 있다.</p>

<p>각 테스트 케이스의 첫 줄에는 노드의 수 <em>n</em> (1 ≤ <em>n</em> ≤ 5,000)과 음이 아닌 정수 <em>m</em> (0 ≤ m ≤ 100,000)이 주어진다. <em>V</em> = {1, 2, ..., <em>n</em>}이고, 간선의 수 |<em>E</em>|=<em>m</em>임을 의미한다.</p>

<p>그 다음부터는 각 간선을 나타내는 <em>m</em>쌍의 수 <em>v</em><sub>1</sub> <em>w</em><sub>1</sub> <em>v</em><sub>2</sub> <em>w</em><sub>2</sub> ... <em>v<sub>m</sub></em> <em>w<sub>m</sub></em>이 공백으로 구분되어 주어진다. 이는 (<em>v<sub>i</sub></em>, <em>w<sub>i</sub></em>) ∈ <em>E</em>를 의미한다.</p>

<p>마지막 줄에 0이 주어지고, 이 경우는 처리하지 않고 프로그램을 종료시켜야 한다.</p>

### 출력 

 <p>각 테스트 케이스마다 한 줄에 걸쳐 bottom(<em>G</em>)의 모든 노드를 출력한다. 노드는 공백으로 구분해야 하며, 오름차순이어야 한다. 만약, bottom(<em>G</em>)가 공집합이면 빈 줄을 출력한다.</p>

