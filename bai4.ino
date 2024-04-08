#include <DHT.h>

#define DHTPIN 2     // Chân DATA của cảm biến DHT22 kết nối vào chân số 2 của Arduino
#define DHTTYPE DHT22   // Sử dụng cảm biến DHT22
DHT dht(DHTPIN, DHTTYPE);

// Khai báo chân LED
const int ledPins[] = {5,6,7}; // Chân kết nối với LED

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  // Khởi tạo các chân LED là OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Tắt tất cả LED khi bắt đầu
  }
}

void loop() {
  // Đọc nhiệt độ và độ ẩm từ cảm biến DHT22
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Đọc nhiệt độ trong độ C

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // In giá trị nhiệt độ và độ ẩm ra Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  // Điều khiển LED tương ứng với nhiệt độ
  if (h > 70) {
    // Nếu độ ẩm cao, tắt tất cả các LED
    controlLEDs(false, false, false);
  } else if (t < 28) {
    // Nếu nhiệt độ thấp, tắt tất cả các LED
    controlLEDs(false, false, false);
  } else if (t >= 28 && t < 30) {
    // Nếu nhiệt độ trung bình, bật LED 1
    controlLEDs(true, false, false);
  } else if (t >= 30 && t < 34) {
    // Nếu nhiệt độ cao, bật LED 1 và LED 2
    controlLEDs(true, true, false);
  } else {
    // Nếu nhiệt độ rất cao, bật tất cả các LED
    controlLEDs(true, true, true);
  }
}

void controlLEDs(bool led1, bool led2, bool led3) {
  digitalWrite(ledPins[0], led1 ? HIGH : LOW);
  digitalWrite(ledPins[1], led2 ? HIGH : LOW);
  digitalWrite(ledPins[2], led3 ? HIGH : LOW);
}