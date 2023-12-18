#include "Tableau.hpp"

Tableau::Tableau(string nomObjet, string descriptionObjet, int etoiles)
{
    nom = nomObjet;
    description = descriptionObjet;
    nombreEtoiles = etoiles;
}

Tableau::~Tableau() {}

int Tableau::visiterTableau() {
    if (nombreEtoiles > 0) {
        nombreEtoiles -= 1;
        return nombreEtoiles;
    }
    else {
        cout << "Vous avez déjà toutes les étoiles de ce tableau";
        return 0;
    }

}
