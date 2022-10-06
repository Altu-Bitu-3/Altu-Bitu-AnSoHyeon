/*
숫자를 저장할 수 있는 메모리가 적으므로 뽑아야하는 순위만큼 최소힙을 지원하는 큐를 만들어서 최소값을 뽑을 수 있도록 한다.
만일 입력값이 현재 큐의 최소값보다 크면 최소값을 pop하고 입력값을 큐에 새로 push한다.
이때 큐를 입력값의 최솟값 이하로 초기화해주어 음수가 들어와도 문제가 없도록 한다

큐를 생성만하고 입력값이 클때마다 push하면 큐의 크기가 뽑아야하는 순위보다 커져서 출력값을 따로 찾거나 뽑아야하는 순위보다
큐의 사이즈가 작을때는 pop을 하지 말아야하는 등 로직이 복잡해지므로 처음부터 크기를 N으로두고 값을 입력의 최솟값으로 초기화하여
새로 push할때마다 pop하는것이 더 간단할 것 같다
*/

#include <iostream>
#include <queue>
#include <functional> // greater

using namespace	std;

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int rank;
	cin >> rank;
	priority_queue<int, vector<int>, greater<int> > pq(rank, -1000000000); // https://data-make.tistory.com/342 최소힙 관련

	for (int i = 0; i < rank * rank; i++) {
		int input;
		cin >> input;
		if (input > pq.top()) {	// 지금 큐의 최솟값보다 입력값이 더클 때 
			pq.pop();
			pq.push(input);
		}
	}
	cout << pq.top() << "\n";
	
	return 0;
}