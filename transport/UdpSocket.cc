#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "inet/common/ModuleAccess.h"
#include "inet/physicallayer/contract/packetlevel/IRadioMedium.h"

using namespace inet;

void UdpSocket::send(Packet *packet)
{
    EV_INFO << "UDP: Sending packet with LEO-aware delay\n";

    // -------------------------------
    // 🔴 NEW: Get RadioMedium
    // -------------------------------
    cModule *radioMediumModule = getSimulation()->getModuleByPath("radioMedium");

    simtime_t propagationDelay = 0;

    if (radioMediumModule != nullptr) {
        EV_INFO << "RadioMedium found → applying dynamic delay\n";

        // Example delay (can be replaced by real FloRaSat delay)
        propagationDelay = uniform(0.02, 0.15);  // 20ms – 150ms
    }
    else {
        EV_WARN << "RadioMedium not found → using default delay\n";
        propagationDelay = 0.01;
    }

    // -------------------------------
    // 🔴 ORIGINAL UDP SEND (MODIFIED)
    // -------------------------------
    sendDelayed(packet, propagationDelay, "udpOut");

    EV_INFO << "Packet sent with delay: " << propagationDelay << endl;
}
