Automated fridge that is opened/closed by a linear actuator controlled by an arduino. This repo should be most of what you need to build one.

The arduino recieves input from two 5V I/O signal wires. When signal 1 is HIGH and  signal 2 is LOW, the actuator extends. When signal 1 is LOW and signal 2 is HIGH, the circuit reverses the polarity of the voltage to the actuator and it retracts.

It is important to use a relay with this design as the actuator is powered by 12V and the arduino can only output 5V. So, the 5V signal from the arduino switches the relay which then draws 12V from the wall to power the actuator.
