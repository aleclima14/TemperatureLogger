/*
   Codigo criado por Alecsander 04/05/2021
   Todos os direitos reservados
*/

#include "configuration.h"
#include "termistor.h"
//#include "UI.h"

#include <U8g2lib.h>


#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


#include <LiquidCrystal_I2C.h>
#include <DHT.h>

U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);

Termistor SensorCH1(PINO_TERMISTOR_CH1);
Termistor SensorCH2(PINO_TERMISTOR_CH2);
Termistor SensorCH3(PINO_TERMISTOR_CH3);
Termistor SensorCH4(PINO_TERMISTOR_CH4);

DHT dht(DHTPIN, DHTTYPE);

double TemperaturaMedidaCH1;
double TemperaturaMedidaCH2;
double TemperaturaMedidaCH3;
double TemperaturaMedidaCH4;

float TemperaturaMedidaDHT;
float UmidadeMedidaDHT;

LiquidCrystal_I2C lcd(LCD_I2C_ANDRESS, LCD_COLUNA, LCD_LINHA);

void setup()
{
  dht.begin();
  u8g2.begin();
}

void loop()
{

  void ExibeTemperatura();

  TemperaturaMedidaCH1 = SensorCH1.GetTemperature();
  TemperaturaMedidaCH2 = SensorCH2.GetTemperature();
  TemperaturaMedidaCH3 = SensorCH3.GetTemperature();
  TemperaturaMedidaCH4 = SensorCH4.GetTemperature();

  TemperaturaMedidaDHT = dht.readTemperature();
  UmidadeMedidaDHT = dht.readHumidity();

  u8g2.firstPage();
  do {

    //Desenha o layout da primeira tela
    //u8g2.drawFrame(0,0,128,64);
    u8g2.drawLine(45, 2, 45, 61);
    u8g2.drawLine(87, 2, 87, 61);
    u8g2.drawLine(48, 32, 125, 32);



    //TEMP DHT
    u8g2.setFont(u8g2_font_5x7_tf);
    u8g2.setCursor(2, 12);
    u8g2.print("TEMP.");
    u8g2.setFont(u8g2_font_helvB08_tf);
    u8g2.setCursor(2, 25);
    u8g2.print(TemperaturaMedidaDHT);
    u8g2.print(" C");

    //UMIDADE DHT
    u8g2.setFont(u8g2_font_5x7_tf);
    u8g2.setCursor(2, 44);
    u8g2.print("UMID.");
    u8g2.setFont(u8g2_font_helvB08_tf);
    u8g2.setCursor(2, 57);
    u8g2.print(UmidadeMedidaDHT);
    u8g2.print(" %");

    //TEMP CH1
    u8g2.setFont(u8g2_font_5x7_tf);
    u8g2.setCursor(48, 12);
    u8g2.print("CH1");
    u8g2.setFont(u8g2_font_helvB08_tf);
    u8g2.setCursor(48, 25);
    u8g2.print(TemperaturaMedidaCH1);
    //u8g2.print(" C");

    //TEMP CH2
    u8g2.setFont(u8g2_font_5x7_tf);
    u8g2.setCursor(90, 12);
    u8g2.print("CH2");
    u8g2.setFont(u8g2_font_helvB08_tf);
    u8g2.setCursor(90, 25);
    u8g2.print(TemperaturaMedidaCH2);
    //u8g2.print(" C");

    //TEMP CH3
    u8g2.setFont(u8g2_font_5x7_tf);
    u8g2.setCursor(48, 44);
    u8g2.print("CH3");
    u8g2.setFont(u8g2_font_helvB08_tf);
    u8g2.setCursor(48, 57);
    u8g2.print(TemperaturaMedidaCH3);
    //u8g2.print(" C");
    
    //TEMP CH4
    u8g2.setFont(u8g2_font_5x7_tf);
    u8g2.setCursor(90, 44);
    u8g2.print("CH4");
    u8g2.setFont(u8g2_font_helvB08_tf);
    u8g2.setCursor(90, 57);
    u8g2.print(TemperaturaMedidaCH4);
    //u8g2.print(" C");
    

  } while ( u8g2.nextPage() );

  delay(100);

}
