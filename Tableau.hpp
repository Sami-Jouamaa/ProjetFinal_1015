#pragma once
#include <string>
#include "Objet.hpp"
#include <iostream>

using namespace std;

class Tableau : public Objet
{
public:
    Tableau(string nomObjet, string descriptionObjet, int etoiles, bool yoshi);
    ~Tableau();

    int visiterTableau();
    int getNbreEtoiles();
    void setNbreEtoiles(int etoiles);

    string getNomTableau();
    string getDescriptionTableau();
    bool getNecessiteYoshi();

private:
    std::string description;
    std::string nom;
    int nombreEtoiles;
    bool necessiteYoshi;
};
