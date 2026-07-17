# Personal fork of dwl - dwm for Wayland

## Build
`sudo make clean install`

## Debugging dwl
`WLR_BACKENDS=wayland WAYLAND_DISPLAY=wayland-0 ./dwl -s "foot" > /tmp/dwl_test.log 2>&1 &`

`ls /run/user/$UID/wayland-*`

`pkill -f "WLR_BACKENDS=wayland.*dwl"`

