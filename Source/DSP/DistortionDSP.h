//
// Created by Joe Bristow on 25/01/2026.
//

#ifndef DISTORTIONDSP_H
#define DISTORTIONDSP_H



class DistortionDSP {
public:
    float m_drive;
    void processBlock(float* channelData, const int numSamples) const;
};


#endif //DISTORTIONDSP_H
