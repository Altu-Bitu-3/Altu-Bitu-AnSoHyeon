/*
동적계획법-기존제출 
해결을 못해서 모범답안을 보고 주석을 달아서 공부했습니다!

[동전]
주어진 동전으로 원하는 금액을 만들 수 있는 방법의 수를 구하기 
*/

#include <iostream>
#include <vector>

using namespace	std;

int	knapsack(int n, vector<int> arr, int m) {
	vector<int> dp(m+1, 0);
	// 인덱스 만큼의 금액을 만들 수 있는 경우의 수를 해당 인덱스 칸에 저장한다.
	
	dp[0] = 1; // 0원을 만들 수 있는 경우의 수는 1

	// arr에는 coin의 종류가 들어온다.
	for (int i = 0; i < n; i++) {	//coin의 종류 수만큼 for을 돈다.
		for (int j = arr[i]; j <= m; j++) {	// coin의 금액부터 만들고자하는 금액까지 for문을 돈다.
			dp[j] = dp[j] + dp[j - arr[i]];
			// 금액으로 arr[i]만큼을 만들 수 있는 경우의 수는 dp[arr[i]]에 담겨 있으므로 
			// 현재 동전(arr[i])을 사용하지 않고 금액을 만들 수 있는 경우의 수와 사용해서 만들 수 있는 경우의 수를 더해서 dp에 저장한다.
		}
	}
	return dp[m];
}

int	main () {
	int t, n, m;
	cin >> t;
	// test case만큼 돈다.
	while (t--) {
		cin >> n;

		vector<int> coin(n);
		// 동전의 종류를 저장할 배열
		for (int i = 0; i < n; i++) {
			cin >> coin[i];	// 동전 초기화
		}

		cin >> m;
		cout << knapsack(n, coin, m) << "\n"; // 경우의 수를 찾을 함수를 통해 결과 출력 
	}
	return 0;
}