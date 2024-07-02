# [Gold I] 슬라임 키우기 - 25620 

[문제 링크](https://www.acmicpc.net/problem/25620) 

### 성능 요약

메모리: 9904 KB, 시간: 316 ms

### 분류

자료 구조, 수학, 우선순위 큐

### 제출 일자

2024년 7월 2일 14:33:39

### 문제 설명

<p><em>N</em>마리의 슬라임이 있다. <em>i</em>번째 슬라임의 크기는 <em>a</em><sub><em>i</em></sub>이다.</p>

<p>생물학자인 레프는 슬라임의 크기를 키워주는 비약을 총 <em>Q</em>번, 순서대로 사용해 슬라임의 크기를 키울 것이다. 이중 <em>i</em>번째로 사용할 비약은 현재 크기가 <em>x</em><sub><em>i</em></sub> 이하인 슬라임의 크기를 순식간에 <em>y</em><sub><em>i</em></sub>배 불려내는 효과를 가지고 있다.</p>

<p><em>Q</em>번의 비약을 차례대로 사용한 후, 슬라임들의 크기를 <strong>오름차순으로 정렬하여</strong> 나타내보자.</p>

### 입력 

 <p>첫째 줄에 양의 정수 <em>N</em>과 <em>Q</em>가 공백으로 구분되어 주어진다. (1 ≤ <em>N</em>, <em>Q</em> ≤ 200 000)</p>

<p>둘째 줄에 <em>N</em>개의 정수 <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, ⋯, <em>a</em><sub><em>N</em></sub>가 공백으로 구분되어 주어진다. (0 ≤ <em>a</em><sub><em>i</em></sub> ≤ 10<sup>9</sup>)</p>

<p>셋째 줄부터 <em>Q</em>개의 줄에 걸쳐 <em>x</em><sub><em>i</em></sub>와 <em>y</em><sub><em>i</em></sub>가 주어진다. 구체적으로 모든 1 ≤ <em>i</em> ≤ <em>N</em>에 대해, (<em>i</em> + 2)번째 줄에는 <em>x</em><sub><em>i</em></sub>와 <em>y</em><sub><em>i</em></sub>가 공백으로 구분되어 주어진다. (0 ≤ <em>x</em><sub><em>i</em></sub>, <em>y</em><sub><em>i</em></sub> ≤ 10<sup>9</sup>)</p>

### 출력 

 <p>첫째 줄에 모든 비약을 차례대로 사용한 후 슬라임들의 크기를 <strong>오름차순으로 정렬하여</strong>, 공백으로 구분하여 출력한다.</p>

