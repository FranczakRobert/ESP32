#include "Servo.hpp"

Servo::Servo(){printf("Hi! I'm SERVO! \n");};
Servo::~Servo(){};


void Servo::run()
{
    // TIMERS
    mcpwm_timer_config_t timer;
    mcpwm_timer_handle_t  retTimer;
    mcpwm_new_timer(&timer,&retTimer);
    
}
