#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//vidas
//balancear experiencia y dinero(?)
//refactorizar codigo
//reparar experiencia(done)
//modificadores stats(done)
//diferentes enemigos(done)
//bonus experiancia(done)
//reparar zonas(done)




struct stat{
	int vida ;
	int ataque;
	int especial;
	int defensa;
	int defensaEsp;
	int velocidad;
	int experiencia;
	int nivel;

};

struct Mochila{
	int numPotPeq;
	int numPotGan;
	int numGalleta;
	int numPotInvin;
	int numPotExp;
	int numPotVel;
};

struct personaje{
	struct stat puntos;
	char nombre[30];
	int dinero;
    int vidas;

};



struct personaje aliado;
struct personaje enemigo;
struct Mochila mochila;

int flagAlly;
int flagEnemy;
int flagEnd;
int diferenciadorInicio;
int aliado_puntos_vida_MAX;
int enemigo_puntos_vida_MAX;
int zona_MAX;
float bonusExp;
int flagBonusSpeed;
int contadorBoss=1;
int BonusZona;
int selectorZona;
int expGanada;
int selectorAccionCombate;
int randomEnemigo;
int indexEnemigo;
int PuntoStat;
int zonaMax;



void Combate();
int Random115();
int Random160();
int DanyoAliado();
int DanyoAliadoEspecial();
int DanyoEnemigo();
int DanyoEnemigoEspecial();
void Atacar();
int AtacarAliado();
int AtacarAliadoEspecial();
int AtacarEnemigo();
int AtacarEnemigoEspecial();
void Defender();
void DefenderEnemigo();//no acabada, demasiado trabajo... Un NPC nunca se defiende de todas maneras
int Inventario();
void CrearPersonaje();
void CargaPersonaje();
void GuardarPersonaje();
void BorrarPersonaje();
void subirNivel();
void experiencia();
void Tienda();
void stats();
void GeneracionEnemigoTankAD();
void GeneracionEnemigoTankAP();
void GeneracionEnemigoADC();
void GeneracionEnemigoAPC();
void GeneracionEnemigoQuick();
void GeneracionEnemigoAverage();
void seleccionEnemigo();
void Zona();
void regenAliado();
void regenEnemigo();
void ModificadorStat();
void IA();




int main(){
    int selector, flagGuardar, flagSalir, i;
    int end=flagGuardar=0;


    srand(time(NULL));/*Nueva seed aleatoria*/

    printf("Bienvenido!\nEste juego ha sido creado enteramente por Santiago Mas\nPendiente de obtencion de derechos de autoria\nDisfruta!");
    CargaPersonaje();
    if(diferenciadorInicio!=1){
        printf("Parece que no tienes un personaje creado. Quieres hacerte uno?\n1:Si  0:No\n");
        scanf("%d", &i);
        if(i==1){
            CrearPersonaje();
        }
    }
    printf("\nMenu principal:\n1)Crear tu personaje\n2)Borrar tu personaje\n3)Cargar tu personaje\n4)Guargar tu perfil\n5)Combatir\n6)Ver stats\n7)Tienda\n8)Zona\n9)Modificar Stat\n20)Salir\nQue quieres hacer?:");
    scanf("%d", &selector);

    //BorrarPersonaje();
    while(selector<=20 && end==0){
    if(selector==1){
        CrearPersonaje();
    }
    else if(selector==2){
        printf("Estas seguro que quieres borrar la partida? Una vez lo hagas no podras recuperar los datos.\nQuieres continuar?  Si=1 No=0 ->");
        scanf("%d", &flagSalir);
        if(flagSalir==0){
            printf("\nNo se ha borrado la partida\n");
            }
    else{
        BorrarPersonaje();
        }
    }
    else if(selector==3){
        CargaPersonaje();
    }
    else if(selector==4){
        GuardarPersonaje();
    }
    else if(selector==5){
        Combate();
       /*if(aliado.vidas<1){
            printf("Te has quedado sin vidas.\nNo puedes seguir jugando.");
           // BorrarPersonaje();
		}*/
    }
    else if(selector==6){
        stats();
    }
    else if(selector==7){
        Tienda();
    }
    else if(selector==8){
        Zona();

    }
    else if(selector==9){
        ModificadorStat();
    }
   /* else if(selector==11){//dev
        aliado.dinero=aliado.dinero+10000;
        printf("+10000G");
    }
    else if(selector==12){//dev
        expGanada=100000;
        experiencia();
    }*/

    else if(selector==20){
        printf("Antes de salir, quieres guardar la partida?\nSi:1, No:0 ->");
        scanf("%d", &flagGuardar);
        if(flagGuardar==1){
            GuardarPersonaje();
             printf("Deseas salir de verdad?\nSi:1, No:0 ->");
        scanf("%d", &flagSalir);
        if(flagSalir==1){
                printf("Hasta pronto!");
            return 0;
        }
        }
        else{
                printf("Deseas salir de verdad?\nSi:1, No:0 ->");
        scanf("%d", &flagSalir);
        if(flagSalir==1){
                printf("Hasta pronto!");
            return 0;
        }
        }

    }
        printf("\nMenu principal:\n1)Crear tu personaje\n2)Borrar tu personaje\n3)Cargar tu personaje\n4)Guargar tu perfil\n5)Combatir\n6)Ver stats\n7)Tienda\n8)Zona\n9)Modificar stat\n20)Salir\nQue quieres hacer?:");
        scanf("%d", &selector);
    }
    return 0;
}

