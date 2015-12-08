const byte ledPin=7;
void setup() {
  Serial.begin(9600); // 初始化序列埠，9600bps速度連線。
  Serial.println("Hello,");
  Serial.print("\tLED pis is: ");
  Serial.print(ledPin);
  Serial.println("\nSee You~");
}
void loop() {    
}
