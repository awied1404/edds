#include "edds.h"

EDDS edds;

void setup() {
  // put your setup code here, to run once:
  edds.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(LED_PLAYER_ONE, !digitalRead(BUT_PLAYER_ONE));
  //digitalWrite(LED_PLAYER_TWO, !digitalRead(BUT_PLAYER_TWO));
  //digitalWrite(LED_PLAYER_THREE, !digitalRead(BUT_PLAYER_THREE));
  if (edds.isWinner() == -1)
  {
    edds.nextSong();
    Serial.println("Exited edds next song");
  }
}
