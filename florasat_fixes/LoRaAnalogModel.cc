#include <omnetpp.h>

using namespace omnetpp;

class LoRaAnalogModel : public cSimpleModule
{
  protected:
    double noiseLevel;

  protected:
    virtual void initialize() override
    {
        noiseLevel = par("noiseLevel").doubleValue();
        EV_INFO << "LoRaAnalogModel initialized\n";
    }

    virtual void handleMessage(cMessage *msg) override
    {
        EV_INFO << "Processing signal in analog model\n";

        // Simulate noise effect
        double signalPower = uniform(-100, -50);
        double snir = signalPower - noiseLevel;

        EV_INFO << "SNIR calculated: " << snir << endl;

        delete msg;
    }
};

Define_Module(LoRaAnalogModel);
