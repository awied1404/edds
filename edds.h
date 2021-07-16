#define LED_PLAYER_ONE 50
#define LED_PLAYER_TWO 52
#define LED_PLAYER_THREE 53
#define BUT_PLAYER_ONE 49
#define BUT_PLAYER_TWO 48
#define BUT_PLAYER_THREE 47
#define IR_RECEIVE_PIN 2

#include "arduino.h"

class EDDS
{
  public:
    void init();
    void nextSong();
    int isWinner();
  private:
    typedef enum e_remoteCommands {INVALID, ZERO, ONE} remoteCommands;
    bool bDebug = true;
    int aiScorePlayers[3] = {};
    void init_hardware();
    remoteCommands getRemoteCommand(int iCodedCommand);
    int receiveRemoteCommand();
};
