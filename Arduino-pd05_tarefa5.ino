const float pi = 3.1415;

unsigned long  tin, tend, inter;

int Ampl1, Ampl2;

double senodei;

float phase, freq, tempo;

void setup()
{
     Serial.begin(115200);
}

void loop(){
  Serial.println("Digite a primeira amplitude da onda: ");
  Ampl1 = lerEntradaNum();
  
  Serial.println("Digite a segunda amplitude da onda: ");
  Ampl2 = lerEntradaNum();
  
  Serial.println("Digite a frequencia da onda: ");
  freq = lerEntradaNum();
  
  Serial.println("Digite a fase inicial da onda em Pi-radianos: ");
  phase = lerEntradaNum();
  
  if(Ampl1 > 0 && Ampl2 > 0 && freq > 0){
    
    inter=50;   // em milissegundos
    freq=0.1;   // em Hz

    Serial.println("Seno:");
    
    for (int i=0; i<200;i++){
      tempo = (float)i*((float)inter/1000);
      if(i <= 100){
      	senodei= Ampl1 * sin(2*pi*freq*tempo + phase);
      } else {
        senodei= Ampl2 * sin(2*pi*freq*tempo + phase);
      }
      Serial.println(senodei);
     
      //delay
      tin = millis();
      tend=tin+inter;
      while(tin<tend){tin=millis();}
  
    }
    
    Serial.println(0);
    Serial.println(0);
    Serial.println(0);
    Serial.println(0);
    Serial.println(0);
    
  } else {
    Serial.println("!_!Valor nao reconhecido!_!");
  }
  
}


//Lê entrada e converte para numero
float lerEntradaNum(){
  char caractere;
  String entrada;
  float numero;
  
  while(Serial.available() == 0){}
  while(Serial.available() > 0){
    caractere = Serial.read();
    if(caractere != '\n'){
      entrada.concat(caractere);
      delay(50);
    }
  }
  numero = entrada.toFloat();
  return numero;
}