void Combate(){
	int /*i,*/ aleatorio;
	//char auxiliar[30];

//introduccion banderas
    flagAlly=0;
    flagEnemy=0;
    BonusZona=1;

	/*datos preparados*/
	/*aliado.puntos.vida=100;
	aliado.puntos.ataque=50;
	aliado.puntos.defensa=10;
	aliado.puntos.velocidad=100;
	aliado.puntos.nivel=1;
*/
	/*enemigo.puntos.vida=enemigo_puntos_vida_MAX=6;
	enemigo.puntos.ataque=5;
	enemigo.puntos.defensa=7;
	enemigo.puntos.velocidad=15;
	enemigo.puntos.nivel=1;*/


	bonusExp=1;

	//mochila.numPotGan=3;
	//mochila.numPotPeq=3;
	//mochila.numPotInvin=3;
	//mochila.numGalleta=3;
   // mochila.numPotExp=3;

   // GeneracionEnemigo();
   seleccionEnemigo();
   printf("%d\n",indexEnemigo);
	printf("Comienza el combate \n");
    /*if(aliado.puntos.nivel<enemigo.puntos.nivel){
        printf("Ha aparecido un jefe! Cuidado,son muy peligrosos!");
    }*/
	while(aliado.puntos.vida>0||enemigo.puntos.vida>0){
		printf("\nVida %s: %d/%d\t Vida %s: %d/%d\n", aliado.nombre,aliado.puntos.vida,aliado_puntos_vida_MAX,
          enemigo.nombre, enemigo.puntos.vida, enemigo_puntos_vida_MAX);
		//aliado.tipo=1;                                                                                 111111111122222222223333333
		//enemigo.tipo=2;                                           /*36 caracteres      123456789012345678901234567890123456*/
		printf("Ataque fisico=1    Ataque especial=2   Defender=3   Stats=4   Mochila=5   Huir=10\nQue quieres hacer: ");
		scanf("%d", &selectorAccionCombate);
		if(selectorAccionCombate==1){/*ataques*/
            Atacar();
            if(flagEnd==1){
                aliado.puntos.vida=aliado_puntos_vida_MAX;
                return;
            }
		regenAliado();
        regenEnemigo();
		}
		else if(selectorAccionCombate==3){/*defensa*/
			Defender();

			if(flagEnd==1){
			    aliado.puntos.vida=aliado_puntos_vida_MAX;
                return;
			}
			regenAliado();
			regenEnemigo();
            }
		else if(selectorAccionCombate==5){/*objetos*/
			Inventario();
			if(flagEnd==1){
			    aliado.puntos.vida=aliado_puntos_vida_MAX;
                return;
			}
			regenAliado();
			regenEnemigo();

			}
        else if(selectorAccionCombate==4){
            stats();
        }
        else if(selectorAccionCombate==11){
            printf("nivel: %d Ataque:%d Especial:%d Defensa:%d Defensa Especial:%d Vida:%d Velocidad:%d\n "
                   ,enemigo.puntos.nivel, enemigo.puntos.ataque,enemigo.puntos.especial, enemigo.puntos.defensa,enemigo.puntos.defensaEsp,
                    enemigo_puntos_vida_MAX, enemigo.puntos.velocidad);

        }
        else if(selectorAccionCombate==2){
                Atacar();
        if(flagEnd==1){
                aliado.puntos.vida=aliado_puntos_vida_MAX;
            return;
		}
		regenAliado();
        regenEnemigo();
		}

        /*else if(selectorAccionCombate==7){
            printf("%d", expGanada);
        }*/
        else if(selectorAccionCombate==10){
                //printf("%d", aleatorio);
                if(Random100()>80){
                    printf("Escapaste del combate.");
                      aliado.puntos.vida=aliado_puntos_vida_MAX;
                    break;
                }
                else{
                        printf("No pudiste escapar del combate.\n");
                    AtacarEnemigo();
                }
		}
	}
	flagBonusSpeed=0;
}

int Random115(){
	int numero;

	numero=rand();
	while(numero>115||numero<85){
		numero=rand();
	}
	return numero;
}

int Random160(){
	int numero;

	numero=rand();
	while(numero>160||numero<40){
		numero=rand();
	}
	return numero;
}

int Random100(){
	int numero;

	numero=rand();
	while(numero>100||numero<0){
		numero=rand();
	}
	return numero;
}

int DanyoAliado(){
	float ataque;
	//int aleatorio;

	//aleatorio=Random();
	ataque=0.01 * Random115()* (((0.2 * aliado.puntos.nivel+1)*50 * aliado.puntos.ataque)/(25 * enemigo.puntos.defensa)+2);
	return ataque;
}

int DanyoAliadoEspecial(){
float ataqueEspecial;
	//int aleatorio;

	//aleatorio=Random();
	ataqueEspecial=0.01 * Random115()* (((0.2 * aliado.puntos.nivel+1)*50 * aliado.puntos.especial)/(25 * enemigo.puntos.defensaEsp)+2);
	return ataqueEspecial;

}

int DanyoEnemigo(){
	float ataque;

	//aleatorio=Random();
	ataque=0.01 *Random115() * (((0.2 * enemigo.puntos.nivel+1) *50* enemigo.puntos.ataque)/(25 * aliado.puntos.defensa)+2);
	return ataque;
}

int DanyoEnemigoEspecial(){
float ataqueEspecial;

	//aleatorio=Random();
	ataqueEspecial=0.01 *Random115() * (((0.2 * enemigo.puntos.nivel+1) *50* enemigo.puntos.especial)/(25 * aliado.puntos.defensaEsp)+2);
	return ataqueEspecial;
}

void regenAliado(){
    int regen;

        regen=aliado.puntos.nivel*.55;
		if(aliado.puntos.vida<aliado_puntos_vida_MAX){
		aliado.puntos.vida=aliado.puntos.vida+ regen;
		printf("Has recuperado %d puntos de vida\n", (regen));
		if(aliado.puntos.vida>aliado_puntos_vida_MAX){
            aliado.puntos.vida=aliado_puntos_vida_MAX;
            }
		}
		return;
}

void regenEnemigo(){
    int regen;

        regen=enemigo.puntos.nivel*.55;
		if(enemigo.puntos.vida<enemigo_puntos_vida_MAX){
		enemigo.puntos.vida=enemigo.puntos.vida+regen;
		printf("%s ha recuperado %d puntos de vida\n", enemigo.nombre, (regen));
		if(enemigo.puntos.vida>enemigo_puntos_vida_MAX){
            enemigo.puntos.vida=enemigo_puntos_vida_MAX;
            }
		}
    return;
}

void Atacar(){
    int velocidadAux;
    if(flagBonusSpeed>0){
        velocidadAux=aliado.puntos.velocidad*2;
    }

    if(velocidadAux>enemigo.puntos.velocidad){
            if(selectorAccionCombate==1){
        AtacarAliado();
        if(flagEnd==1){
            return;
            }
        AtacarEnemigo();
        if(flagEnd==1){
            return;
            }
        }
        else if(selectorAccionCombate==2){
            AtacarAliadoEspecial();
        if(flagEnd==1){
            return;
            }
        AtacarEnemigoEspecial();
        if(flagEnd==1){
            return;
            }
        }
    }
    else if(velocidadAux<enemigo.puntos.velocidad){
            if(selectorAccionCombate==1){
        AtacarEnemigo();
        if(flagEnd==1){
            return;
            }
        AtacarAliado();
        if(flagEnd==1){
            return;
            }
        }
        else if(selectorAccionCombate==2){
            AtacarEnemigo();
        if(flagEnd==1){
            return;
            }
        AtacarAliado();
        if(flagEnd==1){
            return;
            }
        }
    }
    else if(enemigo.puntos.velocidad==velocidadAux){
        if(Random115()>100){
                if(selectorAccionCombate==1){
                  AtacarAliado();
            if(flagEnd==1){
                return;
                }
            AtacarEnemigo();
            if(flagEnd==1){
                return;
				}
                }
                else if(selectorAccionCombate==6){
                    AtacarAliado();
                    if(flagEnd==1){
                        return;
                        }
                    AtacarEnemigo();
                    if(flagEnd==1){
                        return;
                        }
                    }

                }
        else{
            //printf("2");
           if(selectorAccionCombate==1){
                  AtacarAliado();
            if(flagEnd==1){
                return;
                }
            AtacarEnemigo();
            if(flagEnd==1){
                return;
				}
                }
                else if(selectorAccionCombate==6){
                    AtacarAliado();
                    if(flagEnd==1){
                        return;
                        }
                    AtacarEnemigo();
                    if(flagEnd==1){
                        return;
                        }
                    }

                }
        }
	flagBonusSpeed--;
}

