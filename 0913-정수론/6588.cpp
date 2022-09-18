/*
정수론-선택
골드바흐의 추측
*/

#include <iostream>
#include <vector>

using namespace	std;

void	isPrime(vector<bool> &is_prime, int input) {

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= input; i++) {
		if (is_prime[i]) {
			for (int j = 2; i * j <= input; j++) {
				is_prime[i * j] = false;
			}
		}
	}
}

void	conjecture(int input, vector<bool> is_prime) {

	for (int i = 3; i < input / 2 + 1; i++) {
		if (is_prime[i] && is_prime[input - i]) {
			cout << input << " = " << i << " + " << input - i << "\n";
			return ;
		}
	}
	cout << "Goldbach's conjecture is wrong." << "\n";
}

int main () {

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int	input;
	vector<bool> is_prime(1000001, true);
	isPrime(is_prime, 1000001);
	while (true) {
		cin >> input;
		if (input == 0) {
			break;
		}
		conjecture(input, is_prime);
	}
	return 0;
}

/*
fail 사항

1. 처음에는 input 값에 대해서 이전 input보다 더 큰 값이 들어오면 소수판단배열을 초기화하는 방식으로 했는데 계속 시간초과가 났다. 
test횟수가 워낙 많기 때문에 최악의 상황으로 생각해보면 처음에 max값까지 모두 소수 판정을 해놓고 다시는 초기화하지 않고 계속 사용하는 것이 더 시간을 절약할 수  있었다. 

2. 	line 25: for (int i = 3; i < input / 2 + 1; i++) { 
	에서 i를 input/2까지만 돌도록 했었는데 홀수의 경우를 고려해서 + 1까지 확인하도록 했어야 했다.
*/