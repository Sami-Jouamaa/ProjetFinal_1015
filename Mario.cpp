#include "Mario.hpp"

Mario::Mario()
{
	vector<Objet>objets;
	avoirYoshi = false;
	nombreEtoiles = 0;
}

void Mario::wahoo()
{
	cout << "Wahoo !" << endl;
}