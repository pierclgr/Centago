#include "ia.h"

insieme_campi_ruotati generare_campi_ruotati(campo campo_di_gioco)
{
	insieme_campi_ruotati campi_ruotati;
	int i;
	campi_ruotati=malloc(NUM_POSSIBILI_ROTAZIONI*sizeof(campo));
	i=ID_PRIMA_SEZIONE;
	while(i<NUM_SOTTOCAMPI){
		campi_ruotati[i]=copiare_campo(campo_di_gioco);
		campi_ruotati[i+NUM_SOTTOCAMPI]=copiare_campo(campo_di_gioco);
		ruotare_campo(campi_ruotati[i],DX,i);
		ruotare_campo(campi_ruotati[i+NUM_SOTTOCAMPI],SX,i);
		i=spostare_avanti(i);
	}
	return campi_ruotati;
}

mossa_rotazione trovare_miglior_ruotato(campo campo_di_gioco)
{
	mossa_rotazione mossa;
	insieme_campi_ruotati campi;
	int i,j;
	int random;
	int max_campo,campo;
	srand(time(0));
	campi=generare_campi_ruotati(campo_di_gioco);
	campo=PRIMO_DX;
	i=PRIMO_DX;
	while(i<NUM_POSSIBILI_ROTAZIONI&&contare_num_pedine_serie(campi[i],PC,CINQUE_PEDINE)==FALSO){
		i=spostare_avanti(i);
	}
	if(i>=NUM_POSSIBILI_ROTAZIONI){
		i=PRIMO_DX;
		while(i<NUM_POSSIBILI_ROTAZIONI&&contare_num_pedine_serie(campi[i],PC,QUATTRO_PEDINE)==FALSO){
			i=spostare_avanti(i);
		}
	}
	if(i>=NUM_POSSIBILI_ROTAZIONI){
		i=PRIMO_DX;
		while(i<NUM_POSSIBILI_ROTAZIONI&&contare_num_pedine_serie(campi[i],GIOCATORE,TRE_PEDINE)==FALSO){
			i=spostare_avanti(i);
		}
		if(i>=NUM_POSSIBILI_ROTAZIONI){
			max_campo=ZERO_PEDINE;
			i=PRIMO_DX;
			while(i<NUM_POSSIBILI_ROTAZIONI){
				j=QUATTRO_PEDINE;
				while(j>ZERO_PEDINE){
					if(contare_num_pedine_serie(campi[i],PC,j-1)==VERO){
						if(j>max_campo){
							max_campo=j;
							campo=i;
						}
					}
					j=spostare_indietro(j);
				}
				i=spostare_avanti(i);
			}
		}else{
			max_campo=CINQUE_PEDINE;
			i=PRIMO_DX;
			while(i<NUM_POSSIBILI_ROTAZIONI){
				if(contare_num_pedine_serie(campi[i],GIOCATORE,CINQUE_PEDINE)!=VERO){
					if(contare_num_pedine_serie(campi[i],GIOCATORE,QUATTRO_PEDINE)==VERO){
						if(i<PRIMO_SX){
							campo=i+NUM_SOTTOCAMPI;
							if(contare_num_pedine_serie(campi[campo],GIOCATORE,CINQUE_PEDINE)==VERO){
								do{
									random=rand()%NUM_POSSIBILI_ROTAZIONI;
								}while(random==campo);
								campo=random;
							}
						}else{
							campo=i-NUM_SOTTOCAMPI;
							if(contare_num_pedine_serie(campi[campo],GIOCATORE,CINQUE_PEDINE)==VERO){
								do{
									random=rand()%NUM_POSSIBILI_ROTAZIONI;
								}while(random==campo);
								campo=random;
							}
						}
					}else{
						j=ZERO_PEDINE;
						while(j<QUATTRO_PEDINE){
							if(contare_num_pedine_serie(campi[i],GIOCATORE,j+1)==FALSO){
								if(j<max_campo){
									max_campo=j;
									campo=i;
								}
							}
							j=spostare_avanti(j);
						}
					}
				}else{
					if(i<NUM_SOTTOCAMPI){
						campo=i+NUM_SOTTOCAMPI;
						if(contare_num_pedine_serie(campi[campo],GIOCATORE,CINQUE_PEDINE)==VERO){
							do{
								random=rand()%NUM_POSSIBILI_ROTAZIONI;
							}while(random==campo);
							campo=random;
						}
					}else{
						campo=i-NUM_SOTTOCAMPI;
						if(contare_num_pedine_serie(campi[campo],GIOCATORE,CINQUE_PEDINE)==VERO){
							do{
								random=rand()%NUM_POSSIBILI_ROTAZIONI;
							}while(random==campo);
							campo=random;
						}
					}
				}
				i=spostare_avanti(i);
			}
		}
	}else{
		campo=i;
	}
	if(campo<NUM_SOTTOCAMPI){
		mossa.num_campo=campo;
		mossa.verso=DX;
	}else{
		mossa.num_campo=campo-NUM_SOTTOCAMPI;
		mossa.verso=SX;
	}
	return mossa;
}

