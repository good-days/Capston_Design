#include <SoftwareSerial.h>

SoftwareSerial rSerial(2,3);
const int tag_len=16;
void setup() {
  Serial.begin(9600);
  rSerial.begin(9600);
  Serial.println("RFID example start!");
  Serial.println('\n');
}

void loop() {
  // 태그의 ID를 저장할 곳
  char tagString[15];
  int index = 0;

  while (rSerial.available()) {
    // 시리얼 포트에 있는 데이터를 저장합니다.
    int readByte = rSerial.read();
    Serial.println("rSerial.read() is ");
    Serial.print("DEC : ");
    Serial.println(readByte, DEC);
    Serial.print("HEX : ");
    Serial.println(readByte, HEX);
    Serial.println("RFID reading.... store string");

    // RFID 태그의 ID를 저장합니다.
    tagString[index] = readByte;
    index++;
    Serial.println("tagString is : ");
    // RFID 태그의 ID를 출력합니다.
    Serial.println(tagString);
  }

  delay(1000);
}
