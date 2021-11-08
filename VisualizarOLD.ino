void VisualizarOLD() {

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  display.print(tensao());
  display.setCursor(80, 8);
  display.print("V");
 
 if(status_display == 'A'){

   if (digitalRead(releInversor) == LOW) {

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("S");
    display.setCursor(20, 0);
    display.print("Timer");
    display.setCursor(60, 0);
    display.print(cont);  

  } else {

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("C");
    display.setCursor(20, 0);
    display.print("Timer");
    display.setCursor(60, 0);
    display.print("OFF");

  }



 }else{
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("===================");
 }

  


    if(status_display == 'M'){
      
      display.setTextSize(1);
      display.setCursor(128, 17);
      display.print("MANUAL");
    }


    if(status_display == 'A'){
      
      display.setTextSize(1);
      display.setCursor(128, 17);
      display.print("automatico");
     
    }


        if(status_display == 'D'){     
          display.setTextSize(1);
          display.setCursor(128, 17);
          display.print("Desativado");
     
     
    }    
        display.display();
        display.clearDisplay();
}




void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  for (uint8_t i = 0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    if ((i > 0) && (i % 21 == 0))
      display.println();
  }
  display.display();
  delay(1);
}
