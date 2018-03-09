#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "costanti.h"
#include "tipiutente.h"
#include "funzionistruttdati.h"

booleano verificare_esistenza_file(stringa);
void creare_file(stringa);
stringa leggere_imp_file(stringa);
void scrivere_imp_file(stringa,stringa);
void scrivere_file_partite(turno,campo,stringa);
stringa leggere_data_partita(stringa);
turno leggere_turno_gioco_partita(stringa);
campo leggere_campo_gioco_partita(stringa);

#endif
