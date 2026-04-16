# [Silver I] 200% Mixed Juice! - 25312 

[문제 링크](https://www.acmicpc.net/problem/25312) 

### 성능 요약

메모리: 5220 KB, 시간: 36 ms

### 분류

수학, 그리디 알고리즘, 정렬, 정수론, 유클리드 호제법

### 제출 일자

2026년 04월 17일 02:59:42

### 문제 설명

<p>음료수가 담긴 병이 총 $N$개 있다. $i$번째 병에는 음료수가 총 $w_i$<span style="padding: 0 2px 0 2px;">ℓ</span>만큼 담겨있고, 음료수에는 설탕이 총 $v_i$<span style="font-family: "Nimbus Roman No9 L","Times New Roman",Times,serif; padding: 0 2px 0 2px;">mg</span>만큼 들어 있다. 이 음료수들 중 일부를 섞어서 총용량이 정확히 $M$<span style="padding: 0 2px 0 2px;">ℓ</span>인 혼합 음료수를 만들려고 한다. 이때, 병에 있는 음료수를 일부만 사용해도 된다.</p>

<p>혼합 음료수의 설탕량은 섞은 음료수들 각각에 들어 있는 설탕량의 합으로 결정된다. 설탕은 음료수에 균일하게 녹아 있기 때문에, 어떤 병에 든 음료수를 일부만 사용할 경우 설탕 역시 그 비율만큼 들어가게 된다. 즉, $i$번째 음료수를 $a_i$<span style="padding: 0 2px 0 2px;">ℓ</span>만큼$(0 \le a_i \le w_i)$ 섞는다면, $i$번째 음료수에 해당하는 설탕량은 $\left(\frac{a_i}{w_i} \times v_i\right)$<span style="font-family: "Nimbus Roman No9 L","Times New Roman",Times,serif; padding: 0 2px 0 2px;">mg</span>이다.</p>

<p>음료수를 섞어 총용량이 정확히 $M$<span style="padding: 0 2px 0 2px;">ℓ</span>인 혼합 음료수를 만들었을 때, 여기에 들어갈 수 있는 설탕량의 최댓값을 출력하여라.</p>

### 입력 

 <p>첫 줄에는 두 정수 $N$과 $M$이 공백으로 구분되어 주어진다. $(1 \le N \le 100\,000;$ $1 \le M \le w_1 + w_2 + \cdots + w_N)$</p>

<p>다음 $N$개의 줄의 $i$번째 줄에는 두 정수 $w_i$와 $v_i$가 공백으로 구분되어 주어진다. $(1 \le w_i, v_i \le 100\,000)$</p>

### 출력 

 <p>총용량이 정확히 $M$<span style="padding: 0 2px 0 2px;">ℓ</span>인 혼합 음료수에 들어갈 수 있는 설탕량의 최댓값을 기약분수로 표현했을 때 $\left(\frac{a}{b}\right)$<span style="font-family: "Nimbus Roman No9 L","Times New Roman",Times,serif; padding: 0 2px 0 2px;">mg</span>이라고 하자. 이때 $a$와 $b$를 <code>/</code>를 사이에 두고 차례로 출력한다.</p>

