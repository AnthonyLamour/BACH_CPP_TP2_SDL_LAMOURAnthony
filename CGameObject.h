//********************************************************************************************************************************************************************************
//
// fichier : CGameObject.h
//
// description : Gestion d'un gameobject
//
// attributs : 
//
// class : CGameObject
//
//********************************************************************************************************************************************************************************
//08-11-2018 LAMOUR Anthony
//08-11-2018 LAMOUR Anthony
//********************************************************************************************************************************************************************************


#pragma once
#include "CVect2D.h"
#include <SDL.h>

class CGameObject {

	//donnee membre
private:
	CVect2D CVectPosition;

	

	//focntion membre
public:

	//mutateur et assesseur
	CVect2D getPostion()const;
	void setPositionX(float fltX);
	void setPositionY(float fltY);
};
