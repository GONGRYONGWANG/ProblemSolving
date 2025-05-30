# [Platinum III] 윤호는 마법약 도둑 - 14672 

[문제 링크](https://www.acmicpc.net/problem/14672) 

### 성능 요약

메모리: 2556 KB, 시간: 12 ms

### 분류

이분 매칭, 그래프 이론, 수학

### 제출 일자

2025년 3월 8일 03:00:49

### 문제 설명

<p>효빈이의 마법 공장에는 2번부터 N번까지의 제품번호를 가진 마법약을 팔고 있다. 윤호는 효빈이의 마법 공장에서 M개의 마법약을 사와 마법상점을 열기로 했다. 윤호의 정보원 영선이는 윤호에게 효빈이의 중요한 비밀을 알려준다. 그 비밀이란, 어떤 제품 A가 제품번호가 P1 P2 … Pk 인 마법약을 섞어 만들었다면 그 제품의 제품 번호는 P1×P2× …×Pk 로 결정 되고 여기에는 예외가 없다는 것이다. 이때, P1 P2 … Pk 들은 A의 재료가 된다. 하지만 똑똑한 효빈이는 이를 눈치채고 윤호와의 거래를 끊어버렸다! 이제 윤호에게 남은 것은 M개의 마법약뿐이다. 하지만 윤호에게는 아버지께서 물려주신 마법의 기계가 있다.</p>

<p>이 마법의 기계로 마법약 A를 분해할 수 있는데, 이 분해 작업을 하면 재료가 될 수 있는 가능성을 가진 마법약 P1 P2 … Pk 중 하나를 추출할 수 있다. 다만, 이 분해하는 작업을 할 경우에는 마법약 A는 파괴되어 버린다. 예를 들어, 12번 마법약을 분해 할 경우, 2, 3, 4, 6, 12번 마법약들 중 하나를 추출할 수 있다. 윤호는 최대한 다양한 효능을 내는 마법약을 만들고 싶다. 따라서 윤호가 추출한 제품들 중에서 어떤 약도 원료를 공유해서는 안 된다. 즉, 윤호가 q개의 마법약을 분해했을 때, 제품번호가 Y1 Y2 … Yq 인 마법약이 추출 됐다고 하자. 이때, 어떤 K번 마법약이 Yi약의 재료가 될 수도 있고, Yj의 재료도 될 수 있다면 이 추출은 실패한 추출이다. 예를 들어, 윤호가 사들인 효빈이의 약이 12번, 18번 약이었다고 치자. 이때, 12번을 분해해 4번약을 추출하고, 18번을 분해해 6번 약을 추출했다고 한다면, 2번이 4번과 6번 약의 재료가 될 수 있으므로 실패한 추출이다. 반면, 4번과 9번을 추출했다고 한다면 어떤 번호의 약도 동시에 재료가 될 수 없으므로 성공한 추출이다. 윤호가 실패하지 않으면서 추출할 수 있는 불안정한 마법약의 최대 개수를 구하시오. </p>

### 입력 

 <p>프로그램의 입력은 표준 입력으로 받는다. 입력의 첫 줄에는 N과 M이 주어진다. (2 ≤ N ≤ 100,000,000) (1 ≤ M ≤ 1,000) 두 번째 줄에는 M개의 정수가 주어진다. 이 수들은 윤호가 효빈이에게 사온 마법약의 제품 번호이다. 각 수들은 N보다 작거나 같다.</p>

### 출력 

 <p>프로그램의 출력은 표준 출력으로 한다. 윤호가 실패하지 않으면서 추출 할 수 있는 마법약의 최대 개수를 구 하시오.</p>

