/**
   Codigo criado por Alecsander Lima 04/05/2021

   Modulo referente aos termistores e suas funcoes

 **/
 
#include "termistor.h"
#define AMOSTRAS_TEMPERATURA 10

Termistor::Termistor(int pin)
{
  _pin = pin;
}


double Termistor::GetTemperature ()
{
  const double rx = NTC_100K * exp(-BETA / (TEMPERATURA_REFERENCIA + TEMPERATURA_AMBIENTE_COMUM));
  double sensorTemperatura = analogRead (_pin);

  // Determina a resistência do termistor
  double v = (VCC * sensorTemperatura) / (1024);
  double rt = (VCC * RESISTOR) / v - RESISTOR;

  // Calcula a temperatura
  double temp = BETA / log(rt / rx);
  temp -= TEMPERATURA_REFERENCIA;

  double mediaTemp = 0;

  //Armazena os valores da temperatura para posteriormente calcular a media
  for (int i = 0; i < AMOSTRAS_TEMPERATURA; i++)
  {
    mediaTemp += temp;
    delay (100);
  }

  //Se temperatura negativa retorna zero (indicando erro)
  if (temp < -10)
  {
    mediaTemp = 0;
    return mediaTemp;
  }
  //Se nao, retorna media da temperatura registrada
  else
  {
    return mediaTemp / AMOSTRAS_TEMPERATURA ; //
  }
}
