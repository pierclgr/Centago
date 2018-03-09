// @filename: simplified_cunit_template.c
// @rev: 0.1
// @date: 15-02-2015
// @desc: file modello per un main.c con il framework CUnit

#include <stdlib.h>
#include "CUnit/Basic.h"
#include "tipiutente.h"
#include "costanti.h"
#include "file.h"
#include "funzionistruttdati.h"
#include "giocatore.h"
#include "ia.h"
#include "impostazioni.h"
#include "interfacciagrafica.h"
#include "menu.h"
#include "partita.h"
#include "regolegioco.h"
/*
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */
void test_verificare_esistenza_file(void) {
	CU_ASSERT_EQUAL(FALSO,verificare_esistenza_file("vuoto.txt"));
	CU_ASSERT_EQUAL(VERO,verificare_esistenza_file("slot2.txt"));
	//falliscono
	CU_ASSERT_EQUAL(FALSO,verificare_esistenza_file("slot2.txt"));
	CU_ASSERT_EQUAL(VERO,verificare_esistenza_file("vuoto.txt"));
}

void test_leggere_imp_file(void) {
	CU_ASSERT_STRING_EQUAL("GIOCATORE",leggere_imp_file("pentago_impostazioni_default.txt"));
	CU_ASSERT_STRING_EQUAL("PC",leggere_imp_file("pentago_impostazioni_modificate.txt"));
	CU_ASSERT_STRING_EQUAL("",leggere_imp_file("pentago_prova.txt"));
	//falliscono
	CU_ASSERT_STRING_EQUAL("",leggere_imp_file("pentago_impostazioni_default.txt"));
	CU_ASSERT_STRING_EQUAL("",leggere_imp_file("pentago_impostazioni_modificate.txt"));
	CU_ASSERT_STRING_EQUAL("GIOCATORE",leggere_imp_file("pentago_impostazioni_modificate.txt"));
	CU_ASSERT_STRING_EQUAL("PC",leggere_imp_file("pentago_impostazioni_default.txt"));
	CU_ASSERT_STRING_EQUAL("PC",leggere_imp_file("pentago_prova.txt"));
	CU_ASSERT_STRING_EQUAL("GIOCATORE",leggere_imp_file("pentago_prova.txt"));
}

void test_leggere_data_partita(void) {
	CU_ASSERT_STRING_EQUAL("Wed Jun 08 17:58:16 2016",leggere_data_partita("slot2.txt"));
	CU_ASSERT_STRING_EQUAL("",leggere_data_partita("slot3.txt"));
	//falliscono
	CU_ASSERT_STRING_EQUAL("prova",leggere_data_partita("slot2.txt"));
	CU_ASSERT_STRING_EQUAL("Wed May 08 17:58:16 2016",leggere_data_partita("slot2.txt"));
	CU_ASSERT_STRING_EQUAL("Wed Jun 08 17:58:16 2016",leggere_data_partita("slot3.txt"));
	CU_ASSERT_STRING_EQUAL("",leggere_data_partita("slot2.txt"));
}

void test_leggere_turno_gioco_partita(void) {
	CU_ASSERT_EQUAL(GIOCATORE,leggere_turno_gioco_partita("slot2.txt").giocatore);
	CU_ASSERT_EQUAL(POSIZIONA,leggere_turno_gioco_partita("slot2.txt").mossa);
	CU_ASSERT_EQUAL(PC,leggere_turno_gioco_partita("slot1.txt").giocatore);
	CU_ASSERT_EQUAL(RUOTA,leggere_turno_gioco_partita("slot1.txt").mossa);
	//falliscono
	CU_ASSERT_EQUAL(GIOCATORE,leggere_turno_gioco_partita("slot1.txt").giocatore);
	CU_ASSERT_EQUAL(POSIZIONA,leggere_turno_gioco_partita("slot1.txt").mossa);
	CU_ASSERT_EQUAL(PC,leggere_turno_gioco_partita("slot2.txt").giocatore);
	CU_ASSERT_EQUAL(RUOTA,leggere_turno_gioco_partita("slot2.txt").mossa);
	CU_ASSERT_EQUAL(GIOCATORE,leggere_turno_gioco_partita("slot3.txt").giocatore);
	CU_ASSERT_EQUAL(POSIZIONA,leggere_turno_gioco_partita("slot3.txt").mossa);
	CU_ASSERT_EQUAL(PC,leggere_turno_gioco_partita("slot3.txt").giocatore);
	CU_ASSERT_EQUAL(RUOTA,leggere_turno_gioco_partita("slot3.txt").mossa);
}

void test_leggere_campo_gioco_partita(void) {
	CU_ASSERT_EQUAL(PEDINA_PC,leggere_campo_gioco_partita("slot2.txt")[0][0]);
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere_campo_gioco_partita("slot2.txt")[0][1]);
	CU_ASSERT_EQUAL(VUOTA,leggere_campo_gioco_partita("slot2.txt")[0][2]);
	CU_ASSERT_EQUAL(VUOTA,leggere_campo_gioco_partita("slot1.txt")[0][0]);
	CU_ASSERT_EQUAL(VUOTA,leggere_campo_gioco_partita("slot3.txt")[0][0]);
	//falliscono
	CU_ASSERT_EQUAL(PEDINA_PC,leggere_campo_gioco_partita("slot1.txt")[0][0]);
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere_campo_gioco_partita("slot1.txt")[0][0]);
	CU_ASSERT_EQUAL(VUOTA,leggere_campo_gioco_partita("slot2.txt")[0][0]);
	CU_ASSERT_EQUAL(VUOTA,leggere_campo_gioco_partita("slot2.txt")[0][1]);
	CU_ASSERT_EQUAL(PEDINA_PC,leggere_campo_gioco_partita("slot2.txt")[0][2]);
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere_campo_gioco_partita("slot2.txt")[0][2]);
	CU_ASSERT_EQUAL(PEDINA_PC,leggere_campo_gioco_partita("slot3.txt")[0][0]);
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere_campo_gioco_partita("slot3.txt")[0][0]);
}

