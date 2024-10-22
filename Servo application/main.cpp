#include "servo.h"
//use PA2 for PWM tim5 Ch3
int main(void)
{
   HAL_Init();
   __HAL_RCC_GPIOA_CLK_ENABLE();
   __HAL_RCC_TIM5_CLK_ENABLE();
    pinStruct_t servoPin = {GPIOA, GPIO_PIN_2};
 //Statically allocated objects are guaranteed to be initialized by 
 //their constructor at compile-time.Just like how statically allocated
 //variables are initialized at compile time, statically allocated objects 
 // are initialized by their constructor at compile time.
    static Servo servo(servoPin,TIM5,GPIO_AF2_TIM5,TIM_CHANNEL_3);
    

  while(1){
    //thurn servo shaft in the following sequence repeatedly;
    //MID-LEFT-RIGHT
     servo.TurnShaft(SERVO_MIDPOSITION);
     HAL_Delay(1000);
     servo.TurnShaft(SERVO_LESFPOSITION);
     HAL_Delay(1000);
     servo.TurnShaft(SERVO_RIGHTPOSITION);
     HAL_Delay(1000);
  }
}

extern "C" void SysTick_Handler(void)
{
    HAL_IncTick();
}