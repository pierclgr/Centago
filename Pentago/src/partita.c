#include "partita.h"

booleano controllare_fine_partita(campo campo_gioco,giocatore g)
{
	booleano fine;
	fine=FALSO;
	if(contare_num_pedine_serie(campo_gioco,g,CINQUE_PEDINE)==VERO){
		fine=VERO;
	}
	return fine;
}

booleano contare_num_pedine_serie_orizzontali(campo campo_gioco, giocatore g, int contare_num_pedine_consecutive)
{
	booleano pedine_consecutive;
	int i,j;
	int conta_pedine;
	casella controllo_casella;
	pedine_consecutive=FALSO;
	if(contare_num_pedine_consecutive>ZERO_PEDINE&&contare_num_pedine_consecutive<=CINQUE_PEDINE){
		if(g==GIOCATORE||g==PC){
			if(g==GIOCATORE){
				controllo_casella=PEDINA_GIOCATORE;
			}else if(g==PC){
				controllo_casella=PEDINA_PC;
			}
			conta_pedine=ZERO_PEDINE;
			i=ID_PRIMA_RIGA_COLONNA;
			while(i<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
				j=ID_PRIMA_RIGA_COLONNA;
				while(j<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
					if(leggere(campo_gioco,i,j)==controllo_casella){
						conta_pedine=spostare_avanti(conta_pedine);
					}else{
						conta_pedine=ZERO_PEDINE;
					}
					if(conta_pedine==contare_num_pedine_consecutive){
						pedine_consecutive=VERO;
					}
					j=spostare_avanti(j);
				}
				conta_pedine=ZERO_PEDINE;
				i=spostare_avanti(i);
			}
		}
	}
	return pedine_consecutive;
}

booleano contare_num_pedine_serie_verticali(campo campo_gioco,  giocatore g, int contare_num_pedine_consecutive)
{
	booleano pedine_consecutive;
	int i,j;
	int conta_pedine;
	casella controllo_casella;
	pedine_consecutive=FALSO;
	if(contare_num_pedine_consecutive>ZERO_PEDINE&&contare_num_pedine_consecutive<=CINQUE_PEDINE){
		if(g==PC||g==GIOCATORE){
			if(g==GIOCATORE){
				controllo_casella=PEDINA_GIOCATORE;
			}else if(g==PC){
				controllo_casella=PEDINA_PC;
			}
			conta_pedine=ZERO_PEDINE;
			i=ID_PRIMA_RIGA_COLONNA;
			while(i<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
				j=ID_PRIMA_RIGA_COLONNA;
				while(j<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
					if(leggere(campo_gioco,j,i)==controllo_casella){
						conta_pedine=spostare_avanti(conta_pedine);
					}else{
						conta_pedine=ZERO_PEDINE;
					}
					if(conta_pedine==contare_num_pedine_consecutive){
						pedine_consecutive=VERO;
					}
					j=spostare_avanti(j);
				}
				conta_pedine=ZERO_PEDINE;
				i=spostare_avanti(i);
			}
		}
	}
	return pedine_consecutive;
}

booleano contare_num_pedine_serie_obliquo_destra(campo campo_gioco,  giocatore g, int contare_num_pedine_consecutive)
{
	booleano pedine_consecutive;
	int i,j,k;
	int conta_pedine;
	casella controllo_casella;
	pedine_consecutive=FALSO;
	if(contare_num_pedine_consecutive>ZERO_PEDINE&&contare_num_pedine_consecutive<=CINQUE_PEDINE){
		if(g==GIOCATORE||g==PC){
			if(g==GIOCATORE){
				controllo_casella=PEDINA_GIOCATORE;
			}else if(g==PC){
				controllo_casella=PEDINA_PC;
			}
			conta_pedine=ZERO_PEDINE;
			k=ID_PRIMA_RIGA_COLONNA;
			while(k<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
				i=ID_PRIMA_RIGA_COLONNA;
				j=k;
				while(i<spostare_avanti(k)&&pedine_consecutive==FALSO){
					if(leggere(campo_gioco,i,j)==controllo_casella){
						conta_pedine=spostare_avanti(conta_pedine);
					}else{
						conta_pedine=ZERO_PEDINE;
					}
					if(conta_pedine==contare_num_pedine_consecutive){
						pedine_consecutive=VERO;
					}
					i=spostare_avanti(i);
					j=spostare_indietro(j);
				}
				conta_pedine=ZERO_PEDINE;
				k=spostare_avanti(k);
			}
			conta_pedine=ZERO_PEDINE;
			k=ID_SECONDA_RIGA_COLONNA;
			while(k<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
				i=ID_SESTA_RIGA_COLONNA;
				j=k;
				while(j<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
					if(leggere(campo_gioco,i,j)==controllo_casella){
						conta_pedine=spostare_avanti(conta_pedine);
					}else{
						conta_pedine=ZERO_PEDINE;
					}
					if(conta_pedine==contare_num_pedine_consecutive){
						pedine_consecutive=VERO;
					}
					i=spostare_indietro(i);
					j=spostare_avanti(j);
				}
				conta_pedine=ZERO_PEDINE;
				k=spostare_avanti(k);
			}
		}
	}
	return pedine_consecutive;
}

