#include "menu.h"

void menu_principale()
{
	int scelta;
	int inserimento_menu;
	booleano esci_gioco;
	esci_gioco=FALSO;
	scelta=ID_PRIMA_VOCE_MENU;
	do{
		stampare_menu(scelta);
		system("title PENTAGO: Menù principale");
		inserimento_menu=controllare_tasto_menu(scelta);
		if(inserimento_menu==FRECCIA_SU){
			scelta=spostare_indietro(scelta);
		}else if(inserimento_menu==FRECCIA_GIU){
			scelta=spostare_avanti(scelta);
		}else if(inserimento_menu==INVIO){
			if(scelta==ID_PRIMA_VOCE_MENU){
				pulire_interfaccia();
				system("title PENTAGO: Gioco");
				nuova_partita();
			}else if(scelta==ID_SECONDA_VOCE_MENU){
				pulire_interfaccia();
				system("title PENTAGO: Gioco");
				carica_partita();
			}else if(scelta==ID_TERZA_VOCE_MENU){
				pulire_interfaccia();
				system("title PENTAGO: Impostazioni");
				modifica_impostazioni();
			}else if(scelta==ID_QUARTA_VOCE_MENU){
				pulire_interfaccia();
				regole_gioco();
			}else if(scelta==ID_QUINTA_VOCE_MENU){
				pulire_interfaccia();
				esci_gioco=fine_gioco();
			}
		}
	}while(esci_gioco==FALSO);
}

booleano fine_gioco()
{
	booleano esci_gioco;
	esci_gioco=VERO;
	return esci_gioco;
}

void regole_gioco()
{
	int i;
	int cambia_schermata;
	i=ID_SCHERMATA_REGOLE;
	do{
		if(i==ID_SCHERMATA_REGOLE){
			stampare_regole_gioco();
			cambia_schermata=controllare_tasto_regole(i);
			if(cambia_schermata==FRECCIA_DESTRA){
				i=spostare_avanti(i);
			}
		}else if(i==ID_SCHERMATA_ISTRUZIONI){
			stampare_istruzioni_gioco();
			cambia_schermata=controllare_tasto_regole(i);
			if(cambia_schermata==FRECCIA_SINISTRA){
				i=spostare_indietro(i);
			}
		}
	}while(cambia_schermata!=ESC);
	return;
}

void modifica_impostazioni()
{
	booleano conferma;
	giocatore turno;
	int cambia_schermata;
	turno=leggere_imp();
	do{
		stampare_impostazioni(turno);
		if(turno==GIOCATORE){
			cambia_schermata=FRECCIA_SINISTRA;
			cambia_schermata=controllare_tasto_cambia_impostazioni(cambia_schermata);
			if(cambia_schermata==FRECCIA_DESTRA){
				turno=PC;
			}else if(cambia_schermata==INVIO){
				conferma=confermare_operazione("\tVuoi salvare le impostazioni? (s/n)");
				if(conferma==VERO){
					modificare_imp(turno);
				}
			}
		}else{
			cambia_schermata=FRECCIA_DESTRA;
			cambia_schermata=controllare_tasto_cambia_impostazioni(cambia_schermata);
			if(cambia_schermata==FRECCIA_SINISTRA){
				turno=GIOCATORE;
			}else if(cambia_schermata==INVIO){
				conferma=confermare_operazione("\nVuoi salvare le impostazioni? (s/n)");
				if(conferma==VERO){
					modificare_imp(turno);
				}
			}
		}
	}while(cambia_schermata!=INVIO&&cambia_schermata!=ESC);
	return;
}

void nuova_partita()
{
	campo campo_gioco;
	turno turno_gioco;
	campo_gioco=inizializzare();
	turno_gioco.giocatore=leggere_imp();
	turno_gioco.mossa=POSIZIONA;
	giocare_partita(campo_gioco,turno_gioco);
}

void carica_partita()
{
	campo campo_gioco;
	turno turno_gioco;
	booleano conferma;
	campo_gioco=inizializzare();
	turno_gioco.giocatore=GIOCATORE;
	turno_gioco.mossa=POSIZIONA;
	int i;
	int tasto;
	i=ID_PRIMO_SLOT;
	if(verificare_esistenza_file("slot1.txt")==FALSO&&verificare_esistenza_file("slot2.txt")==FALSO&&verificare_esistenza_file("slot3.txt")==FALSO&&verificare_esistenza_file("slot4.txt")==FALSO&&verificare_esistenza_file("slot5.txt")==FALSO&&verificare_esistenza_file("slot6.txt")==FALSO&&verificare_esistenza_file("slot7.txt")==FALSO&&verificare_esistenza_file("slot8.txt")==FALSO&&verificare_esistenza_file("slot9.txt")==FALSO&&verificare_esistenza_file("slot10.txt")==FALSO){
		pulire_interfaccia();
		printf("\n\n\n\t\t");
		printf("Non ci sono partite salvate attualmente.\n");
		printf("\t\tPremi un qualsiasi tasto per tornare al men\x97.\n");
		tasto=acquisire_tasto_qualsiasi();
	}else{
		do{
			do{
				stampare_slot_partite(i);
				tasto=controllare_tasto_menu_salvataggio(i);
				if(tasto==FRECCIA_SU){
					i=spostare_indietro(i);
				}else if(tasto==FRECCIA_GIU){
					i=spostare_avanti(i);
				}else if(tasto==ESC){
					conferma=VERO;
				}
			}while(tasto!=INVIO&&tasto!=ESC);
			if(tasto==INVIO){
				if(i==ID_PRIMO_SLOT){
					if(verificare_esistenza_file("slot1.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot1.txt");
							turno_gioco=leggere_turno_gioco_partita("slot1.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_SECONDO_SLOT){
					if(verificare_esistenza_file("slot2.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot2.txt");
							turno_gioco=leggere_turno_gioco_partita("slot2.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_TERZO_SLOT){
					if(verificare_esistenza_file("slot3.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot3.txt");
							turno_gioco=leggere_turno_gioco_partita("slot3.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_QUARTO_SLOT){
					if(verificare_esistenza_file("slot4.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot4.txt");
							turno_gioco=leggere_turno_gioco_partita("slot4.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_QUINTO_SLOT){
					if(verificare_esistenza_file("slot5.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot5.txt");
							turno_gioco=leggere_turno_gioco_partita("slot5.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_SESTO_SLOT){
					if(verificare_esistenza_file("slot6.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot6.txt");
							turno_gioco=leggere_turno_gioco_partita("slot6.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_SETTIMO_SLOT){
					if(verificare_esistenza_file("slot7.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot7.txt");
							turno_gioco=leggere_turno_gioco_partita("slot7.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_OTTAVO_SLOT){
					if(verificare_esistenza_file("slot8.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot8.txt");
							turno_gioco=leggere_turno_gioco_partita("slot8.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_NONO_SLOT){
					if(verificare_esistenza_file("slot9.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot9.txt");
							turno_gioco=leggere_turno_gioco_partita("slot9.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}else if(i==ID_DECIMO_SLOT){
					if(verificare_esistenza_file("slot10.txt")==VERO){
						if(confermare_operazione("\nSei sicuro di voler caricare questa partita? (s/n)")==VERO){
							campo_gioco=leggere_campo_gioco_partita("slot10.txt");
							turno_gioco=leggere_turno_gioco_partita("slot10.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						conferma=FALSO;
					}
				}
			}
		}while(conferma==FALSO);
		if(tasto==INVIO){
			giocare_partita(campo_gioco,turno_gioco);
		}
	}
}

