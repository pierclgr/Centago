#include "interfacciagrafica.h"

void stampare_menu(int scelta)
{
	if(scelta>=ID_PRIMA_VOCE_MENU&&scelta<NUM_VOCI_MENU){
		pulire_interfaccia();
		printf("\t\t\t\t%cMENU' PRINCIPALE\n\n\n\n",SPAZIO);
		if(scelta==ID_PRIMA_VOCE_MENU){
			printf("\t%c Nuova partita %c\n",FRECCETTE_DX,FRECCETTE_SX);
		}else{
			printf("\tNuova partita\n");
		}
		if(scelta==ID_SECONDA_VOCE_MENU){
			printf("\t%c Carica partita %c\n",FRECCETTE_DX,FRECCETTE_SX);
		}else{
			printf("\tCarica partita\n");
		}
		if(scelta==ID_TERZA_VOCE_MENU){
			printf("\t%c Modifica impostazioni %c\n",FRECCETTE_DX,FRECCETTE_SX);
		}else{
			printf("\tModifica impostazioni\n");
		}
		if(scelta==ID_QUARTA_VOCE_MENU){
			printf("\t%c Regole del gioco %c\n\n",FRECCETTE_DX,FRECCETTE_SX);
		}else{
			printf("\tRegole del gioco\n\n");
		}
		if(scelta==ID_QUINTA_VOCE_MENU){
			printf("\t%c Fine %c",FRECCETTE_DX,FRECCETTE_SX);
		}else{
			printf("\tFine");
		}
		printf("\n\n\n\nSU/GIU': Spostati nel men%c\t\t\t\t%c%c%c%c%c%c%cINVIO: Effettua scelta\n",151,SPAZIO,SPAZIO,SPAZIO,SPAZIO,SPAZIO,SPAZIO,SPAZIO);
	}
	return;
}

void pulire_interfaccia()
{
	system("CLS");
	stampare_logo();
	return;
}

void stampare_impostazioni(giocatore turno)
{
	pulire_interfaccia();
	printf("\t\t\t\t%c%c%cIMPOSTAZIONI\n\n\n\n",SPAZIO,SPAZIO,SPAZIO);
	printf("\tPrimo turno");
	if(turno==PC){
		printf("\t\t\t\t%c%cGIOCATORE%c%c\t%c PC %c\n\n\n\n",SPAZIO,SPAZIO,SPAZIO,SPAZIO,FRECCETTE_DX,FRECCETTE_SX);
	}else if(turno==GIOCATORE){
		printf("\t\t\t\t%c GIOCATORE %c\t%c%cPC%c%c\n\n\n\n",FRECCETTE_DX,FRECCETTE_SX,SPAZIO,SPAZIO,SPAZIO,SPAZIO);
	}
	return;
}

void stampare_logo()
{
	int i;
	i=0;
	while(i<NUM_COLONNE_INTERFACCIA){
		printf("*");
		i=spostare_avanti(i);
	}
	printf("\t\t\t\tGRUPPO 9 - \x1b[35mP\x1b[0m\x1b[31mE\x1b[0m\x1b[33mN\x1b[0m\x1b[32mT\x1b[0m\x1b[34mA\x1b[0m\x1b[36mG\x1b[0m\x1b[35mO\x1b[0m\n");
	i=0;
	while(i<NUM_COLONNE_INTERFACCIA){
		printf("*");
		i=spostare_avanti(i);
	}
	printf("\n\n");
	return;
}

