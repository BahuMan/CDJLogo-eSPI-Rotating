#include <Arduino.h>
// Define the width and height according to the TFT and the
// available memory. The sprites will require:
//     DWIDTH * DHEIGHT * 2 bytes of RAM
// Note: for a 240 * 320 area this is 150 Kbytes!
#define DWIDTH  240
#define DHEIGHT 240

#include <TFT_eSPI.h>
TFT_eSPI    tft = TFT_eSPI();
TFT_eSprite CDJspr = TFT_eSprite(&tft);
TFT_eSprite Fri3dspr = TFT_eSprite(&tft);

void drawCoderDojo();
void drawFri3dCamp();

void setup() {
  Serial.begin(115200);

  tft.init();
  tft.initDMA();
  tft.fillScreen(TFT_YELLOW);

  CDJspr.setColorDepth(1);
  CDJspr.createSprite(DWIDTH, DHEIGHT);
  Fri3dspr.setColorDepth(8);
  Fri3dspr.createSprite(DWIDTH, DHEIGHT);
  /*
  CDJspr.setTextDatum(MC_DATUM);
  CDJspr.setViewport(0, 0, DWIDTH, DHEIGHT);
  Fri3dspr.setTextDatum(MC_DATUM);
  Fri3dspr.setViewport(0, 0, DWIDTH, DHEIGHT);
  */

  drawCoderDojo();
  drawFri3dCamp();
}
uint16_t angle = 0;

void loop() {
  Serial.println("showing CoderDojo");
  //CDJspr.pushSprite(0, 0);
  tft.setPivot(120, 120);
  CDJspr.pushRotated(angle);
  angle = (angle+5) % 360;
  //delay(10);
  //Serial.println("showing Fri3d");
  //Fri3dspr.pushSprite(0, 0);
  //delay(500);
}

//construct CoderDojo sprite using primitives
//once constructed, we can draw ("push") this sprite multiple times
void drawCoderDojo()
{
  CDJspr.fillSprite(TFT_BLACK);
  CDJspr.setRotation(1);
  CDJspr.fillCircleHelper(119, 119, 100, 2, 0, TFT_BLACK);
  CDJspr.fillCircleHelper(119, 119, 100, 1, 0, TFT_WHITE);
  CDJspr.setRotation(0);
  CDJspr.fillCircle(119, 69, 50, TFT_WHITE);
  CDJspr.fillCircle(119, 169, 50, TFT_BLACK);
  
  CDJspr.setTextSize(4);
  CDJspr.setTextColor(TFT_BLACK);
  CDJspr.setCursor(119-12, 69-16);
  CDJspr.print(0);

  CDJspr.setTextColor(TFT_WHITE);
  CDJspr.setCursor(119-12, 169-16);
  CDJspr.print(1);
}

//construct the Fri3d Logo sprite using lines
void drawFri3dCamp()
{
  Fri3dspr.fillSprite(TFT_BLACK);

  //green lines, tripled for extra thickness:
  Fri3dspr.drawLine(118, 239, 0, 120, TFT_GREEN);
  Fri3dspr.drawLine(119, 239, 0, 119, TFT_GREEN);
  Fri3dspr.drawLine(120, 239, 0, 118, TFT_GREEN);

  Fri3dspr.drawLine(0, 118, 218, 0, TFT_GREEN);
  Fri3dspr.drawLine(0, 119, 219, 0, TFT_GREEN);
  Fri3dspr.drawLine(0, 120, 220, 0, TFT_GREEN);

  Fri3dspr.drawLine(218, 0, 118, 239, TFT_GREEN);
  Fri3dspr.drawLine(219, 0, 119, 239, TFT_GREEN);
  Fri3dspr.drawLine(220, 0, 120, 239, TFT_GREEN);

  //blue lines, tripled for extra thickness:
  Fri3dspr.drawLine(118, 239, 239, 118, TFT_BLUE);
  Fri3dspr.drawLine(119, 239, 239, 119, TFT_BLUE);
  Fri3dspr.drawLine(120, 239, 239, 120, TFT_BLUE);

  Fri3dspr.drawLine(239, 120, 18, 0, TFT_BLUE);
  Fri3dspr.drawLine(239, 119, 19, 0, TFT_BLUE);
  Fri3dspr.drawLine(239, 118, 20, 0, TFT_BLUE);

  Fri3dspr.drawLine(18, 0, 118, 239, TFT_BLUE);
  Fri3dspr.drawLine(19, 0, 119, 239, TFT_BLUE);
  Fri3dspr.drawLine(20, 0, 120, 239, TFT_BLUE);
}
