#pragma once
#include <string>
#include "Objet.cpp"

using namespace std;

class Tableau : public Objet
{
public:
    Tableau(std::string nomObjet, std::string descriptionObjet, int etoiles)
    : nom(nomObjet), description(descriptionObjet), nombreEtoiles(etoiles) {}
    ~Tableau();

    void visiterTableau();

    int nombreEtoiles;

private:
    std::string description;
    std::string nom;
};
