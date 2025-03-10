#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include "myconsole.h"
#include "mygraphics.h"
using namespace std;

void set(int arr[50])
{
	for (int i = 0; i < 50; i++)
	{
		arr[i] = 250;
	}
}

void set1(int arr[50])
{
	for (int i = 0; i < 50; i++)
	{
		arr[i] = -10;
	}
}

void set2(int arr[50])
{
	for (int i = 0; i < 50; i++)
	{
		arr[i] = false;
	}
}

void setArray(int a[50], int n)
{
	for (int i = 0; i < 50; i++)
	{
		a[i] = a[i] + n;
	}
}

int randomAliens()
{
	srand(50);
	int n = rand() % 1;
	if (n == 0)
	{
		n = 1;
	}
	return n;
}

void Position(int a1[50], int a2[50])
{
	for (int i = 0; i < 50; i++)
	{
		int pos = ((i % 7) * 70);
		a1[i] = a1[i] + pos;
		a2[i] = a2[i] + pos;
	}
}

void alliens(int x1[50], int x2[50], int y1[50], int y2[50], int flag[50], int temp)
{
	if (temp % 500 == 0)
	{
		int check = randomAliens();
		for (int i = 0; i < 50 && check >= 0; i++)
		{
			if (flag[i] == 0)
			{
				myEllipse(x1[i], y1[i], x2[i], y2[i], RGB(255, 0, 0), RGB(255, 0, 0));
				flag[i] = 1;
				check--;
			}
			if (flag[i] == 1)
			{
				myEllipse(x1[i], y1[i], x2[i], y2[i], RGB(255, 0, 0), RGB(255, 0, 0));
			}
		}
	}
	else
	{
		int check = randomAliens();
		for (int i = 0; i < 50 && check >= 0; i++)
		{
			if (flag[i] == 1)
			{
				myEllipse(x1[i], y1[i], x2[i], y2[i], RGB(255, 0, 0), RGB(255, 0, 0));
			}
		}
	}
}

void aliensMovement(int a1[50], int a2[50], int flag[50])
{
	for (int i = 0; i < 50; i++)
	{
		if (flag[i] == 1)
		{
			a1[i] = a1[i] + 60;
			a2[i] = a2[i] + 60;
		}
	}
}

void ship(int x, int y, bool flag)
{
	if (flag == false)
		myRect(x + 150, y + 126, x + 60, y + 152, RGB(0, 128, 128), RGB(0, 128, 128));
}

void shipMovement(int win_x, int win_y, int& ship_x, int& ship_y, bool flag)
{

	int ship_speed = 50;
	ship(ship_x, ship_y * 2, flag);
	int a = CheckKeyPressed();
	if (ship_x > 50 && a == LEFTKEY)
		ship_x -= 50 + ship_speed;
	else if (ship_x < 300 && a == RIGHTKEY)
		ship_x += 50 + ship_speed;
	else if (ship_y > 50 && a == UPKEY)
		ship_y -= 57 + ship_speed;
	else if (ship_y < 300 && a == DOWNKEY)
		ship_y += 57 + ship_speed;
}

void bullet(int x, int y)
{
	myRect(x + 60, y, x + 65, y + 20, RGB(255, 255, 255), RGB(255, 255, 255));
}

void bulletLimit(bool& flag, int y)
{
	if (y + 10 < 0)
		flag = true;
}

void bulletMovement(int& x, int& y, bool& flag)
{
	int a = CheckKeyPressed();
	if (a == 32) {
		x = x + 30;
	}
	flag = false;
}

void alienBulletCollision(int a_x, int a_y, bool& flag, int& score, int aliens_x1[50], int aliens_x2[50],
	int aliens_y1[50], int aliens_y2[50], int aliens_flag[50])
{
	for (int i = 0; i < 50; i++)
	{
		if ((a_x > aliens_x1[i] && a_x < aliens_x2[i]) && (a_y > aliens_y1[i] && a_y < aliens_y2[i]) && aliens_flag[i] == 1)
		{
			aliens_flag[i] = -1;
			flag = true;
			score = score + 10;
			break;
		}
	}
}