pedina_verso* trovare_coppie_pedine_consecutive(campo campo_di_gioco,giocatore g)
{
	pedina_verso* coppia;
	int i,j,k;
	coppia=malloc(NUM_CASELLE*sizeof(pedina_verso));
	k=ID_PRIMA_COPPIA;
	while(k<NUM_CASELLE){
		coppia[k].coordinata.x=ERRORE;
		coppia[k].coordinata.y=ERRORE;
		k=spostare_avanti(k);
	}
	if(g==GIOCATORE){
		k=ID_PRIMA_COPPIA;
		i=ID_PRIMA_RIGA_COLONNA;
		while(i<DIMENSIONE_CAMPO){
			j=ID_PRIMA_RIGA_COLONNA;
			while(j<DIMENSIONE_CAMPO){
				if(leggere(campo_di_gioco,i,j)==PEDINA_GIOCATORE){
					if(i!=ID_SESTA_RIGA_COLONNA){
						if(j!=ID_PRIMA_RIGA_COLONNA){
							if(leggere(campo_di_gioco,i,spostare_avanti(j))==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=ORIZZONTALE;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),spostare_avanti(j))==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=SINISTRA;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),j)==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=VERTICALE;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),spostare_indietro(j))==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=DESTRA;
								k=spostare_avanti(k);
							}
						}else if(j==ID_PRIMA_RIGA_COLONNA){
							if(leggere(campo_di_gioco,i,spostare_avanti(j))==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=ORIZZONTALE;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),spostare_avanti(j))==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=SINISTRA;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),j)==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=VERTICALE;
								k=spostare_avanti(k);
							}
						}else if(j==ID_SESTA_RIGA_COLONNA){
							if(leggere(campo_di_gioco,spostare_avanti(i),j)==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=VERTICALE;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),spostare_indietro(j))==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=DESTRA;
								k=spostare_avanti(k);
							}
						}
					}else{
						if(j!=ID_SESTA_RIGA_COLONNA){
							if(leggere(campo_di_gioco,i,spostare_avanti(j))==PEDINA_GIOCATORE){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=ORIZZONTALE;
								k=spostare_avanti(k);
							}
						}
					}
				}
				j=spostare_avanti(j);
			}
			i=spostare_avanti(i);
		}
	}else if(g==PC){
		k=ID_PRIMA_COPPIA;
		i=ID_PRIMA_RIGA_COLONNA;
		while(i<DIMENSIONE_CAMPO){
			j=ID_PRIMA_RIGA_COLONNA;
			while(j<DIMENSIONE_CAMPO){
				if(leggere(campo_di_gioco,i,j)==PEDINA_PC){
					if(i!=ID_SESTA_RIGA_COLONNA){
						if(j!=ID_PRIMA_RIGA_COLONNA){
							if(leggere(campo_di_gioco,i,spostare_avanti(j))==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=ORIZZONTALE;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),spostare_avanti(j))==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=SINISTRA;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),j)==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=VERTICALE;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),spostare_indietro(j))==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=DESTRA;
								k=spostare_avanti(k);
							}
						}else if(j==ID_PRIMA_RIGA_COLONNA){
							if(leggere(campo_di_gioco,i,spostare_avanti(j))==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=ORIZZONTALE;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),spostare_avanti(j))==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=SINISTRA;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),j)==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=VERTICALE;
								k=spostare_avanti(k);
							}
						}else if(j==ID_SESTA_RIGA_COLONNA){
							if(leggere(campo_di_gioco,spostare_avanti(i),j)==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=VERTICALE;
								k=spostare_avanti(k);
							}else if(leggere(campo_di_gioco,spostare_avanti(i),spostare_indietro(j))==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=DESTRA;
								k=spostare_avanti(k);
							}
						}
					}else{
						if(j!=ID_SESTA_RIGA_COLONNA){
							if(leggere(campo_di_gioco,i,spostare_avanti(j))==PEDINA_PC){
								coppia[k].coordinata.x=i;
								coppia[k].coordinata.y=j;
								coppia[k].verso=ORIZZONTALE;
								k=spostare_avanti(k);
							}
						}
					}
				}
				j=spostare_avanti(j);
			}
			i=spostare_avanti(i);
		}
	}
	return coppia;
}

