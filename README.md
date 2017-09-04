
# Otto DIY+
"Otto DIY with steroids" 

This Repository have all open source files for Otto DIY+ an interactive robot that anyone can make!,
Otto DIY + can make everything that Otto DIY does + Bluetooth + APP + switch + sensors + strength +... anything you might expand feel FREE to add and contribute.
Is completely open source, Arduino compatible, 3D printable, once you have all components and tools you will be able to build your own Otto
<img src="OTTO_DIY_PLUS.png" width="900" align="center">

This is a more advanced version requires some expertise and patience, if you want to start slow as a beginner  please go to [Otto DIY repository](https://github.com/OttoDIY/DIY)

Start by [downloading all files here](https://github.com/OttoDIY/PLUS/archive/master.zip)

## For the hardware
Gather all the off the shelf parts in the BOM file that you'll need for this assembly, then 3d print the  .stl files and then follow the instruction manual to build your own robot.

## For the programming
1. Download & Install Arduino IDE: https://www.arduino.cc/en/Main/Software also this driver if you have a clone board: http://www.wch.cn/download/CH341SER_EXE.html for PC, or http://www.wch.cn/download/CH341SER_MAC_ZIP.html for MAC
2. Copy all libraries to C:\Users\user\Documents\Arduino\libraries (or wherever your library folder is installed):
3. Open  for example OTTO_smooth_criminal.ino, make sure in tools you have "Board: Arduino Nano" "Processor ATmega328" and your Otto is connected to the corresponding port
4. Upload code to your Otto and will dance!
5. Make your own dance just modify the program using same functions
6. Setup your Bluetooth module
7. Upload the Bluetooth code
8. Play with the APP

+LED mouth Matrix use the [MAX7219](https://es.aliexpress.com/item/1pcs-MAX7219-dot-matrix-module-microcontroller-module-display-module-finished-goods/32725083862.html?spm=2114.search0104.3.97.cyRMWM&ws_ab_test=searchweb0_0%2Csearchweb201602_2_10152_10065_10151_10068_5460011_10307_10301_10303_10137_10060_10155_10154_10056_10055_10054_5470020_10059_100031_10099_10103_10102_10052_10053_10142_10107_10050_10051_5380020_10326_10084_10083_10080_10082_10081_10110_10111_10112_10113_10114_10179_10312_10313_10314_10078_10079_10073_5540020%2Csearchweb201603_2%2CppcSwitch_4&btsid=a23e196a-27ae-44de-9cd0-4252f0e1a4c3&algo_expid=f2ef828c-d2ef-43a0-abc1-84d06ab3babd-12&algo_pvid=f2ef828c-d2ef-43a0-abc1-84d06ab3babd)
+Touch sensor use this [2PCS TTP223 Capacitive Touch Switch Button Self-Lock Module for Arduino](http://www.ebay.com/itm/2PCS-TTP223-Capacitive-Touch-Switch-Button-Self-Lock-Module-for-Arduino/131662428748?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2057872.m2749.l2649)

### Otto DIY + is  design using Autodesk Fusion 360
So is completely parametric and precise to adjust tolerances
[You can modify it for customization](https://gallery.autodesk.com/fusion360/projects/otto-diyplus) or further improvements

### Hall of fame Otto builders list
Our broad community is awesome! we have been developing and improving OttoDIY project together ;)

| contribution  | date | builder name | country |
| --- | --- | --- | --- |
| oscillator algorithm library| Jan 2015 | Obijuan | Spain  |
| inventor of Zowi 3D printable | Dec 2015  | Javier Isabel |Spain |
| Bobwi (combination of Bob and Zowi  | Jan 2016  |G4alileo |Spain  |
| BT, battery, nose LED RGB, touch and tilt | April 2016 |Davor Levstek  |Croatia |
| Robonino with voice control |May 2016|Santiago|Spain |
| Calibration tool  | June 2016 |Rafael López  |Spain |
| FreeCAD model|August 2016|Juan Carlos López Sánchez |Spain |
| ESPOtto voice | Sept 2016 |Gustavo Reynaga |Mexico|
| Otto arms |Sept 2016|Jason Leung| Hong Kong |
| Google Play android APP  | Oct 2016 |Juan Felix Mateos |Spain |
| Switch alternative |Dec 2016|Robert Holt |United States |
| Custom PCB, OttoDIY+ repository | Jan 2017 |Jason Snow |England |
| Single ladies dance| Jan 2017  |brico3D |Spain |
| Nose and DIY APP |Feb 2017|Andrés Fernández Muñoz|Spain |
| feedback  | March 2017   |Frank Lopez |United States |
| feedback | March 2017  |Octavio P Nogueira |Brazil  |
| feedback  | March 2017  |tritri62|??? |
| Custom PCB | 	March 2017 |Marco|Italy |
| Laser cut Otto |March 2017|Florian Festi|Germany |
| XXL Head |March 2017|Markus Otte |Germany |
| XGoBroRobo IR control |March 2017|Jonathan Hess |Germany |
| Easy BT Easy HC-06 | May 2017  |Pablo E. García Palacios  |Spain |
| Custom PCB, battery booster, noise detection | April 2017|Pedro 51|France |
| graphical coding  | June 2017  |Liao Ping Lun  |China |
| Otto bender mod| June 2017  |bricogeek |Spain |
| remote control | July 2017  |Jayesh Chauhan |India  |
| Customizable Otto 3D print |July 2017|Brandon Bowles |United States |
| quadruped Otto | August 2017  |quadruped |China |
| control from laptop | August 2017  |SungHyun Ryu |South Korea |

Special thanks to all these #Ottobuilder that made and are making this project evolve and accessible to everyoone in the world. If we skip one please tell us!

### Pending  to develop idea list
Feel free to grab and mix ideas from this table for your Otto and if you are nice person please share with all the community

| Function-Feature  | sensor(input) | movement (output) | 
| --- | --- | --- | 
| drumer  |microphone|hands+stick|
| Car-balancing  |accelerometer|wheels|
| Sumo |IR|wheels+bumper|
| omniwheel |magnet switch|wheels+rollers|
| Train |IR|Steam generator|
| Humanoid |variable resistor modes|+servos control|
| Spider 6-8 legs |ultrasound gesture|+servos control+vibrators|
| hover or drone |accelerometer|+DC motor control|
| look around http://www.mi.com/xiaofang/ |timer|new head|
| writer |encoders|DC+ pen holder|
| following line |IR+encoders|step motors|
| Bubbles |light|DC fan|
| crane |Buttons|+servos control|
| Gripper |Tilt Sensor|+servo|
| reaction to music  |keepon|vibrators|
| Follow music | MP3 SD card|disco lights|
| Voice commands like Wire Beings beta |telegram|multiple boards|
| clap rhythm |microphone|vibrators|

coding we would like to use a scustom made version ArduBlock or Mitily or Blockly duino or Bitbloq or scratchX or APP for block programming

## License CC-BY-SA
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">Otto DIY</span> by <a xmlns:cc="http://creativecommons.org/ns#"  property="cc:attributionName"> [ottodiy.com](http://ottodiy.com) </a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
