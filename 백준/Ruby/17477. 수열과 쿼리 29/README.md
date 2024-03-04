# [Ruby IV] 수열과 쿼리 29 - 17477 

[문제 링크](https://www.acmicpc.net/problem/17477) 

### 성능 요약

메모리: 224680 KB, 시간: 3452 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 3월 5일 01:18:31

### 문제 설명

<p>길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어지고, B<sub>i</sub> = 0를 만족하는 길이가 N인 수열 B가 있다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오. </p>

<ul>
	<li><code>1 L R X</code>: 모든 L ≤ i ≤ R에 대해서 A<sub>i</sub> = A<sub>i</sub> + X를 적용한다.</li>
	<li><code>2 L R Y</code>: 모든 L ≤ i ≤ R에 대해서 A<sub>i</sub> = max(A<sub>i</sub>, Y)를 적용한다.</li>
	<li><code>3 L R Y</code>: 모든 L ≤ i ≤ R에 대해서 A<sub>i</sub> = min(A<sub>i</sub>, Y)를 적용한다.</li>
	<li><code>4 L R</code>: B<sub>L</sub> + B<sub>L+1</sub> + ... + B<sub>R</sub>을 출력한다.</li>
</ul>

<p>1, 2, 3번 쿼리에 의해 A<sub>i</sub>가 변경될 때마다 B<sub>i</sub>의 값은 1 증가한다.</p>

### 입력 

 <p>첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 500,000)</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (-10<sup>9</sup> ≤ A<sub>i</sub> ≤ 10<sup>9</sup>)</p>

<p>셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 500,000)</p>

<p>넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. (1 ≤ L ≤ R ≤ N, -2,000 ≤ X ≤ 2,000, -10<sup>9</sup> ≤ Y ≤ 10<sup>9</sup>) 4번 쿼리는 한 번 이상 주어진다.</p>

### 출력 

 <p>4번 쿼리의 결과를 한 줄에 하나씩 출력한다.</p>

