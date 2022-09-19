#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace	std;

int	main () {

	string	n1, n2;
	cin >> n1 >> n2;

// 길이가 더 긴 숫자를 기준으로 하기 위해 항상 길이가 더 긴 숫자가 n1에 저장되도록 한다. 
	if (n1.length() < n2.length()) {
		swap(n1, n2);
	}

// 길이가 더 긴 숫자를 int 배열로 (자릿수 별로)저장한다. 
	vector <int> n_str(n1.length());
	for (int i = 0; i < n_str.size(); i++) {
		n_str[i] = n1[i] - '0';
	}

// 길이가 더 짧은 숫자를 자릿수 별로 이미 저장한  int 배열에 더한다.
	int index = n_str.size() - 1;
	for (int i = n2.length() - 1; i >= 0; i--) {
		n_str[index] = n_str[index] + (n2[i] - '0');
		index--;
	}

// 만약 더한 결과의 1의 자리숫자가 10이 넘으면 10의 자리 숫자에 1을 더하고 1의 자리에는 10을 빼서 한자리로 맞춘다.
	for (int i = n_str.size() - 1; i > 0; i--) {
		if (n_str[i] > 9) {
			n_str[i] = n_str[i] - 10;
			n_str[i - 1] = n_str[i - 1] + 1;
		}
	}

// 가장 높은 자리 숫자가 10이 넘으면 미리 1을 string변수에 저장하여 자릿수를 해결한다. 
	string	ans;
	if (n_str[0] > 9) {
		n_str[0] = n_str[0] - 10;
		ans = "1";	
	}

// int를 char 아스키코드값에 맞게 변환하여 하나씩 출력한다. 
	for (int i = 0; i < n_str.size(); i++) {
		ans.push_back(n_str[i] + '0');
	}

	cout << ans;

	return 0;
}