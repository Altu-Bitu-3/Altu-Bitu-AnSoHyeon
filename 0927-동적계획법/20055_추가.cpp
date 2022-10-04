/*
동적 계획법 - 추가제출

[컨베이어 벨트 위의 로봇]

1. 1번은 로봇을 올리는 위치, N번은 로봇을 내리는 위치이다.
2. 로봇이 위치하는 칸의 내구도는 1만큼 감소한다.
3. 앞의 칸에 로봇이 없고, 내구도가 1이상이면 로봇을 앞으로 이동시킨다.
4. 올리는 위치의 내구도가 0이 아니면 로봇을 올린다.
5. 내구도가 0인 칸이 K개 이상이면 종료한다.

종료되었을때 변먼째 단계가  진행중이었는지 출력한다.
---------------------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace	std;

// 해당 칸에 내구도와 로봇의 존재 여부를 알려준다. 
struct info
{
	int		power;
	bool	is_on;
};

vector<info> belt;	//컨테이너 각 칸의 정보를 저장할 배열
int	zero_power = 0; // 내구도가 0인 칸의 개수

/* 
배열에 처음 입력할 때의 값에 맞춰서 인덱스가 저장되어 있으므로 올리는 위치와 내리는 위치의 인덱스 값을 변경하는 방식으로 풀이한다.
이때 컨베이어 벨트가 돌아가는 방향이 인덱스가 올라가는 쪽으로 돌고 있으므로
올리는 위치와 내리는 위치의 인덱스는 -n이 되게 된다.
*/
int	minusPosition(int n, int pos) {
	// 만약에 pos가 0번째 인덱스였으면 이 배열의 끝인 n*2 -1 을 리턴하고 아니면 하나 이전의 인덱스를 리턴
	if (--pos >= 0) {
		return pos;
	}
	return n * 2 - 1;
}

void	second(int n, int start, int end) {
	int	cur = end;
	while (cur != start) { // end - 1 부터 start까지 로봇과 내구도를 확인한다.
		cur = minusPosition(n, cur); // 초기값이 end이므로 함수를 통해 end -1로 변경
		int	next = (cur + 1) % (n * 2); // 앞칸의 로봇과 내구도를 알아야하는데 인덱스가 n*2를 넘어갈 수 있으므로 n*2의 나머지를 활용
		if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { 
		// cur에 로봇이 있고, 앞칸에 로봇이 없으며 내구도가 1이상일때 
			belt[cur].is_on = false;
			belt[next].power--;
			// 로못을 옮기고 앞칸의 내구도 하락
			if (next != end) { // 앞칸이 내리는 위치기 아니면
				belt[next].is_on = true; //로봇을 앞칸으로 옮기기
			}	// 내리는 위치면 옮겨서 내리게 되므로 is_on값을 변걍할 필요가 없다.
			if (belt[next].power == 0) { // 앞칸의 내구도가 0이 되면 
				zero_power++;			// 내구도가 0인 칸의 개수를 늘린다.
			}
		}
	}
}

// 올리는 위치에 로봇을 올리는 단계
void	third(int start) {
	if (belt[start].power) { 
	// 올리는 위치의 내구도가 1이상이면 로봇을 올린다.
		belt[start].is_on = true;
		belt[start].power--;
		if (belt[start].power == 0) { // 로봇을 올려서 이 칸의 내구도가 0이되면 내구도가 0인 칸의 개수를 늘린다.
			zero_power++;
		}
	}
}

int	main () {
	// 입출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int	n, k;
	cin >> n >> k;
	belt.assign(n*2, {0, false}); // 아무것도 없는 값으로 구조체 초기화
	for (int i = 0; i < n*2; i++) {
		cin >> belt[i].power;
	}

	int start = 0; // 인덱스 상 -1한 값으로 시작
	int	end = n - 1;
	int	step = 0;
	while (true) {
		start = minusPosition(n, start); // 올리는 위치 재설정
		end = minusPosition(n, end); // 내리는 위치 재설정
		if ( belt[end].is_on) { // 내리는 위치에 로봇이 있으면
			belt[end].is_on = false;	// 로봇 내리기
		}	// 까지가 첫번째 단계
		second(n,start, end);	// 두번째 단계
		third(start);			// 세번쨰 단계
		step++;	// 한회차 돌았으므로 step++
		if (zero_power >= k) {	// 내구도 0이하가 k개 이상이면 그만하기
			break;
		}
	}
	cout << step;
	return 0;
}
