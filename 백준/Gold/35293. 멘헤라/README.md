# [Gold IV] 멘헤라 - 35293 

[문제 링크](https://www.acmicpc.net/problem/35293) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그리디 알고리즘, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2026년 3월 5일 23:30:11

### 문제 설명

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/911c13a8-c8db-4e49-934a-d540d0158f46/-/preview/" style="width: 500px; height: 400px;"></p>

<p style="text-align: center;"><small>급성 멘헤라가 온 wlgh7407</small></p>

<p>멘헤라가 된 wlgh7407은 마음의 안정을 찾기 위해 알코올을 섭취하여 목표 단위 취기에 도달하고자 한다. wlgh7407의 앞에는 용량이 동일한 네 가지 선택지가 놓여 있다.</p>

<table class="table table-bordered">
<thead>
<tr>
<td><strong>선택지</strong></td>
<td><strong>취기 변화량</strong></td>
</tr>
</thead>
<tbody>
<tr>
<td>순하리 레몬진 9도</td>
<td><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>+</mo><mn>9</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$+9$</span></mjx-container> 단위</td>
</tr>
<tr>
<td>순하리 레몬진 7도</td>
<td><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>+</mo><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$+7$</span></mjx-container> 단위</td>
</tr>
<tr>
<td>순하리 레몬진 4.5도</td>
<td><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c2E"></mjx-c><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>+</mo><mn>4.5</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$+4.5$</span></mjx-container> 단위</td>
</tr>
<tr>
<td>생수</td>
<td><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>−</mo><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$-2$</span></mjx-container> 단위</td>
</tr>
</tbody>
</table>

<p>wlgh7407은 목표 취기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>에 도달하기 위해 마셔야 하는 전체 액체의 양을 최소화하고 싶어 한다. wlgh7407이 정확히 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> 단위 취기에 도달할 수 있는 선택의 최소 횟수를 알아내는 프로그램을 작성하시오.</p>

<p>초기 취기는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>이고, 취기는 음수가 될 수 없다.</p>

### 입력 

 <p>첫 번째 줄에 목표 취기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>은 음이 아닌 실수이다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3C"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>N</mi><mo><</mo><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mn>16</mn></mrow></msup><mo>+</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0 \le N < 10^{16} + 1$</span></mjx-container>)</p>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>은 소수점 첫째 자리까지 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 목표 취기에 도달하기 위한 최소 섭취 횟수를 출력한다. 만약 어떠한 조합으로도 정확히 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>을 만들 수 없다면 <code><span style="color:#e74c3c;">-1</span></code>을 출력한다.</p>

