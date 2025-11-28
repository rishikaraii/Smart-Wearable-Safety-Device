#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int SW=10;         ////////////////sitch women
int SWalert=1;         // variable for reading the pushbutton status
//////////////////////////////////////////////////////////////////////////////
const int SW1=12;         ////////////////sitch GPS
int SWalert1=1;         // variable for reading the pushbutton status
//////////////////////////////////////////////////////////////////////////////
const int Touch=17;         ////////////////sitch touch
int Talert1=0;         // variable for reading the pushbutton status
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int i=0;
int  gps_status=0;
float latitude=0; 
float logitude=0;                       
String gpsString="";
char *test="$GPRMC";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BUZZ = 11; //Connect BUZZ  To Pin #11 ////////buzzer
int RLED = 14; //Connect LED  To Pin #14 ///////led
int GLED = 15; //Connect relay To Pin #15 ///////relay
int CAM = 13; //Connect BUZZ  To Pin #13 ////////CAM
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void initModule(String cmd, char *res, int t)
{
while(1)
{
Serial1.println(cmd);
delay(100);
while(Serial1.available()>0)
{
if(Serial1.find(res))
{
Serial1.println(res);
delay(t);
return;
}
else
{
Serial1.println("Error");
}
}
delay(t);
}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
lcd.begin(16, 2);
Serial1.begin(9600);
Serial2.begin(9600);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
pinMode(SW, INPUT);
pinMode(SW1, INPUT);
pinMode(Touch, INPUT);

pinMode(BUZZ, OUTPUT); 
pinMode(RLED, OUTPUT); 
pinMode(GLED, OUTPUT); 
pinMode(CAM, OUTPUT); 

digitalWrite(BUZZ,LOW);
digitalWrite(RLED,LOW);
digitalWrite(GLED,LOW);
digitalWrite(CAM,LOW);

lcd.clear();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.setCursor(0,0);lcd.print("  Design & and  "); 
lcd.setCursor(0,1);lcd.print("Implementation  ");delay(4000);lcd.clear();
lcd.setCursor(0,0);lcd.print("   of Smart     ");
lcd.setCursor(0,1);lcd.print("Security System ");delay(4000);lcd.clear();
lcd.setCursor(0,0);lcd.print("  for Women     ");
lcd.setCursor(0,1);lcd.print("Safety using    ");delay(4000);lcd.clear();
lcd.setCursor(0,0);lcd.print("  Internet of   ");
lcd.setCursor(0,1);lcd.print(" Things  (IoT)  ");delay(4000);lcd.clear(); 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.setCursor(0,0);lcd.print("Waiting For GPS");
lcd.setCursor(0,1);lcd.print(" Signal    ");
SWalert1 = digitalRead(SW1);
if (SWalert1 == LOW)
{
get_gps();show_coordinate();delay(2000);lcd.clear();
}
else
{
lcd.clear();
lcd.print("Lat:25.279771");
lcd.setCursor(0,1);
lcd.print("Log:74.621211");
delay(2000);
lcd.clear(); 
}
digitalWrite(BUZZ,LOW);delay(100); digitalWrite(GLED,HIGH);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.setCursor(0,0);lcd.print("GPS is OK");delay(1000);lcd.clear();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.setCursor(0,0);lcd.print("Initializing");
lcd.setCursor(0,1);lcd.print("GSM MODEM");delay(1000);
initModule("AT","OK",1000);
initModule("AT+CPIN?","READY",1000);
initModule("AT+CMGF=1","OK",1000);
digitalWrite(GLED,LOW);delay(100);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.setCursor(0,0);lcd.print("Initialized");
lcd.setCursor(0,1);lcd.print("Successfully");
delay(200);lcd.clear(); 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{st:
SWalert = digitalRead(SW);
if (SWalert == LOW)
{
lcd.setCursor(0,0);
lcd.print("  WOMEN  ");
lcd.setCursor(0,1);
lcd.print(" IN TROUBLE     ");
digitalWrite(BUZZ,HIGH);delay(100);
digitalWrite(RLED,HIGH);delay(100);
digitalWrite(GLED,LOW);delay(100);
digitalWrite(CAM,HIGH);delay(100);
delay(2000);lcd.clear();lcd.print("Sending SMS ");delay(2000);Send();delay(2000);
digitalWrite(CAM,LOW);delay(100);delay(100);digitalWrite(BUZZ,LOW);
initModule("AT","OK",1000);initModule("AT","OK",1000);
lcd.clear();lcd.print("CALLING------1 ");
Serial1.print("ATD+91");Serial1.print("9413526244"); Serial1.print(";\r\n");delay(12000);
Serial1.println("ATH");delay(2000);delay(2000);
initModule("AT","OK",1000);initModule("AT","OK",1000);lcd.clear();
lcd.clear();lcd.print("CALLING------2 ");
Serial1.print("ATD+91");Serial1.print("8955602345"); Serial1.print(";\r\n");delay(12000);
Serial1.println("ATH");delay(2000);
initModule("AT","OK",1000);initModule("AT","OK",1000);lcd.clear();
goto st;
}
else
{
lcd.setCursor(0,0);
lcd.print(" WOMEN  ");
lcd.setCursor(0,1);
lcd.print("  IS  SAFE      ");
digitalWrite(BUZZ,LOW);delay(100);
digitalWrite(RLED,LOW);delay(100);
digitalWrite(GLED,HIGH);delay(100);
}
/////////////////////////////////////////
Talert1 = digitalRead(Touch);
if (Talert1 == HIGH)
{
lcd.setCursor(0,0);
lcd.print("  WOMEN  ");
lcd.setCursor(0,1);
lcd.print(" IN TROUBLE     ");
digitalWrite(BUZZ,HIGH);delay(100);
digitalWrite(RLED,HIGH);delay(100);
digitalWrite(GLED,LOW);delay(100);
digitalWrite(CAM,HIGH);delay(100);
delay(2000);lcd.clear();lcd.print("Sending SMS ");delay(2000);Send();delay(2000);
digitalWrite(CAM,LOW);delay(100);delay(100);digitalWrite(BUZZ,LOW);
initModule("AT","OK",1000);initModule("AT","OK",1000);
lcd.clear();lcd.print("CALLING------1 ");
Serial1.print("ATD+91");Serial1.print("9413526244"); Serial1.print(";\r\n");delay(12000);
Serial1.println("ATH");delay(2000);delay(2000);
initModule("AT","OK",1000);initModule("AT","OK",1000);lcd.clear();
lcd.clear();lcd.print("CALLING------2 ");
Serial1.print("ATD+91");Serial1.print("8955602345"); Serial1.print(";\r\n");delay(12000);
Serial1.println("ATH");delay(2000);delay(2000);
initModule("AT","OK",1000);initModule("AT","OK",1000);lcd.clear();
goto st;
}
else
{
lcd.setCursor(0,0);
lcd.print(" WOMEN  ");
lcd.setCursor(0,1);
lcd.print("  IS  SAFE      ");
digitalWrite(BUZZ,LOW);delay(100);
digitalWrite(RLED,LOW);delay(100);
digitalWrite(GLED,HIGH);delay(100);
}
/////////////////////////////////////////////////////////////////////////////////////////
}

//////////////////////////////////////////////////////////////////////////////////////////
void gpsEvent()
{
gpsString="";
while(1)
{
while (Serial2.available()>0)  //Serial incoming data from GPS
{
char inChar = (char)Serial2.read();
gpsString+= inChar;  //store incoming data from GPS to temparary string str[]
i++;
if (i < 7)                      
{
if(gpsString[i-1] != test[i-1])  //check for right string
{
i=0;
gpsString="";
}
}
if(inChar=='\r')
{
if(i>65)
{
gps_status=1;
break;
}
else
{
i=0;
}
}
}
if(gps_status)
break;
}
}
///////////////////////////////////////////////////////////////////
void get_gps()
{
lcd.clear();
lcd.print("Getting GPS Data");
lcd.setCursor(0,1);
lcd.print("Please Wait.....");
gps_status=0;
int x=0;
while(gps_status==0)
{
gpsEvent();
int str_lenth=i;
coordinate2dec();
i=0;x=0;
str_lenth=0;
}
}
////////////////////////////////////////////////////////////////////////////
void show_coordinate()
{
lcd.clear();
lcd.print("Lat:");
lcd.print(latitude);
lcd.setCursor(0,1);
lcd.print("Log:");
lcd.print(logitude);
delay(2000);
lcd.clear();
}
///////////////////////////////////////////////////////////////////////////////////////////
//$GPRMC,053508.00,A,1725.64574,N,07835.11697,E,0.041,,121217,,,D*79
void coordinate2dec()
{
String lat_degree="";
for(i=19;i<=20;i++)         
lat_degree+=gpsString[i];
String lat_minut="";
for(i=21;i<=27;i++)         
lat_minut+=gpsString[i];
String log_degree="";
for(i=32;i<=34;i++)
log_degree+=gpsString[i];
String log_minut="";
for(i=35;i<=41;i++)
log_minut+=gpsString[i];
float minut= lat_minut.toFloat();
minut=minut/60;
float degree=lat_degree.toFloat();
latitude=degree+minut;
minut= log_minut.toFloat();
minut=minut/60;
degree=log_degree.toFloat();
logitude=degree+minut;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void init_sms1()
{Serial1.println("AT+CMGF=1");delay(400);Serial1.println("AT+CMGS=\"9413526244\""); delay(400);}
void init_sms2()
{Serial1.println("AT+CMGF=1");delay(400);Serial1.println("AT+CMGS=\"8955602345\""); delay(400);}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void send_data(String message)
{ Serial1.print(message);delay(200);}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void lcd_status()
{lcd.clear();lcd.print("Message Sent");  delay(3000); lcd.clear(); return;}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Send_sms()
{
lcd.clear();lcd.print("Sending SMS  "); 
Serial1.println("I am in Trouble");delay(500);
Serial1.println("Plz Help me");delay(500);
Serial1.println("Plz Rescue ");
SWalert1 = digitalRead(SW1);
if (SWalert1 == LOW)
{
get_gps();show_coordinate();delay(500);lcd.clear();
Serial1.print("https://www.google.com/maps/place/");
Serial1.print(latitude,6);Serial1.print(",");Serial1.print(logitude,6);Serial1.write(26);delay(2000);
}
else
{
Serial1.print("https://www.google.com/maps/place/25.279771,74.621211");
delay(500);Serial1.write(26);delay(2000);
}
delay(2000);lcd.clear();lcd.print("Message Sent ");  delay(1000); lcd.clear();
Serial1.print("AT\r\n");delay(500);Serial1.print("AT\r\n");delay(500);Serial1.println("AT+CMGF=1");delay(200);lcd.clear();
lcd_status();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Send()
{ 
init_sms1();delay(1000);lcd.clear();lcd.print("Sending SMS1  ");Send_sms();
init_sms2();delay(1000);lcd.clear();lcd.print("Sending SMS2  ");Send_sms();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
