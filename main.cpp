/*----------------------------------------------------------------------*/
/*Assingment: PA9                                                       */
/*                                                                      */
/*Game: Tic Tac Toe                                                     */
/*                                                                      */
/*Programmers:                                                          */
/*Evan Keppler                                                          */
/*Nick Furuya                                                           */
/*Tyler Arlington                                                       */
/*                                                                      */
/*Notes:
    Github Repo Link: https://github.com/TylerArlington/tic-tac-toe
    Incase zip file is too large                                                                */
/*----------------------------------------------------------------------*/

#include "header.h"
#include "menu.h"

int main()
{
    menu Menu;

    RenderWindow window(VideoMode(1200, 800), "Tic Tac Toe"); //makes window
    
    Menu.MainMenu(window);

    return 0;
}
