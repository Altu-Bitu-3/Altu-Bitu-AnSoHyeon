#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 21;
/*
 * vector 사용 풀이
 */
int main()
{
	//cout, cin에 대한 출력속도를 높이기 위함
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> s(SIZE, false); // 0~20의 유무를 나타낼 배열을 false로 초기화
	//숫자를 인덱스로 생각해서 숫자가 있고 없고를 true와 false로 판별한다. 
    int m;

	// 명령어의 입력 횟수동안 while문을 돈다. 
    cin >> m;
    while (m--)
    {
        string command;
        cin >> command;
        if (command == "all")
        {
            s.assign(SIZE, true); // true의 값으로 SIZE개의 원소를 할당
			// all 명령어가 들어오면 모든 인덱스의 flag를 true로 바꾼다. 
        }
        else if (command == "empty")
        {
            s.assign(SIZE, false);
			// empty 명령어가 들어오면 모든 인덱스의 flag를 false로 바꾼다. 
        }
        else
        {
			// 명령어가 all이나 empty가 아니면 명령어 실행을 위해 숫자를 받아야 하므로 숫자를 받는다. 
            int x;
            cin >> x;
			// 역시 들어온 숫자를 인덱스로 생각해서 인덱스의 플래그를 껐다 켜는 방식으로 생각할 수 있다. 
            if (command == "add")
            {
                s[x] = true;
				//숫자 x가 있다는 표시
            }
            if (command == "remove")
            {
                s[x] = false;
				// 숫자 x가 없다는 표시
            }
            if (command == "check")
            {
                cout << s[x] << '\n'; // true이면 1을, false이면 0을 출력
				// true, false로 값을 저장했기때문에 단순히 출력만해도 원하는 결과값을 출력할 수 있다. 
            }
            if (command == "toggle")
            {
                s[x] = !s[x]; // true이면 false를, false면 true를 대입
				// 있으면 없고, 없으면 있게 하는 명령어이므로 단순히 반대(!)기호를 사용하여 원하는 결과를 낼 수 있다. 
            }
        }
    }
    return 0;
}

/*
 처음에 할 때는 set으로 놓고 풀었는데 생각해보니 정렬할 필요가 없으므로 굳이 set으로 놓을 이유가 없던 문제였다. 
 숫자를 삽입, 삭제, 있는지 확인해야한다는 생각에 무조건 value를 숫자로 두려고 했는데 모범답안을 통해
 그럴 필요없이 인덱스를 숫자로 두고 flag를 놓으면 훨씬 구현하기 효율적일 수 있다는 것을 배웠다. 
 이 문제가 숫자를 1-20으로 제한해둬서 가능한 것 같다. 
*/
