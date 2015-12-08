int brightness = 0;    // brightness 變數用來保存目前的燈光亮度。
int fadeAmount = 5;    // fadeAmount 變數用來設定每一次燈光亮度的調整值。
void setup()  
{  
  pinMode(9, OUTPUT);  // 宣告 pin9 為 output pin, LED 接在 pin9 上。
}
void loop()  
{ 
  analogWrite(9, brightness);                // 使用 analogWrite(9, brightness) 設定 pin9 上的 LED 燈光亮度。  
  brightness = brightness + fadeAmount;      // 調整下一次的燈光亮度。  
  if (brightness == 0 || brightness == 255)  // 改變 fadeAmount 燈光亮度調整值，假如 brightness 已達到最亮(255)，就將 fadeAmount 改成 -5，讓燈光下一次的變化改成漸漸變暗，假如 brightness 已達到最暗(0)，就將 fadeAmount 改回 +5，讓燈光下一次的變化改成漸漸變亮。
  {
    fadeAmount = -fadeAmount ;
  }    
   delay(20);                               // 延遲 30ms，這樣肉眼才能看得到 LED 調光的效果。
}
/*
實驗目的：利用 PWM (Pulse Width Modulation, 脈衝寬度調變) 控制 LED 燈光亮度。 
材料：Arduino 主板 x 1、LED x 1、220 ohm 電阻 x 1及單心線 x N。
接線：LED 接到 pin9 和 GND，長腳(陽極)串接一顆 220 ohm 電阻到 pin9，短腳(陰極)直接接到 GND。
*/
