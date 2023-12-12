#pragma once
#include <string>

using namespace std;

class Objet
{
public:
    Objet(std::string nomObjet, std::string descriptionObjet)
    : nom(nomObjet), description(descriptionObjet) {}
    ~Objet();
    string getDescription();
    string getnom();


private:
    std::string nom;
    std::string description;
};
