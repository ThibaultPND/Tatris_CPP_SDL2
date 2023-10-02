#ifndef __SOUND_H__
    #define __SOUND_H__

    #include <iostream>
    #include <SDL2/SDL.h>
    #include <cmath>

    #define SOUND_DURATION 2
    #define MAX_FREQUENCY 2000
    #define BASE_FREQUENCY 100


    SDL_AudioDeviceID InitAudioSystem();
    void PlaySound(int input, SDL_AudioDeviceID audioDevice);
    void QuitAudioSystem(SDL_AudioDeviceID audioDevice);

#endif //__SOUND_H__