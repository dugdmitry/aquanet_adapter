#!/bin/sh
# Example of starting all modules
# Modify the script as you needed
#                        by James

# start the protocol stack
../aquanet_bin/aquanet-stack &
sleep 2
# start the VMDM
#/home/ubuntu/aquanet/trunk/bin/aquanet-vmdc 10.13.13.101 2021 1 10 10 10 &
#../aquanet_bin/aquanet-vmdc 130.160.143.6 2102 1 10 10 10 &
#../aquanet_bin/aquanet-vmdc 100.119.195.86 2021 1 10 10 10 &
../aquanet_bin/aquanet-gatech &
sleep 4
# start the MAC
#../aquanet_bin/aquanet-bcmac &
../aquanet_bin/aquanet-trumac &
sleep 2
# start the routing protocol
../aquanet_bin/aquanet-sroute &
sleep 2
# start the transport layer
../aquanet_bin/aquanet-tra &

#for the modem test: disable for the actual demo
#../aquanet_bin/aquanet-tx-poi 1 2 0.008 0 &
