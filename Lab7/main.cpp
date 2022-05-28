#include "Buffer.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        CircularBuffer<float> buffer_float(6);
        CircularBuffer<float>::Iterator iter_float;

        buffer_float.circular_push_back(2.0);

        buffer_float.circular_push_back(3.14);

        buffer_float.circular_push_back(22.8);

        buffer_float.circular_push_back(35.9);

        buffer_float[4] = 666;

        cout << "\nfloat\n";
        for (iter_float = buffer_float.begin(); iter_float != buffer_float.end(); ++iter_float)
            cout << *iter_float << " ";

        cout << endl;

        iter_float = max_element(buffer_float.begin(), buffer_float.end());

        cout << "\nmax_element buffer: " << *iter_float << endl;

        buffer_float.changeCapacity(100);

        buffer_float.circular_pop_back();
        buffer_float.circular_pop_back();
        buffer_float.circular_pop_back();
        buffer_float.circular_pop_back();
        buffer_float.circular_pop_back();
        buffer_float.circular_pop_back();
        buffer_float.circular_pop_back();
        buffer_float.circular_pop_back();
        buffer_float.circular_pop_front();

        cout << "\nbuffer_float.empty() buffer_float.circular_pop_back() x8\n";
        cout << "Empty?";
        (buffer_float.empty()) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    catch (exception &e)
    {
        e.what();
    }

    return 0;
}
