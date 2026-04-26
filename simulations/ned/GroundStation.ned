package simulations.ned;

import inet.node.inet.StandardHost;

module GroundStation extends StandardHost
{
    parameters:
        @display("i=device/pc");

    submodules:
        app[1]: <default("QuicClientApp")> like inet.applications.contract.IApp {
            @display("p=100,100");
        }
}
