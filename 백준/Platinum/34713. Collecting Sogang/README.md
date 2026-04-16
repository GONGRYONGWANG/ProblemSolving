# [Platinum III] Collecting Sogang - 34713 

[문제 링크](https://www.acmicpc.net/problem/34713) 

### 성능 요약

메모리: 8728 KB, 시간: 72 ms

### 분류

그리디 알고리즘, 이분 탐색, 매개 변수 탐색

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<p>알파벳 소문자로 이루어진 문자열 $S$가 주어진다. 이 문자열에서 <span style="color:#c0392b;"><code>s</code></span>, <span style="color:#c0392b;"><code>o</code></span>, <span style="color:#c0392b;"><code>g</code></span>, <span style="color:#c0392b;"><code>a</code></span>, <span style="color:#c0392b;"><code>n</code></span>, <span style="color:#c0392b;"><code>g</code></span> 여섯 개의 문자를 문자열의 <strong>앞에서부터 순서대로</strong> 추출하여 <span style="color:#c0392b;"><code>sogang</code></span>이라는 단어를 만들 수 있다. 이때, 이 여섯 개의 문자가 문자열에서 <strong>연속할 필요는 없다.</strong></p>

<p><span style="color:#c0392b;"><code>sogang</code></span>단어를 완성할 때마다 상품 하나를 받는다. 사용된 문자는 문자열에서 제거되며, 제거된 자리의 뒷부분에 있는 문자들은 앞으로 당겨진다. 이 과정을 여러 번 반복할 때, 받을 수 있는 상품의 최대 개수를 구하시오.</p>

### 입력 

 <p>첫 번째 줄에 문자열의 길이에 해당하는 정수 $N$이 주어진다. ($1 \le N \le 100\,000$)</p>

<p>두 번째 줄에는 알파벳 소문자로 구성된 길이가 $N$인 문자열 $S$가 주어진다.</p>

### 출력 

 <p>위의 규칙에 따라 단어를 만들 때, 받을 수 있는 상품의 최대 개수를 출력하여라.</p>

