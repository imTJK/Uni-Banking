#include <iostream>
#include <vector>

using namespace std;


#include "cdate.hpp"
#include "ctime.hpp"
#include "cmoney.hpp"
#include "caddress.hpp"
#include "caccount.hpp"
#include "ccurrentaccount.hpp"
#include "csavingsaccount.hpp"
#include "ccustomer.hpp"
#include "cbank.hpp"

int ueb03()
{
	CDate Geburtsdatum(7, 7, 1977);
	CMoney Startkapital(150.0);
	CMoney Dispo(250.0);
	double Zinsen = -2.5;
	CAddress Adresse("Mustergasse 3a", "D - 99889", "Musterstadt");

	// Egon, Anton und Paul sind Drillinge, die noch bei Mutti wohnen
	CCustomer Egon(4711, "Egon Muster", Geburtsdatum, Adresse);
	CCustomer Anton(815, "Anton Muster", Geburtsdatum, Adresse);
	CCustomer Paul(1234, "Paul Muster", Geburtsdatum, Adresse);

	CBank Spasskasse("Berliner Spasskasse", "BESPKADEXXX");
	CBank HochschulBank("Deutsche Hochschul-Bank", "DEHOBADEXXX");

	CAccount Konto1(&Spasskasse, "DE99123456781234567890", &Egon, Startkapital);
	CCurrentAccount Konto2(&HochschulBank, "DE99876543210987654321", &Egon, Startkapital, &Dispo);
	CSavingsAccount Konto3(&Spasskasse, "DE11223344556677889900", &Anton, Startkapital, Zinsen);
	CAccount Konto4(&HochschulBank, "DE99887766554433221100", &Paul, CMoney(100.0, "$"));

	cout << "Daten der Konten:" << endl << "=================" << endl << endl;
	cout << "Konto 1:" << endl; Konto1.print(); cout << endl << endl;
	cout << "Konto 2:" << endl; Konto2.print(); cout << endl << endl;
	cout << "Konto 3:" << endl; Konto3.print(); cout << endl << endl;
	cout << "Konto 4:" << endl; Konto4.print(); cout << endl << endl;
	cout << "Daten der Banken:" << endl << "=================" << endl << endl;
	cout << "Bank 1:" << endl; Spasskasse.print(); cout << endl << endl;
	cout << "Bank 2:" << endl; HochschulBank.print(); cout << endl << endl;

	return 0;
}