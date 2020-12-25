#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

enum _Direction {
	dir_left,
	dir_right,
	dir_top,
	dir_down,
	horizontal,
	vertical
} Direction;

void randomStageDraw(char stageModel[100][100], int currentMapSize, int startX, int startY, int startDir, int *currenrStageGauge, int randomMapCount) {
	*currenrStageGauge = 0;
	for (int i = 0; i < currentMapSize; i++) {
		for (int j = 0; j < currentMapSize; j++) {
			if (i == 0 || j == 0 || i == currentMapSize - 1 || j == currentMapSize - 1) {
				stageModel[i][j] = 1;
			}
			else {
				stageModel[i][j] = 0;
			}
		}
	}

	int posX, posY;

	int diffX = 0, diffY = 0;
	srand(time(NULL));
	int currentDir = startDir;
	int cnt = -1;
	int favorite = 0;

	posX = startX;
	posY = startY;

	for (int i = 0; i < 140 + randomMapCount; i++) {

		/* 방향 설정*/
		int dir = rand() % 4;
		int distance;


		if (i == 0) {
			dir = currentDir;
		}
		/* 만약 같은 이전과 동일한 방향이면 다시 시도*/
		if (currentDir == dir) {
			if (i != 0) {
				continue;
			}

		}
		/* 진행했던 방향으로 바로 다시 돌아오는 것도 불가능*/
		if ((currentDir == dir_left && dir == dir_right) ||
			(currentDir == dir_right && dir == dir_left) ||
			(currentDir == dir_top && dir == dir_down) ||
			(currentDir == dir_down && dir == dir_top)
			) {
			continue;
		}
		// 오른쪽 위
		if (posX >= currentMapSize / 2 && posY <= currentMapSize / 2) {
			if (dir == dir_right || dir == dir_top) {
				if (favorite != 1 && i != 0) {
					favorite = 0;
					continue;
				}
			}
		}
		// 오른쪽 아래
		else if (posX >= currentMapSize / 2 && posY >= currentMapSize / 2) {
			if (dir == dir_right || dir == dir_down) {
				if (favorite != 1 && i != 0) {
					favorite = 0;
					continue;
				}
			}
		}
		// 왼쪽 위
		else if (posX <= currentMapSize / 2 && posY <= currentMapSize / 2) {
			if (dir == dir_left || dir == dir_top) {
				if (favorite != 1 && i != 0) {
					favorite = 0;
					continue;
				}
			}
		}
		// 왼쪽 아래
		else if (posX <= currentMapSize / 2 && posY >= currentMapSize / 2) {
			if (dir == dir_left || dir == dir_down) {
				if (favorite != 1 && i != 0) {
					favorite = 0;
					continue;
				}
			}
		}


		if (dir == dir_left) {
			distance = (rand() % posX) + 2;
		}
		else if (dir == dir_right) {
			distance = (rand() % (currentMapSize - posX)) + 2;
		}
		else if (dir == dir_top) {
			distance = (rand() % posY) + 2;
		}
		else if (dir == dir_down) {
			distance = (rand() % (currentMapSize - posY)) + 2;
		}

		if (dir == dir_left) {
			/*지정한 방향 바로 앞에 벽이네?*/
			if (stageModel[posY][posX - 1] == 1) {
				continue;
			}
			/*지정한 방향 바로 앞앞에 경로가 있네???*/  // <- 수정 가능
			if (stageModel[posY][posX - 2] < 0 && stageModel[posY][posX - 3] < 0) {
				favorite = 1;
				continue;
			}
			/*지정한 길이만큼 가면 원래 길이 막히네?*/
			if (stageModel[posY][posX - distance - 1] < 0) {
				continue;
			}
			if (stageModel[posY][posX - distance] < 0) {
				continue;
			}
			/*거기까지 가면 갈곳이 없네?*/
			if (stageModel[posY - 2][posX - distance] < 0 || stageModel[posY + 2][posX - distance] < 0) {
				if (stageModel[posY - 1][posX - distance] < 0 || stageModel[posY + 1][posX - distance] < 0) {
					continue;
				}
			}
		}
		else if (dir == dir_right) {
			if (stageModel[posY][posX + 1] == 1) {
				continue;
			}
			if (stageModel[posY][posX + 2] < 0 && stageModel[posY][posX + 3] < 0) {
				favorite = 1;
				continue;
			}
			if (stageModel[posY][posX + distance + 1] < 0) {
				continue;
			}
			if (stageModel[posY][posX + distance] < 0) {
				continue;
			}
			if (stageModel[posY - 2][posX + distance] < 0 || stageModel[posY + 2][posX + distance] < 0) {
				if (stageModel[posY - 1][posX + distance] < 0 || stageModel[posY + 1][posX + distance] < 0) {
					continue;
				}
			}
		}
		else if (dir == dir_top) {
			if (stageModel[posY - 1][posX] == 1) {
				continue;
			}
			if (stageModel[posY - 2][posX] < 0 && stageModel[posY - 3][posX] < 0) {
				favorite = 1;
				continue;
			}
			if (stageModel[posY - distance - 1][posX] < 0) {
				continue;
			}
			if (stageModel[posY - distance][posX] < 0) {
				continue;
			}
			if (stageModel[posY - distance][posX + 2] < 0 || stageModel[posY - distance][posX - 2] < 0) {
				if (stageModel[posY - distance][posX + 1] < 0 || stageModel[posY - distance][posX - 1] < 0) {
					continue;
				}
			}
		}
		else if (dir == dir_down) {
			if (stageModel[posY + 1][posX] == 1) {
				continue;
			}
			if (stageModel[posY + 2][posX] < 0 && stageModel[posY + 3][posX] < 0) {
				favorite = 1;
				continue;
			}
			if (stageModel[posY + distance + 1][posX] < 0) {
				continue;
			}
			if (stageModel[posY + distance][posX] < 0) {
				continue;
			}
			if (stageModel[posY + distance][posX + 2] < 0 || stageModel[posY + distance][posX - 2] < 0) {
				if (stageModel[posY + distance][posX + 1] < 0 || stageModel[posY + distance][posX - 1] < 0) {
					continue;
				}
			}
		}

		currentDir = dir;
		if (currentDir == dir_left) {
			for (int j = 0; j < distance; j++) {
				if (stageModel[posY][posX - 1] == 1) {
					break;
				}
				stageModel[posY][posX] = cnt;
				posX -= 1;
			}
			stageModel[posY][posX - 1] = 1;
		}
		else if (currentDir == dir_right) {
			for (int j = 0; j < distance; j++) {
				if (stageModel[posY][posX + 1] == 1) {
					break;
				}
				stageModel[posY][posX] = cnt;
				posX += 1;
			}
			stageModel[posY][posX + 1] = 1;
		}
		else if (currentDir == dir_top) {
			for (int j = 0; j < distance; j++) {
				if (stageModel[posY - 1][posX] == 1) {
					break;
				}
				stageModel[posY][posX] = cnt;
				posY -= 1;
			}
			stageModel[posY - 1][posX] = 1;
		}
		else if (currentDir == dir_down) {

			for (int j = 0; j < distance; j++) {
				if (stageModel[posY + 1][posX] == 1) {
					break;
				}
				stageModel[posY][posX] = cnt;
				posY += 1;
			}
			stageModel[posY + 1][posX] = 1;
		}

		if (diffX != posX || diffY != posY) {
			(*currenrStageGauge)++;
		}
		cnt--;
		diffX = posX;
		diffY = posY;


	}

	stageModel[startY][startX] = 9;

	(*currenrStageGauge) += 3;
	/* 목표지점 설정 */
	if (currentDir == dir_down) {
		stageModel[posY - 1][posX] = 8;
	}
	else if (currentDir == dir_top) {
		stageModel[posY + 1][posX] = 8;
	}
	else if (currentDir == dir_left) {
		stageModel[posY][posX + 1] = 8;
	}
	else if (currentDir == dir_right) {
		stageModel[posY][posX - 1] = 8;
	}


   for (int y = 1; y < currentMapSize - 1; y++) {
	  for (int x = 1; x < currentMapSize - 1; x++) {
		 if (stageModel[y][x] == 1) {
			if (stageModel[y][x + 1] == 0) {
			   int r = rand() % 2;
			   if (r == 0) {
				  stageModel[y][x + 1] = 1;
			   }
			}
			if (stageModel[y][x - 1] == 0) {
			   int r = rand() % 2;
			   if (r == 0) {
				  stageModel[y][x - 1] = 1;
			   }
			}
			if (stageModel[y + 1][x] == 0) {
			   int r = rand() % 2;
			   if (r == 0) {
				  stageModel[y + 1][x] = 1;
			   }
			}
			if (stageModel[y - 1][x] == 0) {
			   int r = rand() % 2;
			   if (r == 0) {
				  stageModel[y - 1][x] = 1;
			   }
			}
		 }
	  }
   }

   for (int y = currentMapSize - 2; y > 0; y--) {
	  for (int x = currentMapSize - 2; x > 0; x--) {
		 if (stageModel[y][x] == 1) {
			if (stageModel[y][x + 1] == 0) {
			   int r = rand() % 2;
			   if (r == 0) {
				  stageModel[y][x + 1] = 1;
			   }
			}
			if (stageModel[y][x - 1] == 0) {
			   int r = rand() % 2;
			   if (r == 0) {
				  stageModel[y][x - 1] = 1;
			   }
			}
			if (stageModel[y + 1][x] == 0) {
			   int r = rand() % 2;
			   if (r == 0) {
				  stageModel[y + 1][x] = 1;
			   }
			}
			if (stageModel[y - 1][x] == 0) {
			   int r = rand() % 2;
			   if (r == 0) {
				  stageModel[y - 1][x] = 1;
			   }
			}
		 }
	  }
   }
}