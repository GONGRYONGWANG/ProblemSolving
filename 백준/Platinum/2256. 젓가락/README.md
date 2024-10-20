# [Platinum III] 젓가락 - 2256 

[문제 링크](https://www.acmicpc.net/problem/2256) 

### 성능 요약

메모리: 41408 KB, 시간: 104 ms

### 분류

다이나믹 프로그래밍, 정렬

### 제출 일자

2024년 10월 15일 22:48:05

### 문제 설명

<p>사람들은 보통 식사를 할 때 젓가락을 두 개 사용한다. 그러나 모 선생님 댁에서는 조금 다르게 세 개의 젓가락을 사용한다. 우리가 일반적으로 사용하는 한 벌의 젓가락에 큰 젓가락을 한 개 더 포함시켜 큰 음식을 젓가락에 꽂아 먹는 방식을 택한다.</p>

<p>큰 젓가락의 경우에는 별도의 용도로 사용하기 때문에 문제가 없지만, 나머지 두 젓가락의 길이가 많이 차이 나는 경우에는 불편할 수도 있다. 한 사람이 가지게 되는 젓가락의 길이 A, B, C(A ≤ B ≤ C)라고 할 때, (A-B)×(A-B)가 그 벌점이 된다.</p>

<p>오늘은 모 선생님의 생일이라 K(1 ≤ K ≤ 1000)명의 사람들이 함께 식사를 하게 되었다. 이를 위해서 모 선생님은 K벌(3×K개)의 젓가락을 준비해야 한다. 이를 위해서 모 선생님은 이미 가지고 있는 N(3×K ≤ N ≤ 5000)개의 젓가락들 중에서 몇 개의 젓가락을 골라서 K명의 사람들에게 나눠주기로 하였다. 하지만 이렇게 많은 인원이 식사하게 된 경우가 처음이라 일부 젓가락의 길이가 맞지 않게 되었다. 모 선생님은 가급적 모든 사람들이 편하게 젓가락을 이용할 수 있도록, 각 사람에게 나눠준 젓가락의 벌점의 총 합이 최소가 되도록 하려 한다.</p>

<p>젓가락에 대한 정보가 주어졌을 때, 벌점의 총 합의 최솟값을 구해내는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 두 정수 K, N이 주어진다. 다음 줄에는 N개의 젓가락의 길이가 주어진다. 각 젓가락의 길이는 1이상 32767이하의 정수이다.</p>

### 출력 

 <p>첫째 줄에 벌점의 총 합의 최솟값을 출력한다.</p>

