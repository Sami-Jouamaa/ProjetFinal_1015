#include "Mario.hpp"

Mario::Mario()
{
	vector<Objet>objets;
	avoirYoshi = false;
	nombreEtoiles = 0;
}

void Mario::gagnerEtoile() {
	nombreEtoiles++;
}

Mario::~Mario() {}

void Mario::wahoo()
{
	cout << "Wahoo !" << endl;
}
