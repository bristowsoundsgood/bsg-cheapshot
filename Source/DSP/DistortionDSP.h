//
// Created by Joe Bristow on 25/01/2026.
//

#ifndef DISTORTIONDSP_H
#define DISTORTIONDSP_H

#include <cmath>
#include <juce_audio_basics/juce_audio_basics.h>

class DistortionDSP {
public:
    void processBlock(float* channelData, int numSamples) const;
    void setDrive(float driveParam);
    [[nodiscard]] float getDrive() const;
private:
    float m_drive {  };
    float m_minDrive { 0.0f };
    float m_maxDrive { 0.04f };
};


#endif //DISTORTIONDSP_H
