#include<iostream>
using namespace std;

char matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'X'; int n;

//Draw 3x3 grid
void draw()
{
	system("cls");
	cout << "TIC TAC TOE (X:O)!!" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<< matrix[i][j] << " " ;
		}
		cout << endl;
	}
}

//Specify the position of X or O
void input()
{
	int a;
	cout <<"Its "<< player <<" turn "
		<< "Press the number you want:";
	cin >> a;

	if (a == 1)
		matrix[0][0] = player;
	if (a == 2)
		matrix[0][1] = player;
	if (a == 3)
		matrix[0][2] = player;
	if (a == 4)
    matrix[1][0] = player;
	if (a == 5)
		matrix[1][1] = player;
	if (a == 6)
		matrix[1][2] = player;
	if (a == 7)
		matrix[2][0] = player;
	if (a == 8)
		matrix[2][1] = player;
	if (a == 9)
		matrix[2][2] = player;
}

//Change player's turn
void change()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

//Winning conditions
char win()
{
	// Player 1
	for (int i = 0; i < 3; i++)
	{
		int j = 0;
		if ((matrix[i][j] == 'X' && matrix[i][j + 1] == 'X' && matrix[i][j + 2] == 'X') || (matrix[j][i] == 'X'&&matrix[j + 1][i] == 'X'&&matrix[j + 2][i] == 'X'))
			return 'X';
		else if (matrix[0][0] == 'X'&&matrix[1][1] == 'X'&&matrix[2][2] == 'X')
			return 'X';
		else if (matrix[0][2] == 'X'&&matrix[1][1] == 'X'&&matrix[2][0] == 'X')
			return 'X';
	}
	// PLayer 2
	for (int i = 0; i < 3; i++)
	{
		int j = 0;
		if ((matrix[i][j] == 'O' && matrix[i][j + 1] == '0' && matrix[i][j + 2] == 'O') || (matrix[j][i] == 'O'&&matrix[j + 1][i] == 'O'&&matrix[j + 2][i] == 'O'))
			return 'O';
		else if (matrix[0][0] == '0'&&matrix[1][1] == 'O'&&matrix[2][2] == 'O')
			return 'O';
		else if (matrix[0][2] == 'O'&&matrix[1][1] == 'O'&&matrix[2][0] == 'O')
			return 'O';
	}
	return '/';
}

int main()
{
	n = 0;
	draw();
	while (1)
	{
		n++;
		input();
		draw();
		if (win() == 'X')
		{
			cout << "Player X wins!!";
			break;
		}
		else if (win() == 'O')
		{
			cout << "Player O wins!!";
			break;
		}
		else if (win() == '/'&& n == 9)
		{
			cout << "Match Draw!!" << endl;
			break;
		}
		change();
	}
	system("pause");
	return 0;
}
