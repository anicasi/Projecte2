const int pinLDR = 2; 

void setup() {
  Serial.begin(115200);   // Inicialitzem la comunicació sèrie a 115200 baudios
  delay(1000);
  Serial.println("Llegint dades del sensor LDR...");
}

void loop() {
   int valor = analogRead(pinLDR);   // Llegim el valor analògic (de 0 a 4095)

  Serial.print("Llum detectada: ");   // Mostra el valor pel Monitor Sèrie

  Serial.println(valor);

  delay(2000);  // Esperem 2000ms (2 segons) per no col·lapsar la pantalla

}
