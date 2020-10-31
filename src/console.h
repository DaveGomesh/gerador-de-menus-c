#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

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
static int __FOREGROUND = RED;

int gotoxy(DWORD x, DWORD y){
    COORD Coordenadas;

    Coordenadas.X = (x - 1);
    Coordenadas.Y = (y - 1);

    return (
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            Coordenadas
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

void backgroudcolor(int color){
    __BACKGROUND = color;

    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        __FOREGROUND + (color << 4)
    );
}

#endif /* CONSOLE_H_INCLUDED */