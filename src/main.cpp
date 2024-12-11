#include <Arduino.h>

#define TOUCH_PIN 32 // Pin capacitivo D32
#define LED_PIN 23    // Pin del LED (cambiado al pin 23)

const int buzzerPin = 5; // Pin D5
const int ledcChannel = 0; // Canal 0
const int ledcTimerBit = 13; // Resolución del timer

bool ledState = false; // Estado inicial del LED

void setup() {
  // Configurar el canal del LEDC
  ledcSetup(ledcChannel, 0, ledcTimerBit);
  // Adjuntar el pin al canal
  ledcAttachPin(buzzerPin, ledcChannel);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState); // Inicializar el LED apagado
}

void playTone(int frequency, int duration) {
  ledcWriteTone(ledcChannel, frequency);
  delay(duration);
  ledcWriteTone(ledcChannel, 0); // Silenciar el buzzer
}

void loop() {
  // Leer el valor del sensor capacitivo
  int touchValue = touchRead(TOUCH_PIN);
  
  // Detecta el toque si el valor es menor que 30
  if (touchValue < 30) {
    ledState = true; // Enciende el LED
    digitalWrite(LED_PIN, HIGH); // Mantiene el LED encendido

    // Melodía de Halloween
    int melody[] = {
      440, 440, 660, 660, 880, 880, 660, 440,
      330, 330, 220, 220, 330, 440, 660, 660
    };

    int noteDurations[] = {
      400, 400, 400, 400, 400, 400, 400, 400,
      400, 400, 400, 400, 400, 400, 400, 400
    };

    // Reproducir la melodía
    for (int thisNote = 0; thisNote < 16; thisNote++) {
      playTone(melody[thisNote], noteDurations[thisNote]);
      delay(50); // Pequeño retraso entre notas
    }

    ledState = false; // Apaga el LED después de que termine la melodía
    digitalWrite(LED_PIN, LOW); // Apaga el LED

    delay(2000); // Esperar 2 segundos antes de permitir otro toque
  }

  delay(100); // Pequeño retraso entre lecturas
}
