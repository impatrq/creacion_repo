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
}

loop() {}