#pragma once
#include "Objet.hpp"
#include "Piece.hpp"
#include "Mario.hpp"
#include "Carte.hpp"
#include <iostream>

using namespace std;


int main()
{
	vector<Piece> pieces;
	
	//Nombres d'etoiles a changer au besoin

	Piece sallePrincipale("Salle principale", "Premiere piece en entrant", 0);
	Piece couloirGauche("Couloir Gauche", "Connecte au donjon et Tableau de bombes", 0); //Porte gauche
	Piece salleBombe("Salle avec un Tableau avec des Bombes", "Cul-de-sac", 2); //Tableau bombe
	Piece salleEnneigee("Salle avec un Tableau enneige", "Portal vers le pays des pingouins", 1); //Tableau pingouins
	Piece aquarium("Aquarium", "Portail vers le niveau aquatique", 3); //Tableau  eau
	Piece donjon("Donjon", "Portail vers le niveau de lave", 4); //Niveau lave
	Piece couloirDroit("Couloir Droit", "Connecte au tableau d'eau, cour arriere et tableau de neige", 0); //Porte droite
	Piece courArriere("Cour Arriere", "Cul-de-sac", 0);
	Piece dehors("Dehors", "À l'exterieur du château", 0); //Salle initiale
	Piece escaliers("En haut des escaliers", "Debut du deuxieme etage", 0);
	Piece horloge("Salle avec une Horloge Geante", "Portail vers horloge", 5); //Tableau horloge
	Piece exposition("Salle d'exposition", "Salle avec une statue", 0);
	//Piece courArriere("Cour arriere"); On a dejà une cour arriere
	Piece infini("Escalier infini", "Escalier interminable jusqu'au boss", 0);
	Piece bossFinal("Boss final", "Bowser", 6);

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

	Tableau tableauBombe("Tableau bombes", "Un portail vers le pays de King Bob-Omb", 1);
	Tableau tableauPinguoins("Tableau pingouins", "Un portail vers le pays enneigé des pingouins", 1);
	Tableau tableauEau("Tableau aquatique", "Un tableau menant au niveau aquatique du château", 1);
	Tableau tableauLave("Tableau lave", "Un portail vers la terre infernale de lave", 1);
	Tableau tableauHorloge("Tableau horloge", "Un portail vers le pays des horloges", 1);

	salleBombe.ajouterObjet(tableauBombe);
	salleEnneigee.ajouterObjet(tableauPinguoins);
	aquarium.ajouterObjet(tableauEau);
	donjon.ajouterObjet(tableauLave);
	horloge.ajouterObjet(tableauHorloge);

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
	cout << '\t' << "E pour aller a l'Est de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "O pour aller a l'Ouest de la piece ou vous etes en ce moment." << endl;
	cout << '\t' << "START pour commencer le jeu" << endl;
	cout << '\t' << "EXIT pour sortir du jeu" << endl;

	string inputMovement;

	while (inputMovement != "START")
	{
		cout << "Écrivez START pour commencer la partie ";
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

		// Liste des objets dans la salle

		if (!(carte.getSalleActuelle()->isObjetsEmpty()))
		{
			cout << "Il y a des objets dans la salle : " << endl;
			carte.getSalleActuelle()->printObjects();
		}

		cout << "Vous pouvez vous diriger vers :" << endl;

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

		cout << "Vers ou voulez-vous vous diriger ? (N/S/E/W) : ";
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
				cout << "Il n'y a aucun moyen d'aller vers le Nord pour le moment." << endl;
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
				cout << "Il n'y a aucun moyen d'aller vers le Sud pour le moment." << endl;
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
				cout << "Il n'y a aucun moyen d'aller vers l'Ouest pour le moment." << endl;
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
				cout << "Il n'y a aucun moyen d'aller vers l'Est pour le moment." << endl;
			}
		}
		else
		{
			cout << "Veuillez entrer une commande de déplacement valide." << endl;
		}
	}
}
