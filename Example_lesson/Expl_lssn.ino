int cont = 0;

int key_pin = 12;

int led_pin = 13;
int led_pin2 = 9;

int pot_pin = A0;

float volt = 0;
int pot_val = 0;
int led_int = 0;

bool key_stats = false;

void setup(){
  	pinMode(key_pin, INPUT);
  	pinMode(pot_pin, INPUT);
	pinMode(led_pin, OUTPUT);
	pinMode(led_pin2, OUTPUT);
  	Serial.begin(9600);
}

void loop()
{
 key_stats = digitalRead(key_pin);
  
  if(key_stats == true) {
  digitalWrite(led_pin, HIGH);
   
    while(digitalRead(key_pin) == true){
      
    contador = cont + 1;
      Serial.println(cont);
    }
    contador = 0;
     
  }
  else{
    digitalWrite(led_pin, LOW);
	Serial.println("OFF");
    while(digitalRead(key_pin) == false)
    {
    	pot_val = analogRead(pot_pin);
    	volt = pot_val *5.0/1023;
    	led_int = map(pot_val, 0, 1023, 0, 255);
    	Serial.println(volt);  
      	analogWrite(led_pin2, led_int);
    }
    
  }
  
}