coordinata trovare_casella_posizionabile(campo campo_gioco,pedina_verso coppia,giocatore g)
{
	int i;
	coordinata coordinata;
	if(coppia.coordinata.x!=ERRORE&&coppia.coordinata.y!=ERRORE){
		if(g==GIOCATORE){
			if(coppia.verso==ORIZZONTALE){
				i=DISTANZA_PRIMA_PEDINA_COPPIA;
				while(coppia.coordinata.y+i<DIMENSIONE_CAMPO&&leggere(campo_gioco,coppia.coordinata.x,coppia.coordinata.y+i)==PEDINA_GIOCATORE){
					i=spostare_avanti(i);
				}
				if(coppia.coordinata.y+i<DIMENSIONE_CAMPO&&leggere(campo_gioco,coppia.coordinata.x,coppia.coordinata.y+i)==VUOTA){
					coordinata.x=coppia.coordinata.x;
					coordinata.y=coppia.coordinata.y+i;
				}else{
					i=DISTANZA_PRIMA_PEDINA_COPPIA_INV;
					while(coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA&&leggere(campo_gioco,coppia.coordinata.x,coppia.coordinata.y-i)==PEDINA_GIOCATORE){
						i=spostare_avanti(i);
					}
					if(coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA&&leggere(campo_gioco,coppia.coordinata.x,coppia.coordinata.y-i)==VUOTA){
						coordinata.x=coppia.coordinata.x;
						coordinata.y=coppia.coordinata.y-i;
					}else{
						coordinata.x=ERRORE;
						coordinata.y=ERRORE;
					}
				}
			}else if(coppia.verso==VERTICALE){
				i=DISTANZA_PRIMA_PEDINA_COPPIA;
				while(coppia.coordinata.x+i<DIMENSIONE_CAMPO&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y)==PEDINA_GIOCATORE){
					i=spostare_avanti(i);
				}
				if(coppia.coordinata.x+i<DIMENSIONE_CAMPO&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y)==VUOTA){
					coordinata.x=coppia.coordinata.x+i;
					coordinata.y=coppia.coordinata.y;
				}else{
					i=DISTANZA_PRIMA_PEDINA_COPPIA_INV;
					while(coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y)==PEDINA_GIOCATORE){
						i=spostare_avanti(i);
					}
					if(coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y)==VUOTA){
						coordinata.x=coppia.coordinata.x-i;
						coordinata.y=coppia.coordinata.y;
					}else{
						coordinata.x=ERRORE;
						coordinata.y=ERRORE;
					}
				}
			}else if(coppia.verso==DESTRA){
				i=DISTANZA_PRIMA_PEDINA_COPPIA;
				while((coppia.coordinata.x+i<DIMENSIONE_CAMPO&&coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA)&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y-i)==PEDINA_GIOCATORE){
					i=spostare_avanti(i);
				}
				if((coppia.coordinata.x+i<DIMENSIONE_CAMPO&&coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA)&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y-i)==VUOTA){
					coordinata.x=coppia.coordinata.x+i;
					coordinata.y=coppia.coordinata.y-i;
				}else{
					i=DISTANZA_PRIMA_PEDINA_COPPIA_INV;
					while((coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&coppia.coordinata.y+i<DIMENSIONE_CAMPO)&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y+i)==PEDINA_GIOCATORE){
						i=spostare_avanti(i);
					}
					if((coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&coppia.coordinata.y+i<DIMENSIONE_CAMPO)&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y+i)==VUOTA){
						coordinata.x=coppia.coordinata.x-i;
						coordinata.y=coppia.coordinata.y+i;
					}else{
						coordinata.x=ERRORE;
						coordinata.y=ERRORE;
					}
				}
			}else if(coppia.verso==SINISTRA){
				i=DISTANZA_PRIMA_PEDINA_COPPIA;
				while((coppia.coordinata.x+i<DIMENSIONE_CAMPO&&coppia.coordinata.y+i<DIMENSIONE_CAMPO)&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y+i)==PEDINA_GIOCATORE){
					i=spostare_avanti(i);
				}
				if((coppia.coordinata.x+i<DIMENSIONE_CAMPO&&coppia.coordinata.y+i<DIMENSIONE_CAMPO)&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y+i)==VUOTA){
					coordinata.x=coppia.coordinata.x+i;
					coordinata.y=coppia.coordinata.y+i;
				}else{
					i=DISTANZA_PRIMA_PEDINA_COPPIA_INV;
					while((coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA)&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y-i)==PEDINA_GIOCATORE){
						i=spostare_avanti(i);
					}
					if((coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA)&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y-i)==VUOTA){
						coordinata.x=coppia.coordinata.x-i;
						coordinata.y=coppia.coordinata.y-i;
					}else{
						coordinata.x=ERRORE;
						coordinata.y=ERRORE;
					}
				}
			}
		}else if(g==PC){
			if(coppia.verso==ORIZZONTALE){
				i=DISTANZA_PRIMA_PEDINA_COPPIA;
				while(coppia.coordinata.y+i<DIMENSIONE_CAMPO&&leggere(campo_gioco,coppia.coordinata.x,coppia.coordinata.y+i)==PEDINA_PC){
					i=spostare_avanti(i);
				}
				if(coppia.coordinata.y+i<DIMENSIONE_CAMPO&&leggere(campo_gioco,coppia.coordinata.x,coppia.coordinata.y+i)==VUOTA){
					coordinata.x=coppia.coordinata.x;
					coordinata.y=coppia.coordinata.y+i;
				}else{
					i=DISTANZA_PRIMA_PEDINA_COPPIA_INV;
					while(coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA&&leggere(campo_gioco,coppia.coordinata.x,coppia.coordinata.y-i)==PEDINA_PC){
						i=spostare_avanti(i);
					}
					if(coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA&&leggere(campo_gioco,coppia.coordinata.x,coppia.coordinata.y-i)==VUOTA){
						coordinata.x=coppia.coordinata.x;
						coordinata.y=coppia.coordinata.y-i;
					}else{
						coordinata.x=ERRORE;
						coordinata.y=ERRORE;
					}
				}
			}else if(coppia.verso==VERTICALE){
				i=DISTANZA_PRIMA_PEDINA_COPPIA;
				while(coppia.coordinata.x+i<DIMENSIONE_CAMPO&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y)==PEDINA_PC){
					i=spostare_avanti(i);
				}
				if(coppia.coordinata.x+i<DIMENSIONE_CAMPO&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y)==VUOTA){
					coordinata.x=coppia.coordinata.x+i;
					coordinata.y=coppia.coordinata.y;
				}else{
					i=DISTANZA_PRIMA_PEDINA_COPPIA_INV;
					while(coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y)==PEDINA_PC){
						i=spostare_avanti(i);
					}
					if(coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y)==VUOTA){
						coordinata.x=coppia.coordinata.x-i;
						coordinata.y=coppia.coordinata.y;
					}else{
						coordinata.x=ERRORE;
						coordinata.y=ERRORE;
					}
				}
			}else if(coppia.verso==DESTRA){
				i=DISTANZA_PRIMA_PEDINA_COPPIA;
				while((coppia.coordinata.x+i<DIMENSIONE_CAMPO&&coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA)&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y-i)==PEDINA_PC){
					i=spostare_avanti(i);
				}
				if((coppia.coordinata.x+i<DIMENSIONE_CAMPO&&coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA)&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y-i)==VUOTA){
					coordinata.x=coppia.coordinata.x+i;
					coordinata.y=coppia.coordinata.y-i;
				}else{
					i=DISTANZA_PRIMA_PEDINA_COPPIA_INV;
					while((coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&coppia.coordinata.y+i<DIMENSIONE_CAMPO)&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y+i)==PEDINA_PC){
						i=spostare_avanti(i);
					}
					if((coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&coppia.coordinata.y+i<DIMENSIONE_CAMPO)&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y+i)==VUOTA){
						coordinata.x=coppia.coordinata.x-i;
						coordinata.y=coppia.coordinata.y+i;
					}else{
						coordinata.x=ERRORE;
						coordinata.y=ERRORE;
					}
				}
			}else if(coppia.verso==SINISTRA){
				i=DISTANZA_PRIMA_PEDINA_COPPIA;
				while((coppia.coordinata.x+i<DIMENSIONE_CAMPO&&coppia.coordinata.y+i<DIMENSIONE_CAMPO)&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y+i)==PEDINA_PC){
					i=spostare_avanti(i);
				}
				if((coppia.coordinata.x+i<DIMENSIONE_CAMPO&&coppia.coordinata.y+i<DIMENSIONE_CAMPO)&&leggere(campo_gioco,coppia.coordinata.x+i,coppia.coordinata.y+i)==VUOTA){
					coordinata.x=coppia.coordinata.x+i;
					coordinata.y=coppia.coordinata.y+i;
				}else{
					i=DISTANZA_PRIMA_PEDINA_COPPIA_INV;
					while((coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA)&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y-i)==PEDINA_PC){
						i=spostare_avanti(i);
					}
					if((coppia.coordinata.x-i>=ID_PRIMA_RIGA_COLONNA&&coppia.coordinata.y-i>=ID_PRIMA_RIGA_COLONNA)&&leggere(campo_gioco,coppia.coordinata.x-i,coppia.coordinata.y-i)==VUOTA){
						coordinata.x=coppia.coordinata.x-i;
						coordinata.y=coppia.coordinata.y-i;
					}else{
						coordinata.x=ERRORE;
						coordinata.y=ERRORE;
					}
				}
			}
		}
	}else{
		coordinata.x=ERRORE;
		coordinata.y=ERRORE;
	}
	return coordinata;
}

