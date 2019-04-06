/*
 * Battery Capacity Meter
 * 
 * Connect to battery and hook up a load. It will save the last 10 runs in EEPROM
 * (runtime in minutes plus accumulated AmpHours). Upon start it will either start 
 * a new run (when a load is detected) or simply cycle through the results of the
 * last 10 runs.
 */
// Arduino Nano
// Processor ATmega328 (Old Bootloader)

#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(6, 7, 8, 9, 10, 11);
//LiquidCrystal lcd(2, 3, 4, 5, 11, 12);
const byte ACS711_PIN = A3;
//const int ACS711_VOLTAGE_REFERENCE = 4780;
const int ACS711_VOLTAGE_REFERENCE = 4990;
//const int ACS711_ZERO_LOAD_OFFSET = 512;
const int ACS711_ZERO_LOAD_OFFSET = 518;

//const byte LCD_TX = 9; // D9
//const byte LCD_RX = 6; // not connected anywhere
//SoftwareSerial myLcdSerial =  SoftwareSerial(LCD_RX, LCD_TX);

/*
 * EEPROM layout: 
 *  - one byte startup counter at eepromStartupCounterAddress
 *  - afterwards for each run 
 *     - 2 bytes (unsinged int) for runtime in minutes
 *     - 4 bytes (long) for milliamp hours
    EEPROM  variable  slot
    0   startupCounter  
    1   runtime1  0
    2   runtime2  
    3   mah1  
    4   mah2  
    5   mah3  
    6   mah4  
    7   runtime1  1
    8   runtime2  
    9   mah1  
    10    mah2  
    11    mah3  
    12    mah4  
    ... 
 */
const int eepromStartupCounterAddress=0;

byte eepromSlotForStartup;
unsigned int currentRuntimeInMinutes;
long previousMilliAmpMinutes;

// ------------------------ iteadstudio lcd -------------
// https://www.itead.cc/blog/uart-serial-lcd-module

void setupLcd()
{
    lcd.begin(16, 2);
 // pinMode(LCD_TX, OUTPUT); // Arduino's Tx as transmitter to LCD
  //pinMode(LCD_RX, INPUT); //
  Serial.begin(9600);
 lcd.clear();
 // delay(10);
 //lcd.print("sb0;"); // set backlight, 0=off, 1=on (sb)
  //delay(10);
lcd.setCursor(0,0);
 
 lcd.print("mars monitoring");
 
 lcd.setCursor(0,1);
 // delay(10);
 lcd.print("Battery Capacity");
 // delay(10);
  delay(2000);
  lcd.clear();
}

void printLcdSketchConfig(int rawValueCoded, int rawValueMeasured, int referenceVoltageCoded, int milliAmps) {
 lcd.clear();
 // delay(10);
// lcd.print("sb1;"); // set backlight, 0=off, 1=on (sb)
 // delay(10);
lcd.setCursor(0,0); //set coordinate (col 0,row 0)
 // delay(10);
 lcd.print("no load|mA");
 lcd.print(milliAmps);
 ////lcd.print(";");
 // delay(10);
 lcd.setCursor(0,0); //set coordinate (col 0,row 0)
 // delay(10);
// //lcd.print("ss");
 lcd.print("rc");
 lcd.print(rawValueCoded);
 lcd.print("rm");
 lcd.print(rawValueMeasured);
 lcd.print("vc");
 lcd.print(referenceVoltageCoded);
 //lcd.print(";");
 // delay(10);
}

void printLcdHistoricRun(byte startupCounter1, unsigned int runtimeInMins1, long milliampHours1, byte startupCounter2, unsigned int runtimeInMins2, long milliampHours2) {
 lcd.clear(); //lcd.clear():
 // delay(10);
lcd.setCursor(0,0); //set coordinate (col 0,row 0)  //lcd.setCursor(0,0);
 // delay(10);
// //lcd.print("ss");
 
 lcd.print("R");
 lcd.print(startupCounter1);
 lcd.print("|");
 lcd.print(runtimeInMins1);
 lcd.print("min|");
  if (milliampHours1 >= 1000) {
   lcd.print((int) milliampHours1 / 1000);
   lcd.print("Ah");
  } else {
   lcd.print(milliampHours1);
   lcd.print("mAh");
  }
 // delay(10);
 lcd.setCursor(0,1); //set coordinate (col 0,row 1)
 // delay(10);
// //lcd.print("ss");
 
 lcd.print("R");
 lcd.print(startupCounter2);
 lcd.print("|");
 lcd.print(runtimeInMins2);
 
 lcd.print("min|");
  if (milliampHours2 >= 1000) {
   lcd.print((int) milliampHours2 / 1000);
   lcd.print("Ah");
  } else {
   lcd.print(milliampHours2);
   lcd.print("mAh");
  }
 // delay(10);
}

