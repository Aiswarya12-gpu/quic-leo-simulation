#ifndef __LORA_RECEIVER_H
#define __LORA_RECEIVER_H

#include "inet/physicallayer/wireless/common/analogmodel/packetlevel/ScalarSnir.h"

using namespace inet;

class LoRaReceiver
{
  protected:
    double sensitivity = -120; // dBm

  public:
    LoRaReceiver() {}

    bool isReceptionSuccessful(double snir)
    {
        if (snir > sensitivity) {
            EV_INFO << "LoRa reception successful\n";
            return true;
        }
        else {
            EV_WARN << "LoRa reception failed (low SNIR)\n";
            return false;
        }
    }
};

#endif
