/************************************************
input data : 
5 5
#####
#..B#
#.#.#
#RO.#
#####

7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######

7 7
#######
#..R#B#
#.#####
#.....#
#####.#
#O....#
#######

3 7
#######
#R.O.B#
#######

10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.##...#
#O..#....#
##########

10 6
######
#....#
#.#..#
#..#R#
##.#.#
#....#
#.#.B#
#..#O#
#.#..#
######

6 10
##########
#R.B...#.#
#........#
#..#.#...#
#O...#...#
##########

10 8
########
##.....#
#.#.#.O#
#...#.##
#....R##
#.#...##
#......#
#.#....#
#B.....#
########

9 5
#####
#..R#
#.B.#
#.#.#
#...#
#...#
##.O#
#...#
#####

5 9
#########
#R.#....#
#O......#
###..B..#
#########

10 5
#####
#B#.#
#.O.#
#..##
##..#
#...#
#R..#
#.#.#
#...#
#####

9 10
##########
##.#.....#
#........#
#........#
#...#.#..#
#.#.B..#.#
#...##.RO#
#........#
##########

8 10
##########
##..R....#
#.......##
#...#....#
#.#......#
#.#.....B#
#...O...##
##########

9 8
########
#..B.O##
#.#.R#.#
#..#..##
#......#
#.#.#..#
#..##..#
#...#..#
########

10 6
######
#....#
#..#.#
#..#R#
#....#
##...#
##..##
#.B..#
#.#O.#
######

5 7
#######
#.B...#
#..O#.#
#...R.#
#######

7 9
#########
#..#....#
#O.##..##
##..R..##
#.....#.#
#...#.B.#
#########

**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
using namespace std;

#define MAXNUM 1e9
char map[11][11] = { 0, };
int h, w;
int  dirH[4] = {-1,1,0,0},dirW[4] = { 0,0,-1,1 };
int ans = MAXNUM;
pair<int, int> R, B, O;

void dfs(int count) {
	if (R == O && B != O) {
		ans = min(ans, count);
		return;
	} else {
		if (B == O) return;
		if (count >= 10) return;
		count++;
		pair<int, int> pr=R, pb=B;
		for (int i = 0; i < 4; ++i) {
			bool trueR=true, trueB=true;
			while (trueR || trueB) {
				if (map[R.first][R.second] != 'O'&&(map[R.first + dirH[i]][R.second + dirW[i]] == '.' || map[R.first + dirH[i]][R.second + dirW[i]] == 'O')) {
					map[R.first][R.second] = '.';
					R.first += dirH[i]; R.second += dirW[i];
					if(map[R.first][R.second]!='O')
						map[R.first][R.second] = 'R';
				}
				else trueR = false;
				if (map[B.first][B.second] != 'O'&&(map[B.first + dirH[i]][B.second + dirW[i]] == '.' || map[B.first + dirH[i]][B.second + dirW[i]] == 'O')) {
					map[B.first][B.second] = '.';
					B.first += dirH[i]; B.second += dirW[i];
					if(map[B.first][B.second] != 'O')
						map[B.first][B.second] = 'B';
				}
				else trueB = false;
			}
			dfs(count);
			map[R.first][R.second] = '.';
			map[B.first][B.second] = '.';
			R = pr;
			B = pb;
			map[R.first][R.second] = 'R';
			map[B.first][B.second] = 'B';
			map[O.first][O.second] = 'O';
		}
	}
}
int problem(int count) {
	bool istrue = false;
	pair<int, int> pr = R, pb = B;
	while (!istrue) {
		cout << "KB_code : ";
		int KB_code;
		cin >> KB_code;
		bool trueR = true, trueB = true;
		while (trueR || trueB) {
			if (map[R.first][R.second] != 'O' && (map[R.first + dirH[KB_code]][R.second + dirW[KB_code]] == '.' || map[R.first + dirH[KB_code]][R.second + dirW[KB_code]] == 'O')) {
				map[R.first][R.second] = '.';
				R.first += dirH[KB_code]; R.second += dirW[KB_code];
				if (map[R.first][R.second] != 'O')
					map[R.first][R.second] = 'R';
			}
			else trueR = false;
			if (map[B.first][B.second] != 'O' && (map[B.first + dirH[KB_code]][B.second + dirW[KB_code]] == '.' || map[B.first + dirH[KB_code]][B.second + dirW[KB_code]] == 'O')) {
				map[B.first][B.second] = '.';
				B.first += dirH[KB_code]; B.second += dirW[KB_code];
				if (map[B.first][B.second] != 'O')
					map[B.first][B.second] = 'B';
			}
			else trueB = false;
			Sleep(1000);
			for (int i = 0; i < h; ++i) {
				for (int j = 0; j < w; ++j)
					cout<<map[i][j];
				cout << endl;
			}

		}
		count++;
		if (R == O || B==O) {
			istrue = true;
		}
		if (B == O) count = MAXNUM;
	}
	map[R.first][R.second] = '.';
	map[B.first][B.second] = '.';
	R = pr;
	B = pb;
	map[R.first][R.second] = 'R';
	map[B.first][B.second] = 'B';
	map[O.first][O.second] = 'O';
	return count;
}
int main(void) {
	scanf("%d%d", &h, &w);
	getchar();
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%c",&map[i][j]);
			
			char& temp = map[i][j];
			if (temp == 'R') {
				R.first = i; R.second = j;
			}
			else if (temp == 'B') {
				B.first = i; B.second = j;
			}
			else if (temp == 'O') {
				O.first = i; O.second = j;
			}
		}
		getchar();
	}
	dfs(0); 
	if (ans == MAXNUM) ans = -1;
	//cout << "answer : " << ans << endl;
	
	
	int ans2 = MAXNUM;
	while (true) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j)
				cout << map[i][j];
			cout << endl;
		}
		cout << "Put only the red ball into the hole with minimal movement." << endl;
		cout << "0 : KB_UP\n1 : KB_DOWN\n2 : KB_LEFT\n3 : KB_RIGHT << endl;
		ans2 = problem(0);
		if(ans2 != ans)
			if (ans2 == MAXNUM) {
				cout << "Oops!! The blue ball fell into the hole." << endl;
			}else cout << "There is a smaller answer,,"<<endl;
		else break;
	}
	cout << "Good job.\n"<< "minimal movement is " << ans <<"."<< endl;
	system("pause");
}
