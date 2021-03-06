// ParticleFireExplosion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include "Screen.h"

using namespace std;
using namespace sdlScreen;


int main(int argc, char *args[])
{
  (void) argc;
  (void) args;

  Screen screen;
  if (screen.init() == false) {
    cout << "Error initialising SDL." << endl;
  }


  while(true) {
    if (!screen.processEvents()) {
      break;
    }
  }

  screen.exit();
  return 0;
}

