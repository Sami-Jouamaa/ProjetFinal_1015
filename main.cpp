#include "Objet.hpp"
#include "Piece.hpp"
#include "Mario.hpp"
#include "Carte.hpp"
#include <iostream>

using namespace std;


int main()
{
	vector<Piece> pieces;

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

	Carte carte(sallePrincipale, pieces);

	carte.ajouterPiece(sallePrincipale);
	carte.ajouterPiece(couloirGauche);
	carte.ajouterPiece(couloirDroit);
	carte.ajouterPiece(escaliers);
	carte.ajouterPiece(infini);
	carte.ajouterPiece(horloge);
	carte.ajouterPiece(exposition);
	carte.ajouterPiece(bossFinal);
	carte.ajouterPiece(courArriere);
	carte.ajouterPiece(aquarium);
	carte.ajouterPiece(salleEnneigee);
	carte.ajouterPiece(donjon);
	carte.ajouterPiece(salleBombe);
	carte.ajouterPiece(dehors);

	cout << "Welcome to Super Marios 64" << endl; //Nom du jeu
	cout << endl;
	cout << "Controles sont :" << endl;
	cout << '\t' << "N pour aller au Nord de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "S pour aller au Sud de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "E pour aller a l'est de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "O pour aller a l'Ouest de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "START pour commencer le jeu" << endl;
	cout << '\t' << "EXIT pour sortir du jeu" << endl;

	string inputMovement;

	while (inputMovement != "START")
	{
		cout << "Type START to commence the game : ";
		cin >> inputMovement;
		if (inputMovement == "EXIT")
		{
			break;
		}
	}

	while (inputMovement != "EXIT")
	{
		cout << endl;
		cout << "----" << carte.getSalleActuelle()->getNom() << "----" << endl;

		cout << "Your choices are :" << endl;
		
		if (carte.getSalleActuelle()->getNord() != nullptr)
		{
			cout << '\t' << "N:" << carte.getSalleActuelle()->getNord()->getNom() << endl;
		}

		if (carte.getSalleActuelle()->getSud() != nullptr)
		{
			cout << '\t' << "S:" << carte.getSalleActuelle()->getSud()->getNom() << endl;
		}
		
		if (carte.getSalleActuelle()->getEst() != nullptr)
		{
			cout << '\t' << "E:" << carte.getSalleActuelle()->getEst()->getNom() << endl;
		}
		
		if (carte.getSalleActuelle()->getOuest() != nullptr)
		{
			cout << '\t' << "W:" << carte.getSalleActuelle()->getOuest()->getNom() << endl;
		}

		cout << "Type your next move : ";
		cin >> inputMovement;
		cout << endl;

		if (inputMovement == "N")
		{
			if (carte.getSalleActuelle()->getNord() != nullptr)
			{
				carte.setSalleActuelle(*(carte.getSalleActuelle()->getNord()));
			}
			else
			{
				cout << "You cannot go North of where you are right now." << endl;
			}
		}
		else if (inputMovement == "S")
		{
			if (carte.getSalleActuelle()->getSud() != nullptr)
			{
				carte.setSalleActuelle(*(carte.getSalleActuelle()->getSud()));
			}
			else
			{
				cout << "You cannot go South of where you are right now." << endl;
			}
		}
		else if (inputMovement == "W")
		{
			if (carte.getSalleActuelle()->getOuest() != nullptr)
			{
				carte.setSalleActuelle(*(carte.getSalleActuelle()->getOuest()));
			}
			else
			{
				cout << "You cannot go West of where you are right now." << endl;
			}
		}
		else if (inputMovement == "E")
		{
			if (carte.getSalleActuelle()->getEst() != nullptr)
			{
				carte.setSalleActuelle(*(carte.getSalleActuelle()->getEst()));
			}
			else
			{
				cout << "You cannot go East from where you are right now." << endl;
			}
		}
		else
		{
			cout << "Please type a valid movement input." << endl;
		}
	}
}
