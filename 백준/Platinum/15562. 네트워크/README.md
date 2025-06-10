# [Platinum V] 네트워크 - 15562 

[문제 링크](https://www.acmicpc.net/problem/15562) 

### 성능 요약

메모리: 9836 KB, 시간: 228 ms

### 분류

그래프 이론

### 제출 일자

2025년 6월 10일 21:53:51

### 문제 설명

<p>우리의 회사에는 <em>N</em>개의 네트워크 시스템 <em>S</em><sub>1</sub>, <em>S</em><sub>2</sub>, ..., <em>S</em><sub><em>N</em></sub>와 이들을 연결하는 <em>M</em>개의 네트워크들 <em>W</em><sub>1</sub>, <em>W</em><sub>2</sub>, ..., <em>W</em><sub><em>M</em></sub>이 있다. 네트워크 시스템들은 우선순위가 있어 모든 네트워크는 우선순위가 높은 곳에서 낮은 곳으로만 전달된다. 즉, <em>S</em><sub><em>A</em></sub>에서 <em>S</em><sub><em>B</em></sub>로 전달되는 네트워크가 있다면 <em>A</em> < <em>B</em> 이다.</p>

<p>최근 이 네트워크 시스템이 너무 난잡해져 이를 정리하기로 했다. 이를 설명하자면, 시스템 <em>S</em><sub><em>A</em></sub>, <em>S</em><sub><em>B</em></sub>, <em>S</em><sub><em>C</em></sub>에 대해서 <em>S</em><sub><em>A</em></sub>에서 <em>S</em><sub><em>B</em></sub>로 전달되는 네트워크와 <em>S</em><sub><em>B</em></sub>에서 <em>S</em><sub><em>C</em></sub>로 전달되는 네트워크가 있다면 이 둘을 합쳐 <em>S</em><sub><em>A</em></sub>에서 <em>S</em><sub><em>C</em></sub>로 전달되는 네트워크로 간략화하는 것이다. 이 방식으로 간략화를 반복해서 최대한 네트워크의 수를 줄이고자 한다. 이때, 남은 네트워크의 수를 구하여라.</p>

### 입력 

 <p>첫 번째 줄에 <em>N</em>와 <em>M</em>이 주어진다. (1 ≤ <em>N</em>, <em>M</em> ≤ 10<sup>6</sup>)</p>

<p><em>M</em>줄 동안 두 숫자 <em>A</em><sub><em>i</em></sub>, <em>B</em><sub><em>i</em></sub>가 주어진다. 이는 <em>W</em><sub><em>i</em></sub>가 <em>S</em><sub><em>A</em><sub><em>i</em></sub></sub>와 <em>S</em><sub><em>B</em><sub><em>i</em></sub></sub>를 연결함을 뜻한다. (<em>i</em> = 1, 2, ..., <em>M</em>, 1 ≤ <em>A</em><sub><em>i</em></sub> < <em>B</em><sub><em>i</em></sub> ≤ <em>N</em>)</p>

### 출력 

 <p>최대한 간략화했을때 남은 네트워크의 수를 출력한다.</p>

