#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>

#include "costanti.h"
#include "tipiutente.h"
#include "giocatore.h"
#include "partita.h"
#include "funzionistruttdati.h"
#include "impostazioni.h"
#include "interfacciagrafica.h"
#include "regolegioco.h"

void menu_principale();
booleano fine_gioco();
void regole_gioco();
void modifica_impostazioni();
void nuova_partita();
void carica_partita();

#endif
