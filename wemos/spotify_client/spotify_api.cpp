#include "spotify_api.h"

void SpotifyAPI::init()
{
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

bool SpotifyAPI::next_track()
{
  HTTPClient client;
  char * url = getRequest(NEXT);
  client.begin(url);
  int status = client.GET();
  memset(acRequest, 20, 0);
  return true;
}

bool SpotifyAPI::pause()
{
  HTTPClient client;
  char * url = getRequest(PAUSE);
  client.begin(url);
  int status = client.GET();
  memset(acRequest, 20, 0);
  return true;
}

bool SpotifyAPI::resume()
{
  HTTPClient client;
  char * url = getRequest(RESUME);
  client.begin(url);
  int status = client.GET();
  memset(acRequest, 20, 0);
  return true;
}

char * SpotifyAPI::getRequest(t_action action)
{
  char acAction[20] = {};
  switch (action)
  {
    case NEXT:
      snprintf(acAction, 20, "%s", "spotify/next_song");
      break;
    case PAUSE:
      snprintf(acAction, 20, "%s", "spotify/pause");
      break;
    case RESUME:
      snprintf(acAction, 20, "%s", "spotify/resume");
      break;
  }
  snprintf(acRequest, 50, "%s%s%s", this->protocol, this->ip_address, acAction);
  return acRequest;
}
