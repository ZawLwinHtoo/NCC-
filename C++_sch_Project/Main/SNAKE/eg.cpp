#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);

    // Set the refresh rate to control the speed of the snake movement
    int refreshRate = 100000; // 100000 microseconds (0.1 second per move)

    // Board dimensions
    int boardHeight = 20;
    int boardWidth = 40;

    // Initial position and direction of the snake
    int snakeX = boardWidth / 2;
    int snakeY = boardHeight / 2;
    int directionX = 1;
    int directionY = 0;

    // Animation loop
    char ch;
    while ((ch = getch()) != 'q') {
        // Check for user input
        if (ch == 'w') { // 'w' key for up
            directionX = 0;
            directionY = -1;
        } else if (ch == 's') { // 's' key for down
            directionX = 0;
            directionY = 1;
        } else if (ch == 'a') { // 'a' key for left
            directionX = -1;
            directionY = 0;
        } else if (ch == 'd') { // 'd' key for right
            directionX = 1;
            directionY = 0;
        }

        // Move the snake
        snakeX += directionX;
        snakeY += directionY;

        // Clear the screen
        clear();

        // Draw the snake on the board
        mvprintw(snakeY, snakeX, "o");

        // Refresh the screen
        refresh();

        // Sleep for a short time to control the snake's movement speed
        usleep(refreshRate);
    }

    // Cleanup
    endwin();

    return 0;
}