void test_leggere(void) {
	CU_ASSERT_EQUAL(PEDINA_PC,leggere(leggere_campo_gioco_partita("slot2.txt"),0,0));
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere(leggere_campo_gioco_partita("slot2.txt"),0,1));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),0,2));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot1.txt"),0,0));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),-1,-1));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),-1,0));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),0,-1));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),0,40));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),40,0));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),40,40));
	//falliscono
	CU_ASSERT_EQUAL(PEDINA_PC,leggere(leggere_campo_gioco_partita("slot1.txt"),0,0));
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere(leggere_campo_gioco_partita("slot1.txt"),0,0));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),0,0));
	CU_ASSERT_EQUAL(VUOTA,leggere(leggere_campo_gioco_partita("slot2.txt"),0,1));
	CU_ASSERT_EQUAL(PEDINA_PC,leggere(leggere_campo_gioco_partita("slot2.txt"),0,2));
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere(leggere_campo_gioco_partita("slot2.txt"),0,2));
	CU_ASSERT_EQUAL(PEDINA_PC,leggere(leggere_campo_gioco_partita("slot2.txt"),-1,-1));
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere(leggere_campo_gioco_partita("slot2.txt"),-1,0));
	CU_ASSERT_EQUAL(PEDINA_PC,leggere(leggere_campo_gioco_partita("slot2.txt"),0,-1));
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere(leggere_campo_gioco_partita("slot2.txt"),0,40));
	CU_ASSERT_EQUAL(PEDINA_PC,leggere(leggere_campo_gioco_partita("slot2.txt"),40,0));
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere(leggere_campo_gioco_partita("slot2.txt"),40,40));
	CU_ASSERT_EQUAL(PEDINA_PC,leggere(leggere_campo_gioco_partita("slot3.txt"),0,0));
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,leggere(leggere_campo_gioco_partita("slot3.txt"),0,0));
}

void test_inizializzare(void) {
	CU_ASSERT_EQUAL(VUOTA,inizializzare()[0][0]);
	CU_ASSERT_EQUAL(VUOTA,inizializzare()[0][3]);
	CU_ASSERT_EQUAL(VUOTA,inizializzare()[3][1]);
	//falliscono
	CU_ASSERT_EQUAL(PEDINA_PC,inizializzare()[0][0]);
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,inizializzare()[0][3]);
	CU_ASSERT_EQUAL(PEDINA_PC,inizializzare()[3][2]);
	CU_ASSERT_EQUAL(PEDINA_GIOCATORE,inizializzare()[2][3]);
}

void test_spostare_avanti(void) {
	CU_ASSERT_EQUAL(4,spostare_avanti(3));
	CU_ASSERT_EQUAL(1,spostare_avanti(0));
	CU_ASSERT_EQUAL(0,spostare_avanti(-1));
	CU_ASSERT_EQUAL(6,spostare_avanti(5));
	CU_ASSERT_EQUAL(5,spostare_avanti(4));
	CU_ASSERT_EQUAL(40,spostare_avanti(39));
	CU_ASSERT_EQUAL(-19,spostare_avanti(-20));
	//falliscono
	CU_ASSERT_EQUAL(2,spostare_avanti(3));
	CU_ASSERT_EQUAL(-1,spostare_avanti(0));
	CU_ASSERT_EQUAL(-2,spostare_avanti(-1));
	CU_ASSERT_EQUAL(4,spostare_avanti(5));
	CU_ASSERT_EQUAL(3,spostare_avanti(4));
	CU_ASSERT_EQUAL(38,spostare_avanti(39));
	CU_ASSERT_EQUAL(-18,spostare_avanti(-17));
}

void test_spostare_indietro(void) {
	CU_ASSERT_EQUAL(2,spostare_indietro(3));
	CU_ASSERT_EQUAL(-1,spostare_indietro(0));
	CU_ASSERT_EQUAL(0,spostare_indietro(1));
	CU_ASSERT_EQUAL(6,spostare_indietro(7));
	CU_ASSERT_EQUAL(5,spostare_indietro(6));
	CU_ASSERT_EQUAL(38,spostare_indietro(39));
	CU_ASSERT_EQUAL(-21,spostare_indietro(-20));
	//falliscono
	CU_ASSERT_EQUAL(4,spostare_indietro(3));
	CU_ASSERT_EQUAL(1,spostare_indietro(0));
	CU_ASSERT_EQUAL(0,spostare_indietro(-1));
	CU_ASSERT_EQUAL(6,spostare_indietro(5));
	CU_ASSERT_EQUAL(5,spostare_indietro(4));
	CU_ASSERT_EQUAL(40,spostare_indietro(39));
	CU_ASSERT_EQUAL(-16,spostare_indietro(-17));
}

