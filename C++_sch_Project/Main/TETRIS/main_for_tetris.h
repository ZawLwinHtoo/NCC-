//
// Created by zl_shit_h on 08/09/23.
//

#ifndef C___SCH_PROJECT_MAIN_FOR_TETRIS_H
#define C___SCH_PROJECT_MAIN_FOR_TETRIS_H

#include "kbhit.h"
#include "ncurses.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <random>
//#include <conio.h>
using namespace std;

struct Random
{
    Random(int min, int max)
            : mUniformDistribution(min, max)
    {}

    int operator()()
    {
        return mUniformDistribution(mEngine);
    }

    std::default_random_engine mEngine{ std::random_device()() };
    std::uniform_int_distribution<int> mUniformDistribution;
};

std::vector<std::vector<int>> stage(22, std::vector<int>(13, 0));
std::vector<std::vector<int>> block =
        {
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 }
        };

std::vector<std::vector<int>> field(22, std::vector<int>(13, 0));
// coordinate
int y = 0;
int x = 4;
bool gameover = false;
size_t GAMESPEED = 50000;

Random getRandom{ 0, 6 };

std::vector<std::vector<std::vector<int>>> block_list =
        {
                {
                        { 0, 1, 0, 0 },
                        { 0, 1, 0, 0 },
                        { 0, 1, 0, 0 },
                        { 0, 1, 0, 0 }
                },
                {
                        { 0, 0, 0, 0 },
                        { 0, 1, 1, 0 },
                        { 0, 1, 0, 0 },
                        { 0, 1, 0, 0 }
                },
                {
                        { 0, 0, 1, 0 },
                        { 0, 1, 1, 0 },
                        { 0, 1, 0, 0 },
                        { 0, 0, 0, 0 }
                },
                {
                        { 0, 1, 0, 0 },
                        { 0, 1, 1, 0 },
                        { 0, 0, 1, 0 },
                        { 0, 0, 0, 0 }
                },
                {
                        { 0, 0, 0, 0 },
                        { 0, 1, 0, 0 },
                        { 1, 1, 1, 0 },
                        { 0, 0, 0, 0 }
                },
                {
                        { 0, 0, 0, 0 },
                        { 0, 1, 1, 0 },
                        { 0, 1, 1, 0 },
                        { 0, 0, 0, 0 }
                },
                {
                        { 0, 0, 0, 0 },
                        { 0, 1, 1, 0 },
                        { 0, 0, 1, 0 },
                        { 0, 0, 1, 0 }
                }
        };

int menu();
int gameOver();
void title();
void gameLoop();
void display();
bool makeBlocks();
void initGame();
void moveBlock(int, int);
void collidable();
bool isCollide(int, int);
void userInput();
bool rotateBolck();
void spwanBlock();

int Main_tetris(){

    switch (menu())
    {
        case 1:
            gameLoop();
            break;
        case 2:
            return 0;
        default :
            return 0;
    }
    return 0;

}

int gameOver()
{
    cout<< "\nGAME OVER!\n\nPress any key or enter\n";
    return 0;
}

void gameLoop()
{
    size_t time = 0;
    initGame();

    while (!gameover)
    {
        if (kbhit())
        {
            userInput();
        }

        if (time < GAMESPEED)
        {
            time++;
        }
        else
        {
            spwanBlock();
            time = 0;
        }
    }

}

int menu()
{
    title();
    int select_num;
    std::cin >> select_num;
    return select_num;
}

void title()
{
    using namespace std;

    system("cls");
    cout<< "TETRIS";
    cout << "\t<MENU>\n";
    cout << "\t1: Start Game\n\t2: Quit\n\n";
    cout << "Choose >> ";
}

void display()
{
//    system("cls")
    clear();

    for (size_t i = 0; i < 21; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            switch (field[i][j])
            {
                case 0:
                    std::cout << " " << std::flush;
                    break;
                case 9:
                    std::cout << "-" << std::flush;
                    break;
                default:
                    std::cout << "#" << std::flush;
                    break;
            }
        }
        std::cout << std::endl;
    }

    std::cout << "\nTo Left : a \nTo Down : s \nTo Right : d \nTo Rotate : space";

    if (gameover)
    {
//        system("cls");
        clear();
        refresh();
        gameOver();
    }
    refresh();
}

