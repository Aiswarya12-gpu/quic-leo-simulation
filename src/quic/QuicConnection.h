#ifndef __QUIC_CONNECTION_H
#define __QUIC_CONNECTION_H

#include "inet/common/INETDefs.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "inet/common/packet/Packet.h"

using namespace inet;

class QuicConnection : public cSimpleModule
{
  protected:
    UdpSocket socket;

    simtime_t rtt = 0;
    int cwnd = 10;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    void sendPacket(Packet *pkt);
    void handleHandoverEvent();

};

#endif