void test_acquisire_tasto_qualsiasi(void) {
	CU_ASSERT_EQUAL(FRECCIA_SU,acquisire_tasto_qualsiasi()); //premere freccia_su
	CU_ASSERT_EQUAL(FRECCIA_GIU,acquisire_tasto_qualsiasi()); //premere freccia_giu
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,acquisire_tasto_qualsiasi()); //premere freccia_destra
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,acquisire_tasto_qualsiasi()); //premere freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,acquisire_tasto_qualsiasi()); //premere invio
	CU_ASSERT_EQUAL(ESC,acquisire_tasto_qualsiasi()); //premere esc
	//falliscono
	CU_ASSERT_EQUAL(256,acquisire_tasto_qualsiasi()); //premere freccia_su
	CU_ASSERT_EQUAL(256,acquisire_tasto_qualsiasi()); //premere freccia_giu
	CU_ASSERT_EQUAL(256,acquisire_tasto_qualsiasi()); //premere freccia_destra
	CU_ASSERT_EQUAL(256,acquisire_tasto_qualsiasi()); //premere freccia_sinistra
	CU_ASSERT_EQUAL(256,acquisire_tasto_qualsiasi()); //premere invio
	CU_ASSERT_EQUAL(256,acquisire_tasto_qualsiasi()); //premere esc
}

void test_controllare_tasto_regole(void) {
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_regole(ID_SCHERMATA_REGOLE)); //freccia_destra
	CU_ASSERT_EQUAL(ESC,controllare_tasto_regole(ID_SCHERMATA_REGOLE)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_regole(ID_SCHERMATA_ISTRUZIONI)); //freccia_sinistra
	CU_ASSERT_EQUAL(ESC,controllare_tasto_regole(ID_SCHERMATA_ISTRUZIONI)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_regole(ID_SCHERMATA_REGOLE-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_regole(ID_SCHERMATA_ISTRUZIONI+1));
	//falliscono
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_regole(ID_SCHERMATA_REGOLE)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_regole(ID_SCHERMATA_REGOLE)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_regole(ID_SCHERMATA_ISTRUZIONI)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_regole(ID_SCHERMATA_ISTRUZIONI)); //esc
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_regole(ID_SCHERMATA_REGOLE-1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_regole(ID_SCHERMATA_REGOLE-1));
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_regole(ID_SCHERMATA_ISTRUZIONI+1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_regole(ID_SCHERMATA_ISTRUZIONI+1));
}

void test_controllare_tasto_cambia_impostazioni(void){
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_cambia_impostazioni(FRECCIA_DESTRA)); //freccia_sinistra
	CU_ASSERT_EQUAL(ESC,controllare_tasto_cambia_impostazioni(FRECCIA_DESTRA)); //esc
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_cambia_impostazioni(FRECCIA_SINISTRA)); //freccia_destra
	CU_ASSERT_EQUAL(ESC,controllare_tasto_cambia_impostazioni(FRECCIA_SINISTRA)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_cambia_impostazioni(FRECCIA_DESTRA+1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_cambia_impostazioni(FRECCIA_SINISTRA-1));
	//falliscono
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_cambia_impostazioni(FRECCIA_DESTRA)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_cambia_impostazioni(FRECCIA_DESTRA)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_cambia_impostazioni(FRECCIA_SINISTRA)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_cambia_impostazioni(FRECCIA_SINISTRA)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_cambia_impostazioni(FRECCIA_DESTRA+1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_cambia_impostazioni(FRECCIA_DESTRA+1));
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_cambia_impostazioni(FRECCIA_SINISTRA-1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_cambia_impostazioni(FRECCIA_SINISTRA-1));
}

void test_controllare_tasto_menu(void){
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_menu(ID_PRIMA_VOCE_MENU)); //freccia_giu
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu(ID_PRIMA_VOCE_MENU)); //invio
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_menu(ID_QUINTA_VOCE_MENU)); //freccia_su
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu(ID_QUINTA_VOCE_MENU)); //invio
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_menu(ID_TERZA_VOCE_MENU)); //freccia_su
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_menu(ID_TERZA_VOCE_MENU)); //freccia_giu
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu(ID_TERZA_VOCE_MENU)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_PRIMA_VOCE_MENU-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_QUINTA_VOCE_MENU+1));
	//falliscono
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_PRIMA_VOCE_MENU)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_PRIMA_VOCE_MENU)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_QUINTA_VOCE_MENU)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_QUINTA_VOCE_MENU)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_TERZA_VOCE_MENU)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_TERZA_VOCE_MENU)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu(ID_TERZA_VOCE_MENU)); //invio
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_menu(ID_PRIMA_VOCE_MENU-1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu(ID_PRIMA_VOCE_MENU-1));
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_menu(ID_QUINTA_VOCE_MENU+1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu(ID_QUINTA_VOCE_MENU+1));
}

void test_controllare_tasto_posizionamento_pedina(void){
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //esc

	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //esc

	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //esc

	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA-1,ID_PRIMA_RIGA_COLONNA));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA-1,ID_PRIMA_RIGA_COLONNA-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA-1,ID_SESTA_RIGA_COLONNA));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA-1,ID_SESTA_RIGA_COLONNA+1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA+1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA+1,ID_PRIMA_RIGA_COLONNA));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA+1,ID_PRIMA_RIGA_COLONNA-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA+1,ID_SESTA_RIGA_COLONNA));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA+1,ID_SESTA_RIGA_COLONNA+1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA+1));
	//falliscono
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)); //esc

	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)); //esc

	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_posizionamento_pedina(ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)); //esc

	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA-1,ID_PRIMA_RIGA_COLONNA));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA-1,ID_PRIMA_RIGA_COLONNA-1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA-1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA-1,ID_SESTA_RIGA_COLONNA));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA-1,ID_SESTA_RIGA_COLONNA+1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA+1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA+1,ID_PRIMA_RIGA_COLONNA));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA+1,ID_PRIMA_RIGA_COLONNA-1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA-1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA+1,ID_SESTA_RIGA_COLONNA));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA+1,ID_SESTA_RIGA_COLONNA+1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_posizionamento_pedina(ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA+1));
}

