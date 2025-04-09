# [Gold III] 우주왕자 사교파티 - 30390 

[문제 링크](https://www.acmicpc.net/problem/30390) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

수학, 정수론

### 제출 일자

2025년 4월 9일 22:50:10

### 문제 설명

<p>우주왕자 <span style="background-color:#000;background-image:linear-gradient(163deg,#000 0%,#ccc 50%,#000 100%);background-size:100%;-webkit-background-clip:text;-moz-background-clip:text;-webkit-text-fill-color:transparent;-moz-text-fill-color:transparent;"><em><b>VITAS</b></em></span>는 지구인들과 친해지기 위해 사교파티를 열었다. <span style="background-color:#000;background-image:linear-gradient(163deg,#000 0%,#ccc 50%,#000 100%);background-size:100%;-webkit-background-clip:text;-moz-background-clip:text;-webkit-text-fill-color:transparent;-moz-text-fill-color:transparent;"><em><b>VITAS</b></em></span>는 포도주 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A$</span></mjx-container>병과 빵 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>개를 가지고 있고, 포도주 한 병을 빵 한 개로 바꾸거나 빵 한 개를 포도주 한 병으로 바꾸는 마법을 최대 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>번 부릴 수 있다.</p>

<p><span style="background-color:#000;background-image:linear-gradient(163deg,#000 0%,#ccc 50%,#000 100%);background-size:100%;-webkit-background-clip:text;-moz-background-clip:text;-webkit-text-fill-color:transparent;-moz-text-fill-color:transparent;"><em><b>VITAS</b></em></span>는 초대한 모든 지구인에게 각각 동일한 수의 포도주와 빵을 나눠 줄 것이다. 한 종류를 아무에게도 나눠 주지 않는 것도 가능하다. 단, 포도주와 빵을 나눠주고 난 뒤 남은 것이 있으면 안 된다.</p>

<p><span style="background-color:#000;background-image:linear-gradient(163deg,#000 0%,#ccc 50%,#000 100%);background-size:100%;-webkit-background-clip:text;-moz-background-clip:text;-webkit-text-fill-color:transparent;-moz-text-fill-color:transparent;"><em><b>VITAS</b></em></span>가 위 조건을 만족시키면서 초대할 수 있는 지구인의 수의 최댓값을 구하여라.</p>

### 입력 

 <p>첫째 줄에 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>가 공백을 사이에 두고 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>A</mi><mo>,</mo><mi>B</mi><mo>,</mo><mi>K</mi><mo>≤</mo><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mn>10</mn></mrow></msup><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 \le A, B, K \le 10^{10})$</span> </mjx-container></p>

### 출력 

 <p><span style="background-color:#000;background-image:linear-gradient(163deg,#000 0%,#ccc 50%,#000 100%);background-size:100%;-webkit-background-clip:text;-moz-background-clip:text;-webkit-text-fill-color:transparent;-moz-text-fill-color:transparent;"><em><b>VITAS</b></em></span>가 조건을 만족시키면서 초대할 수 있는 지구인의 수의 최댓값을 출력한다.</p>

