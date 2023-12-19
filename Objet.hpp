#pragma once
#include <string>

using namespace std;

class Objet
{
public:
    Objet();
    Objet(string nomObjet, string descriptionObjet);
    ~Objet();
    string getDescriptionObjet();
    string getNomObjet();


private:
    std::string nom;
    std::string description;
};
