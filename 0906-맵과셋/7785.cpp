#include <iostream>
#include <string>
#include <map>

using namespace	std;

int main () {
	
	int num;
	cin >> num;

	map <string, string> list;
	string name;
	string val;
	for (int i = 0; i < num; i++) {
		cin >> name >> val;
		// leave로 들어오면 이미 있는 회사원이므로 바로 삭제한다. 
		if (val == "leave") {
			list.erase(name);
		}
		else
			list.insert(pair<string, string>(name, val));
	}

// 거꾸로 (내림 차순) 으로 출력하기 
	for (auto it = list.rbegin(); it != list.rend(); it++) {
		cout << it->first << "\n";
	}
	return 0;
}