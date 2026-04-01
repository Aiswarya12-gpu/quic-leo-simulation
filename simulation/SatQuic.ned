package satquic;

import inet.node.inet.StandardHost;
import inet.node.inet.Router;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;

network SatQuicNet
{
    parameters:
        int numSats = default(10);
        int numGS = default(20);

    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=100,50");
        }

        sat[numSats]: Router {
            @display("i=device/satellite;p=150+index*100,100");
        }

        gs[numGS]: StandardHost {
            @display("i=device/laptop;p=150+index*100,400");
        }

    connections allowunconnected:
        // Satellite ring
        for i=0..numSats-2 {
            sat[i].pppg++ <--> sat[i+1].pppg++;
        }
        sat[numSats-1].pppg++ <--> sat[0].pppg++;

        // Ground stations to satellites
        for i=0..numGS-1 {
            gs[i].pppg++ <--> sat[i % numSats].pppg++;
        }
}
