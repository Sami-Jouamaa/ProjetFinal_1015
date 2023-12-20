#pragma once
#include "Piece.hpp"

Piece::Piece(string nomPiece, string descriptionPiece, int nombreEtoiles)
{
    nom = nomPiece;
    description = descriptionPiece;
    etoilesRequises = nombreEtoiles;
    nord = nullptr;
    sud = nullptr;
    ouest = nullptr;
    est = nullptr;
    vector<Objet>objects;
    vector<Tableau>tableaux;
}

Piece::~Piece() {}

string Piece::getNomPiece()
{
    return nom;
}

string Piece::getDescriptionPiece()
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

int Piece::getNbreEtoilesRequises()
{
    return etoilesRequises;
}

Tableau getTableau(int i = 0) {
        if (i >= 0 && i < tableaux.size()) { // ICI!!!!
            return tableaux[i];
        } 
        else{
            return tableaux[0];
        }
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

bool Piece::isTableauxEmpty()
{
    if (tableaux.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Piece::isTableauInPiece(string nomTableau)
{
    for (int i = 0; i < tableaux.size(); i++)
    {
        if (tableaux[i].getNomTableau() == nomTableau)
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}

bool Piece::isObjetInPiece(string nomObjet)
{
    for (int i = 0; i < objets.size(); i++)
    {
        if (objets[i].getNomObjet() == nomObjet)
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}

Objet Piece::getObjet(string nomObjet)
{
    for (int i = 0; i < objets.size(); i++)
    {
        if (objets[i].getNomObjet() == nomObjet)
        {
            return objets[i];
        }
        else
        {
            continue;
        }
    }
}

void Piece::decrementerTableauEtoiles()
{
    tableaux[0].setNbreEtoiles(0);
}

void Piece::printObjects()
{
    for (int i = 0; i < objets.size(); i++)
    {
        cout << objets[i].getNomObjet() << ": " << objets[i].getDescriptionObjet() << endl;
    }
}

void Piece::ajouterTableau(Tableau tableau)
{
    tableaux.push_back(tableau);
}

void Piece::ajouterObjet(Objet objet)
{
    objets.push_back(objet);
}

void Piece::printTableaux()
{
    for (int i = 0; i < tableaux.size(); i++)
    {
        cout << tableaux[i].getNomTableau() << ": " << tableaux[i].getDescriptionTableau() << endl;
    }
}

int Piece::getTableauNbreEtoiles()
{
    return (tableaux[0].getNbreEtoiles());
}

void retirerObjet(const Objet& objetAretirer) { // ICI!!!!
    auto it = std::find(objets.begin(), objets.end(), objetAretirer);
    if (it != objets.end()) {
        objets.erase(it);
    } else {
        std::cerr << "L'objet n'a pas été trouvé dans le vecteur.";
    }
}

