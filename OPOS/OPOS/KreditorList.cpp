#include "KreditorList.h"
#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

CKreditorList::CKreditorList(void)
{
	m_iAnzahl = 0;
    
    LesenFile();
}

CKreditorList::~CKreditorList(void)
{
	SchreibenFile();
}
void CKreditorList::LesenFile()
{
	string sLine;
    ifstream infile;
    infile.open("files/Kreditoren.txt");
    while (!infile.eof())
    {
		m_Kreditor[m_iAnzahl] = new CKreditor();
        getline(infile, sLine);
		m_Kreditor[m_iAnzahl]->m_iID = atoi(Split(sLine, 1).c_str());
		int iID = m_Kreditor[m_iAnzahl]->m_iID;
		m_Kreditor[m_iAnzahl]->m_sName = Split(sLine, 2);
		m_iAnzahl++;
		//cout << iID << endl;
    }
    infile.close();
	m_iAnzahl--;
}

void CKreditorList::AddKreditor(int iID, string sName)
{
	//m_Kreditor[m_iAnzahl] = new CKreditor(iID, sName);
	//m_iAnzahl++;
}

void CKreditorList::Ausgabe(void)
{
	for (int x = 0; x < m_iAnzahl; x++)
    {
		cout << m_Kreditor[x]->getID() << " " << m_Kreditor[x]->getName()<< endl;
    }
}

void CKreditorList::Eingabe()
{
	int iID;
	string sName;
	cout << "KreditorID: ";
	cin >> iID;
	cout << "Beschreibung: ";
	cin >> sName;
	cout << endl;

	m_Kreditor[m_iAnzahl] = new CKreditor();
	m_Kreditor[m_iAnzahl]->m_iID = iID;
	m_Kreditor[m_iAnzahl]->m_sName = sName;
	m_iAnzahl++;

	
}

void CKreditorList::SchreibenFile()
{
	fstream datei;
	datei.open("files/Kreditoren.txt", ios::in | ios::out /*| ios::ate*/);
	for (int x = 0; x < m_iAnzahl; x++)
    {
		datei << m_Kreditor[x]->getID() << ";" << m_Kreditor[x]->getName() << ";" << endl;
	}
	datei.close();
	cout << "Ihr Kreditor wurde eingetragen." << endl << endl;
}