void alienGroundCollision(int y1[50], int flag[50], int win_y)
{
	int x = 10, y = 0;
	myLine(x / 2, y + 550, x + 900, y + 550, RGB(255, 255, 0));
	for (int i = 0; i < 50; i++)
	{
		if (flag[i] == 1)
		{
			if (y1[i] + 50 > win_y)
			{
				ClearScreen();
				int a, b;
				char defeat[] = "GAME OVER !";
				GetWindowDimensions(a, b);
				myDrawTextWithFont((a / 2) - 100, b / 2, 100, defeat, RGB(255, 15, 0), RGB(0, 0, 0));
				Sleep(5000);
				ClearScreen();
				exit(0);
			}
		}
	}
}

void shipAlienCollision(int aliens_x1[50], int aliens_x2[50],
	int aliens_y1[50], int aliens_y2[50], int aliens_flag[50], int a_x, int a_y, int& lives, int x = 150, int y = 30)
{
	for (int i = 0; i < 50; i++)
	{
		if ((a_x > aliens_x1[i] && a_x < aliens_x2[i]) && (a_y * 2 > aliens_y1[i] && a_y * 2 < aliens_y2[i]) && aliens_flag[i] == 1)
		{
			if (lives > 1)
			{
				aliens_flag[i] = -1;
				lives--;

				return;
				system("pause");

			}
			else
			{
				ClearScreen();
				int r, s;
				char defeat[] = "GAME OVER !";
				GetWindowDimensions(r, s);
				myDrawTextWithFont((r / 2) - 100, s / 2, 100, defeat, RGB(255, 0, 0), RGB(0, 0, 0));
				Sleep(5000);
				ClearScreen();
				exit(0);
			}
		}

	}
}

void victory(int alien_flag[50])
{
	int score = 0;
	for (int i = 0; i < 50; i++)
	{
		if (alien_flag[i] == -1)
			score++;
	}
	if (score == 70)
	{
		ClearScreen();
		int x, y;
		char win[] = "VICTORY ! !";
		GetWindowDimensions(x, y);
		myDrawTextWithFont(x / 2 - 80, y / 2 - 100, 100, win, RGB(0, 255, 0), RGB(0, 0, 0));
		Sleep(5000);
		ClearScreen();
		exit(0);
	}
}

void printScore(int score)
{
	PlaceCursor(0, 0);
	char score_char[3 + sizeof(char)];
	sprintf_s(score_char, "%d", score);
	cout << "Score: " << score_char;

}

void printLives(int lives)
{
	PlaceCursor(0, 1);
	char lives_char[3 + sizeof(char)];
	sprintf_s(lives_char, "%d", lives);
	cout << "Lives: " << lives_char;
}

void highScore(int score[5])
{
	char high[] = "High Scores ";
	myDrawTextWithFont(200, 0, 50, high, RGB(192, 192, 192), RGB(0, 0, 0));
	for (int i = 4; i >= 0; i--)
	{
		char score_char[3 + sizeof(char)];
		sprintf_s(score_char, "%d", score[i]);
		myDrawTextWithFont(70, 100 + (i * 100), 50, score_char, RGB(255, 251, 240), RGB(0, 0, 0));
	}
	Sleep(5000);

}

