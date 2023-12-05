#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Objet.hpp"

class Mario 
{

public:
    Mario();

    void wahoo();

private:
    vector<Objet> objets;
    bool avoirYoshi;
    int nombreEtoiles;
};