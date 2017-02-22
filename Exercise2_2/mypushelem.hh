#ifndef CLICK_MYPUSHELEMENT_HH
#define CLICK_MYPUSHELEMENT_HH

#include <click/element.hh>

CLICK_DECLS

class MyPushElement : public Element {

public:
	MyPushElement();
	~MyPushElement();
	
	const char *class_name() const { return "MyPushElement";}
	const char *port_count() const { return "1/2"; }
	const char *processing() const { return PUSH; }
	
	int configure(Vector<String>&, ErrorHandler*);
	void push(int, Packet *);
	
private:
	uint32_t maxSize;

};

CLICK_ENDDECLS

#endif
