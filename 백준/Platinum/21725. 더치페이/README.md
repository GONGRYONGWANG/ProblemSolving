# [Platinum III] 더치페이 - 21725 

[문제 링크](https://www.acmicpc.net/problem/21725) 

### 성능 요약

메모리: 18784 KB, 시간: 96 ms

### 분류

그래프 이론, 자료 구조, 그래프 탐색, 누적 합, 분리 집합, 작은 집합에서 큰 집합으로 합치는 테크닉

### 제출 일자

2025년 6월 21일 01:12:59

### 문제 설명

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>명의 친구들이 인덱스국에 여행을 떠난다. 인덱스국은 굉장히 넓고, 친구들은 각자 가보고 싶은 위치가 다르다. 따라 맨 처음에는 모두 1인 그룹으로 각자 여행을 하다가, 일정이 지나면서 그룹끼리 합류하여 마지막에는 하나의 그룹으로 뭉쳐서 다같이 여행을 마무리하기로 했다.</p>

<p>여행을 하는 데 지출은 필수적이다. 이 친구들은 각자 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-msup space="3"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c38"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>×</mo><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mn>18</mn></mrow></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \times 10^{18}$</span></mjx-container>원씩을 가지고 있어서, 여행 동안에 돈을 그다지 계획적으로 쓰지는 않았다. 그래서 여행이 모두 끝난 후, 각자가 원래 부담했어야 할 몫을 정산하는 것이 무척 성가시게 되었다.</p>

<p>여행할 때 지출은 그룹 단위로 이루어지며, 여행할 때는 그룹원 중 한 명이 모두 계산한다. 여행이 모두 끝나고 정산할 때는 지출 당시의 모든 그룹원이 모두 공평하게 같은 금액만큼 부담한다. 금액은 원화로 계산하며, 각 지출은 당시 그룹원의 수로 나누어 떨어진다.</p>

<p>정산은 한 명이 다른 한 명에게 돈을 전송하는 송금을 통해 이루어진다. 매 지출마다 각자의 부담금을 계산하여 여행할 때 돈을 냈던 사람에게 송금을 하는 것은 매우 귀찮기 때문에, 친구들은 지출들을 모두 한꺼번에 정산해 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>번 이하의 송금으로 모든 정산을 할 수 있는지 궁금해졌다.</p>

<p>그룹이 합류한 기록과 모든 지출의 기록이 시간 순서대로 주어진다. 여행이 모두 끝난 후, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>번 이하의 송금으로 모든 지출을 정산할 수 없다면 <code>-1</code>, 정산할 수 있다면 송금 횟수와 송금에 대한 정보를 출력하도록 하자.</p>

### 입력 

 <p>입력의 첫 줄에 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi><mo>,</mo><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n, m$</span></mjx-container>이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>은 여행을 한 친구들의 수, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container>은 그룹의 합류 및 지출 기록의 총 개수이다. 각 친구들은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>번부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>번까지의 번호로 표현한다.</p>

<p>이후 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container>개의 줄에 걸쳐 각 기록을 나타내는 수들이 한 줄에 하나씩 주어진다.</p>

<p>두 그룹이 합류한 기록은 <em>1 x y</em>와 같이 주어진다. 이는 <em>x</em>가 속한 그룹과 <em>y</em>가 속한 그룹이 합류했다는 것을 의미한다. <em>x</em>와 <em>y</em>가 이미 같은 그룹에 속해 있는 경우는 없다.</p>

<p>지출이 발생한 기록은 <em>2 x c</em>와 같이 주어진다. 이는 <em>x</em>가 현재 그룹원들을 위해 총 <em>c</em>원을 지출했다는 의미이다. <em>c</em>는 <em>x</em>가 속한 그룹의 그룹원의 수로 나누어 떨어진다.</p>

<p>기록들이 모두 처리된 시점에 모든 학생이 한 그룹에 속해 있음이 보장된다.</p>

### 출력 

 <p>첫째 줄에 조건을 만족하는 송금 방법이 존재하지 않으면 <code>-1</code>, 존재하면 송금의 총 횟수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>k</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$k$</span></mjx-container>를 출력하라. (단, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>k</mi><mo>≤</mo><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0 \le k \le n$</span></mjx-container>)</p>

<p>그 다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>k</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$k$</span></mjx-container>개 줄 각각에는 송금에 대한 정보를 조건에 맞게 출력하라. 여러 방법이 존재하면 그 중 아무거나 출력해도 좋고, 송금 또한 아무 순서로나 출력해도 괜찮다.</p>

<p>송금에 대한 정보는 <em>x y c</em>와 같이 나타내도록 하자. 이는 <em>x</em>가 <em>y</em>에게 <em>c</em>원을 보낸다는 의미이다. <em>x</em>와 <em>y</em>의 순서에 유의하라.</p>

