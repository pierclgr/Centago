#include "funzionistruttdati.h"

void scrivere(campo campo,int i,int j,casella valore)
{
	if((i>=ID_PRIMA_RIGA_COLONNA&&i<DIMENSIONE_CAMPO)&&(j>=ID_PRIMA_RIGA_COLONNA&&j<DIMENSIONE_CAMPO)){
		*(*(campo+i)+j)=valore;
	}
	return;
}

casella leggere(campo campo, int i, int j)
{
	casella valore;
	if((i>=ID_PRIMA_RIGA_COLONNA&&i<DIMENSIONE_CAMPO)&&(j>=ID_PRIMA_RIGA_COLONNA&&j<DIMENSIONE_CAMPO)){
		valore=*(*(campo+i)+j);
	}else{
		valore=VUOTA;
	}
	return valore;
}

void cancellare(campo campo, int i, int j)
{
	if((i>=ID_PRIMA_RIGA_COLONNA&&i<DIMENSIONE_CAMPO)&&(j>=ID_PRIMA_RIGA_COLONNA&&j<DIMENSIONE_CAMPO)){
		*(*(campo+i)+j)=VUOTA;
	}
	return;
}

campo inizializzare()
{
	campo campo_di_gioco;
	int i;
	campo_di_gioco=malloc(DIMENSIONE_CAMPO*sizeof(casella*));
	i=ID_PRIMA_RIGA_COLONNA;
	while(i<DIMENSIONE_CAMPO){
		*(campo_di_gioco+i)=malloc(DIMENSIONE_CAMPO*sizeof(casella));
		i=spostare_avanti(i);
	}
	azzerare(campo_di_gioco);
	return campo_di_gioco;
}

void azzerare(campo campo_di_gioco)
{
	int i,j;
	i=ID_PRIMA_RIGA_COLONNA;
	while(i<DIMENSIONE_CAMPO){
		j=ID_PRIMA_RIGA_COLONNA;
		while(j<DIMENSIONE_CAMPO){
			cancellare(campo_di_gioco,i,j);
			j=spostare_avanti(j);
		}
		i=spostare_avanti(i);
	}
	return;
}

int spostare_avanti(int i)
{
	int posizione_successiva;
	posizione_successiva=i+1;
	return posizione_successiva;
}

int spostare_indietro(int i)
{
	int posizione_precedente;
	posizione_precedente=i-1;
	return posizione_precedente;
}