void IA(){
int selector, aleatorio;

aleatorio=Random100();

    if(enemigo.puntos.ataque<enemigo.puntos.especial){
        if(aleatorio>15){
            AtacarEnemigoEspecial();
        }
        else{
            AtacarEnemigo();
        }
    }
    else if(enemigo.puntos.ataque>enemigo.puntos.especial){
        if(aleatorio>15){
            AtacarEnemigo();
        }
        else{
             AtacarEnemigoEspecial();
        }
    }
    else{
        if(aleatorio>50){
            AtacarEnemigo();
        }
        else{
            AtacarEnemigoEspecial();
        }
    }
}

int AtacarAliado(){
    int danyoAliado=0;

    danyoAliado=DanyoAliado();
    flagEnd=0;
    if(enemigo.puntos.vida-danyoAliado<=0){
            printf("\nHas hecho %d puntos de daño.\n",danyoAliado );
            enemigo.puntos.vida=enemigo.puntos.vida-danyoAliado;
            printf("Vida %s: %d, Vida %s: 0\nAcaba el combate. Ganador: ALIADO\n",aliado.nombre, aliado.puntos.vida, enemigo.nombre);
            printf("Has ganado %d G.\n", (10 +enemigo.puntos.nivel*3));
            aliado.dinero=(aliado.dinero+(10+enemigo.puntos.nivel*3));
            experiencia();
            GuardarPersonaje();
            flagEnd=1;
            return 0;
            }
    else{
    enemigo.puntos.vida=enemigo.puntos.vida-danyoAliado;
    printf("Has hecho %d puntos de daño.\n",danyoAliado );
    }
return 0;
}

int AtacarAliadoEspecial(){
      int danyoAliado=0;

    danyoAliado=DanyoAliadoEspecial();
    flagEnd=0;
    if(enemigo.puntos.vida-danyoAliado<=0){
            printf("\nHas hecho %d puntos de daño.\n",danyoAliado );
            enemigo.puntos.vida=enemigo.puntos.vida-danyoAliado;
            printf("Vida %s: %d, Vida %s: 0\nAcaba el combate. Ganador: ALIADO\n",aliado.nombre, aliado.puntos.vida, enemigo.nombre);
            printf("Has ganado %d G.\n", (10 +enemigo.puntos.nivel*3));
            aliado.dinero=(aliado.dinero+(10+enemigo.puntos.nivel*3));
            experiencia();
            GuardarPersonaje();
            flagEnd=1;
            return 0;
            }
    else{
    enemigo.puntos.vida=enemigo.puntos.vida-danyoAliado;
    printf("Has hecho %d puntos de daño.\n",danyoAliado );
    }
return 0;
}

int AtacarEnemigo(){
    int danyoEnemigo=0;


    danyoEnemigo=DanyoEnemigo();
    flagEnd=0;
     if(aliado.puntos.vida-danyoEnemigo<=0){
            printf("%s te ha hecho %d puntos de daño.\n", enemigo.nombre, danyoEnemigo);
           // aliado.puntos.vida=aliado.puntos.vida-danyoEnemigo;
            printf("Vida %s: 0, Vida %s: %d\nAcaba el combate. Ganador: ENEMIGO\n", aliado.nombre,enemigo.nombre, enemigo.puntos.vida);
            flagEnd=1;
           // aliado.vidas--;
            return 0;
            }
            else{
    aliado.puntos.vida=aliado.puntos.vida-danyoEnemigo;
    printf("%s te ha hecho %d puntos de daño.\n", enemigo.nombre, danyoEnemigo);
            }
            return 0;
}

int AtacarEnemigoEspecial(){
    int danyoEnemigo=0;


    danyoEnemigo=DanyoEnemigoEspecial();
    flagEnd=0;
     if(aliado.puntos.vida-danyoEnemigo<=0){
        printf("%s te ha hecho %d puntos de daño.\n", enemigo.nombre, danyoEnemigo);
           // aliado.puntos.vida=aliado.puntos.vida-danyoEnemigo;
            printf("Vida %s: 0, Vida enemigo: %d\nAcaba el combate. Ganador: ENEMIGO\n", aliado.nombre,enemigo.puntos.vida);
            flagEnd=1;
           // aliado.vidas--;
            return 0;
            }
            else{
    aliado.puntos.vida=aliado.puntos.vida-danyoEnemigo;
    printf("%s te ha hecho %d puntos de daño.\n", enemigo.nombre, danyoEnemigo);
        }
return 0;
}

void Defender(){
	int defense, damage;

    flagEnd=0;
    defense=aliado.puntos.defensa*2;
    damage=0.01 *Random115() * (((0.2 * enemigo.puntos.nivel+1) *50* enemigo.puntos.ataque)/(25 * defense)+2);
    printf("%s te ha hecho %d puntos de daño.\n", enemigo.nombre, damage);
    if(aliado.puntos.vida-damage<=0){
        //aliado.puntos.vida=aliado.puntos.vida-damage;
        flagEnd=1;
       // aliado.vidas--;
        printf("Vida aliado: 0, Vida %s: %d\nAcaba el combate. Ganador: ENEMIGO\n",enemigo.nombre, enemigo.puntos.vida);
        return;
    }
    else{
        aliado.puntos.vida=aliado.puntos.vida-damage;
    }
}

void DefenderEnemigo(){
/*int defense, damage;

    flagEnd=0;
    defense=enemigo.puntos.defensa*2;
    damage=0.01 *Random115() * (((0.2 * aliado.puntos.nivel+1) *50* al.puntos.ataque)/(25 * defense)+2);
    printf("%s te ha hecho %d puntos de daño.\n", enemigo.nombre, damage);
    if(aliado.puntos.vida-damage<=0){
        //aliado.puntos.vida=aliado.puntos.vida-damage;
        flagEnd=1;
       // aliado.vidas--;
        printf("Vida aliado: 0, Vida %s: %d\nAcaba el combate. Ganador: ENEMIGO\n",enemigo.nombre, enemigo.puntos.vida);
        return;
    }
    else{
        aliado.puntos.vida=aliado.puntos.vida-damage;
    }*/
}

