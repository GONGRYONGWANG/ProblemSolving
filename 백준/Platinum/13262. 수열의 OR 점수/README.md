# [Platinum I] 수열의 OR 점수 - 13262 

[문제 링크](https://www.acmicpc.net/problem/13262) 

### 성능 요약

메모리: 197452 KB, 시간: 876 ms

### 분류

분할 정복, 분할 정복을 사용한 최적화, 다이나믹 프로그래밍

### 제출 일자

2025년 5월 14일 20:26:24

### 문제 설명

<p>크기가 N인 수열 A와 정수 K가 주어진다. 이때, 수열을 K개의 연속된 비어있지 않은 그룹으로 나누어야 한다. 수열의 모든 원소는 한 그룹에 포함되어 있어야 한다.</p>

<p>각각의 그룹은 두 정수 L과 R로 나타낼 수 있으며, L번째 수부터 R번째 수까지 그룹에 포함된다는 의미를 가진다. 그룹의 비용은 그룹에 속한 모든 원소를 비트 연산 OR한 값이다.</p>

<p>수열의 OR 점수는 모든 그룹의 점수를 합한 것이다.</p>

<p>수열을 K개의 연속된 비어있지 않은 그룹으로 나누어서 수열의 OR 점수의 최댓값을 구하는 프로그램을 작성하시오. </p>

### 입력 

 <p>첫째 줄에 N (1 ≤ N ≤ 5000)과 K (1 ≤ K ≤ N)이 주어진다.</p>

<p>둘째 줄에는 수열의 원소 A<sub>i</sub> (0 ≤ A<sub>i</sub> ≤ 2<sup>30</sup>)이 주어진다.</p>

### 출력 

 <p>수열의 OR 점수의 최댓값을 출력한다.</p>

