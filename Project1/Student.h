#pragma once
#include <string>
#include "Odsek.h"
using namespace std;
class Odsek;
class Predmet;

class Student
{
private:
	string ime;
	string prezime;
	string brojIndeksa;
	int semestar;
	string JMBG;
	string datumUpisa;
	Odsek* odsek;
	vector<Predmet> predmeti;
	bool budzet;
public:
	Student()=delete;
	Student(string brIndeksa, string ime, string prezime, string JMBG, string datumUpisa, int brojSemestra, bool budzet);
	void setOdsek(Odsek* o);
	void prikaziInfo();
	int izracunajESPB() {
		return 0;
	}
	void dodajPredmet(Predmet* p);
	int getSemestar() {
		return semestar;
	}
	string& getBrojIndeksa() {
		return brojIndeksa;
	}
	void prikaziTrenutnePredmete();
	bool daLiPostojiVecPredmet(string sifraPred);
	void zameniPredmete(Predmet* s, Predmet* n);
	void povecajSemestar() {
		semestar++;
	}
	int vratiUkupanESPB();
	bool returnBudzet() {
		return budzet;
	}
};

