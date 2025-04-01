# [Gold IV] 젓가락으로 메추리알 집기 - 33707 

[문제 링크](https://www.acmicpc.net/problem/33707) 

### 성능 요약

메모리: 30264 KB, 시간: 268 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2025년 4월 1일 16:54:13

### 문제 설명

<p><strong>이 문제는 인터랙티브 문제이다.</strong></p>

<p>세로로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개, 가로로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>개의 정사각형 칸들로 이루어진 반찬통이 있다. 쿠가 메추리알을 거의 다 먹어 치워 버렸기에, 반찬통 안에는 메추리알이 단 <strong>한 칸</strong>에만 놓여 있다.</p>

<p>당신은 눈을 가린 채로, 반찬통 안의 어딘가에 남아 있는 메추리알 하나를 젓가락으로 집어먹어 보려 한다! </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e721f27d-21ea-407d-8f52-30baf0dd9a21/-/preview/" style="width: 400px;"></p>

<p style="text-align: center;"><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mtext class="mjx-n" space="2"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>=</mo><mn>2</mn><mo>,</mo><mtext> </mtext><mi>M</mi><mo>=</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N = 2,\ M = 3$</span></mjx-container>일 때, 반찬통 안에 메추리알이 놓여 있는 모습이다.</p>

<p>당신은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-s3"><mjx-c class="mjx-c230A TEX-S3"></mjx-c></mjx-mo><mjx-mstyle><mjx-mfrac><mjx-frac type="d"><mjx-num><mjx-nstrut type="d"></mjx-nstrut><mjx-mrow><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line type="d"></mjx-line><mjx-row><mjx-den><mjx-dstrut type="d"></mjx-dstrut><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-mstyle><mjx-mo class="mjx-s3"><mjx-c class="mjx-c230B TEX-S3"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">⌊</mo><mstyle displaystyle="true" scriptlevel="0"><mfrac><mrow><mi>N</mi><mi>M</mi></mrow><mn>2</mn></mfrac></mstyle><mo data-mjx-texclass="CLOSE">⌋</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\left\lfloor \dfrac{NM}{2} \right\rfloor$</span></mjx-container>번의 젓가락질 이내로 메추리알을 잡아야 한다. 젓가락질은 다음 과정으로 이루어진다.</p>

<ul>
	<li>반찬통 안의 칸 하나를 골라 그 칸을 향해 젓가락질한다.</li>
	<li>젓가락질한 칸에 메추리알이 있다면, 메추리알을 집는다.</li>
	<li>젓가락질한 칸에 메추리알이 없다면, 메추리알은 다음 규칙에 따라 이동한다.
	<ul>
		<li>젓가락질한 칸이 메추리알이 있는 칸과 인접하다면, 메추리알은 인접한 <strong>무작위</strong> 칸 중 하나로 이동한다. 단, <strong>방금 젓가락질한 칸</strong>이나 반찬통 밖으로는 이동하지 않는다.</li>
		<li>젓가락질한 칸이 메추리알이 있는 칸과 인접하지 않는다면, 메추리알은 이동하지 않는다.</li>
	</ul>
	</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/3711e25c-4416-457f-8c91-eb160e5e92ba/-/crop/836x405/47,47/-/preview/" style="width: 400px;"></p>

<p style="text-align: center;">파란색 칸에 젓가락질하면 메추리알은 두 빨간색 칸 중 하나로 이동한다.</p>

<p>어떤 두 칸이 한 변을 공유하면 두 칸은 인접한다고 한다. 꼭짓점만을 공유하는 두 칸은 서로 인접하지 않는다.</p>

<p>정해진 젓가락질 횟수 안에 메추리알을 잡아보자!</p>

### 입력 

 <p>첫째 줄에 반찬통의 크기를 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>이 공백으로 구분되어 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mtext class="mjx-n" space="2"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">(</mo><mn>2</mn><mo>≤</mo><mi>N</mi><mo>,</mo><mtext> </mtext><mi>M</mi><mo>≤</mo><mn>100</mn><mo data-mjx-texclass="CLOSE">)</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\left(2 \le N, \ M \le 100\right)$</span> </mjx-container></p>

### 출력 

 <p>당신은 표준 입출력으로 채점 시스템과 상호작용해야 한다. 다음과 같이 문자열을 한 줄에 출력하여 젓가락질할 수 있다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>? r c</code></span>: 반찬통의 위에서 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>r</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$r$</span></mjx-container>번째, 왼쪽에서 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>c</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$c$</span></mjx-container>번째에 위치한 칸에 젓가락질한다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3B"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>r</mi><mo>≤</mo><mi>N</mi><mo>;</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 \le r \le N;$</span></mjx-container> <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>c</mi><mo>≤</mo><mi>M</mi><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le c \le M)$</span> </mjx-container></li>
</ul>

<p>당신은 최대 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-s3"><mjx-c class="mjx-c230A TEX-S3"></mjx-c></mjx-mo><mjx-mstyle><mjx-mfrac><mjx-frac type="d"><mjx-num><mjx-nstrut type="d"></mjx-nstrut><mjx-mrow><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line type="d"></mjx-line><mjx-row><mjx-den><mjx-dstrut type="d"></mjx-dstrut><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-mstyle><mjx-mo class="mjx-s3"><mjx-c class="mjx-c230B TEX-S3"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">⌊</mo><mstyle displaystyle="true" scriptlevel="0"><mfrac><mrow><mi>N</mi><mi>M</mi></mrow><mn>2</mn></mfrac></mstyle><mo data-mjx-texclass="CLOSE">⌋</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\left\lfloor \dfrac{NM}{2} \right\rfloor$</span></mjx-container>번 젓가락질할 수 있으며, 반찬통을 벗어나거나 횟수를 초과하는 경우 <span data-darkreader-inline-color="" style="color: rgb(221, 65, 36); --darkreader-inline-color: var(--darkreader-text-dd4124, #e0543a);">틀렸습니다</span>를 받는다.</p>

<p>문자열을 출력한 이후, 당신은 젓가락질의 결과를 나타내는 정수 하나를 입력받아야 한다.</p>

<ul>
	<li>메추리알을 집었다면 <span style="color:#e74c3c;"><code>1</code></span>을 입력받는다.</li>
	<li>메추리알을 집지 못했다면 <span style="color:#e74c3c;"><code>0</code></span>을 입력받고, 메추리알은 문제의 규칙에 따라 이동한다.</li>
</ul>

<p><strong>젓가락질의 결과로 <span style="color:#e74c3c;"><code>1</code></span>을 입력받았다면 프로그램을 즉시 종료해야 한다</strong>. 그렇지 않으면 예상하지 못한 채점 결과를 받을 수 있다.</p>

<p><strong>각 행동을 출력한 이후, 프로그램은 매번 표준 출력을 flush해야 한다.</strong> 그렇지 않으면 <span style="color:#fa7268;"><span data-darkreader-inline-color="" style="--darkreader-inline-color: var(--darkreader-text-f39c12, #fa7268);">시간 초과</span></span>를 받을 수 있다. 대표적인 언어에서 표준 출력을 flush하는 방법은 다음과 같다.</p>

<ul>
	<li>C++: <code>std::cout << std::flush;</code></li>
	<li>Python: <code>sys.stdout.flush()</code></li>
	<li>Java: <code>System.out.flush();</code></li>
</ul>

<p>이 문제의 인터랙터는 <strong>적응적</strong>이다. 메추리알의 시작 위치와 이동할 방향은 미리 정해져 있지 않다.</p>

