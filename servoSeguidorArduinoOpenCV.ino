#include <Servo.h>
Servo servo1;

String entradaSerial = "";         // String para almacenar entrada
bool entradaCompleta = false;  // Indicar si el String está completo

int pin = 9;    // pin de conexión PWM al servo
int pulsoMinimo = 580;  // Duración en microsegundos del pulso para girar 0º
int pulsoMaximo = 2500; // Duración en microsegundos del pulso para girar 180º
int angulo = 0; // Variable para guardar el angulo que deseamos de giro

void setup()
{
  servo1.attach(pin, pulsoMinimo, pulsoMaximo);
  Serial.begin(9600);
}

void loop()
{
  if (entradaCompleta) {
    if (entradaSerial == "izq1\n") {
      Serial.print("0 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo1.write(0);
    }
    else if (entradaSerial == "izq2\n") {
      Serial.print("30 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo1.write(30);
    }
    else if (entradaSerial == "izq3\n") {
      Serial.print("60 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo1.write(60);
    }
    else if (entradaSerial == "ctr\n") {
      Serial.print("Centro 90 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo1.write(90);
    }
    else if (entradaSerial == "der3\n") {
      Serial.print("120 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo1.write(120);
    }
    else if (entradaSerial == "der2\n") {
      Serial.print("150 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo1.write(150);
    }
    else if (entradaSerial == "der1\n") {
      Serial.print("180 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo1.write(180);
    }
    else { // Cualquier otro dato recibido
      Serial.println("El dato recibido es inválido!!");
    }
    entradaSerial = "";
    entradaCompleta = false;
  }
}

// Función que se activa al recibir algo por
// el puerto serie, Interrupción del Puerto Serie.
void serialEvent() {
  while (Serial.available()) {
    // Obtener bytes de entrada:
    char inChar = (char)Serial.read();
    // Agregar al String de entrada:
    entradaSerial += inChar;
    // Para saber si el string está completo, se detendrá al recibir
    // el caracter de retorno de línea ENTER \n
    if (inChar == '\n') {
      entradaCompleta = true;
    }
  }
}
