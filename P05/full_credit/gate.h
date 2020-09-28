#ifndef _GATE_H
#define _GATE_H

#include <iostream>

class Gate {

    public:
        void Gate();
        connect(Gate& gate, Pin input_pin);
        input(Pin pin, Signal signal);
        Signal(input(Pin pin));
        virtual Signal output();
    protected:
        Signal _input1;
        Signal _input2;        
    private:
        Gate* _to_gate;
        Pin( _to_pin);
};

class And : public Gate {
    public:
        Signal output() override {
            if()
        };                
};

class Or : public Gate {
    public:
        Signal output() override {
            if()
           };
};
#endif
