#pragma once
#include <string>

using namespace std;

class Objet
{
public:
    Objet();
    Objet(string nomObjet, string descriptionObjet);
    ~Objet();
    string getDescription();
    string getnom();


private:
    std::string nom;
    std::string description;
};
