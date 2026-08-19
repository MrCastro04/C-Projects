#include "Emotion.h"

#include <iostream>
#include <string>

Emotion::Emotion(EEmotions emotion)
{
    _currentEmotion = emotion;
}

FString Emotion::GetEmotionName() const
{
    switch (_currentEmotion)
    {
    case EEmotions::ANGRY: return "ANGRY";
    case EEmotions::JOY: return "JOY";
    case EEmotions::SAD: return "SAD";

    default: return "UNKNOWN";
    }
}
