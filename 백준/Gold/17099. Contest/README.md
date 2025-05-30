# [Gold III] Contest - 17099 

[문제 링크](https://www.acmicpc.net/problem/17099) 

### 성능 요약

메모리: 32556 KB, 시간: 284 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 정렬

### 제출 일자

2025년 2월 2일 23:10:36

### 문제 설명

<p>승민이는 세계 최고의 프로그래머로, 대회에 참여하기만 하면 1등을 한다는 것은 여러분 모두가 알고 있는 사실이다. 승민이는 상금을 벌기 위해 여러 프로그래밍 대회를 참여하기로 하였는데, 총 N개의 대회가 있다.</p>

<p>당연하지만, 시간이 겹치는 대회가 있다면 그 대회 여러개를 동시에 칠 수는 없을 것이다. 그렇기에 승민이는 N개의 대회가 시작하는 시간, 끝나는 시간, 그리고 상금이 주어지면 최대로 상금을 벌 수 있는 방법으로 대회를 치루기로 하였다. 당연하지만 승민이는 모든 대회에서 상금을 받을 수 있다. 또한, 이동 시간을 고려해서 전 대회가 끝나는 시간과 다음 대회가 시작하는 시간이 같으면 안 된다.</p>

### 입력 

 <p>첫 줄에 N이 주어진다. (1 ≤ N ≤ 3×10<sup>5</sup>)</p>

<p>N개의 줄에 걸쳐 대회의 정보가 주어지는데, S<sub>i</sub>, E<sub>i</sub>, C<sub>i</sub>가 공백으로 구분되어 순서대로 주어진다. 이는 i번째 대회는 S<sub>i</sub>시간에 시작해 E<sub>i</sub>시간에 끝나며 상금은 C<sub>i</sub>라는 뜻이다. (0 ≤ S<sub>i</sub> < E<sub>i</sub> ≤ 10<sup>9</sup>, 1 ≤ C<sub>i</sub> ≤ 10<sup>3</sup>)</p>

### 출력 

 <p>승민이가 받을 수 있는 최대 상금을 출력한다.</p>

