const int sensorPin1 = A0; 
const int sensorPin2 = A1;
const int sensorPin3 = A2;
int sensorValue1 = 0;   
int sensorValue2 = 0;
int sensorValue3 = 0;
float Vin = 5;
float Vout1 = 0;  
float Vout2 = 0;
float Vout3 = 0;
float Rref1 = 1000; 
float Rref2 = 1000;
float Rref3 = 910;
float r1 = 0; 
float r2 = 0;  
float r3 = 0;
float ra=0,rb=0,rc=0;
void setup ()
{
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
}
void getR1(){
  sensorValue1 = analogRead(sensorPin1);
  Vout1 = (Vin * sensorValue1) / 1024;    
  r1 = Rref1 * (1 / ((Vin / Vout1) - 1));  
  Serial.print("Resistor 1: ");                  
  Serial.println(r1);                
  delay(1000);
  }
  void getR2(){
  sensorValue2 = analogRead(sensorPin2);
  Vout2 = (Vin * sensorValue2) / 1023;    
  r2 = Rref2 * (1 / ((Vin / Vout2) - 1));  
  Serial.print("Resistor 2: ");                  
  Serial.println(r2);                     // Give calculated resistance in Serial Monitor
  delay(1000);
  }
  void getR3(){
  sensorValue3 = analogRead(sensorPin3);
  Vout3 = (Vin * sensorValue3) / 1023;    
  r3 = Rref3 * (1 / ((Vin / Vout3) - 1));  
  Serial.print("Resistor 3: ");                  
  Serial.println(r3);                     // Give calculated resistance in Serial Monitor
    delay(1000);
  }
void loop ()
{
  Serial.println("------------------------------------------");
  Serial.println("Delta to Y");
  Serial.println("Reading Resistors. . . . ");
  getR1();
  getR2();
  getR3();
  Serial.println("Computing.....");
  delay(2000);
   ra=(r2*r3)/(r1+r2+r3);
   rb=(r3*r1)/(r1+r2+r3);
    rc=(r1*r2)/(r1+r2+r3);
    Serial.print("Resistor A:");
    Serial.println(ra);
    Serial.print("Resistor B:");
    Serial.println(rb);
    Serial.print("Resistor C:");
    Serial.println(rc);
    Serial.println("------------------------------------------");
delay(2000);
}
