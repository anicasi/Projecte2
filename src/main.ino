const int pinLDR = 2;
const int pinTemp = 4;
const int pinLED = 18;

bool ledForcatOff = false;   // Control manual del LED

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Sistema preparat. Escriu STATUS per veure dades.");

  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);
}

void loop() {

  // --- LECTURA DE COMANDES ---
  if (Serial.available()) {
  String comanda = Serial.readStringUntil('\n');
  comanda.trim();
  processarComanda(comanda);
  }

  // --- LECTURA LDR ---
  int valorLDR = analogRead(pinLDR);

  // --- LECTURA TEMPERATURA ---
  int lecturaTemp = analogRead(pinTemp);
  float volts = (lecturaTemp * 5.0) / 4095.0;
  float temperatura = volts * 100.0;

  // (NO HI HA ALERTES)

  delay(2000);
}

// -----------------------------
// FUNCIONS DE COMANDES
// -----------------------------
void processarComanda(String cmd) {

  if (cmd == "STATUS") {
  Serial.println("---- ESTAT ACTUAL ----");

  int valorLDR = analogRead(pinLDR);
  Serial.print("Llum: ");
  Serial.println(valorLDR);

  int lecturaTemp = analogRead(pinTemp);
  float volts = (lecturaTemp * 5.0) / 4095.0;
  float temperatura = volts * 100.0;

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.println("-----------------------");
  }

  else if (cmd == "LED_OFF") {
  ledForcatOff = true;
  digitalWrite(pinLED, LOW);
  Serial.println("LED apagat manualment.");
  }

  else {
  Serial.println("Ordre desconeguda.");
  }
}

