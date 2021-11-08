/*
  Autor: Alessandro Pinho
  Data: 29-08-2021

  Aplicação:

  Controle de Transferencia rede para solar




*/



#include <Wire.h>


#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);



//--------------------mapeamento HardWare-------------------------------------

#define pinoSensorTensaoDC A0
#define releInversor 2
#define releventilacao 3
#define releContatora 4
#define funcionamento 6
#define botao_funcao 5
#define pinoDeteccaoRede A1
#define pinoDeteccaoSolar A2



//----------------Prototipo de funçoes-------------------------------------------------

void monitora();
float tensao();
void Detector();
long moving_average();
 bool flag = 0;

int status = 0;
char status_display;


//------------------variaveis Globais---------------------------------------------------


int cont8Seg = 0;
int cont = 0;
float resultado;
long int i = 0;
float accuml = 0;
float accuml_tensao = 0;
float tensao_M = 0;
bool StatusLed = 0;
static long long tempoDelay =0;
static long long tempo1Delay =0;
static long long tempo2Delay =0;
#define      n 1


int       original,          //recebe o valor de AN0
          filtrado;          //recebe o valor original filtrado

int       numbers[n];        //vetor com os valores para média móvel





void setup()
{
  Serial.begin(9600);
 


    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)

  display.clearDisplay();
  display.display();





  pinMode(pinoSensorTensaoDC, INPUT);
 
  pinMode(botao_funcao, INPUT_PULLUP   );

  pinMode(releInversor, OUTPUT);
  pinMode(releventilacao, OUTPUT);
  pinMode(releContatora, OUTPUT);
  pinMode(funcionamento, OUTPUT);


  digitalWrite(releInversor, HIGH);
  digitalWrite(releventilacao, HIGH);
  digitalWrite(releContatora, HIGH);


}
void loop() {


 // monitora();

  VisualizarOLD();

  //Detector();
  tensao();
funcaoStatus();


 



if (tempoDelay + 500 < millis()){
  StatusLed   = ! StatusLed;
  tempoDelay = millis();

 digitalWrite(funcionamento, StatusLed);

}












}
