#include "Student.h"

Student::Student(string brIndeksa, string ime, string prezime, string JMBG, string datumUpisa, int brojSemestra, bool budzet) {
	this->brojIndeksa = brIndeksa;
	this->ime = ime;
	this->prezime = prezime;
	this->budzet = budzet;
	this->JMBG = JMBG;
	this->datumUpisa = datumUpisa;
	this->semestar = brojSemestra;
	this->odsek = nullptr;
}

void Student::prikaziInfo() {
	cout << "Broj indeksa: " << brojIndeksa << endl;
	cout << "Ime i prezime: " << ime << " " << prezime << endl;
	cout << "Odsek: " << odsek->getNaziv() << "\t";
	cout << "Semestar: " << semestar << endl;
	cout << "JMBG: " << JMBG << endl;
	cout << "Datum upisa: " << datumUpisa << endl;
}

void Student::setOdsek(Odsek* o){
		odsek = o;
}

void Student::dodajPredmet(Predmet* p) {
	predmeti.push_back(*p);
}

void Student::prikaziTrenutnePredmete() {
	cout << "Trenutni predmeti studenta sa indeksom " << brojIndeksa << ": " <<endl;
	for (auto i = predmeti.begin(); i < predmeti.end(); i++)
	{
		i->prikaziInfo();
	}
}

bool Student::daLiPostojiVecPredmet(string sifraPred){
	for (auto i = predmeti.begin(); i < predmeti.end(); i++)
	{
		if (sifraPred == i->getSifraPredmeta())
			return true;
	}
	return false;
}

void Student::zameniPredmete(Predmet* s,Predmet* n) {
	for (auto i = predmeti.begin(); i < predmeti.end(); i++)
	{
		if (i->getSifraPredmeta()==s->getSifraPredmeta())
		{
			*i = *n;
		}
	}
}

int Student::vratiUkupanESPB() {
	int brESPB = 0;
	for (auto i = predmeti.begin(); i < predmeti.end(); i++)
	{
		if (i->getSemestar()==semestar)
		{
			brESPB += i->getESPB();
		}
	}
	return brESPB;
}
