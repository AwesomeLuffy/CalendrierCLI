#include "MesStructures.h"
#include "MesFonctions.h"
#include <iomanip>
#include <iostream>
using namespace std;

Date saisirDate() {
	Date date;
	Mois mois;
	int nombreJour;
	cout << "Entrez l'ann\x82""e d\x82sir\x82""e (1900 à aujourd'hui) : ";
	do {
		while (!(cin >> date.annee)) {
			cout << "ERREUR, Veuillez entrer un chiffre";
			cin.clear();
			cin.ignore(256, '\n');
			if (date.annee < 1900) { cout << "Date trop grande veuillez r\x82""essayer" << endl; }
		}
	} while (date.annee < 1900);

	cout << "Entrez le mois d\x82sir\x82""e : ";
	do {
		while (!(cin >> date.mois)) {
			cout << "ERREUR, Veuillez entrer un chiffre";
			cin.clear();
			cin.ignore(256, '\n');
			if (date.mois < 1 || date.mois > 12) { cout << "Mois trop grand veuillez r\x82""essayer" << endl; }
		}
	} while (date.mois < 1 || date.mois > 12);

	nombreJour = getNbrJoursMois(date.mois, estBisextile(date.annee));
	cout << "Entrez le jour d\x82sir\x82""e : ";
	do {
		while (!(cin >> date.jour)) {
			cout << "ERREUR, Veuillez entrer un chiffre";
			cin.clear();
			cin.ignore(256, '\n');
		}
		if (date.jour > nombreJour || date.jour < 1) { cout << "Jour trop grand, veuillez r\x82""essayer" << endl; }
	} while (date.jour > nombreJour || date.jour < 1);
	return date;
}
bool estBisextile(int anneeCible) {
	if ((anneeCible - 1900) % 4 == 0) { return true; }
	else { return false; }
}
void afficherSiBisextile(bool estAnneeBisextile) {
	string estBisextile;
	(estAnneeBisextile) ? estBisextile = " est " : estBisextile = " n'est pas ";
	cout << "Cette année" << estBisextile << "bisextile";
}
int getPremierJourAnnee(int anneeCible) {
	int anneeDepart = 1900, jourDep = 0;
	while (anneeDepart < anneeCible) {
		(estBisextile(anneeDepart) && anneeDepart > 1900) ? ++jourDep += 1 : ++jourDep;
		if (jourDep >= 7) { jourDep = 0 + (jourDep - 7); }
		anneeDepart++;
	}
	return jourDep;
}
int getNbrJoursMois(int moisCible, bool estAnneeBisextile) {
	int checkTO[7] = { 0, 2, 4, 6, 7, 9, 11 };
	for (int i = 0; i < 7; i++) {
		if (moisCible == checkTO[i]) {
			return 31;
		}
	}
	if (moisCible == 1 && estAnneeBisextile) { return 29; }
	else if (moisCible == 1 && !(estAnneeBisextile)) { return 28; }
	else { return 30; }
}
int getnumJourWeekStart(int moisCible, int annee) {
	int mois = 0, jour = 0, totalJour = 0;
	jour = getPremierJourAnnee(annee);
	while (mois < moisCible) {
		totalJour += getNbrJoursMois(mois, estBisextile(annee));
		mois++;
	}
	for (int i = 0; i < totalJour; i++){
		jour++;
		if (jour > 6) { jour = 0; }
	}
	return jour;
}
void construireCalendrier(Calendrier& calendrierCible) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < getNbrJoursMois(i, estBisextile(calendrierCible.annee)); j++) {
			calendrierCible.structMoisArray[i][j] = j + 1;
		}
	}

}
string getNomMois(int noMois) {
	string Mois[12] = { "Janvier", "F\x82vrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Ao\x81t",
					   "Septembre", "Octobre", "Novembre", "D\x82""cembre" };
	return Mois[noMois];
}
void afficherCalendrier(Calendrier calendrier) {
	Mois mois;
	int checkEndl;
	for (int i = 0; i < 12; i++) {
		mois = { (getNomMois(i)), (getNbrJoursMois(i, estBisextile(calendrier.annee))),
			(getnumJourWeekStart(i, calendrier.annee)) };
		cout << "[" << getNomMois(i) << "]" << endl;
		for (int j = 0; j < 7; j++) {
			cout << right << getDeuxLettreJour(j) << setw(3);
		}
		cout << endl;
		checkEndl = mois.numJourWeekStart;
		for (int j = 0; j < getNbrJoursMois(i, estBisextile(calendrier.annee)); j++) {
			if (j == 0) {
				if (mois.numJourWeekStart > 0) {
					int temp = ((((mois.numJourWeekStart - 1) * 2) + mois.numJourWeekStart - 1)) + 3;
					string space(temp, ' ');
					cout << space;
				}
			}
			if ((checkEndl % 7 == 0) && j > 0) { cout << endl; }
			cout << setw(2) << calendrier.structMoisArray[i][j] << " ";
			checkEndl++;
		}
		cout << endl;
		cout << "---------------------" << endl;
	}
}
string getDeuxLettreJour(int noJour) {
	string Jours[7] = { "Lu", "Ma", "Me", "Je", "Ve", "Sa", "Di" };
	return Jours[noJour];
}
void afficherDate(Date date) {
	cout << date.jour << " " << getNomMois(date.mois) << " " << date.annee;
}
void ordonnerDate(Date& premierDate, Date& deuxiemeDate) {
	if (premierDate.annee > deuxiemeDate.annee) {
		inverserDate(premierDate, deuxiemeDate);
		cout << "First";
	}
	else{
		if (premierDate.mois > deuxiemeDate.mois) {
			inverserDate(premierDate, deuxiemeDate);
			cout << "Second";
		}
		else {
			if (premierDate.jour > deuxiemeDate.jour) {
				inverserDate(premierDate, deuxiemeDate);
				cout << "Third";
			}
		}
	}
}
void inverserDate(Date& premierDate, Date& deuxiemeDate) {
	Date temp;
	temp = deuxiemeDate;
	deuxiemeDate = premierDate;
	premierDate = temp;
}

