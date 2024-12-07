// Parâmetros do circuito
const int pinControle = 2;   // Pino digital (PWM) conectado ao resistor
const int pinMedicao = A2;   // Pino analógico conectado ao capacitor

// Limiares de tensão (em relação ao ADC)
int limiarCarregado = 1023 * (4.9 / 5.0);  // Aproximadamente 4,9 V
int limiarDescarga = 1023 * (0.1 / 5.0);   // Aproximadamente 0,1 V

int ciclos = 0;  // Contador de ciclos (carregamento e descarregamento)

void setup() {
  Serial.begin(9600);           // Inicia a comunicação serial
  pinMode(pinControle, OUTPUT); // Configura o pino de controle como saída
  digitalWrite(pinControle, LOW); // Inicia o pino em LOW (capacitor descarregado)
  Serial.println("tempo(ms),tensao(V),estado"); // Cabeçalho dos dados para CSV
}

void loop() {
  if (ciclos >= 2) { // Finaliza após dois ciclos completos
    Serial.println("Experimento finalizado.");
    while (1); // Loop infinito para parar o programa
  }

  // Carregar o capacitor
  unsigned long tempoInicial = millis();
  digitalWrite(pinControle, HIGH); // Configura o pino para HIGH (5V)
  while (true) {
    int leitura = analogRead(pinMedicao);
    float tensao = (5.0 * leitura) / 1023.0;
    unsigned long tempoAtual = millis() - tempoInicial;

    // Envia os dados para o Serial Monitor
    Serial.print(tempoAtual);
    Serial.print(",");
    Serial.print(tensao);
    Serial.println(",Carregando");

    if (leitura >= limiarCarregado) { // Verifica se atingiu 4,9 V
      break;
    }
    delay(50); // Atraso para suavizar as leituras
  }

  // Descarregar o capacitor
  tempoInicial = millis();
  digitalWrite(pinControle, LOW); // Configura o pino para LOW (0V)
  while (true) {
    int leitura = analogRead(pinMedicao);
    float tensao = (5.0 * leitura) / 1023.0;
    unsigned long tempoAtual = millis() - tempoInicial;

    // Envia os dados para o Serial Monitor
    Serial.print(tempoAtual);
    Serial.print(",");
    Serial.print(tensao);
    Serial.println(",Descarregando");

    if (leitura <= limiarDescarga) { // Verifica se atingiu 0,1 V
      break;
    }
    delay(50); // Atraso para suavizar as leituras
  }

  ciclos++; // Incrementa o contador de ciclos
}
