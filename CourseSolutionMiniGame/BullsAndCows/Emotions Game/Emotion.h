#pragma once
#include <string>

using FString = std::string;

enum class EEmotions
{
    SAD,
    ANGRY,
    JOY,
};

class Emotion
{
public:
    Emotion (EEmotions emotion);
    
    FString GetEmotionName() const;

private:
    EEmotions _currentEmotion;
};
