#include "Fakultet.h"

Fakultet::Fakultet(string naziv, string datumOsnivanja) {
	this->naziv = naziv;
	this->datumOsnivanja = datumOsnivanja;
}

void Fakultet::dodajOdsek(string punNaziv,string naziv) {
	Odsek tmp(punNaziv,naziv);
	smerovi.push_back(tmp);
	brojOdseka++;
}

void Fakultet::prikaziInfo() {
	cout << "==========================================" << endl;
	cout << endl << "Naziv fakulteta: " << naziv << endl;
	cout << "Datum osnivanja: " << datumOsnivanja << endl;
	cout << "Broj odseka: " << brojOdseka << endl;
	cout << "Ukupan broj studenata: " << brStudenata << endl << endl;
	cout << "==========================================" << endl;
}

void Fakultet::prikaziInfoOdseka() {
	cout << "==========================================" << endl;
	cout << endl << "Broj odseka: " << brojOdseka << endl;
	cout << endl;
	for (auto i = smerovi.begin(); i != smerovi.end(); i++)
	{
		i->prikaziInfo();
		cout << endl;
	}
	cout << "==========================================" << endl;
}

void Fakultet::prikaziInfoStudenta(string brIndeksa)
{
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->pronadjiStudenta(brIndeksa))
		{
			i->prikaziInfoStudenta(brIndeksa);
			break;
		}
	}
}


bool Fakultet::upisiStudenta(string brIndeksa, string ime, string prezime, string JMBG, string datumUpisa, string smer, int semestar, string budzet)
{
	bool budz_t;
	if (budzet == "1")
		budz_t = true;
	else
		budz_t = false;
	Student tmp(brIndeksa,ime,prezime,JMBG,datumUpisa,semestar,budz_t);
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->getNaziv()==smer)
		{
			brStudenata++;
			i->dodajObaveznePredmete(tmp);
			i->dodajStudenta(tmp);
			i->povecajBrStudenata();
			return true;
		}
	}
	return false;
}

Fakultet& Fakultet::getInstance(string naziv, string datumOsnivanja) {
	static Fakultet instance(naziv, datumOsnivanja);
	return instance;
}

void Fakultet::upisiStudenteIzFajla(string nazivFajla) {
	ifstream i(nazivFajla);
	while (i.good())
	{
		string brInd, JMBG, datumUpisa, smer, ime, prez, budzet;
		int semestar;
		i >> brInd >> ime >> prez >> JMBG >> datumUpisa >> smer >> semestar>> budzet;
		upisiStudenta(brInd, ime, prez, JMBG, datumUpisa, smer, semestar, budzet);
	}
}

void Fakultet::prikaziStudenteOdseka(string smer)
{
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->getNaziv()==smer)
		{
			i->prikaziInfoStudenata();
			break;
		}
	}
}


void Fakultet::prikaziPredmeteOdseka(string smer)
{
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->getNaziv() == smer)
		{
			i->prikaziInfoPredmeta();
			break;
		}
	}
}

void Fakultet::ucitajPredmeteIzFajla(string naziv)
{
	ifstream is(naziv);
	if (!is.is_open()) {
		cout << "Greska pri otvaranju fajla." << endl;
		return;
	}
	string line;
	while (is.good())
	{
		string nazivPredmeta, smer, sifra;
		int brojESPB,semestar, obavezni;
		if (is >> nazivPredmeta >> brojESPB >> smer >> sifra >> semestar >> obavezni) 
			
			dodajPredmet(sifra, nazivPredmeta, brojESPB, smer, semestar , obavezni);
			
		
	}
}

bool Fakultet::dodajPredmet(string sifraPred, string naziv, int ESPB, string smer, int semestar, bool obavezni)
{
	Predmet p(sifraPred, naziv, ESPB, semestar, obavezni);
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->getNaziv()==smer)
		{
			i->dodajPredmet(p);
			i->povecajBrPredmeta();
		}
	}
	return false;
}

void Fakultet::prikaziPredmeteStudenta(string brIndeksa) {
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->pronadjiStudenta(brIndeksa))
		{
			i->prikaziPredmeteStudenta(brIndeksa);
			break;
		}
	}
}

void Fakultet::izaberiIzborniPredmetStundentu(string brIndeksa, string sifraPred){

	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->pronadjiStudenta(brIndeksa))
		{
			i->dodajIzborniStudentu(brIndeksa,sifraPred);
			break;
		}
	}

}

void Fakultet::zameniIzborniPredmetStudentu(string brIndeksa, string sifraPostojecegPredmeta, string sifraNovogPredmeta) {

	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->pronadjiStudenta(brIndeksa))
		{
			i->zameniIzborniStudentu(brIndeksa, sifraPostojecegPredmeta,sifraNovogPredmeta);
			break;
		}
	}

}

void Fakultet::overiSemestarStudentu(string brIndeksa)
{
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->pronadjiStudenta(brIndeksa))
		{
			i->overiSemestarStudentu(brIndeksa);
			break;
		}
	}
}

int Fakultet::vratiUkupanBrojESPBzaStudenta(string brIndeksa) {
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		if (i->pronadjiStudenta(brIndeksa))
		{
			int espb=i->izracunajESPB(brIndeksa);
			return espb;
		}
	}
	return 0;
}

void Fakultet::prikaziInfoOStatusuFinansiranjaStudenata()
{
	int budz = 0, sf = 0;
	int* bs = new int[2];
	bs[0] = 0;
	bs[1] = 0;
	for (auto i = smerovi.begin(); i < smerovi.end(); i++)
	{
		i->izracunajBudzetISaf(bs);
	}
	cout << "==========================================" << endl;
	cout << endl << "Broj studenata: " << brStudenata << endl;
	cout << "Broj studenata na budzetu: " << bs[0] << endl;
	cout << "Broj studenata na samofinansiranju: " << bs[1] << endl << endl;

	cout << "==========================================" << endl;

	delete bs;
}
