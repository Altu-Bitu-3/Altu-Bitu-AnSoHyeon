#include <queue>
#include <iostream>

using namespace	std;

int	returnQueue(priority_queue<int> &pq) {
	if (!pq.empty()) { // 
		int top;
		top = pq.top();
		pq.pop();
		return (-1 * top);	// 원소의 부호를 바꿔서 push했으므로 다시 부호를 바꿔서 리턴하여 출력한다.
	}
	else {
		return 0;
	}
}

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int time;
	cin >> time;
	priority_queue<int> pq;

	int	input;
	while (time--) {
		cin >> input;
		if (input == 0) {
			cout << returnQueue(pq) << "\n";
		}
		else {
			pq.push(-1 * input);	// 입력값은 0과 자연수뿐이므로 우선순위를 거꾸로 하기위해 부호를 바꿔서 push한다.
		}
	}
	return 0;
}