int Inventario(){

   // int i;
	int selector1;
	int flagInvincib;

	printf("Mochila:\n1)%d Pociones Grandes\n2)%d Pociones Pequeñas\n3)%d Pociones de Invincibilidad\n4)%d Galletas\n5)%d Bonificadores de experiencia\n6)%d Bonificadores de Velocidad\n10)Salir\nQue deseas hacer?:", mochila.numPotGan,mochila.numPotPeq, mochila.numPotInvin, mochila.numGalleta, mochila.numPotExp, mochila.numPotVel);
	scanf("%d", &selector1);
	if(selector1==1){
        if(mochila.numPotGan>0){
            if(aliado.puntos.vida<aliado_puntos_vida_MAX){
                aliado.puntos.vida=aliado.puntos.vida+75;
                mochila.numPotGan--;
                if(aliado.puntos.vida>aliado_puntos_vida_MAX){
                    aliado.puntos.vida=aliado_puntos_vida_MAX;
                    }
                }
                else{
                    printf("No puedes recuperar mas vida.\n");
                }
            }
            else{
                printf("No te quedan pociones.\n");
                }
               // AtacarEnemigo();
               IA();
            }
            else if(selector1==2){
                if(mochila.numPotPeq>0){
                    if(aliado.puntos.vida<aliado_puntos_vida_MAX){
                        aliado.puntos.vida=aliado.puntos.vida+25;
                        mochila.numPotPeq--;
                        if(aliado.puntos.vida>aliado_puntos_vida_MAX){
                            aliado.puntos.vida=aliado_puntos_vida_MAX;
                        }
                    }
                    else{
                        printf("No puedes recuperar mas vida.\n");
                    }}
                    else{
                        printf("No te quedan pociones.\n");
                    }
                    //AtacarEnemigo();
                    IA();
                }
	else if(selector1==3){/*pocion de invincibilidad*/
            flagInvincib=0;
	    if(mochila.numPotInvin>0){
            mochila.numPotInvin--;
            flagInvincib=1;
            return flagInvincib;
	    }
        else{
            printf("No te quedan pociones.\n");
            }
	}
	 else if(selector1==4){//galleta
		if(mochila.numGalleta>0){
                    if(aliado.puntos.vida<aliado_puntos_vida_MAX){
                        aliado.puntos.vida=aliado.puntos.vida+10;
                        mochila.numGalleta--;
                        if(aliado.puntos.vida>aliado_puntos_vida_MAX){
                            aliado.puntos.vida=aliado_puntos_vida_MAX;
                        }
                    }
                    else{
                        printf("No puedes recuperar mas vida.\n");
                    }}
                    else{
                        printf("No te quedan mas galletas.\n");
                    }
                    //AtacarEnemigo();
                    IA();
                }
    else if(selector1==5){//bonificador experiencia
		if(mochila.numPotExp>0){
            bonusExp=bonusExp+0.5;
            mochila.numPotExp--;
		}
        else{
            printf("No te quedan mas bonificadores.\n");
        }
        //AtacarEnemigo();
        IA();
    }
    else if(selector1==6){
        if(mochila.numPotVel>0){
            flagBonusSpeed++;
            mochila.numPotVel--;
            printf("Has duplicado tu velocidad.\n");
        }
        else{
            printf("No te quedan bonificadores.\n");
        }
        IA();
    }
	else if(selector1==10){
		return 0;
	}
	return 0;
}

void CrearPersonaje(){
    FILE*fperfil;
    char auxiliar[30];
    int flagSalir=0;

    CargaPersonaje();
    if(diferenciadorInicio>0){
        printf("Ya existe un perfil creado. Crear uno nuevo sobreescribira el antiguo.\nQuieres continuar?  Si:1, No:0 ->");
        scanf("%d", &flagSalir);
        if(flagSalir==0){
            return;
        }
        else{
            printf("Escribe el nombre de tu personaje(una palabra):");
            scanf("%s", auxiliar);
            fperfil=fopen("PerfilPersonaje.txt", "w");

            if(fperfil==NULL){
                printf("Error");
            }
            else{
                fprintf(fperfil, "1\n");//diferenciador
                fprintf(fperfil,"%s\n", auxiliar);//nombre
                fprintf(fperfil, "1\n");//nivel
                fprintf(fperfil,"%d\n", Random115()/50+5);//ataque
                fprintf(fperfil,"%d\n", Random115()/50+5);//ataque especial
                fprintf(fperfil,"%d\n", Random115()/50+5);//defensa
                fprintf(fperfil,"%d\n", Random115()/50+5);//defensa especial
                fprintf(fperfil, "%d\n", Random115()/50+15);//vida
                fprintf(fperfil, "%d\n", Random115()/50+10);//velocidad
                fprintf(fperfil, "0\n");//experiencia
                fprintf(fperfil, "0\n");//dinero
                fprintf(fperfil, "0\n");//Punto Stat
                fprintf(fperfil, "3\n");//vidas
                fprintf(fperfil, "0\n");//potpequeñas
                fprintf(fperfil, "0\n");//potgrandes
                fprintf(fperfil, "1\n");//galletas
                fprintf(fperfil, "0\n");//potinvincibilidad
                fprintf(fperfil, "0\n");//potvelocidad
                fprintf(fperfil, "0\n");//pot bonus EXP
                fprintf(fperfil, "1\n");//selectorzona
                fprintf(fperfil, "1\n");//zona_MAX
                fclose(fperfil);
            }
        CargaPersonaje();
        }
    }
    else{
        printf("Escribe el nombre de tu personaje:");
        scanf("%s", auxiliar);
        fperfil=fopen("PerfilPersonaje.txt", "w");

        if(fperfil==NULL){
            printf("Error");
        }
        else{
            fprintf(fperfil, "1\n");//diferenciador
            fprintf(fperfil,"%s\n", auxiliar);//nombre
            fprintf(fperfil, "1\n");//nivel
            fprintf(fperfil,"%d\n", Random115()/50+5);//ataque
            fprintf(fperfil,"%d\n", Random115()/50+5);//ataque especial
            fprintf(fperfil,"%d\n", Random115()/50+5);//defensa
            fprintf(fperfil,"%d\n", Random115()/50+5);//defensa especial
            fprintf(fperfil, "%d\n", Random115()/50+15);//vida
            fprintf(fperfil, "%d\n", Random115()/50+10);//velocidad
            fprintf(fperfil, "0\n");//experiencia
            fprintf(fperfil, "0\n");//dinero
            fprintf(fperfil, "0\n");//Punto Stat
            fprintf(fperfil, "3\n");//vidas
            fprintf(fperfil, "0\n");//potpequeñas
            fprintf(fperfil, "0\n");//potgrandes
            fprintf(fperfil, "1\n");//galletas
            fprintf(fperfil, "0\n");//potinvincibilidad
            fprintf(fperfil, "0\n");//potvelocidad
            fprintf(fperfil, "0\n");//pot bonusEXP
            fprintf(fperfil, "1\n");//selectorzona
            fprintf(fperfil, "1\n");//zona_MAX
            fclose(fperfil);
        }
    CargaPersonaje();
    }
}

