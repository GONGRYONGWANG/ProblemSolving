# [Diamond II] 수열과 쿼리 2 - 13543 

[문제 링크](https://www.acmicpc.net/problem/13543) 

### 성능 요약

메모리: 13772 KB, 시간: 656 ms

### 분류

스플레이 트리, 트리

### 제출 일자

2023년 12월 2일 15:42:25

### 문제 설명

<p>길이가 N인 수열 A<sub>0</sub>, A<sub><span style="font-size:10.8333px">1</span></sub>, ..., A<sub>N-1</sub>이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오. (0 ≤ A<sub>i</sub> < 2<sup>32</sup>)</p>

<ul>
	<li><code>1 p v</code>: A<sub>p</sub>의 앞에 v를 추가한다. p가 A의 길이와 같은 경우에는 가장 마지막에 추가하는 것이다. (0 ≤ p ≤ A의 길이, 0 ≤ v < 2<sup>32</sup>)</li>
	<li><code>2 p</code>: A<sub>p</sub>를 제거한다. (0 ≤ p < A의 길이)</li>
	<li><code>3 p v</code>: A<sub>p</sub>를 v로 바꾼다. (0 ≤ p < A의 길이, 0 ≤ v < 2<sup>32</sup>)</li>
	<li><code>4 l r k</code>: l ≤ i ≤ r에 대해서 (ΣA<sub>i</sub> × (i - l + 1)<sup>k</sup>) mod 2<sup>32</sup>를 구한 다음 출력한다. (0 ≤ k ≤ 10)</li>
</ul>

### 입력 

 <p>첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.</p>

<p>둘째 줄에는 A<sub>0</sub>, A<sub>1</sub>, ..., A<sub>N-1</sub>이 주어진다.</p>

<p>셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.</p>

<p>넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다.</p>

### 출력 

 <p>각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.</p>

