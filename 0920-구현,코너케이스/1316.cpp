/*
0920-구현코너케이스 / 선택
*/

#include <iostream>
#include <string>
#include <vector>

using namespace	std;

//이면 1, 아니면 0을 반환
bool	isGroupWord(string word) {

	vector <bool> alpha(26, false);
	string tmp;
	tmp.push_back(word[0]);
	alpha[word[0] - 'a'] = true;
	for (int i = 1; i < word.size(); i++) {
		if (word[i] == tmp.back())	//같은 문자가 연속되고 있으면 pass
			tmp.push_back(word[i]);
		else {
			if (!alpha[word[i] - 'a']) // 만일 지금 찾는 문자가 앞에 없으면 pass
				tmp.push_back(word[i]);
			else
				return false;
		}
		alpha[word[i] - 'a'] = true;
	}
	return true;
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