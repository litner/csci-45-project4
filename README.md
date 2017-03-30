# csci-45-project4

## Team ##
Joses Paras <br />
Tanpreet Dhaliwal

## Rules ##
<p>The specific rules for this project are:</p>
1. It can rotate up to 180 degrees, detect a stationary target within the firing arc, and shoot it.
2. Autonomous mode (you turn it on, it will engage seek and destroy mode automatically)
3. It must fire a bouncy ball or something equally cool (a miniature harpoon, a ping pong ball, etc.)
4. Accurate: it should strike the center of mass on the target, or as close as possible to the center
5. Distance: It should be able to detect and hit targets between 1m and 5m (the effective range of our ultrasound sensors.

- - - -
# Project Proposal #
<p>sentry turret that shoots bouncy balls if it detects something with ultrasound sensors
while rotating back and forth with a servo</p>

## Sensors ##
Ultrasound Sensor

## Moving Parts ##
1 servo <br />
2 motors

### Pins ###
EchoPin 12
TrigPin 16
SERVOPIN 26
MotorPin1 5
MotorPin2 6
RelayPin 13

## Responsibilities ##
Joses Paras - coding
Tanpreet Dhaliwal - construction and writing the papers

- - - -
# Compile and Run Code #
Run code: <br />
```
make
sudo ./project.o
```
