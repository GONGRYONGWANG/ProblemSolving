# [Gold I] 문자열 지우기 - 31948 

[문제 링크](https://www.acmicpc.net/problem/31948) 

### 성능 요약

메모리: 134020 KB, 시간: 200 ms

### 분류

다이나믹 프로그래밍, 게임 이론

### 제출 일자

2025년 5월 2일 00:08:56

### 문제 설명

<p>준범이와 명섭이가 문자열 지우기 게임을 하고 있다.</p>

<p>문자열 지우기 게임은 <span style="color:#e74c3c;">0</span>, <span style="color:#e74c3c;">1</span>, <span style="color:#e74c3c;">? </span>만으로 이루어진 문자열을 사용하는 게임이다. 문자열에 <span style="color:#e74c3c;">?</span>는 최대 하나 존재한다. 두 명이 다음 중 한 가지 행동을 번갈아 진행한다.</p>

<ul>
	<li>문자열 가장 앞의 연속된 같은 숫자 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>개 이상을 지운다.</li>
	<li>문자열 가장 뒤의 연속된 같은 숫자 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>개 이상을 지운다.</li>
	<li>문자열에 존재하는 <span style="color:#e74c3c;">?</span> 하나를 <span style="color:#e74c3c;">0</span> 또는 <span style="color:#e74c3c;">1</span>로 바꾼다.</li>
</ul>

<p>준범이부터 문자열 지우기 게임을 시작한다. 더 이상 할 수 있는 행동이 없는 경우 패배한다. 준범이와 명섭이 모두 이기기 위해 최선을 다할 때 둘 중 누가 이기게 되는지 구해보자.</p>

### 입력 

 <p>첫째 줄에 문자열 지우기 게임에 사용할 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어진다.</p>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>는 <span style="color:#e74c3c;">0</span>, <span style="color:#e74c3c;">1</span>, <span style="color:#e74c3c;">?</span> 만으로 이루어진 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>500</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\,500$</span></mjx-container> 이하의 문자열이고 <span style="color:#e74c3c;">?</span>는 둘 이상 주어지지 않는다.</p>

### 출력 

 <p>준범이가 이기게 되면 <span style="color:#e74c3c;">1</span>, 명섭이가 이기게 되면 <span style="color:#e74c3c;">0</span>을 출력한다.</p>

