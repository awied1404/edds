#include "spotify_api.h"
SpotifyAPI sAPI;
void setup() {
  sAPI.init();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int iAvailableBytes = Serial.available();
  char acCommand[20] = {};
  if(iAvailableBytes)
  {
    int charsRead = Serial.readBytesUntil('\n', acCommand, sizeof(acCommand) - 1);
    Serial.print("pause test");
    Serial.println(strcmp(acCommand, "PAUSE"));
    Serial.print("resume test");
    Serial.println(strcmp(acCommand, "RESUME"));
    if (strstr(acCommand, "START"))
    {
      Serial.println("Starting ");
      sAPI.startEDDS();
    }
    else if (strstr(acCommand, "PAUSE"))
    {
      Serial.println("Pause");
      sAPI.pause(); 
    }
    else if (strstr(acCommand, "RESUME"))
    {
      Serial.println("Resume");
      sAPI.resume();
    }
    else if (strstr(acCommand, "NEXT"))
    {
      Serial.println("next");
      sAPI.next_track();
    }
    Serial.println(acCommand);
  }
}
