#include <iostream>
#include <iomanip>
#include <string>
#include "MesStructures.h"
#include "MesFonctions.h"

using namespace std;
int main() {
	Date premiereDate, deuxiemeDate;
	Calendrier calendrier;
	premiereDate = saisirDate();
	calendrier.annee = premiereDate.annee;
	construireCalendrier(calendrier);
	afficherCalendrier(calendrier);
	cout << endl << "Premi\x8Are Date : "; 
	afficherDate(premiereDate);
	cout << endl << "Entrez une deuxi\x8Ame date : " << endl;
	deuxiemeDate = saisirDate();
	ordonnerDate(premiereDate, deuxiemeDate);
	cout << endl << "Le ";
	afficherDate(premiereDate); 
	cout << " arrive avant le ";
	afficherDate(deuxiemeDate);
	cout << endl;

	return 0;
}
