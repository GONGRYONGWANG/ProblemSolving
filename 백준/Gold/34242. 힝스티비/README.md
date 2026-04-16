# [Gold V] 힝스티비 - 34242 

[문제 링크](https://www.acmicpc.net/problem/34242) 

### 성능 요약

메모리: 2912 KB, 시간: 12 ms

### 분류

구현, 문자열, 브루트포스 알고리즘, 많은 조건 분기

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<p>덧셈, 뺄셈, <em><strong style="background-color:#000;background-image:linear-gradient(163deg,#000 0%,#999 50%,#000 100%);background-size:100%;-webkit-background-clip:text;-moz-background-clip:text;-webkit-text-fill-color:transparent;-moz-text-fill-color:transparent;">XOR</strong></em>을 공부하던 나도리는 각 연산자를 나열하다가 <strong>표정 문자열</strong>이라는 것을 만들었다. 표정 문자열은 <code>+</code>, <code>-</code>, <code>^</code>으로만 이루어진 문자열이다.<code>+^+</code>은 뭔가 신나 보이는 표정이고, <code>-^-</code>은 뭔가 힝스러운 표정이다.</p>

<p>표정 문자열의 흥미도는 문자열에 존재하는 아래 부분 문자열의 개수에 따라 정해진다.</p>

<ul>
	<li><code>+^+</code>: 각 $1$점</li>
	<li><code>-^-</code>: 각 $-1$점</li>
</ul>

<p>표정 문자열을 만든 후, 월간 향유회 멤버들은 표정 문자열을 이용하여 매일 아침에 운세를 보기 시작했다.</p>

<p>표정 문자열 $S$를 나도리에게 보여 주면, 나도리는 $S$의 흥미도를 알려 준다.</p>

<p>힝스한 표정이 너무 많으면 아침부터 기분도 힝스해지기 때문에 나도리는 기특한 생각을 하나 해 냈다.</p>

<blockquote>
<p>$S$에서 최대 하나의 문자를 지운 상태에서 흥미도의 최댓값을 알려 주자!</p>
</blockquote>

<p>표정 문자열이 주어졌을 때 나도리가 적절한 운세를 볼 수 있게 해 주자.</p>

### 입력 

 <p>첫째 줄에 표정 문자열 $S$가 주어진다. ($1 \leq \left\vert S \right\vert \leq 300\,000$)</p>

### 출력 

 <p>첫째 줄에 $S$에서 최대 하나의 문자를 지운 상태에서 흥미도의 최댓값을 출력한다.</p>

