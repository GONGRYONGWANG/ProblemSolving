# [Gold V] 욘세이대학교 - 34827 

[문제 링크](https://www.acmicpc.net/problem/34827) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 그리디 알고리즘, 문자열, 브루트포스 알고리즘, 백트래킹

### 제출 일자

2025년 12월 8일 01:42:50

### 문제 설명

<p><span style="color:#e74c3c;"><code>YONSEI</code></span> 라는 단어를 보고, 형진이는 무의식적으로 <strong>욘세이</strong>라고 읽어버렸다. 문득 궁금해졌다. 왜 연세대학교에서 <strong>연세</strong>가 <span style="color:#e74c3c;"><code>YONSEI</code></span> 일까?</p>

<p>잠깐 고민해본 형진이는, 순식간에 한 가지를 깨달을 수 있었다. 바로, <span style="color:#e74c3c;"><code>YONSEI</code></span> 라는 단어는 <strong>멋이 있다</strong>는 것이다! 반면, <span style="color:#e74c3c;"><code>YUNSE</code></span> 는 약간 멋이 없는 것 같기도 하다. (전적으로 형진이의 기준이다.)</p>

<p>형진이의 기준에, 영단어들은 <strong>멋이 있는</strong> 영단어가 있고, <strong>멋이 없는</strong> 영단어가 있다는 것을 알게 됐다.</p>

<p>형진이가 제안한 <strong>멋이 있는 단어</strong>는 다음과 같다:</p>

<ul>
<li>단어는 알파벳 대문자만으로 이루어져 있다.</li>
<li>각 단어에 포함된 모든 문자는 1회만 사용된다.</li>
<li>단어에서 인접한 두 문자에 대해서, 앞에 있는 문자가 사전순으로 나열했을 때 더 앞에 있는 횟수를 $X$, 뒤에 있는 문자가 사전순으로 나열했을 때 더 앞에 있는 횟수를 $Y$라고 하자. 이 때, $|X-Y| \leq 1$을 만족한다.</li>
</ul>

<p>대표적으로, <code><span style="color:#e74c3c;">YUNSE</span></code> 는 형진이의 기준에 멋이 없는 단어이다. <span style="color:#e74c3c;"><code>YUNSE</code></span> 문자열에서 $X = 1$ (<span style="color:#e74c3c;"><code>NS</code></span>), $Y = 3$ (<span style="color:#e74c3c;"><code>YU</code></span>, <span style="color:#e74c3c;"><code>UN</code></span>, <span style="color:#e74c3c;"><code>SE</code></span>)이다. $|X-Y| = 2$이므로, 해당 단어는 멋이 없는 단어이다.</p>

<p>반면, <span style="color:#e74c3c;"><code>YONSEI</code></span> 는 형진이의 기준에 멋이 있는 단어이다. <span style="color:#e74c3c;"><code>YONSEI</code></span> 문자열에서 $X = 2$ (<span style="color:#e74c3c;"><code>NS</code></span>, <span style="color:#e74c3c;"><code>EI</code></span>), $Y = 3$ (<span style="color:#e74c3c;"><code>YO</code></span>, <span style="color:#e74c3c;"><code>ON</code></span>, <span style="color:#e74c3c;"><code>SE</code></span>)이다. $|X-Y| = 1$이므로, 해당 단어는 멋이 있는 단어이다.</p>

<p>특정한 단어가 주어졌을 때, 해당 단어를 접두사로 하는 <strong>가장 짧은 멋이 있는 단어</strong>를 하나 구성해서 출력해보자. 만약 가장 짧은 멋있는 단어가 여러 개라면, 그중 아무거나 출력한다.</p>

### 입력 

 <p>첫째 줄에 단어의 길이 $N$이 입력으로 주어진다. ($1\le N \le 5$)</p>

<p>둘째 줄에 단어가 입력으로 주어진다. 단어는 모두 알파벳 대문자로 이루어져 있으며, 주어지는 단어에 있는 모든 문자는 서로 다르다.</p>

### 출력 

 <p>첫째 줄에 주어진 단어를 접두사로 하는 가장 짧은 멋있는 단어의 길이를 출력한다.</p>

<p>둘째 줄에 그 단어를 출력한다.</p>

