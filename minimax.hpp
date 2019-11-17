#include <iostream>
using namespace std;
#ifndef _MINIMAX_
#define _MINIMAX_

int situacion[3][3] = {{0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0},
};

int MAX = 1; //Define maximizer as X -- Human
int MIN = -1; //Define minimizer as O -- Computer


int evaluar(int situacion){
    int puntuacion = 0;
    if(endgame(situacion, MIN)){
        puntuacion = 1;
    }else if(endgame(situacion,MAX)){
        puntuacion = -1;
    }
    return puntuacion;
}


bool ganador(int situacion, int jugador){
  int estado_de_victoria[8][3] = {{situacion[0][0], situacion[0][1], situacion[0][2]},
                                  {situacion[1][0], situacion[1][1], situacion[1][2]},
                                  {situacion[2][0], situacion[2][1], situacion[2][2]},
                                  {situacion[0][0], situacion[1][0], situacion[2][0]},
                                  {situacion[0][1], situacion[1][1], situacion[2][1]},
                                  {situacion[0][2], situacion[1][2], situacion[2][2]},
                                  {situacion[0][0], situacion[1][1], situacion[2][2]},
                                  {situacion[2][0], situacion[1][1], situacion[0][2]},
  }
  int sit_jugador[3] = {jugador,jugador,jugador};
  //Returns true if sit_jugador is in estado_de_victoria
  bool is_in = find(begin(estado_de_victoria), end(estado_de_victoria), sit_jugador) != end(estado_de_victoria);
  if(is_in){
      return true;
  }else{
      return false;
  }
}

bool fin_del_juego(situacion){
    return ganador(situacion, MAX) || ganador(situacion, MIN);
}




