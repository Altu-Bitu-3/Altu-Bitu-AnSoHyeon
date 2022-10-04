/*
동적계획법-추가제출

[포도주 시식]
0. 각 포도주 잔은 모두 다른 양이 들어 있다. 
1. 포도주 잔을 선택하면 다 마시고 원래 위치에 내려놓는다.
2. 연속된 3잔을 모두 마실 수 없다.

최대로 많이 마실 수 있는 양은?
--------------------------------------------------------
많이 마실 수 있는 양을 출력하는 과제이므로 지금 와인잔의 위치에서 n-1번째 잔과 n-2번째 잔을 같이 마신게 best인지 아닌지 판별한다. 
n번째 잔까지 마신 와인의 총량을 n번쨰 배열에 저장하고 n번째 와인으로부터 (뒤로)가까이 있는 와인을 더한 값을 비교해서 가장 큰 값을 고른다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace	std;

int maxWine(int n, vector<int> wine) {

	vector<int> dp(n + 1, 0);
	// n개까지 마신 와인의 총량을 이 배열에 저장한다.
	dp[1] = wine[1];
	// 1번 와인을 마셨을 때 마실 수 있는 총량
	dp[2] = wine[1] + wine[2];
	// 2번 와인은 1번 와인에 이어서 마실 수 있으므로 1 + 2한 값

	// 2번까지는 픽스이므로 3번부터 비교
	for (int i = 3; i < n + 1; i++) {
		dp[i] = max({dp[i-3] + wine[i-1] + wine[i], dp[i-2] + wine[i], dp[i-1]});
		/*
		n 번째 와인까지 중에서 마실 수 있는 와인의 경우
		1. n-1, n번째 와인을 마신다.
		2. n번째 와인만 마신다.
		3. 다 안먹고 다음으로 넘어간다. 
		*/
	}
	return dp[n];
	// n번째 까지 계산을 마쳤으므로 n번쨰의 결과를 리턴
}

int	main () {
	int n;
	cin >> n;

	vector<int> wine(n + 1);
	// 입력값으로 주는 와인의 양을 저장할 배열
	// 인덱스를 1번째부터 주기 위해 n+1칸을 할당한다.
	for (int i = 0; i < n+1; i++) {
		cin >> wine[i];
		// 입력받고
	}
	cout << maxWine(n, wine);
	// 와인의 최댓값 구하기 
	return 0;
}