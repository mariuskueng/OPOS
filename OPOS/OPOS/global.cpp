#include <string>

using namespace std;
string Split(string sText, int iFeld)
{
    int iPos = 0, iCount = 0;
    for (int i = 0; i < sText.length(); i++)
    {
        if (sText[i] == ';')
        {
            iCount++;
            if (iCount == iFeld)
            {
                return sText.substr(iPos, i - iPos);
            }        
            iPos = i + 1;
        }
    }
    return sText.substr(iPos, sText.length() - iPos);
}
