/*
동적계획법 - 필수

*/

#include <iostream>
#include <deque>

using namespace	std;

deque<int> dodo;
deque<int> susu;
deque<int> dodo_ground;
deque<int> susu_ground;

// 1이면 도도 승, 0이면 수연승
int	pushBell() {
	if (!dodo_ground.empty() && !susu_ground.empty() && (dodo_ground.front() + susu_ground.front() == 5))
			return 0;
	else if (dodo_ground.front() == 5 || susu_ground.front() == 5)
		return 1;
	else 
		return 2;
}
//////////////질문
////디버깅을 해보면 pushBell 까지는 들어오는데 18번 줄후로 세그멘테이션이 뜹니다... 그런데 왜 그런지 도통 모르겠어요 ㅠㅜ

void	keepCard(int win) {
	if (win == 1) {	// 도도승
		while (!susu_ground.empty()) {
			dodo.push_front(susu_ground.back());
			susu_ground.pop_back();
		}
		while (!dodo_ground.empty()) {
			susu.push_front(dodo_ground.back());
			dodo_ground.pop_back();
		}
	}
	else if (win == 0) {
		while (!dodo_ground.empty()) {
			susu.push_front(dodo_ground.back());
			dodo_ground.pop_back();
		}
		while (!susu_ground.empty()) {
			dodo.push_front(susu_ground.back());
			susu_ground.pop_back();
		}
	}
	else
	{
		return ;
	}
}

string	hally(int m) {

	int do_pop;
	int su_pop;
	for (int i = 0; i < m; i++) {
		do_pop = dodo.back();
		dodo.pop_back();
		dodo_ground.push_front(do_pop);
		keepCard(pushBell());
		su_pop = susu.back();
		susu.pop_back();
		susu_ground.push_front(su_pop);
		keepCard(pushBell());
	}
	if (dodo.size() > susu.size())
		return ("do\n");
	else if (dodo.size() < susu.size())
		return ("su\n");
	else
		return ("dosu\n");
}

int main () {

	int n, m;
	cin >> n >> m;

	dodo.assign(n, 0);
	susu.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> dodo[i] >> susu[i];
	}
		for (int i = 0; i < n; i++) {
		cout << i << ": " << dodo[i] << " " << susu[i] << "\n";
	}
	cout << hally(m);
	return 0;
}