void saveGame(int lives, int score[5], bool bullet_flag, int bullet_x,
	int bullet_y, int ship_x, int ship_y, int aliens_x1[50], int aliens_x2[50],
	int aliens_y1[50], int aliens_y2[50], int aliens_flag[50])
{
	ofstream myfile;
	myfile.open("game.txt");
	myfile << lives << endl;
	for (int i = 0; i < 5; i++)
	{
		myfile << score[i] << " ";
	}
	for (int i = 0; i < 50; i++)
	{
		myfile << aliens_flag[i] << " ";
	}
	for (int i = 0; i < 50; i++)
	{
		myfile << aliens_x1[i] << " ";
	}
	for (int i = 0; i < 50; i++)
	{
		myfile << aliens_x2[i] << " ";
	}
	for (int i = 0; i < 50; i++)
	{
		myfile << aliens_y1[i] << " ";
	}
	for (int i = 0; i < 50; i++)
	{
		myfile << aliens_y2[i] << " ";
	}
	myfile << bullet_flag << endl;
	myfile << bullet_x << endl;
	myfile << bullet_y << endl;
	myfile << ship_x << endl;
	myfile << ship_y << endl;
	myfile.close();
}

void continueGame(int& lives, int score[5], bool& bullet_flag, int& bullet_x,
	int& bullet_y, int& ship_x, int& ship_y, int alien_x1[50], int alien_x2[50], int alien_y1[50], int alien_y2[50], int alien_flag[50])
{
	ifstream myfile;
	myfile.open("game.txt");
	myfile >> lives;
	for (int i = 0; i < 5; i++)
	{
		myfile >> score[i];
	}
	for (int i = 0; i < 50; i++)
	{
		myfile >> alien_flag[i];
	}
	for (int i = 0; i < 50; i++)
	{
		myfile >> alien_x1[i];
	}
	for (int i = 0; i < 50; i++)
	{
		myfile >> alien_x2[i];
	}
	for (int i = 0; i < 50; i++)
	{
		myfile >> alien_y1[i];
	}
	for (int i = 0; i < 50; i++)
	{
		myfile >> alien_y2[i];
	}
	myfile >> bullet_flag;
	myfile >> bullet_x;
	myfile >> bullet_y;
	myfile >> ship_x;
	myfile >> ship_y;
	myfile.close();
}