booleano contare_num_pedine_serie_obliquo_sinistra(campo campo_gioco, giocatore g, int contare_num_pedine_consecutive)
{
	booleano pedine_consecutive;
	int i,j,k;
	int conta_pedine;
	casella controllo_casella;
	pedine_consecutive=FALSO;
	if(contare_num_pedine_consecutive>ZERO_PEDINE&&contare_num_pedine_consecutive<=CINQUE_PEDINE){
		if(g==GIOCATORE||g==PC){
			if(g==GIOCATORE){
				controllo_casella=PEDINA_GIOCATORE;
			}else{
				controllo_casella=PEDINA_PC;
			}
			conta_pedine=ZERO_PEDINE;
			k=ID_PRIMA_RIGA_COLONNA;
			while(k<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
				i=ID_PRIMA_RIGA_COLONNA;
				j=ID_SESTA_RIGA_COLONNA-k;
				while(i<spostare_avanti(k)&&pedine_consecutive==FALSO){
					if(leggere(campo_gioco,i,j)==controllo_casella){
						conta_pedine=spostare_avanti(conta_pedine);
					}else{
						conta_pedine=ZERO_PEDINE;
					}
					if(conta_pedine==contare_num_pedine_consecutive){
						pedine_consecutive=VERO;
					}
					i=spostare_avanti(i);
					j=spostare_avanti(j);
				}
				conta_pedine=ZERO_PEDINE;
				k=spostare_avanti(k);
			}
			conta_pedine=ZERO_PEDINE;
			k=ID_SECONDA_RIGA_COLONNA;
			while(k<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
				i=ID_PRIMA_RIGA_COLONNA+k;
				j=ID_PRIMA_RIGA_COLONNA;
				while(i<DIMENSIONE_CAMPO&&pedine_consecutive==FALSO){
					if(leggere(campo_gioco,i,j)==controllo_casella){
						conta_pedine=spostare_avanti(conta_pedine);
					}else{
						conta_pedine=ZERO_PEDINE;
					}
					if(conta_pedine==contare_num_pedine_consecutive){
						pedine_consecutive=VERO;
					}
					i=spostare_avanti(i);
					j=spostare_avanti(j);
				}
				conta_pedine=ZERO_PEDINE;
				k=spostare_avanti(k);
			}
		}
	}
	return pedine_consecutive;
}

booleano contare_num_pedine_serie(campo campo_gioco, giocatore g, int contare_num_pedine_consecutive)
{
	booleano pedine_consecutive;
	pedine_consecutive=FALSO;
	if(contare_num_pedine_consecutive>ZERO_PEDINE&&contare_num_pedine_consecutive<=CINQUE_PEDINE){
		if(g==PC||g==GIOCATORE){
			if((contare_num_pedine_serie_orizzontali(campo_gioco,g,contare_num_pedine_consecutive)==VERO)||
				(contare_num_pedine_serie_verticali(campo_gioco,g,contare_num_pedine_consecutive)==VERO)||
				(contare_num_pedine_serie_obliquo_destra(campo_gioco,g,contare_num_pedine_consecutive)==VERO)||
				(contare_num_pedine_serie_obliquo_sinistra(campo_gioco,g,contare_num_pedine_consecutive)==VERO)){
				pedine_consecutive=VERO;
			}
		}
	}
	return pedine_consecutive;
}

