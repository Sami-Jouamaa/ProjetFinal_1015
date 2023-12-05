#include "Objet.hpp"
#include "Piece.hpp"
#include "Mario.hpp"
#include "Carte.hpp"
#include <iostream>

using namespace std;


int main()
{
	Piece sallePrincipale("Salle principale", "Premiere piece en entrant");
	Piece couloirGauche("Couloir Gauche", "Connecte au donjon et Tableau de bombes"); //Porte gauche
	Piece salleBombe("Salle avec un Tableau avec des Bombes", "Cul-de-sac"); //Tableau bombe
	Piece salleEnneigee("Salle avec un Tableau enneige", "Portal vers le pays des pingouins");
	Piece aquarium("Aquarium", "Portail vers le niveau aquatique"); //Tableau  eau
	Piece donjon("Donjon", "Portail vers le niveau de lave"); //Niveau lave
	Piece couloirDroit("Couloir Droit", "Connecte au tableau d'eau, cour arriere et tableau de neige"); //Porte droite
	Piece courArriere("Cour Arriere", "Cul-de-sac");
	Piece dehors("Dehors", "À l'exterieur du château"); //Salle initiale
	Piece escaliers("En haut des escaliers", "Debut du deuxieme etage");
	Piece horloge("Salle avec une Horloge Geante", "Portail vers horloge"); //Tableau horloge
	Piece exposition("Salle d'exposition", "Salle avec une statue");
	//Piece courArriere("Cour arriere"); On a dejà une cour arriere
	Piece infini("Escalier infini", "Escalier interminable jusqu'au boss");
	Piece bossFinal("Boss final", "Bowser");

	sallePrincipale.connecterPieces(couloirGauche, "Ouest");
	sallePrincipale.connecterPieces(couloirDroit, "Est");
	sallePrincipale.connecterPieces(escaliers, "Nord");
	sallePrincipale.connecterPieces(dehors, "Sud");
	couloirGauche.connecterPieces(salleBombe, "Ouest");
	couloirGauche.connecterPieces(donjon, "Sud");
	couloirDroit.connecterPieces(courArriere, "Nord");
	couloirDroit.connecterPieces(aquarium, "Est");
	couloirDroit.connecterPieces(salleEnneigee, "Sud");
	escaliers.connecterPieces(infini, "Nord");
	escaliers.connecterPieces(horloge, "Est");
	escaliers.connecterPieces(exposition, "Ouest");
	infini.connecterPieces(bossFinal, "Nord");

	cout << "Welcome to Super Marios 64" << endl; //Nom du jeu
	cout << endl;
	cout << "Controles sont :" << endl;
	cout << '\t' << "N pour aller au Nord de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "S pour aller au Sud de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "E pour aller a l'est de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "O pour aller a l'Ouest de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "START pour commencer le jeu" << endl;
	cout << '\t' << "EXIT pour sortir du jeu" << endl;
	cout << "Type START to start the game" << endl;

	cout << "----" << sallePrincipale.getNom() << "----" << endl; //Piece initiale
	string inputMovement;

	while (inputMovement != "EXIT")
	{
		cout << "Type your next move : ";
		cin >> inputMovement;
	}





}