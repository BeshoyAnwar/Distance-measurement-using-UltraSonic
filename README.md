# Distance measurement using UltraSonic
we used an ultrasonic sensor to measure the distances in range 2cm:400cm and display it on three 7-segments on TIVA C board
# Ultrasonic Sensor Module
Ultrasonic sensor HC-SR04 is used here to measure distance in range of 2cm-400cm with accuracy of 3mm. The sensor module consists of ultrasonic transmitter, receiver and the control circuit. The working principle of ultrasonic sensor is as follows:

High level signal is sent for 10us using Trigger.

The module sends eight 40 KHz signals automatically, and then detects whether pulse is received or not.

If the signal is received, then it is through high level. The time of high duration is the time gap between sending and receiving the signal.

Distance= (Time x Speed of Sound in Air (340 m/s))/2

# 7-segment Display.

The 7-segment display, also written as “seven segment display”, consists of seven LEDs (hence its name) arranged in a rectangular fashion as shown. Each of the seven LEDs is called a segment because when illuminated the segment forms part of a numerical digit (both Decimal and Hex) to be displayed. An additional 8th LED is sometimes used within the same package thus allowing the indication of a decimal point, (DP) when two or more 7-segment displays are connected together to display numbers greater than ten.

Each one of the seven LEDs in the display is given a positional segment with one of its connection pins being brought straight out of the rectangular plastic package. These individually LED pins are labelled from a through to g representing each individual LED. The other LED pins are connected together and wired to form a common pin.

So by forward biasing the appropriate pins of the LED segments in a particular order, some segments will be light and others will be dark allowing the desired character pattern of the number to be generated on the display. This then allows us to display each of the ten decimal digits 0 through to 9 on the same 7-segment display.

The displays common pin is generally used to identify which type of 7-segment display it is. As each LED has two connecting pins, one called the “Anode” and the other called the “Cathode”, there are therefore two types of LED 7-segment display called: Common Cathode (CC) 'the common node connected to the ground' so if you need to on the A-LED need to force a Vcc on the other node of A(active high)
and Common Anode (CA)'the common node connected to the Vcc' so if you need to on the A-LED need to force a ground on the other node of A (active low),here we using three Common-anode 7-segments.

Our target is TIVA C kit and developed and tested on kiel v4
