#include "Piece.hpp"

Piece::Piece(std::string nomPiece, std::string descriptionPiece, int nombreEtoiles = 0)
        : nom(nomPiece), description(descriptionPiece), nombreEtoiles(nombreEtoiles),
          nord(nullptr), sud(nullptr), ouest(nullptr), est(nullptr), objets() {}

Piece::~Piece() {}

string Piece::getNom()
{
	return nom;
}

string Piece::getDescription()
{
	return description;
}

Piece* Piece::getNord()
{
	return nord;
}

Piece* Piece::getSud()
{
	return sud;
}

Piece* Piece::getEst()
{
	return est;
}

Piece* Piece::getOuest()
{
	return ouest;
}

void Piece::ajouterObjet(Objet objet)
{
    objets.push_back(objet);
}

void Piece::connecterPieces(Piece& pieceConnectee, string orientation)
{
    if (orientation == "Nord" || orientation == "nord") {
        nord = &pieceConnectee;
        pieceConnectee.setSud(this);
    }
    else if (orientation == "Sud" || orientation == "sud") {
        sud = &pieceConnectee;
        pieceConnectee.setNord(this);
    }
    else if (orientation == "Est" || orientation == "est") {
        est = &pieceConnectee;
        pieceConnectee.setOuest(this);
    }
    else if (orientation == "Ouest" || orientation == "ouest") {
        ouest = &pieceConnectee;
        pieceConnectee.setEst(this);
    }
}

void Piece::setNord(Piece* piece)
{
    nord = piece;
}

void Piece::setSud(Piece* piece)
{
    sud = piece;
}

void Piece::setEst(Piece* piece)
{
    est = piece;
}

void Piece::setOuest(Piece* piece)
{
    ouest = piece;
}

void Piece::recupererEtoile({


}