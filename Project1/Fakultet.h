#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;
#include "Odsek.h"
class Odsek;
class Fakultet
{
private:
	string naziv;
	string datumOsnivanja;
	vector<Odsek> smerovi;
	int brojOdseka;
	int brStudenata = 0;
	Fakultet()=delete;
	Fakultet(const Fakultet&) = delete;
	Fakultet(string naziv, string datumOsnivanja);
public:
	static Fakultet& getInstance(string naziv, string datumOsnivanja);
	void prikaziInfo();
	void prikaziInfoOdseka();
	void prikaziInfoStudenta(string brIndeksa);

	void dodajOdsek(string punNaziv,string naziv);
	bool dodajPredmet(string sifraPred, string naziv, int ESPB, string smer, int semestar, bool obavezni);
	bool upisiStudenta(string brIndeksa, string ime, string prezime, string JMBG, string datumUpisa, string smer, int semestar, string budzet);

	void upisiStudenteIzFajla(string nazivFajla);
	void ucitajPredmeteIzFajla(string naziv);

	void prikaziStudenteOdseka(string smer);
	void prikaziPredmeteOdseka(string smer);

	void prikaziPredmeteStudenta(string brIndeksa);
	void izaberiIzborniPredmetStundentu(string brIndeksa, string sifraPred);
	void zameniIzborniPredmetStudentu(string brIndeksa, string sifraPostojecegPredmeta, string sifraNovogPredmeta);
	void overiSemestarStudentu(string brIndeksa);
	int vratiUkupanBrojESPBzaStudenta(string brIndeksa);
	void prikaziInfoOStatusuFinansiranjaStudenata();
};

