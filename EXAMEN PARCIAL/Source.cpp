//#include "pch.h"
#include "conio.h"
#include "iostream"

//definiendo 
#define ARRIBA 72 
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define WIDTH 70
#define HEIGHT 20
#define BARRA_ESPACIADORA 32
#define ESCAPE 27


using namespace System;

using namespace std;

int main()
{
    Console::SetWindowSize(WIDTH, HEIGHT);
    Console::Clear();
    Console::CursorVisible = false; //para que no se vea el cursor

    int x, y;
    x = 2; y = 4; //coord de donde empieza
    Console::SetCursorPosition(x, y); cout << "--->";
    while (1)
    {
        if (kbhit()) //comprubea que una tecla se presionó
        {
            //borrar
            Console::SetCursorPosition(x, y);
            cout << "     ";
            char tecla = getch();

            //mover
            if (tecla == ARRIBA && y > 0)        y--;
            if (tecla == ABAJO && y < ABAJO)      y++;
            if (tecla == DERECHA && x < WIDTH)   x++;
            if (tecla == IZQUIERDA && x > 0)      x--;

            //dibujar
            Console::SetCursorPosition(x, y); cout << "--->";

        }
    }
    _getch();
    return 0;
}