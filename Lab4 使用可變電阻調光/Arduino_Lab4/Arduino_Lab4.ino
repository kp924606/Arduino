int potPin = 3;                         // 宣告可變電阻所用的類比輸入腳位。
int ledPin = 9;                         // 宣告 LED 燈號腳位。
void setup() {
  Serial.begin(9600);                    // 設定 SerialPort 的傳輸速率，鮑率為 9600 bps (bit per second)。  
}
void loop() {
  int sensorValue = analogRead(potPin); // 讀取可變電阻讀值並且放到 sensorValue 變數裏。
  Serial.println(sensorValue, DEC);      // 使用 Serial.println(sensorValue, DEC) 把電阻值列印到 SerialPort。DEC 代表以十進位顯示數字。  
  sensorValue = sensorValue/4;          // analogRead() 讀進來的是一個 10 位元的數值，值域為 0 到 1023，由於 analogWrite() 的參數只能接受 0 到 255 的數值，所以得將 sensorValue 除以 4，讓 sensorValue 的數值從 0-1023 等比例縮小到 0-255 的範圍。
  analogWrite(ledPin, sensorValue);
  delay(150);                           // 讓 CPU 閒置150ms。
}
/*
實驗目的：使用可變電阻 (potentiometer) 控制 LED 的燈光亮度，達到調光的目的。 
材料：Arduino 主板 x 1、LED x 1、220 ohm 電阻 x 10、麵包板 x 1、可變電阻 x 1及單心線 x N。
接線：1.LED 接到 pin9 和 GND，長腳(陽極)串接一顆 220 ohm 電阻到 pin9，短腳(陰極)直接接到 GND。
      2.可變電阻中間腳位接到類比輸入(Analog Input) pin3，剩下的兩支腳位，一支接到 5V，另外一支接到 GND。
*/
