# [Platinum IV] Rabbit Carrot - 27347 

[문제 링크](https://www.acmicpc.net/problem/27347) 

### 성능 요약

메모리: 8272 KB, 시간: 88 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열: O(n log n), 세그먼트 트리

### 제출 일자

2025년 4월 14일 00:49:18

### 문제 설명

<p>Rabbit called Carrot is willing to cross the bridge. The bridge consists of <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> poles of different height. Carrot can jump at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container> centimeters up and any distance down.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/bfe1fd0c-f169-4416-8e59-cda1e423cc8a/-/preview/" style="width: 288px; height: 152px;"></p>

<p>The rabbit starts crossing the bridge from the left and is standing at height zero immediately before the first pole. The goal of the Carrot is to reach the other side of the bridge by jumping on each pole in order.</p>

<p>However, it might happen, that the rabbit will not be able to jump on some poles as it will be too high.</p>

<p>Help the rabbit Carrot to cross the bridge by modifying the heights of some poles. Calculate the smallest possible amount of poles the height of which has to be either increased or decreased so that the Carrot could cross the bridge. Height of each of the poles can be increased by any amount and decreased to a non-negative value.</p>

### 입력 

 <p>The first line contains two integers: the number of bridge poles <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> and the Carrot leap-up size <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>. The following <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> lines contain the heights of the poles <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>a</mi><mi>i</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$a_i$</span></mjx-container> given as integers one number per line.</p>

### 출력 

 <p>Output one integer – the least number of poles that have to be either lifted or lowered so that the rabbit Carrot could cross the bridge.</p>

