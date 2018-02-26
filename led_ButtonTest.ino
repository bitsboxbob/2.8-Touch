/* An example program for the 2.8" SPI TFT Touch Display.
Configured for the Uno using 1k/1k voltage dividers on display and touch
input pins.
*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <URTouch.h>

#define TFT_RST 8
#define TFT_DC 9
#define TFT_CS 10
#define TOUCH_ORIENTATION  LANDSCAPE

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

Adafruit_GFX_Button buttons[9];

// Initialize touchscreen
// Pins using T_Clk,T_CS, T_Din, T_DO, T_IRQ 
URTouch  myTouch( 7, 6, 5, 4, 3);

// Declare which fonts we will be using
extern uint8_t BigFont[];

int x, y;
char ON[3] = {"ON"};
char OFF[4] = {"OFF"};

//led output pin constant
const int led = 2;

void waitfortouch(unsigned short int *x,unsigned short int *y){
  do
  {    
    delay(10);
    if (myTouch.dataAvailable() == true)
    {
      myTouch.read();
      *x = myTouch.getX();  //Get touch point  
      *y = myTouch.getY();
      return;
      }
  }while(myTouch.dataAvailable()==false); 
}

void setup()
{
// Initial setup
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(30,30);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
  tft.print("Bitsbox");
  tft.setCursor(30,100);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(3);
  tft.print("2.8 TFT Test");

  digitalWrite(led, HIGH);

// create the buttons // x, y, w, h, outline, fill, text
  buttons[0].initButton(&tft, 100,200,80,40,ILI9341_WHITE, ILI9341_RED, ILI9341_WHITE,
                      ON, 2); 
          buttons[0].drawButton();
  buttons[1].initButton(&tft, 200,200,80,40,ILI9341_WHITE, ILI9341_RED, ILI9341_WHITE,
                      OFF, 2); 
          buttons[1].drawButton();  
}

void loop()
{
    waitfortouch(&x,&y);  //Wait for a screen touch and receive co-ordinates in x & y
    
   // Serial.print(x); Serial.print(","); Serial.println(y); //for debugging show x & y received
   
    if (buttons[0].contains(x,y)) //switch LED dependent on which button is pressed.
    {
      digitalWrite(led, HIGH);
    }
    if (buttons[1].contains(x,y))
    {
      digitalWrite(led, LOW);
    }
}

