#include "Carte.hpp"

Carte::Carte(Piece* salleDepart)
{
	vector<Piece>pieces;
	salleActuelle = salleDepart;
}

void Carte::ajouterPiece(Piece piece)
{
	pieces.push_back(piece);
}