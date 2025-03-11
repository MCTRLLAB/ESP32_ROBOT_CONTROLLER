#include "driver/twai.h"

#define RX_PIN        13
#define TX_PIN        14
//#define CAN_RS        2
#define CAN_REQST_ID  0x7DF
#define MODE_CONTROL 0x01
#define MODE_REC 0x01

void setup() {
  Serial.begin(115200);
  //pinMode(CAN_RS, INPUT);     // INPUT (high impedance) = slope control mode, OUTPUT = see next line
  //digitalWrite(CAN_RS, LOW);  // LOW = high speed mode, HIGH = low power mode (listen only)
  twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT((gpio_num_t)TX_PIN, (gpio_num_t)RX_PIN, TWAI_MODE_NORMAL);  // TWAI_MODE_NORMAL, TWAI_MODE_NO_ACK or TWAI_MODE_LISTEN_ONLY
  twai_timing_config_t t_config  = TWAI_TIMING_CONFIG_500KBITS();
  twai_filter_config_t f_config  = TWAI_FILTER_CONFIG_ACCEPT_ALL();
  twai_driver_install(&g_config, &t_config, &f_config);
  twai_start();
}


void loop() {
  Serial.println(CANsend());
  Serial.println("Message sent!");
  delay(1);
}

int CANsend (void) {
  twai_message_t message;
  message.identifier = CAN_REQST_ID;
  message.extd = 0;
  message.rtr = 0;
  message.data_length_code = 8;
  message.data[0] = 2;
  message.data[1] = 1;
  message.data[2] = 5;
  message.data[3] = 12;
  message.data[4] = 97;
  message.data[5] = 0;
  message.data[6] = 0;
  message.data[7] = 0; 
  return twai_transmit(&message, 0); 
}
