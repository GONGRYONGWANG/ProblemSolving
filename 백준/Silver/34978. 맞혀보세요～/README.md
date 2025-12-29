# [Silver V] 맞혀보세요~ - 34978 

[문제 링크](https://www.acmicpc.net/problem/34978) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2025년 12월 29일 22:06:36

### 문제 설명

<p>짐비는 휴이 선배와 같이 규칙 맞히기 퀴즈를 하고 있었다. 규칙 맞히기 퀴즈란 질문자가 제시한 문자열이 답변자가 정한 모든 규칙을 만족한다면 <span style="color:#e74c3c;"><code>yes</code></span>, 아니라면 <span style="color:#e74c3c;"><code>no</code></span>를 답변하는 게임이다.</p>

<p>모든 규칙은 아래와 같은 형식을 가진다.</p>

<blockquote>
<p>어떤 문자 $X$의 바로 뒤에는 허용된 문자 집합 $\{ Y_1, \cdots , Y_M \}$에 속하는 문자가 오거나, 아무것도 오지 않고 문자열이 끝나야 한다.</p>
</blockquote>

<p>예를 들어 규칙이 "문자 <code><span style="color:#e74c3c;">a</span></code>의 바로 뒤에는 집합 {<code><span style="color:#e74c3c;">b</span></code>, <code><span style="color:#e74c3c;">c</span></code>}에 속하는 문자가 오거나 아무것도 오지 않는다" 라면</p>

<ul>
<li><code><span style="color:#e74c3c;">abx</span></code>: <code><span style="color:#e74c3c;">a</span></code>의 바로 뒤에 <code><span style="color:#e74c3c;">b</span></code>가 왔고, <code><span style="color:#e74c3c;">b</span></code>는 허용된 집합에 속하므로 조건을 만족한다. 즉, 이 질문에 대한 답은 <code><span style="color:#e74c3c;">yes</span></code>이다.</li>
<li><code><span style="color:#e74c3c;">ba</span></code>: <code><span style="color:#e74c3c;">a</span></code>의 바로 뒤에 아무것도 오지 않았기 때문에 조건을 만족한다. 즉, 이 질문에 대한 답은 <code><span style="color:#e74c3c;">yes</span></code>이다.</li>
<li><code><span style="color:#e74c3c;">adx</span></code>: <code><span style="color:#e74c3c;">a</span></code>의 바로 뒤에 <code><span style="color:#e74c3c;">d</span></code>가 왔고, <code><span style="color:#e74c3c;">d</span></code>는 허용된 집합에 속하지 않으므로 조건을 만족하지 않는다. 즉, 이 질문에 대한 답은 <code><span style="color:#e74c3c;">no</span></code>이다.</li>
</ul>

<p>규칙이 주어지지 않은 문자 뒤에는 무엇이 오든 상관없다.</p>

<p>퀴즈는 짐비가 내고, 정답은 휴이 선배가 맞히고 있다. 휴이 선배는 제한 시간 안에 대답해야 하지만 전날에 메이플스토리를 너무 많이 한 탓에 머리가 돌아가지 않았고, 결국 여러분에게 도움을 청했다.</p>

<p>$N$개의 규칙들과 짐비의 새로운 질문 문자열 $S$가 주어진다. 이 질문이 모든 규칙을 만족하여 <code><span style="color:#e74c3c;">yes</span></code>라고 대답해야 하는지, 아니면 <code><span style="color:#e74c3c;">no</span></code>라고 대답해야 하는지 판단하는 프로그램을 작성하자.</p>

### 입력 

 <p>첫번째 줄에 규칙의 수 $N$이 주어진다. $(1 \leq N \leq 26)$</p>

<p>두번째 줄부터 $N$개의 줄에 걸쳐, 한 줄에 하나씩 규칙을 나타내는 $X, M, Y_1, \cdots,Y_M$ 이 공백으로 구분되어 입력으로 주어진다. 이는 영문 소문자 $X$ 의 바로 뒤에는 집합 $\{Y_1, \cdots, Y_M\}$에 속하는 영문 소문자가 오거나 아무것도 오지 않고 문자열이 끝나야 함을 의미한다. $(1 \leq M \leq 20)$</p>

<p>각 규칙에 대해 $X$는 모두 서로 다르며, 한 규칙 내의 $Y_1, \cdots ,Y_M$ 중 중복되는 영문 소문자는 없다.</p>

<p>마지막 줄에 영문 소문자로 이루어진 짐비의 질문 문자열 $S$가 주어진다. $(1 \leq |S| \leq 1\,000)$</p>

### 출력 

 <p>첫번째 줄에 질문 문자열 $S$가 $N$개의 모든 규칙을 만족하면 <span style="color:#e74c3c;"><code>yes</code></span>를, 하나라도 만족하지 않는다면 <span style="color:#e74c3c;"><code>no</code></span>를 출력한다.</p>

