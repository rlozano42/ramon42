#!/usr/bin/env bash
#reiniciar la ip de virtualbox​

function reset_dhcp() {
	echo "🧼 Cleaning DHCP ..."
	kill -9 $(ps aux | grep -i "vboxsvc\|vboxnetdhcp" | awk '{print $2}') 2>/dev/null
​
	if [[ -f ~/Library/VirtualBox/HostInterfaceNetworking-vboxnet0-Dhcpd.leases ]] ; then
    rm  ~/Library/VirtualBox/HostInterfaceNetworking-vboxnet0-Dhcpd.leases
	fi
	echo  "🧙‍♂️ Magic has been done"
}
​
reset_dhcp 