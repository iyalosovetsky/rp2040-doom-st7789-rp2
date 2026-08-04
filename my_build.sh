rm -rf build_pico/
mkdir  build_pico/
export CMAKE_POLICY_VERSION_MINIMUM=3.5
cd build_pico

#cmake -DCMAKE_BUILD_TYPE=MinSizeRel -DPICO_BOARD=pico -DPICO_SDK_PATH=../pico/pico-sdk -DPICO_EXTRAS_PATH=../pico/pico-extras ..
#cmake -DCMAKE_BUILD_TYPE=MinSizeRel -DPICO_BOARD=pico2 -DPICO_DOOM_USB=ON  -DPICO_SDK_PATH=/mnt/projs/pico/pico-sdk -DPICO_EXTRAS_PATH=/mnt/projs/pico/pico-extras ..
cmake -DCMAKE_BUILD_TYPE=MinSizeRel -DPICO_BOARD=pico2 -DPICO_DOOM_USB=ON  -DPICO_SDK_PATH=/mnt/projs/pico/pico-sdk -DPICO_EXTRAS_PATH=/mnt/projs/pico/pico-extras ..

make -j12
cd ..
#rm -rf build_pico && cmake -B build_pico -DPICO_DOOM_USB=ON && cmake --build build_pico


#/usr/local/bin/picotool load -f ./build_pico/src/doom_tiny_nost.uf2
/usr/local/bin/picotool load -f ./build_pico/src/doom_tiny_nost_usb.uf2
#/usr/local/bin/picotool load -f /mnt/projs/pico/rp2040-doom-ili9341-screen/build_pico/src/doom_tiny_nost_usb.uf2
/usr/local/bin/picotool info -a

/usr/local/bin/picotool reboot
