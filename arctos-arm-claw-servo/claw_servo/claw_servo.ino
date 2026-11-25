#include <Servo.h>

// Creating my servo object to control the Arctos claw gripper
Servo myClaw;

// Pin setup - I plugged my servo signal wire into digital pin 11 on my Arduino Mega
const int SERVO_PIN = 11;

// I tweaked these angle values so my printed gripper fully opens and closes without jamming
const int OPEN_ANGLE = 20;    // My claw's wide open position
const int CLOSE_ANGLE = 110;  // My claw's fully closed position

// Keeping track of where my servo currently is
int currentAngle = OPEN_ANGLE;

void setup() {
  // Starting serial communication just in case I need to debug later
  Serial.begin(9600);

  // Attaching my servo object to the pin on my board
  myClaw.attach(SERVO_PIN);

  // Set the starting position to open so I know it's ready
  myClaw.write(OPEN_ANGLE);
  delay(500);
}

void loop() {
  // Open the claw smoothly
  smoothMove(OPEN_ANGLE, 15);
  delay(2000); // Hold open for 2 seconds

  // Close the claw smoothly
  smoothMove(CLOSE_ANGLE, 15);
  delay(2000); // Hold closed for 2 seconds
}

// I wrote this function to move the servo gradually.
// If I just use write() directly, the DS3225 servo snaps shut way too fast
// and shakes my whole robotic arm!
void smoothMove(int targetAngle, int stepDelay) {
  if (currentAngle < targetAngle) {
    // Stepping up to target position
    for (int pos = currentAngle; pos <= targetAngle; pos++) {
      myClaw.write(pos);
      delay(stepDelay); // Small delay between steps makes it move smoothly
    }
  } else {
    // Stepping down to target position
    for (int pos = currentAngle; pos >= targetAngle; pos--) {
      myClaw.write(pos);
      delay(stepDelay);
    }
  }
  // Remember my new position
  currentAngle = targetAngle;
}
