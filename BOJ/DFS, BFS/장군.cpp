// 16509
/*
문제
오랜만에 휴가를 나온 호근이는 문득 동아리방에 있는 장기가 하고 싶어졌다. 
하지만 장기를 오랫동안 하지 않은 탓인지 예전에는 잘 쓰던 상을 제대로 쓰는 것이 너무 힘들었다. 
호근이를 위해 상을 어떻게 써야 할지 도와주자.
(0, 3)과 (2, 5)를 꼭짓점으로 하는 사각형과, (7, 3)과 (9, 5)를 꼭짓점으로 하는 사각형은 왕이 위치할 수 있는 궁성이라고 한다. 
상은 8가지 방법으로 움직일 수 있는데, 상, 하, 좌, 우로 한 칸을 이동한 후에 같은 방향 쪽 대각선으로 두 칸 이동한다.

만약 상이 이동하는 경로에 다른 기물이 있다면 상은 그쪽으로 이동할 수 없다. 또한, 상이 장기판을 벗어날 수도 없다.

10×9 크기의 장기판 위에 상과 왕의 처음 위치가 주어졌을 때, 상이 왕에게 도달할 수 있는 최소 이동 횟수를 구하여라.

입력
첫 번째 줄에는 상의 위치를 의미하는 정수 R1, C1이 주어진다.

두 번째 줄에는 왕의 위치를 의미하는 정수 R2, C2가 주어진다. 
장기판에서 Ri (0 ≤ Ri ≤ 9)는 행을, Ci (0 ≤ Ci ≤ 8)는 열을 의미한다.

왕은 항상 궁성에 자리 잡고 있으며, 상과 왕의 위치는 겹치지 않는다.

출력
상이 왕에게 도달할 수 있는 최소 이동 횟수를 출력한다. 
만약 도달할 수 없다면 -1을 출력한다.
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int answer = 99;
int s_x, s_y;
int w_x, w_y;
		//  (0,1)  (0,-1) (1,0)  (-1,0)
int dx[8] = {2, -2, 2, -2, 3, 3, -3, -3};
int dy[8] = {3, 3, -3, -3, 2, -2, 2, -2};
int ox[16] = {0, 1, 0, -1, 0, 1, 0, -1, 1, 2, 1, 2, -1, -2, -1, -2};
int oy[16] = {1, 2, 1, 2, -1, -2, -1, -2, 0, 1, 0, -1, 0, 1, 0, -1};

bool visit[10][9];

void dfs(int x, int y, int dep){
    if(x == w_x && y == w_y){
        answer = min(answer, dep);
        return;
    }
    
    if(dep > answer)
    	return;
    
    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || ny<0 || nx>9 || ny>8) continue;
        if(visit[nx][ny])continue;
        if((x+ox[i*2] == w_x && y+oy[i*2]) == w_y || (x+ox[i*2+1] == w_x && y+oy[i*2+1] == w_y)) continue;
        visit[nx][ny] = true;
        dfs(nx, ny, dep+1);
        visit[nx][ny] = false;
    }
}

int main(){
    scanf("%d %d", &s_x, &s_y);
    scanf("%d %d", &w_x, &w_y);
    
    visit[s_x][s_y] = true;
    
    dfs(s_x, s_y, 0);
    
    if(answer == 99){
    	printf("-1");
    	return 0;
	}
    
    printf("%d", answer);
    
    return 0;
}
