//Inisialisasi pembuatan variable
#define B1 7 // Motor B pins
#define B2 8
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(B1, OUTPUT);
 pinMode(B2, OUTPUT);
 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
}

void loop() {
}
void forward() { //function of forward 
 digitalWrite(B1, HIGH);
 delay(70);
 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
}
void backward() { //function of backward
 digitalWrite(B1, LOW);
 digitalWrite(B2, HIGH);
 delay(70);
 digitalWrite(B2, LOW);
}
void Stop() { //function of stop
 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
}
