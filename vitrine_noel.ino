// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       vitrine_noel.ino
    Created:	21/11/2019 17:25:05
    Author:     DESKTOP-IJFTLEV\fauch
*/
#define LED_BLUE_1 13
#define LED_BLUE_2 12
#define LED_BLUE_3 11
#define LED_WHITE_1 10
#define LED_WHITE_2 9
#define LED_WHITE_3 8
#define LED_WHITE_4 7
#define LED_RED_LINE 6
#define LED_WHITE_LINE 5
#define LED_YELLOW_SOLO 4
#define LED_RED_SOLO 3

byte state_led = LOW;
void setup()
{
	pinMode(LED_BLUE_1, OUTPUT);
	pinMode(LED_BLUE_2, OUTPUT);
	pinMode(LED_BLUE_3, OUTPUT);
	pinMode(LED_WHITE_1, OUTPUT);
	pinMode(LED_WHITE_2, OUTPUT);
	pinMode(LED_WHITE_3, OUTPUT);
	pinMode(LED_RED_LINE, OUTPUT);
	pinMode(LED_WHITE_4, OUTPUT);
	pinMode(LED_WHITE_LINE, OUTPUT);
	pinMode(LED_RED_SOLO, OUTPUT);
	pinMode(LED_YELLOW_SOLO, OUTPUT);

	
	
}

// Add the main program code into the continuous loop() function
void loop()
{
	state_led = !state_led;
	digitalWrite(LED_BLUE_1, state_led);
	digitalWrite(LED_BLUE_2, state_led);
	digitalWrite(LED_BLUE_3, state_led);
	digitalWrite(LED_WHITE_1, state_led);
	digitalWrite(LED_WHITE_2, state_led);
	digitalWrite(LED_WHITE_3, state_led);
	digitalWrite(LED_WHITE_4, state_led);
	digitalWrite(LED_RED_LINE, state_led);
	digitalWrite(LED_RED_SOLO, state_led);
	digitalWrite(LED_WHITE_LINE, state_led);
	digitalWrite(LED_YELLOW_SOLO, state_led);
	
	delay(500);

}
