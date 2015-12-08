const byte ledPin=7;
void setup() {
  Serial.begin(9600); // 初始化序列埠，9600bps速度連線。
  Serial.println("Hello,");
  Serial.println("\tLED pis is: ");
  Serial.println(ledPin);
  Serial.println(3.14159);// 預設小數點後2位。
  Serial.println(3.14159,0); // 不輸出小數點。
  Serial.println(3.14159,4); // 輸出小數點後4位。
  Serial.println(77,BIN); // 2進位。
  Serial.println(77,HEX); // 16進位。
  Serial.println(77,OCT); // 8進位。
  Serial.println(77,DEC); // 10進位。
  Serial.println("\nSee You~");
}
void loop() {    
}
