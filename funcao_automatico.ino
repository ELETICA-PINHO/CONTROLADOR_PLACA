void funcaoStatus(){
 

  if(digitalRead(botao_funcao) == LOW && flag == 0){
    status ++;
    flag = 1;
  }

   if(!digitalRead(botao_funcao) == LOW && flag == 1){
    flag = 0;
  }
    
    
  

    switch (status) {
  case 0:
  status_display = 'A';  
   monitora();
    break;
  case 1:
    status_display = 'M'; 
    digitalWrite(releInversor, LOW);
    digitalWrite(releventilacao, LOW);
    digitalWrite(releContatora, LOW);
    break;

     case 2:
     status_display = 'D'; 
    digitalWrite(releInversor, HIGH);
    digitalWrite(releventilacao, HIGH);
    digitalWrite(releContatora, HIGH);

     break;

          case 3:

      status    =0;
     break;
 
 
}


}