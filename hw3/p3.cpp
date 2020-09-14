#include <fstream>
#include <sstream>
#include <string>
#include "Stack.h"

struct offsets {
	int a, b;
};
enum directions { N, NE, E, SE, S, SW, W, NW };

int main() {
	int row = 0;  //紀錄讀的檔總共有多少row和col
	int col = 0;
	stringstream sst;
	string str;
	fstream file("p3.in", ios::in);  //確認地圖大小，先進行一次開檔關檔
	while (getline(file, str)) {  //計算總共有幾個row
		row++;
	}
	file.close();
	sst << str;  //使用sst的功能計算一行有幾個column
	char text;  //暫存sst讀出的字元
	while (sst >> text) {
		col++;
	}
	row += 2;
	col += 2;
	sst.clear();
	//確認地圖大小，動態宣告二維矩陣為(m+2)*(n+2)
	char **myMaze = new char*[row];
	for (int i = 0; i < row; i++) {
		myMaze[i] = new char[col];
	}

	//重新開檔，將地圖資料存入地圖中
	file.open("p3.in", ios::in);
	int r = 1;
	while (getline(file, str)) {
		sst << str;
		for (int c = 1; c < col; c++) {
			sst >> myMaze[r][c];
		}
		r++;
		sst.clear();
	}
	file.close();
	//設置周圍為'b'的圍牆
	for (int i = 0; i < row; i++) {
		if (i == 0 || i == (row - 1)) {
			for (int j = 0; j < col; j++)
				myMaze[i][j] = 'b';
		}
		else {
			myMaze[i][0] = 'b';
			myMaze[i][col - 1] = 'b';
		}
	}
	row -= 2; //將row與col改為原大小
	col -= 2;


	offsets moveOffets[8];
	moveOffets[N].a = -1;
	moveOffets[N].b = 0;
	moveOffets[NE].a = -1;
	moveOffets[NE].b = 1;
	moveOffets[E].a = 0;
	moveOffets[E].b = 1;
	moveOffets[SE].a = 1;
	moveOffets[SE].b = 1;
	moveOffets[S].a = 1;
	moveOffets[S].b = 0;
	moveOffets[SW].a = 1;
	moveOffets[SW].b = -1;
	moveOffets[W].a = 0;
	moveOffets[W].b = -1;
	moveOffets[NW].a = -1;
	moveOffets[NW].a = -1;
	int count = 0;  //紀錄總步數
	offsets ratOffset;  //設置老鼠的位置
	Items *topStack;  //存取stack最上層的位置
	Items *newStack=new Items;  //存取新的stack成員
	int direction = 0;  //儲存從何方向開始找
	bool findThePath = false;
	bool noFind = false;  //作為找不到路徑的標示
	ratOffset.a = 1;
	ratOffset.b = 1;
	Stack pathStack(row*col);
	while (true) {  //尋找路徑
		if (myMaze[ratOffset.a][ratOffset.b]=='e') {  //找到終點，離開
			count++;
			findThePath = true;
			break;
		}
		if (noFind)  //沒找到路，也離開
			break;

		for (int i = direction; i < 8; i++) {  //老鼠在該位置依照directions的順序從N到NW找可以走的路
			//該點找不到可走的路
			if (i == 7 && myMaze[ratOffset.a][ratOffset.b] != '0') {
				if (!pathStack.isEmpty()) {
					count--;
					myMaze[ratOffset.a][ratOffset.b] = '0';
					topStack = pathStack.getTop();
					ratOffset.a = topStack->y;
					ratOffset.b = topStack->x;
					direction = topStack->dir + 1;
					pathStack.pop();
				}
				else
					noFind = true;
				break;
			}

			if (myMaze[ratOffset.a + moveOffets[i].a][ratOffset.b + moveOffets[i].b] == '0' 
 				|| myMaze[ratOffset.a + moveOffets[i].a][ratOffset.b + moveOffets[i].b]== 'e') {  //如果找到可以走的路或出口
				//新增成員到stack中
				newStack->y = ratOffset.a;
				newStack->x = ratOffset.b;
				newStack->dir = i;
				pathStack.push(newStack);

				//重新繪製myMaze
				ratOffset.a += moveOffets[i].a;
				ratOffset.b += moveOffets[i].b;
				if (myMaze[ratOffset.a][ratOffset.b] == 'e')
					break;
				else {
					if (i == 0 || i == 4)
						myMaze[ratOffset.a][ratOffset.b] = '|';
					else if (i == 1 || i == 5)
						myMaze[ratOffset.a][ratOffset.b] = '/';
					else if (i == 2 || i == 6)
						myMaze[ratOffset.a][ratOffset.b] = '-';
					else
						myMaze[ratOffset.a][ratOffset.b] = '\\';
				count++;
				}
				direction = 0;  //到達新位置，重設direction
				break;
			}
		}
	}
	if (findThePath) {
		for (int i = 1; i <= row ; i++) {
			for (int j = 1; j <= col ; j++) {
				cout << myMaze[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << "共需" << count << "步" << endl;
		cout<< "橫向: -" << endl << "縱向: |" << endl << "斜向: / or \\" << endl;
	}
	else
		cout << "No path in maze." << endl;
	return 0;
}