void CargaPersonaje(){
    FILE*fperfil;

    fperfil=fopen("PerfilPersonaje.txt", "r");
    if(fperfil==NULL){
        printf("Error");
    }
    else{
            fscanf(fperfil, "%d\n", &diferenciadorInicio);
        while(!feof(fperfil)){
                fscanf(fperfil, "%s\n", &aliado.nombre);
                fscanf(fperfil, "%d\n", &aliado.puntos.nivel);
                fscanf(fperfil, "%d\n", &aliado.puntos.ataque);
                fscanf(fperfil, "%d\n", &aliado.puntos.especial);
                fscanf(fperfil, "%d\n", &aliado.puntos.defensa);
                fscanf(fperfil, "%d\n", &aliado.puntos.defensaEsp);
                fscanf(fperfil, "%d\n", &aliado_puntos_vida_MAX);
                fscanf(fperfil, "%d\n", &aliado.puntos.velocidad);
                fscanf(fperfil, "%d\n", &aliado.puntos.experiencia);
                fscanf(fperfil, "%d\n", &aliado.dinero);
                fscanf(fperfil, "%d\n", &PuntoStat);
                fscanf(fperfil, "%d\n", &aliado.vidas);
                fscanf(fperfil, "%d\n", &mochila.numPotPeq);
                fscanf(fperfil, "%d\n", &mochila.numPotGan);
                fscanf(fperfil, "%d\n", &mochila.numGalleta);
                fscanf(fperfil, "%d\n", &mochila.numPotInvin);
                fscanf(fperfil, "%d\n", &mochila.numPotVel);
                fscanf(fperfil, "%d\n", &mochila.numPotExp);
                fscanf(fperfil, "%d\n", &selectorZona);
                fscanf(fperfil, "%d\n", &zona_MAX);
        }
        aliado.puntos.vida=aliado_puntos_vida_MAX;
        zonaMax=selectorZona;
    }


    //fgets();
fclose(fperfil);

}

void GuardarPersonaje(){
    FILE*fperfil;


    fperfil=fopen("PerfilPersonaje.txt", "w");
    printf("Partida guardada!\n");

    if(fperfil==NULL){
        printf("Error");
    }
    else{
        fprintf(fperfil,"1\n");//diferenciador
        fprintf(fperfil,"%s\n", aliado.nombre);//nombre
        fprintf(fperfil,"%d\n", aliado.puntos.nivel);//nivel
        fprintf(fperfil,"%d\n", aliado.puntos.ataque);//ataque
        fprintf(fperfil,"%d\n", aliado.puntos.especial);//ataque especial
        fprintf(fperfil,"%d\n", aliado.puntos.defensa);//defensa
        fprintf(fperfil,"%d\n", aliado.puntos.defensaEsp);//defensa especial
        fprintf(fperfil,"%d\n", aliado_puntos_vida_MAX);//vida
        fprintf(fperfil,"%d\n", aliado.puntos.velocidad);//velocidad
        fprintf(fperfil,"%d\n", aliado.puntos.experiencia);//experiencia
        fprintf(fperfil,"%d\n", aliado.dinero);
        fprintf(fperfil,"%d\n", PuntoStat);
        fprintf(fperfil,"%d\n", aliado.vidas);
        fprintf(fperfil,"%d\n", mochila.numPotPeq);
        fprintf(fperfil,"%d\n", mochila.numPotGan);
        fprintf(fperfil,"%d\n", mochila.numGalleta);
        fprintf(fperfil,"%d\n", mochila.numPotInvin);
        fprintf(fperfil,"%d\n", mochila.numPotVel);
        fprintf(fperfil,"%d\n", mochila.numPotExp);
        fprintf(fperfil,"%d\n", selectorZona);
        fprintf(fperfil,"%d\n", zona_MAX);


    fclose(fperfil);
    }
    CargaPersonaje();
}

void BorrarPersonaje(){
    FILE*fperfil;
    int i;

        printf("Partida borrada\n");
        fperfil=fopen("PerfilPersonaje.txt", "w");

        if(fperfil==NULL){
            printf("ERROR");
        }
        else{
            fprintf(fperfil,"0\n");
            for(i=0; i<50; i++){
                fprintf(fperfil,"0\n");
            }

        }
    fclose(fperfil);
    CargaPersonaje();
    }

void experiencia(){

    //expGanada=9;
    expGanada=((90*enemigo.puntos.nivel*bonusExp)/(7*aliado.puntos.nivel*.5));
    printf("Has ganado %d puntos de experiencia.\n", expGanada);
    if(aliado.puntos.experiencia+expGanada>=((aliado.puntos.nivel+1)*(aliado.puntos.nivel+1))){
        subirNivel();
        expGanada=expGanada-((aliado.puntos.nivel*aliado.puntos.nivel)-aliado.puntos.experiencia);
        while(expGanada>((aliado.puntos.nivel+1)*(aliado.puntos.nivel+1))){
        subirNivel();
        expGanada=expGanada-((aliado.puntos.nivel*aliado.puntos.nivel)-aliado.puntos.experiencia);
        }
        aliado.puntos.experiencia=expGanada;
    }
    else{
    aliado.puntos.experiencia=aliado.puntos.experiencia+expGanada;
        }
    }

void subirNivel(){
 int ataque2, especial2, defensa2, defensaEsp2, vida2, velocidad2/*, aleatorio*/;


    aliado.puntos.nivel++;
    ataque2=aliado.puntos.ataque+2*Random160()/100;
    especial2=aliado.puntos.especial+2*Random160()/100;
    defensa2=aliado.puntos.defensa+2*Random160()/100;
    defensaEsp2=aliado.puntos.defensaEsp+2*Random160()/100;
    vida2=aliado_puntos_vida_MAX+3*Random160()/100;
    velocidad2=aliado.puntos.velocidad+3*Random160()/100;

    PuntoStat++;
    printf("Has subido de nivel!\nHas ganado un punto de stat. Tienes %d.\n", PuntoStat);
    printf("Eres nivel %d\n", aliado.puntos.nivel);
    printf("Vida: %d-> %d\n", aliado_puntos_vida_MAX, vida2);
    printf("Ataque: %d-> %d\n", aliado.puntos.ataque, ataque2);
    printf("Especial: %d-> %d\n", aliado.puntos.especial, especial2);
    printf("Defensa: %d-> %d\n", aliado.puntos.defensa, defensa2);
    printf("Defensa Especial: %d-> %d\n", aliado.puntos.defensaEsp, defensaEsp2);
    printf("Velocidad: %d-> %d\n", aliado.puntos.velocidad, velocidad2);
    aliado_puntos_vida_MAX=vida2;
    aliado.puntos.ataque=ataque2;
    aliado.puntos.especial=especial2;
    aliado.puntos.defensa=defensa2;
    aliado.puntos.defensaEsp=defensaEsp2;
    aliado.puntos.velocidad=velocidad2;


}

