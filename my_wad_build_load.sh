./build_whd_gen/src/whd_gen/whd_gen wad/DOOM2.WAD doom2.whd -no-super-tiny
/usr/local/bin/picotool info -a
#sudo /usr/local/bin/picotool load -v -t bin doom2.whd -o 0x10048000
# for pio usb
/usr/local/bin/picotool load -v -t bin doom2.whd -o  0x10050000
/usr/local/bin/picotool info -a
