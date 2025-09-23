# [Platinum IV] 츠바메가에시 - 22876 

[문제 링크](https://www.acmicpc.net/problem/22876) 

### 성능 요약

메모리: 86520 KB, 시간: 2284 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 9월 23일 19:10:22

### 문제 설명

<p>"츠바메가에시"(つばめがえし)는 일본의 검사 "사사키 코지로"가 날아가는 제비를 베었다고 전해지는 검 초식의 이름이다. 기록상으로는 세 번 연속 칼질을 했다고 전해지나, 실제로 기술을 재연해 본 바에 따르면 두 번 연속 까지가 한계라고 한다. 하지만 세 번 연속 베는 것이 더 멋있어 보이므로 게임이나 애니메이션 등의 미디어에서 이 기술을 묘사할 때는 검격을 세 번 하는 모습을 주로 볼 수 있다.</p>

<p>미디어에 영향을 많이 받은 pichulia는 세 번 연속 베는 기술을 재연하고자 한다. 피나는 노력 끝에 pichulia는 마침내 <strong>X 축 또는 Y 축과 평행한 무한한 길이의 직선 형태의 검격</strong>을 구사할 수 있게 되었다.</p>

<p>연습은 끝났고 이제는 실전이다. 하지만 pichulia는 야생생물 보호 및 관리에 관한 법률 제19조 1항에 의거해 야생의 제비를 벨 수 없었고, 부득이하게 제비뽑기의 제비를 베기로 결심했다.</p>

<p>2차원 평면상에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 제비가 있고, 각 제비마다 베었을 때 얻을 수 있는 점수를 가지고 있다. <strong>정확히 세 번의 검격을 통해</strong> 얻을 수 있는 점수의 최댓값을 구해보자.</p>

<p>점수는 검격들에 베인 제비의 점수들의 합이다. 단, 한 제비를 여러 번 베어도 점수는 한 번만 더해진다.</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="https://upload.acmicpc.net/8604b60b-d965-4a9a-9a7f-2958fd07da18/-/preview/" style="width: 480px; height: 480px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/dd551807-2711-49a5-a54e-5c8192ac24d6/-/preview/" style="width: 480px; height: 480px;"></td>
		</tr>
		<tr>
			<td>그림 D.1: 2차원 평면상에 배치된 제비</td>
			<td>그림 D.2: 세 번의 검격으로 제비를 베는 모습</td>
		</tr>
	</tbody>
</table>

### 입력 

 <p>첫 번째 줄에는 제비의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>(<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>300</mn><mtext> </mtext><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$ 1 \leq N \leq 300\ 000 $</span></mjx-container>)이 주어진다.</p>

<p>두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>+</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N+1$</span></mjx-container>번째 줄까지 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>줄에 걸쳐서 세 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$y$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>v</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$v$</span></mjx-container>가 공백으로 구분되어 주어진다. 이는 2차원 평면상의 좌표 (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$y$</span></mjx-container>) 에 점수가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>v</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$v$</span></mjx-container> 인 제비가 있음을 의미한다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>x</mi><mo>,</mo><mi>y</mi><mo>≤</mo><mn>1</mn><mtext> </mtext><mn>000</mn><mtext> </mtext><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0 \leq x, y \leq 1\ 000\ 000$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c37"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>v</mi><mo>≤</mo><mn>7</mn><mtext> </mtext><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \leq v \leq 7\ 000$</span></mjx-container>)</p>

<p>모든 제비의 위치는 서로 다르다.</p>

### 출력 

 <p><strong>정확히 세 번의 검격을 통해</strong> 얻을 수 있는 점수의 최댓값을 출력한다.</p>

