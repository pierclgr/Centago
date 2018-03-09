#ifndef PARTITA_H_
#define PARTITA_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "costanti.h"
#include "tipiutente.h"
#include "giocatore.h"
#include "ia.h"
#include "file.h"
#include "funzionistruttdati.h"
#include "interfacciagrafica.h"

booleano contare_num_pedine_serie_orizzontali(campo,giocatore,int);
booleano contare_num_pedine_serie_verticali(campo,giocatore,int);
booleano contare_num_pedine_serie_obliquo_destra(campo,giocatore,int);
booleano contare_num_pedine_serie_obliquo_sinistra(campo,giocatore,int);
booleano contare_num_pedine_serie(campo,giocatore,int);
booleano controllare_fine_partita(campo,giocatore);
void giocare_partita(campo,turno);
booleano controllare_campo_pieno(campo);
void posizionare_pedina(campo,int,int,giocatore);
booleano controllare_casella_libera(campo,int,int);
void ruotare_campo(campo,verso_rotazione,int);
void salvare_partita();

#endif
