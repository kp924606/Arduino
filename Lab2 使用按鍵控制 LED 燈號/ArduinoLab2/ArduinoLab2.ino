const int buttonPin = 2;     // 定義按鍵與 LED 的腳位，按鍵接在 pin2, 而 LED 接在 pin13。
const int ledPin =  13;
int buttonState = 0;         // 讀取按鍵的狀態並保存到 buttonState 變數裏。
void setup() 
{
  pinMode(ledPin, OUTPUT);   // 宣告 ledPin 為 output pin。
  pinMode(buttonPin, INPUT); 
}
void loop()
{
 buttonState = digitalRead(buttonPin);   // 讀取 buttonPin腳位數值，無論是高還是低。
 if (buttonState == HIGH)                // 按下按鍵時要打開 LED 燈號，放開按鍵時要關閉 LED 燈號，因此，假如 buttonState 為 HIGH，代表按鍵狀態是按下(pressed)的，此時要打開 LED，反之，假如 buttonState 為 LOW，代表按鍵狀態是放開的，此時要關閉 LED。
  digitalWrite(ledPin, HIGH);            // 開燈。
 else                                    // 只需改變 HIGH或 LOW就可將開燈及關燈邏輯反轉。
  digitalWrite(ledPin, LOW);             // 關燈。
}
/*
實驗目的：使用按鍵 (PushButton)控制 LED 燈號的開關，當按鍵被按下時打開 LED 燈號，按鍵放開時關閉 LED 燈號。  
材料：Arduino 主板 x 1、LED x 1、PushButton 或 Switch 開關 x 1、10K 電阻 x 1、麵包板 x 1及單心線 x N。
接線：1.把 LED 接到 pin13，長腳(陽極)接到 pin13，短腳(陰極)接到 GND。
      2.PushButton 一支腳接到 +5V。
      3.pin2 接到 Pushbutton 的另一支腳，同一支腳位接一個 10K 電阻連到 GND。
*/
