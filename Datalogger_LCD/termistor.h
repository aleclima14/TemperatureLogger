/**
 * Codigo criado por Alecsander Lima 04/05/2021
 * 
 * Modulo referente aos pinos usados no hardware 
 * 
 * 
 * */
#ifndef termistor_h
#define termistor_h

#include "Arduino.h"
#include <math.h>
#include "configuration.h"
#include "pin_map.h"

//Cria a classe para poder facilitar a criacao de novos canais de medicao
class Termistor
{
  public:
    Termistor (int pin);
    double GetTemperature();
  private:
    int _pin; 
};

double GetTemperature ();

#endif
