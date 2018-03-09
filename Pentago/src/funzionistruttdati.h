#ifndef FUNZIONISTRUTTDATI_H_
#define FUNZIONISTRUTTDATI_H_

#include <stdio.h>
#include <stdlib.h>

#include "costanti.h"
#include "tipiutente.h"

void scrivere(campo,int,int,casella);
casella leggere(campo,int,int);
void cancellare(campo,int,int);
void azzerare(campo);
campo inizializzare();
int spostare_avanti(int);
int spostare_indietro(int);

#endif
