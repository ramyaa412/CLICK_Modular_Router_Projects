require(library /home/comnetsii/elements/routerport.click);

rp :: RouterPort(DEV veth2, IN_MAC 52:0c:ec:14:35:1e, OUT_MAC ba:4e:82:d1:5f:dd);

rp[0] -> [0]psh::MyPushElement(MAXPACKETSIZE 32);
psh[0] ->[0]rp;
psh[1] -> Print(CONTENTS 'ASCII') -> Discard;

