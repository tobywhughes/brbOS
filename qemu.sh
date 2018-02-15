#!/bin/sh
set -e
. ./iso.sh

qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom brbos.iso -serial file:serial.log

if [ $# -eq 1 ]
then
	if [ "$1" = "-nc" ]
	then
		echo "SKIPPED CLEANING"	
	fi	
else
	. ./clean.sh
fi
