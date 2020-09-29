#ifndef _AND_H
#define _AND_H

class And : public Gate {
    public:
		And() : Gate(){};
        Signal output();                
};
#endif
