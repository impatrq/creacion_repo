#include <Arduino.h>
#include <FreeRTOS.h>

// Pines para los sensores ultrasónicos
const int trigPin1 = 9;
const int echoPin1 = 8;
const int trigPin2 = 7;
const int echoPin2 = 6;

// Variables globales para almacenar las distancias
volatile float distance1 = 0;
volatile float distance2 = 0;

// Declaración de funciones
void measureDistance(void *pvParameters);
void calculateLateralMovement(void *pvParameters);

// Setup
void setup() {
  Serial.begin(9600);
// Configuración de los pines
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

}

loop() {}

void measureDistance(void *pvParameters) {
  for (;;) {
    // Sensor 1
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    float duration1 = pulseIn(echoPin1, HIGH);
    distance1 = (duration1 * 0.034) / 2;
    
    // Sensor 2
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    float duration2 = pulseIn(echoPin2, HIGH);
    distance2 = (duration2 * 0.034) / 2;

    // Imprimir distancias para depuración
    Serial.print("Distance 1: ");
    Serial.print(distance1);
    Serial.print(" cm, Distance 2: ");
    Serial.print(distance2);
    Serial.println(" cm");

    // Esperar 200 ms antes de la siguiente medición
    vTaskDelay(pdMS_TO_TICKS(200));
  }
}

void calculateLateralMovement(void *pvParameters) {
  for (;;) {
    // Cálculo de movimiento lateral
    float lateralMovement = distance2 - distance1;
    
    // Aquí puedes añadir el código para actuar sobre motores u otro mecanismo
    // para realizar el movimiento lateral basado en la variable lateralMovement.
    
    // Imprimir el resultado para depuración
    Serial.print("Lateral Movement: ");
    Serial.println(lateralMovement);
    
    // Esperar 200 ms antes de la siguiente ejecución
    vTaskDelay(pdMS_TO_TICKS(200));
  }
}
