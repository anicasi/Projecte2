const int pinLDR = 2; 
const int pinTemp = 4; 
const int pinLED = 18; 

void setup() {
Serial.begin(115200);
delay(1000);
Serial.println("Llegint sensors...");

pinMode(pinLED, OUTPUT);
digitalWrite(pinLED, LOW);
}

void loop() {
// LECTURA LDR
int valorLDR = analogRead(pinLDR);
Serial.print("Llum detectada: ");
Serial.println(valorLDR);

// LECTURA TEMPERATURA LM35
int lecturaTemp = analogRead(pinTemp);

float volts = (lecturaTemp * 5.0) / 4095.0; // Conversió a volts
float temperatura = volts * 100.0; // Conversió a °C

Serial.print("Temperatura: ");
Serial.print(temperatura);
Serial.println(" °C");

// ALERTA TEMPERATURA
if (temperatura > 25.0) {
digitalWrite(pinLED, HIGH);
Serial.println("ALERTA: Sobreescalfament CPD!");
} else {
digitalWrite(pinLED, LOW);
}

// ALERTA LLUM
if (valorLDR > 2000) {
Serial.println("AVÍS: Porta oberta o llum encesa");
}

delay(2000);
}
