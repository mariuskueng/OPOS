#pragma once
#include <string>

using namespace std;

class CMenuItem
{
public:
    CMenuItem();
    CMenuItem(char cKey, string sText, void (*Funktion)());
    ~CMenuItem(void);
    
    void Ausgabe();
    char getKey();
    void (*getFunktion())();

    
protected:
    char m_cKey;
    string m_sText;
    void (*m_Funktion)();
};
