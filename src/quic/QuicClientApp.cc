#include "inet/applications/base/ApplicationBase.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/packet/chunk/ByteCountChunk.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "QuicConnection.h"

using namespace inet;

class QuicClientApp : public ApplicationBase
{
  protected:
    cMessage *sendTimer = nullptr;
    int packetSize = 1024;

    virtual void initialize(int stage) override
    {
        if (stage == INITSTAGE_APPLICATION_LAYER) {
            sendTimer = new cMessage("sendTimer");
            scheduleAt(simTime() + 1, sendTimer);
        }
    }

    virtual void handleMessageWhenUp(cMessage *msg) override
    {
        if (msg == sendTimer) {
            Packet *pkt = new Packet("QUIC-Data");

            pkt->insertAtBack(makeShared<ByteCountChunk>(B(packetSize)));

            send(pkt, "out");  // to QUIC layer

            scheduleAt(simTime() + 0.05, sendTimer);
        }
    }
};

Define_Module(QuicClientApp);
