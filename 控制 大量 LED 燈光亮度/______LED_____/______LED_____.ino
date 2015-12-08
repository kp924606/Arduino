int brightness[13],fadeAmount[13] ,i;    // brightness 變數用來保存目前的燈光亮度、fadeAmount 變數用來設定每一次燈光亮度的調整值。
void setup()  
{    
  for(i=1;i<=13;i++)
  {
   pinMode(i, OUTPUT);  // 宣告 pini 為 output pin, LED 接在 pini 上。
   fadeAmount[i]=i;
   brightness[i]=0;
  }
}
void loop()  
{ 
  for(i=1;i<=13;i++) // 注意要使用PWM需要看此PORT是否有支援，只需觀察腳位的號碼前是否有~。
  {   
   analogWrite(i,brightness[i]);                // 使用 analogWrite(i, brightness) 設定 pini 上的 LED 燈光亮度。 
   brightness[i]+=fadeAmount[i];                // 調整下一次的燈光亮度。
   if (brightness[i] <= 0 || brightness[i] >= 255)  // 改變 fadeAmount 燈光亮度調整值，假如 brightness 已達到最亮(255)，就將 fadeAmount 改成 -5，讓燈光下一次的變化改成漸漸變暗，假如 brightness 已達到最暗(0)，就將 fadeAmount 改回 +5，讓燈光下一次的變化改成漸漸變亮。
    fadeAmount[i] = -fadeAmount[i];  
  }   
  delay(30);                               // 延遲 30ms，這樣肉眼才能看得到 LED 調光的效果。  
}
/*
實驗目的：利用 PWM (Pulse Width Modulation, 脈衝寬度調變) 控制 LED 燈光亮度。 
材料：Arduino 主板 x 1、LED x 1、220 ohm 電阻 x 1及單心線 x N。
接線：LED 接到 pin9 和 GND，長腳(陽極)串接一顆 220 ohm 電阻到 pini，短腳(陰極)直接接到 GND。
*/
