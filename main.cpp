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
void generateFood() {
    bool onsnake;
    do {
        onsnake = false;
        foodX = rand()%l;
        foodY = rand()%w;
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
    char dir = 'D';
    generateFood();
}

int main() {
    setup();

}