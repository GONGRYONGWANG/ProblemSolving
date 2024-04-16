# [Platinum II] Biathlon - 14059 

[문제 링크](https://www.acmicpc.net/problem/14059) 

### 성능 요약

메모리: 2704 KB, 시간: 52 ms

### 분류

볼록 껍질, 기하학, 수학

### 제출 일자

2024년 4월 16일 20:28:24

### 문제 설명

<p>Piggy decided to organize a biathlon race, where the competitors would compete in two disciplines. She invited N competitors, who have the following characteristics:</p>

<ul>
	<li>Each competitor has velocities V<sub>1</sub> and V<sub>2</sub>, for the two disciplines, respectively.</li>
	<li>The competitors have constant velocities (V<sub>1</sub> and V<sub>2</sub>) throughout the respective tracks.</li>
	<li>The distance, which a competitor covers for time t<sub>1</sub> in the first discipline is S<sub>1</sub> = V<sub>1</sub>t<sub>1</sub>, and the distance for the second discipline for time t<sub>2</sub> is S<sub>2</sub> = V<sub>2</sub>t<sub>2</sub>.</li>
	<li>A competitor wins, if the sum of his times is uniquely the smallest among these of all competitors (i.e. strictly less than all the others).</li>
</ul>

<p>As an organizer, Piggy can choose whatever distances she likes (non-negative real numbers S<sub>1</sub> and S<sub>2</sub>) for each of the two disciplines. Now she is wondering which competitors are potential winners, that’s to say, whether there exist S<sub>1</sub> and S<sub>2</sub> to ensure them victory.</p>

<p>Write a program biathlon to determine which competitors can win.</p>

### 입력 

 <p>On the first line of the standard input, N is given. On the next N lines are given two positive integers V<sub>1</sub> and V<sub>2</sub>, separated by a space: the velocities of the i-th competitor (for i=0, 1, …, N-1).</p>

### 출력 

 <p>On one line of the standard output, print the indexes of the competitors who can win. The indexes should be in increasing order, separated by spaces. Indexing starts from 0. This line should contain the number -1, when there is no competitor who can win.</p>

