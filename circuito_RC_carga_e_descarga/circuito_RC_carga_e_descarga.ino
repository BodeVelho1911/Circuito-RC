// Parâmetros do circuito
const int pinControle = 2;   // Pino digital (PWM) conectado ao resistor
const int pinMedicao = A2;   // Pino analógico conectado ao capacitor

// Limiares de tensão (em relação ao ADC)
int limiarCarregado = 1023 * (4.9 / 5.0);  // Aproximadamente 4,9 V
int limiarDescarga = 1023 * (0.1 / 5.0);   // Aproximadamente 0,1 V

void setup() {
  Serial.begin(9600);           // Inicia a comunicação serial
  pinMode(pinControle, OUTPUT); // Configura o pino de controle como saída
  digitalWrite(pinControle, LOW); // Inicia o pino em LOW (capacitor descarregado)
}

void loop() {
  // Carregar o capacitor
  digitalWrite(pinControle, HIGH); // Configura o pino para HIGH (5V)
  while (true) {
    int leitura = analogRead(pinMedicao);
    float tensao = (5.0 * leitura) / 1023.0;

    // Envia os dados para o Serial Plotter
    Serial.print("Carregando, ");
    Serial.print(tensao);
    Serial.println(" V");

    if (leitura >= limiarCarregado) { // Verifica se atingiu 4,9 V
      break;
    }
    delay(50); // Atraso para suavizar as leituras
  }

  // Descarregar o capacitor
  digitalWrite(pinControle, LOW); // Configura o pino para LOW (0V)
  while (true) {
    int leitura = analogRead(pinMedicao);
    float tensao = (5.0 * leitura) / 1023.0;

    // Envia os dados para o Serial Plotter
    Serial.print("Descarregando, ");
    Serial.print(tensao);
    Serial.println(" V");

    if (leitura <= limiarDescarga) { // Verifica se atingiu 0,1 V
      break;
    }
    delay(50); // Atraso para suavizar as leituras
  }

  delay(1000); // Pausa entre ciclos
}
