#include "giocatore.h"

int acquisire_tasto_qualsiasi()
{
	int tasto;
	tasto=getch();
	if(tasto==INDEFINITO){
		tasto=getch();
	}
	return tasto;
}

int controllare_tasto_regole(int i)
{
	int tasto;
	if(i>=ID_SCHERMATA_REGOLE&&i<=ID_SCHERMATA_ISTRUZIONI){
		if(i==ID_SCHERMATA_REGOLE){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_DESTRA&&tasto!=ESC);
		}else if(i==ID_SCHERMATA_ISTRUZIONI){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=ESC&&tasto!=FRECCIA_SINISTRA);
		}
	}else{
		tasto=ERRORE;
	}
	return tasto;
}

int controllare_tasto_menu(int scelta)
{
	int tasto;
	if(scelta>=ID_PRIMA_VOCE_MENU&&scelta<NUM_VOCI_MENU){
		if(scelta==ID_PRIMA_VOCE_MENU){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_GIU&&tasto!=INVIO);
		}else if(scelta==ID_QUINTA_VOCE_MENU){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_SU&&tasto!=INVIO);
		}else{
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_SU&&tasto!=FRECCIA_GIU&&tasto!=INVIO);
		}
	}else{
		tasto=ERRORE;
	}
	return tasto;
}

int controllare_tasto_posizionamento_pedina(int x, int y)
{
	int tasto;
	if((y>=ID_PRIMA_RIGA_COLONNA&&y<DIMENSIONE_CAMPO)&&(x>=ID_PRIMA_RIGA_COLONNA&&x<DIMENSIONE_CAMPO)){
		if(y==ID_PRIMA_RIGA_COLONNA){
			if(x==ID_PRIMA_RIGA_COLONNA){
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_GIU&&tasto!=FRECCIA_DESTRA&&tasto!=INVIO);
			}else if(x==ID_SESTA_RIGA_COLONNA){
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_SU&&tasto!=FRECCIA_DESTRA&&tasto!=INVIO);
			}else{
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_GIU&&tasto!=FRECCIA_DESTRA&&tasto!=FRECCIA_SU&&tasto!=INVIO);
			}
		}else if(y==ID_SESTA_RIGA_COLONNA){
			if(x==ID_PRIMA_RIGA_COLONNA){
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_GIU&&tasto!=FRECCIA_SINISTRA&&tasto!=INVIO);
			}else if(x==ID_SESTA_RIGA_COLONNA){
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_SU&&tasto!=FRECCIA_SINISTRA&&tasto!=INVIO);
			}else{
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_GIU&&tasto!=FRECCIA_SINISTRA&&tasto!=FRECCIA_SU&&tasto!=INVIO);
			}
		}else{
			if(x==ID_PRIMA_RIGA_COLONNA){
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_GIU&&tasto!=FRECCIA_SINISTRA&&tasto!=FRECCIA_DESTRA&&tasto!=INVIO);
			}else if(x==ID_SESTA_RIGA_COLONNA){
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_SU&&tasto!=FRECCIA_SINISTRA&&tasto!=FRECCIA_DESTRA&&tasto!=INVIO);
			}else{
				do{
					tasto=acquisire_tasto_qualsiasi();
				}while(tasto!=ESC&&tasto!=FRECCIA_SU&&tasto!=FRECCIA_GIU&&tasto!=FRECCIA_SINISTRA&&tasto!=FRECCIA_DESTRA&&tasto!=INVIO);
			}
		}
	}else{
		tasto=ERRORE;
	}
	return tasto;
}

int controllare_tasto_campo_da_ruotare(int i)
{
	int tasto;
	if(i>=ID_PRIMA_SEZIONE&&i<NUM_SOTTOCAMPI){
		if(i==ID_PRIMA_SEZIONE){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_DESTRA&&tasto!=INVIO&&tasto!=ESC);
		}else if(i==ID_QUARTA_SEZIONE){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_SINISTRA&&tasto!=INVIO&&tasto!=ESC);
		}else{
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_SINISTRA&&tasto!=FRECCIA_DESTRA&&tasto!=INVIO&&tasto!=ESC);
		}
	}else{
		tasto=ERRORE;
	}
	return tasto;
}

int controllare_tasto_verso_rotazione(int i)
{
	int tasto;
	if(i>=ID_RUOTA_SX&&i<=ID_RUOTA_DX){
		if(i==ID_RUOTA_SX){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_DESTRA&&tasto!=INVIO&&tasto!=ESC);
		}else{
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_SINISTRA&&tasto!=INVIO&&tasto!=ESC);
		}
	}else{
		tasto=ERRORE;
	}
	return tasto;
}

int controllare_tasto_cambia_impostazioni(int t)
{
	int tasto;
	if(t==FRECCIA_DESTRA){
		do{
			tasto=acquisire_tasto_qualsiasi();
		}while(tasto!=FRECCIA_SINISTRA&&tasto!=INVIO&&tasto!=ESC);
	}else if(t==FRECCIA_SINISTRA){
		do{
			tasto=acquisire_tasto_qualsiasi();
		}while(tasto!=FRECCIA_DESTRA&&tasto!=INVIO&&tasto!=ESC);
	}else{
		tasto=ERRORE;
	}
	return tasto;
}

int controllare_tasto_menu_salvataggio(int i)
{
	int tasto;
	if(i>=ID_PRIMO_SLOT&&i<NUM_SLOT){
		if(i==ID_PRIMO_SLOT){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=INVIO&&tasto!=FRECCIA_GIU&&tasto!=ESC);
		}else if(i==ID_DECIMO_SLOT){
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_SU&&tasto!=INVIO&&tasto!=ESC);
		}else{
			do{
				tasto=acquisire_tasto_qualsiasi();
			}while(tasto!=FRECCIA_SU&&tasto!=INVIO&&tasto!=FRECCIA_GIU&&tasto!=ESC);
		}
	}else{
		tasto=ERRORE;
	}
	return tasto;
}


booleano confermare_operazione(stringa msg)
{
	booleano conferma;
	char scelta;
	do{
		pulire_interfaccia();
		printf("%s\n",msg);
		scelta=getch();
	}while(scelta!='n'&&scelta!='N'&&scelta!='s'&&scelta!='S');
	if(scelta=='s'||scelta=='S'){
		conferma=VERO;
	}else if(scelta=='n'||scelta=='N'){
		conferma=FALSO;
	}
	return conferma;
}
