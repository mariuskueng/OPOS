#pragma once
#include <string>

using namespace std;

class COP
{
public:
    COP(void);
    ~COP(void);
    
    int getID();
    string getText();
    double getBetrag();
    string getDatum();
    bool getBezahlt();
    int getKreditorID();
    int getFibuID();
    
	int m_iID;
    string m_sText;
    double m_dBetrag;
    string m_sDatum;
    bool m_bBezahlt;
    int m_iKreditorID;
    int m_iFibuID;



protected:
    
};