void initGame()
{
    for (size_t i = 0; i <= 20; i++)
    {
        for (size_t j = 0; j <= 11; j++)
        {
            if ((j == 0) || (j == 11) || (i == 20))
            {
                field[i][j] = stage[i][j] = 9;
            }
            else
            {
                field[i][j] = stage[i][j] = 0;
            }
        }
    }

    makeBlocks();

    display();
}

bool makeBlocks()
{
    x = 4;
    y = 0;

    int blockType = getRandom();

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            block[i][j] = 0;
            block[i][j] = block_list[blockType][i][j];
        }
    }

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            field[i][j + 4] = stage[i][j + 4] + block[i][j];

            if (field[i][j + 4] > 1)
            {
                gameover = true;
                return true;
            }
        }
    }
    return false;
}

void moveBlock(int x2, int y2)
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            field[y + i][x + j] -= block[i][j];
        }
    }
    x = x2;
    y = y2;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            field[y + i][x + j] += block[i][j];
        }
    }

    display();
}
void collidable()
{
    for (size_t i = 0; i<21; i++)
    {
        for (size_t j = 0; j<12; j++)
        {
            stage[i][j] = field[i][j];
        }
    }
}
bool isCollide(int x2, int y2)
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (block[i][j] && stage[y2 + i][x2 + j] != 0)
            {
                return true;
            }
        }
    }
    return false;
}

void userInput()
{
    char key;

    key = getch();

    switch (key)
    {
        case 'd':
            if (!isCollide(x + 1, y))
            {
                moveBlock(x + 1, y);
            }
            break;
        case 'D':
            if (!isCollide(x + 1, y))
            {
                moveBlock(x + 1, y);
            }
            break;
        case 'a':
            if (!isCollide(x - 1, y))
            {
                moveBlock(x - 1, y);
            }
            break;
        case 'A':
            if (!isCollide(x - 1, y))
            {
                moveBlock(x - 1, y);
            }
            break;
        case 's':
            if (!isCollide(x, y + 1))
            {
                moveBlock(x, y + 1);
            }
            break;
        case 'S':
            if (!isCollide(x, y + 1))
            {
                moveBlock(x, y + 1);
            }
            break;
        case ' ':
            rotateBolck();
    }
}

bool rotateBolck()
{
    std::vector<std::vector<int>> tmp(4, std::vector<int>(4, 0));

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            tmp[i][j] = block[i][j];
        }
    }

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            block[i][j] = tmp[3 - j][i];
        }
    }

    if (isCollide(x, y))
    {
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                block[i][j] = tmp[i][j];
            }
        }
        return true;
    }

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            field[y + i][x + j] -= tmp[i][j];
            field[y + i][x + j] += block[i][j];
        }
    }

    display();

    return false;
}

bool isRowFull(int row)
{
    for (size_t j = 1; j <= 10; j++) {
        if (field[row][j] == 0) {
            return false;
        }
    }
    return true;
}

void spwanBlock()
{
    if (!isCollide(x, y + 1))
    {
        moveBlock(x, y + 1);
    }
    else
    {
        collidable();
        if (isCollide(x, y))
        {
            for (size_t i = 0; i < 4; i++)
            {
                for (size_t j = 0; j < 4; j++)
                {
                    if (block[i][j])
                    {
                        field[y + i][x + j] = 1;
                    }
                }
            }
            int fullLines = 0;
            for (int i = 0; i < 20; i++)
            {
                if (isRowFull(i))
                {
                    fullLines++;

                    for (int k = i; k > 0; k--)
                    {
                        for (int j = 1; j <= 10; j++)
                        {
                            field[k][j] = field[k - 1][j];
                        }
                    }
                    for (int j = 1; j <= 10; j++)
                    {
                        field[0][j] = 0;
                    }
                }
            }
            for (int i = 19; i >= 0; i--)
            {
                for (int j = 1; j <= 10; j++)
                {
                    if (field[i][j] != 0 && field[i + 1][j] == 0)
                    {
                        int k = i;
                        while (k < 19 && field[k + 1][j] == 0)
                        {
                            field[k + 1][j] = field[k][j];
                            field[k][j] = 0;
                            k++;
                        }
                    }
                }
            }

            makeBlocks();
            display();
        }
    }
}

#endif //C___SCH_PROJECT_MAIN_FOR_TETRIS_H
