// Pin definitions
const int RELAY_IN3 = 8;      // First relay control pin
const int RELAY_IN4 = 7;      // Second relay control pin
const int IO_SIGNAL1 = 2;     // First I/O input from liquid handler
const int IO_SIGNAL2 = 3;     // Second I/O input from liquid handler

// Timing constants
const int RELAY_DELAY = 50;   // Delay between relay switching to prevent shorts

void setup() {
  // Configure relay control pins as outputs
  pinMode(RELAY_IN3, OUTPUT);
  pinMode(RELAY_IN4, OUTPUT);

  // Configure I/O signal pins as inputs
  pinMode(IO_SIGNAL1, INPUT);
  pinMode(IO_SIGNAL2, INPUT);

  // Initialize relays to OFF state
  digitalWrite(RELAY_IN3, HIGH);  // Relays are typically active LOW
  digitalWrite(RELAY_IN4, HIGH);
}

void loop() {
  // Read I/O signals
  int signal1 = digitalRead(IO_SIGNAL1);
  int signal2 = digitalRead(IO_SIGNAL2);

  // Safety check - make sure both signals aren't active
  if (signal1 == HIGH && signal2 == HIGH) {
    // Error condition - turn everything off
    digitalWrite(RELAY_IN3, HIGH);
    digitalWrite(RELAY_IN4, HIGH);
    return;
  }

  // Direction 1 - First signal active
  if (signal1 == HIGH && signal2 == LOW) {
    digitalWrite(RELAY_IN4, HIGH);  // Make sure other relay is off first
    delay(RELAY_DELAY);            // Brief delay to prevent shorts
    digitalWrite(RELAY_IN3, LOW);   // Activate first relay
  }
  // Direction 2 - Second signal active
  else if (signal2 == HIGH && signal1 == LOW) {
    digitalWrite(RELAY_IN3, HIGH);  // Make sure other relay is off first
    delay(RELAY_DELAY);            // Brief delay to prevent shorts
    digitalWrite(RELAY_IN4, LOW);   // Activate second relay
  }
  // No signals active - stop movement
  else {
    digitalWrite(RELAY_IN3, HIGH);
    digitalWrite(RELAY_IN4, HIGH);
  }
}