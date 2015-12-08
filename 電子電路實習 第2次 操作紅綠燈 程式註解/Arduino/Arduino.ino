int led[7]={0,1,2,3,4,5,6},i;  // 定義一字元型態的變數，名稱為 led，並含有陣列元素為 led[0]~led[6]，腳位的設定。
void setup() {                 // 程式一開始的設置，只運行一次，可用來做初始值設定。
  for(i=1;i<=6;i++)            // 運用迴圈依序的將腳位設為輸出。
   pinMode(led[i],OUTPUT);     // pinMode將配置指定腳位的行為設為輸入或輸出。 
}
void loop() {                  // 無限循環的迴圈，void 為表示該功能預計將沒有訊息返回到它被調用的函數。
  digitalWrite(led[1],HIGH);   // n red，1。
  digitalWrite(led[6],HIGH);   // e green，1。
  delay(3000);                 // 延遲，單位為 milliseconds。語法：delay(ms)。
  //---
  for(i=500;i>=200;i-=100)     // 閃爍速度加快，運用迴圈設定時間量的變數。
  {
  digitalWrite(led[6],LOW);    //  e green，0。
  delay(i);                    // 延遲，單位為 milliseconds。
  digitalWrite(led[6],HIGH);   //  e green，1。
  delay(i);
  }
  digitalWrite(led[6],LOW);    //  e gree 
  //-------------   
  digitalWrite(led[5],HIGH);   // e yellow
  delay(2000);  // 300.200  
  for(i=500;i<=2000;i+=500)    // 閃爍固定時間，運用迴圈設定執行的次數。
  {
  digitalWrite(led[5],LOW);  //  e green
  delay(250);
  digitalWrite(led[5],HIGH); //  e green
  delay(250);
  }  
  
  digitalWrite(led[5],LOW);  // e yellow 
  digitalWrite(led[1],LOW);   // n red  
  digitalWrite(led[3],HIGH);  // n green
  digitalWrite(led[4],HIGH);  // e red
  delay(3000);
  //--
  for(i=500;i>=200;i-=100)
  {
  digitalWrite(led[3],LOW);  //  n green
  delay(i);
  digitalWrite(led[3],HIGH); //  n green
  delay(i);
  }
  digitalWrite(led[3],LOW);  //  n gree
  //--
  digitalWrite(led[5],LOW);   //  e yellow 
  
  digitalWrite(led[3],LOW);  // n green
  digitalWrite(led[2],HIGH);  // n yellow
  delay(2000);
   for(i=500;i<=2000;i+=500)
  {
  digitalWrite(led[2],LOW);  //  n yellow
  delay(250);
  digitalWrite(led[2],HIGH); //  n yellow
  delay(250);
  }  
  
  digitalWrite(led[2],LOW);  // n yellow
  digitalWrite(led[4],LOW);  // n red  
}
