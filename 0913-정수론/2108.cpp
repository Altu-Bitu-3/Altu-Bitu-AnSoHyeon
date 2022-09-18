/*
정수론 필수과제
통계학

첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
둘째 줄에는 중앙값을 출력한다.
셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
넷째 줄에는 범위를 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace	std;

void	arithMean(vector<int> number, int n) {

	double	sum = 0;

	for (int i = 0; i < n; i++) {
		sum += number[i];
	}
	int mean = round(sum / n);
	cout << mean << "\n";
}

void	medianNum(vector<int> number, int n) {

	n = n / 2;
	cout << number[n] << "\n";
}

void	modeNum(vector<int> number, int n) {

	int	mode = 0;
	int	frequ = 0;
	int second = 0;

	for (int i = 0; i < n; i++) {
		int tmp_num = number[i];
		int tmp_fre = 1;
		while(number[i] == tmp_num) {
			tmp_fre++;
			i++;
		}
		i--;
		if (tmp_fre > frequ) {
			frequ = tmp_fre;
			mode = tmp_num;
			second = 1;
		}
		else if (tmp_fre == frequ) {
			if (second < 2) {
				mode = tmp_num;
				second++;
			}
		}
	}
	cout << mode << "\n";
}

void	numRange(vector<int> number, int n) {
	cout << number[n - 1] - number[0] << "\n";
}

int main () {
	int n;
	cin >> n;

	vector<int> number(n);
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	sort(number.begin(), number.end());


	arithMean(number, n);
	medianNum(number, n);
	modeNum(number, n);
	numRange(number, n);

	return 0;
}

