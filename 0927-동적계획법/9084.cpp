#include <iostream>
#include <vector>

using namespace	std;

vector <int> coins(coin);

void	memoization(vector<int> &res, int sum) {
	for (int i = 0; i < sum) {

	}
}

// sum에 index에 해당하는 값을 만들기 위한 방법을 저장하고 각 인덱스를 더해서 총 금액이 원하는 금액이 되는 경우를 구한다.
// 500이 되는 방법을 구할 때, res[50] + res[450] 을 통해서 구할 수 있다. -> 0부터 250까지만 더하면 된다. 
int	calcCoin(int sum) {

	int res = 0;
	vector <int> res(sum + 1, 0);
	res[0] = 1; // 예를 들어 0 + 500을 하는 경우를 위해 필요하다. 근데 0원이 되는 방법은 1가지 밖에 없음.

	///////예를 들어 5 10원이 들어올 수 있으면
	/*
		res[5] = 1, res[10] =  = 2, res[15] = 2 이런식으로 앞의 값을 더해서 만들고 싶은데 어떻게 해야할지 모르겠어요
ㅠㅜㅠ	*/
	for (int i = 0; i < sum; i++)
		memoization(res, sum);
	return res[sum];
}

int main () {
	
	int case;
	cin >> case;

	int coin;
	int sum;
	while (case--) {
		cin >> coin;
		coins.assign(coin, 0);
		for (int i = 0; i < coin; i++) {
			cin >> coins[i];
		}
		cin >> sum;
		cout << calcCoin(coins, sum) << "\n";
	}
	return 0;
}