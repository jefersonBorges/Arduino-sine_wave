
unsigned long  tin, tend;

const float pi = 3.1415;

float phase = 0;

void setup()
{
     Serial.begin(115200);
}

void loop()
{
  unsigned long inter=50;   // em milissegundos
  int Ampl=2;
  float freq=0.1;   // em Hz
  float phase = 0;  // em Pi-radianos
  double senodei;
  float tempo;
  
  Serial.println("Seno =");
  for (int i=0; i<200;i++)
  {
   tempo = (float)i*((float)inter/1000);
   senodei= Ampl * sin(2*pi*freq*tempo + phase);
   Serial.println(senodei);
   tin = millis();
   tend=tin+inter;
   while(tin<tend){tin=millis();}
  }
Serial.println(0);
Serial.println(0);
Serial.println(0);
Serial.println(0);
Serial.println(0);
}
