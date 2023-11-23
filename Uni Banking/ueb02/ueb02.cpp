#include <iostream>
#include <vector>

using namespace std;

#include "cdate.hpp"
#include "ctime.hpp"
#include "cmoney.hpp"
#include "caddress.hpp"
#include "caccount.hpp"
#include "ccustomer.hpp"

int ueb02()
{
   CTime Jetzt, SUBeginn(16, 0);
   CDate Heute, Geburtsdatum(7, 7, 1977);
   CMoney Startkapital(150.0);
   CAddress Adresse("Mustergasse 3a", "D - 99889", "Musterstadt");
   CCustomer Kunde(4711, "Egon Muster", Geburtsdatum, Adresse);
   //CAccount Konto1("DE99123456781234567890", &Kunde, Startkapital);

   cout << "Dieses Programm wurde am ";
   Heute.print();
   cout << " um ";
   Jetzt.print();
   cout << " gestartet." << endl << endl;

   cout << "Das Startkapital fuer alle Kunden betraegt ";
   Startkapital.print();
   cout << "." << endl << endl;

   cout << "Personenbezogene Daten des Bank-Kunden:" << endl;
   Kunde.print();
   cout << endl << endl;

   cout << "Daten des Konto 1:" << endl;
   //Konto1.print();
   cout << endl << endl;

   //CAccount Konto2("DE99876543210987654321", &Kunde, CMoney(100.0, "$"));

   cout << "Personenbezogene Daten des Bank-Kunden (ein Konto mehr):" << endl;
   Kunde.print();
   cout << endl << endl;

   cout << "Daten des Konto 2:" << endl;
   //Konto2.print();
   cout << endl << endl;

   return 0;
}
