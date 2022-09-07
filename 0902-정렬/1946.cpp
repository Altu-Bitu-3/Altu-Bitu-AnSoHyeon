/*
첫번째 점수를 기준으로 정렬하고
1등의 두번째 점수(a)를 저장한 후 다음 순위자의 두번째 점수가 a보다 낮으면 탈락, 높으면 합격
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace	std;

bool	compareFirst(pair<int,int> a, pair<int,int> b) {
	return (a.first < b.first);
}

int	main () {

	int test_case;
	cin >> test_case;
	vector<int> pass;
	pass.assign(test_case, 1);

	int n;
	for (int i = 0; i < test_case; i++) {
		cin >> n;
		vector< pair<int, int> > rank(n);
		for (int k = 0; k < n; k++) {
			cin >> rank[k].first >> rank[k].second;
		}

		sort(rank.begin(), rank.end(), compareFirst);

		int	limit = rank[0].second;
		for (int k = 1; k < n; k++) {
			if (rank[k].second < limit) {
				pass[i]++;
				limit = rank[k].second; // 두번째의 최소 랭크를 계속 갱신하여 갈수록 최소 랭크 기준이 높아지도록 한다. 
			}
		}
	}
	for (int i = 0; i < test_case; i++) {
		cout << pass[i] << "\n";
	}
	return (0);
}
