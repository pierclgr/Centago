#ifndef TIPIUTENTE_H_
#define TIPIUTENTE_H_

typedef enum{
	FALSO,
	VERO
} booleano;

typedef enum{
	PEDINA_GIOCATORE,
	PEDINA_PC,
	VUOTA
}casella;

typedef casella** campo;

typedef enum{
	GIOCATORE,
	PC
}giocatore;

typedef enum{
	RUOTA,
	POSIZIONA
}mossa;

typedef struct{
	giocatore giocatore;
	mossa mossa;
}turno;

typedef char* stringa;

typedef struct{
	int x;
	int y;
}coordinata;

typedef enum{
	DX,
	SX
}verso_rotazione;

typedef struct{
	int num_campo;
	verso_rotazione verso;
} mossa_rotazione;

typedef campo* insieme_campi_ruotati;

typedef enum{
	ORIZZONTALE,
	VERTICALE,
	DESTRA,
	SINISTRA,
}verso_serie_pedina;

typedef struct{
	coordinata coordinata;
	verso_serie_pedina verso;
}pedina_verso;

#endif
