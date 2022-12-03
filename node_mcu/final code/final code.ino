#include<ESP8266WiFi.h>
#include<stdio.h>
#include <WiFiClientSecure.h>
#include<ESP8266HTTPClient.h>
WiFiClientSecure client;
HTTPClient http;
String url="https://carpsapi-production.up.railway.app/updatedb/";
int stepvalue[6];
/*int stepvalue2;
int stepvalue3;
int stepvalue4;
int stepvalue5;
int stepvalue6;*/
//String API="2W8MHCZL117QTVRX";
//String FieldNo="1";
void ConnectTOWifi(void);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
ConnectTOWifi();
pinMode(D0,INPUT);
pinMode(D1,INPUT);
pinMode(D2,INPUT);
pinMode(D3,INPUT);
pinMode(D4,INPUT);
pinMode(D5,INPUT);

}
int httpcode;
void loop() {
  // put your main code here, to run repeatedly:
 stepvalue[0]=digitalRead(D0);
 stepvalue[1]=digitalRead(D1);
 stepvalue[2]=digitalRead(D2);
 stepvalue[3]=digitalRead(D3);
 stepvalue[4]=digitalRead(D4);
 stepvalue[5]=digitalRead(D5)-- ;
SendGETRequest();
}
void SendGETRequest(){
     client.setInsecure();
     int i=0;
     for(i=0;i<5;i++){
       String url1=url+"A"+(i+1)+"/";
     if(stepvalue[i]==0){
  http.begin(client,url1+"1");  //Specify request destination
  http.GET(); }
  else{
   http.begin(client,url1+"0");  //Specify request destination
  http.GET(); }
          
  Serial.println(stepvalue[i]);
     }
}
void ConnectTOWifi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin("DESKTOP-K27DURC 2587","vaheed123");
  Serial.print("connecting to wifi");
  while(WiFi.status()!=WL_CONNECTED){
 delay(100);
  } 
}
