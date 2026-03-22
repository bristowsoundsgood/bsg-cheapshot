//
// Created by Joe Bristow on 11/03/2026.
//

#ifndef CLIPDSP_H
#define CLIPDSP_H

// https://www.kvraudio.com/forum/viewtopic.php?t=195315
// https://www.kvraudio.com/forum/viewtopic.php?t=449705
// https://www.kvraudio.com/forum/viewtopic.php?t=466276
// https://forum.juce.com/t/help-soft-clipping-algorythm/63843
// https://www.youtube.com/watch?v=_0ys155xv1Q
// https://www.youtube.com/watch?v=rnvEA7SOaSA

class ClipDSP {
public:
     void processBlock(float* channelData, int blockSize) noexcept;
};



#endif //CLIPDSP_H
