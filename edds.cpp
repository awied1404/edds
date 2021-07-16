#include "edds.h"
#include <IRremote.h>

void EDDS::init_hardware()
{
    pinMode(LED_PLAYER_ONE, OUTPUT);
    pinMode(LED_PLAYER_TWO, OUTPUT);
    pinMode(LED_PLAYER_THREE, OUTPUT);
    pinMode(BUT_PLAYER_ONE, INPUT_PULLUP);
    pinMode(BUT_PLAYER_TWO, INPUT_PULLUP);
    pinMode(BUT_PLAYER_THREE, INPUT_PULLUP);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);

    if(this->bDebug == true)
    {
      Serial.begin(115200);
      Serial.println("Hardware initialized correctly");
    }
}

void EDDS::init()
{
  this->init_hardware();
}

EDDS::remoteCommands EDDS::getRemoteCommand(int iCodedCommand)
{
  remoteCommands returnCommand = INVALID;
  switch(iCodedCommand)
  {
    case 0x16:
      returnCommand = ZERO;
      break;
    case 0xC:
      returnCommand = ONE;
      break;

  }
  return returnCommand;
}

int EDDS::receiveRemoteCommand()
{
  int iReturnCommand = -1;
  while(true)
  {
    if(IrReceiver.decode())
    {
      iReturnCommand = IrReceiver.decodedIRData.command;
      IrReceiver.resume(); // Enable receiving of the next value
      break;
    }
  }
  return iReturnCommand;
}
