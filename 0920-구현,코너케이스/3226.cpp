/*
0920-구현코너케이스 / 선택

통화시작시간이 07:00-17:59이면 1븐에 10원을, 19:00~05:59이면 1분에 5원을 적용하도록 한다. 
통화할 수 있는 시간이 최대 60분이므로 통화 요금 상향의 경계에 들어갈 수 있는 시간은 06:00-06:59, 18:00-18:59 이다.
이 시간에 통화를 시작하면 통화기간을 통화시작시간에 더해서 분이 60이상이 되면 경계를 넘은것으로 간주하고 따로 계산해주는 로직을 사용한다.   
*/

#include <iostream>
#include <string>

using namespace	std;

int	timeToPayBoth(int hour, int min, int dur) {
	
	if (min + dur > 59) {
		int h_not_over, h_over;
		h_over = min + dur - 60;
		h_not_over = dur - h_over;
		if (hour == 6) {
			return (h_not_over * 5 + h_over * 10);
		}
		else {
			return (h_not_over * 10 + h_over * 5);
		}
	}
	else {
		if (hour == 6) 
			return (dur * 5);
		else
			return (dur * 10);
	}
}

int	calcBill(string time, int dur) {
	
	int hour;
	int min;
	hour = stoi(time);
	time = time.substr(3,2);
	min = stoi(time);

	if (hour == 6 || hour == 18) {
		return (timeToPayBoth(hour, min, dur));
	}
	else if (hour > 6 && hour < 18) {
		return (dur * 10);
	}
	else {
		return (dur * 5);
	}	
}

int main () {

	int n;
	cin >> n;
	
	string	time;
	int 	dur;
	int		pay = 0;
	for (int i = 0; i < n; i++) {
		cin >> time >> dur;
		pay += calcBill(time, dur);
	}

	cout << pay << "\n";

	return 0;
}