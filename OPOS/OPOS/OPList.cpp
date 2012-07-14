#include <iostream>
#include <fstream>
#include "global.h"
#include "OPList.h"
#include "OP.h"
#include "Kreditor.h"

using namespace std;

COPList::COPList(void)
{
    m_iAnzahl = 0;
    
    LesenFile();
    
}
COPList::~COPList(void)
{
	SchreibenFile();
}
void COPList::LesenFile()
{
	string sLine;
    ifstream infile;
    infile.open("files/OP.txt");
    while (!infile.eof())
    {
		m_OP[m_iAnzahl] = new COP();
        getline(infile, sLine);
		m_OP[m_iAnzahl]->m_iID = atoi(Split(sLine, 1).c_str());
		m_OP[m_iAnzahl]->m_sDatum = Split(sLine, 2);
		m_OP[m_iAnzahl]->m_dBetrag = atoi(Split(sLine, 3).c_str());
		m_OP[m_iAnzahl]->m_iKreditorID = atoi(Split(sLine, 4).c_str());
		m_OP[m_iAnzahl]->m_iFibuID = atoi(Split(sLine, 5).c_str());
		m_OP[m_iAnzahl]->m_bBezahlt = atoi(Split(sLine, 6).c_str());
		m_OP[m_iAnzahl]->m_sText = Split(sLine, 7);
		m_iAnzahl++;
		//cout << iID << endl;
    }
    infile.close();
	m_iAnzahl--;//Zählt eine Instanz züruck, ansonsten würde es am Ende noch eine Leere schreiben da wir vorher um eine erhöht haben, diese aber nicht verwenden.
}

void COPList::AddOP(int iID, string sText, double dBetrag, string sDatum, bool bBezahlt, int iKreditorID, int iFibuID)
{
}


void COPList::Ausgabe(void)
{
    for (int x = 0; x < m_iAnzahl; x++)
    {
		cout << m_OP[x]->getID() << " " << m_OP[x]->getDatum() << " " << m_OP[x]->getBetrag() << " " << m_OP[x]->getKreditorID() << " " << m_OP[x]->getFibuID() << " " << m_OP[x]->getBezahlt() << " " << m_OP[x]->getText() << endl;
    }
    
}
void COPList::OffeneRechnungen(void)
{
	for (int x = 0; x < m_iAnzahl; x++)
    {
		if(m_OP[x]->getBezahlt()== 0)
		{
			cout << m_OP[x]->getID() << " " << m_OP[x]->getDatum() << " " << m_OP[x]->getBetrag() << " " << m_OP[x]->getKreditorID() << " " << m_OP[x]->getFibuID() << " " << m_OP[x]->getBezahlt() << " " << m_OP[x]->getText() << endl;
		}
	}
}
void COPList::Eingabe()
{
	int iID;
	string sText;
	double dBetrag;
	string sDatum; 
	bool bBezahlt; 
	int iKreditorID; 
	int iFibuID;

	iID = 0;
	cout << "Datum: ";
	cin >> sDatum;
	cout << "Betrag: ";
	cin >> dBetrag;
	cout << "KreditorID: ";
	cin >> iKreditorID;
	cout << "FibukontoID: ";
	cin >> iFibuID;
	cout << "bezahlt? (1/0): ";
	cin >> bBezahlt;
	cout << "Beschreibung: ";
	cin >> sText;
	cout << endl;
	
	m_LastID = m_iAnzahl+1;
	/*for (int x = 0; x < m_iAnzahl; x++)
    {
		if(x+1 == m_iAnzahl)
		{
			m_LastID = x+2;
		}
    }*/

	m_OP[m_iAnzahl] = new COP();
	m_OP[m_iAnzahl]->m_iID = m_LastID;
	m_OP[m_iAnzahl]->m_sDatum = sDatum;
	m_OP[m_iAnzahl]->m_dBetrag = dBetrag;
	m_OP[m_iAnzahl]->m_iKreditorID = iKreditorID;
	m_OP[m_iAnzahl]->m_iFibuID = iFibuID;
	m_OP[m_iAnzahl]->m_bBezahlt = bBezahlt;
	m_OP[m_iAnzahl]->m_sText = sText;
	m_iAnzahl++;
	/*SchreibenFile();*/
}

void COPList::SchreibenFile()
{
	fstream datei;
	datei.open("files/OP.txt", ios::in | ios::out /*| ios::ate*/);
	for (int x = 0; x < m_iAnzahl; x++)
    {
		datei << m_OP[x]->getID() << ";" << m_OP[x]->getDatum() << ";" << m_OP[x]->getBetrag() << ";" << m_OP[x]->getKreditorID() << ";" << m_OP[x]->getFibuID() << ";" << m_OP[x]->getBezahlt() << ";" << m_OP[x]->getText() << ";" << endl;
	}
	datei.close();
	cout << "Ihre Buchung wurde eingetragen." << endl << endl;
}

