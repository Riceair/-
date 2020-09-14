#include <fstream>
#include <sstream>
#include <string>
#include "Stack.h"

struct offsets {
	int a, b;
};
enum directions { N, NE, E, SE, S, SW, W, NW };

int main() {
	int row = 0;  //����Ū�����`�@���h��row�Mcol
	int col = 0;
	stringstream sst;
	string str;
	fstream file("p3.in", ios::in);  //�T�{�a�Ϥj�p�A���i��@���}������
	while (getline(file, str)) {  //�p���`�@���X��row
		row++;
	}
	file.close();
	sst << str;  //�ϥ�sst���\��p��@�榳�X��column
	char text;  //�ȦssstŪ�X���r��
	while (sst >> text) {
		col++;
	}
	row += 2;
	col += 2;
	sst.clear();
	//�T�{�a�Ϥj�p�A�ʺA�ŧi�G���x�}��(m+2)*(n+2)
	char **myMaze = new char*[row];
	for (int i = 0; i < row; i++) {
		myMaze[i] = new char[col];
	}

	//���s�}�ɡA�N�a�ϸ�Ʀs�J�a�Ϥ�
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
	//�]�m�P��'b'������
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
	row -= 2; //�Nrow�Pcol�אּ��j�p
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
	int count = 0;  //�����`�B��
	offsets ratOffset;  //�]�m�ѹ�����m
	Items *topStack;  //�s��stack�̤W�h����m
	Items *newStack=new Items;  //�s���s��stack����
	int direction = 0;  //�x�s�q���V�}�l��
	bool findThePath = false;
	bool noFind = false;  //�@���䤣����|���Х�
	ratOffset.a = 1;
	ratOffset.b = 1;
	Stack pathStack(row*col);
	while (true) {  //�M����|
		if (myMaze[ratOffset.a][ratOffset.b]=='e') {  //�����I�A���}
			count++;
			findThePath = true;
			break;
		}
		if (noFind)  //�S�����A�]���}
			break;

		for (int i = direction; i < 8; i++) {  //�ѹ��b�Ӧ�m�̷�directions�����ǱqN��NW��i�H������
			//���I�䤣��i������
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
 				|| myMaze[ratOffset.a + moveOffets[i].a][ratOffset.b + moveOffets[i].b]== 'e') {  //�p�G���i�H�������ΥX�f
				//�s�W������stack��
				newStack->y = ratOffset.a;
				newStack->x = ratOffset.b;
				newStack->dir = i;
				pathStack.push(newStack);

				//���sø�smyMaze
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
				direction = 0;  //��F�s��m�A���]direction
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
		cout << endl << "�@��" << count << "�B" << endl;
		cout<< "��V: -" << endl << "�a�V: |" << endl << "�צV: / or \\" << endl;
	}
	else
		cout << "No path in maze." << endl;
	return 0;
}