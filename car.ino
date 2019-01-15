#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int in1 =D0;
int in2 =D1;
int in3 =D2;
int in4 =D3;
int pwm1 =D4;
int pwm2 =D5;

char auth[] = "c63f382ea53849cf9d1adfe879e2ba87";
char ssid[] = "This_is_mine";
char pass[] = "fdgk5606";

BLYNK_WRITE(V0)
{
  int r_slider = param.asInt();
  //Turn off in range 400-600
  if (r_slider < 600 && r_slider > 400)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  //Move forward when > 600
  if (r_slider > 600)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(pwm1, map(r_slider, 600, 1023, 0, 1023));
    Serial.println(map(r_slider, 600, 1023, 0, 255));
  }
  //Move backwards when < 400
  if (r_slider < 400)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(pwm1, map(r_slider, 400, 0, 0, 1023));
    Serial.println(map(r_slider, 400, 0, 0, 255));    
  }
}

BLYNK_WRITE(V1)
{
  int l_slider = param.asInt();
  //Turn off in range 400-600
  if (l_slider < 600 && l_slider > 400)
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  //Move forward when > 600
  if (l_slider > 600)
  {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(pwm2, map(l_slider, 600, 1023, 0, 1023));
    Serial.println(map(l_slider, 600, 1023, 0, 1023));
  }
  //Move backwards when < 400
  if (l_slider < 400)
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(pwm2, map(l_slider, 400, 0, 0, 1023));    
    Serial.println(map(l_slider, 400, 0, 0, 1023));
  }  
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

void loop()
{
  Blynk.run();
}`
