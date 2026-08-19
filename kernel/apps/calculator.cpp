// Native Calculator Application Engine
#pragma once

namespace leraOS::Apps {
    class Calculator {
    private:
        long current = 0;
        long registerVal = 0;
        char operation = '\0';

    public:
        void InputDigit(int digit) {
            current = (current * 10) + digit;
        }

        void SetOp(char op) {
            registerVal = current;
            current = 0;
            operation = op;
        }

        void Evaluate() {
            if (operation == '+') current = registerVal + current;
            if (operation == '-') current = registerVal - current;
            if (operation == '*') current = registerVal * current;
            if (operation == '/' && current != 0) current = registerVal / current;
            operation = '\0';
        }

        long GetDisplay() const { return current; }
    };
}
