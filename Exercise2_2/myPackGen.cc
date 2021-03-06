#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>
#include <click/timer.hh>
#include "myPackGen.hh"
#include "mypacket.hh"

CLICK_DECLS

MyPackGen::MyPackGen() : _timer(this), current_loop(0) {}
MyPackGen::~MyPackGen(){}

int MyPackGen::configure(Vector<String> &conf, ErrorHandler *errh) {
	return 0;
}

int MyPackGen::initialize(ErrorHandler *) {
	_timer.initialize(this);
	_timer.schedule_after_sec(0);
	return 0;
}

void MyPackGen::run_timer(Timer *timer) {
	Timestamp now = Timestamp::now();
	click_chatter("%s: %{timestamp}: timer fired!\n",declaration().c_str(), &now);
	if (current_loop % 2 == 0) {
		this->sendPackettype0();
	}
	else {
		this->sendPackettype1();
	}
	current_loop++;
	_timer.reschedule_after_sec(3);
}

void MyPackGen::sendPackettype0() {
	click_chatter("Sending packet");
	WritablePacket *packet = Packet::make(0, "*hi!*", sizeof(my_packet), 0);
	my_packet *header = (my_packet *)packet->data();
	header->type = 0;
	header->length = sizeof(my_packet);
	output(0).push(packet);
}

void MyPackGen::sendPackettype1() {
	click_chatter("Sending Packet");
	WritablePacket *packet = Packet::make(0, "*hi!*", sizeof(my_packet), 0);
	my_packet *header = (my_packet *)packet->data();
	header->type = 1;
	header->length = sizeof(my_packet);
	output(0).push(packet);
}

void MyPackGen::push(int port, Packet *p) {
	click_chatter("ERROR: this should not happen");
	return;
}

CLICK_ENDDECLS
EXPORT_ELEMENT(MyPackGen)
