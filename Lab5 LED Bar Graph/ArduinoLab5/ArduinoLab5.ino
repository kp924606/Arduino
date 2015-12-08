const int ledCount = 10;    // LED的數量。
int ledPins[] = { 2, 3, 4, 5, 6, 7,8,9,10,11 };             // 宣告 ledPins 陣列並定義 LED bar 或 10 顆 LED 所在的腳位，在此使用 pin2 到 pin11 這 10 支腳位
void setup() 
{
 for (int thisLed = 0; thisLed < ledCount; thisLed++)
  pinMode(ledPins[thisLed], OUTPUT);                        // 宣告 ledPins[thisLed] 為 output pin。
}
void loop() 
{
  for (int thisLed = 0; thisLed < ledCount; thisLed++)      // 讓 LED 產生掃瞄的效果，先由右往左。
  {
   digitalWrite(ledPins[thisLed], HIGH);                    // 供應 5V 電壓到 ledPins[thisLed]，藉此打開 LED 燈號。
   delay(60);                                               // 讓 CPU 閒置60ms，讓 LED 燈號亮著60ms。
   digitalWrite(ledPins[thisLed], LOW);                     // 關閉燈號。
  }
  for (int thisLed = ledCount -1 ; thisLed >= 0; thisLed--) // 繼續讓 LED 產生掃瞄的效果，這次換成由左往右。跑完一輪後(先由右往左，再由左往右，這樣算一輪)，不關閉第一顆 LED 燈號，讓第一顆 LED 暫停一下
  {
   digitalWrite(ledPins[thisLed], HIGH);                    // 供應 5V 電壓到 ledPins[thisLed]，藉此打開 LED 燈號。
   delay(60);                                               // 讓 CPU 閒置60ms，讓 LED 燈號亮著60ms。
   if (thisLed == 0)
    delay(200);                                             // 跑完一輪後，讓第一顆 LED 亮著暫停一下。
   else
     digitalWrite(ledPins[thisLed], LOW);                   // 關閉燈號。
  }
}
/*
實驗目的：控制 LED 燈排 (LED Bar Graph)，製作出類似「霹靂遊俠」影集中「夥計」車頭 LED 燈排的掃瞄效果。  
材料：Arduino 主板 x 1、LED bar garph x 1 或是 LED x 10、220 ohm 電阻 x 10、麵包板 x 1及單心線 x N。
接線：把 LED bar graph 或 10 顆 LED 接到 pin2 到 pin11 腳 。LED 的接法為: 長腳(陽極)接到 pin 腳，短腳(陰極)串接一顆 220 ohm 電阻接到 GND。
*/
