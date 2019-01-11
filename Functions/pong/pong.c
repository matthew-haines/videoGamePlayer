#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int vel_x;
    int vel_y;
} ballType;

typedef struct {
    int x;
    int y;
    int score;
} playerType;

typedef struct {
    int x;
    int y;
} dimension;

void drawBall(ballType * position) {
    mvprintw(position->y, position->x, "O");
    return;
}

void drawPlayer(playerType * position) {
    mvprintw(position->y, position->x, "|");
    return;
}

int check(playerType * player, ballType * ball) {
    if (ball->y <= player->y + 1 || ball->y >= player->y - 2) {
        return 1; // Player hit ball
    }
    return 0; // Player miss ball
}

int main() {
    initscr();
    curs_set(0);
    noecho();

    dimension field;
    getmaxyx(stdscr, field.x, field.y);

    playerType player1, player2;
    printw("test");
}