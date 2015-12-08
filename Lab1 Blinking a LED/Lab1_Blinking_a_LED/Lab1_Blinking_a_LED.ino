void setup() 
{  
 pinMode(13, OUTPUT);// 把 pin13 設置成 output pin。
}
void loop() 
{
  digitalWrite(13, HIGH);   // 供應 5V 電壓到 pin13，藉此打開 LED 燈號。
  delay(1000);              // 讓 CPU 閒置一秒鐘，讓 LED 燈號亮著一秒鐘。
  digitalWrite(13, LOW);    // 關閉燈號。
  delay(1000);              // 讓 CPU 閒置一秒鐘，讓 LED 燈號關閉一秒鐘。
}
/*
實驗目的：讓一顆燈號閃爍，每隔一秒切換一次燈號。 
材料：Arduino 主板 x 1、LED x 1。
接線：把 LED 接到 Arduino 板子上，LED 長腳(陽極)接到 pin13，短腳(陰極)接到 GND。
*/
