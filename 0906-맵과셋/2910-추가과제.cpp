//선택 추가문제
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ci;//반복되는 형태는 typedef로 미리 선언하고 사용해요!
map<int, int> order;

//비교 정렬 함수 사용 시, 비교 변수는 함수 내에서 절대로 값이 변경되면 안돼 상수화를 권장해요!
//또 가독성을 위해, 같지 않을 경우에 대한 조건을 먼저 처리 하는 것을 권장해요! -> 국영수 문제를 참고해보세요!
bool cmp(const ci& a, const ci& b) {
	if (a.second != b.second) {
		return a.second > b.second; //빈도가 다르면 빈도수 내림차순
	}
	return order[a.first] < order[b.first]; //빈도가 같다면 순서(나온 순서,index) 오름차순
	 
}


int main() {

	int n,c, num;
	map<int, int> frequency;

	cin >> n>> c;

	//정수값에 따라서 빈도수와 처음 나온 순서를 frequency와 order에 저장
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (!frequency[num]) {
		// 만일 frequency에 없는 숫자면 처음으로 나온 숫자이므로 order에 해당 num이 가장 처음 나온 인덱스를 저장해두도록 한다. 
			order[num] = i; 
			//후에 만약 빈도수가 같다면 먼저 나온 숫자를 먼저 출력하기 위해 가장 처음나온 인덱스를 order에 저장해든다. 
		}
		frequency[num]++;
		// frequency의 value를 증가시켜 빈도수를 체크할 수 있도록 한다. 
	}

	/*
	* 정렬 순위
	* 1. 빈도수 내림차순
	* 2. 빈도수가 같다면 처음 나온 순서 오름차순
	*/
	vector<ci> v(frequency.begin(), frequency.end());//map은 정렬 함수가 따로 없어서 vector로 바꿔야해요!

	sort(v.begin(), v.end(), cmp); 
	// 두번째 값을 기준으로 정렬하는 순간이 필요하므로 cmp함수를 선언하여 의도한 대로 정렬할 수 있도록 한다. 

	for (int i = 0; i < v.size(); i++) {
		while (v[i].second--) {
			cout << v[i].first << ' ';
		} // 숫자의 빈도수만큼 while문을 돌려서 원하는 만큼 출력될 수 있도록 한다. 
	}

	return 0;
}

/*
map을 두개를 써서 한 숫자에 대한 다른 정보를 저장할 생각을 못했다. 그냥 두개를 선언해서 각자 저장하는데 한번에 저장해야한다고만 
생각했던 것 같다. 
이번 모범답안을 보면서는 특히 반복되는 선언을 typedef로 선언하여 간단하게 사용할 수 있다는 것과
map은 정렬함수가 없다는 것을 알 수 있었다. 
*/