void giocare_partita(campo campo_gioco, turno turno_gioco)
{
	int tasto;
	stringa notifica;
	campo campo_temporaneo;
	mossa_rotazione mossa;
	coordinata coordinata;
	int campo_da_ruotare;
	verso_rotazione verso;
	int x;
	int y;
	int z;
	if((turno_gioco.giocatore==GIOCATORE||turno_gioco.giocatore==PC)&&(turno_gioco.mossa==RUOTA||turno_gioco.mossa==POSIZIONA)){
		x=ID_PRIMA_RIGA_COLONNA;
		y=ID_PRIMA_RIGA_COLONNA;
		z=ID_PRIMA_SEZIONE;
		do{
			if(turno_gioco.giocatore==GIOCATORE){
				if(turno_gioco.mossa==POSIZIONA){
					stampare_campo(campo_gioco,x,y);
					stampare_scelta_rotazione(ERRORE);
					if(controllare_casella_libera(campo_gioco,x,y)==FALSO){
						notifica="\x1b[36m\nCasella gi\x85 occupata!\x1b[0m";
					}else{
						notifica="\n";
					}
					printf("%s\n",notifica);
					tasto=controllare_tasto_posizionamento_pedina(x,y);
					if(tasto!=ESC){
						if(tasto==FRECCIA_SU){
							x=spostare_indietro(x);
						}else if(tasto==FRECCIA_GIU){
							x=spostare_avanti(x);
						}else if(tasto==FRECCIA_DESTRA){
							y=spostare_avanti(y);
						}else if(tasto==FRECCIA_SINISTRA){
							y=spostare_indietro(y);
						}else if(tasto==INVIO){
							if(controllare_casella_libera(campo_gioco,x,y)==VERO){
								posizionare_pedina(campo_gioco,x,y,turno_gioco.giocatore);
								turno_gioco.mossa=RUOTA;
							}
						}
					}
				}else{
					stampare_campo(campo_gioco,ERRORE,ERRORE);
					stampare_scelta_rotazione(z);
					if(z>=ID_PRIMA_SEZIONE&&z<NUM_SOTTOCAMPI){
						tasto=controllare_tasto_campo_da_ruotare(z);
						if(tasto!=ESC){
							if(tasto==FRECCIA_DESTRA){
								z=spostare_avanti(z);
							}else if(tasto==FRECCIA_SINISTRA){
								z=spostare_indietro(z);
							}else if(tasto==INVIO){
								campo_da_ruotare=z;
								z=ID_RUOTA_SX;
							}
						}
					}else if(z>=ID_RUOTA_SX&&z<=ID_RUOTA_DX){
						tasto=controllare_tasto_verso_rotazione(z);
						if(tasto==FRECCIA_DESTRA){
							z=spostare_avanti(z);
						}else if(tasto==FRECCIA_SINISTRA){
							z=spostare_indietro(z);
						}else if(tasto==INVIO){
							if(z==ID_RUOTA_SX){
								verso=SX;
							}else if(z==ID_RUOTA_DX){
								verso=DX;
							}
							ruotare_campo(campo_gioco,verso,campo_da_ruotare);
							z=ID_PRIMA_SEZIONE;
							turno_gioco.giocatore=PC;
							turno_gioco.mossa=POSIZIONA;
						}
					}
				}
			}else if(turno_gioco.giocatore==PC){
				if(turno_gioco.mossa==POSIZIONA){
					campo_temporaneo=copiare_campo(campo_gioco);
					stampare_campo(campo_temporaneo,ERRORE,ERRORE);
					stampare_scelta_rotazione(ERRORE);
					mossa=trovare_miglior_ruotato(campo_temporaneo);
					ruotare_campo(campo_temporaneo,mossa.verso,mossa.num_campo);
					coordinata=scegliere_coppia(campo_temporaneo,GIOCATORE);
					if(coordinata.x!=ERRORE&&coordinata.y!=ERRORE){
						posizionare_pedina(campo_temporaneo,coordinata.x,coordinata.y,turno_gioco.giocatore);
					}else{
						coordinata=scegliere_coppia(campo_temporaneo,PC);
						if(coordinata.x!=ERRORE&&coordinata.y!=ERRORE){
							posizionare_pedina(campo_temporaneo,coordinata.x,coordinata.y,turno_gioco.giocatore);
						}else{
							coordinata=posizionare_per_priorita(campo_gioco);
							posizionare_pedina(campo_temporaneo,coordinata.x,coordinata.y,turno_gioco.giocatore);
						}
					}
					sleep(1);
					turno_gioco.mossa=RUOTA;
				}else{
					if(mossa.verso==DX){
						ruotare_campo(campo_temporaneo,SX,mossa.num_campo);
					}else{
						ruotare_campo(campo_temporaneo,DX,mossa.num_campo);
					}
					stampare_campo(campo_temporaneo,ERRORE,ERRORE);
					stampare_scelta_rotazione(ERRORE);
					ruotare_campo(campo_temporaneo,mossa.verso,mossa.num_campo);
					campo_gioco=copiare_campo(campo_temporaneo);
					free(campo_temporaneo);
					sleep(1);
					turno_gioco.giocatore=GIOCATORE;
					turno_gioco.mossa=POSIZIONA;
				}
			}
			stampare_campo(campo_gioco,ERRORE,ERRORE);
			stampare_scelta_rotazione(ERRORE);
		}while(controllare_fine_partita(campo_gioco,GIOCATORE)==FALSO&&controllare_fine_partita(campo_gioco,PC)==FALSO&&controllare_campo_pieno(campo_gioco)==FALSO&&tasto!=ESC);
		if((controllare_campo_pieno(campo_gioco)==VERO)||(controllare_fine_partita(campo_gioco,GIOCATORE)==VERO&&controllare_fine_partita(campo_gioco,PC)==VERO)){
			printf("\x1b[33m\nLa partita è finita in pareggio. Premi un tasto per tornare al men\x97.\n\x1b[0m");
				tasto=acquisire_tasto_qualsiasi();
		}else if(controllare_fine_partita(campo_gioco,PC)==VERO){
			printf("\x1b[31m\nIl PC ha vinto la partita. Premi un tasto per tornare al men\x97.\n\x1b[0m");
			tasto=acquisire_tasto_qualsiasi();
		}else if(controllare_fine_partita(campo_gioco,GIOCATORE)==VERO){
			printf("\x1b[32m\nHai vinto la partita! Premi un tasto per tornare al men\x97.\n\x1b[0m");
			tasto=acquisire_tasto_qualsiasi();
		}else if(tasto==ESC){
			if(confermare_operazione("\nVuoi salvare la partita? (s/n)")==VERO){
				salvare_partita(campo_gioco,turno_gioco);
			}
		}
	}
	return;
}

