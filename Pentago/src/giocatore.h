#ifndef GIOCATORE_H_
#define GIOCATORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "costanti.h"
#include "tipiutente.h"
#include "interfacciagrafica.h"

int acquisire_tasto_qualsiasi();
int controllare_tasto_cambia_impostazioni(int);
int controllare_tasto_regole(int);
int controllare_tasto_menu(int);
int controllare_tasto_posizionamento_pedina(int,int);
int controllare_tasto_campo_da_ruotare(int);
int controllare_tasto_verso_rotazione(int);
int controllare_tasto_menu_salvataggio(int);
booleano confermare_operazione(stringa);

#endif
