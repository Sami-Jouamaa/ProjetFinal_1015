#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Objet.hpp"

class Mario
{

public:
    Mario(bool aYoshi, int etoilesPossedees);
    ~Mario();

    void wahoo();

    void ajouterObjet(Objet objet);
    void gagnerEtoile();
    int getNbreEtoilesMario();
    void setNbreEtoilesMario(int etoiles);

private:
    vector<Objet> objets;
    bool avoirYoshi;
    int nombreEtoiles;
};
