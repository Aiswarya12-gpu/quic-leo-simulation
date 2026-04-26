#include "QuicConnection.h"

Define_Module(QuicConnection);

void QuicConnection::initialize()
{
    socket.setOutputGate(gate("udpOut"));
    socket.bind(4433);

    EV_INFO << "QUIC Connection Initialized\n";
}

void QuicConnection::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(), "handover") == 0) {
        handleHandoverEvent();
        delete msg;
        return;
    }

    Packet *pkt = check_and_cast<Packet *>(msg);
    EV_INFO << "QUIC received packet\n";

    delete pkt;
}

void QuicConnection::sendPacket(Packet *pkt)
{
    EV_INFO << "QUIC sending packet\n";
    socket.send(pkt);
}

void QuicConnection::handleHandoverEvent()
{
    EV_INFO << "LEO Handover detected\n";

    // Reset RTT and congestion window
    rtt = 0;
    cwnd = 10;

    EV_INFO << "RTT + CWND Reset\n";
}
