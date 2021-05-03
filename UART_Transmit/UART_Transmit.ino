void setup() {
  Serial3.begin(115200);
  Serial.begin(115200);
}

void sendUART(int input[])
{
  char C;

  Serial3.print('a');
  for (int i = 0; i <= 9; i++)
  {
    Serial3.print(input[i]);
    if (Serial3.available() > 0)
    {
      C = (char)Serial3.read();
      Serial.print(C);
    }
    delay(60);
  }
  C = (char)Serial3.read();
  Serial.print(C);
  delay(1000);
}

void loop() {
  int reg5[10] = {0,0,0,4,1,9,4,3,0,9};
  int reg4[10] = {1,6,1,2,0,7,1,1,4,0};
  int reg3[10] = {0,0,0,0,0,6,2,0,0,3};
  int reg2[10] = {0,2,0,1,3,6,7,3,6,2};
  int reg1[10] = {1,0,7,3,7,7,5,5,9,3};
  int reg0[10] = {0,0,1,3,1,0,7,2,0,0};

  Serial.println("Starting transmission");
  for (int i = 0; i < 2; i++)
  {
    sendUART(reg5);
    Serial.println("");
    sendUART(reg4);
    Serial.println("");
    sendUART(reg3);
    Serial.println("");
    sendUART(reg2);
    Serial.println("");
    sendUART(reg1);
    Serial.println("");
    sendUART(reg0);
    Serial.println("");
    delay(30);
  }

  delay(5000);
}
