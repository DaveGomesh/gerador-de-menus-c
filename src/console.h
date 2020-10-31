#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

/**
 * @author: desconhecido
 * @Melhorias: David Gomesh
 * 
 * Documentação: https://github.com/DavidGomesh/console-h
*/

#include <windows.h>

typedef enum{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;

static int __BACKGROUND = BLACK;
static int __FOREGROUND = WHITE;

int gotoxy(DWORD x, DWORD y){
    COORD Coordinates;

    Coordinates.X = (x - 1);
    Coordinates.Y = (y - 1);

    return (
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            Coordinates
        )
    );
}

void textcolor(int color){
    __FOREGROUND = color;

    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        color + (__BACKGROUND << 4)
    );
}

void backgroundcolor(int color){
    __BACKGROUND = color;

    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        __FOREGROUND + (color << 4)
    );
}

#endif /* CONSOLE_H_INCLUDED */