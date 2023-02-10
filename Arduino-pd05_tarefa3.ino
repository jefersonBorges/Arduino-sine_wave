const float pi = 3.1415;

unsigned long  tin, tend, inter;

int Ampl;

double senodei;

float phase, freq, tempo;

void setup()
{
     Serial.begin(115200);
}

void loop(){
  Serial.println("Digite a amplitude da onda: ");
  Ampl = lerEntradaNum();
  Serial.print(Ampl);
  Serial.println(" ");
  
  Serial.println("Digite a frequencia da onda: ");
  freq = lerEntradaNum();
  Serial.print(freq);
  Serial.println(" ");
  
  if(Ampl > 0 && freq > 0){
    
    inter=50;   // em milissegundos
    freq=0.1;   // em Hz
    phase = 0;  // em Pi-radianos

    Serial.println("Seno:");
    
    for (int i=0; i<200;i++){
      tempo = (float)i*((float)inter/1000);
      senodei= Ampl * sin(2*pi*freq*tempo + phase);
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