# [Platinum V] 모닝커피 (Large) - 12456 

[문제 링크](https://www.acmicpc.net/problem/12456) 

### 성능 요약

메모리: 2164 KB, 시간: 0 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐

### 제출 일자

2024년 8월 30일 02:37:39

### 문제 설명

<p>호토 코코아(이하, 코코아)는 아침의 하루를 커피를 마시는 것으로 시작한다.</p>

<p>코코아의 찬장에는 <strong>N</strong> 종류의 커피가 있고, <strong>i</strong>번의 커피는 <strong>c<sub>i</sub></strong> 잔 분이 남아있으며, 오늘부터 유통기한까지 <strong>t<sub>i</sub></strong> 일 남았다. 그녀는 i번 (1 ≤ <strong>i</strong> ≤ <strong>N</strong>) 종류의 커피를 1잔 마시면, <strong>s<sub>i</sub></strong>만큼의 만족도를 얻는다. 유통기한이 지난 커피는 마실 수 없다. (그러나, 딱 <strong>t<sub>i</sub></strong>일째에는 그 커피를 마실 수 있다.)</p>

<p>예를 들어, <strong>t<sub>i</sub></strong>=1인 경우, 오늘 중에 그 커피를 마시던가, 버리던가 해야 한다.</p>

<p>코코아는 커피를 하루에 한잔, 아침에밖에 마시지 않는다. 찬장에 커피가 하나도 없으면, 만족도를 얻을수 없다. 오늘부터 시작해서 커피를 마시는 것으로, <strong>K</strong>일에 코코아가 얻을수 있는 만족도 합계의 최대를 구하라.</p>

### 입력 

 <p>입력의 제일 첫 줄은 테스트케이스 T이다, 그 뒤로 T개의 테스트 케이스가 입력된다. 각각의 테스트케이스는 1개의 공백으로 구분된 2개의 양의 정수가 포함된 행으로 시작한다.  첫 정수는 커피의 종류 N을 의미하며, 다음 정수는 최대로 얻을 수 있는 만족도를 계산할 날짜인 K를 의미한다. 그 뒤에 N개의 커피 종류에 대한 남아있는 커피 개수, 유통기한, 만족도를 아래의 포맷으로 입력받는다.</p>

<pre>ci ti si</pre>

<p>값의 범위</p>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 100</li>
	<li>1 ≤ <strong>c<sub>i</sub></strong> ≤ K</li>
	<li>1 ≤ <strong>t<sub>i</sub></strong> ≤ K</li>
	<li>1 ≤ <strong>s<sub>i</sub></strong> ≤ 1000</li>
	<li>1 ≤ <strong>N</strong> ≤ 100</li>
	<li>1 ≤ <strong>K</strong> ≤ 2 * 10<sup>12</sup> (32bit 정수형을 초과하는 것에 주의)</li>
</ul>

### 출력 

 <p>각 테스트 케이스마다</p>

<pre>Case #X: Y</pre>

<p>을 1행씩 출력한다, X는 테스트 케이스의 번호, Y는 만족도 합계의 최대를 표시한다.</p>

