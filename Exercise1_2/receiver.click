require(library /home/comnetsii/elements/routerport.click);

rp :: RouterPort(DEV veth2, IN_MAC 6e:d4:02:56:76:69, OUT_MAC de:b4:56:85:9a:e5);

Idle -> rp -> Print(CONTENTS 'ASCII') -> Discard;
