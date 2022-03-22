#include <iostream>
#include <allegro.h>
#include "inicia.h"
using namespace std;

int validar_torre=0;
//funcion gotoxy para pintar en posiciones esactas

 char table[9][9]= {{'0','1','2','3','4','5','6','7','8'}, //array para repintar tablero unavez mivida una pieza
                    {'1',' ','.',' ','.',' ','.',' ','.'},
                    {'2','.',' ','.',' ','.',' ','.',' '},
                    {'3',' ','.',' ','.',' ','.',' ','.'},
                    {'4','.',' ','.',' ','.',' ','.',' '},
                    {'5',' ','.',' ','.',' ','.',' ','.'},
                    {'6','.',' ','.',' ','.',' ','.',' '},
                    {'7',' ','.',' ','.',' ','.',' ','.'},
                    {'8','.',' ','.',' ','.',' ','.',' '}};

char tablero[9][9]={{'0','1','2','3','4','5','6','7','8'},//tablero con piezaz pintadas
                    {'1','T','P',' ','.',' ','.','p','t'},
                    {'2','C','P','.',' ','.',' ','p','c'},
                    {'3','A','P',' ','.',' ','.','p','a'},
                    {'4','Q','P','.',' ','.',' ','p','q'},
                    {'5','R','P',' ','.',' ','.','p','r'},
                    {'6','A','P','.',' ','.',' ','p','a'},
                    {'7','C','P',' ','.',' ','.','p','c'},
                    {'8','T','P','.',' ','.',' ','p','t'}};



/*funcion para saber quien gana lo que hace es recorrer el tablero y si algun rey falta pinta en la
pantalla quien gana*/


/*funcion mover es la funcio que borra y pinta en las posicion dada por eel user*/
void mover(int x,int y,int xp,int yp){
    tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];

}//fin de mover

//Funcion mivimiento invalido declara o pintala invalidacion de movimiento
/*
void movi_invalido(int x, int y,int xp, int yp){
gotoxy(0,0);cout<<"movimiento invalido";
Sleep(1500);

}//fin de micimiento invalido
*/












int main()
{
  allegro_init();
  install_keyboard();
  install_timer();
  install_mouse();
   set_color_depth(8);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,640, 0, 0);


    BITMAP *buffer=load_bitmap("tablero.bmp",NULL);
BITMAP *peonb=load_bitmap("peonb.bmp",NULL);
BITMAP *torreb=load_bitmap("torreb.bmp",NULL);
BITMAP *alfilb=load_bitmap("alfilb.bmp",NULL);
BITMAP *reyb=load_bitmap("reyb.bmp",NULL);
BITMAP *reinab=load_bitmap("reinab.bmp",NULL);
BITMAP *caballob=load_bitmap("caballob.bmp",NULL);
BITMAP *peonn=load_bitmap("peonn.bmp",NULL);
BITMAP *torren=load_bitmap("torren.bmp",NULL);
BITMAP *alfiln=load_bitmap("alfiln.bmp",NULL);
BITMAP *reyn=load_bitmap("reyn.bmp",NULL);
BITMAP *reinan=load_bitmap("reinan.bmp",NULL);
BITMAP *caballon=load_bitmap("caballon.bmp",NULL);
BITMAP *espa_b=load_bitmap("espaciob.bmp",NULL);
BITMAP *espa_n=load_bitmap("espacion.bmp",NULL);
int cont=0;
int x,y,xp,yp;
 int reybl,reyne;                   //pintar piezas

