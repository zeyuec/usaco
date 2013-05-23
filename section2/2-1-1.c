/*
  ID: zeyuec1
  LANG: C
  TASK: castle
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int M, N, map[60][60][5], hash[60][60], colorCount[300];
int maxRoomSize=0, maxX, maxY, maxD;

void put(int x, int y, int k)
{
    map[x][y][0] = k;
    int i=1;
    while (k > 0) {
        map[x][y][i++] = k % 2;
        k = k / 2;
    }
}

void findEmpty(int *retX, int *retY)
{
    int i, j;
    for (i=1; i<=N; i++) {
        for (j=1; j<=M; j++) {
            if (hash[i][j] == 0) {
                *retX = i;
                *retY = j;
                return;
            }
        }
    }
    *retX = 0;
    *retY = 0;
    return ;
}

void floodFill(int x, int y, int color, int *fillCount)
{
    if (x >= 1 && y >= 1 && x <= N && y <= M && hash[x][y] == 0) {
        (*fillCount)++;
        hash[x][y] = color;
        if (map[x][y][1] == 0) {
            floodFill(x, y-1, color, fillCount);
        }
        if (map[x][y][2] == 0) {
            floodFill(x-1, y, color, fillCount);
        }
        if (map[x][y][3] == 0) {
            floodFill(x, y+1, color, fillCount);
        }
        if (map[x][y][4] == 0) {
            floodFill(x+1, y, color, fillCount);
        }
    }
}

int markAndCalMaxRoom()
{
    int color=1, i, j, count, maxCount = 0;
    memset(hash, 0, sizeof(hash));
    findEmpty(&i, &j);
    do {
        /* fill and count */
        count = 0;
        floodFill(i, j, color, &count);
        colorCount[color] = count;
        maxCount = count > maxCount ? count : maxCount;
        color++;
        
        /* next try */
        findEmpty(&i, &j);
    } while (i != 0 && j != 0);
    
    return maxCount;
}

int calRoomNum() {
    int i, j, maxColor=0;
    for (i=1; i<=N; i++) {
        for (j=1; j<=M; j++) {
            maxColor = hash[i][j] > maxColor ? hash[i][j] : maxColor;
        }
    }
    return maxColor;
}

void save(int m, int x, int y, int d) {
    if (m > maxRoomSize) {
        maxRoomSize = m;
        maxX = x;
        maxY = y;
        maxD = d;
    } else if (m == maxRoomSize) {
        if (y < maxY || (y == maxY && x > maxX)) {
            maxRoomSize = m;
            maxX = x;
            maxY = y;
            maxD = d;
        } else if (x == maxX && y == maxY && d < maxD) {
            maxRoomSize = m;
            maxX = x;
            maxY = y;
            maxD = d;
        }
    }
}

void tryRemove() {
    int i, j, roomSize;
    for (i=1; i<=N; i++) {
        for (j=1; j<=M; j++) {
            if (i != 1 && map[i][j][2] == 1) {
                /* try remove NORTH wall*/
                roomSize = colorCount[hash[i][j]];                
                if (hash[i-1][j] != hash[i][j]) {
                    roomSize += colorCount[hash[i-1][j]];
                }
                save(roomSize, i, j, 0);
            }
            
            if (j != M && map[i][j][3] == 1) {
                /* try remove EAST wall*/
                roomSize = colorCount[hash[i][j]];
                if (hash[i][j+1] != hash[i][j]) {
                    roomSize += colorCount[hash[i][j+1]];
                }
                save(roomSize, i, j, 1);
            }
        }
    }
    printf("%d\n", maxRoomSize);
    printf("%d %d %c\n", maxX, maxY, maxD == 0 ? 'N' : 'E');
}

int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    int i, j, t;
    scanf("%d %d", &M, &N);
    for (i=1; i<=N; i++) {
        for (j=1; j<=M; j++) {
            scanf("%d", &t);
            put(i, j, t);
        }
    }
    colorCount[0] = 0;
    int maxRoom = markAndCalMaxRoom();
    int maxColor = calRoomNum();
    printf("%d\n%d\n", maxColor, maxRoom);
    tryRemove();
    return 0;
}
