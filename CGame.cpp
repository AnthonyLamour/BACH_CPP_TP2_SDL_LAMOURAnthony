#include "CGame.h"
//********************************************************************************************************************************************************************************
//
// fichier : CGameObject.cpp
//
// class : CGameObject
//
//********************************************************************************************************************************************************************************
//15-11-2018 LAMOUR Anthony
//15-11-2018 LAMOUR Anthony
//********************************************************************************************************************************************************************************

void CGame::jouer()
{
	const char *File;

	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 700;
	const int SPRITE_HEIGHT = 256;
	const int SPRITE_WIDTH = 256;

	File = "./data/MonImage.png";

	CGameObject MonObjet;

	MonObjet.setPositionX(0.0f);
	MonObjet.setPositionY(0.0f);

	MonObjet.setSprite((char*)File);

	MonObjet.setHeight(SPRITE_HEIGHT);
	MonObjet.setWidth(SPRITE_WIDTH);

	SDL_Init(SDL_INIT_VIDEO);

	IMG_Init(IMG_INIT_PNG);

	SDL_Window * window = SDL_CreateWindow("Mouvement de sprite",

		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, MonObjet.getSprite());

	MonObjet.Mouvement(window, renderer, texture);

	SDL_DestroyTexture(texture);

	SDL_FreeSurface(MonObjet.getSprite());

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);

	IMG_Quit();

	SDL_Quit();
}
