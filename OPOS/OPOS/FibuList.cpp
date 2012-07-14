#include "FibuList.h"
#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

CFibuList::CFibuList(void)
{
	m_iAnzahl = 0;
    
    LesenFile();
}


CFibuList::~CFibuList(void)
{
	SchreibenFile();
}

void CFibuList::LesenFile()
{
	string sLine;
    ifstream infile;
    infile.open("files/Fibu.txt");
    while (!infile.eof())
    {
		m_Fibu[m_iAnzahl] = new CFibu();
        getline(infile, sLine);
		m_Fibu[m_iAnzahl]->m_iID = atoi(Split(sLine, 1).c_str());
		int iID = m_Fibu[m_iAnzahl]->m_iID;
		m_Fibu[m_iAnzahl]->m_sBezeichnung = Split(sLine, 2);
		m_iAnzahl++;
		//cout << iID << endl;
    }
    infile.close();
	m_iAnzahl--;
}
void CFibuList::Ausgabe()
{
	for (int x = 0; x < m_iAnzahl; x++)
    {
		cout << m_Fibu[x]->getID() << " " << m_Fibu[x]->getText()<< endl;
    }
}
void CFibuList::AddFibu(int iID, string sBezeichnung)
{
}
void CFibuList::Eingabe()
{
	int iID;
	string sName;
	cout << "FibuID: ";
	cin >> iID;
	cout << "Name: ";
	cin >> sName;
	cout << endl;

	m_Fibu[m_iAnzahl] = new CFibu();
	m_Fibu[m_iAnzahl]->m_iID = iID;
	m_Fibu[m_iAnzahl]->m_sBezeichnung = sName;
	m_iAnzahl++;	
}

void CFibuList::SchreibenFile()
{
	fstream datei;
	datei.open("files/fibu.txt", ios::in | ios::out /*| ios::ate*/);
	for (int x = 0; x < m_iAnzahl; x++)
    {
		datei << m_Fibu[x]->getID() << ";" << m_Fibu[x]->getText() << ";" << endl;
	}
	datei.close();
	cout << "Ihr Fibukonto wurde eingetragen." << endl << endl;
}
