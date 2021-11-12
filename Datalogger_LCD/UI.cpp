/*



#include "UI.h"
#include <DHT.h>

double TemperaturaMedidaCH1;
double TemperaturaMedidaCH2;

Termistor SensorCH1(PINO_TERMISTOR_CH1);
Termistor SensorCH2(PINO_TERMISTOR_CH2);

DHT dht(DHTPIN, DHTTYPE);
dht.begin();

TemperaturaMedidaCH1 = SensorCH1.GetTemperature();
TemperaturaMedidaCH2 = SensorCH2.GetTemperature();

void ExibeTemperatura()
{
  TemperaturaMedidaDHT = dht.readTemperature();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print ("CH: ");
 // lcd.print (TemperaturaMedidaCH1);
  lcd.print (" ");
 // lcd.print (TemperaturaMedidaCH2);

  lcd.setCursor(0, 1);
  lcd.print ("DHT: ");
  lcd.print(TemperaturaMedidaDHT);
  lcd.print (" C");

  delay(100);
}
*/
