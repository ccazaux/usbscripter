/*
  USBSCRIPTER
  ESP32S3-USB-OTG avec capacité a gérer USB keyboard
  Auteur : CCA
  NB : Pour avoir un clavier francais, remplacer /home/<user>/.arduino15/packages/esp32/hardware/esp32/<version>/libraries/USB/src/USBHIDKeyboard.cpp par le fichier USBHIDKeyboard.cpp_FR fourni avec ce code
*/

#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting USB Keyboard ESP32-S3!");
  //Initialisation
  Keyboard.begin();
  //  Keyboard.begin(KeyboardLayout_fr_FR); // use the Swedish layout
  USB.begin();

}


void openTerminal()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(500);
  Keyboard.releaseAll();
  delay(1000);
}

void moveTerminalLEFT()
{
  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.press(KEY_LEFT_ARROW);
  delay(50);
  Keyboard.releaseAll();
  delay(100);
}

void moveTerminalRIGHT()
{
  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.press(KEY_RIGHT_ARROW);
  delay(50);
  Keyboard.releaseAll();
  delay(100);
}

void loop()
{
  delay(1500);
  openTerminal();
  moveTerminalLEFT();
  Keyboard.println("figlet   Auto   Scripter"); delay(2000);
  Keyboard.println("ll /opt -R"); delay(500);
  Keyboard.println("btop"); delay(500);

  openTerminal();
  moveTerminalRIGHT();
  Keyboard.println("ifconfig"); delay(500);
  Keyboard.println("ping 8.8.8.8"); delay(500);
  delay(-1);  //infinite sleep

}
