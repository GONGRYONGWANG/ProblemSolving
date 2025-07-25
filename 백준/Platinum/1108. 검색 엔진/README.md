# [Platinum III] 검색 엔진 - 1108 

[문제 링크](https://www.acmicpc.net/problem/1108) 

### 성능 요약

메모리: 2364 KB, 시간: 0 ms

### 분류

그래프 이론, 자료 구조, 집합과 맵, 해시를 사용한 집합과 맵, 방향 비순환 그래프, 위상 정렬, 강한 연결 요소

### 제출 일자

2025년 7월 17일 16:36:14

### 문제 설명

<p>새로운 검색 엔진을 만들었다. 이 검색 엔진은 구글을 뛰어넘는 세계 최고의 검색 엔진이기 때문에, 신뢰도가 높은 결과를 보여줘야 한다. 하지만, 사용자가 검색어를 입력했을 때, 이것에 맞는 결과가 수천, 수만개가 될 수 있으므로, 이 중에 어떤 것이 중요하고, 어떤 사이트를 보여줘야 하는지가 큰 문제이다.</p>

<p>구글은 이러한 것을 사이트를 크롤링해서 자체 알고리즘을 이용해서 사이트의 순위를 매긴다.</p>

<p>우리의 검색 엔진은 다음과 같은 방법을 사용할 것이다.</p>

<p>일단 모든 웹사이트에 1점을 준다. 만약에 웹사이트 A에 웹사이트 B로 가는 링크가 있다면, 웹사이트 B의 점수에 웹사이트 A의 점수를 더한다.</p>

<p>예를 들어, 웹사이트가 총 3개가 있다. A, B, C이다. 일단 모든 웹사이트의 점수는 1이다. 이제, 웹사이트 A와 B에 모두 C로 가는 링크가 있다고 하면, C의 점수는 3이 되고, A와 B의 점수는 그대로 1이다. 만약 어떤 검색어가 입력 되었는데, 이 웹사이트 A B C에 모두 해당하는 것이었다면, C가 가장 위에 표시된다.</p>

<p>이런 웹사이트에 점수를 매기는 일이 어려운 이유는 바로, 링크를 교환하는 사이트 들이 있기 때문이다. 이 말은 A가 B를 링크하고, B가 A를 링크하는 것이다. 따라서, 이런 현상으로 점수가 무한대로 늘어나는 것을 방지하기 위해서, A의 점수를 B에 더할 때는, B에서 A로의 링크가 직접적으로 또는 간접적으로 없을 때이다.</p>

<p>링크가 어떻게 되어있는 지가 주어지고, 웹사이트의 이름이 주어질 때, 그 웹사이트의 점수를 출력하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 링크 정보의 개수 N이 주어진다. 이 N은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 링크의 정보가 주어진다. 링크의 정보에 처음 등장하는 문자열은 웹사이트의 이름이고, 그 다음에 등장하는 수는 그 웹사이트를 가리키고 있는 웹사이트 이름의 수이다. 예를 들어, "C 2 A B"는 A에서 C로 가는 링크, B에서 C로 가는 링크가 있다는 의미이다. 마지막 줄에는 점수를 조사해야 할 웹사이트의 이름이 주어진다.</p>

<p>모든 웹사이트의 이름은 길이가 50보다 작거나 같은 알파벳 대문자로 이루어진 문자열이다. 한 웹사이트를 가리키고 있는 웹사이트 이름의 수는 24보다 작거나 같은 음이 아닌 정수이다. 한 웹사이트를 가르키고 있는 웹사이트에 대한 정보는 여러 번 등장하지 않는다. 점수를 조사해야 할 웹사이트의 이름은 반드시 링크의 정보에 등장한다.</p>

### 출력 

 <p>첫째 줄에 문제의 정답을 출력한다.</p>

