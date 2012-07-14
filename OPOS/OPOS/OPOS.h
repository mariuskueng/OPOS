#pragma once
#include "OPList.h"
#include "KreditorList.h"
#include "FibuList.h"

COPList *myOPList;
CKreditorList *myKreditorList;
CFibuList *myFibuList;

void AusgabeOP();
void AusgabeKreditoren();
void AusgabeFibu();
void EingabeOP();
void EingabeKreditoren();
void EingabeFibu();
void AusgabeOffeneRechnungen();