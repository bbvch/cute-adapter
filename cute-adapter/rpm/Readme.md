
Install
=======

Sailfish OS
-----------

* Inside Sailfish OS Build Engine

    mb2 -t SailfishOS-3.0.0.8-i486 build
    sudo /srv/mer/targets/SailfishOS-3.0.0.8-i486/bin/rpm --root /srv/mer/targets/SailfishOS-3.0.0.8-i486/ -i RPMS/*.rpm

* clean everything (remove all object files)

    mb2 -t SailfishOS-3.0.0.8-armv7hl build
    sudo /srv/mer/targets/SailfishOS-3.0.0.8-armv7hl/bin/rpm --root /srv/mer/targets/SailfishOS-3.0.0.8-armv7hl/ --ignorearch -i RPMS/*.rpm

