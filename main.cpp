#include <bits/stdc++.h>
#include <conio.h>

/*
0: space path
1: wall
3: destination
4: box
5: player
7: box on destination
8: player on destination
*/

int init_map[8][8] = {
    {0, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 0, 3, 0, 1, 0, 0},
    {1, 0, 4, 3, 4, 1, 1, 0},
    {1, 0, 0, 3, 4, 0, 1, 0},
    {1, 0, 4, 3, 0, 5, 1, 0},
    {1, 0, 4, 3, 4, 1, 1, 0},
    {1, 1, 0, 3, 0, 1, 0, 0},
    {1, 0, 1, 1, 1, 1, 0, 0}
};
// int init_map[8][8]={
//     {1,1,1,1,1,1,1,1},
//     {1,0,0,0,1,0,0,1},
//     {1,0,1,0,1,4,3,1},
//     {1,0,0,0,0,4,3,1},
//     {1,0,1,0,1,4,3,1},
//     {1,0,0,0,1,0,0,1},
//     {1,1,1,1,1,5,0,1},
//     {0,0,0,0,1,1,1,1}};
int map[8][8];
int r, c; // row and column for player

void init() {
    memcpy(map, init_map, sizeof(init_map));
    r = 4, c = 5;
    // r = 6, c = 5;
}

void render() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch(map[i][j]) {
                case 0:printf(" ");break;
                case 1:printf("#");break;
                case 3:printf(".");break;
                case 4:printf("@");break;
                case 5:printf("P");break;
                case 7:printf("@");break;
                case 8:printf("P");break;
            }
            putchar(' ');
        }
        printf("\n");
    }
}

void player() {
    char key = getch();
    switch (key) {
        case 'w':
            if (map[r-1][c] == 0 || map[r-1][c] == 3) {
                map[r-1][c] += 5;
                map[r][c] -= 5;
                r--;
            } else if (map[r-1][c] == 4 || map[r-1][c] == 7) {
                if (map[r-2][c] == 0 || map[r-2][c] == 3) {
                    map[r-2][c] += 4;
                    map[r-1][c] += 1;
                    map[r][c] -= 5;
                    r--;
                }
            }
            break;

        case 's':
            if (map[r+1][c] == 0 || map[r+1][c] == 3) {
                map[r+1][c] += 5;
                map[r][c] -=5;
                r++;
            } else if (map[r+1][c] == 4 || map[r+1][c] == 7) {
                if (map[r+2][c] == 0 || map[r+2][c] == 3) {
                    map[r+2][c] += 4;
                    map[r+1][c] += 1;
                    map[r][c] -= 5;
                    r++;
                }
            }
            break;
        
        case 'a':
            if (map[r][c-1] == 0 || map[r][c-1] == 3) {
                map[r][c-1] += 5;
                map[r][c] -= 5;
                c--;
            } else if (map[r][c-1] == 4 || map[r][c-1] == 7) {
                if (map[r][c-2] == 0 || map[r][c-2] == 3) {
                    map[r][c-2] += 4;
                    map[r][c-1] += 1;
                    map[r][c] -= 5;
                    c--;
                }
            }
            break;
        
        case 'd':
            if (map[r][c+1] == 0 || map[r][c+1] == 3) {
                map[r][c+1] += 5;
                map[r][c] -= 5;
                c++;
            } else if (map[r][c+1] == 4 || map[r][c+1] == 7) {
                if (map[r][c+2] == 0 || map[r][c+2] == 3) {
                    map[r][c+2] += 4;
                    map[r][c+1] += 1;
                    map[r][c] -= 5;
                    c++;
                }
            }
            break;
        
        case 'r': init();
        default: break;
    }
    
}

int main() {
    init();

    while (1) {
        system("cls");
        render();
        player();
    }
    return 0;

}