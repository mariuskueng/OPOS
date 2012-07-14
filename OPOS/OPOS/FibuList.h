#pragma once
#include "Fibu.h"
#include <iostream>
#include <fstream>
#include "global.h"
#include "FibuList.h"

using namespace std;

class CFibuList
{
public:
    CFibuList(void);
    ~CFibuList(void);
	
	void LesenFile();
    void AddFibu(int iID, string sBezeichnung);
	void Ausgabe(void);
	void Eingabe(void);
	void SchreibenFile(void);
    
protected:
    CFibu *m_Fibu[100];
    int m_iAnzahl;
    
    
};
