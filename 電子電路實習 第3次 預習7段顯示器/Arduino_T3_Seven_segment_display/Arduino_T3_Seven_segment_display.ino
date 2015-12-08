int a=7;  // 0~9~.
int b=6; 
int c=5; 
int d=11; 
int e=10; 
int f=8; 
int g=9; 
int dp=4; 
void digital_1(void) //顯示數位1 
{ 
 int j; 
 digitalWrite(c,LOW);         //給數字 5 引腳低電平，點亮 c 段。 
 digitalWrite(b,LOW);         //點亮 b 段。 
 for(j=7;j<=11;j++)           //熄滅其餘段。 
 digitalWrite(j,HIGH); 
 digitalWrite(dp,HIGH);       //熄滅小數點 DP段。 
} 
void digital_2(void) //顯示數位2 
{ 
 unsigned char j; 
 digitalWrite(b,LOW); 
 digitalWrite(a,LOW); 
 for(j=9;j<=11;j++) 
 digitalWrite(j,LOW); 
 digitalWrite(dp,HIGH); 
 digitalWrite(c,HIGH); 
 digitalWrite(f,HIGH); 
} 
void digital_3(void) //顯示數位3 
{ 
 unsigned char j; 
 digitalWrite(g,LOW); 
 digitalWrite(d,LOW); 
 for(j=5;j<=7;j++) 
 digitalWrite(j,LOW); 
 digitalWrite(dp,HIGH); 
 digitalWrite(f,HIGH); 
 digitalWrite(e,HIGH); 
} 
void digital_4(void) //顯示數位4 
{ 
 digitalWrite(c,LOW);
 digitalWrite(b,LOW); 
 digitalWrite(f,LOW); 
 digitalWrite(g,LOW); 
 digitalWrite(dp,HIGH); 
 digitalWrite(a,HIGH); 
 digitalWrite(e,HIGH); 
 digitalWrite(d,HIGH); 
} 
void digital_5(void) //顯示數位5 
{ 
 unsigned char j; 
 for(j=7;j<=9;j++) 
 digitalWrite(j,LOW); 
 digitalWrite(c,LOW); 
 digitalWrite(d,LOW); 
 digitalWrite(dp,HIGH); 
 digitalWrite(b,HIGH); 
 digitalWrite(e,HIGH); 
} 
void digital_6(void) //顯示數位6 
{ 
 unsigned char j; 
 for(j=7;j<=11;j++) 
 digitalWrite(j,LOW); 
 digitalWrite(c,LOW); 
 digitalWrite(dp,HIGH); 
 digitalWrite(b,HIGH); 
} 
void digital_7(void) //顯示數位7 
{ 
 unsigned char j; 
 for(j=5;j<=7;j++) 
 digitalWrite(j,LOW); 
 digitalWrite(dp,HIGH); 
 for(j=8;j<=11;j++) 
 digitalWrite(j,HIGH); 
}
void digital_8(void)  //顯示數位8 
{ 
 unsigned char j; 
 for(j=5;j<=11;j++) 
 digitalWrite(j,LOW);
 digitalWrite(dp,HIGH); 
} 
void digital_9(void) //顯示數位 9
{ 
  unsigned char j;
  for(j=10;j<=11;j++) 
  digitalWrite(j,HIGH); 
}
void digital_point(void) //顯示數位 .
{ 
  unsigned char j;
  for(j=5;j<=9;j++) 
  digitalWrite(j,HIGH); 
 digitalWrite(4,LOW); 
}
void digital_0(void) //顯示數位 0
{ 
 digitalWrite(g,HIGH);  // g腳熄滅
 unsigned char j; 
 for(j=5;j<=11;j++)
 {
  if(j!=9)
  { 
  digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
  } 
 }
} 
void setup()                       // 程式一開始就先做此敘述，且只做一次，通常都做腳位及數值等各種設定。
{ 
 int i;//定義變數 
 for(i=4;i<=11;i++) 
 pinMode(i,OUTPUT);                //設置 4～11引腳為輸出模式。 
} 
void loop() 
{
 int yes=1,time=700,t=time,s=100;  // yes(為1時速度加快，為0時速度減緩)、time(時間數值)、t(延遲時間)及s(時間差)。
 while(1)                          // 無限迴圈。
 {  
 if(yes==1)                        // 當yes相等於1時，速度加快。
  t-=s;
 if(t<=s)                          // 當速度為最低點時，將yes為0，準備將速度減緩。
  yes=0;
 if(yes==0)                        // 當yes相等於0時，速度減緩。
  t+=s;
 if(t>=time)                       // 當速度為最高點時，將yes為1，準備將速度加快。
  yes=1;
  
 digital_0();  //數字 0
 delay(t);
 digital_1();  //數字 1 
 delay(t);     //延時 ts 
 digital_2(); 
 delay(t); 
 digital_3(); 
 delay(t); 
 digital_4(); 
 delay(t); 
 digital_5(); 
 delay(t); 
 digital_6(); 
 delay(t); 
 digital_7(); 
 delay(t); 
 digital_8(); 
 delay(t); 
 digital_9(); 
 delay(t);
 digital_point();
 delay(t);
 } 
}