void pause(int lives, int score[5], bool bullet_flag, int bullet_x, int bullet_y, int ship_x, int ship_y, int aliens_x1[50], int aliens_x2[50],
	int aliens_y1[50], int aliens_y2[50], int aliens_flag[50])
{
	char key = CheckKeyPressed();
	if (key == 'P')
	{
		key = 'P';
		while (1)
		{
			ClearScreen();
			char paused[] = "Game Paused";
			myDrawTextWithFont(500, 100, 100, paused, RGB(0, 255, 0), RGB(0, 0, 0));
			char toSave[] = "Press S to Save.";
			myDrawTextWithFont(550, 220, 60, toSave, RGB(0, 255, 255), RGB(0, 0, 0));
			char Hscore[] = "Press H to Show High Scores.";
			myDrawTextWithFont(470, 300, 50, Hscore, RGB(0, 255, 255), RGB(0, 0, 0));
			char toExit[] = "Press ESCKEY to Exit";
			myDrawTextWithFont(530, 400, 50, toExit, RGB(0, 255, 255), RGB(0, 0, 0));
			key = CheckKeyPressed();
			if (key == 'P')
			{
				break;
			}
			else if (key == 'S')
			{
				saveGame(lives, score, bullet_flag, bullet_x, bullet_y, ship_x, ship_y, aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			}
			else if (key == 'H')
			{
				ClearScreen();
				highScore(score);
			}
			else if (key == ESCKEY)
			{
				ClearScreen();
				exit(0);
			}
		}
	}
}

void Game(int win_x, int win_y, int& ship_x, int& ship_y, bool bullet_flag,
	int bullet_x, int bullet_y, int score[5], int& lives, int aliens_x1[50], int aliens_x2[50],
	int aliens_y1[50], int aliens_y2[50], int aliens_flag[50])
{

	while (1)
	{
		bullet_x = ship_x;
		bullet_y = ship_y * 2;
		bulletMovement(bullet_x, bullet_y, bullet_flag);
		int count = 499;
		while (bullet_flag != true)
		{
			ClearScreen();
			count++;
			shipMovement(win_x, win_y, ship_x, ship_y, bullet_flag);
			shipAlienCollision(aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag, ship_x, ship_y, lives);
			alliens(aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag, count);
			if (count % 500 == 0)
			{
				aliensMovement(aliens_y1, aliens_y2, aliens_flag);
			}
			alienBulletCollision(bullet_x, bullet_y, bullet_flag, score[0], aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			pause(lives, score, bullet_flag, bullet_x, bullet_y, ship_x, ship_y, aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			alienGroundCollision(aliens_y1, aliens_flag, win_y);
			printScore(score[0]);
			printLives(lives);
			bullet_y = bullet_y - 50;
			pause(lives, score, bullet_flag, bullet_x, bullet_y, ship_x, ship_y, aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			bullet(bullet_x, bullet_y);
			pause(lives, score, bullet_flag, bullet_x, bullet_y, ship_x, ship_y, aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			alienBulletCollision(bullet_x, bullet_y, bullet_flag, score[0], aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			pause(lives, score, bullet_flag, bullet_x, bullet_y, ship_x, ship_y, aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			bulletLimit(bullet_flag, bullet_y);
			pause(lives, score, bullet_flag, bullet_x, bullet_y, ship_x, ship_y, aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			victory(aliens_flag);
			pause(lives, score, bullet_flag, bullet_x, bullet_y, ship_x, ship_y, aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
			alienBulletCollision(bullet_x, bullet_y, bullet_flag, score[0], aliens_x1, aliens_x2, aliens_y1, aliens_y2, aliens_flag);
		}
		Sleep(1000);
	}
}


int main()
{
	char space[] = "Space Invader";
	int win_x, win_y;
	SetWindowTitle(space);
	GetWindowDimensions(win_x, win_y);
	PlaceCursor(20, 0);
	int ship_x = (win_x / 2) - 50;
	int ship_y = (win_y / 2) - 50;
	bool bullet_flag = false;
	int bullet_x = ship_x;
	int bullet_y = ship_y * 2;
	int score[5] = { 0, 1, 2, 3, 4 };
	int lives = 3;
	int alien_x1[50];
	int alien_x2[50];
	int alien_y1[50];
	int alien_y2[50];
	int alien_flag[50];
	set(alien_x1);
	set(alien_x2);
	setArray(alien_x2, 50);
	set1(alien_y1);
	set1(alien_y2);
	setArray(alien_y2, 50);
	set2(alien_flag);
	Position(alien_x1, alien_x2);
	while (1)
	{
		ClearScreen();
		char invader[] = "SPACE INVADERS";
		myDrawTextWithFont(350, 200, 100, invader, RGB(255, 255, 0), RGB(0, 0, 0));
		char start[] = "Press G to Start.";
		myDrawTextWithFont(420, 350, 60, start, RGB(0, 0, 255), RGB(0, 0, 0));
		char load[] = "Press C to Continue.";
		myDrawTextWithFont(400, 450, 60, load, RGB(0, 0, 255), RGB(0, 0, 0));

		char key = CheckKeyPressed();
		if (key == 'G')
		{
			Game(win_x, win_y, ship_x, ship_y, bullet_flag, bullet_x, bullet_y, score, lives, alien_x1, alien_x2, alien_y1, alien_y2, alien_flag);
		}
		else if (key == 'C')
		{
			continueGame(lives, score, bullet_flag, bullet_x, bullet_y, ship_x, ship_y, alien_x1, alien_x2, alien_y1, alien_y2, alien_flag);
			Game(win_x, win_y, ship_x, ship_y, bullet_flag, bullet_x, bullet_y, score, lives, alien_x1, alien_x2, alien_y1, alien_y2, alien_flag);
			break;
		}
		else
		{
			continue;
		}
	}
	Sleep(100000);
	return 0;
}