make
mkdir -p tmp
mount /dev/sda1 tmp/
mv Anhydrate_pico_rc_in.uf2 tmp/
umount tmp

