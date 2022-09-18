/*
정수론 필수과제
palindrome string

1. 대문자 알파벳만 들어오므로 알파벳 개수만큼의 배열을 두고 인덱스에 맞춰서 알파벳의 개수를 count
2. 앞에서부터 count가 홀수인지, 짝수인지 확인하고, 
3. count/2만큼 string변수에 push_back하되 count가 홀수인 알파벳 후로 또 count가 홀수인 알파벳이 있으면 palindrome string으로 만들 수 없다고 판정.
4. count가 홀수인 알파벳이 있으면 한번 더 string 변수에 push_back하고 
5. 3번까지한 string을 reverse해서 원래의 string에 더한다. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace	std;

void	putCharPalin(int count, string &palin, char c) {

	for (int i = 0; i < count; i++) {
		palin.push_back(c);
	}
}

void	countAlphabet(vector<int> &count, string name) {

	for (auto it = name.begin(); it != name.end(); it++) {
		count[*it - 'A']++;
	}
}

string	palinStr(string name) {

	vector<int> count(26, 0);
	countAlphabet(count, name);

	int center_alphabet = -1;
	string palin;
	for (int i = 0; i < 26; i++) {		// 이 for문은 palindrome의 정중앙 전까지만 만들 수 있다. 
		if (count[i]) {
			if ((count[i]%2) == 1) {	// count가 홀수면
				if (center_alphabet != -1) {	//count가 홀수인 알파벳이 이미 나왔으면 palin string 불가능
					return ("I'm Sorry Hansoo");
				}
				center_alphabet = i;			// 중앙에 올 알파벳 인덱스 저장
			}
			putCharPalin(count[i]/2, palin, i + 'A');	// count의 절반만큼 palin에 알파벳 삽입
		}
	}

	string rev_palin(palin);
	reverse(rev_palin.begin(), rev_palin.end());	// 절반만큼 쓴 string을 뒤집어서
	/* 
	copy(palin.rbegin(), palin.rend(), rev_palin.begin());
	질문 : 원래 reverse가 아니라 copy를 이용해서 뒤집어진 string을 구하려고 했는데 copy()함수를 이렇게 쓰는게 아닌가요?
	*/
	if (center_alphabet != -1) { 				// 홀수개 count된 알파벳이 있으면 
		palin.push_back(center_alphabet + 'A');	// 해당 알파벳을 한번 더 쓰고
	}
	palin = palin + rev_palin;	// 완전한 palindrome string 만들기 
	return (palin);
}

int	main () {

	string	name;
	cin >> name;
	
	cout << palinStr(name);
	return 0;
}