void Tienda(){
    int selector;

    printf("Bienvenido! Tenemos la mejor mercancia.\nQue deseas?\n");
    printf("Tienes %d G\n", aliado.dinero);
    printf("1-Pocion pequeña: 50G\n2-Pocion grande: 150G\n3-Pocion de invincibilidad: 500G\n4-Galleta: 10G\n5-Bonificador de experiencia: 200G\n6-Bonificador de velocidad(Duplica tu velocidad durante un combate completo): 250G\n10-Salir\n");
    scanf("%d", &selector);
    if(selector==1){
        if(aliado.dinero>=50){
                printf("Has comprado una pocion pequeña.\n");
            mochila.numPotPeq++;
            aliado.dinero=aliado.dinero-50;
        }
        else{
            printf("No tienes dinero suficiente.\n");
        }
    }
    else if(selector==2){
        if(aliado.dinero>=150){
                printf("Has comprado una pocion grande.\n");
            mochila.numPotGan++;
            aliado.dinero=aliado.dinero-150;
        }
        else{
            printf("No tienes dinero suficiente.\n");
        }
    }
    else if(selector==3){
            if(aliado.dinero>=500){
                printf("Has comprado una pocion de invincibilidad.\n");
            mochila.numPotInvin++;
            aliado.dinero=aliado.dinero-500;
        }
        else{
            printf("No tienes dinero suficiente.\n");
        }

    }
    else if(selector==4){
            if(aliado.dinero>=10){
                printf("Has comprado una galleta.\n");
            mochila.numGalleta++;
            aliado.dinero=aliado.dinero-10;
        }
        else{
            printf("No tienes dinero suficiente.\n");
        }

    }

    else if(selector==5){
        if(aliado.dinero>=200){
            printf("Has comprado un bonificador de experiencia.\n");
            mochila.numPotExp++;
            aliado.dinero=aliado.dinero-200;
        }
        else{
            printf("No tienes dinero suficiente.\n");
        }
    }
    else if (selector==6){
        if(aliado.dinero>=250){
                printf("Has comprado un bonificador de velocidad.\n");
        mochila.numPotVel++;
        aliado.dinero=aliado.dinero-250;
        }
        else{
            printf("No tienes dinero suficiente.\n");
        }
    }
    else if(selector==10){
        return;
    }

}

void stats(){
    printf("Nombre: %s\n", aliado.nombre);
    printf("Nivel:%d\tHp:%d/%d\n", aliado.puntos.nivel, aliado.puntos.vida, aliado_puntos_vida_MAX);
    printf("Ataque:%d\tDefensa:%d\n", aliado.puntos.ataque, aliado.puntos.defensa);
    printf("Especial:%d\tDefensa Especial:%d\n", aliado.puntos.especial, aliado.puntos.defensaEsp);
    printf("Velocidad:%d\tExperiencia:%d/%d\n", aliado.puntos.velocidad, aliado.puntos.experiencia, ((aliado.puntos.nivel+1)*(aliado.puntos.nivel+1)));
    printf("Dinero:%dG\tModificadores de stats: %d\n\n", aliado.dinero, PuntoStat);


}

void GeneracionEnemigoFullHealth(){
 int i,ataque2, especial2, defensa2, defensaEsp2, vida2, velocidad2/*, aleatorio*/;;

//generar enemigo
    strcpy(enemigo.nombre,"Dr. Mundo");
    enemigo_puntos_vida_MAX=Random115()/35+20;
    enemigo.puntos.ataque=Random115()/75+3;
    enemigo.puntos.especial=Random115()/75+3;
    enemigo.puntos.defensa=Random115()/50+6;
    enemigo.puntos.defensaEsp=Random115()/50+6;
    enemigo.puntos.velocidad=Random115()/45+7;
    enemigo.puntos.nivel=1;
    enemigo.puntos.vida=enemigo_puntos_vida_MAX;

    if(enemigo.puntos.nivel<selectorZona){
        for(i=0; i<selectorZona; i++){

        enemigo.puntos.nivel++;
        ataque2=enemigo.puntos.ataque+2*Random160()/150;
        especial2=enemigo.puntos.especial+2*Random160()/150;
        defensa2=enemigo.puntos.defensa+2*Random160()/80;
        defensaEsp2=enemigo.puntos.defensaEsp+2*Random160()/80;
        vida2=enemigo_puntos_vida_MAX+4*Random160()/75;
        velocidad2=enemigo.puntos.velocidad+2*Random160()/100;

        enemigo.puntos.vida=vida2;
        enemigo.puntos.ataque=ataque2;
        enemigo.puntos.ataque=especial2;
        enemigo.puntos.defensa=defensa2;
        enemigo.puntos.defensa=defensaEsp2;
        enemigo.puntos.velocidad=velocidad2;

        enemigo_puntos_vida_MAX=enemigo.puntos.vida;
        }
    }
}

void GeneracionEnemigoTankAD(){
 int i,ataque2, especial2, defensa2, defensaEsp2, vida2, velocidad2/*, aleatorio*/;;

//generar enemigo
    strcpy(enemigo.nombre,"Darius");
    enemigo_puntos_vida_MAX=Random115()/50+17;
    enemigo.puntos.ataque=Random115()/50+4;
    enemigo.puntos.especial=Random115()/50+1;
    enemigo.puntos.defensa=Random115()/40+7;
    enemigo.puntos.defensaEsp=Random115()/40+7;
    enemigo.puntos.velocidad=Random115()/50+8;
    enemigo.puntos.nivel=1;
    enemigo.puntos.vida=enemigo_puntos_vida_MAX;

    if(enemigo.puntos.nivel<selectorZona){
        for(i=0; i<selectorZona; i++){

        enemigo.puntos.nivel++;
        ataque2=enemigo.puntos.ataque+2*Random160()/150;
        especial2=enemigo.puntos.especial+1*Random160()/150;
        defensa2=enemigo.puntos.defensa+3*Random160()/80;
        defensaEsp2=enemigo.puntos.defensaEsp+3*Random160()/80;
        vida2=enemigo_puntos_vida_MAX+4*Random160()/100;
        velocidad2=enemigo.puntos.velocidad+2*Random160()/100;

        enemigo.puntos.vida=vida2;
        enemigo.puntos.ataque=ataque2;
        enemigo.puntos.ataque=especial2;
        enemigo.puntos.defensa=defensa2;
        enemigo.puntos.defensa=defensaEsp2;
        enemigo.puntos.velocidad=velocidad2;

        enemigo_puntos_vida_MAX=enemigo.puntos.vida;
        }
    }
}

