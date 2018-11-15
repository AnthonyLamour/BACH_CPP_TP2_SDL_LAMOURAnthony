//********************************************************************************************************************************************************************************
//
// fichier : CGameObject.cpp
//
// class : CGameObject
//
//********************************************************************************************************************************************************************************
//12-11-2018 LAMOUR Anthony
//15-11-2018 LAMOUR Anthony
//********************************************************************************************************************************************************************************

#include "CGameObject.h"
#include "CVect2D.h"

void CGameObject::setPositionX(float fltX)
{
	this->CVectPosition.setVectX(fltX);
}

void CGameObject::setPositionY(float fltY)
{
	this->CVectPosition.setVectX(fltY);
}

void CGameObject::setWidth(int nwidth)
{
	this->nwidth = nwidth;
}

void CGameObject::setHeight(int nheight)
{
	this->nheight = nheight;
}

int CGameObject::gettHeight()
{
	return this->nheight;
}

int CGameObject::getWidth()
{
	return this->nwidth;
}

void CGameObject::setSprite(char* pszFile)
{
	this->Sprite = IMG_Load(pszFile);
}

CVect2D CGameObject::getPosition()
{
	return this->CVectPosition;
}

SDL_Surface* CGameObject::getSprite()
{
	return this->Sprite;
}

void CGameObject::Mouvement(SDL_Window *Fenetre, SDL_Renderer *Renderer, SDL_Texture *Texture)
{
	bool quit = false;

	SDL_Event event;

	SDL_Surface * image = this->Sprite;

	while (!quit)

	{
		Uint32 ticks = SDL_GetTicks();

		Uint32 sprite = (ticks / 100) % 6;

		SDL_Rect srcrect = { sprite * this->getWidth(), 0, this->getWidth(), this->gettHeight() };

		SDL_Rect dstrect = { this->CVectPosition.getVectX(), this->CVectPosition.getVectY(), this->getWidth(), this->gettHeight() };

		CVect2D Speed;

		Speed.setVectX(0.0f);
		Speed.setVectY(0.0f);

		while (SDL_PollEvent(&event) != NULL)

		{

			switch (event.type)

			{

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
					{
					case SDLK_UP:
						Speed.setVectX(0.0f);
						Speed.setVectY(10.0f);
						this->CVectPosition=this->CVectPosition.soustractionDeVecteur(Speed);
						break;
					case SDLK_DOWN:
						Speed.setVectX(0.0f);
						Speed.setVectY(10.0f);
						this->CVectPosition = this->CVectPosition.additionDeVecteur(Speed);
						break;
					case SDLK_RIGHT:
						Speed.setVectX(10.0f);
						Speed.setVectY(0.0f);
						this->CVectPosition = this->CVectPosition.additionDeVecteur(Speed);
						break;
					case SDLK_LEFT:
						Speed.setVectX(10.0f);
						Speed.setVectY(0.0f);
						this->CVectPosition = this->CVectPosition.soustractionDeVecteur(Speed);
						break;
					}
				break;

			case SDL_QUIT:

				quit = true;

				break;

			}

		}

		SDL_RenderClear(Renderer);

		SDL_RenderCopy(Renderer, Texture, &srcrect, &dstrect);

		SDL_RenderPresent(Renderer);

	}
}

