#pragma once
#include <string>
#include <vector>
#include "Objet.hpp"
#include "Tableau.hpp"
using namespace std;

class Piece
{
public:
    Piece(string nomPiece, string descriptionPiece, int etoilesRequises);

    ~Piece();

    void setSud(Piece* piece);
    void setNord(Piece* piece);
    void setEst(Piece* piece);
    void setOuest(Piece* piece);

    void ajouterObjet(Objet objet);
    void ajouterTableau(Tableau tableau);

    void connecterPieces(Piece& pieceConnectee, string orientation);

    //Getters pour nom, description, pieces au sud, nord, ouest, est
    string getNomPiece();
    string getDescriptionPiece();

    Piece* getSud();
    Piece* getNord();
    Piece* getEst();
    Piece* getOuest();

    int getNbreEtoilesRequises();

    Tableau getTableau(int i = 1);


    bool isObjetsEmpty();
    bool isTableauxEmpty();
    bool isTableauInPiece(string nomTableau);
    bool isObjetInPiece(string nomObjet);

    Objet getObjet(string nomObjet);

    void decrementerTableauEtoiles();
    int getTableauNbreEtoiles();

    void printObjects();
    void printTableaux();

    void ajouterObjet(Objet objet);
    void retirerObjet(const Objet& objetAretirer);

    

private:
    vector<Tableau> tableaux;
    vector<Objet> objets;
    string nom;
    string description;
    int etoilesRequises;
    Piece* nord;
    Piece* sud;
    Piece* est;
    Piece* ouest;
};
