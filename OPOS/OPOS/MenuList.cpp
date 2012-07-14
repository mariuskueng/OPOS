#include <iostream>
#include "MenuList.h"

using namespace std;

CMenuList::CMenuList(void)
{
    this->m_iAnzahl = 0;
}

CMenuList::~CMenuList(void)
{
}

void CMenuList::AddMenuItem(char cKey, string sText, void (*Funktion)())
{
    this->myMenuItemList[this->m_iAnzahl] =  new CMenuItem(cKey, sText, Funktion);
    this->m_iAnzahl++;   
}

void (*CMenuList::getMenuItemFunktion(char cKey))()
{
    for (int x = 0; x < this->m_iAnzahl; x++)
    {
        if (myMenuItemList[x]->getKey() == cKey)
            return myMenuItemList[x]->getFunktion();
    }

}

void CMenuList::Anzeigen()
{
    char iAuswahl = ' ';
    
    system("cls");
    cout << "M e n u e" << endl << endl;
    
    for (int x = 0; x < this->m_iAnzahl; x++)
    {
        myMenuItemList[x]->Ausgabe();
    }
    
    cout << endl << endl << "0   Beenden" << endl;
    
    cout << endl << "Bitte waehlen ";
    
    cin >> iAuswahl;
    
    if (iAuswahl == '0')
        return;
    else
    {
        getMenuItemFunktion(iAuswahl)();
        system("pause");
        this->Anzeigen();
    }
}