void GeneracionEnemigoTankAP(){
 int i,ataque2, especial2, defensa2, defensaEsp2, vida2, velocidad2/*, aleatorio*/;;

//generar enemigo
    strcpy(enemigo.nombre,"Sejuani");
    enemigo_puntos_vida_MAX=Random115()/50+17;
    enemigo.puntos.ataque=Random115()/50+1;
    enemigo.puntos.especial=Random115()/50+4;
    enemigo.puntos.defensa=Random115()/40+7;
    enemigo.puntos.defensaEsp=Random115()/40+7;
    enemigo.puntos.velocidad=Random115()/50+8;
    enemigo.puntos.nivel=1;
    enemigo.puntos.vida=enemigo_puntos_vida_MAX;

    if(enemigo.puntos.nivel<selectorZona){
        for(i=0; i<selectorZona; i++){

        enemigo.puntos.nivel++;
        ataque2=enemigo.puntos.ataque+1*Random160()/150;
        especial2=enemigo.puntos.especial+2*Random160()/120;
        defensa2=enemigo.puntos.defensa+3*Random160()/80;
        defensaEsp2=enemigo.puntos.defensaEsp+3*Random160()/80;
        vida2=enemigo_puntos_vida_MAX+4*Random160()/100;
        velocidad2=enemigo.puntos.velocidad+2*Random160()/100;

        enemigo.puntos.vida=vida2;
        enemigo.puntos.ataque=ataque2;
        enemigo.puntos.ataque=especial2;
        enemigo.puntos.defensa=defensa2;
        enemigo.puntos.defensa=defensaEsp2;
        enemigo.puntos.velocidad=velocidad2;

        enemigo_puntos_vida_MAX=enemigo.puntos.vida;
        }
    }
}

void GeneracionEnemigoADC(){
 int i,ataque2, especial2, defensa2, defensaEsp2, vida2, velocidad2/*, aleatorio*/;;

//generar enemigo
    strcpy(enemigo.nombre,"Tristana");
    enemigo_puntos_vida_MAX=Random115()/50+12;
    enemigo.puntos.ataque=Random115()/50+7;
    enemigo.puntos.especial=Random115()/50+2;
    enemigo.puntos.defensa=Random115()/50+4;
    enemigo.puntos.defensaEsp=Random115()/50+4;
    enemigo.puntos.velocidad=Random115()/50+12;
    enemigo.puntos.nivel=1;
    enemigo.puntos.vida=enemigo_puntos_vida_MAX;

    if(enemigo.puntos.nivel<selectorZona){
        for(i=0; i<selectorZona; i++){

        enemigo.puntos.nivel++;
        ataque2=enemigo.puntos.ataque+3*Random160()/80;
        especial2=enemigo.puntos.especial+1*Random160()/100;
        defensa2=enemigo.puntos.defensa+2*Random160()/120;
        defensaEsp2=enemigo.puntos.defensaEsp+2*Random160()/120;
        vida2=enemigo_puntos_vida_MAX+2*Random160()/100;
        velocidad2=enemigo.puntos.velocidad+3*Random160()/80;

        enemigo.puntos.vida=vida2;
        enemigo.puntos.ataque=ataque2;
        enemigo.puntos.ataque=especial2;
        enemigo.puntos.defensa=defensa2;
        enemigo.puntos.defensa=defensaEsp2;
        enemigo.puntos.velocidad=velocidad2;

        enemigo_puntos_vida_MAX=enemigo.puntos.vida;
        }
    }
}

void GeneracionEnemigoAPC(){
 int i,ataque2, especial2, defensa2, defensaEsp2, vida2, velocidad2/*, aleatorio*/;;

//generar enemigo
    strcpy(enemigo.nombre,"Leblenk");
    enemigo_puntos_vida_MAX=Random115()/50+12;
    enemigo.puntos.ataque=Random115()/50+2;
    enemigo.puntos.especial=Random115()/50+7;
    enemigo.puntos.defensa=Random115()/50+4;
    enemigo.puntos.defensaEsp=Random115()/50+4;
    enemigo.puntos.velocidad=Random115()/50+12;
    enemigo.puntos.nivel=1;
    enemigo.puntos.vida=enemigo_puntos_vida_MAX;

    if(enemigo.puntos.nivel<selectorZona){
        for(i=0; i<selectorZona; i++){

        enemigo.puntos.nivel++;
        ataque2=enemigo.puntos.ataque+1*Random160()/100;
        especial2=enemigo.puntos.especial+3*Random160()/80;
        defensa2=enemigo.puntos.defensa+2*Random160()/120;
        defensaEsp2=enemigo.puntos.defensaEsp+2*Random160()/120;
        vida2=enemigo_puntos_vida_MAX+2*Random160()/100;
        velocidad2=enemigo.puntos.velocidad+3*Random160()/80;

        enemigo.puntos.vida=vida2;
        enemigo.puntos.ataque=ataque2;
        enemigo.puntos.ataque=especial2;
        enemigo.puntos.defensa=defensa2;
        enemigo.puntos.defensa=defensaEsp2;
        enemigo.puntos.velocidad=velocidad2;

        enemigo_puntos_vida_MAX=enemigo.puntos.vida;
        }
    }
}

void GeneracionEnemigoQuick(){
 int i,ataque2, especial2, defensa2, defensaEsp2, vida2, velocidad2/*, aleatorio*/;;

//generar enemigo
    strcpy(enemigo.nombre, "Hecarim");
    enemigo_puntos_vida_MAX=Random115()/50+10;
    enemigo.puntos.ataque=Random115()/50+4;
    enemigo.puntos.especial=Random115()/50+4;
    enemigo.puntos.defensa=Random115()/50+3;
    enemigo.puntos.defensaEsp=Random115()/50+3;
    enemigo.puntos.velocidad=Random115()/50+15;
    enemigo.puntos.nivel=1;
    enemigo.puntos.vida=enemigo_puntos_vida_MAX;

    if(enemigo.puntos.nivel<selectorZona){
        for(i=0; i<selectorZona; i++){

        enemigo.puntos.nivel++;
        ataque2=enemigo.puntos.ataque+2*Random160()/100;
        especial2=enemigo.puntos.especial+2*Random160()/100;
        defensa2=enemigo.puntos.defensa+1*Random160()/100;
        defensaEsp2=enemigo.puntos.defensaEsp+1*Random160()/100;
        vida2=enemigo_puntos_vida_MAX+2*Random160()/150;
        velocidad2=enemigo.puntos.velocidad+4*Random160()/80;

        enemigo.puntos.vida=vida2;
        enemigo.puntos.ataque=ataque2;
        enemigo.puntos.ataque=especial2;
        enemigo.puntos.defensa=defensa2;
        enemigo.puntos.defensa=defensaEsp2;
        enemigo.puntos.velocidad=velocidad2;

        enemigo_puntos_vida_MAX=enemigo.puntos.vida;
        }
    }
}