void test_controllare_tasto_campo_da_ruotare(void){
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE)); //freccia_destra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE)); //esc
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_campo_da_ruotare(ID_SECONDA_SEZIONE)); //freccia_destra
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_campo_da_ruotare(ID_SECONDA_SEZIONE)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_campo_da_ruotare(ID_SECONDA_SEZIONE)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_campo_da_ruotare(ID_SECONDA_SEZIONE)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE+1));
	//falliscono
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_SECONDA_SEZIONE)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_SECONDA_SEZIONE)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_SECONDA_SEZIONE)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_campo_da_ruotare(ID_SECONDA_SEZIONE)); //esc
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE-1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE-1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_campo_da_ruotare(ID_PRIMA_SEZIONE-1));
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE+1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE+1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_campo_da_ruotare(ID_QUARTA_SEZIONE+1));
}

void test_controllare_tasto_verso_rotazione(void){
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_verso_rotazione(ID_RUOTA_SX)); //freccia_destra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_verso_rotazione(ID_RUOTA_SX)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_verso_rotazione(ID_RUOTA_SX)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_verso_rotazione(ID_RUOTA_DX)); //freccia_sinistra
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_verso_rotazione(ID_RUOTA_DX)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_verso_rotazione(ID_RUOTA_DX)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_verso_rotazione(ID_RUOTA_SX-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_verso_rotazione(ID_RUOTA_DX+1));
	//falliscono
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_verso_rotazione(ID_RUOTA_SX)); //freccia_destra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_verso_rotazione(ID_RUOTA_SX)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_verso_rotazione(ID_RUOTA_SX)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_verso_rotazione(ID_RUOTA_DX)); //freccia_sinistra
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_verso_rotazione(ID_RUOTA_DX)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_verso_rotazione(ID_RUOTA_DX)); //esc
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_verso_rotazione(ID_RUOTA_SX-1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_verso_rotazione(ID_RUOTA_SX-1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_verso_rotazione(ID_RUOTA_SX-1));
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_verso_rotazione(ID_RUOTA_DX+1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_verso_rotazione(ID_RUOTA_DX+1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_verso_rotazione(ID_RUOTA_DX+1));
}

void test_controllare_tasto_menu_salvataggio(void){
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT)); //freccia_giu
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT)); //freccia_su
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT)); //esc
	CU_ASSERT_EQUAL(FRECCIA_SU,controllare_tasto_menu_salvataggio(ID_QUINTO_SLOT)); //freccia_su
	CU_ASSERT_EQUAL(FRECCIA_GIU,controllare_tasto_menu_salvataggio(ID_QUINTO_SLOT)); //freccia_giu
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu_salvataggio(ID_QUINTO_SLOT)); //invio
	CU_ASSERT_EQUAL(ESC,controllare_tasto_menu_salvataggio(ID_QUINTO_SLOT)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT-1));
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT+1));
	//falliscono
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT)); //esc
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_QUINTO_SLOT)); //freccia_su
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_QUINTO_SLOT)); //freccia_giu
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_QUINTO_SLOT)); //invio
	CU_ASSERT_EQUAL(ERRORE,controllare_tasto_menu_salvataggio(ID_QUINTO_SLOT)); //esc
	CU_ASSERT_EQUAL(FRECCIA_DESTRA,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT-1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT-1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_menu_salvataggio(ID_PRIMO_SLOT-1));
	CU_ASSERT_EQUAL(FRECCIA_SINISTRA,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT+1));
	CU_ASSERT_EQUAL(INVIO,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT+1));
	CU_ASSERT_EQUAL(ESC,controllare_tasto_menu_salvataggio(ID_DECIMO_SLOT+1));
}

void test_confermare_operazione(void){
	CU_ASSERT_EQUAL(FALSO,confermare_operazione("")); //n
	CU_ASSERT_EQUAL(VERO,confermare_operazione("")); //v
	//falliscono
	CU_ASSERT_EQUAL(VERO,confermare_operazione("")); //n
	CU_ASSERT_EQUAL(FALSO,confermare_operazione("")); //v
}

void test_generare_campi_ruotati(void){
	CU_ASSERT_NOT_EQUAL(NULL,generare_campi_ruotati(leggere_campo_gioco_partita("slot2.txt")));
	CU_ASSERT_NOT_EQUAL(NULL,generare_campi_ruotati(leggere_campo_gioco_partita("slot1.txt")));
	//falliscono
	CU_ASSERT_EQUAL(NULL,generare_campi_ruotati(leggere_campo_gioco_partita("slot2.txt")));
	CU_ASSERT_EQUAL(NULL,generare_campi_ruotati(leggere_campo_gioco_partita("slot1.txt")));
}

