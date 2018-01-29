#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/brbos.kernel isodir/boot/brbos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "brbos" {
	multiboot /boot/brbos.kernel
}
EOF
grub-mkrescue -o brbos.iso isodir
