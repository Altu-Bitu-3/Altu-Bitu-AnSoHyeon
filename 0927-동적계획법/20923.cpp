/*
동적계획법 - 필수

*/

#include <iostream>
#include <deque>

using namespace	std;
	deque<int> dodo_ground;
	deque<int> susu_ground;

// 1이면 도도 승, 0이면 수연승
int	pushBell()/*deque<int>&dodo_ground, deque<int>&susu_ground)*/ {
	if (!dodo_ground.empty() && !susu_ground.empty() && (dodo_ground.front() + susu_ground.front() == 5))
		return 0;
	if (dodo_ground.front() == 5 || susu_ground.front() == 5)
		return 1;
}

void	keepCard(int win, deque<int>&dodo, deque<int>&susu) {
	if (win) {	// 도도승
		if (!susu_ground.empty())
			// dodo = susu_ground + dodo; deque을 더하려면 어떻게 해야하지 ??
	}

}

string	hally(deque<int>&dodo, deque<int>&susu, int m) {

	int do_pop = 0;
	int su_pop = 0;

	for (int i = 0; i < m; i++) {
		do_pop = dodo.back();
		dodo.pop_back();
		dodo_ground.push_front(do_pop);
		pushBell();//dodo_ground, susu_ground);
		su_pop = susu.back();
		susu.pop_back();
		susu_ground.push_front(su_pop);
		pushBell();//dodo_ground, susu_ground);
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

	deque<int> dodo(n);
	deque<int> susu(n);
	for (int i = 0; i < n; i++) {
		int d, s;
		cin >> d >> s;
		dodo.push_back(d);
		susu.push_back(s);
	}

	cout << hally(dodo, susu, m);
	return 0;
}