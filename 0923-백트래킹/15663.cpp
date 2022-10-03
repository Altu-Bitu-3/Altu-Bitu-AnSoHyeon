#include <iostream>
#include <vector>
#include <algorithm>

using namespace	std;
const int MAX = 8;

int n, m;
vector<bool> check(MAX, false); 
vector<int> num(MAX, 10010);	// 입력으로 들어온 수 목록 // sort 했을떄 빈칸이 앞으로 오는 것을 방지하기 위해 큰 값으로 초기화
vector<int> arr(MAX, 0);

void	backtracking(int count) {

	if (count == m) {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return ;
	}

	int	before = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i] && before != num[i]) {
			arr[count] = num[i];	
			// 실제로 이라인에서 배열을 모두 출력하도록 해보면 이 앞의 인덱스까지는 저장해두고 지금의 인덱스부분만 계속 교체해가면서 배열을 완성한다. 
			// 또한 배열은 이미 오름차순으로 정렬되어 작은 순서부터 인덱스에 넣어보고 있다. 
			// 따라서 지금 인덱스 넣을 값이 이전에 인덱스에 넣어보았던 값과 같다면 중복된 순열이고
			// 다르면 다른 순열이라고 결정할 수 있다. 
			before = num[i];
			check[i] = true;
			backtracking(count + 1);
			check[i] = false;
		}
	}
}

int main () {

	cin >> n >> m;
	int	input;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	backtracking(0);
	return 0;
}
