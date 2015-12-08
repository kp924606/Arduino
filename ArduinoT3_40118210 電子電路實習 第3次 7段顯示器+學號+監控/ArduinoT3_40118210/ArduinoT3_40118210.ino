int number[11][8]={{0,0,0,0,0,0,1,1},   // 0
                   {1,0,0,1,1,1,1,1},   // 1
                   {0,0,1,0,0,1,0,1},   // 2
                   {0,0,0,0,1,1,0,1},   // 3
                   {1,0,0,1,1,0,0,1},   // 4
                   {0,1,0,0,1,0,0,1},   // 5
                   {0,1,0,0,0,0,0,1},   // 6
                   {0,0,0,1,1,1,1,1},   // 7
                   {0,0,0,0,0,0,0,1},   // 8
                   {0,0,0,1,1,0,0,1},   // 9
                   {1,1,1,1,1,1,1,0}};  // cp
                 // a.b.c.d.e.f.g.cp     共陽極共同端接 +，輸出接地（亮）。
int potPin=3,t;                    // 宣告可變電阻所用的類比輸入腳位port3、t 為延遲時間。
void setup() {                     // 程式一開始的設置，只運行一次，可用來做初始值設定。
 for(int i=4;i<=11;i++)            // 從port4開始，直到第port11，一共8個port並設置成 output pin。
   pinMode(i,OUTPUT);
  Serial.begin(9600);               // 裝置發到另一裝置的位元率。
}
void loop() {                      // 無限循環的迴圈，void 為表示該功能預計將沒有訊息返回到它被調用的函數。
 show2();                          // 一開始先關閉燈號，把不該亮的都關掉。
 int id[9]={4,0,1,1,8,2,1,0,10};   // 顯示學號及小數點共有9個燈號。
 for(int i=0;i<=8;i++)             // 依序顯示燈號共9個。
 {
  show(id[i]);            // 依序顯示燈號，每顯示一號碼便延遲一段時間之後關燈。  
  show2();                // 關閉燈號。  
 } 
}
void show(int n)// 顯示燈號，n為對應的號碼陣列縱向。
{  
 int star=4,sensorValue = analogRead(potPin);  // star為port開始的順序此從開始、star為port開始的順序此從開始、讀取可變電阻讀值並且放到 sensorValue 變數裏。 
 for(int i=0;i<=7;i++,star++)                  // i為二陣列橫向的順序同時也是顯示的個數。
 {
  digitalWrite(star,number[n][i]);             // 將對應的號碼依照七段顯示器腳位的亮或滅做顯示。
 } 
 t=analogRead(potPin);                         // 讀取類比port3的可變電阻讀值並且放到 t 變數裡。
 Serial.println(sensorValue);                   // 讀取光敏電阻並輸出到 sensorValuet，監控。 
 delay(t+100);                                 // 讓可變電阻也能控制亮的時間，延遲時間 t有可能為 0，所以必須要有最低底線才有延遲效果出現。
}
void show2()// 關閉燈。
{ 
 int sensorValue = analogRead(potPin);         // star為port開始的順序此從開始、讀取可變電阻讀值並且放到 sensorValue 變數裏。 
 for(int i=4;i<=11;i++)                        // 7段顯示器共8個LED燈腳位，從port 4開始。
 {
  digitalWrite(i,HIGH);                        // 共陽極共同端接正，不同的接正極接地便無電位差此時為滅。
 } 
 t=analogRead(potPin);                         // 讀取類比port3的可變電阻讀值並且放到 t 變數裡。
 Serial.println(sensorValue);                   // 讀取光敏電阻並輸出到 sensorValuet，監控。 
 delay(t+100);                                 // 讓可變電阻也能控制亮的時間，延遲時間 t有可能為 0，所以必須要有最低底線才有延遲效果出現。
}
