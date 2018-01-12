#include <RHMesh.h>
#include <RHRouter.h>
#include <RH_RF95.h>
#include <SPI.h>
#define NODE_ID 3
#define FREQ 915.00
#define TX 5
#define CAD 2000
#define TIMEOUT 1000
#define CS 8
#define INT 3

static RHMesh* router;
//RH_RF95 radio(CS, INT);
RH_RF95 *radio;


/*
void setupRadio(RH_RF95 rf95)
{
    Serial.print("Setting up radio with RadioHead Version ");
    Serial.print(RH_VERSION_MAJOR, DEC); Serial.print(".");
    Serial.println(RH_VERSION_MINOR, DEC);
    Serial.print("Node ID: ");
    Serial.println(NODE_ID);
    router = new RHMesh(rf95, NODE_ID); 
    //rf95.setModemConfig(RH_RF95::Bw125Cr48Sf4096); // doesn't work with RH 1.71
    if (!router->init())
        Serial.println("Router init failed");
    Serial.print(F("FREQ: ")); Serial.println(FREQ);
    if (!rf95.setFrequency(FREQ)) {
        Serial.println("Radio frequency set failed");
    } 
    rf95.setTxPower(TX, false);
    //rf95.setCADTimeout(CAD);
    router->setTimeout(TIMEOUT);
    delay(100);
}
*/



void setup() {
    while (!Serial);
    Serial.print("Setting up radio with RadioHead Version ");
    Serial.print(RH_VERSION_MAJOR, DEC); Serial.print(".");
    Serial.println(RH_VERSION_MINOR, DEC);
    Serial.print("Node ID: ");
    Serial.println(NODE_ID);
    radio = new RH_RF95(CS, INT);
    router = new RHMesh(*radio, NODE_ID);
    if (!router->init())
        Serial.println("Router init failed");
    Serial.print(F("FREQ: ")); Serial.println(FREQ);
    if (!radio->setFrequency(FREQ)) {
        Serial.println("Radio frequency set failed");
    } 
    radio->setTxPower(TX, false);
    //rf95.setCADTimeout(CAD);
    router->setTimeout(TIMEOUT);
    delay(100);
}

void loop() {
  uint8_t data[] = "Message";
  Serial.println("Sending message");
  if (router->sendtoWait(data, sizeof(data), 14) != RH_ROUTER_ERROR_NONE) {
      Serial.println("sendtoWait failed");
      //Serial.println("sleeping 10 seconds");
      //router->_driver.sleep();
      //delay(10000); 
  }
  delay(10);
}