booleano controllare_campo_pieno(campo campo_gioco)
{
	booleano pieno;
	int i,j;
	i=ID_PRIMA_RIGA_COLONNA;
	pieno=VERO;
	do{
		j=ID_PRIMA_RIGA_COLONNA;
		do{
			if(leggere(campo_gioco,i,j)==VUOTA){
				pieno=FALSO;
			}
			j=spostare_avanti(j);
		}while(j<DIMENSIONE_CAMPO&&pieno!=FALSO);
		i=spostare_avanti(i);
	}while(i<DIMENSIONE_CAMPO&&pieno!=FALSO);
	return pieno;
}

void posizionare_pedina(campo campo,int x, int y,giocatore giocatore)
{
	if(x>=ID_PRIMA_RIGA_COLONNA&&x<DIMENSIONE_CAMPO&&y>=ID_PRIMA_RIGA_COLONNA&&y<DIMENSIONE_CAMPO){
		if(giocatore==GIOCATORE){
			scrivere(campo,x,y,PEDINA_GIOCATORE);
		}else if(giocatore==PC){
			scrivere(campo,x,y,PEDINA_PC);
		}
	}
	return;
}

booleano controllare_casella_libera(campo campo_gioco,int x, int y)
{
	booleano vuota;
	vuota=VERO;
	if(x>=ID_PRIMA_RIGA_COLONNA&&x<DIMENSIONE_CAMPO&&y>=ID_PRIMA_RIGA_COLONNA&&y<DIMENSIONE_CAMPO){
		if(leggere(campo_gioco,x,y)==PEDINA_GIOCATORE||leggere(campo_gioco,x,y)==PEDINA_PC){
			vuota=FALSO;
		}
	}
	return vuota;
}

