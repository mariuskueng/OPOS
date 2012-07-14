#include "OP.h"

COP::COP(void)
{
}

COP::~COP(void)
{
}
int COP::getID()
{
    return this->m_iID;
}
string COP::getText()
{
    return this->m_sText;
}
double COP::getBetrag()
{
    return this->m_dBetrag;
}
string COP::getDatum()
{
    return this->m_sDatum;
}
bool COP::getBezahlt()
{
    return this->m_bBezahlt;
}
int COP::getKreditorID()
{
    return this->m_iKreditorID;
}
int COP::getFibuID()
{
    return this->m_iFibuID;
}
