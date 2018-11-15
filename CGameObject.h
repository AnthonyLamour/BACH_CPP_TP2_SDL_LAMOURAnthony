//********************************************************************************************************************************************************************************
//
// fichier : CGameObject.h
//
// description : Gestion d'un gameobject
//
// attributs : CVect2D CVectPosition SDL_Surface *Sprite
//
// class : CGameObject
//
//********************************************************************************************************************************************************************************
//08-11-2018 LAMOUR Anthony
//15-11-2018 LAMOUR Anthony
//********************************************************************************************************************************************************************************


#pragma once
#include "CVect2D.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <string.h>

class CGameObject {

	//donnee membre
private:
	CVect2D CVectPosition;
	SDL_Surface *Sprite;
	int nwidth;
	int nheight;
	

	//focntion membre
public:

	//mutateur et assesseur
	void setPositionX(float fltX);
	void setPositionY(float fltY);
	void setWidth(int nwidth);
	void setHeight(int nheight);
	int gettHeight();
	int getWidth();
	void setSprite(char* pszFile);
	CVect2D getPosition();
	SDL_Surface* getSprite();


	void Mouvement(SDL_Window *Fenetre, SDL_Renderer *Renderer, SDL_Texture *Texture);
};
