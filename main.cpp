// main.cpp
// Este archivo contiene la ejecucion principal del programa, hace uso de la clase Game, la cual contiene todos los metodos necesarios para la generacion de la aplicacion, asi como el uso de la funcion SDL_Delay para un optimo desplazamiento de los objetos.

#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

Game* g_game = 0;

const int FPS = 60; //Cuantos frames por segundo queremos, 60 es el que utilizan los televisores
const int DELAY_TIME = 1000.0f / FPS;  //1000 ms entre los fps da el numero de milisegundos entre cada frame


int main(int argc, char* argv[])
{

	Uint32 frameStart, frameTime;

	g_game = new Game();
	
	g_game->init("Proyecto Final: Arkanoid", 100, 100, 650, 650, SDL_WINDOW_SHOWN);
	
	while(g_game->running())
	{
		
		frameStart = SDL_GetTicks(); //Numero de ms desde el inicio del programa
		
		g_game->handleEvents();
		g_game->update();
		g_game->render();

		frameTime = SDL_GetTicks() - frameStart;  //Tiempo que ha tardado en presentarse el frame
	    if(frameTime< DELAY_TIME)  //Si es menor al tiempo que debería ser
	    {
	        SDL_Delay((int)(DELAY_TIME - frameTime)); //Espera un tiempo
	    }


	}

	g_game->clean();
	
	return 0;
}