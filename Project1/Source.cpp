#include "Odsek.h"
#include "Student.h"
#include "Fakultet.h"

int main() {
	Fakultet& f = Fakultet::getInstance("Elektronski Fakultet", "01.01.1970");

	f.dodajOdsek("Racunarstvo i informatika", "RII");
	f.dodajOdsek("Elektroenergetika", "EEN");
	f.dodajOdsek("Elektronske komponente i mikrosistemi", "EKM");
	f.dodajOdsek("Elektronika", "ELK");
	f.dodajOdsek("Komunikacije i informacione tehnologije", "KIT");
	f.dodajOdsek("Upravljanje sistemima", "UPS");

	f.ucitajPredmeteIzFajla("predmeti.txt");
	// postoji i funkcija f.dodajPredmet(...)
	f.upisiStudenteIzFajla("studenti.txt");
	// postoji i funkcija f.dodajStudenta(...)

	f.prikaziInfo();
	f.prikaziInfoOdseka();
	f.prikaziInfoOStatusuFinansiranjaStudenata();

	f.prikaziPredmeteOdseka("RII");
	f.prikaziStudenteOdseka("RII");


	f.prikaziInfoStudenta("18010");

	f.prikaziPredmeteStudenta("18001");
	cout << "|" << f.vratiUkupanBrojESPBzaStudenta("18001") << "|";
	f.overiSemestarStudentu("18001");
	f.prikaziPredmeteStudenta("18001");
	cout << "|" << f.vratiUkupanBrojESPBzaStudenta("18001") << "|";


	f.izaberiIzborniPredmetStundentu("18001", "300RI2999");
	f.prikaziPredmeteStudenta("18001");
	f.zameniIzborniPredmetStudentu("18001", "300RI2999", "300RII100");
	f.prikaziPredmeteStudenta("18001");


}