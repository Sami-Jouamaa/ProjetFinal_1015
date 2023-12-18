#include "Piece.hpp"

Piece::Piece(string nomPiece, string descriptionPiece, int nombreEtoiles)
    :nom(nomPiece), description(descriptionPiece), etoilesRequises(nombreEtoiles),
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

bool Piece::isObjetsEmpty()
{
    if (objets.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Piece::printObjects()
{
    for (int i = 0; i < objets.size(); i++)
    {
        cout << objets[i].getnom() << ": " << objets[i].getDescription() << endl;
    }
}
