#include "Carte.hpp"

Carte::Carte(Piece& salleDepart, vector<Piece> vecteurPieces)
{
	pieces = vecteurPieces;
	salleActuelle = &salleDepart;
}

Carte::~Carte() {}

Piece* Carte::getSalleActuelle()
{
	return salleActuelle;
}

void Carte::setSalleActuelle(Piece& nouvelleSalle)
{
	salleActuelle = &nouvelleSalle;
}

void Carte::ajouterPiece(Piece& piece)
{
	pieces.push_back(piece);
}
