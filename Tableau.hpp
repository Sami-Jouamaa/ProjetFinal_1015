#pragma once
#include <string>
#include "Objet.hpp"
#include <iostream>

using namespace std;

class Tableau : public Objet
{
public:
    Tableau(string nomObjet, string descriptionObjet, int etoiles);
    ~Tableau();

    int visiterTableau();
    int getNbreEtoiles();
    void setNbreEtoiles(int etoiles);

    string getNomTableau();
    string getDescriptionTableau();

private:
    std::string description;
    std::string nom;
    int nombreEtoiles;
};
