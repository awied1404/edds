#include "EDDS_HW.h"
#include <IRremote.h>


void EDDS_HW::init()
{
    pinMode(LED_PLAYER_ONE, OUTPUT);
    pinMode(LED_PLAYER_TWO, OUTPUT);
    pinMode(LED_PLAYER_THREE, OUTPUT);
    pinMode(BUT_PLAYER_ONE, INPUT_PULLUP);
    pinMode(BUT_PLAYER_TWO, INPUT_PULLUP);
    pinMode(BUT_PLAYER_THREE, INPUT_PULLUP);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);

    for (int i = 0; i<NUMBER_PLAYERS; i++)
    {
        aiPlayerEnabled[i] = true;
    }

    Serial.begin(115200);
    Serial.println("Hardware initialized correctly");
}

int EDDS_HW::receiveRemoteCommand()
{
    IrReceiver.enableIRIn();
    IrReceiver.resume(); // Enable receiving of the next value
    int iReturnCommand = -1;
    while(true)
    {
      if(IrReceiver.decode())
      {
          iReturnCommand = IrReceiver.decodedIRData.command;
          break;
      }
    }
    IrReceiver.disableIRIn();
    return iReturnCommand;
}

int EDDS_HW::getPlayerToAnswer()
{
    unsigned long lTimeOut = 35000L;
    long lStartTime = millis();
    while(millis() - lStartTime < lTimeOut)
    {
        for(int i = 0; i < NUMBER_PLAYERS; i++)
        {
            if (digitalRead(BUTTON_PINS[i]) == LOW && aiPlayerEnabled[i])
            {
                aiPlayerEnabled[i] = false;
                iPlayersDisabled += 1;
                digitalWrite(LED_PINS[i], HIGH);   
                return i;
            }
        }

    }
    return -1; // no player guessed a song
}

void EDDS_HW::nextSong()
{
    for (int i = 0; i<NUMBER_PLAYERS; i++)
    {
        aiPlayerEnabled[i] = true;
        digitalWrite(LED_PINS[i], LOW);
    }
    iPlayersDisabled = 0;
}

void EDDS_HW::resetLEDs()
{
    for (int i = 0; i<NUMBER_PLAYERS; i++)
    {
        digitalWrite(LED_PINS[i], LOW);
    }
}

bool EDDS_HW::atLeastOnePlayerEnabled()
{
    return !(this->iPlayersDisabled == NUMBER_PLAYERS);
}