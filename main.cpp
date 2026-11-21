#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int w = 20;
const int l = 20;
vector<pair<int, int>> snake;
int foodX, foodY;
int score = 0;
char dir = 'D';
bool gameover = false;
void generateFood() {
    bool onsnake;
    do {
        onsnake = false;
        foodX = 1 + rand() % (l-2);
        foodY = 1 + rand() % (w-2);
        for (int i = 0; i < snake.size(); i++) {
            if (foodX == snake[i].first && foodY == snake[i].second) {
                onsnake = true;
                break;
            }
        }
    } while (onsnake);
}

void setup() {
    snake.push_back({10,11});
    snake.push_back({10,10});
    snake.push_back({10,9});
    srand(time(0));
    generateFood();
}

void draw() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == l-1 || j == 0 || j == w-1) {
                cout << "#";
            }
            else if (i == snake[0].first && j == snake[0].second) {
                cout << "O";
            }
            else {
                bool body = false;
                for (int k = 1; k < snake.size(); k++) {
                    if (i == snake[k].first && j == snake[k].second) {
                        cout << "o";
                        body = true;
                        break;
                    }
                }
                if (!body) {
                    if (i == foodX && j == foodY) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
}

void input() {
    if (_kbhit()) {
        switch(_getch()) {
            case 'a':
            case 'A':
                if (dir != 'D') {
                    dir = 'A';
                }
                break;
            

            case 'd':
            case 'D':
                if (dir != 'A') {
                    dir = 'D';
                }
                break;
                
            case 'w':
            case 'W':
                if (dir != 'S') {
                    dir = 'W';
                }
                break;

            case 's':
            case 'S':
                if (dir != 'W') {
                    dir = 'S';
                }
                break;

        }
    }
}

void logic() {
    pair<int, int> head = snake[0];

    if (dir == 'D') {
        head.second++;
    }
    else if (dir == 'A') {
        head.second--;
    }
    else if (dir == 'W') {
        head.first--;
    }
    else if (dir == 'S') {
        head.first++;
    }

    if (head.first == 0 || head.first == l-1 || head.second == 0 || head.second == w-1) {
        gameover = true;
        return;
    }

    for (int i = 0; i < snake.size(); i++) {
        if (head == snake[i]) {
            gameover = true;
            return;
        }
    }

    bool ate;
    if (head.first == foodX && head.second == foodY) {
        ate = true;
    }
    else {
        ate = false;
    }

    snake.insert(snake.begin(), head);
    if (ate) {
        score++;
        generateFood();
    }
    else {
        snake.pop_back();
    }
}
int main() {
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
        Sleep(600);
    }
    system("cls");
    cout << "GAME OVER"<< endl;
    cout << "FINAL SCORE IS: " << score << endl;
    return 0;
}