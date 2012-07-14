#include <iostream>
#include "OPOS.h"
#include "MenuList.h"
#include "OPList.h"
#include "KreditorList.h"
#include "FibuList.h"
#include "global.h"

int main()
{
    myOPList = new COPList();
	myKreditorList = new CKreditorList();
	myFibuList = new CFibuList();

    CMenuList myMenuList;
    myMenuList.AddMenuItem('1', "Ausgabe OP-Liste", &AusgabeOP);
	myMenuList.AddMenuItem('2', "Ausgabe Kreditor-Liste", &AusgabeKreditoren);
	myMenuList.AddMenuItem('3', "Ausgabe Fibukonten-Liste", &AusgabeFibu);
	myMenuList.AddMenuItem('4', "Eingabe Neue OP", &EingabeOP);
	myMenuList.AddMenuItem('5', "Eingabe Neuer Kreditor", &EingabeKreditoren);
	myMenuList.AddMenuItem('6', "Eingabe Neues Fibukonto", &EingabeFibu);
    myMenuList.AddMenuItem('7', "Ausgabe Offene Posten (bezahlt?)", &AusgabeOffeneRechnungen);
    myMenuList.Anzeigen();
	delete myOPList;
	delete myKreditorList;
	delete myFibuList;
	system("pause");
    return 0;
}
void AusgabeOP()
{
    myOPList->Ausgabe();
}
void AusgabeKreditoren()
{
	myKreditorList->Ausgabe();
}
void AusgabeFibu()
{
	myFibuList->Ausgabe();
}
void EingabeOP()
{
	myOPList->Eingabe();
}
void EingabeKreditoren()
{
	myKreditorList->Eingabe();
}
void EingabeFibu()
{
	myFibuList->Eingabe();
}
void AusgabeOffeneRechnungen()
{
	myOPList->OffeneRechnungen();
}

