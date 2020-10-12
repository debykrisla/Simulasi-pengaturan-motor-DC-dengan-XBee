int Motor1 = 7;
int Motor2 = 6;
int Motor3 = 5;
int Motor4 = 4;
int DataCheck = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);
   
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, HIGH);
  digitalWrite(Motor3, HIGH);
  digitalWrite(Motor4, HIGH);
  Serial.print("Simulasi Pengendali Motor DC dgn XBee:");
  Serial.println();
  Serial.println("Broadband Multimedia");
  Serial.println();
  Serial.println();
  Serial.println();
   
}
void loop() 
{
  if(Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    Serial.print("      ======== >      ");
    
    if(data == '1'){DataCheck = 1; digitalWrite(Motor2, LOW);digitalWrite(Motor1, HIGH); Serial.println("Motor Pertama berputar searah jarum jam.");}
    if(data == '2'){DataCheck = 1; digitalWrite(Motor1, LOW);digitalWrite(Motor2, HIGH); Serial.println("Motor Pertama berputar berlawanan arah jarum jam.");}
    if(data == '3'){DataCheck = 1; digitalWrite(Motor1, LOW);digitalWrite(Motor2,  LOW); Serial.println("Motor Pertama BERHENTI");} 
    if(data == '4'){DataCheck = 1; digitalWrite(Motor3, LOW);digitalWrite(Motor4, HIGH); Serial.println("Motor Kedua berputar searah jarum jam.");}
    if(data == '5'){DataCheck = 1; digitalWrite(Motor4, LOW);digitalWrite(Motor3, HIGH); Serial.println("Motor Kedua berputar berlawanan arah jarum jam.");}
    if(data == '6'){DataCheck = 1; digitalWrite(Motor3, LOW);digitalWrite(Motor4,  LOW); Serial.println("Motor Kedua BERHENTI");}
    if(DataCheck == 0){Serial.println("Perintah Salah. Silakan ulangi !!! ");}
    Serial.println();
    DataCheck = 0;
  }
}
