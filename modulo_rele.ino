//en estas salidas van los reles :D
int rele1 = 3;
int rele2 = 4;
int rele3 = 5;
int rele4 = 6;

void setup() {
//aca ponemos para que todos los pines sean de salida
pinMode(rele1, OUTPUT);
pinMode(rele2, OUTPUT);
pinMode(rele3, OUTPUT);
pinMode(rele4, OUTPUT);
//los reles tienen lógica inversa, por eso los inicializamos en HIGH
digitalWrite(rele1, HIGH);
digitalWrite(rele2, HIGH);
digitalWrite(rele3, HIGH);
digitalWrite(rele4, HIGH);
//inicializamos la comunicacion via serial
Serial.begin(9600);  
}

void loop() {
 if(Serial.available()>0){
    int s = Serial.parseInt();
    //Serial.println(s);
    if(s==1 || s==2 || s==3 || s==4){
    conmutarRele(s);    
    }
  }
  delay(200);
}

void conmutarRele(int _rele){
  _rele = _rele+2;
  bool p = digitalRead(_rele);
  //Serial.println(p);  
  //delay(200);
  Serial.print("Rele nro: ");
  Serial.print(_rele-2);
  if(!p){
  digitalWrite(_rele, HIGH);  
  Serial.println(" se ha apagado.");   
  } else {
    digitalWrite(_rele, LOW);
    Serial.println(" se ha encendido.");
    }
}

