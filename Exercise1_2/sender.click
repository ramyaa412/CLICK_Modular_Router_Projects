require(library /home/comnetsii/elements/routerport.click);

rp :: RouterPort(DEV veth1, IN_MAC de:b4:56:85:9a:e5, OUT_MAC 6e:d4:02:56:76:69);

MyPackGen() ->Print(CONTENTS 'ASCII') -> rp -> Discard;
