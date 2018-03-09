#include "file.h"

void scrivere_imp_file(stringa nome_file,stringa valore_da_scrivere)
{
	FILE* fp;
	if(strcmp(valore_da_scrivere,"PC")==0||strcmp(valore_da_scrivere,"GIOCATORE")==0){
		fp=fopen(nome_file,"w");
		if(fp==NULL){
			printf("Errore apertura file!\n");
		}else{
			fprintf(fp,"%s",valore_da_scrivere);
		}
		fclose(fp);
	}
	return;
}

stringa leggere_imp_file(stringa nome_file)
{
	stringa valore_da_leggere;
	valore_da_leggere=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	FILE* fp;
	fp=fopen(nome_file,"r");
	if(fp==NULL){
		printf("Errore apertura file!\n");
		valore_da_leggere="";
	}else{
		fscanf(fp,"%s",valore_da_leggere);
	}
	fclose(fp);
	return valore_da_leggere;
}

void creare_file(stringa nome_file)
{
	FILE* fp;
	fp=fopen(nome_file,"w+");
	if(fp==NULL){
		printf("Errore apertura file!");
	}
	fclose(fp);
	return;
}

booleano verificare_esistenza_file(stringa nome_file)
{
	booleano verifica_esistenza;
	FILE* fp;
	if((fp=fopen(nome_file,"r"))==NULL){
		verifica_esistenza=FALSO;
	}else{
		verifica_esistenza=VERO;
	}
	fclose(fp);
	return verifica_esistenza;
}

stringa leggere_data_partita(stringa nome_file)
{
	stringa valore_da_leggere;
	stringa giorno_g,mese,giorno_num,ora,anno;
	giorno_g=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	mese=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	giorno_num=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	ora=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	anno=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	valore_da_leggere=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	FILE* fp;
	fp=fopen(nome_file,"r");
	if(fp==NULL){
		printf("Errore apertura file!\n");
		valore_da_leggere="";
	}else{
		fscanf(fp,"%s %s %s %s %s",giorno_g,mese,giorno_num,ora,anno);
		sprintf(valore_da_leggere,"%s %s %s %s %s",giorno_g,mese,giorno_num,ora,anno);
	}
	fclose(fp);
	return valore_da_leggere;
}

void scrivere_file_partite(turno turno_gioco,campo campo_gioco,stringa nome_file)
{
	FILE* fp;
	int i,j;
	time_t ora_data;
	time(&ora_data);
	fp=fopen(nome_file,"w");
	if(fp==NULL){
		printf("Errore apertura file!\n");
	}else{
		fputs(ctime(&ora_data),fp);
		i=ID_PRIMA_RIGA_COLONNA;
		while(i<DIMENSIONE_CAMPO){
			j=ID_PRIMA_RIGA_COLONNA;
			while(j<DIMENSIONE_CAMPO){
				if(leggere(campo_gioco,i,j)==VUOTA){
					fputs("VUOTA",fp);
				}else if(leggere(campo_gioco,i,j)==PEDINA_GIOCATORE){
					fputs("PEDINA_GIOCATORE",fp);
				}else if(leggere(campo_gioco,i,j)==PEDINA_PC){
					fputs("PEDINA_PC",fp);
				}
				fputs("\n",fp);
				j=spostare_avanti(j);
			}
			i=spostare_avanti(i);
		}
		if(turno_gioco.giocatore==GIOCATORE){
			if(turno_gioco.mossa==POSIZIONA){
				fputs("GIOCATORE",fp);
				fputs("\n",fp);
				fputs("POSIZIONA",fp);
				fputs("\n",fp);
			}else{
				fputs("GIOCATORE",fp);
				fputs("\n",fp);
				fputs("RUOTA",fp);
				fputs("\n",fp);
			}
		}else if(turno_gioco.giocatore==PC){
			if(turno_gioco.mossa==POSIZIONA){
				fputs("PC",fp);
				fputs("\n",fp);
				fputs("POSIZIONA",fp);
				fputs("\n",fp);
			}else{
				fputs("PC",fp);
				fputs("\n",fp);
				fputs("RUOTA",fp);
				fputs("\n",fp);
			}
		}
	}
	fclose(fp);
	return;
}

campo leggere_campo_gioco_partita(stringa nome_file)
{
	FILE* fp;
	int i,j;
	campo campo_gioco;
	stringa temp;
	temp=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	campo_gioco=inizializzare();
	fp=fopen(nome_file,"r");
	if(fp==NULL){
		printf("Errore apertura file!\n");
	}else{
		i=ID_PRIMA_RIGA_COLONNA;
		j=ID_PRIMA_RIGA_COLONNA;
		while(!feof(fp)){
			fscanf(fp,"%s\n",temp);
			if(strcmp(temp,"VUOTA")==0){
				scrivere(campo_gioco,i,j,VUOTA);
				if(j==ID_SESTA_RIGA_COLONNA){
					i=spostare_avanti(i);
					j=ID_PRIMA_RIGA_COLONNA;
				}else{
					j=spostare_avanti(j);
				}
			}else if(strcmp(temp,"PEDINA_GIOCATORE")==0){
				scrivere(campo_gioco,i,j,PEDINA_GIOCATORE);
				if(j==ID_SESTA_RIGA_COLONNA){
					i=spostare_avanti(i);
					j=ID_PRIMA_RIGA_COLONNA;
				}else{
					j=spostare_avanti(j);
				}
			}else if(strcmp(temp,"PEDINA_PC")==0){
				scrivere(campo_gioco,i,j,PEDINA_PC);
				if(j==ID_SESTA_RIGA_COLONNA){
					i=spostare_avanti(i);
					j=ID_PRIMA_RIGA_COLONNA;
				}else{
					j=spostare_avanti(j);
				}
			}
		}
	}
	fclose(fp);
	return campo_gioco;
}

turno leggere_turno_gioco_partita(stringa nome_file)
{
	FILE* fp;
	turno turno_gioco;
	stringa temp;
	temp=malloc(LUNGHEZZA_STRINGA*sizeof(char));
	fp=fopen(nome_file,"r");
	if(fp==NULL){
		printf("Errore apertura file!\n");
	}else{
		while(!feof(fp)){
			fscanf(fp,"%s\n",temp);
			if(strcmp(temp,"GIOCATORE")==0){
				turno_gioco.giocatore=GIOCATORE;
			}else if(strcmp(temp,"PC")==0){
				turno_gioco.giocatore=PC;
			}else if(strcmp(temp,"RUOTA")==0){
				turno_gioco.mossa=RUOTA;
			}else if(strcmp(temp,"POSIZIONA")==0){
				turno_gioco.mossa=POSIZIONA;
			}
		}
	}
	fclose(fp);
	return turno_gioco;
}
