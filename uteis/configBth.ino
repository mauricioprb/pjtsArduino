int led = 8;
int bthpw = 7;

char nomeBth[10] = "bth-HC-06";
char velocidade = '4';
char pin[5] = "0000";
char modo = '0';

void setup() {
  pinMode(led, OUTPUT);
  pinMode(bthpw, OUTPUT);

  digitalWrite(led, LOW);
  digitalWrite(bthpw, HIGH);

  Serial.begin(9600);

  Serial.print("AT");
  delay(1000);

  Serial.print("AT+NAME");
  Serial.print(nomeBth);
  delay(1000);

  Serial.print("AT+BAUD4");
  Serial.print(velocidade);
  delay(1000);

  Serial.print("AT+PIN");
  Serial.print(pin);
  delay(1000);

  Serial.print("AT+ROLE");
  Serial.print(modo);
  delay(1000);

  digitalWrite(led, HIGH);
}

void loop() {

}
