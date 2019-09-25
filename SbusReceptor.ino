/*PROGRAMA QUE DETECTA CAMBIOS BRUSCOS EN LA SEÑAL DE LOS 12 CANALES CON TOLERANCIA DE +0.35 Y -0.35. ADAPTADO A SERVO TEST MODE
EL CONTROL DEBE ESTAR CONECTADO EN TEST MODE PARA LUEGO INICIAR EL PROGRAMA ESTE ESPERARA 1 SEGUNDO
PARA COMENZAR A HACER LAS VERIFICACIONES POR PRIMERA VEZ, ESTO PORQUE EL SERVO TEST MODE INICIALIZA SUS 
VALORES EN LOS VALORES MAXIMOS Y MINIMOS Y NO ES POSIBLE PREDECIR EL PRIMER VALOR LEIDO

*/
#include <SBUS.h>
SBUS sbus(Serial1);
int AlarmaDeRuido = 0; // La alarma de ruido (es decir la verificación estará apagada hasta transcurrido 1 segundo)
float SbusRead[16] ;   
bool Failsafe, LostFrame;
int PinBuzzer = 13; //Cambiar para colocar buzzer luego

unsigned long TiempoAhora = 0; //  Parametros para la espera con millis
const unsigned long periodo = 2000; // 2 segundo de espera

float canaluno = +0.10;
float canaldos = +0.10;
float canaltres = +0.10;
float  canalcuatro = +0.10;
float canalcinco = +0.10;
float  canalseis = +0.10;
float canalsiete = +0.10;
float canalocho = +0.10;
float canalnueve = +0.10;
float canaldiez = +0.10;
float  canalonce = +0.10;
float canaldoce = +0.10;

float canalunoR;
float canaldosR;
float canaltresR;
float  canalcuatroR;
float canalcincoR;
float  canalseisR;
float canalsieteR;
float canalochoR;
float canalnueveR;
float canaldiezR;
float  canalonceR;
float canaldoceR;

void setup() {
 Serial.begin(115200);
 sbus.begin();
pinMode(PinBuzzer, OUTPUT);
digitalWrite(PinBuzzer, LOW);
}

void loop() {

  if (sbus.readCal(&SbusRead[0], &Failsafe, &LostFrame)) {

      canaluno = SbusRead[0];
      canaldos = SbusRead[1];
      canaltres = SbusRead[2];
      canalcuatro = SbusRead[3];
      canalcinco = SbusRead[4];
      canalseis = SbusRead[5];
      canalsiete = SbusRead[6];
      canalocho = SbusRead[7];
      canalnueve = SbusRead[8];
      canaldiez = SbusRead[9];
      canalonce = SbusRead[10];
      canaldoce = SbusRead[11];
}


// COMIENZAN LOS IF VERIFICAN QUE NO HAYAN CAMBIOS BRUSCOS EN LOS VALORES DE RECEPCIÓN (DETECCION DE RUIDO)
  // VERIFICA SOLO SI HA PASADO 1 SEGUNDO 
  if (millis() - TiempoAhora > periodo)  {
    TiempoAhora = millis(); 
    // Espero 2 segundos
    AlarmaDeRuido = 1;
  }

  if (AlarmaDeRuido !=0) {
    
 if (canaluno > (canalunoR + 0.35) || (canaluno < (canalunoR -0.35))){ // Se verifica que la señal actual medida no tenga una diferencoia de 0.15 con respecto al anterior
    digitalWrite(PinBuzzer, HIGH); //De ser asi se activa el buzzer
  }
if (canaldos > (canaldosR + 0.35) || (canaldos < (canaldosR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
if (canaltres > (canaltresR + 0.35) || (canaltres < (canaltresR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canalcuatro > (canalcuatroR + 0.35) || (canalcuatro < (canalcuatroR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canalcinco > (canalcincoR + 0.35) || (canalcinco < (canalcincoR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canalseis > (canalseisR + 0.35) || (canalseis < (canalseisR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canalsiete > (canalsieteR + 0.35) || (canalsiete < (canalsieteR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canalocho > (canalochoR + 0.35) || (canalocho < (canalochoR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canalnueve > (canalnueveR + 0.35) || (canalnueve < (canalnueveR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canaldiez > (canaldiezR + 0.35) || (canaldiez < (canaldiezR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canalonce > (canalonceR + 0.35) || (canalonce < (canalonceR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  if (canaldoce > ((canaldoceR + 0.35)) || (canaldoce < (canaldoceR - 0.35))){
    digitalWrite(PinBuzzer, HIGH);
  } 
  }
// Se cambian los valores de referencia por los actuales que serán utilizados en el siguiente ciclo
      canalunoR = canaluno;
      canaldosR = canaldos;
      canaltresR = canaltres;
      canalcuatroR = canalcuatro;
      canalcincoR = canalcinco;
      canalseisR = canalseis;
      canalsieteR = canalsiete;
       canalochoR = canalocho;
      canalnueveR = canalnueve;
      canaldiezR = canaldiez;
      canalonceR = canalonce;
      canaldoceR = canaldoce;

  
// IMPRIME LOS VALORES DE TODOS LOS CANALES 
    Serial.print("salidas");
    Serial.print("\t");
    Serial.print(canaluno,1);
    Serial.print("\t");
    Serial.print(canaldos,1);
    Serial.print("\t");
    Serial.print(canaltres,1);
    Serial.print("\t");
    Serial.print(canalcuatro,1);
    Serial.print("\t");
    Serial.print(canalcinco,1);
    Serial.print("\t");
    Serial.print(canalseis,1);
    Serial.print("\t");
    Serial.print(canalsiete,1);
    Serial.print("\t");
    Serial.print(canalocho,1);
    Serial.print("\t");
    Serial.print(canalnueve,1);
    Serial.print("\t");
    Serial.print(canaldiez,1);
    Serial.print("\t");
    Serial.print(canalonce,1);
    Serial.print("\t");
    Serial.println(canaldoce,1);
 
}
