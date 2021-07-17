#include "Spotify.h"

void Spotify::pauseSong()
{
    Serial.println("PAUSE");
}

void Spotify::playNextSong()
{
    Serial.println("NEXT");
}

void Spotify::resumeSong()
{
    Serial.println("RESUME");
}

void Spotify::init()
{
}

void Spotify::start()
{
    Serial.println("START");
}