#1/bin/sh

ifconfig | grep ether | cut -c 7- | tr -d ' '

