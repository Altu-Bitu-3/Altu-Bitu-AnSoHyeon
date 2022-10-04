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
	if (!dodo_ground.empty() && !susu_ground.empty() && dodo_ground.front() + susu_ground.front() == 5)
			return 0;
	else if (!dodo_ground.empty() && dodo_ground.front() == 5 || !susu_ground.empty() && susu_ground.front() == 5)
		return 1;
	else 
		return 2;
}

void	dequeSum(deque<int> &winner, deque<int> &winner_grd, deque<int> &loser_grd) {
	while (!loser_grd.empty()) {
		winner.push_front(loser_grd.back());
		loser_grd.pop_back();
	}
	while (!winner_grd.empty()) {
		winner.push_front(winner_grd.back());
		winner_grd.pop_back();
	}
}

void	keepCard(int win) {
	if (win == 1) {	// 도도승
		dequeSum(dodo, dodo_ground, susu_ground);
		// while (!susu_ground.empty()) {
		// 	dodo.push_front(susu_ground.back());
		// 	susu_ground.pop_back();
		// }
		// while (!dodo_ground.empty()) {
		// 	susu.push_front(dodo_ground.back());
		// 	dodo_ground.pop_back();
		// }
	}
	else if (win == 0) {
		dequeSum(susu, susu_ground, dodo_ground);
		// while (!dodo_ground.empty()) {
		// 	susu.push_front(dodo_ground.back());
		// 	dodo_ground.pop_back();
		// }
		// while (!susu_ground.empty()) {
		// 	dodo.push_front(susu_ground.back());
		// 	susu_ground.pop_back();
		// }
	}
	else
	{
		return ;
	}
}

string	hally(int m) {

	bool	flag = true; // true->dodo exec, false->su evec

	for (int i = 0; i < m; i++) {
		
		if (flag) { // dodo turn
			dodo_ground.push_front(dodo.back());
			dodo.pop_back();
			if (dodo.empty())
				return "su\n";
		} else {
			susu_ground.push_front(susu.back());
			susu.pop_back();
			if (susu.empty())
				return "do\n";

		}
		keepCard(pushBell());
		flag = !flag;
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

	cout << hally(m);
	return 0;
}