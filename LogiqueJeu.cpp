#pragma once
#include "LogiqueJeu.hpp"

using namespace std;

LogiqueJeu::LogiqueJeu() {}

LogiqueJeu::~LogiqueJeu() {}

void LogiqueJeu::startGame()
{
	Mario mario(false, 0);
	vector<Piece> pieces;

	Piece sallePrincipale("Salle principale", "La Salle principale du château. Un puit de lumiere puissant vous aveugle legerement.", 0);
	Piece couloirGauche("Couloir Gauche", "Un couloir intermediaire de la salle principale et d'une autre salle.", 0); //Porte gauche
	Piece salleBombe("Salle avec un Tableau avec des Bombes", "Une petite salle d'exposition tres modeste. Une etrange toile est accrochee sur le mur vide, avec des dessins ressemblant a des bombes.", 0); //Tableau bombe
	Piece salleEnneigee("Salle Enneigee", "Une salle froide avec des murs blancs. Au millieu reside un tableau, avec un dessin d'un chalet entoure de pingouins bleus.", 1); //Tableau pingouins
	Piece aquarium("Aquarium", "Une salle donc les murs sont remplaces par un immense aquarium circulaire. Au millieu de la vitre, un tableau figurant une epave au fond de l'ocean est accroche.", 2); //Tableau  eau
	Piece donjon("Donjon", "Un endroit sombre et peu accueillant. Pourquoi la princesse possede elle un donjon en premier lieu?", 1); //Niveau lave
	Piece couloirDroit("Couloir Droit", "Un simple couloir. Il mene a trois portes differentes, une avec une poignee gele, une avec une poignee rouillee et une qui mene vers la cour arriere.", 0); //Porte droite
	Piece courArriere("Cour Arriere", "Une cour remplie de vegetation incroyable, pourtant tres silencieuse.", 0);
	Piece dehors("Dehors", "La cour avant du château. Un jardin de marguerites cree un chemin naturel vers la porte d'entree avec un immense canon bleu qui pointe etrangement vers le château.", 0); //Salle initiale
	Piece escaliers("En haut des escaliers", "Des marches, des marches et encore d'autres marches. Ce château ne finit jamais", 3);
	Piece horloge("Salle avec une Horloge Geante", "Une salle aux murs avec des motifs indescriptibles. Au millieu se situe une immense horloge.", 0); //Tableau horloge
	Piece exposition("Salle d'exposition", "Une salle vide, avec une statue sans visage.", 4);
	Piece infini("Escalier infini", "Une salle vide, avec un escalier rouge qui semble monter vers le haut a l'infini.", 0);
	Piece bossFinal("Boss final", "L'endroit ou se cache l'infâme Bowser.", 5);

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

	Tableau tableauBombe("TableauBombes", "Un portail vers le pays de King Bob-Omb", 1, false);
	Tableau tableauPingouins("TableauPingouins", "Un portail vers le pays enneige des pingouins", 1, false);
	Tableau tableauEau("TableauAquatique", "Un tableau menant au niveau aquatique du château", 1, false);
	Tableau tableauLave("TableauLave", "Un portail vers la terre infernale de lave", 1, false);
	Tableau tableauHorloge("TableauHorloge", "Un portail vers le pays des horloges", 1, true);

	salleBombe.ajouterTableau(tableauBombe);
	salleEnneigee.ajouterTableau(tableauPingouins);
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

	Objet toad("ToadRouge", "Il est gentil mais parle beaucoup trop fort.");
	Objet yoshi("Yoshi", "Un dinosaure vert avec un immense nez.");
	Objet poisson("Poisson", "Un vieux poisson qui traîne sur le plancher.");
	Objet livre("Livre", "Un vieux livre traîne sur le sol. << L'avenir de la societe industrielle>>, par un certain Theodore John Kaczynski.");
	Objet luigi("Statue", "Une statue en forme d'etoile a cinq côtes, avec l'inscription << L is real >> sur la base.");

	sallePrincipale.ajouterObjet(toad);
	courArriere.ajouterObjet(yoshi);
	aquarium.ajouterObjet(poisson);
	salleBombe.ajouterObjet(livre);
	courArriere.ajouterObjet(luigi);


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
		cout << "Ecrivez START pour commencer la partie ";
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
			break;
		}

		else if (!(carte.getSalleActuelle()->isObjetsEmpty()) || !(carte.getSalleActuelle()->isTableauxEmpty()))
		{
			cout << "Il y a des objets dans la salle : " << endl;
			carte.getSalleActuelle()->printObjectsNom();
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
				cout << "Il n'y a soit pas de piece au Nord de vous ou, vous n'avez pas assez d'etoiles." << endl;
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
				cout << "Il n'y a aucun moyen d'aller vers le Sud pour le moment ou alors vous n'avez pas assez d'etoiles." << endl;
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
				cout << "Il n'y a aucun moyen d'aller vers l'Ouest pour le moment ou alors vous n'avez pas assez d'etoiles." << endl;
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
				cout << "Il n'y a aucun moyen d'aller vers l'Est pour le moment ou alors vous n'avez pas assez d'etoiles." << endl;
			}
		}
		else if (inputMovement == "USE")
		{
			cout << "Entrez le nom de l'obet avec lequel vous voulez interagir, par exemple: Tableau Bombes.: ";
			cin >> nomObjet;
			cout << endl;

			if (carte.getSalleActuelle()->isTableauInPiece(nomObjet))
			{
				if ((carte.getSalleActuelle()->getTableau(0).getNecessiteYoshi()) && !(mario.possedeYoshi()))
				{
					cout << "Le tableau est trop haut pour être atteint! Si seulement vous aviez quelque chose pour aider..." << endl;
				}

				else if ((carte.getSalleActuelle()->getTableau(0).getNecessiteYoshi()) && (mario.possedeYoshi()) && (carte.getSalleActuelle()->getTableauNbreEtoiles() > 0))
				{
					mario.gagnerEtoile();
					mario.wahoo();
					carte.getSalleActuelle()->decrementerTableauEtoiles();
					carte.setSalleActuelle(sallePrincipale);
					cout << "Woosh! Une lumiere blanche plus forte que 1000 soleils vous aveugle, et vous vous retrouvez dans la salle principale du château. Vous vous sentez plus confiant." << endl;

				}

				else if (carte.getSalleActuelle()->getTableauNbreEtoiles() > 0)
				{
					mario.gagnerEtoile();
					mario.wahoo();
					carte.getSalleActuelle()->decrementerTableauEtoiles();
					carte.setSalleActuelle(sallePrincipale);
					cout << "Woosh! Une lumiere blanche plus forte que 1000 soleils vous aveugle, et vous vous retrouvez dans la salle principale du château. Vous vous sentez plus confiant." << endl;

				}
				else
				{
					cout << "Vous avez deja toutes les etoiles de ce tableau" << endl;
				}
			}

			else if (carte.getSalleActuelle()->isObjetInPiece(nomObjet))
			{
				if ((nomObjet == "Yoshi") && !(mario.possedeYoshi()))
				{
					mario.trouverYoshi();
				}
				mario.ajouterObjet(carte.getSalleActuelle()->getObjet(nomObjet));

				cout << "Objet acquis! Il n'est plus dans la piece desormais, mais plutôt dans l'immense poche de votre salopette." << endl;

				carte.getSalleActuelle()->retirerObjet(carte.getSalleActuelle()->getObjet(nomObjet));
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
			cout << "Veuillez entrer une commande de deplacement valide." << endl;
		}
	}
}
