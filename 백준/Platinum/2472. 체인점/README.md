# [Platinum I] 체인점 - 2472 

[문제 링크](https://www.acmicpc.net/problem/2472) 

### 성능 요약

메모리: 12824 KB, 시간: 112 ms

### 분류

그래프 이론, 자료 구조, 세그먼트 트리, 최단 경로, 데이크스트라, 값 / 좌표 압축

### 제출 일자

2025년 7월 1일 19:59:15

### 문제 설명

<p>홍길동은 요즘 한창 인기가 많은 KOI 치킨 체인점을 차리려고 계획하고 있다. 홍길동이 사는 지역의 도로 지도는 아래 그림과 같다. 그림에서 원으로 표시된 부분은 체인점의 매장 설치 후보지이고, 선은 도로를 나타내며 선 옆에 표시된 값은 도로의 길이이다. 이 지역에는 대규모 아파트 단지가 세 군데 있다. 아파트의 위치는 그림에서 A, B, C로 표시된 원이다. 이 지역의 모든 교차로는 연결된 도로의 개수가 5개 이하이고, 도로를 통해 어떤 장소라도 찾아갈 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/64e663f6-f89d-4689-9b53-4e69b5b44354/-/preview/" style="width: 225px; height: 178px;"></p>

<p>위 그림에서 매장 후보지 1에 매장을 설치한다고 하자. 후보지 1에서 아파트 단지 A, B, C까지의 최단 경로 길이는 각각 8, 16, 9이다. 이 값들은 매장 후보지 4에서 아파트 단지 A, B, C까지 최단 경로의 길이인 6, 7, 3보다 각각 더 크다. 사람들은 더 가까운 매장을 이용하는 경향이 있기 때문에, 아파트 단지까지의 거리를 비교할 때 후보지 1은 모든 면(각 아파트까지의 거리)에서 후보지 4보다 불리한 위치이다. 후보지 6의 경우는 아파트 단지 A, B, C까지의 거리가 각각 5, 3, 5이므로, 후보지 1과 비교하면 모든 면에서 유리하지만, 후보지 4와 비교하면 아파트 단지 A, B에는 유리하고 C에는 불리하다. </p>

<p>이런 이유 때문에 홍길동은 매장 위치를 결정하는데 있어 다음의 기준을 정해 놓았다. </p>

<blockquote>
<p><strong>매장 후보지 p에서 아파트 단지 A, B, C까지의 최단 경로 길이를 각각 a, b, c라고 하고 다른 매장 후보지 q가 존재해서 q에서 아파트 단지 A, B, C까지의 최단 경로 길이를 각각 x, y, z라고 할 때, a > x 이고 b > y 이고 c > z이면 p에는 매장을 설치하지 않는다.</strong></p>
</blockquote>

<p>홍길동은 자신이 원하는 어떤 장소에 매장을 차릴 수 있는지를 알려고 한다. 질의로서 매장 후보지가 하나 주어질 때 그 곳에 매장을 차릴 수 있는지 여부를 판별하는 프로그램을 작성하시오. 질의는 여러 개가 들어올 수 있다. 아파트 단지가 위치한 장소에도 매장을 설치할 수 있다는 점과 각 교차로는 기껏해야 오거리임에 유의하라. </p>

### 입력 

 <p>첫째 줄에는 매장 후보지의 개수를 나타내는 정수 N이 입력된다(1 ≤ N ≤ 100,000). 매장 후보지들은 1부터 N까지의 번호로 구분된다. 둘째 줄에는 아파트 단지의 위치를 나타내는 세 개의 정수 A, B, C가 빈칸을 사이에 두고 주어진다. A, B, C는 모두 다른 값이며 매장 후보지 중의 하나로 주어진다. 세 번째 줄에는 도로의 개수를 나타내는 정수 M이 주어진다. 그 다음 M개의 줄에는 각 줄마다 세 개의 정수 X, Y, Z가 주어진다. 여기서 X, Y는 도로의 양 끝 매장 후보지 번호를 나타내고, Z는 도로의 길이이다(1 ≤ Z ≤ 10,000). 입력에서 같은 도로가 중복해서 들어오는 경우는 없다. 그 다음 줄에는 질의의 개수를 나타내는 정수 T가 주어진다(1 ≤ T ≤ 10,000). 그 다음 T개의 줄에는 각 줄마다 질의를 나타내는 한 개의 정수 Q가 주어진다(1 ≤ Q ≤ N).</p>

### 출력 

 <p>각 질의 Q에 대해 매장 후보지 Q에 매장을 설치할 수 있으면 대문자로 YES, 아니면 NO를 출력한다. </p>