void GeneracionEnemigoAverage(){
 int i,ataque2, especial2, defensa2, defensaEsp2, vida2, velocidad2/*, aleatorio*/;;

//generar enemigo
    strcpy(enemigo.nombre, "Garen");
    enemigo_puntos_vida_MAX=Random115()/50+15;
    enemigo.puntos.ataque=Random115()/50+5;
    enemigo.puntos.especial=Random115()/50+5;
    enemigo.puntos.defensa=Random115()/50+5;
    enemigo.puntos.defensaEsp=Random115()/50+5;
    enemigo.puntos.velocidad=Random115()/50+10;
    enemigo.puntos.nivel=1;
    enemigo.puntos.vida=enemigo_puntos_vida_MAX;

    if(enemigo.puntos.nivel<selectorZona){
        for(i=0; i<selectorZona; i++){

        enemigo.puntos.nivel++;
        ataque2=enemigo.puntos.ataque+2*Random160()/100;
        especial2=enemigo.puntos.especial+2*Random160()/100;
        defensa2=enemigo.puntos.defensa+2*Random160()/100;
        defensaEsp2=enemigo.puntos.defensaEsp+2*Random160()/100;
        vida2=enemigo_puntos_vida_MAX+3*Random160()/100;
        velocidad2=enemigo.puntos.velocidad+3*Random160()/100;

        enemigo.puntos.vida=vida2;
        enemigo.puntos.ataque=ataque2;
        enemigo.puntos.ataque=especial2;
        enemigo.puntos.defensa=defensa2;
        enemigo.puntos.defensa=defensaEsp2;
        enemigo.puntos.velocidad=velocidad2;

        enemigo_puntos_vida_MAX=enemigo.puntos.vida;
        }
    }
}

void seleccionEnemigo(){
    int selector;

    selector=Random100();
    if(selector<14){
        GeneracionEnemigoAverage();
        indexEnemigo=1;
    }
    else if(selector>13&&selector<28){
        GeneracionEnemigoFullHealth();
        indexEnemigo=2;
    }
    else if(selector>27&&selector<42){
        GeneracionEnemigoQuick();
        indexEnemigo=3;
    }
    else if(selector>41&&selector<56){
        GeneracionEnemigoADC();
        indexEnemigo=4;
    }
    else if(selector>55&&selector<70){
        GeneracionEnemigoAPC();
        indexEnemigo=5;
    }
    else if(selector>69&&selector<85){
        GeneracionEnemigoTankAD();
        indexEnemigo=6;
    }
    else if(selector>84){
        GeneracionEnemigoTankAP();
        indexEnemigo=7;
    }
}

void Zona(){
    int i, selector;

    printf("Te encuentras en la zona %d\nZona maxima: %d\nTienes %d G\n", selectorZona, zona_MAX, aliado.dinero);
    printf("Que quieres hacer?\nAvanzar de zona:1   Retroceder una zona:2   Salir:3\n");
    scanf("%d", &i);

    if(i==1){
        if(selectorZona<zona_MAX){
            printf("Has avanzado de zona! Cuidado, ahora los enemigos son mas fuertes!\n");
            selectorZona++;
        }
        else{
            if(aliado.dinero<selectorZona*10){
                printf("No tienes dinero suficiente");
                return;
            }
            else{
                printf("Te costara %d G pasar a la zona siguiente. Quieres hacerlo?\nSi:1  No:2 -->", selectorZona*10);
                scanf("%d", &selector);
                if(selector==2){
                    return;

                }
                printf("Has avanzado de zona! Cuidado, ahora los e nemigos son mas fuertes!\n");
                selectorZona++;
                aliado.dinero=aliado.dinero-selectorZona*10;
                zona_MAX++;
            }
        }
    }
    else if(i==2){
            if(selectorZona-1<1){
                printf("No puedes retroceder mas");
                return;
            }
            printf("Has retrocedido a una zona anterior.\n Los enemigos son mas debiles aqui.\n");
            selectorZona--;

    }
    else if(i==3){
        return;
    }

    return ;
}

void ModificadorStat(){
    int selector;

    if(PuntoStat>0){
        printf("Tienes %d puntos de stats. Puedes usar uno para aumentar una de tus facultades de manera permanente\n", PuntoStat);
        while(PuntoStat>0){

                printf("\n1)Hp maximos:%d -> %d\n" ,aliado_puntos_vida_MAX, aliado_puntos_vida_MAX+5);
                printf("2)Ataque:%d -> %d\n", aliado.puntos.ataque, aliado.puntos.ataque+2);
                printf("3)Defensa:%d -> %d\n", aliado.puntos.defensa, aliado.puntos.defensa+2);
                printf("4)Especial:%d -> %d\n", aliado.puntos.especial, aliado.puntos.especial+2);
                printf("5)Defensa Especial:%d -> %d\n", aliado.puntos.defensaEsp, aliado.puntos.defensaEsp+2);
                printf("6)Velocidad:%d ->%d\n", aliado.puntos.velocidad, aliado.puntos.velocidad+3);
                printf("Te quedan %d puntos para usar. Que stat deseas modificar?: \n", PuntoStat);
                printf("Salir:10\n");
                scanf("%d", &selector);
                if(selector==1){
                    aliado_puntos_vida_MAX=aliado_puntos_vida_MAX+5;
                    PuntoStat--;
                    printf("\nSalud mejorada.");
                }
                else if(selector==2){
                    aliado.puntos.ataque=aliado.puntos.ataque+2;
                    PuntoStat--;
                    printf("\nAtaque aumentado.");
                }
                else if(selector==3){
                    aliado.puntos.defensa=aliado.puntos.defensa+2;
                    PuntoStat--;
                    printf("\nDefensa mejorada.");
                }
                else if(selector==4){
                    aliado.puntos.especial=aliado.puntos.especial+2;
                    PuntoStat--;
                    printf("\nAtaque especial aumentado.");
                }
                else if(selector==5){
                    aliado.puntos.defensaEsp=aliado.puntos.defensaEsp+2;
                    PuntoStat--;
                    printf("\nDefensa especial aumentada.");
                }
                else if(selector==6){
                    aliado.puntos.velocidad=aliado.puntos.velocidad+3;
                    PuntoStat--;
                    printf("\nVelocidad aumentada.");
                }
                else if(selector==10){
                        return;
                }
        }
    }
    else{
        printf("No tienes puntos de habilidad que gastar\n");
    }

}
