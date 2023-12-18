#pragma once
#include <string>
#include "Objet.cpp"
#include <iostream>

using namespace std;

class Tableau : public Objet
{
public:
    Tableau(string nomObjet, string descriptionObjet, int etoiles);
    ~Tableau();

    int visiterTableau();

    int nombreEtoiles; 

private:
    std::string description;
    std::string nom;
};
