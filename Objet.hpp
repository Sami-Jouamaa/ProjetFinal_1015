#pragma once
#include <string>

using namespace std;

class Objet
{
public:
    Objet(string nomObjet, string descriptionObjet);
    string getDescription();
    string getnom();


private:
    std::string nom;
    std::string description;
};