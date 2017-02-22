#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>
#include "mypushelem.hh"
#include "mypacket.hh"

CLICK_DECLS

MyPushElement::MyPushElement(){}
MyPushElement::~MyPushElement(){}

int MyPushElement::configure(Vector<String> &conf, ErrorHandler *errh) {
	if (cp_va_kparse(conf, this, errh, "MAXPACKETSIZE", cpkM, cpInteger, &maxSize, cpEnd) < 0) return -1;
	if (maxSize <= 0) return errh->error("maxsize should be larger than 0");
	return 0;
}

void MyPushElement::push(int port, Packet *p) {
	click_chatter("Got a packet of size %d", p->length());
	const unsigned char *data = p->data();
	msg_t type = (msg_t)data[0];
	if (p->length() > maxSize) {
		click_chatter("Killing the packet");
		p->kill();
	} else if (type == 0) {
		output(0).push(p);
	} else if (type == 1) {
		output(1).push(p);
	}
}

CLICK_ENDDECLS
EXPORT_ELEMENT(MyPushElement)
