# I-am-Speed

s0: 
1. //writen
2. check video how joystick works
3. System setup

s1: Rotary encoder
> Arduino programming & testing (Get Feel of Working)
ex- if (rVal<0) {(serial.write("left/right"))}
> Connect to python. 
ex- if s.read=="left": pag.press('left')
> check in game

s2: Pedals
> 3 SEPARATE pushbuttons- Break, Acc, N2O (Get Feel of Working)
> Arduino programming & testing
ex- if (p0 pressed)->serial.write("brake")
> Connect to python. 
  if s.read=="brake": pag.press('space')
> check in game

s3: Joystick
> Arduino programming & testing
if (jValx < -50 && jValy > 50)
{serial.write("Gear1") }
> Connect to python. 
  if s.read=="Gear2": pag.press('2')
> check in game


sF:
body taiyaar
i. steering wheel
ii. Pedals 
iii. Gear box
iv. Step
