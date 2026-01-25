//
// Created by Joe Bristow on 25/01/2026.
//

#ifndef STEREOWIDTHDSP_H
#define STEREOWIDTHDSP_H

/*
 * - Takes L/R channels.
 * - Calculate middle signal.
 * - Calculate side signal.
 * - Amplify side by parameter coeffient.
 */


class StereoWidthDSP {
public:
    void processBlock(float* channelData, const int numSamples);
};



#endif //STEREOWIDTHDSP_H
