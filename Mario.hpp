#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Objet.hpp"

class Mario 
{

public:
    Mario();
    ~Mario();

    void wahoo();

    void gagnerEtoile();

private:
    vector<Objet> objets;
    bool avoirYoshi;
    int nombreEtoiles;
};
