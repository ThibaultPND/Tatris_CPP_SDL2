#include <sound2.h>
// Fonction pour initialiser le système audio
SDL_AudioDeviceID InitAudioSystem() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        throw std::runtime_error("Erreur lors de l'initialisation de SDL2 : " + std::string(SDL_GetError()));
    }

    // Configuration des spécifications audio
    SDL_AudioSpec audioSpec;
    audioSpec.freq = 44100;        // Fréquence audio (Hz)
    audioSpec.format = AUDIO_S16;  // Format audio 16 bits signé
    audioSpec.channels = 1;        // 1 canal (mono)
    audioSpec.samples = 1024;      // Taille du tampon audio
    audioSpec.callback = nullptr;  // Fonction de rappel (sera définie plus tard)
    audioSpec.userdata = nullptr;  // Données utilisateur (si nécessaire)

    // Ouvrir le périphérique audio
    SDL_AudioDeviceID audioDevice = SDL_OpenAudioDevice(nullptr, 0, &audioSpec, nullptr, 0);
    if (audioDevice == 0) {
        throw std::runtime_error("Erreur lors de l'ouverture du périphérique audio : " + std::string(SDL_GetError()) );
    }

    // Commencer la lecture audio
    SDL_PauseAudioDevice(audioDevice, 0);
    return audioDevice;
}

// Fonction pour jouer un son en fonction de l'entrée (0 à 800)
void PlaySound(int input, SDL_AudioDeviceID audioDevice) {
    int frequency = BASE_FREQUENCY + (input * (MAX_FREQUENCY - BASE_FREQUENCY) / 800);
    double amplitude = 32767.0;
    double phaseIncrement = 2.0 * M_PI * frequency / 44;
    Sint16 samples[SOUND_DURATION * 44];
    for (int i = 0; i < SOUND_DURATION * 44; ++i) {
        samples[i] = static_cast<Sint16>(amplitude * sin(phaseIncrement * i));
    }
    // Jouer le son
    SDL_QueueAudio(audioDevice, samples, sizeof(samples));
}

// Fonction pour arrêter le système audio
void QuitAudioSystem(SDL_AudioDeviceID audioDevice) {
    // Arrêter la lecture audio
    SDL_PauseAudioDevice(audioDevice, 1);

    // Fermer le périphérique audio
    SDL_CloseAudioDevice(audioDevice);

    // Libérer SDL2
    SDL_Quit();
}
