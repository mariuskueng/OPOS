#pragma once
#include "OP.h"

class COPList
{
public:
    COPList(void);
    ~COPList(void);
    
    void Ausgabe(void);
    void LesenFile();
    void AddOP(int iID, string sText, double dBetrag,string sDatum, bool bBezahlt, int iKreditorID, int iFibuID);
	void Eingabe(void);
	void SchreibenFile(void);
	void OffeneRechnungen(void);

	int m_LastID;


protected:
    COP *m_OP[100];
    int m_iAnzahl;
};
