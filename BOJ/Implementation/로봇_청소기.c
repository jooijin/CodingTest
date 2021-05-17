// 못풀어서 다른 사람 풀이를 참고했다
// 방식은 똑같은데 왜 오류가 났을까..
// 수학적으로 생각하면 조금 더 효율적으로 풀 수 있다
//14503
/*
문제
로봇 청소기가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.

로봇 청소기가 있는 장소는 N×M 크기의 직사각형으로 나타낼 수 있으며, 1×1크기의 정사각형 칸으로 나누어져 있다. 
각각의 칸은 벽 또는 빈 칸이다. 청소기는 바라보는 방향이 있으며, 이 방향은 동, 서, 남, 북중 하나이다. 
지도의 각 칸은 (r, c)로 나타낼 수 있고, r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로 부터 떨어진 칸의 개수이다.

로봇 청소기는 다음과 같이 작동한다.

현재 위치를 청소한다.
현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.

입력
첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)

둘째 줄에 로봇 청소기가 있는 칸의 좌표 (r, c)와 바라보는 방향 d가 주어진다. 
d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.

셋째 줄부터 N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 
빈 칸은 0, 벽은 1로 주어진다. 지도의 첫 행, 마지막 행, 첫 열, 마지막 열에 있는 모든 칸은 벽이다.

로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.

출력
로봇 청소기가 청소하는 칸의 개수를 출력한다.
*/

#include <stdio.h>

int main(void){
    int answer = 0;
    int N, M;
    int y, x, dir;
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &y, &x, &dir);
    
    int arr[50][50];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    while(1){
        if(arr[y][x]==0){
			arr[y][x]=2;//1
			answer++;
		}
		if(arr[y-1][x]>0 && arr[y+1][x]>0 && arr[y][x-1]>0 && arr[y][x+1]>0){//four-way blocked
			if(dir%2==0){//N,S
				if(arr[y+1-dir][x]==1){//2-d
					break;
				}
				else y-= dir-1;//2-c
			}
			else{//E,W
				if(arr[y][x+dir-2]==1) break;
				else x+=dir-2;
			}
		}
		else if(dir%2==0){
			if(arr[y][x+(dir-1)]==0){//2-a
				x+=(dir-1);
			}
			dir=(dir+3)%4;//rotate
		}
		else{
			if(arr[y+(dir-2)][x]==0){//2-a
				y+=(dir-2);
			}
			dir=(dir+3)%4;//rotate
		}
    }
    
    printf("%d", answer);
    
    return 0;
}
