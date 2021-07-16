#include "ESP8266WiFi.h"
#include "WiFiClient.h"
#include <ESP8266HTTPClient.h>

class SpotifyAPI
{
public:
  void init();
  bool next_track();
  bool pause();
  bool resume();
private:
  typedef enum e_action {NEXT, PAUSE, RESUME} t_action;
  const char * ssid = "Kronenberg";
  const char * password = "sdfhnedro654jtr34";
  const char * url = "http://192.168.2.46:5000/spotify/pause";
  char * ip_address = "192.168.2.46:5000/";
  char * protocol = "http://";
  char * getRequest(t_action action);
  char acRequest[50] = {};
};
