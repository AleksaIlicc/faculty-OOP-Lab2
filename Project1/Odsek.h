#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Predmet.h"
using namespace std;
class Student;
class Fakultet;
class Predmet;

class Odsek
{
private:
	string punNaziv;
	string naziv;
	int brojStudenata;
	int brojPredmeta;
	vector<Student> studenti;
	vector<Predmet> predmeti;
public:
	Odsek() = delete;
	Odsek(string punNaziv,string naziv);
	void prikaziInfoStudenata();
	void prikaziInfoStudenta(string brIndeksa);
	void prikaziInfoPredmeta();
	void dodajObaveznePredmete(Student& s);
	void dodajStudenta(Student& s);
	void dodajPredmet(Predmet& p);
	void prikaziInfo();
	void povecajBrStudenata() {
		brojStudenata++;
	}
	void povecajBrPredmeta() {
		brojPredmeta++;
	}
	void dodajIzborniStudentu(string brIndeksa, string sifraPred);
	void zameniIzborniStudentu(string brIndeksa, string sifraPredStarog, string sifraPredNovog);
	void prikaziPredmeteStudenta(string brIndeksa);
	Predmet* pronadjiPredmet(string sifraPred);
	bool pronadjiStudenta(string brIndeksa);
	void overiSemestarStudentu(string brIndeksa);
	string& getNaziv()
	{
		return naziv;
	}
	int izracunajESPB(string brIndeksa);
	void izracunajBudzetISaf(int* budzISaf);

};

