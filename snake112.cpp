#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <fstream>
using namespace std;

bool gameOver;
const int width = 40;
const int height = 15;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;


enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;


class area{
private:
	
public:
	void setup()
	{
		gameOver = false;
		dir = STOP;
		x = width / 2;
		y = height / 2;
		fruitX = rand() % width + 1;
		fruitY = rand() % height;
		score = 0;
	}
};
class snake{
public:

	void draw()
	{

		system("cls");
		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0)
					cout << "#";
				if (i == y && j == x)
					cout << "@";
				else if (i == fruitY && j == fruitX)
					cout << "F";
				else
				{
					bool print = false;
					for (int k = 0; k < nTail; k++)
					{
						if (tailX[k] == j && tailY[k] == i)
						{
							cout << "o";
							print = true;
						}
					}
					if (!print)
						cout << " ";
				}


				if (j == width - 1)
					cout << "#";
			}
			cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;
		cout << "Score:" << score << endl;
	}
};
class management :area {
public:

	void input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;


			}
		}
	}
	void logic()
	{
		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;
		tailX[0] = x;
		tailY[0] = y;
		for (int i = 1; i < nTail; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
		switch (dir)
		{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
			//default:
				//break;
		}


	}
};
class borders {
public:
		void death() {

			if (x >= width || x < 0 || y >= height || y < 0) {
				gameOver = true;
				cout << endl << "                        GAME OVER" << endl;

			}
			if (x >= width) x = 0;
			else if (x < 0) x = width - 1;

			if (y >= height) y = 0;
			else if (y < 0) y = height - 1;

			for (int i = 0; i < nTail; i++)
				if (tailX[i] == x && tailY[i] == y)
					gameOver = true;

			
		
	    }
		void scor() {
			if (x == fruitX && y == fruitY)
			{
				score += 10;
				fruitX = rand() % width;
				fruitY = rand() % height;
				nTail++;
			}
		}
};

int main()
{
	
	srand(time(0));

	int t, u, z, g,o;

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                                SNAKE " << endl << endl << "                                             START GAME" << endl << endl << "                                              OPTIONS" << endl << endl << "                                               EXIT" << endl;
	cin >> t;
	switch (t)
	{
	case 1://start
	
		area a ;
		snake f;
		management e;
		borders r;
		a.setup();
		
			
			while (!gameOver)
			{
				f.draw();
				
				
				e.input();
				e.logic();
				r.death();
				r.scor();
				Sleep(30);

			}


		
			 
			break;

	case 2://option

		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                        OPTIONS" << endl << endl;
		cout << "                                   Snake game management" << endl << endl << "                            a - left       d - right       w - up       s - down" << endl << endl << "                         RULES OF THE GAME" << endl << endl << "snake game" << endl << "1.Has only one level in the level forbidden to hit the wall of the card or hit the tail of the snake it will end the game" << endl << "2. The snake must eat fruit to increase its size." << endl << "3.fruits are marked on the map 'F'." << endl << endl << endl << "                            GOOD LUCK IN THE GAME" << endl << endl;
		cout << "START GAME " << endl << "BACK TO MANU" << endl << endl << endl << endl << endl << endl << endl;
		cin >> u;
		switch (u) {
		case 1:// start in option
			area a;
			snake f;
			management e;
			borders r;
			a.setup();


			while (!gameOver)
			{
				f.draw();


				e.input();
				e.logic();
				r.death();
				r.scor();
				Sleep(30);

			}
			break;
		case 2://back in  manu
			cout << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                                SNAKE " << endl << endl << "                                             START GAME" << endl << endl << "                                              OPTIONS" << endl << endl << "                                               EXIT" << endl << endl << endl << endl << endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cin >> z;
			switch (z) {
			case 1://start after come back

				area a;
				snake f;
				management e;
				borders r;
				a.setup();


				while (!gameOver)
				{
					f.draw();


					e.input();
					e.logic();
					r.death();
					r.scor();
					Sleep(30);

				}
				break;
			case 2://option after come back

				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                        OPTIONS" << endl << endl;
				cout << "                                   Snake game management" << endl << endl << "                            a - left       d - right       w - up       s - down" << endl << endl << "                         RULES OF THE GAME" << endl << endl << "snake game" << endl << "1.Has only one level in the level forbidden to hit the wall of the card or hit the tail of the snake it will end the game" << endl << "2. The snake must eat fruit to increase its size." << endl << "3.fruits are marked on the map 'F'." << endl << endl << endl << "                            GOOD LUCK IN THE GAME" << endl << endl;
				cout << "START GAME " << endl << "the end" << endl << endl << endl << endl << endl << endl << endl;
				cin >> g;
				switch (g) {
				case 1://start game
					area a;
					snake f;
					management e;
					borders r;
					a.setup();


					while (!gameOver)
					{
						f.draw();


						e.input();
						e.logic();
						r.death();
						r.scor();
						Sleep(30);

					}
					break;
				}
				break;
			case 3://exit
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                                       GAME OVER" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				break;

			}
			break;


		}
	case 3://exit
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                                                       GAME OVER" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		break;
	}
	return 0;
}