#include "inet/transportlayer/contract/udp/UdpSocket.h"

using namespace inet;

class QuicSocket
{
  private:
    UdpSocket udpSocket;

  public:
    void setOutputGate(cGate *gate) {
        udpSocket.setOutputGate(gate);
    }

    void bind(int port) {
        udpSocket.bind(port);
    }

    void connect(L3Address addr, int port) {
        udpSocket.connect(addr, port);
    }

    void send(Packet *pkt) {
        udpSocket.send(pkt);
    }
};
