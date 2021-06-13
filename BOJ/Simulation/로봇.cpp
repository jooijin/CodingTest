// 13567
/*
문제
로봇은 명령어를 읽어들여 정사각형 영역 S를 x축 또는 y축과 평행한 방향으로 움직인다. 
S의 왼쪽 아래 꼭짓점은 (0, 0)이고, 오른쪽 위의 꼭짓점은 (M, M)이다. 처음에 로봇은 (0, 0)에 위치해 있고, 동쪽 방향을 향하고 있다.

명령어는 로봇이 현재 위치에서 행할 동작과 그 동작과 관련된 값으로 주어진다. 
동작은 두 가지가 있는데, TURN과 MOVE이다. 
TURN 0 명령은 현재 위치에서 왼쪽으로 90도 회전, TURN 1 명령은 현재 위치에서 오른쪽으로 90도 회전을 의미한다. 
MOVE d 명령은 로봇이 향하고 있는 방향으로 d만큼 움직이는 것을 의미한다. 여기서 d는 양수이다.

명령의 수행 후 로봇이 S의 경계 또는 내부에 있으면 이 명령어는 유효하다. 
만일 명령어 수행 후 로봇이 S의 바깥으로 완전히 나가게 된다면 명령어는 유효하지 않다. 
일련의 명령어 열을 이루는 각 명령어가 모두 유효하다면, 이 명령어 열을 유효하다고 한다.

예를 들어 로봇이 왼쪽 그림과 같이 (MOVE 6, TURN 0, MOVE 5, TURN 0, MOVE 2, TURN 0, MOVE 2, TURN 0, MOVE 4, TURN 0, MOVE 3, MOVE 2) 명령어를 읽어들인다면, 
최종적으로 로봇은 (8, 8) 위치에 있게 된다. 
가운데 그림과 같이 (MOVE 10, TURN 0, MOVE 2, TURN 0, MOVE 5, TURN 1, MOVE 5, TURN 1, MOVE 2, TURN 1, MOVE 3, TURN 0, TURN 0, MOVE 6) 명령어를 읽어들인다면, 
로봇은 (7, 10)에 위치하게 된다. 
오른쪽 그림과 같이 로봇이 S 바깥으로 나간다면, 명령어 열은 유효하지 않다.



그림 1. M = 11일 때 세 가지 명령어 열을 받은 로봇의 경로

한 변의 길이가 M인 정사각형과 n개의 명령어, 그리고 로봇이 (0, 0) 위치에서 시작해 동쪽을 바라보고 있을 때, n개의 명령어를 따라 움직였을 때 최종 위치를 출력하는 프로그램을 작성하라.

입력
입력은 표준 입력으로부터 받는다. 첫 줄에는 두 정수 M과 n (1 ≤ M ≤ 1,000, 1 ≤ n ≤ 1,000)이 주어진다. 
M은 정사각형 S의 한 변의 길이, 즉 오른쪽 맨 위의 좌표는 (M, M)이 된다. n은 로봇이 수행할 n개의 명령어이다. 
그 다음 n개의 줄에는 명령어가 하나씩 주어진다. 각 명령어는 TURN과 dir 또는 MOVE와 d의 쌍으로 주어진다. 
여기서 dir은 0 또는 1이며 d는 1,000 이하의 양의 정수이다. 로봇의 처음 위치는 (0, 0)이며 동쪽을 바라보고 있음에 유의하라.

출력
표준 출력으로 정확히 한 줄을 출력한다. 명령어 열이 유효하다면 두 음 아닌 정수를 출력하며, 이는 각각 명령어 수행 후 로봇의 위치의 x좌표와 y좌표이고 빈 칸으로 구분되어 있다. 
명령어 열이 유효하지 않다면 -1을 출력한다.
*/

#include <iostream>
#include <string>

using namespace std;

int M;
int x = 0,y = 0;
int dir = 0;

// 0 동쪽, 1 북쪽, 2 서쪽, 3 남쪽
// dir+1 % 4;

int robot(string comm, int num){
    if(comm == "MOVE"){
        switch(dir){
            case 0:
                x+=num;
                break;
            case 1:
                y+=num;
                break;
            case 2:
                x-=num;
                break;
            case 3:
                y-=num;
                break;
        }
        if(x<0 || y<0 || x>M || y >M) return -1;
    }
    else{
    	if(num == 0){
        	dir = (dir+1)%4;
        }
        else{
        	dir -= 1;
        	if(dir < 0)
        		dir = 3;
		}
    }
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    
	cin>>M>>n;
    
    for(int i=0; i<n; i++){
        string comm;
        int num;
        cin>>comm>>num;
        int res = robot(comm, num);
        if(res == -1){cout<<-1; return 0;}
    }
    
    cout<<x<<" "<<y;
    
    return 0;
}
