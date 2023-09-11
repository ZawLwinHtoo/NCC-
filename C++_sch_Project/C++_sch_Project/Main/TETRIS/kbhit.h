//
// Created by zl_shit_h on 08/09/23.
//

#ifndef C___SCH_PROJECT_KBHIT_H
#define C___SCH_PROJECT_KBHIT_H

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);

    // Set terminal to non-blocking mode
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
#endif //C___SCH_PROJECT_KBHIT_H
