# Claw Servo Code for a 6-DOF Arctos Robotic Arm

Arduino code I wrote for the claw on a 6-DOF Arctos robotic arm, built by a team of four in ZOTBotics at UC Irvine. I was on the electrical subteam and wired the arm's stepper motors, Hall-effect limit sensors, and Arduino MEGA. The arm itself ran GRBL, which I didn't write, and this repo is only the claw code. The arm completed all three competition tasks: weight lifting, cup stacking, and pouring water.

Photos: [be-ph-5.github.io](https://be-ph-5.github.io/)

## Hardware

- Arduino MEGA
- DS3225 servo driving a 3D-printed two-prong gripper
- Servo signal on digital pin 11

## How it works

- `OPEN_ANGLE` (20°) and `CLOSE_ANGLE` (110°) were tuned so the printed gripper fully opens and closes without jamming.
- `smoothMove()` steps the servo one degree at a time with a 15 ms pause between steps, so a 90° swing takes about 1.4 s.
- Writing the target angle in one step made the DS3225 snap shut and shake the whole arm, so stepping it gradually fixed that.
- The test loop opens the claw, holds for 2 s, closes it, and holds for 2 s.
