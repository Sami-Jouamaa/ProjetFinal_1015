#pragma once
#include <vector>
#include "Piece.hpp"

class Carte
{
public:
    Carte(Piece* salleDepart);
    void ajouterPiece(Piece piece);


private:
    vector<Piece> pieces;
    Piece* salleActuelle;
};