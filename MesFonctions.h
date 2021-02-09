#pragma once
#include <string>
#include "MesStructures.h"
using namespace std;

Date saisirDate();
bool estBisextile(int anneeCible);
void afficherSiBisextile(bool estAnneeBisextile);
int getPremierJourAnnee(int anneeCible);
int getNbrJoursMois(int moisCible, bool estAnneeBisextile);
int getnumJourWeekStart(int moisCible, int annee);
void construireCalendrier(Calendrier& calendrierCible);
string getNomMois(int noMois);
void afficherCalendrier(Calendrier calendrier);
string getDeuxLettreJour(int noJour);
void  afficherDate(Date date);
void ordonnerDate(Date& premierDate, Date& deuxiemeDate);
void inverserDate(Date& premierDate, Date& deuxiemeDate);
