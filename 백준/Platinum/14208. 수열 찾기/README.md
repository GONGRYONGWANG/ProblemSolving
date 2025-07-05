# [Platinum IV] 수열 찾기 - 14208 

[문제 링크](https://www.acmicpc.net/problem/14208) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 수학

### 제출 일자

2025년 7월 6일 05:35:38

### 문제 설명

<p>총 N개의 양의 정수로 이루어진 수열 B = B<sub>0</sub>, ..., B<sub>N-1</sub>가 주어진다. 이때, 아래와 같은 성질을 만족하는 수열 A = A<sub>0</sub>, ..., A<sub>N-1</sub>을 만들려고 한다.</p>

<ul>
	<li>수열 A의 모든 수는 서로 달라야 한다.</li>
	<li>모든 A<sub>i</sub>는 1보다 커야 한다.</li>
	<li>모든 i에 대해서, A<sub>i</sub>^B<sub>i</sub> (A<sub>i</sub>의 B<sub>i</sub>제곱)은 P<sub>i</sub>로 나누어 떨어져야 한다. 이때, P<sub>i</sub>는 A에서 A<sub>i</sub>를 제외한 수를 모두 곱한 값이다. 즉, P<sub>i</sub> = A<sub>0</sub>×A<sub>1</sub>×...×A<sub>i-1</sub>×A<sub>i+1</sub>×...×A<sub>N-1</sub> 이다.</li>
</ul>

<p>수열 A를 만들 수 있는지 없는지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 수열의 크기 N (2 ≤ N ≤ 50)이 주어진다. 둘째 줄에는 수열 B가 주어진다. (1 ≤ B<sub>i</sub> ≤ 10)</p>

### 출력 

 <p>첫째 줄에 수열 A를 만들 수 있으면 1을 없으면 0을 출력한다.</p>