void ruotare_campo(campo campo_di_gioco, verso_rotazione verso, int num_campo)
{
	int i;
	casella val_temp;
	coordinata casella_di_partenza;
	if(num_campo>=ID_PRIMA_SEZIONE&&num_campo<NUM_SOTTOCAMPI){
		if(verso==DX||verso==SX){
			if(num_campo==ID_PRIMA_SEZIONE){
				casella_di_partenza.x=PRIMA_RIGA_SEZ_0;
				casella_di_partenza.y=PRIMA_COLONNA_SEZ_0;
			}else if(num_campo==ID_SECONDA_SEZIONE){
				casella_di_partenza.x=PRIMA_RIGA_SEZ_1;
				casella_di_partenza.y=PRIMA_COLONNA_SEZ_1;
			}else if(num_campo==ID_TERZA_SEZIONE){
				casella_di_partenza.x=PRIMA_RIGA_SEZ_2;
				casella_di_partenza.y=PRIMA_COLONNA_SEZ_2;
			}else{
				casella_di_partenza.x=PRIMA_RIGA_SEZ_3;
				casella_di_partenza.y=PRIMA_COLONNA_SEZ_3;
			}
			if(verso==SX){
				i=0;
				while(i<RIPETIZIONI_NECESSARIE_ROTAZIONE){
					val_temp=leggere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y);
					scrivere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y,leggere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y+DISTANZA_1_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y+DISTANZA_1_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_1_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_1_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_1_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_1_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_1_PRIMA_POSIZIONE,casella_di_partenza.y));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_1_PRIMA_POSIZIONE,casella_di_partenza.y,val_temp);
					i=spostare_avanti(i);
				}
			}else{
				i=0;
				while(i<RIPETIZIONI_NECESSARIE_ROTAZIONE){
					val_temp=leggere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y);
					scrivere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_1_PRIMA_POSIZIONE,casella_di_partenza.y));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_1_PRIMA_POSIZIONE,casella_di_partenza.y,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_1_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_1_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_2_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x+DISTANZA_1_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x+DISTANZA_1_PRIMA_POSIZIONE,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y+DISTANZA_2_PRIMA_POSIZIONE,leggere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y+DISTANZA_1_PRIMA_POSIZIONE));
					scrivere(campo_di_gioco,casella_di_partenza.x,casella_di_partenza.y+DISTANZA_1_PRIMA_POSIZIONE,val_temp);
					i=spostare_avanti(i);
				}
			}
		}
	}
	return;
}

void salvare_partita(campo campo_gioco, turno turno_gioco)
{
	int i;
	int tasto;
	booleano conferma;
	if((turno_gioco.giocatore==GIOCATORE||turno_gioco.giocatore==PC)&&(turno_gioco.mossa==RUOTA||turno_gioco.mossa==POSIZIONA)){
		i=ID_PRIMO_SLOT;
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
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot1.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot1.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot1.txt");
						conferma=VERO;
					}
				}else if(i==ID_SECONDO_SLOT){
					if(verificare_esistenza_file("slot2.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot2.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot2.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot2.txt");
						conferma=VERO;
					}
				}else if(i==ID_TERZO_SLOT){
					if(verificare_esistenza_file("slot3.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot3.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot3.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot3.txt");
						conferma=VERO;
					}
				}else if(i==ID_QUARTO_SLOT){
					if(verificare_esistenza_file("slot4.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot4.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot4.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot4.txt");
						conferma=VERO;
					}
				}else if(i==ID_QUINTO_SLOT){
					if(verificare_esistenza_file("slot5.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot5.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot5.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot5.txt");
						conferma=VERO;
					}
				}else if(i==ID_SESTO_SLOT){
					if(verificare_esistenza_file("slot6.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot6.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot6.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot6.txt");
						conferma=VERO;
					}
				}else if(i==ID_SETTIMO_SLOT){
					if(verificare_esistenza_file("slot7.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot7.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot7.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot7.txt");
						conferma=VERO;
					}
				}else if(i==ID_OTTAVO_SLOT){
					if(verificare_esistenza_file("slot8.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot8.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot8.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot8.txt");
						conferma=VERO;
					}
				}else if(i==ID_NONO_SLOT){
					if(verificare_esistenza_file("slot9.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot9.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot9.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot9.txt");
						conferma=VERO;
					}
				}else if(i==ID_DECIMO_SLOT){
					if(verificare_esistenza_file("slot10.txt")==VERO){
						if(confermare_operazione("\nE' gi\x85 presente una partita in questo slot, vuoi sovrascriverla? (s/n)")==VERO){
							scrivere_file_partite(turno_gioco,campo_gioco,"slot10.txt");
							conferma=VERO;
						}else{
							conferma=FALSO;
						}
					}else{
						creare_file("slot10.txt");
						scrivere_file_partite(turno_gioco,campo_gioco,"slot10.txt");
						conferma=VERO;
					}
				}
			}
		}while(conferma==FALSO);
	}
	return;
}


