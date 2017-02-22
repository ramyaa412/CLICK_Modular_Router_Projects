#ifndef CLICK_MYPACKGEN_HH
#define CLICK_MYPACKGEN_HH

#include <click/element.hh>
#include <click/timer.hh>

CLICK_DECLS

class MyPackGen : public Element {

public:
	MyPackGen();
	~MyPackGen();
	
	const char *class_name() const { return "MyPackGen";}
	const char *port_count() const { return "0/1"; }
	const char *processing() const { return PUSH; }
	
	int configure(Vector<String>&, ErrorHandler*);
	void push(int, Packet *);
	int initialize(ErrorHandler *errh);
	void run_timer(Timer *timer);
	void sendPacket();
	
	
private:
	Timer _timer;
};

CLICK_ENDDECLS

#endif
