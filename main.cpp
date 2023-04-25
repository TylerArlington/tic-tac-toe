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
/*Notes:                                                                */
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