void test_copiare_campo(void){
	CU_ASSERT_NOT_EQUAL(NULL,copiare_campo(leggere_campo_gioco_partita("slot2.txt")));
	CU_ASSERT_NOT_EQUAL(NULL,copiare_campo(leggere_campo_gioco_partita("slot1.txt")));
	CU_ASSERT_EQUAL(leggere_campo_gioco_partita("slot2.txt")[0][0],copiare_campo(leggere_campo_gioco_partita("slot2.txt"))[0][0]);
	CU_ASSERT_EQUAL(leggere_campo_gioco_partita("slot2.txt")[1][0],copiare_campo(leggere_campo_gioco_partita("slot2.txt"))[1][0]);
	CU_ASSERT_EQUAL(leggere_campo_gioco_partita("slot2.txt")[5][5],copiare_campo(leggere_campo_gioco_partita("slot2.txt"))[5][5]);
	//falliscono
	CU_ASSERT_EQUAL(NULL,copiare_campo(leggere_campo_gioco_partita("slot2.txt")));
	CU_ASSERT_EQUAL(NULL,copiare_campo(leggere_campo_gioco_partita("slot1.txt")));
	CU_ASSERT_NOT_EQUAL(leggere_campo_gioco_partita("slot2.txt")[0][0],copiare_campo(leggere_campo_gioco_partita("slot2.txt"))[0][0]);
	CU_ASSERT_NOT_EQUAL(leggere_campo_gioco_partita("slot2.txt")[1][0],copiare_campo(leggere_campo_gioco_partita("slot2.txt"))[1][0]);
	CU_ASSERT_NOT_EQUAL(leggere_campo_gioco_partita("slot2.txt")[5][5],copiare_campo(leggere_campo_gioco_partita("slot2.txt"))[5][5]);
}

