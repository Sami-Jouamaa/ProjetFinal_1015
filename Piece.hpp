#pragma once
#include <string>
#include <vector>
#include "Objet.hpp"
using namespace std;

class Piece
{
public:
    Piece(string nomPiece, string descriptionPiece);
    ~Piece();

    void setSud(Piece* piece);
    void setNord(Piece* piece);
    void setEst(Piece* piece);
    void setOuest(Piece* piece);

    void ajouterObjet(Objet objet);

    void connecterPieces(Piece& pieceConnectee, string orientation);

    //Getters pour nom, description, pieces au sud, nord, ouest, est
    string getNom();
    string getDescription();

    Piece* getSud();
    Piece* getNord();
    Piece* getEst();
    Piece* getOuest();

private:
    string nom;
    string description;
    vector<Objet> objets;
    Piece* nord;
    Piece* sud;
    Piece* est;
    Piece* ouest;
};
