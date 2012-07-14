#pragma once
#include "MenuItem.h"

class CMenuList
{
public:
    CMenuList(void);
    void AddMenuItem(char cKey, string sText,void (*Funktion)());
    ~CMenuList(void);
    
    void Anzeigen();
    
protected:
    CMenuItem *myMenuItemList[100];
    void (*getMenuItemFunktion(char cKey))();
    int m_iAnzahl;
};
