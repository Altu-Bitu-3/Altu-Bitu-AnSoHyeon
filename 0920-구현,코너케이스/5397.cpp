/*
필수 문제

들어가 있는 원소를 다양한 위치에서 삽입, 삭제하는 문제이므로 list를 쓰면 성능이 좋을 것 같다. 
-> 메모리 초과난다. 
	원래는 < > - char 에 대해서 동작하는 각각의 함수를 만들고 이터레이터와 리스트를 매개변수로 
	전댈했는데 계속해서 매개변수로 전달하면 메모리를 (불필요하게)과도하게 사용한다고 해서 전역변수로 선언하였다. 

-> 출력 오류가 난다. 
	vector에서의 erase는 자동으로 뒤의 값들을 앞으로 당겨와주지만 
	list의 erase는 다음 노드를 연결해주지 않기 때문에 erase의 반환값을 이터레이터에 받아줘야 계속해서 
	의도한 계산을 이어갈 수 있음을 알았다. 
*/

#include <iostream>
#include <string>
#include <list>

using namespace	std;
list <char> key;
list<char>::iterator cur;

void	keyLogger(string input) {

	cur = key.begin();
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '<') {
			if (cur != key.begin()) {
				cur--;
			}
		}
		else if (input[i] == '>') {	
			if (cur != key.end()) {
				cur++;
			}
		}
		else if (input[i] == '-') {
			if (cur != key.begin()) {
				cur = key.erase(--cur);
			}
		}
		else
			key.insert(cur, input[i]);
	}

	for (cur = key.begin(); cur != key.end(); cur++) {
		cout << *cur;
	}
	key.clear();
}

int	main () {

	int test;
	cin >> test;

	string	input;
	while (test--) {
		cin >> input;
		keyLogger(input);
		cout << "\n";
	}

	return 0;
}