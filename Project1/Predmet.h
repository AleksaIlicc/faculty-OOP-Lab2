#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Odsek.h"
class Odsek;

class Predmet
{
private:
	string sifraPredmeta;
	string naziv;
	bool obavezni;
	int semestar;
	int ESPB;
	Odsek* odsek;
public:
	Predmet(string sifraPred, string naziv, int ESPB, int sem, bool obavezni);
	void prikaziInfo();
	void setOdsek(Odsek* o);
	int getSemestar() {
		return semestar;
	}
	bool getObavezni() {
		return obavezni;
	}
	int obavezniToNum() {
		if (obavezni == true)
			return 1;
		else 
			return 0;
	}
	string& getSifraPredmeta() {
		return sifraPredmeta;
	}
	int getESPB() {
		return ESPB;
	}

};

