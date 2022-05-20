#include <SoftwareSerial.h>
//////////////////////////////////DECELARATION OF VARIABLES//////////////////////////////////////////
SoftwareSerial portOne(10, 11);// RX, TX
SoftwareSerial portTwo(9, 8);//RX,TX
 char gps[167];
char first;
int t;
int i;

char gps1[630];
char first1;
int t1;
int i1;
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  7;      // the number of the LED pin
const int ledPin1 =  13;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status



///////////////////////////////////////SETUP LOOP//////////////////////////////////////////////
void setup() {
   // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
   pinMode(ledPin1, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(4800);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("STEEL CODE");

  // set the data rate for the SoftwareSerial port
  portTwo.begin(9600);
  portOne.begin(57600);
  


  
}


///////////////////////////////////////FOR BAUDRATE 9600//////////////////////////////////////////////
void baudrate9600()
{
 // print the string when a newline arrives:
   portTwo.begin(9600);//9,8
    buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)
  {
   return;
   
  }
  while( portTwo.available() )
  {
    buttonState = digitalRead(buttonPin);
     if (buttonState == LOW)
  {
   return;
   
  }
 
    char first =   portTwo.read();
    if(first=='$')
    {
      
     gps1[0]= first;
     i=1;
     if(gps1[i]!='$')
     {
     
     while (i<630)
     {
       buttonState = digitalRead(buttonPin);
      if (buttonState == LOW)
  {
   return;
   
  }
       if (  portTwo.available())
       {
       buttonState = digitalRead(buttonPin);
        if (buttonState == LOW)
  {
   return;
   
  }
         gps1[i]=  portTwo.read();
         t=i++;
        
        }
       
     }
     }
    for (i = 0; i <t; i++) {
       buttonState = digitalRead(buttonPin);
      if (buttonState == LOW)
  {
   return;
   
  }
      Serial.print(gps1[i]);
      
    }
    if (buttonState == LOW)
  {
   return;
   
  }
    Serial.println();
   }
   if (buttonState == LOW)
  {
   return;
   
  }
  if (buttonState == LOW)
  {
   return;
   
  }
 }
 if (buttonState == LOW)
  {
   return;
   
  }
}



//////////////////////////FOR BAUDRATE 57600////////////////////////////////////////////

void baudrate57600()
{
  portOne.begin(57600);//10,11
 // print the string when a newline arrives:
 
    buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
   return;
   
  }
  while(portOne.available() )
  {
    buttonState = digitalRead(buttonPin);
     if (buttonState == HIGH)
  {
   return;
   
  }
 
    char first = portOne.read();
    if(first=='$')
    {
      
     gps[0]= first;
    i=1;
     if(gps[i]!='$')
     {
     
     while (i<167)
     {
       buttonState = digitalRead(buttonPin);
      if (buttonState == HIGH)
  {
   return;
   
  }
       if (portOne.available())
       {
       buttonState = digitalRead(buttonPin);
        if (buttonState == HIGH)
  {
   return;
   
  }
         gps[i]=portOne.read();
         t=i++;
        
        }
       
     }
     }
    for (i = 0; i <t; i++) {
       buttonState = digitalRead(buttonPin);
      if (buttonState == HIGH)
  {
   return;
   
  }
  
      Serial.print(gps[i]);
      
    }
    if (buttonState == HIGH)
  {
   return;
   
  }
    Serial.println();
   }
   if (buttonState == HIGH)
  {
   return;
   
  }
  if (buttonState == HIGH)
  {
   return;
   
  }
 }
 if (buttonState == HIGH)
  {
   return;
   
  }
}




///////////////////////MAIN LOOP///////////////////////////////////////////////////////
void loop() 
{
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH)
  {
   
    digitalWrite(ledPin, HIGH);//green led on
    digitalWrite(ledPin1, LOW);//red led off
  baudrate9600();
  }
  else if (buttonState == LOW)
  {
    buttonState = digitalRead(buttonPin);// pin 10 rx for rukumani

    digitalWrite(ledPin, LOW);// green off
    digitalWrite(ledPin1, HIGH);//red on
    baudrate57600();
  }
  }

