#include <RH_RF95.h>

/* Feather 32u4 Chipset */
#if BOARD == Feather32u4
    #define RFM95_CS 8
    #define RFM95_RST 4
    #define RFM95_INT 7
#endif

/* Feather M0 Chipset */
#if BOARD == FeatherM0
    #define RFM95_CS 8
    #define RFM95_RST 4
    #define RFM95_INT 3
#endif

RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setupRadio() {
    Serial.println(F("LoRa Test!"));
    digitalWrite(RFM95_RST, LOW);
    delay(10);
    digitalWrite(RFM95_RST, HIGH);
    delay(10);
    while (!rf95.init()) {
        fail(LORA_INIT_FAIL);
    }
    Serial.println(F("LoRa OK!"));
    if (!rf95.setFrequency(RF95_FREQ)) {
        fail(LORA_FREQ_FAIL);
    }
    Serial.print(F("FREQ: ")); Serial.println(RF95_FREQ);
    rf95.setTxPower(TX_POWER, false);
    delay(100);
}
