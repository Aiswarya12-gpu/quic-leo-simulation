#include "inet/applications/base/ApplicationBase.h"
#include "inet/common/packet/Packet.h"

using namespace inet;

class QuicServerApp : public ApplicationBase
{
  protected:
    virtual void handleMessageWhenUp(cMessage *msg) override
    {
        Packet *pkt = check_and_cast<Packet *>(msg);

        EV_INFO << "Server received packet: " << pkt->getName() << endl;

        delete pkt;
    }
};

Define_Module(QuicServerApp);
