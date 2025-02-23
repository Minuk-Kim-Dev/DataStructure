#define _CRT_SECURE_NO_WARNINGS		//입출력과정에서 발생하는 경고를 무시하기 위해 추가합니다.
#include <stdio.h>		//표준 입출력 헤더입니다.

void Find(int maze[][10], int i, int j) {		//미로, i(통과하는 사람의 행 위치), j(통과하는 사람의 열 위치) 입니다.
	//왼쪽으로 이동 방향 파악
	if (i == 0 && j == 0) {		//아직 미로에 들어가지 않았을 떄
		for (i = 0; i < 8; i++) {		//첫번째 열에서 입구를 찾습니다
			if (maze[i][j] == 0) {		//원소의 값이 0인 곳이 입구입니다.
				return Find(maze, i, j);		//입구를 찾으면 입구의 위치를 매개변수로 넘기며 함수를 다시 호출합니다
			}
		}
	}

	maze[i][j] = 2;		//내가 지나간 길을 2로 바꿉니다.

	for (int x = 0; x < 8; x++) {		//미로를 통과하는 과정 전체를 출력하기 위해 추가했습니다.
		for (int y = 0; y < 10; y++) {
			printf("%d ", maze[x][y]);
		}
		printf("\n");
	}
	printf("\n\n");

	if (i < 8 && j + 1 < 10) {		//벽을 넘지 않을 때
		if (maze[i - 1][j] == 0) {		//위로 이동할 수 있는지 확인합니다.
			return Find(maze, --i, j);		//이동할 수 있다면 해당 위치를 매개변수로 넘기며 함수를 다시 호출합니다.
		}
		else if (maze[i][j + 1] == 0) {		//오른쪽으로 이동할 수 있는지 확인합니다.
			return Find(maze, i, ++j);		//이동할 수 있다면 해당 위치를 매개변수로 넘기며 함수를 다시 호출합니다.
		}
		else if (maze[i + 1][j] == 0) {		//아래로 이동할 수 있는지 확인합니다.
			return Find(maze, ++i, j);		//이동할 수 있다면 해당 위치를 매개변수로 넘기며 함수를 다시 호출합니다.
		}
		else if (maze[i][j - 1] == 0) {		//좌측으로 이동할 수 있는지 확인합니다.
			return Find(maze, i, --j);		//이동할 수 있다면 해당 위치를 매개변수로 넘기며 함수를 다시 호출합니다.
		}
	}
}

int main() {
	int i = 0;		//미로를 통과하는 사람의 행 위치
	int j = 0;		//미로를 통과하는 사람의 열 위치

	int maze[8][10] =		//미로입니다
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1}
	};

	Find(maze, i, j);		//미로를 빠져나가는 함수를 호출합니다.
}