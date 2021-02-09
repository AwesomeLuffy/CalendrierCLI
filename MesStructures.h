#pragma once
#include <string>
using namespace std;

struct Date {
	int annee;
	int mois;
	int jour;
};

struct Mois {
	string nomMois;
	int nombreJour;
	int numJourWeekStart;
};

struct Calendrier {
	int annee;
	int structMoisArray[12][31];
};
