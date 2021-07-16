#include "edds.h"

EDDS edds;

void setup() {
  const int buzzer = 8;
  pinMode(buzzer, OUTPUT);
  tone(buzzer, 4000);
  delay(1000);
  noTone(buzzer);

  
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
