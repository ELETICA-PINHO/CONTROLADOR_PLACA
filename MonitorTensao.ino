







float tensao() {

  for (i = 0; i < 1000; i++) {
    resultado  = analogRead(pinoSensorTensaoDC); //filtrado;//
    accuml = accuml + resultado;
    //Serial.println(accuml);


  }

if (tempoDelay + 500 < millis()){
  StatusLed   = ! StatusLed;
  tempoDelay = millis();
}

  tensao_M = accuml / 1000;

  accuml_tensao = tensao_M * (4.94 / 1024);
  accuml_tensao = accuml_tensao * 4.94;

  accuml = 0;

  return accuml_tensao;



}


void monitora() {

  if (tensao() >= 13.00) {
    digitalWrite(releInversor, LOW);
    digitalWrite(releventilacao, LOW);


if (tempo1Delay + 9000 < millis()){
 
  tempo1Delay = millis();

digitalWrite(releContatora, LOW);
    cont = 0;  



}

    

   
    




  }



  if (tensao() <= 10.50) {



if (tempo2Delay + 5000 < millis()){

  tempo2Delay = millis();

      if (digitalRead(releInversor) == LOW) {
      cont++;
      if (cont == 5) {
        digitalWrite(releInversor, HIGH);
        digitalWrite(releventilacao, HIGH);
        digitalWrite(releContatora, HIGH);
        cont = 0;

      }
    }

   



}///











  }


}
