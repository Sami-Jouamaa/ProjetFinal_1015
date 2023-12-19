#pragma once
#include "Mario.hpp"

Mario::Mario(bool aYoshi, int etoilesPossedees)
{
	vector<Objet>objets;
	avoirYoshi = aYoshi;
	nombreEtoiles = etoilesPossedees;
}

void Mario::gagnerEtoile() {
	nombreEtoiles++;
}

Mario::~Mario() {}

int Mario::getNbreEtoilesMario()
{
	return nombreEtoiles;
}

void Mario::setNbreEtoilesMario(int etoiles)
{
	nombreEtoiles = etoiles;
}

void Mario::ajouterObjet(Objet objet)
{
	objets.push_back(objet);
}

void Mario::wahoo()
{
	cout << "Wahoo !" << endl;
}
