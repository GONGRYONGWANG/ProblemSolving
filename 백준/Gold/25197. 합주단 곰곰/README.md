# [Gold III] 합주단 곰곰 - 25197 

[문제 링크](https://www.acmicpc.net/problem/25197) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 확률론, 기댓값의 선형성

### 제출 일자

2025년 5월 25일 23:15:19

### 문제 설명

<p>곰곰은 실로폰을 아주 잘 친다.</p>

<p>곰곰의 실로폰 채가 건반에 닿는 순간, 주변의 온 관심은 실로폰이 내는 청아한 소리에 모인다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/23ff7203-d2ba-40b5-bfa0-4f2459c889c5/-/preview/"></p>

<p>곰곰은 이 재능으로 사람들을 행복하게 만들기 위해 합주단을 만들었다.</p>

<p>이 합주단에는 많은 곰곰이 존재하며, 각 곰곰이 한 음씩 맡아, 악보에 맞춰 연주를 한다.</p>

<p>곰곰이 연주하는 실로폰은, 곰곰이 같은 음을 모여서 연주할 때 더 청아한 소리가 나게 된다는 특징이 있으므로, 같은 음을 내는 곰곰을 모아서, 조를 만들기로 결정했다.</p>

<p>성공적으로 연주를 마친 곰곰 합주단은, 각 조원이 자신을 제외한 조원 하나하나와 단둘이 밥을 먹으며 서로 친해지는 시간을 가진다.</p>

<p>이 식사 비용은 합주단장 곰곰이 부담하기에, 공연 전에 미리 필요한 금액을 알아두어야만 비용을 준비할 수 있다.</p>

<p>그렇지만, 아직 연주할 악보가 결정되지 않았기에, 한 조에 몇 명이 들어갈 지 알 수가 없어, 정확한 비용을 계산할 수 없다.</p>

<p>그러므로 곰곰 단장은 <strong>일어날 수 있는 식사 횟수의 기댓값</strong>을 구해서, 그만큼의 비용을 준비하려고 한다.</p>

<p><strong><em>각 곰곰이 연주할 음은 음의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>개 사이에서 같은 확률로 결정된다고 가정한다.</em></strong></p>

<p>단원들이 밥을 먹지 못하는 일이 일어나지 않도록 곰곰 단장을 도와주자!</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d7cd07e3-80e5-4f7c-9aa3-63f23a58801b/-/preview/"></p>

### 입력 

 <p>합주단원의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>1</mn><mtext> </mtext><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \le N \le 1\ 000$</span></mjx-container>), 곰곰이 연주할 수 있는 음의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>K</mi><mo>≤</mo><mn>1</mn><mtext> </mtext><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le K \le 1\ 000$</span></mjx-container>)가 차례로 주어진다.</p>

### 출력 

 <p>식사가 일어나는 횟수의 기댓값을 출력한다. 절대/상대 오차는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mo>−</mo><mn>6</mn></mrow></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^{-6}$</span></mjx-container>까지 허용한다.</p>

