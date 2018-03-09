#ifndef INTERFACCIAGRAFICA_H_
#define INTERFACCIAGRAFICA_H_

#include <stdio.h>
#include <stdlib.h>

#include "costanti.h"
#include "tipiutente.h"
#include "file.h"

void stampare_menu(int);
void pulire_interfaccia();
void stampare_impostazioni(giocatore);
void stampare_logo();
void stampare_campo(campo,int,int);
void stampare_scelta_rotazione(int);
void stampare_slot_partite(int);

#endif
