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
  while(true)
  {
    int iPlayerAnswered = hw.getPlayerToAnswer();
    if (iPlayerAnswered == -1)
    {
      break;
    }
    spotify.pauseSong();

    remoteCommands command;
    do
    {
      int iRemoteCommand = hw.receiveRemoteCommand();
      command= getRemoteCommand(iRemoteCommand);
    } while (command == INVALID);
    
    if(command == ONE) // player answered correctly
    {
      aiScorePlayers[iPlayerAnswered] += 1;
      break;
    } 
    else 
    {
      hw.resetLEDs();
      if(hw.atLeastOnePlayerEnabled() == false)
      {
        break;
      }
      else
      {
        spotify.resumeSong();
      }
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