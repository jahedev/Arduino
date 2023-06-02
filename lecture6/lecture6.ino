/*
 *  An over-engineered project of building an LED counter
 */ 

#define LED_WHITE   4
#define LED_YELLOW  5
#define LED_BLUE    6
#define LED_RED     7

#define BIN_DIGITS  4

int * binary;
unsigned int decimal_num;
int max_decimal;

void setup() {
  Serial.begin(9600);
  Serial.println("\n\n\n");
  delay(1000);

  pinModeConfig();
  binary = NULL;
  decimal_num = 15;

}

void loop() {
  binary = convertToBinary(decimal_num++, BIN_DIGITS);
  writeLED(binary[0], binary[1], binary[2], binary[3]);
  printArray(binary, BIN_DIGITS);
  delay(1000);
}

void pinModeConfig() {
  pinMode(LED_WHITE,  OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE,   OUTPUT);
  pinMode(LED_RED,    OUTPUT);
}

void clearLED() {
  digitalWrite(LED_WHITE,   LOW);
  digitalWrite(LED_YELLOW,  LOW);
  digitalWrite(LED_BLUE,    LOW);
  digitalWrite(LED_RED,     LOW);
}

void writeLED(bool LED_1, bool LED_2, bool LED_3, bool LED_4) {
  digitalWrite(LED_WHITE,   LED_1  ? HIGH : LOW);
  digitalWrite(LED_YELLOW,  LED_2  ? HIGH : LOW);
  digitalWrite(LED_BLUE,    LED_3  ? HIGH : LOW);
  digitalWrite(LED_RED,     LED_4  ? HIGH : LOW);
}

int* convertToBinary(unsigned int n, int digits) {
    int* binaryArray = new int[digits];

    for (int i = digits - 1; i >= 0; --i) {
        binaryArray[i] = n % 2;
        n /= 2;
    }

    return binaryArray;
}

void printArray(int * arr, int size) {
    for (int i = 0; i < size; i++) {
      Serial.print(i);
      Serial.print(": ");
      Serial.print(arr[i]);
    }
    Serial.println();
}
