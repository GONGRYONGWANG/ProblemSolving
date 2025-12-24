# [Bronze IV] 셔틀 탈래 말래 탈래 말래 애매하긴 해 - 34946 

[문제 링크](https://www.acmicpc.net/problem/34946) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 구현, 사칙연산, 많은 조건 분기

### 제출 일자

2025년 12월 25일 02:04:21

### 문제 설명

<p>화연이는 지각 위기에 놓였다!</p>

<p>현재 화연이는 이화여대 정문 셔틀 정류장에 있고, 다음 수업은 멀기로 유명한 공학관에서 진행된다.</p>

<p>화연이에게는 두 가지 선택지가 있다.</p>

<ul>
<li>셔틀을 기다렸다가 타고 공학관까지 간다.</li>
<li>셔틀을 기다리지 않고 곧바로 공학관까지 걸어간다.</li>
</ul>

<p>강의실에 도착한 시간이 수업이 시작하는 시간보다 빠르거나 같다면 지각이 아니다. 즉, 강의실까지의 이동 시간이 수업 시작까지 남은 시간보다 작거나 같다면 지각이 아니다. 편의상 공학관에서 강의실까지 이동하는 시간은 무시한다.</p>

<p>화연이는 지각을 피할 수 있을까?</p>

### 입력 

 <p>첫째 줄에 셔틀이 정문 정류장까지 도착할 때까지 남은 시간 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A$</span></mjx-container>, 셔틀이 정문에서 공학관까지 가는 데 걸리는 시간 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>, 정문 정류장에서 공학관까지 걸어가는 데 걸리는 시간 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>C</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$C$</span></mjx-container>, 수업 시작까지 남은 시간 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>D</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$D$</span></mjx-container>가 공백으로 구분되어 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c36"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>A</mi><mo>,</mo><mi>B</mi><mo>,</mo><mi>C</mi><mo>,</mo><mi>D</mi><mo>≤</mo><mn>60</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 ≤ A, B, C, D ≤ 60$</span></mjx-container>)</p>

<p>입력으로 들어오는 모든 수는 정수이다.</p>

### 출력 

 <p>만약 어떤 선택을 하더라도 지각을 피할 수 있다면 <span style="color:#e74c3c;"><code>~.~</code></span>을, 어떤 선택을 하더라도 지각을 피할 수 없다면 <span style="color:#e74c3c;"><code>T.T</code></span>를 출력한다. 셔틀을 타면 지각을 피할 수 있지만, 걸어가면 지각을 피할 수 없는 경우에는 <span style="color:#e74c3c;"><code>Shuttle</code></span>을, 걸어가면 지각을 피할 수 있지만, 셔틀을 타면 지각을 피할 수 없는 경우 <span style="color:#e74c3c;"><code>Walk</code></span>를 출력한다.</p>

