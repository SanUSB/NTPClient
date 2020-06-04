#define LED 16

bool toggle = 0;

void timer0_ISR (void) {
  if (toggle) { digitalWrite(LED, HIGH); toggle = 0;
              } else { digitalWrite(LED, LOW); toggle = 1;
                      }

timer0_write(ESP.getCycleCount() + 80000000L); // para 80MHz -> conta 80000000 = 1sec 
Serial.println("Timer0 ESP8266 Hardware Interrupt");
}

void setup() {
Serial.begin(115200);
pinMode(LED, OUTPUT);
noInterrupts();
timer0_isr_init(); //ISR = Interrupt service routine
timer0_attachInterrupt(timer0_ISR);
timer0_write(ESP.getCycleCount() + 80000000L); // para 80MHz, 80000000L =  1sec
interrupts();
}

void loop() {}
