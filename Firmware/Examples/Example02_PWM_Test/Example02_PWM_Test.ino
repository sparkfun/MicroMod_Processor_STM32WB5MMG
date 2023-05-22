/**
 * @file Example02_PWM_Test.ino
 * @brief This example sets the PWM channels to be read by an oscilloscope.
 * @copyright SPDX-License-Identifier: MIT
 * @author Alex Brudner, SparkFun Electronics
 * @date 2023-04-18
 * @note Based on the PWM example from ST here:
 * https://github.com/stm32duino/STM32Examples
 *
 * Feel like supporting open source hardware?
 * Buy a board from SparkFun!
 *      MicroMod STM32WB5MMG Processor Board
 *        | https://www.sparkfun.com/products/21438
 *      MicroMod ATP Carrier Board                       
 *        | https://www.sparkfun.com/products/16885
 */

#include <Arduino.h>

#define PWM0 PD14
#define PWM1 PD15
// #define EX_TRIG PE0
// #define PWM_BRK PB12

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial) { delay(100); };

  Serial.println(F("Begin PWM Test."));


  TIM_TypeDef *tim_pwm0 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(PWM0), PinMap_PWM);
  uint32_t channel_pwm0 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM0), PinMap_PWM));
  
  HardwareTimer *MyTim_pwm0 = new HardwareTimer(tim_pwm0);
  MyTim_pwm0->setPWM(channel_pwm0, PWM0, 50000, 25);

  TIM_TypeDef *tim_pwm1 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(PWM1), PinMap_PWM);
  uint32_t channel_pwm1 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM1), PinMap_PWM));

  
  HardwareTimer *MyTim_pwm1 = new HardwareTimer(tim_pwm1);
  MyTim_pwm1->setPWM(channel_pwm1, PWM1, 50000, 75);  
}

void loop() {

}
