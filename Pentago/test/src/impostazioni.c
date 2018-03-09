#include "impostazioni.h"

void creare_impostazioni_default()
{
	stringa nome_file_imp_def="pentago_impostazioni_default.txt";
	creare_file(nome_file_imp_def);
	scrivere_imp_file(nome_file_imp_def,"GIOCATORE");
	return;
}

void modificare_imp(giocatore turno)
{
	stringa nome_file_imp_mod="pentago_impostazioni_modificate.txt";
	if(turno==GIOCATORE||turno==PC){
		if(verificare_esistenza_file(nome_file_imp_mod)==VERO){
			if(turno==GIOCATORE){
				scrivere_imp_file(nome_file_imp_mod,"GIOCATORE");
			}else{
				scrivere_imp_file(nome_file_imp_mod,"PC");
			}
		}else{
			creare_file(nome_file_imp_mod);
			if(turno==GIOCATORE){
				scrivere_imp_file(nome_file_imp_mod,"GIOCATORE");
			}else{
				scrivere_imp_file(nome_file_imp_mod,"PC");
			}
		}
	}
	return;
}

giocatore leggere_imp()
{
	stringa nome_file_imp_def="pentago_impostazioni_default.txt";
	stringa nome_file_imp_mod="pentago_impostazioni_modificate.txt";
	stringa turno_l;
	giocatore turno;
	if(verificare_esistenza_file(nome_file_imp_mod)==VERO){
		turno_l=leggere_imp_file(nome_file_imp_mod);
		if(strcmp(turno_l,"GIOCATORE")==0){
			turno=GIOCATORE;
		}else{
			turno=PC;
		}
	}else{
		if(verificare_esistenza_file(nome_file_imp_def)!=VERO){
			creare_impostazioni_default();
		}
		turno_l=leggere_imp_file(nome_file_imp_def);
		if(strcmp(turno_l,"GIOCATORE")==0){
			turno=GIOCATORE;
		}else{
			turno=PC;
		}
	}
	return turno;
}
