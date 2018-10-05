#include <Wire.h>

struct analogDaten{
  int analog1;
  int analog2;
  }data;
//uint8_t data[] ={0,0};

void setup() {
  Wire.begin(8);
  Wire.onRequest(requestEvent);

}

void loop() {
    data.analog1 = analogRead(A2);
    data.analog2 = analogRead(A3);
    delay(1000);

}

void requestEvent(){
  byte data_to_send[sizeof(data)];
  memcpy(&data_to_send,&data,sizeof(data));
  Wire.write(data_to_send,sizeof(data));
}
