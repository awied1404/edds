#include "edds.h"

void EDDS::init()
{
  this->hw.init();
  this->spotify.init();
  this->spotify.start();
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

void EDDS::nextSong()
{
  spotify.playNextSong();
  hw.nextSong();
  int iPlayerAnswered = hw.getPlayerToAnswer();
  spotify.pauseSong();
  while(true)
  {
    int iRemoteCommand = hw.receiveRemoteCommand();
    remoteCommands command = getRemoteCommand(iRemoteCommand);
    if(command == ONE) // player answered correctly
    {
      aiScorePlayers[iPlayerAnswered] += 1;
      break;
    } 
    else 
    {
      spotify.resumeSong();
      hw.resetLEDs();
      if(hw.atLeastOnePlayerEnabled() == false)
      {
        break;
      }
      iPlayerAnswered = hw.getPlayerToAnswer();
      spotify.pauseSong();
    }
  }
}

int EDDS::isWinner()
{
  for(int i = 0; i < NUMBER_PLAYERS; i++)
  {
    if(aiScorePlayers[i] == POINTS_TO_WIN)
    {
      return i + 1;
    }
  }
  return -1;
}