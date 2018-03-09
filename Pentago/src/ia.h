#ifndef IA_H_
#define IA_H_

#include <stdio.h>
#include <stdlib.h>

#include "costanti.h"
#include "tipiutente.h"
#include "partita.h"

insieme_campi_ruotati generare_campi_ruotati(campo);
campo copiare_campo(campo);
mossa_rotazione trovare_miglior_ruotato(campo);
coordinata trovare_casella_posizionabile(campo,pedina_verso,giocatore);
pedina_verso* trovare_coppie_pedine_consecutive(campo,giocatore);
coordinata scegliere_coppia(campo,giocatore);
coordinata posizionare_per_priorita(campo);

#endif
