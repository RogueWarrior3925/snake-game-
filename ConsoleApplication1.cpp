#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

int x, y;
int fruitX, fruitY;
int score;
char dir;
bool gameOver;

void moveCursorToTop()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, 0 };
    SetConsoleCursorPosition(hConsole, pos);
}

void setup()
{
    srand(time(0));

    x = WIDTH / 2;
    y = HEIGHT / 2;

    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;

    score = 0;
    dir = 'd';
    gameOver = false;
}

void draw()
{
    moveCursorToTop();

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "#";

        for (int j = 0; j < WIDTH; j++)
        {
            if (j == x && i == y)
                cout << "O";
            else if (j == fruitX && i == fruitY)
                cout << "F";
            else
                cout << " ";
        }

        cout << "#" << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";

    cout << "\nScore: " << score << endl;
    cout << "Use W A S D to move (X to quit)" << endl;
}

void input()
{
    if (_kbhit())
    {
        char key = _getch();

        if (key == 'w' || key == 'a' ||
            key == 's' || key == 'd')
        {
            dir = key;
        }

        if (key == 'x')
        {
            gameOver = true;
        }
    }
}

void logic()
{
    if (dir == 'w') y--;
    if (dir == 's') y++;
    if (dir == 'a') x--;
    if (dir == 'd') x++;

    if (x < 0 || x >= WIDTH ||
        y < 0 || y >= HEIGHT)
    {
        gameOver = true;
    }

    if (x == fruitX && y == fruitY)
    {
        score++;

        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
}

int main()
{
    setup();

    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(120);
    }

    cout << "\nGame Over!" << endl;
    cout << "Final Score: " << score << endl;

    return 0;
}