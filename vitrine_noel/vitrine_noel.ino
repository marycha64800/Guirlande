// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
  Name:       vitrine_noel.ino
  Created:  21/11/2019 17:25:05
  Author:     DESKTOP-IJFTLEV\fauch
*/




// Guirlande 
constexpr auto LED_BLUE_1 = 13;
constexpr auto LED_BLUE_2 = 12;
constexpr auto LED_BLUE_3 = 11;
constexpr auto LED_WHITE_1 = 10;
constexpr auto LED_WHITE_2 = 9;
constexpr auto LED_WHITE_3 = 8;
constexpr auto LED_WHITE_4 = 7;
constexpr auto LED_RED_LINE = 6;
constexpr auto LED_WHITE_LINE = 5;
constexpr auto LED_YELLOW_SOLO = 4;
constexpr auto LED_RED_SOLO = 3;

const unsigned int INTERVAL_BLUE_LED = 500;
const unsigned int INTERVAL_WHITE_LED = 10000;




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
	pinMode(LED_YELLOW_SOLO, OUTPUT);
	pinMode(LED_RED_SOLO, OUTPUT);
	Serial.begin(9600);

	

}


void loop()
{
	blink_blue();
	blink_white();
	digitalWrite(LED_RED_LINE, HIGH);
	digitalWrite(LED_WHITE_LINE, HIGH);
	blink_fire();
}

void blink_blue()
{
	static unsigned long previous_millis = 0;
	static int state_pin = LOW;
	unsigned long current_millis = millis();
	static int lag = 0;

	if (current_millis - previous_millis >= INTERVAL_BLUE_LED)
	{
		switch (lag)
		{
		case 0:
			digitalWrite(LED_BLUE_1, !state_pin);
			digitalWrite(LED_BLUE_2, state_pin);
			digitalWrite(LED_BLUE_3, state_pin);
			lag++;
			break;
		case 1:
			digitalWrite(LED_BLUE_1, state_pin);
			digitalWrite(LED_BLUE_2, !state_pin);
			digitalWrite(LED_BLUE_3, state_pin);
			lag++;
			break;
		case 2:
			digitalWrite(LED_BLUE_1, state_pin);
			digitalWrite(LED_BLUE_2, state_pin);
			digitalWrite(LED_BLUE_3, !state_pin);
			lag++;
			break;

		default:
			lag = 0;
			break;
		}
		previous_millis = current_millis;
	}

}

int random_interval()
{
	static int first = 0;

	if (first == 0)
	{
		srand(millis());
		first = 1;
	}
	unsigned long interval = random();

	return interval;
}

void blink_white()
{
	static unsigned long previous_millis = 0;
	static int state_pin = LOW;
	unsigned long current_millis = millis();
	static int scenario = 0;

	if (current_millis - previous_millis >= random_interval() % (INTERVAL_WHITE_LED - random()) + INTERVAL_WHITE_LED)
	{
		switch (scenario)
		{
		case 0:
			digitalWrite(LED_WHITE_1, !state_pin);
			digitalWrite(LED_WHITE_2, state_pin);
			digitalWrite(LED_WHITE_3, state_pin);
			digitalWrite(LED_WHITE_4, !state_pin);
			scenario = random_interval() % 11;
			break;
		case 1:
			digitalWrite(LED_WHITE_1, state_pin);
			digitalWrite(LED_WHITE_2, !state_pin);
			digitalWrite(LED_WHITE_3, !state_pin);
			digitalWrite(LED_WHITE_4, state_pin);
			scenario = random_interval() % 11;
			break;
		case 2:
			digitalWrite(LED_WHITE_1, !state_pin);
			digitalWrite(LED_WHITE_2, !state_pin);
			digitalWrite(LED_WHITE_3, !state_pin);
			digitalWrite(LED_WHITE_4, !state_pin);
			scenario = random_interval() % 11;
			break;
		case 3:
			digitalWrite(LED_WHITE_1, state_pin);
			digitalWrite(LED_WHITE_2, state_pin);
			digitalWrite(LED_WHITE_3, state_pin);
			digitalWrite(LED_WHITE_4, state_pin);
			scenario = random_interval() % 11;
		case 4:
			digitalWrite(LED_WHITE_1, !state_pin);
			digitalWrite(LED_WHITE_2, state_pin);
			digitalWrite(LED_WHITE_3, !state_pin);
			digitalWrite(LED_WHITE_4, !state_pin);
			scenario = random_interval() % 11;
			break;
		case 5:
			digitalWrite(LED_WHITE_1, !state_pin);
			digitalWrite(LED_WHITE_2, state_pin);
			digitalWrite(LED_WHITE_3, state_pin);
			digitalWrite(LED_WHITE_4, state_pin);
			scenario = random_interval() % 11;
			break;
		case 6:
			digitalWrite(LED_WHITE_1, state_pin);
			digitalWrite(LED_WHITE_2, state_pin);
			digitalWrite(LED_WHITE_3, state_pin);
			digitalWrite(LED_WHITE_4, !state_pin);
			scenario = random_interval() % 11;
			break;
		case 7:
			digitalWrite(LED_WHITE_1, state_pin);
			digitalWrite(LED_WHITE_2, state_pin);
			digitalWrite(LED_WHITE_3, !state_pin);
			digitalWrite(LED_WHITE_4, state_pin);
			scenario = random_interval() % 11;
			break;
		case 8:
			digitalWrite(LED_WHITE_1, state_pin);
			digitalWrite(LED_WHITE_2, !state_pin);
			digitalWrite(LED_WHITE_3, state_pin);
			digitalWrite(LED_WHITE_4, state_pin);
			scenario = random_interval() % 11;
			break;
		case 9:
			digitalWrite(LED_WHITE_1, state_pin);
			digitalWrite(LED_WHITE_2, !state_pin);
			digitalWrite(LED_WHITE_3, state_pin);
			digitalWrite(LED_WHITE_4, !state_pin);
			scenario = random_interval() % 11;
			break;
		case 10:
			digitalWrite(LED_WHITE_1, !state_pin);
			digitalWrite(LED_WHITE_2, state_pin);
			digitalWrite(LED_WHITE_3, !state_pin);
			digitalWrite(LED_WHITE_4, state_pin);
			scenario = random_interval() % 11;
			break;

		default:
			scenario = 0;
			break;
		}
		previous_millis = current_millis;
	}

}

void blink_fire()
{
	static unsigned long previous_millis = 0;
	static int state_pin = LOW;
	unsigned long current_millis = millis();

	if (current_millis - previous_millis >= random_interval() % 15)
	{
		if (random_interval() % 2)
		{
			digitalWrite(LED_RED_SOLO, !state_pin);
			digitalWrite(LED_YELLOW_SOLO, state_pin);
		}
		else
		{
			digitalWrite(LED_RED_SOLO, state_pin);
			digitalWrite(LED_YELLOW_SOLO, !state_pin);

		}
	}


}