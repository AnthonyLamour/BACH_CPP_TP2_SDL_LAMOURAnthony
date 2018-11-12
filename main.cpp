//********************************************************************************************************************************************************************************
//
// fichier : main.cpp
//
// class : main
//
//********************************************************************************************************************************************************************************
//12-11-2018 LAMOUR Anthony
//12-11-2018 LAMOUR Anthony
//********************************************************************************************************************************************************************************

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char **argv)
{
	// Notre fenêtre

	SDL_Window* fenetre(0);
	SDL_Surface* MonImage;
	SDL_Rect dest;

	// Initialisation de la SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return -1;
	}


	// Création de la fenêtre

	fenetre = SDL_CreateWindow("Test Sprite SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	MonImage = IMG_Load("./data/Akame.jpg");
	if (MonImage) {
		dest = { 640 / 2 - MonImage->w / 2,480 / 2 - MonImage->h / 2, 0, 0 };
		SDL_BlitSurface(MonImage, NULL, SDL_GetWindowSurface(fenetre), &dest);
		SDL_UpdateWindowSurface(fenetre);
		SDL_Delay(1000);
		SDL_FreeSurface(MonImage);
	}
	else {
		fprintf(stdout, "Échec de chargement du sprite (%s)\n", SDL_GetError());
	}
	

	// On quitte la SDL
	
	SDL_DestroyWindow(fenetre);
	SDL_Quit();

	return 0;
}