#pragma once
#include "Objet.hpp"
#include "Piece.hpp"
#include "Mario.hpp"
#include "Carte.hpp"
#include "Tableau.hpp"
#include <iostream>

using namespace std;


int main()
{
	Mario mario(false, 0);
	vector<Piece> pieces;
	
	//Nombres d'etoiles a changer au besoin

	Piece sallePrincipale("Salle principale", "Premiere piece en entrant", 0);
	Piece couloirGauche("Couloir Gauche", "Connecte au donjon et Tableau de bombes", 0); //Porte gauche
	Piece salleBombe("Salle avec un Tableau avec des Bombes", "Cul-de-sac", 1); //Tableau bombe
	Piece salleEnneigee("Salle avec un Tableau enneige", "Portal vers le pays des pingouins", 0); //Tableau pingouins
	Piece aquarium("Aquarium", "Portail vers le niveau aquatique", 2); //Tableau  eau
	Piece donjon("Donjon", "Portail vers le niveau de lave", 3); //Niveau lave
	Piece couloirDroit("Couloir Droit", "Connecte au tableau d'eau, cour arriere et tableau de neige", 0); //Porte droite
	Piece courArriere("Cour Arriere", "Cul-de-sac", 0);
	Piece dehors("Dehors", "À l'exterieur du château", 0); //Salle initiale
	Piece escaliers("En haut des escaliers", "Debut du deuxieme etage", 0);
	Piece horloge("Salle avec une Horloge Geante", "Portail vers horloge", 4); //Tableau horloge
	Piece exposition("Salle d'exposition", "Salle avec une statue", 0);
	//Piece courArriere("Cour arriere"); On a dejà une cour arriere
	Piece infini("Escalier infini", "Escalier interminable jusqu'au boss", 0);
	Piece bossFinal("Boss final", "Bowser", 5);

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

	Tableau tableauBombe("TableauBombes", "Un portail vers le pays de King Bob-Omb", 1);
	Tableau tableauPinguoins("TableauPingouins", "Un portail vers le pays enneigé des pingouins", 1);
	Tableau tableauEau("TableauAquatique", "Un tableau menant au niveau aquatique du château", 1);
	Tableau tableauLave("TableauLave", "Un portail vers la terre infernale de lave", 1);
	Tableau tableauHorloge("TableauHorloge", "Un portail vers le pays des horloges", 1);

	salleBombe.ajouterTableau(tableauBombe);
	salleEnneigee.ajouterTableau(tableauPinguoins);
	aquarium.ajouterTableau(tableauEau);
	donjon.ajouterTableau(tableauLave);
	horloge.ajouterTableau(tableauHorloge);

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
	string nomObjet;

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
		cout << "----" << carte.getSalleActuelle()->getNomPiece() << "----" << endl;

		// Liste des objets dans la salle
		if (carte.getSalleActuelle()->getNomPiece() == "Boss final")
		{
			mario.wahoo();
			cout << "Bravo ! Vous avez fini Super Mario 64" << endl;
			cout << "Veuillez taper EXIT pour sortir du jeu" << endl;
		}

		else if (!(carte.getSalleActuelle()->isObjetsEmpty()) || !(carte.getSalleActuelle()->isTableauxEmpty()))
		{
			cout << "Il y a des objets dans la salle : " << endl;
			carte.getSalleActuelle()->printObjects();
			carte.getSalleActuelle()->printTableaux();
		}

		cout << "Vous pouvez vous diriger vers :" << endl;

		if (carte.getSalleActuelle()->getNord() != nullptr)
		{
			cout << '\t' << "N:" << carte.getSalleActuelle()->getNord()->getNomPiece() << endl;
		}

		if (carte.getSalleActuelle()->getSud() != nullptr)
		{
			cout << '\t' << "S:" << carte.getSalleActuelle()->getSud()->getNomPiece() << endl;
		}

		if (carte.getSalleActuelle()->getEst() != nullptr)
		{
			cout << '\t' << "E:" << carte.getSalleActuelle()->getEst()->getNomPiece() << endl;
		}

		if (carte.getSalleActuelle()->getOuest() != nullptr)
		{
			cout << '\t' << "W:" << carte.getSalleActuelle()->getOuest()->getNomPiece() << endl;
		}

		cout << "Vers ou voulez-vous vous diriger ? (N/S/E/W) : ";
		cout << "Vous pouvez aussi interagir avec un des objets dans la salle avec: " << endl;
		cout << '\t' << "USE" << endl;
		cin >> inputMovement;
		cout << endl;

		if (inputMovement == "N")
		{
			if ((carte.getSalleActuelle()->getNord() != nullptr) && (mario.getNbreEtoilesMario() >= carte.getSalleActuelle()->getNord()->getNbreEtoilesRequises()))
			{
				carte.setSalleActuelle(*(carte.getSalleActuelle()->getNord()));
			}
			else
			{
				cout << "Il n'y a soit pas de pièce au Nord de vous ou, vous n'avez pas assez d'étoiles." << endl;
			}
		}
		else if (inputMovement == "S")
		{
			if ((carte.getSalleActuelle()->getSud() != nullptr) && (mario.getNbreEtoilesMario() >= carte.getSalleActuelle()->getSud()->getNbreEtoilesRequises()))
			{
				carte.setSalleActuelle(*(carte.getSalleActuelle()->getSud()));
			}
			else
			{
				cout << "Il n'y a aucun moyen d'aller vers le Sud pour le moment ou alors vous n'avez pas assez d'étoiles." << endl;
			}
		}
		else if (inputMovement == "W")
		{
			if ((carte.getSalleActuelle()->getOuest() != nullptr) && (mario.getNbreEtoilesMario() >= carte.getSalleActuelle()->getOuest()->getNbreEtoilesRequises()))
			{
				carte.setSalleActuelle(*(carte.getSalleActuelle()->getOuest()));
			}
			else
			{
				cout << "Il n'y a aucun moyen d'aller vers l'Ouest pour le moment ou alors vous n'avez pas assez d'étoiles." << endl;
			}
		}
		else if (inputMovement == "E")
		{
			if ((carte.getSalleActuelle()->getEst() != nullptr) && (mario.getNbreEtoilesMario() >= carte.getSalleActuelle()->getEst()->getNbreEtoilesRequises()))
			{
				carte.setSalleActuelle(*(carte.getSalleActuelle()->getEst()));
			}
			else
			{
				cout << "Il n'y a aucun moyen d'aller vers l'Est pour le moment ou alors vous n'avez pas assez d'étoiles." << endl;
			}
		}
		else if (inputMovement == "USE")
		{
			cout << "Entrez le nom de l'obet avec lequel vous voulez interagir, par exemple: Tableau Bombes.: ";
			cin >> nomObjet;
			cout << endl;

			if (carte.getSalleActuelle()->isTableauInPiece(nomObjet))
			{
				if (carte.getSalleActuelle()->getTableauNbreEtoiles() > 0)
				{
					mario.gagnerEtoile();
					carte.getSalleActuelle()->decrementerTableauEtoiles();
					mario.wahoo();
				}
				else
				{
					cout << "Vous avez déjà toutes les étoiles de ce tableau" << endl;
				}
			}

			else if (carte.getSalleActuelle()->isObjetInPiece(nomObjet))
			{
				mario.ajouterObjet(carte.getSalleActuelle()->getObjet(nomObjet));
			}

			else
			{
				cout << "Cet objet n'est pas dans la salle" << endl;
			}
		}
		else if (inputMovement == "EXIT")
		{
			break;
		}

		else
		{
			cout << "Veuillez entrer une commande de déplacement valide." << endl;
		}
	}
}
