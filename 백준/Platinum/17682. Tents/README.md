# [Platinum IV] Tents - 17682 

[문제 링크](https://www.acmicpc.net/problem/17682) 

### 성능 요약

메모리: 72524 KB, 시간: 76 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2025년 1월 29일 14:16:31

### 문제 설명

<p>JOI-kun runs a campsite. This campsite is divided into a rectangular grid of H rows and W columns. The rows are parallel to the east-west direction, and the columns are parallel to the north-south direction. The section in the i-th row from north and j-th column from east is called the section (i, j).</p>

<p>JOI-kun is going to put up some tents in some sections. Each tent must occupy exactly one section. No two tents may occupy the same section.</p>

<p>Each tent has one entrance directed to one of the four directions: north, south, east or west. The directions of the entrances of the tents put up in the campsite must satisfy the following conditions.</p>

<ul>
	<li>If both of the two sections (i<sub>1</sub>, j) and (i<sub>2</sub>, j) (1 ≤ i<sub>1</sub> < i<sub>2</sub> ≤ H, 1 ≤ j ≤ W) are occupied by tents, then the entrance of the tent in the section (i<sub>1</sub>, j) must be directed to south, and the entrance of the tent in the section (i<sub>2</sub>, j) must be directed to north.</li>
	<li>If both of the two sections (i, j<sub>1</sub>) and (i, j<sub>2</sub>) (1 ≤ i<sub>1</sub> < i<sub>2</sub> ≤ H, 1 ≤ j ≤ W) are occupied by tents, then the entrance of the tent in the section (i, j<sub>1</sub>) must be directed to east, and the entrance of the tent in the section (i, j<sub>2</sub>) must be directed to west.</li>
</ul>

<p>JOI-kun became curious about the number of ways to put up at least one tent in the campsite. Two ways to put up tents are distinguished when there exists a section such that the status of the tent in the section (existence of a tent, or the direction of the entrance of the tent) differs.</p>

<p>Write a program which calculates the remainder of the number of ways to put up at least one tent satisfying the condition described in the problem statement, divided by 1 000 000 007.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<ul>
	<li>The first line of input contains two integers H and W. This means that the campsite ran by JOI-kun is divided into H rows and W columns.</li>
</ul>

### 출력 

 <p>Write one line to the standard output. The output should contain the remainder of the number of ways to put up at least one tent satisfying the condition described in the problem statement, divided by 1 000 000 007.</p>

