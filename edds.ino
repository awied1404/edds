#include "edds.h"

EDDS edds;

void setup() {
  // put your setup code here, to run once:
  edds.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (edds.isWinner() == -1)
  {
    edds.nextSong();
    delay(2000); // delay between two songs to guess
    Serial.println("Exited edds next song");
  }
  else{
    Serial.print("And the Winner is: Player ");
    Serial.println(edds.isWinner());
    delay(3000);
  }
}