void test_trovare_miglior_ruotato(void){
	CU_ASSERT_EQUAL(ID_PRIMA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot1.txt")).num_campo);
	CU_ASSERT_EQUAL(DX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot1.txt")).verso);
	CU_ASSERT_EQUAL(ID_SECONDA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot6.txt")).num_campo);
	CU_ASSERT_EQUAL(SX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot6.txt")).verso);
	CU_ASSERT_EQUAL(ID_SECONDA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot7.txt")).num_campo);
	CU_ASSERT_EQUAL(DX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot7.txt")).verso);
	CU_ASSERT_EQUAL(ID_SECONDA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot5.txt")).num_campo);
	CU_ASSERT_EQUAL(DX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot5.txt")).verso);
	CU_ASSERT_EQUAL(ID_SECONDA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot8.txt")).num_campo);
	CU_ASSERT_EQUAL(SX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot8.txt")).verso);
	//falliscono
	CU_ASSERT_EQUAL(ID_SECONDA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot1.txt")).num_campo);
	CU_ASSERT_EQUAL(SX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot1.txt")).verso);
	CU_ASSERT_EQUAL(ID_TERZA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot6.txt")).num_campo);
	CU_ASSERT_EQUAL(DX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot6.txt")).verso);
	CU_ASSERT_EQUAL(ID_QUARTA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot7.txt")).num_campo);
	CU_ASSERT_EQUAL(SX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot7.txt")).verso);
	CU_ASSERT_EQUAL(ID_TERZA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot5.txt")).num_campo);
	CU_ASSERT_EQUAL(SX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot5.txt")).verso);
	CU_ASSERT_EQUAL(ID_PRIMA_SEZIONE,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot8.txt")).num_campo);
	CU_ASSERT_EQUAL(DX,trovare_miglior_ruotato(leggere_campo_gioco_partita("slot8.txt")).verso);
}

void test_trovare_casella_posizionabile(void){
	pedina_verso coppia;
	coppia.coordinata.x=0;
	coppia.coordinata.y=5;
	coppia.verso=VERTICALE;
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).x);
	CU_ASSERT_EQUAL(5,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).y);
	coppia.coordinata.x=0;
	coppia.coordinata.y=1;
	coppia.verso=ORIZZONTALE;
	CU_ASSERT_EQUAL(0,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).x);
	CU_ASSERT_EQUAL(3,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).y);
	coppia.coordinata.x=0;
	coppia.coordinata.y=5;
	coppia.verso=VERTICALE;
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).x);
	CU_ASSERT_EQUAL(5,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).y);
	coppia.coordinata.x=0;
	coppia.coordinata.y=1;
	coppia.verso=ORIZZONTALE;
	CU_ASSERT_EQUAL(0,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).x);
	CU_ASSERT_EQUAL(3,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).y);
	coppia.coordinata.x=4;
	coppia.coordinata.y=4;
	coppia.verso=SINISTRA;
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).x);
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).y);
	coppia.coordinata.x=4;
	coppia.coordinata.y=4;
	coppia.verso=SINISTRA;
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).x);
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).y);
	coppia.coordinata.x=0;
	coppia.coordinata.y=5;
	coppia.verso=DESTRA;
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot5.txt"),coppia,GIOCATORE).x);
	CU_ASSERT_EQUAL(3,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot5.txt"),coppia,GIOCATORE).y);
	//falliscono
	coppia.coordinata.x=0;
	coppia.coordinata.y=5;
	coppia.verso=VERTICALE;
	CU_ASSERT_EQUAL(4,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).x);
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).y);
	coppia.coordinata.x=0;
	coppia.coordinata.y=1;
	coppia.verso=ORIZZONTALE;
	CU_ASSERT_EQUAL(1,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).x);
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).y);
	coppia.coordinata.x=0;
	coppia.coordinata.y=5;
	coppia.verso=VERTICALE;
	CU_ASSERT_EQUAL(5,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).x);
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).y);
	coppia.coordinata.x=0;
	coppia.coordinata.y=1;
	coppia.verso=ORIZZONTALE;
	CU_ASSERT_EQUAL(1,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).x);
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).y);
	coppia.coordinata.x=4;
	coppia.coordinata.y=4;
	coppia.verso=SINISTRA;
	CU_ASSERT_EQUAL(1,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).x);
	CU_ASSERT_EQUAL(0,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot7.txt"),coppia,GIOCATORE).y);
	coppia.coordinata.x=4;
	coppia.coordinata.y=4;
	coppia.verso=SINISTRA;
	CU_ASSERT_EQUAL(1,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).x);
	CU_ASSERT_EQUAL(1,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot6.txt"),coppia,PC).y);
	coppia.coordinata.x=0;
	coppia.coordinata.y=5;
	coppia.verso=DESTRA;
	CU_ASSERT_EQUAL(3,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot5.txt"),coppia,GIOCATORE).x);
	CU_ASSERT_EQUAL(2,trovare_casella_posizionabile(leggere_campo_gioco_partita("slot5.txt"),coppia,GIOCATORE).y);
}

void test_trovare_coppie_pedine_consecutive(void){
	CU_ASSERT_EQUAL(ERRORE,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot1.txt"),PC)[0].coordinata.y);
	CU_ASSERT_EQUAL(ERRORE,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot1.txt"),GIOCATORE)[0].coordinata.y);
	CU_ASSERT_EQUAL(0,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[0].coordinata.y);
	CU_ASSERT_EQUAL(1,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[1].coordinata.y);
	CU_ASSERT_EQUAL(0,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[2].coordinata.x);
	CU_ASSERT_EQUAL(3,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[3].coordinata.y);
	CU_ASSERT_EQUAL(4,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[4].coordinata.x);
	CU_ASSERT_EQUAL(0,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[0].coordinata.y);
	CU_ASSERT_EQUAL(1,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[1].coordinata.y);
	CU_ASSERT_EQUAL(0,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[2].coordinata.x);
	CU_ASSERT_EQUAL(3,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[3].coordinata.y);
	CU_ASSERT_EQUAL(4,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[4].coordinata.x);
	CU_ASSERT_EQUAL(2,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot5.txt"),GIOCATORE)[2].coordinata.y);
	CU_ASSERT_EQUAL(4,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot5.txt"),GIOCATORE)[3].coordinata.x);
	//falliscono
	CU_ASSERT_EQUAL(0,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot1.txt"),PC)[0].coordinata.y);
	CU_ASSERT_EQUAL(0,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot1.txt"),GIOCATORE)[0].coordinata.y);
	CU_ASSERT_EQUAL(1,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[0].coordinata.y);
	CU_ASSERT_EQUAL(0,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[1].coordinata.y);
	CU_ASSERT_EQUAL(1,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[2].coordinata.x);
	CU_ASSERT_EQUAL(2,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[3].coordinata.y);
	CU_ASSERT_EQUAL(3,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot6.txt"),PC)[4].coordinata.x);
	CU_ASSERT_EQUAL(1,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[0].coordinata.y);
	CU_ASSERT_EQUAL(0,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[1].coordinata.y);
	CU_ASSERT_EQUAL(1,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[2].coordinata.x);
	CU_ASSERT_EQUAL(2,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[3].coordinata.y);
	CU_ASSERT_EQUAL(3,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE)[4].coordinata.x);
	CU_ASSERT_EQUAL(ERRORE,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot5.txt"),GIOCATORE)[2].coordinata.y);
	CU_ASSERT_EQUAL(3,trovare_coppie_pedine_consecutive(leggere_campo_gioco_partita("slot5.txt"),GIOCATORE)[3].coordinata.x);
}

void test_scegliere_coppia(void){
	CU_ASSERT_EQUAL(3,scegliere_coppia(leggere_campo_gioco_partita("slot5.txt"),GIOCATORE).y);
	CU_ASSERT_EQUAL(3,scegliere_coppia(leggere_campo_gioco_partita("slot8.txt"),PC).y);
	CU_ASSERT_EQUAL(3,scegliere_coppia(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE).y);
	//falliscono
	CU_ASSERT_EQUAL(5,scegliere_coppia(leggere_campo_gioco_partita("slot5.txt"),GIOCATORE).y);
	CU_ASSERT_EQUAL(5,scegliere_coppia(leggere_campo_gioco_partita("slot8.txt"),PC).y);
	CU_ASSERT_EQUAL(5,scegliere_coppia(leggere_campo_gioco_partita("slot7.txt"),GIOCATORE).y);
}

void test_posizionare_per_priorita(void){
	CU_ASSERT_EQUAL(ID_SECONDA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot7.txt")).x);
	CU_ASSERT_EQUAL(ID_SECONDA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot7.txt")).y);
	CU_ASSERT_EQUAL(ID_SECONDA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot8.txt")).x);
	CU_ASSERT_EQUAL(ID_SECONDA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot8.txt")).y);
	CU_ASSERT_EQUAL(ID_QUINTA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot2.txt")).x);
	CU_ASSERT_EQUAL(ID_QUINTA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot2.txt")).y);
	//falliscono
	CU_ASSERT_EQUAL(ID_QUINTA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot7.txt")).x);
	CU_ASSERT_EQUAL(ID_QUINTA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot7.txt")).y);
	CU_ASSERT_EQUAL(ID_QUINTA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot8.txt")).x);
	CU_ASSERT_EQUAL(ID_QUINTA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot8.txt")).y);
	CU_ASSERT_EQUAL(ID_SECONDA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot2.txt")).x);
	CU_ASSERT_EQUAL(ID_SECONDA_RIGA_COLONNA,posizionare_per_priorita(leggere_campo_gioco_partita("slot2.txt")).y);
}

void test_leggere_imp(void){
	CU_ASSERT_EQUAL(GIOCATORE,leggere_imp());
	//falliscono
	CU_ASSERT_EQUAL(PC,leggere_imp());
}

void test_fine_gioco(void){
	CU_ASSERT_EQUAL(VERO,fine_gioco());
	//falliscono
	CU_ASSERT_EQUAL(FALSO,fine_gioco());
}

void test_contare_num_pedine_serie_orizzontali(void){
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,1));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,6));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,1));
	//falliscono
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,1));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),PC,6));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_orizzontali(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,1));
}

void test_contare_num_pedine_serie_verticali(void){
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,1));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,6));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,1));
	//falliscono
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,1));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,6));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_verticali(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE,1));
}

