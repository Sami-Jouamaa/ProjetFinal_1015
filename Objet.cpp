#pragma once
#include "Objet.hpp"

Objet::Objet()
{
	nom = "";
	description = "";
}

Objet::Objet(string nomObjet, string descriptionObjet)
{
	nom = nomObjet;
	description = descriptionObjet;
}

Objet::~Objet() {}

string Objet::getNomObjet()
{
	return nom;
}

string Objet::getDescriptionObjet()
{
	return description;
}
