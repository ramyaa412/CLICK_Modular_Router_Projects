require(library /home/comnetsii/elements/routerport.click);

rp :: RouterPort(DEV veth1, IN_MAC ba:4e:82:d1:5f:dd, OUT_MAC 52:0c:ec:14:35:1e);

MyPackGen() -> Print(CONTENTS 'ASCII') -> [0]rp;

rp[0] -> Print(CONTENTS 'ASCII') -> Discard;
