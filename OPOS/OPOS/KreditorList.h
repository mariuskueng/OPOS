#pragma once
#include "Kreditor.h"

class CKreditorList
{
public:
    CKreditorList(void);
    ~CKreditorList(void);
	void Ausgabe(void);
    void LesenFile();
    void AddKreditor(int iID, string sName);
	void Eingabe(void);
	void SchreibenFile(void);


protected:
    CKreditor *m_Kreditor[100];
    int m_iAnzahl;
};
