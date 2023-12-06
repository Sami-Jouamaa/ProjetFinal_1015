#pragma once
#include <vector>
#include "Piece.hpp"

class Carte
{
public:
    Carte(Piece& salleDepart, vector<Piece> vecteurPieces);
    ~Carte();
    void ajouterPiece(Piece& piece);

    Piece* getSalleActuelle();
    void setSalleActuelle(Piece& salle);

private:
    vector<Piece> pieces;
    Piece* salleActuelle;
};