coordinata scegliere_coppia(campo campo_gioco,giocatore g)
{
	coordinata coordinata;
	pedina_verso* coppie;
	int i;
	if(g==GIOCATORE||g==PC){
		coppie=trovare_coppie_pedine_consecutive(campo_gioco,g);
		i=ID_PRIMA_COPPIA;
		do{
			coordinata=trovare_casella_posizionabile(campo_gioco,coppie[i],g);
			i=spostare_avanti(i);
		}while(i<NUM_CASELLE&&coordinata.x==ERRORE&&coordinata.y==ERRORE);
	}else{
		coordinata.x=ERRORE;
		coordinata.y=ERRORE;
	}
	return coordinata;
}

campo copiare_campo(campo campo_di_gioco)
{
	campo nuovo_campo;
	int i,j;
	nuovo_campo=inizializzare();
	i=ID_PRIMA_RIGA_COLONNA;
	while(i<DIMENSIONE_CAMPO){
		j=ID_PRIMA_RIGA_COLONNA;
		while(j<DIMENSIONE_CAMPO){
			scrivere(nuovo_campo,i,j,leggere(campo_di_gioco,i,j));
			j=spostare_avanti(j);
		}
		i=spostare_avanti(i);
	}
	return nuovo_campo;
}

coordinata posizionare_per_priorita(campo campo_gioco)
{
	coordinata coordinata;
	if(controllare_casella_libera(campo_gioco,ID_SECONDA_RIGA_COLONNA,ID_SECONDA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SECONDA_RIGA_COLONNA;
		coordinata.y=ID_SECONDA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUINTA_RIGA_COLONNA,ID_QUINTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUINTA_RIGA_COLONNA;
		coordinata.y=ID_QUINTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SECONDA_RIGA_COLONNA,ID_QUINTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SECONDA_RIGA_COLONNA;
		coordinata.y=ID_QUINTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUINTA_RIGA_COLONNA,ID_SECONDA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUINTA_RIGA_COLONNA;
		coordinata.y=ID_SECONDA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_TERZA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_TERZA_RIGA_COLONNA;
		coordinata.y=ID_TERZA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUARTA_RIGA_COLONNA,ID_QUARTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUARTA_RIGA_COLONNA;
		coordinata.y=ID_QUARTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_TERZA_RIGA_COLONNA,ID_QUARTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_TERZA_RIGA_COLONNA;
		coordinata.y=ID_QUARTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUARTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUARTA_RIGA_COLONNA;
		coordinata.y=ID_TERZA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_PRIMA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_PRIMA_RIGA_COLONNA;
		coordinata.y=ID_PRIMA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_PRIMA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_PRIMA_RIGA_COLONNA;
		coordinata.y=ID_SESTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SESTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SESTA_RIGA_COLONNA;
		coordinata.y=ID_PRIMA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SESTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SESTA_RIGA_COLONNA;
		coordinata.y=ID_SESTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_PRIMA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_PRIMA_RIGA_COLONNA;
		coordinata.y=ID_TERZA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_PRIMA_RIGA_COLONNA,ID_QUARTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_PRIMA_RIGA_COLONNA;
		coordinata.y=ID_QUARTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SESTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SESTA_RIGA_COLONNA;
		coordinata.y=ID_TERZA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SESTA_RIGA_COLONNA,ID_QUARTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SESTA_RIGA_COLONNA;
		coordinata.y=ID_QUARTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SECONDA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SECONDA_RIGA_COLONNA;
		coordinata.y=ID_TERZA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SECONDA_RIGA_COLONNA,ID_QUARTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SECONDA_RIGA_COLONNA;
		coordinata.y=ID_QUARTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_TERZA_RIGA_COLONNA,ID_SECONDA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_TERZA_RIGA_COLONNA;
		coordinata.y=ID_SECONDA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_TERZA_RIGA_COLONNA,ID_QUINTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_TERZA_RIGA_COLONNA;
		coordinata.y=ID_QUINTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUARTA_RIGA_COLONNA,ID_SECONDA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUARTA_RIGA_COLONNA;
		coordinata.y=ID_SECONDA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUARTA_RIGA_COLONNA,ID_QUINTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUARTA_RIGA_COLONNA;
		coordinata.y=ID_QUINTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUINTA_RIGA_COLONNA,ID_TERZA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUINTA_RIGA_COLONNA;
		coordinata.y=ID_TERZA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUINTA_RIGA_COLONNA,ID_QUARTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUINTA_RIGA_COLONNA;
		coordinata.y=ID_QUARTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SECONDA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SECONDA_RIGA_COLONNA;
		coordinata.y=ID_PRIMA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_TERZA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_TERZA_RIGA_COLONNA;
		coordinata.y=ID_SESTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUARTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUARTA_RIGA_COLONNA;
		coordinata.y=ID_PRIMA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUARTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUARTA_RIGA_COLONNA;
		coordinata.y=ID_SESTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_PRIMA_RIGA_COLONNA,ID_QUINTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_PRIMA_RIGA_COLONNA;
		coordinata.y=ID_QUINTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_PRIMA_RIGA_COLONNA,ID_SECONDA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_PRIMA_RIGA_COLONNA;
		coordinata.y=ID_SECONDA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUINTA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUINTA_RIGA_COLONNA;
		coordinata.y=ID_SESTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_QUINTA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_QUINTA_RIGA_COLONNA;
		coordinata.y=ID_PRIMA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SESTA_RIGA_COLONNA,ID_SECONDA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SESTA_RIGA_COLONNA;
		coordinata.y=ID_SECONDA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SESTA_RIGA_COLONNA,ID_QUINTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SESTA_RIGA_COLONNA;
		coordinata.y=ID_QUINTA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_TERZA_RIGA_COLONNA,ID_PRIMA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_TERZA_RIGA_COLONNA;
		coordinata.y=ID_PRIMA_RIGA_COLONNA;
	}else if(controllare_casella_libera(campo_gioco,ID_SECONDA_RIGA_COLONNA,ID_SESTA_RIGA_COLONNA)==VERO){
		coordinata.x=ID_SECONDA_RIGA_COLONNA;
		coordinata.y=ID_SESTA_RIGA_COLONNA;
	}else{
		coordinata.x=ERRORE;
		coordinata.y=ERRORE;
	}
	return coordinata;
}

