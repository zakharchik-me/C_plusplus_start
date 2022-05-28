#ifndef LABA5_ERRORS_H
#define LABA5_ERRORS_H

#define zero_value 0

using namespace std;

class Errors
{
public:
    static void appealToNullptr()
    {
        throw logic_error("Âû ïûòàåòåñü îáðàòüñÿ ê äàííûì â nullptr");
    }

    static void makeBufferSmaller()
    {
        throw logic_error("Âû ïûòàåòåñü ñäåëàòü áóôôåð ìåíüøå (íå ñ÷èòàÿ erase_back)");
    }

    static void wrongBufferSize()
    {
        throw logic_error("Âû íå ìîæåòå ñîçäàòü áóôôåð ðàçìåðîì ìåíüøå zero_value");
    }

    static void wrongCapacity()
    {
        throw logic_error("Âû íå ìîæåòå èçìåíèòü êàïàñèòè íà áîëåå ìàëåíüêèé èëè òàêîé æå");
    }

    static void fullBuffer()
    {
        throw logic_error("Âû íå ìîæåòå äîáàâèòü ýëåìåíò â ïåðåïîëíåííûé áóôôåð");
    }

    static void wrongIndex()
    {
        throw logic_error("Âû íå ìîæåòå îáðàòèòüñÿ ê äàííîìó èíäåêñó, òàê êàê åãî íåò â áóôôåðå");
    }
};

#endif