/*
필수 문제

변한 횟수만큼 시계반대방향으로 돌린 자리가 현재 화살표가 가리키는 알파벳의 돌리기 직전 위치이다. 
따라서 rotate에 용이한 deque를 사용해서 현 위치로부터 시계 반대방향으로 돌려가며 원판을 채운다. 

처음에 deque을 ?으로 채워서 나중에 못채웠을 때 자연스럽게 ?로 출력이 되도록 한다. 
시계반대방향으로 돌아가면서 이미 ?이 아닌 다른 문자가 채워져 있을 때 또 다른 문자의 위치라고 나오면 바로 ! 출력후 종료 
deque를 순회할 때 인덱스의 오름차순이 시계방향이도록 한다. (시계반대방향으로 해도 push, pop을 계속해야해서 이득이 없다.)
*/

#include <iostream>
#include <deque>
#include <stdio.h>

using namespace	std;

int	findLocation(deque <char> &lucky, int s, char ch) {

	char	tmp;
	while (s--) {
		tmp = lucky.back();
		lucky.push_front(tmp);
		lucky.pop_back();
	}
	if (lucky[0] == '?') { // 아직 아무 알파벳도 들어와있지 않으면 ch를 넣는다. 
		lucky[0] = ch;
		for (auto it = lucky.begin() + 1; it != lucky.end(); it++) { // 넣고 난 후 중복이 있는지 확인하고 중복이 있으면 유효하지 않으므로 0을 리턴한다.
			if (lucky[0] == *it)
				return 0;
		}
		return 1;
	}
	else {
		if (lucky[0] != ch) { // 만일 회전한 자리에 이미 다른 알파벳이 있었다면 잘못된 것이므로 0을 리턴하여 !을 출력하고 종료할 수 있오록 한다. 
			return 0;
		}
		// 같은 알파벳을 떄 
		return 1;
	}
}

int	main () {

	int n, k;
	cin >> n >> k;
	deque <char> lucky(n, '?');

	int s; 
	char ch;
	while (k--) {
		scanf("%d %c", &s, &ch);
		if(!findLocation(lucky, s, ch)) {	// 유효한 location을 찾지 못하면 (return 0이면) !을 출력하고 종료한다. 
			cout << "!";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << lucky[i];
	}

	return 0;
}
