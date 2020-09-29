#ifndef _GATE_H
#define _GATE_H

typedef int Pin;
typedef bool Signal;

class Gate {

    public:
        Gate() :_input{true}, _input2{false} {};
        void connect(Gate& gate, Pin input_pin);
        void input(Pin pin, Signal signal);
        Signal input(Pin pin);
        Signal output();
    protected:
        Signal _input1;
        Signal _input2;        
    private:
        Gate* _to_gate;
        Pin _to_pin;
};
#endif