void stampare_campo(campo campo,int x, int y)
{
	int i,j;
	int r,c;
	r=ERRORE;
	c=ERRORE;
	if((x==ERRORE&&y==ERRORE)||(x>=ID_PRIMA_RIGA_COLONNA&&x<DIMENSIONE_CAMPO&&y>=ID_PRIMA_RIGA_COLONNA&&y<DIMENSIONE_CAMPO)){
		pulire_interfaccia();
		if(x!=ERRORE&&y!=ERRORE){
			if(x==ID_PRIMA_RIGA_COLONNA){
				r=2;
			}else if(x==ID_SECONDA_RIGA_COLONNA){
				r=4;
			}else if(x==ID_TERZA_RIGA_COLONNA){
				r=6;
			}else if(x==ID_QUARTA_RIGA_COLONNA){
				r=9;
			}else if(x==ID_QUINTA_RIGA_COLONNA){
				r=11;
			}else if(x==ID_SESTA_RIGA_COLONNA){
				r=13;
			}
			if(y==ID_PRIMA_RIGA_COLONNA){
				c=4;
			}else if(y==ID_SECONDA_RIGA_COLONNA){
				c=8;
			}else if(y==ID_TERZA_RIGA_COLONNA){
				c=12;
			}else if(y==ID_QUARTA_RIGA_COLONNA){
				c=18;
			}else if(y==ID_QUINTA_RIGA_COLONNA){
				c=22;
			}else if(y==ID_SESTA_RIGA_COLONNA){
				c=26;
			}
		}
		i=0;
		while(i<16){
			printf("\t\t\t%c%c%c",SPAZIO,SPAZIO,SPAZIO);
			j=0;
			while(j<31){
					if(i==r&&j==c-1){
						if(x!=ERRORE&&y!=ERRORE){
							printf("%c",FRECCETTE_DX);
						}else{
							printf("%c",SPAZIO);
						}
					}else if(i==r&&j==c+1){
						if(x!=ERRORE&&y!=ERRORE){
							printf("%c",FRECCETTE_SX);
						}else{
							printf("%c",SPAZIO);
						}
					}else{
						if(i==0){
							if(j==0){
								printf("%c",201);
							}else if(j==30){
								printf("%c",187);
							}else{
								printf("%c",205);
							}
						}else if(i==1||i==8){
							if(j==1||j==29){
								printf("%c",SPAZIO);
							}else if(j==0||j==30){
								printf("%c",186);
							}else if(j==2||j==16){
								printf("%c",218);
							}else if(j==14||j==28){
								printf("%c",191);
							}else if(j==6||j==10||j==20||j==24){
								printf("%c",194);
							}else if(j==15){
								printf("%c",SPAZIO);
							}else{
								printf("%c",196);
							}
						}else if(i==7||i==14){
							if(j==1||j==29){
								printf("%c",SPAZIO);
							}else if(j==0||j==30){
								printf("%c",186);
							}else if(j==2||j==16){
								printf("%c",192);
							}else if(j==14||j==28){
								printf("%c",217);
							}else if(j==6||j==10||j==20||j==24){
								printf("%c",193);
							}else if(j==15){
								printf("%c",SPAZIO);
							}else{
								printf("%c",196);
							}
						}else if(i==3||i==5||i==10||i==12){
							if(j==1||j==29){
								printf("%c",SPAZIO);
							}else if(j==0||j==30){
								printf("%c",186);
							}else if(j==2||j==16){
								printf("%c",195);
							}else if(j==14||j==28){
								printf("%c",180);
							}else if(j==6||j==10||j==20||j==24){
								printf("%c",197);
							}else if(j==15){
								printf("%c",SPAZIO);
							}else{
								printf("%c",196);
							}
						}else if(i==15){
							if(j==0){
								printf("%c",200);
							}else if(j==30){
								printf("%c",188);
							}else{
								printf("%c",205);
							}
						}else if(i==2&&j==4){
							if(leggere(campo,0,0)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,0,0)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==2&&j==8){
							if(leggere(campo,0,1)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,0,1)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==2&&j==12){
							if(leggere(campo,0,2)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,0,2)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==2&&j==18){
							if(leggere(campo,0,3)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,0,3)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==2&&j==22){
							if(leggere(campo,0,4)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,0,4)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==2&&j==26){
							if(leggere(campo,0,5)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,0,5)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==4&&j==4){
							if(leggere(campo,1,0)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,1,0)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==4&&j==8){
							if(leggere(campo,1,1)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,1,1)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==4&&j==12){
							if(leggere(campo,1,2)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,1,2)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==4&&j==18){
							if(leggere(campo,1,3)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,1,3)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==4&&j==22){
							if(leggere(campo,1,4)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,1,4)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==4&&j==26){
							if(leggere(campo,1,5)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,1,5)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==6&&j==4){
							if(leggere(campo,2,0)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,2,0)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==6&&j==8){
							if(leggere(campo,2,1)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,2,1)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==6&&j==12){
							if(leggere(campo,2,2)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,2,2)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==6&&j==18){
							if(leggere(campo,2,3)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,2,3)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==6&&j==22){
							if(leggere(campo,2,4)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,2,4)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==6&&j==26){
							if(leggere(campo,2,5)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,2,5)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==9&&j==4){
							if(leggere(campo,3,0)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,3,0)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==9&&j==8){
							if(leggere(campo,3,1)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,3,1)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==9&&j==12){
							if(leggere(campo,3,2)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,3,2)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==9&&j==18){
							if(leggere(campo,3,3)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,3,3)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==9&&j==22){
							if(leggere(campo,3,4)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,3,4)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==9&&j==26){
							if(leggere(campo,3,5)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,3,5)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==11&&j==4){
							if(leggere(campo,4,0)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,4,0)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==11&&j==8){
							if(leggere(campo,4,1)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,4,1)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==11&&j==12){
							if(leggere(campo,4,2)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,4,2)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==11&&j==18){
							if(leggere(campo,4,3)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,4,3)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==11&&j==22){
							if(leggere(campo,4,4)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,4,4)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==11&&j==26){
							if(leggere(campo,4,5)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,4,5)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==13&&j==4){
							if(leggere(campo,5,0)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,5,0)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==13&&j==8){
							if(leggere(campo,5,1)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,5,1)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==13&&j==12){
							if(leggere(campo,5,2)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,5,2)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==13&&j==18){
							if(leggere(campo,5,3)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,5,3)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==13&&j==22){
							if(leggere(campo,5,4)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,5,4)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else if(i==13&&j==26){
							if(leggere(campo,5,5)==PEDINA_PC){
								printf("%c",184);
							}else if(leggere(campo,5,5)==PEDINA_GIOCATORE){
								printf("%c",79);
							}else{
								printf("%c",SPAZIO);
							}
						}else{
							if(j==1||j==29){
								printf("%c",SPAZIO);
							}else if(j==0||j==30){
								printf("%c",186);
							}else if(j==2||j==6||j==10||j==14||j==16||j==20||j==24||j==28){
								printf("%c",179);
							}else{
								printf("%c",SPAZIO);
							}
						}
					}
					j=spostare_avanti(j);
				}
			printf("\n");
			i=spostare_avanti(i);
		}
		printf("\n");
	}
	return;
}

void stampare_scelta_rotazione(int scelta)
{
	int i,j;
	if((scelta>=ID_PRIMA_SEZIONE&&scelta<=ID_RUOTA_DX)||scelta==ERRORE){
		i=0;
		while(i<3){
			printf("\t\t\t%c%c%c",SPAZIO,SPAZIO,SPAZIO);
			j=0;
			while(j<31){
				if(i==0){
					if(j==0||j==20){
						printf("%c",201);
					}else if(j==16||j==30){
						printf("%c",187);
					}else if(j==4||j==8||j==12||j==25){
						printf("%c",203);
					}else if(j>16&&j<20){
						printf("%c",SPAZIO);
					}else{
						printf("%c",205);
					}
				}else if(i==2){
					if(j==0||j==20){
						printf("%c",200);
					}else if(j==16||j==30){
						printf("%c",188);
					}else if(j==4||j==8||j==12||j==25){
						printf("%c",202);
					}else if(j>16&&j<20){
						printf("%c",SPAZIO);
					}else{
						printf("%c",205);
					}
				}else{
					if(j==0||j==4||j==8||j==12||j==16||j==20||j==25||j==30){
						printf("%c",186);
					}else if(scelta==ID_PRIMA_SEZIONE&&(j==1)){
						printf("%c",FRECCETTE_DX);
					}else if(j==2){
						printf("1");
					}else if(j==3&&scelta==ID_PRIMA_SEZIONE){
						printf("%c",FRECCETTE_SX);
					}else if(scelta==ID_SECONDA_SEZIONE&&j==5){
						printf("%c",FRECCETTE_DX);
					}else if(j==6){
						printf("2");
					}else if(scelta==ID_SECONDA_SEZIONE&&j==7){
						printf("%c",FRECCETTE_SX);
					}else if(scelta==ID_TERZA_SEZIONE&&j==9){
						printf("%c",FRECCETTE_DX);
					}else if(j==10){
						printf("3");
					}else if(scelta==ID_TERZA_SEZIONE&&j==11){
						printf("%c",FRECCETTE_SX);
					}else if(scelta==ID_QUARTA_SEZIONE&&j==13){
						printf("%c",FRECCETTE_DX);
					}else if(j==14){
						printf("4");
					}else if(scelta==ID_QUARTA_SEZIONE&&j==15){
						printf("%c",FRECCETTE_SX);
					}else if(j==21&&scelta==ID_RUOTA_SX){
						printf("%c",FRECCETTE_DX);
					}else if(j==22){
						printf("S");
					}else if(j==23){
						printf("X");
					}else if(j==24&&scelta==ID_RUOTA_SX){
						printf("%c",FRECCETTE_SX);
					}else if(j==26&&scelta==ID_RUOTA_DX){
						printf("%c",FRECCETTE_DX);
					}else if(j==27){
						printf("D");
					}else if(j==28){
						printf("X");
					}else if(j==29&&scelta==ID_RUOTA_DX){
						printf("%c",FRECCETTE_SX);
					}else{
						printf("%c",SPAZIO);
					}
				}
				j=spostare_avanti(j);
			}
			printf("\n");
			i=spostare_avanti(i);
		}
	}
	return;
}

void stampare_slot_partite(int i)
{
	if(i>=ID_PRIMO_SLOT&&i<NUM_SLOT){
		pulire_interfaccia();
		printf("\n\n\n");
		if(i==ID_PRIMO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("%c Slot1: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot1.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot1: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_SECONDO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("%c Slot2: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot2.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot2: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_TERZO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("%c Slot3: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot3.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot3: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_QUARTO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("%c Slot4: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot4.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot4: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_QUINTO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("%c Slot5: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot5.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot5: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_SESTO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("%c Slot6: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot6.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot6: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_SETTIMO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("%c Slot7: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot7.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot7: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_OTTAVO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("%c Slot8: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot8.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot8: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_NONO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("%c Slot9: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot9.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot9: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("Slot10: %s\n",leggere_data_partita("slot10.txt"));
			}else{
				printf("Slot10: VUOTO\n");
			}
		}else if(i==ID_DECIMO_SLOT){
			printf("\t\t\t");
			if(verificare_esistenza_file("slot1.txt")==VERO){
				printf("Slot1: %s\n",leggere_data_partita("slot1.txt"));
			}else{
				printf("Slot1: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot2.txt")==VERO){
				printf("Slot2: %s\n",leggere_data_partita("slot2.txt"));
			}else{
				printf("Slot2: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot3.txt")==VERO){
				printf("Slot3: %s\n",leggere_data_partita("slot3.txt"));
			}else{
				printf("Slot3: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot4.txt")==VERO){
				printf("Slot4: %s\n",leggere_data_partita("slot4.txt"));
			}else{
				printf("Slot4: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot5.txt")==VERO){
				printf("Slot5: %s\n",leggere_data_partita("slot5.txt"));
			}else{
				printf("Slot5: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot6.txt")==VERO){
				printf("Slot6: %s\n",leggere_data_partita("slot6.txt"));
			}else{
				printf("Slot6: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot7.txt")==VERO){
				printf("Slot7: %s\n",leggere_data_partita("slot7.txt"));
			}else{
				printf("Slot7: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot8.txt")==VERO){
				printf("Slot8: %s\n",leggere_data_partita("slot8.txt"));
			}else{
				printf("Slot8: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot9.txt")==VERO){
				printf("Slot9: %s\n",leggere_data_partita("slot9.txt"));
			}else{
				printf("Slot9: VUOTO\n");
			}
			printf("\t\t\t");
			if(verificare_esistenza_file("slot10.txt")==VERO){
				printf("%c Slot10: %s %c\n",FRECCETTE_DX,leggere_data_partita("slot10.txt"),FRECCETTE_SX);
			}else{
				printf("%c Slot10: VUOTO %c\n",FRECCETTE_DX,FRECCETTE_SX);
			}
		}
	}
	return;
}