void test_contare_num_pedine_serie_obliquo_destra(void){
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,1));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,6));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,1));
	//falliscono
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,1));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,6));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_destra(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,1));
}

void test_contare_num_pedine_serie_obliquo_sinistra(void){
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,1));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,6));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,1));
	//falliscono
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,1));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,6));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie_obliquo_sinistra(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,1));
}

void test_contare_num_pedine_serie(void){
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xverticali.txt"),PC,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10.txt"),PC,2));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10.txt"),PC,6));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xverticale.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,2));
	//falliscono
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC,5));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC,4));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xverticale.txt"),PC,3));
	CU_ASSERT_EQUAL(FALSO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10.txt"),PC,2));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10.txt"),PC,ZERO_PEDINE));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10.txt"),PC,6));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE,5));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE,4));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10xverticale.txt"),GIOCATORE,3));
	CU_ASSERT_EQUAL(VERO,contare_num_pedine_serie(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE,2));
}

void test_controllare_fine_partita(void){
	CU_ASSERT_EQUAL(VERO,controllare_fine_partita(leggere_campo_gioco_partita("slot10.txt"),PC));
	CU_ASSERT_EQUAL(VERO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xverticali.txt"),PC));
	CU_ASSERT_EQUAL(VERO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC));
	CU_ASSERT_EQUAL(VERO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC));
	CU_ASSERT_EQUAL(FALSO,controllare_fine_partita(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE));
	CU_ASSERT_EQUAL(FALSO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE));
	CU_ASSERT_EQUAL(FALSO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE));
	CU_ASSERT_EQUAL(FALSO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE));
	//falliscono
	CU_ASSERT_EQUAL(FALSO,controllare_fine_partita(leggere_campo_gioco_partita("slot10.txt"),PC));
	CU_ASSERT_EQUAL(FALSO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xverticali.txt"),PC));
	CU_ASSERT_EQUAL(FALSO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xobliquosx.txt"),PC));
	CU_ASSERT_EQUAL(FALSO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xobliquodx.txt"),PC));
	CU_ASSERT_EQUAL(VERO,controllare_fine_partita(leggere_campo_gioco_partita("slot10.txt"),GIOCATORE));
	CU_ASSERT_EQUAL(VERO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xverticali.txt"),GIOCATORE));
	CU_ASSERT_EQUAL(VERO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xobliquosx.txt"),GIOCATORE));
	CU_ASSERT_EQUAL(VERO,controllare_fine_partita(leggere_campo_gioco_partita("slot10xobliquodx.txt"),GIOCATORE));
}

void test_controllare_campo_pieno(void){
	CU_ASSERT_EQUAL(VERO,controllare_campo_pieno(leggere_campo_gioco_partita("slot1campopieno.txt")));
	CU_ASSERT_EQUAL(FALSO,controllare_campo_pieno(leggere_campo_gioco_partita("slot10.txt")));
	//falliscono
	CU_ASSERT_EQUAL(FALSO,controllare_campo_pieno(leggere_campo_gioco_partita("slot1campopieno.txt")));
	CU_ASSERT_EQUAL(VERO,controllare_campo_pieno(leggere_campo_gioco_partita("slot10.txt")));
}

void test_controllare_casella_libera(void){
	CU_ASSERT_EQUAL(FALSO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),0,0));
	CU_ASSERT_EQUAL(VERO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),0,3));
	CU_ASSERT_EQUAL(VERO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),-1,3));
	CU_ASSERT_EQUAL(VERO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),-1,-1));
	CU_ASSERT_EQUAL(VERO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),3,-1));
	CU_ASSERT_EQUAL(VERO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),6,3));
	CU_ASSERT_EQUAL(VERO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),6,6));
	CU_ASSERT_EQUAL(VERO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),3,6));
	//falliscono
	CU_ASSERT_EQUAL(VERO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),0,0));
	CU_ASSERT_EQUAL(FALSO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),0,3));
	CU_ASSERT_EQUAL(FALSO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),-1,3));
	CU_ASSERT_EQUAL(FALSO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),-1,-1));
	CU_ASSERT_EQUAL(FALSO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),3,-1));
	CU_ASSERT_EQUAL(FALSO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),6,3));
	CU_ASSERT_EQUAL(FALSO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),6,6));
	CU_ASSERT_EQUAL(FALSO,controllare_casella_libera(leggere_campo_gioco_partita("slot7.txt"),3,6));
}