x=y=xp=yp=0;
//buclle de juego
show_mouse(screen);
while(1){
    if(mouse_x>0 && mouse_x<70 && mouse_y>0 && mouse_y<70 && (mouse_b & 1)){
        exit(0);

    }
reybl=reyne=0;
    for(int o=0;o<9;o++){

        for(int w=0;w<9;w++){


            if(tablero[o][w]=='r'){
            reybl++;
            }
            if(tablero[o][w]=='R'){
                reyne++;
            }


        }

    }

    if(reybl==0){

     exit(0);
    }
        if(reyne==0){


     exit(0);
    }
//PINTAR PIEZAS
    for(int j=0;j<9;j++){

        for(int d=0;d<9;d++){
if(tablero[j][d]=='p'){masked_blit( peonb, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='a'){draw_sprite(buffer,alfilb,j*71,d*71);}
if(tablero[j][d]=='t'){masked_blit(torreb , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='q'){masked_blit( reinab, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='c'){masked_blit(caballob , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='r'){masked_blit( reyb , buffer, 0, 0, j*71,d*71, 71, 71);}

if(tablero[j][d]=='P'){masked_blit( peonn, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='A'){masked_blit( alfiln, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='T'){masked_blit(torren , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='Q'){masked_blit( reinan, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='C'){masked_blit(caballon , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='R'){masked_blit( reyn , buffer, 0, 0, j*71,d*71, 71, 71);}

        }

    }

//FIN DE PINTAR PIEZAS

 blit(buffer,screen,0,0,0,0,639,639);
 //iniciamos variables
//variables de cordenadas
//x= a posicio x original
//y= a posicio y original
//xp= a posicio x a la cual vamos a mover pieza
//yp= a posicio y a la cual vamos a mover pieza
 /*   int x,y,xp,yp;
    cout<<"y  =";cin>>x;
     cout<<"x  =";cin>>y;
      cout<<"yp  =";cin>>xp;
       cout<<"xp  =";cin>>yp;*/

if(cont%2==0){
 if(mouse_x>70 && mouse_x<140 && (mouse_b & 1)){
 y=1;
 }else
 if(mouse_x>140 && mouse_x<210  && (mouse_b & 1)){
 y=2;
 }
 if(mouse_x>210 && mouse_x<280  && (mouse_b & 1)){
     y=3;
 }else
  if(mouse_x>280 && mouse_x<350 && (mouse_b & 1)){
y=4;
  }else
   if(mouse_x>350 && mouse_x<420  && (mouse_b & 1)){
y=5;
   }else
    if(mouse_x>420 && mouse_x<490  && (mouse_b & 1)){
y=6;
    }else
    if(mouse_x>490 && mouse_x<560  && (mouse_b & 1)){
    y=7;
    }else
    if(mouse_x>560 && mouse_x<640  && (mouse_b & 1)){
        y=8;
    }
 if(mouse_y>70 && mouse_y<140 && (mouse_b & 1)){
 x=1;
 }else
 if(mouse_y>140 && mouse_y<210  && (mouse_b & 1)){
 x=2;
 }
 if(mouse_y>210 && mouse_y<280  && (mouse_b & 1)){
  x=3;
 }else
  if(mouse_y>280 && mouse_y<350 && (mouse_b & 1)){
x=4;
  }else
   if(mouse_y>350 && mouse_y<420  && (mouse_b & 1)){
       x=5;
   }else
    if(mouse_y>420 && mouse_y<490  && (mouse_b & 1)){
x=6;
    }else
    if(mouse_y>490 && mouse_y<560  &&(mouse_b & 1)){
    x=7;
    }else
    if(mouse_y>560 && mouse_y<640  && (mouse_b & 1)){
        x=8;
    }

    cout<<"x= "<<y<<" y=  "<<x<<"\n";


}
if(mouse_b & 2){
cont++;
}
if(cont%2!=0){
if(mouse_x>70 && mouse_x<140 && (mouse_b & 1)){
 yp=1;
 }else
 if(mouse_x>140 && mouse_x<210  && (mouse_b & 1)){
 yp=2;
 }
 if(mouse_x>210 && mouse_x<280  && (mouse_b & 1)){
     yp=3;
 }else
  if(mouse_x>280 && mouse_x<350 && (mouse_b & 1)){
yp=4;
  }else
   if(mouse_x>350 && mouse_x<420  && (mouse_b & 1)){
yp=5;
   }else
    if(mouse_x>420 && mouse_x<490  && (mouse_b & 1)){
yp=6;
    }else
    if(mouse_x>490 && mouse_x<560  && (mouse_b & 1)){
    yp=7;
    }else
    if(mouse_x>560 && mouse_x<640  && (mouse_b & 1)){
        yp=8;
    }
 if(mouse_y>70 && mouse_y<140 && (mouse_b & 1)){
 xp=1;
 }else
 if(mouse_y>140 && mouse_y<210  && (mouse_b & 1)){
 xp=2;
 }
 if(mouse_y>210 && mouse_y<280  && (mouse_b & 1)){
  xp=3;
 }else
  if(mouse_y>280 && mouse_y<350 && (mouse_b & 1)){
xp=4;
  }else
   if(mouse_y>350 && mouse_y<420  && (mouse_b & 1)){
       xp=5;
   }else
    if(mouse_y>420 && mouse_y<490  && (mouse_b & 1)){
xp=6;
    }else
    if(mouse_y>490 && mouse_y<560  && (mouse_b & 1)){
    xp=7;
    }else
    if(mouse_y>560 && mouse_y<640  && (mouse_b & 1)){
        xp=8;
    }


   cout<<"xp= "<<yp<<" yp=  "<<xp<<"\n";

}
       /*mover_p en esta funcion veremos todos lo movimientos de cada pieza
para cada pieza existe un if y dentro de este if de cada pieza hay varios if anidados
los cuales verifican que la pieza que seleciona el user y el movimiento que le de
a dicha pieza sea correcto --- leer los comentarios para saber que pieza es----*/

  //comprueba que no tecomas tu mismo
if(x==xp && y==yp)
{
          tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=tablero[y][x];
    x=y=xp=yp=0;

}else
//verifica que los valores ingresados este dentro del rango de eje de cordenadas
if(x>8 || y >8 || x<0 || y<0 || xp>8 || yp>8 || xp<0 || yp<0 ){
  //  movi_invalido(x,y,xp,yp);
//fin de verifica
}else

    //alfil
if(tablero[y][x]=='a'||tablero[y][x]=='A' ){
if(x-xp == y-yp){
          tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else
if(xp-x == y-yp){
    tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else
if(xp-x == yp-y){
    tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else
if(x-xp == yp-y){
    tablero[yp][xp]=tablero[y][x];
  tablero[y][x]=table[y][x];
  x=y=xp=yp=0;
}else{
//movi_invalido(x,y,xp,yp);
}//fin alfil
}else
//torre
if(tablero[y][x]=='t'||tablero[y][x]=='T' ){

    if(x==xp && yp>y){

    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;

}else
if(y==yp && xp>x){

    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;

}else

    if(x==xp && yp<y){

    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;

}else
if(y==yp && xp<x){

     tablero[yp][xp]=tablero[y][x];
  tablero[y][x]=table[y][x];
  x=y=xp=yp=0;
}else{
  //movi_invalido(x,y,xp,yp);
}
//fin torre
}else
//reina
if( tablero[y][x]=='q'||tablero[y][x]=='Q'){

    if(x==xp && yp>y){
      tablero[yp][xp]=tablero[y][x];
   tablero[y][x]=table[y][x];
   x=y=xp=yp=0;
}else
if(y==yp && xp>x){
     tablero[yp][xp]=tablero[y][x];
 tablero[y][x]=table[y][x];
 x=y=xp=yp=0;
}else

    if(x==xp && yp<y){
    tablero[yp][xp]=tablero[y][x];
   tablero[y][x]=table[y][x];
   x=y=xp=yp=0;
}else
if(y==yp && xp<x){
    tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else

if(x-xp == y-yp){
      tablero[yp][xp]=tablero[y][x];
   tablero[y][x]=table[y][x];
   x=y=xp=yp=0;
}else
if(xp-x == y-yp){
    tablero[yp][xp]=tablero[y][x];
  tablero[y][x]=table[y][x];
  x=y=xp=yp=0;
}else
if(xp-x == yp-y){
     tablero[yp][xp]=tablero[y][x];
  tablero[y][x]=table[y][x];
  x=y=xp=yp=0;
}else
if(x-xp == yp-y){
    tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else
{
  //movi_invalido(x,y,xp,yp);
}
//fin reina
}else
//caballo
if(tablero[y][x]=='c'||tablero[y][x]=='C'){
if(x+1==xp && y-2==yp){
     tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else
if(x+2==xp&&y-1==yp){
    tablero[yp][xp]=tablero[y][x];
   tablero[y][x]=table[y][x];
   x=y=xp=yp=0;
}else
if(x+2==xp&&y+1==yp){
    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
}else
if(x+1==xp&&y+2==yp){
    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
}else
if(x-1==xp&&y+2==yp){
    tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else
if(x-2==xp&&y+1==yp){
    tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else
if(x-2==xp&&y-1==yp){
    tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
}else
if(x-1==xp&&y-2==yp){
    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
}else{
//movi_invalido(x,y,xp,yp);
}
//fin caballo
}else
//rey
if(tablero[y][x]=='r'||tablero[y][x]=='R' ){
if(y-1==yp && x==xp || x+1==xp || x-1 == xp){
    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
}else
if(y==yp  && x==xp || x+1==xp || x-1 == xp){
    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
}else
if(y+1 == yp && x==xp || x+1==xp || x-1 == xp){
    tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
}else{
//movi_invalido(x,y,xp,yp);
}
//fin rey
}else
//PEON1
if(tablero[y][x]=='P' && xp>x){

    if(y==yp && x==xp-1 && tablero[yp][xp]==' ' || tablero[yp][xp]=='.' ){
          tablero[yp][xp]=tablero[y][x];
    tablero[y][x]=table[y][x];
    x=y=xp=yp=0;
    }else
    if(tablero[yp][xp]!=' '){
    if(x==xp-1 && y-1==yp || y+1==yp){
      tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
    }
    }else{
//movi_invalido(x,y,xp,yp);
}

}else
//peon2

if(tablero[y][x]=='p' && xp<x){
    if(y==yp && x==xp+1 && tablero[yp][xp]==' ' || tablero[yp][xp]=='.' ){
              tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
    }else
    if(tablero[yp][xp]!=' '){
    if(x==xp+1 && y-1==yp || y+1==yp){
         tablero[yp][xp]=tablero[y][x];
     tablero[y][x]=table[y][x];
     x=y=xp=yp=0;
    }
    }else{
//movi_invalido(x,y,xp,yp);
}
//fin de peon
}else{//si no es niguna de las poxixiones o coodeenadas antereore da movimiento invalido
//movi_invalido(x,y,xp,yp);
}


  //fin de mover







//PINTAR PIEZAS
    for(int j=0;j<9;j++){

        for(int d=0;d<9;d++){
if(tablero[j][d]=='p'){masked_blit( peonb, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='a'){masked_blit( alfilb, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='t'){masked_blit(torreb , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='q'){masked_blit( reinab, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='c'){masked_blit(caballob , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='r'){masked_blit( reyb , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='.'){masked_blit( espa_n , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]==' '){masked_blit( espa_b , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='P'){masked_blit( peonn, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='A'){masked_blit( alfiln, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='T'){masked_blit(torren , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='Q'){masked_blit( reinan, buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='C'){masked_blit(caballon , buffer, 0, 0, j*71,d*71, 71, 71);}
if(tablero[j][d]=='R'){masked_blit( reyn , buffer, 0, 0, j*71,d*71, 71, 71);}

        }

    }

//FIN DE PINTAR PIEZAS
blit(buffer,screen,0,0,0,0,639,639);


}
readkey();
destroy_bitmap(buffer);
allegro_exit();
return 0;
}
END_OF_MAIN();
