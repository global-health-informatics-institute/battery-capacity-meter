# battery-capacity-meter

### Data from previous runs

Connect without any load. The BCM will go into passive mode and log data form the previous 9 runs together with information about the current current sensor calibration.

After the calibration data the last up to 9 runs are displayed. Each line shows the results from one run:

* startupCounter: runtime in minutes | measured mAh or Ah

### Measuring battery capacity

If a load is detected during startup, the BCM switches into measuring mode. It will take one minute before the first reading is displayed on the screen. From then every minute an intermediate result will be shown until the LVD cuts out.

Note that with +/- 31 Amps current sensor, a smaller load may not be properly be detected. Also make sure that the calibration (esp offset for the 0 value of the coded raw value) somehow matches.

### Calibration 

The calibration is necessary if a change in the layout is done (other current sensor, other Arduino board) as the sketch is written to the specific values of these specific components and can/will change with other components (mostly internal voltage regulator of the Arduino and wiring). This diagnostic data is printed on the screen with the prefix "no load":

* mA: current measured load (should oscillate around 0)
* rc: The raw value as read by the analog input (provided by the current sensor). Usually this is around 1024/2 and determines the 0 mA range. The rc value is the Raw values as currently Coded in the sketch. Should match rm.
* rm: The above raw value as currently delivered by the current sensor. Should match rc.
* vc: The currently coded reference voltage of the sketch as seen by the current sensor. Should be verified with an external voltmeter directly from the current sensor ('inner' GND pin and 'middle' V pin). CAREFUL to not short these 2 pins as they fry the Arduino and potentially other components.