/*
 * Funzioni di inizializzazione e pulizia delle suite.
 * Di default sono funzioni vuote.
 */
int init_suite_default(void) {
	return 0;
}

int clean_suite_default(void) {
	return 0;
}


/* **************************************************
 *	TEST di UNITA'
 */

int main() {
	/* inizializza registro - e' la prima istruzione */
	CU_initialize_registry();

	/* Aggiungi le suite al test registry */
	CU_pSuite pSuite_File = CU_add_suite("Suite_File", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_FunzioniStruttDati = CU_add_suite("Suite_FunzioniStruttDati", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Giocatore = CU_add_suite("Suite_Giocatore", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_IA = CU_add_suite("Suite_IA", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Impostazioni = CU_add_suite("Suite_Impostazioni", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Menu = CU_add_suite("Suite_Menu", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_Partita = CU_add_suite("Suite_Partita", init_suite_default, clean_suite_default);

	/* Aggiungi i test alle suite
	 * NOTA - L'ORDINE DI INSERIMENTO E' IMPORTANTE
	 */
	CU_add_test(pSuite_File, "test of verificare_esistenza_file()", test_verificare_esistenza_file);
	CU_add_test(pSuite_File, "test of leggere_imp_file()", test_leggere_imp_file);
	CU_add_test(pSuite_File, "test of leggere_data_partita()", test_leggere_data_partita);
	CU_add_test(pSuite_File, "test of leggere_turno_gioco_partita()", test_leggere_turno_gioco_partita);
	CU_add_test(pSuite_File, "test of leggere_campo_gioco_partita()", test_leggere_campo_gioco_partita);

	CU_add_test(pSuite_FunzioniStruttDati, "test of leggere()", test_leggere);
	CU_add_test(pSuite_FunzioniStruttDati, "test of inizializzare()", test_inizializzare);
	CU_add_test(pSuite_FunzioniStruttDati, "test of spostare_avanti()", test_spostare_avanti);
	CU_add_test(pSuite_FunzioniStruttDati, "test of spostare_indietro()", test_spostare_indietro);

	CU_add_test(pSuite_Giocatore, "test of acquisire_tasto_qualsiasi()", test_acquisire_tasto_qualsiasi);
	CU_add_test(pSuite_Giocatore, "test of controllare_tasto_regole()", test_controllare_tasto_regole);
	CU_add_test(pSuite_Giocatore, "test of controllare_tasto_cambia_impostazioni()", test_controllare_tasto_cambia_impostazioni);
	CU_add_test(pSuite_Giocatore, "test of controllare_tasto_menu()", test_controllare_tasto_menu);
	CU_add_test(pSuite_Giocatore, "test of controllare_tasto_posizionamento_pedina()", test_controllare_tasto_posizionamento_pedina);
	CU_add_test(pSuite_Giocatore, "test of controllare_tasto_campo_da_ruotare()", test_controllare_tasto_campo_da_ruotare);
	CU_add_test(pSuite_Giocatore, "test of controllare_tasto_verso_rotazione()", test_controllare_tasto_verso_rotazione);
	CU_add_test(pSuite_Giocatore, "test of controllare_tasto_menu_salvataggio()", test_controllare_tasto_menu_salvataggio);
	CU_add_test(pSuite_Giocatore, "test of confermare_operazione()", test_confermare_operazione);

	CU_add_test(pSuite_IA, "test of generare_campi_ruotati()", test_generare_campi_ruotati);
	CU_add_test(pSuite_IA, "test of copiare_campo()", test_copiare_campo);
	CU_add_test(pSuite_IA, "test of trovare_miglior_ruotato()", test_trovare_miglior_ruotato);
	CU_add_test(pSuite_IA, "test of trovare_casella_posizionabile()", test_trovare_casella_posizionabile);
	CU_add_test(pSuite_IA, "test of trovare_coppie_pedine_consecutive()", test_trovare_coppie_pedine_consecutive);
	CU_add_test(pSuite_IA, "test of scegliere_coppia()", test_scegliere_coppia);
	CU_add_test(pSuite_IA, "test of posizionare_per_priorita()", test_posizionare_per_priorita);

	CU_add_test(pSuite_Impostazioni, "test of leggere_imp()", test_leggere_imp);

	CU_add_test(pSuite_Menu, "test of fine_gioco()", test_fine_gioco);

	CU_add_test(pSuite_Partita, "test of contare_num_pedine_serie_orizzontali()", test_contare_num_pedine_serie_orizzontali);
	CU_add_test(pSuite_Partita, "test of contare_num_pedine_serie_verticali()", test_contare_num_pedine_serie_verticali);
	CU_add_test(pSuite_Partita, "test of contare_num_pedine_serie_obliquo_destra()", test_contare_num_pedine_serie_obliquo_destra);
	CU_add_test(pSuite_Partita, "test of contare_num_pedine_serie_obliquo_sinistra()", test_contare_num_pedine_serie_obliquo_sinistra);
	CU_add_test(pSuite_Partita, "test of contare_num_pedine_serie()", test_contare_num_pedine_serie);
	CU_add_test(pSuite_Partita, "test of controllare_fine_partita()", test_controllare_fine_partita);
	CU_add_test(pSuite_Partita, "test of controllare_campo_pieno()", test_controllare_campo_pieno);
	CU_add_test(pSuite_Partita, "test of controllare_casella_libera()", test_controllare_casella_libera);

	/* Esegue tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	/* Pulisce il registro e termina lo unit test */
	CU_cleanup_registry();
	system("pause");
	return CU_get_error();
}

