# Landing Gear Arduino Skecth

I'd like to thank (Thingiverse Username) ComikzInk for the plans for this build as well as pleantiful documentation that can be found here.

FliteTest Swapable Spitfire Retractable Landing Gear found on #Thingiverse https://www.thingiverse.com/thing:270...

A little background: 

I wanted to use a landing gear for this FT MIG-3 I put together, but the steel wire remain-in-place ones weren't cutting it for me. I came across these plans on Thingiverse and spent a couple days mulling over how I might be able to incorporate this design into my build. I don't have a fancy transmitter that could support these, so I resolved to manage the movement of them by writing a program for and using an Arduino nano. This enabled me to easily fine tune the setup and throttle the servos down to keep them from swinging their full 90° range. Since the MIG's bottom surface of the wing is flush with the fuselage and the wing is a little bit thinner, I was able to recess the gear a little ways into the foam. I used foaming garilla glue to fix the service horns into the gear leg and once it dried, I applied some JB weld.   Since I have a microcontroller onboard the plane now, I'm also considering using a spare gyroscope, barometer, and GPS I have laying around to play around with some sort of flight control program. 

The code:

The code is divided into the setup which starts the Serial, sets pinMode, and attaches servos to output pins, then calls a single use function to initialize the landing gear so the microcontroller knows the servo's position. Going into the loop, the PWM signal is measured from the reciver. Serial data is printed, and it works it's way through two while loops that call the gear to be deployed or retracted depending on the signal and what position the gear is in already. It's been a fun project and I can't wait to see out the thing holds up. 
