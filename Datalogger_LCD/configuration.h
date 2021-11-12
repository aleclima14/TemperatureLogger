/**
 * Codigo criado por Alecsander Lima 04/05/2021
 * 
 * Modulo referente as configuracoes usadas no sistema 
 * 
 * 
 * */
#include "Arduino.h"
#include "pin_map.h"
#include "termistor.h"

/*Definicao do termistor usado*/
#define BETA 3950
#define NTC_100K 100000
#define TEMPERATURA_REFERENCIA 273.15
#define TEMPERATURA_AMBIENTE_COMUM 25 

/*Definicao do sistema*/
#define VCC 5.0
#define RESISTOR 4700

/*Definicao do DHT*/
#define DHTTYPE DHT22


/*Display LCD*/
#define LCD_I2C_ANDRESS 0x27
#define LCD_COLUNA 16
#define LCD_LINHA 2
