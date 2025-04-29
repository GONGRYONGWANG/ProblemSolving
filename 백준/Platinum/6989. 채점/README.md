# [Platinum II] 채점 - 6989 

[문제 링크](https://www.acmicpc.net/problem/6989) 

### 성능 요약

메모리: 44068 KB, 시간: 1876 ms

### 분류

비트마스킹, 비트 집합, 다이나믹 프로그래밍

### 제출 일자

2025년 4월 30일 01:16:10

### 문제 설명

<p>N개의 문항이 있는 답안지를 채점하고자 한다. 1번부터 N번까지 각 문항에 대한 배점이 각각 S<sub>1</sub>, S<sub>2</sub>, ..., S<sub>N</sub>일 경우, 문항별 점수와 답안지의 총점은 다음과 같이 결정된다.</p>

<ol>
	<li>틀린 문항에 대한 점수는 0이다. </li>
	<li>1번 문항이 맞으면 이 문항의 점수는 S<sub>1</sub>이다. i(2 ≤ i ≤ N)번 문항의 답이 맞을 경우에는 (i-1)번 문항의 정답 여부에 따라 이 문항의 점수가 다르게 정해진다.
	<ol style="list-style-type:lower-alpha">
		<li>(i-1)번 문항의 답도 맞으면 i번 문항의 점수는 S<sub>i</sub>에 (i-1)번 문항의 점수를 더한 값이 된다.</li>
		<li>(i-1)번 문항의 답이 틀리면 i번 문항의 점수는 S<sub>i</sub>이다.</li>
	</ol>
	</li>
	<li>답안지의 총점은 위와 같이 계산된 문항별 점수의 합이다.</li>
</ol>

<p>예를 들어 9개 문항이 있는 시험에서 문항별 배점이 <표 1>과 같다고 하자.</p>

<table class="table table-bordered table-center-40 td-center th-center">
	<tbody>
		<tr>
			<th style="width:13%">문항 번호</th>
			<td style="width:3%">1</td>
			<td style="width:3%">2</td>
			<td style="width:3%">3</td>
			<td style="width:3%">4</td>
			<td style="width:3%">5</td>
			<td style="width:3%">6</td>
			<td style="width:3%">7</td>
			<td style="width:3%">8</td>
			<td style="width:3%">9</td>
		</tr>
		<tr>
			<th>문항 배점</th>
			<td>3</td>
			<td>2</td>
			<td>7</td>
			<td>2</td>
			<td>6</td>
			<td>8</td>
			<td>2</td>
			<td>5</td>
			<td>2</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;"><표 1></p>

<p>어떤 답안지에서 문항 1번부터 9번까지에 대하여 제출한 답이 맞는지(○) 혹은 틀린지(×)가 아래 <표 2>와 같다고 하자.</p>

<table class="table table-bordered table-center-40 td-center th-center">
	<tbody>
		<tr>
			<th style="width:13%">문항 번호</th>
			<td style="width:3%">1</td>
			<td style="width:3%">2</td>
			<td style="width:3%">3</td>
			<td style="width:3%">4</td>
			<td style="width:3%">5</td>
			<td style="width:3%">6</td>
			<td style="width:3%">7</td>
			<td style="width:3%">8</td>
			<td style="width:3%">9</td>
		</tr>
		<tr>
			<th>문항 배점</th>
			<td>○</td>
			<td>×</td>
			<td>○</td>
			<td>○</td>
			<td>○</td>
			<td>×</td>
			<td>×</td>
			<td>○</td>
			<td>×</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;"><표 2></p>

<p>그러면 문항별 점수는 다음 <표 3>과 같으므로 답안지의 총점은 39점이 된다.</p>

<table class="table table-bordered table-center-40 td-center th-center">
	<tbody>
		<tr>
			<th style="width:13%">문항 번호</th>
			<td style="width:3%">1</td>
			<td style="width:3%">2</td>
			<td style="width:3%">3</td>
			<td style="width:3%">4</td>
			<td style="width:3%">5</td>
			<td style="width:3%">6</td>
			<td style="width:3%">7</td>
			<td style="width:3%">8</td>
			<td style="width:3%">9</td>
		</tr>
		<tr>
			<th>문항 배점</th>
			<td>3</td>
			<td>0</td>
			<td>7</td>
			<td>9</td>
			<td>15</td>
			<td>0</td>
			<td>0</td>
			<td>5</td>
			<td>0</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;"><표 3></p>

<p>그러나 어떤 수는 결코 답안지의 총점으로 나올 수 없다. 예를 들어, 문항별 배점이 <표 1>과 같을 때, 각 문항에 대하여 어떤 답을 하더라도 73점의 총점을 받을 수는 없다.</p>

<p>문항별 배점과 어떤 자연수 K가 입력으로 주어진다. K보다 크거나 같은 정수로서 총점으로 나올 수 없는 가장 작은 값 M을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 전체 문항 수 N(1 ≤ N ≤ 150)이 주어진다. 다음 줄에는 N개 문항들의 배점이 빈칸을 사이에 두고 차례대로 주어진다. 문항별 배점은 1 이상 100 이하의 정수이다. 마지막 줄에 자연수 K(1 ≤ K ≤ 2,000,000,000)가 주어진다.</p>

### 출력 

 <p>답안지의 총점으로 나올 수 없는 가장 작은 정수 M(M ≥ K)을 첫째 줄에 출력한다.</p>

