#include "Odsek.h"

Odsek::Odsek(string punNaziv, string naziv) {
	this->naziv = naziv;
	this->punNaziv = punNaziv;
	this->brojStudenata = 0;
	this->brojPredmeta = 0;
}

void Odsek::prikaziInfo() {
	cout << "Naziv odseka: " << punNaziv << endl;
	cout << "Broj studenata: " << brojStudenata << endl;
}



void Odsek::prikaziInfoStudenata() {
	cout << "==========================================" << endl;
	cout << endl << "Broj studenata smera " << getNaziv() << ": " << brojStudenata << endl;
	cout << endl;
	for (auto i = studenti.begin(); i != studenti.end(); i++)
	{
		i->prikaziInfo();
		cout << endl;
	}
	cout << "==========================================" << endl;
}

void Odsek::prikaziInfoPredmeta() {
	cout << "==========================================" << endl;
	cout << endl << "Broj predmeta smera " << getNaziv() << ": " << brojPredmeta << endl;
	cout << endl;
	for (auto i = predmeti.begin(); i != predmeti.end(); i++)
	{
		i->prikaziInfo();
		cout << endl;
	}
	cout << endl << "==========================================" << endl;
}

void Odsek::dodajObaveznePredmete(Student& s)
{
	for (auto i = predmeti.begin(); i < predmeti.end(); i++)
	{
		if (s.getSemestar()==i->getSemestar() && i->getObavezni()==true)
		{
			s.dodajPredmet(&(*i));
		}
	}
}

void Odsek::dodajStudenta(Student& s){
	s.setOdsek(this);
	studenti.push_back(s);
}

void Odsek::dodajPredmet(Predmet& p) {
	p.setOdsek(this);
	predmeti.push_back(p);
}

bool Odsek::pronadjiStudenta(string brIndeksa) {
	for (auto i = studenti.begin(); i < studenti.end(); i++)
	{
		if (i->getBrojIndeksa() == brIndeksa)
			return true;
	}
	return false;
}

void Odsek::prikaziPredmeteStudenta(string brIndeksa) {
	cout << "==========================================" << endl<<endl;

	for(auto i = studenti.begin();  i< studenti.end(); i++)
	{
		if (brIndeksa==i->getBrojIndeksa())
		{
			i->prikaziTrenutnePredmete();
			break;
		}
	}
	cout << endl << "==========================================" << endl;

}

void Odsek::dodajIzborniStudentu(string brIndeksa, string sifraPred) {
	
	for (auto i = studenti.begin(); i < studenti.end(); i++)
	{
		if (brIndeksa == i->getBrojIndeksa() && !(i->daLiPostojiVecPredmet(sifraPred)))
		{
			Predmet* p = pronadjiPredmet(sifraPred);
			if (p!=nullptr && p->getSemestar()==i->getSemestar())
				i->dodajPredmet(p);
			break;
		}
	}

}

Predmet* Odsek::pronadjiPredmet(string sifraPred) {
	for (auto i = predmeti.begin(); i < predmeti.end(); i++)
	{
		if (sifraPred==i->getSifraPredmeta())
		{
			return &(*i);
		}
	}
	return nullptr;
}
void Odsek::zameniIzborniStudentu(string brIndeksa, string sifraPredStarog, string sifraPredNovog) {
	for (auto i = studenti.begin(); i < studenti.end(); i++)
	{
		if (brIndeksa == i->getBrojIndeksa() && !(i->daLiPostojiVecPredmet(sifraPredNovog)))
		{
			Predmet* stari = pronadjiPredmet(sifraPredStarog);
			Predmet* novi = pronadjiPredmet(sifraPredNovog);
			
			if (stari != nullptr && novi != nullptr && stari->getSemestar()==novi->getSemestar())
				//i->zameniPredmete(stari,novi);
				i->zameniPredmete(stari, novi);
			break;
		}
	}
}

void Odsek::prikaziInfoStudenta(string brIndeksa) {
	cout << "==========================================" << endl << endl;
	for (auto i = studenti.begin(); i < studenti.end(); i++)
	{
		if (i->getBrojIndeksa()==brIndeksa)
		{
			i->prikaziInfo();
		}
	}
	cout << endl << "==========================================" << endl;
}

void Odsek::overiSemestarStudentu(string brIndeksa) {
	for (auto i = studenti.begin(); i < studenti.end(); i++)
	{
		if (i->getSemestar()<8)
			i->povecajSemestar();
		Student* tmp = &(*i);
		dodajObaveznePredmete(*i);
	}
}
int Odsek::izracunajESPB(string brIndeksa) {
	for (auto i = studenti.begin(); i < studenti.end(); i++)
	{
		if (i->getBrojIndeksa() == brIndeksa) {
			return i->vratiUkupanESPB();
		}
	}
	return 0;
}

void Odsek::izracunajBudzetISaf(int* budzISaf)
{
	for (auto i = studenti.begin(); i < studenti.end(); i++)
	{
		if (i->returnBudzet())
			budzISaf[0]++;
		else
			budzISaf[1]++;
	}
}
