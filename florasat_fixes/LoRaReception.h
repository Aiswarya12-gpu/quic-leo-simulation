#ifndef __LORA_RECEPTION_H
#define __LORA_RECEPTION_H

#include "inet/common/INETDefs.h"

using namespace inet;

class LoRaReception
{
  protected:
    simtime_t startTime;
    simtime_t endTime;
    double carrierFrequency;
    double bandwidth;

  public:
    LoRaReception(simtime_t start, simtime_t end)
        : startTime(start), endTime(end)
    {
        carrierFrequency = 868e6; // Hz
        bandwidth = 125e3;        // Hz
    }

    simtime_t getStartTime() const { return startTime; }
    simtime_t getEndTime() const { return endTime; }

    double getLoRaCF() const { return carrierFrequency; }
    double getBandwidth() const { return bandwidth; }
};

#endif
