#include "Predmet.h"

Predmet::Predmet(string sifraPred,string naziv, int ESPB, int sem, bool obavezni) {
	this->sifraPredmeta = sifraPred;
	this->naziv = naziv;
	this->ESPB = ESPB;
	this->semestar = sem;
	this->obavezni = obavezni;
}

void Predmet::setOdsek(Odsek* o) {
	odsek = o;
}

void Predmet::prikaziInfo() {
	cout << endl << "Naziv: " << naziv << endl;
	cout << "Sifra Predmeta: " << sifraPredmeta << endl;
	cout << "Broj ESPB: " << ESPB << endl;
	cout << "Semestar: " << semestar << endl;
	cout << "Obavezni: " << obavezniToNum() << endl;
}