#include <iostream>
#include "MenuItem.h"

using namespace std;

CMenuItem::CMenuItem()
{
    this->m_cKey = 0;
    this->m_sText = "";
}

CMenuItem::CMenuItem(char cKey, string sText, void (*Funktion)())
{
    this->m_cKey = cKey;
    this->m_sText = sText;
    this->m_Funktion = Funktion;
}

CMenuItem::~CMenuItem(void)
{
}
void CMenuItem::Ausgabe()
{
    cout << this->m_cKey << "   " << this->m_sText << endl;
}
char CMenuItem::getKey()
{
    return m_cKey;
}
void (*CMenuItem::getFunktion())()
{
    return m_Funktion;
}
