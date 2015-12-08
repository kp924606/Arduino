int photocellPin = 2;   // 光敏電阻 (photocell) 接在 anallog pin 2。
int photocellVal = 0;   // photocell variable。
int minLight = 200;     // 最小光線門檻值。
int ledPin = 9;
int ledState = 0; 
void setup()
{
  pinMode(ledPin, OUTPUT);                      // 宣告 ledPin 為 output pin。
  Serial.begin(9600);                            // 裝置發到另一裝置的位元率。
}
void loop() 
{
  photocellVal = analogRead(photocellPin);      // 讀取光敏電阻並輸出到 Serial Port。
  Serial.println(photocellVal);                  // 傳送資料到外部電腦。
  if (photocellVal < minLight && ledState == 0) // 光線不足時打開 LED。
  {
    digitalWrite(ledPin, HIGH);                 //開啟 LED。
    ledState = 1;
  }   
  if (photocellVal > minLight && ledState == 1) // 光線充足時關掉 LED。
  {
    digitalWrite(ledPin, LOW);                  // 關閉 LED。
    ledState = 0;
  }   
  //delay(100);       
}
/*
實驗目的：利用光敏電阻做一個 LED 的自動開關，在光線不足時，自動打開 LED 燈，反之，光線充足時便關掉 LED 燈。
材料：Arduino 主板 x 1、LED x 1、光敏電阻(photocell) x 1、麵包板 x 1、可變電阻 x 1、220 ohm 電阻 x 1、10k ohm 電阻 x 1及單心線 x N。
接線：1.光敏電阻一支腳接到 5V，另一支腳串接一顆 10k 電阻接到 analog pin 2。
      2.LED 接到 pin9 和 GND，長腳(陽極)串接一顆 220 ohm 電阻到 pin9，短腳(陰極)直接接到 GND。
*/
