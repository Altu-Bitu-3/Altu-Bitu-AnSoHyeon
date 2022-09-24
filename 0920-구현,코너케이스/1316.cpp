/*
0920-구현코너케이스 / 선택
*/

#include <iostream>
#include <string>

using namespace	std;

//이면 1, 아니면 0을 반환
int	isGroupWord(string word) {

	string tmp;
	tmp.push_back(word.front());
	for (int i = 1; i < word.size(); i++) {
		if (word[i] == tmp.back())	//같은 문자가 연속되고 있으면 pass
			tmp.push_back(word[i]);
		else {
			if (tmp.find(word[i]) == tmp.npos) // 만일 지금 찾는 문자가 앞에 없으면 pass
				tmp.push_back(word[i]);
			else
				return 0;
		}
	}
	return 1;
}

int	main () {

	int num;
	cin >> num;

	int count = 0;
	while (num--) {
		string word;
		cin >> word;
		count += isGroupWord(word);
	}

	cout << count << "\n";
	return 0;
}