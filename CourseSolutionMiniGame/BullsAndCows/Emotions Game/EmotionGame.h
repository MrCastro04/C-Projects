#pragma once

#include <vector>
#include "Emotion.h"

using EmotionsList = std::vector<Emotion>; 

class EmotionGame
{
public:
    void Play();
    
    private:
    EmotionsList _emotions;
    
    void CreateEmotions(int emotionsCount);
};
