# [Bronze I] 당신은 운명을 믿나요? - 27930 

[문제 링크](https://www.acmicpc.net/problem/27930) 

### 성능 요약

메모리: 2912 KB, 시간: 4 ms

### 분류

그리디 알고리즘, 문자열

### 제출 일자

2023년 4월 8일 13:40:35

### 문제 설명

<p>수능 시험을 앞둔 민지는 수능 전날 점집에서 점괘를 받았다. 이 점괘를 통해 민지는 어떤 학교에 합격할지를 해석할 수 있다. 점괘 $S$는 알파벳 대문자로 이루어진 문자열이다.</p>

<p>점괘를 해석하는 방법은 다음과 같다. 점괘의 첫 글자부터 차례대로 점괘를 읽는다. $i$번 글자까지 읽었을 때, 현재까지 읽은 점괘에서 순서를 유지한 채로 $0$개 이상의 글자를 제거하고 <span style="color:#e74c3c;"><code>YONSEI</code></span>나 <span style="color:#e74c3c;"><code>KOREA</code></span>를 얻을 수 있다면, 민지는 각각 <span style="color:#e74c3c;"><code>YONSEI</code></span>와 <span style="color:#e74c3c;"><code>KOREA</code></span>에 합격하는 것이다.</p>

<p>민지는 <span style="color:#e74c3c;"><code>YONSEI</code></span> 또는 <span style="color:#e74c3c;"><code>KOREA</code></span>를 반드시 찾을 수 있음이 보장된다. 또한 <span style="color:#e74c3c;"><code>YONSEI</code></span>와 <span style="color:#e74c3c;"><code>KOREA</code></span>를 모두 찾을 수 있는 경우, 먼저 찾은 학교에 합격하게 된다.</p>

<p>민지가 어떤 학교에 합격하게 될지를 알아보자. 두 학교를 동시에 합격할 수 없음이 보장된다.</p>

### 입력 

 <p>점괘 $S$가 주어진다.</p>

### 출력 

 <p>민지가 합격할 학교를 출력한다.</p>

