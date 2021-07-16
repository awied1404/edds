#define LED_PLAYER_ONE 50
#define LED_PLAYER_TWO 52
#define LED_PLAYER_THREE 53
#define BUT_PLAYER_ONE 49
#define BUT_PLAYER_TWO 48
#define BUT_PLAYER_THREE 47
#define IR_RECEIVE_PIN 2
#include "config.h"
#include "arduino.h"
class EDDS_HW
{
public:
    void init();
    void nextSong();
    int getPlayerToAnswer();
    int receiveRemoteCommand();
    void resetLEDs();
    bool atLeastOnePlayerEnabled();
private:
    bool aiPlayerEnabled[NUMBER_PLAYERS] = {};
    int LED_PINS[NUMBER_PLAYERS] = {LED_PLAYER_ONE, LED_PLAYER_TWO, LED_PLAYER_THREE};
    int BUTTON_PINS[NUMBER_PLAYERS] = {BUT_PLAYER_ONE, BUT_PLAYER_TWO, BUT_PLAYER_THREE};
    int iPlayersDisabled = 0;
};