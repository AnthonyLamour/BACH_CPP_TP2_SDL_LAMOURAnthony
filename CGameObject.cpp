//********************************************************************************************************************************************************************************
//
// fichier : CGameObject.cpp
//
// class : CGameObject
//
//********************************************************************************************************************************************************************************
//12-11-2018 LAMOUR Anthony
//12-11-2018 LAMOUR Anthony
//********************************************************************************************************************************************************************************

#include "CGameObject.h"
#include "CVect2D.h"

CVect2D CGameObject::getPostion() const
{
	return this->CVectPosition;
}

void CGameObject::setPositionX(float fltX)
{
	this->CVectPosition.setVectX(fltX);
}

void CGameObject::setPositionY(float fltY)
{
	this->CVectPosition.setVectX(fltY);
}