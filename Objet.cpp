#include "Objet.hpp"

Objet::Objet(string nomObjet, string descriptionObjet)
{
	nom = nomObjet;
	description = descriptionObjet;
}

Objet::~Objet() {}

string Objet::getnom()
{
	return nom;
}

string Objet::getDescription()
{
	return description;
}