void printLcdCurrentRun(byte startupCounter, unsigned int runtimeInMins, long milliampHours, int milliamps) {
 lcd.clear();
 // delay(10);
   int rawValue = sampleAnalogRead(ACS711_PIN, 40, 10);

lcd.setCursor(0,0); //set coordinate (col 0,row 0)
 // delay(10);
  //lcd.print("ss");
 lcd.print("Run");
 lcd.print(startupCounter);
 lcd.print(" | ");
 lcd.print(runtimeInMins);
 lcd.print("min");
 // delay(10);
 lcd.setCursor(0,1); //set coordinate (col 0,row 1)
 // delay(10);
 ////lcd.print("ss");
 lcd.print(milliamps);
 lcd.print("mA");
 lcd.print("| ");
  if (milliampHours >= 1000) {
    // lcd.setCursor(0,1);
   lcd.print( milliampHours / 1000);
   lcd.print("Ah");
  } else {
   lcd.print(milliampHours);
   lcd.print("mAh");
  }
  
 //// delay(10);

  if (rawValue > 507 && rawValue < 520) {
    // no load detected, print diagnostic and historic values
    while (true) {  
      lcd.setCursor(0,0); 
      lcd.print("LOAD WENT OFF AT.. ");
       lcd.setCursor(0,1); 
       lcd.print(runtimeInMins);
 lcd.print("min");
     
 //lcd.print(milliamps);
 //lcd.print("mA");
 lcd.print(" | ");
  if (milliampHours >= 1000) {
    //lcd.print("|"); 
   lcd.print( milliampHours / 1000);
   lcd.print("Ah");
  
  }
  else {
    lcd.print(" | ");
   lcd.print(milliampHours);
   lcd.print("mAh");
  }
           }}
    
delay(10000);
}

void printLcdWait() {
 //lcd.clear();
 // delay(10);
lcd.setCursor(0,0); //set coordinate (col 0,row 0)
 // delay(10);
 lcd.print("Wait 1 minute");
 // delay(10);
 lcd.setCursor(0,1); //set coordinate (col 0,row 1)
 // delay(10);
 lcd.print("Measuring...");
 // delay(10);
}

// ---------------- Current sensing ACS 711 -------------

// https://www.pololu.com/product/2452
int pololuAcs711DcMilliAmps(int analogInputPin, int mVReference, int zeroLoadOffset) {

  // reference voltage, should be 5 V, but can vary a bit
  // with my MacBookPro and Leonardo via USB it is 5110
  //const int mVReference = 5110;

  // 36.7 * (voltage / mVReference) - 18.3

  // 136 mV / Amp for +/- 15 A version, depending on mVRef
  // 68 mV / Amp for +/- 31 A version, depending on mVRef
  const int mVperAmp = 68 ;
  
  int rawValue = sampleAnalogRead(analogInputPin, 40, 10);
  float voltage = ((rawValue - zeroLoadOffset) / 1023.0) * mVReference;
  float mamps = voltage / mVperAmp;
  return (int) (mamps * 1000);
}

int sampleAnalogRead(int analogInputPin, int sampleSize, int delayPeriod) {
  long rawValue = 0;
  int in = 0;
  for (int i = 0; i < sampleSize; i++) {
    in = analogRead(analogInputPin);
    //Serial.print(" ");
    //Serial.print(in);
    rawValue += in;
    delay(delayPeriod);
  }
  int rawValueAvg = (long) rawValue / sampleSize;
  //Serial.print(": ");
  //Serial.println(rawValueAvg);
  return rawValueAvg;
}

