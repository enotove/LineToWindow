
#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>

using namespace std::chrono_literals;
int x = 0;

void PersonInLine()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(1s);
        x++;
        std::cout << x << "\t";
    }
}
void PersonOutLine()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(2s);
        x--;
        std::cout << x << "\t";
    }
}

int main()
{
    std::thread t1(PersonInLine);
    std::thread t2(PersonOutLine);
    t1.join();
    t2.join();
}


