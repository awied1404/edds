#include "arduino.h"
#include "Spotify.h"
#include "EDDS_HW.h"
#include "config.h"
class EDDS
{
  public:
    void init();
    void nextSong();
    int isWinner();
  private:
    typedef enum e_remoteCommands {INVALID, ZERO, ONE} remoteCommands;
    Spotify spotify;
    EDDS_HW hw; 
    bool bDebug = true;
    int aiScorePlayers[NUMBER_PLAYERS] = {};
    remoteCommands getRemoteCommand(int iCodedCommand);
    
};