// ------------------------------------------
void setup() {
  while (!Serial) {
    delay(1);  // for Leonardo/Micro/Zero
  }
  Serial.begin(9600);
  Serial.println("setup");

  //internalEepromClear();
  //delay(60000);
  
  printInternalEeprom();
  setupLcd();
 
  int rawValue = sampleAnalogRead(ACS711_PIN, 40, 10);
  int milliAmps = -1;
  Serial.println("raw value");
  Serial.println(rawValue);
  
  //  if (false) { // use this to enforce logging of current config values
  if (rawValue > 507 && rawValue < 520) {
    // no load detected, print diagnostic and historic values
    while (true) {
      rawValue = sampleAnalogRead(ACS711_PIN, 40, 10);
      milliAmps = pololuAcs711DcMilliAmps(ACS711_PIN, ACS711_VOLTAGE_REFERENCE, ACS711_ZERO_LOAD_OFFSET);

      Serial.print("Analog input no load reference value: ");
      Serial.print("Used (hardcoded): ");
      Serial.print(ACS711_ZERO_LOAD_OFFSET);
      Serial.print(" - Current reading: ");
      Serial.println(rawValue);
      Serial.print("Reference voltage of current sensor (hardcoded): ");
      Serial.println(ACS711_VOLTAGE_REFERENCE);
      Serial.print("Current milliAmps: ");
      Serial.println(milliAmps);
    
      // simply cycle forever to prevent invocation of loop
      printLcdSketchConfig(ACS711_ZERO_LOAD_OFFSET, rawValue, ACS711_VOLTAGE_REFERENCE, milliAmps);
      delay(5000);
      int startups = readStartupCounter();
      for (int i = startups; i > 0 && (i > (startups-10)) ; i-=2) {
        printLcdHistoricRun(
          i, 
          readRuntimeCounterForStartup(i % 10), 
          readMilliAmpHoursForStartup(i % 10), 
          i-1, 
          readRuntimeCounterForStartup((i-1) % 10), 
          readMilliAmpHoursForStartup((i-1) % 10)
        );
        delay(5000);
      }
    }
  }

  // make sure not more than 9 runs are stored
  eepromSlotForStartup = (readStartupCounter() + 1) % 10;
  if (readStartupCounter() < 9) {
    writeStartupCounter(readStartupCounter() + 1);
  } else {
    writeStartupCounter(1);
  }
  
  currentRuntimeInMinutes = 0;
  writeRuntimeCounterForStartup(eepromSlotForStartup, currentRuntimeInMinutes);

  printLcdWait();
  Serial.println("Setup done");
}

void loop() {
  Serial.println("loop");
  delay(60000);
   

  

  currentRuntimeInMinutes++;
  writeRuntimeCounterForStartup(eepromSlotForStartup, currentRuntimeInMinutes);  

  int milliAmps;
  milliAmps = pololuAcs711DcMilliAmps(ACS711_PIN, ACS711_VOLTAGE_REFERENCE, ACS711_ZERO_LOAD_OFFSET);
  long previousMilliAmpHours;
  previousMilliAmpHours = readMilliAmpHoursForStartup(eepromSlotForStartup);
  long currentMilliAmpHours;
  currentMilliAmpHours = previousMilliAmpHours + (milliAmps / (long) 60);
  writeMilliAmpHoursForStartup(eepromSlotForStartup, currentMilliAmpHours);
  
  printLcdCurrentRun(readStartupCounter(), currentRuntimeInMinutes, currentMilliAmpHours, milliAmps);
  
  Serial.print("startupCounter: ");
  Serial.print(readStartupCounter());
  Serial.print(" - eepromSlot: ");
  Serial.print(eepromSlotForStartup);
  Serial.print(" - currentRuntime: ");
  Serial.print(currentRuntimeInMinutes);
  Serial.print(" - current milliAmps: ");
  Serial.print(milliAmps);
  Serial.print(" - milliAmpHours: ");
  Serial.print(currentMilliAmpHours);
  Serial.println();

    }


// ------------- EEPROM -------------------

void printInternalEeprom() {
  Serial.println("Previous runtimes");
  int startups = readStartupCounter();
  for (int i = startups; i > 0 && (i > (startups-10)) ; i--) {
    Serial.print("Startup: ");
    Serial.print(i);
    
    Serial.print(" | Mins: ");
    unsigned int runtimes;
    runtimes = readRuntimeCounterForStartup((i % 10));
    Serial.print(runtimes);
    
    Serial.print(" | Milliamphours: ");
    long mah;
    mah = readMilliAmpHoursForStartup((i % 10));
    Serial.print(mah);
    Serial.println();
  }
}

byte readStartupCounter() {
  return EEPROM.read(eepromStartupCounterAddress);
}

void writeStartupCounter(byte counter) {
  EEPROM.write(eepromStartupCounterAddress, counter);
}

unsigned int readRuntimeCounterForStartup(byte counter) {
  unsigned int minutes;
  EEPROM.get((counter * 6) + 1, minutes);
  return minutes;
}

void writeRuntimeCounterForStartup(byte counter, unsigned int  minutes) {
  EEPROM.put((counter * 6) + 1, minutes);
}

long readMilliAmpHoursForStartup(byte counter) {
  long mah;
  EEPROM.get((counter * 6) + 3, mah);
  return mah;
}

void writeMilliAmpHoursForStartup(byte counter, long mah) {
  EEPROM.put((counter * 6) + 3, mah);
}

void internalEepromClear() {
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
  Serial.println("eeprom cleared");
}
