#include "regolegioco.h"

void stampare_regole_gioco()
{
	pulire_interfaccia();
	system("title PENTAGO: Regole");
	printf("\t\t\t\t%cREGOLE DEL GIOCO\n\n\n\n",SPAZIO);
	printf("\tPentago \212 un gioco per 2 giocatori.\n");
	printf("\tSi gioca su un campo di 6x6 caselle suddiviso in 4 sottocampi 3x3.\n");
	printf("\tI due giocatori devono posizionare a turno una pedina in una\n");
	printf("\tcasella libera e, successivamente, ruotare uno dei\n");
	printf("\tsottocampi in senso orario o antiorario di 90 gradi.\n");
	printf("\tVince il giocatore che riesce a posizionare 5 pedine del suo\n");
	printf("\tcolore in una fila continua, in orizzontale, verticale o obliquo,\n");
	printf("\tprima o dopo la rotazione.\n");
	printf("\tSe uno dei due giocatori fa una mossa che consente ad entrambi \n");
	printf("\ti giocatori di comporre una fila da 5, la parita finisce in pareggio.\n");
	printf("\tAnche nel caso in cui tutte le caselle del campo vengono riempite e\n");
	printf("\tnessuno dei giocatori riesce a fare una fila da 5, la partita\n");
	printf("\tfinisce in pareggio.\n");
	printf("\n\n\n\nESC MENU'\t\t\t\t\t\t\t%c%c%cISTRUZIONI GIOCO %c\n",SPAZIO,SPAZIO,SPAZIO,FRECCETTE_DX);
	return;
}

void stampare_istruzioni_gioco()
{
	pulire_interfaccia();
	system("title PENTAGO: Istruzioni");
	printf("\t\t\t\tISTRUZIONI DI GIOCO\n\n\n\n");
	printf("\tPer giocare al computer, l'inserimento della pedina\n");
	printf("\tavviene mediante l'utilizzo delle frecce direzionali dell'INVIO,\n");
	printf("\tche serve per inserire la pedina nella posizione selezionata.\n");
	printf("\tDurante la partita, il giocatore pu\x95 premere ESC per scegliere \n");
	printf("\tdi salvare la partita.\n");
	printf("\tLa scelta del sottocampo da ruotare e del verso in cui ruotarlo\n");
	printf("\tavviene sempre tramite l'utilizzo delle frecce direzionali\n");
	printf("\te dell'invio per selezionare il sottocampo e il verso\n");
	printf("\tdi rotazione.\n");
	printf("\tIl sottocampo in alto a sinistra \212 il num. 1, quello in alto a destra\n");
	printf("\t\212 il num. 2, quello in basso a sinistra il num. 3 e quello in basso\n");
	printf("\ta destra il num. 4.\n");
	printf("\tAnche negli altri men\x97 del gioco, per effettuare\n");
	printf("\tla propria scelta si utilizza il tasto INVIO, il tasto ESC\n");
	printf("\tper tornare al men\x97 principale e le frecce direzionali per\n");
	printf("\tmuoversi nel men\x97.\n");
	printf("\tIn alcuni casi, pu\x95 venire richiesto al giocatore di\n");
	printf("\tconfermare l'operazione appena eseguita.\n");
	printf("\tIl giocatore premer\x85 quindi 's' per confermare o 'n' per annullare.\n");
	printf("\n\n\n\n%c REGOLE GIOCO\t\t\t\t\t\t\t\t%c%c%cESC MENU'\n",FRECCETTE_SX,SPAZIO,SPAZIO,SPAZIO);
	return;
}
