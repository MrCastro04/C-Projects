#include "EmotionGame.h"

#include <iostream>
#include <ostream>

void EmotionGame::Play()
{
    int emotionsCount = 3;

    CreateEmotions(emotionsCount);
}

void EmotionGame::CreateEmotions(int emotionsCount)
{
    for (int i = 0; i < emotionsCount; i++)
    {
        EEmotions eEmotion = static_cast<EEmotions>(i); // каст в обьект <T> (с чего, с int);
        Emotion* emotion = new Emotion(eEmotion);

        std::cout << "Created new emotion - " << emotion->GetEmotionName() << '\n';
        
        _emotions.emplace_back(*emotion);
        
        std::cout << "Emotion was added to list" << '\n';
    }
}
