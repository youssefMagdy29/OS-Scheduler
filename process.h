#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
public:
    Process(std::string name, int arrival_time,
            int burst_time, int priority = -1) :
        name(name),
        arrival_time(arrival_time),
        burst_time(burst_time),
        priority(priority)
    { }

    std::string get_name() { return name;         }
    int get_arrival_time() { return arrival_time; }
    int get_burst_time()   { return burst_time;   }
    int get_priority()     { return priority;     }

private:
    std::string name;
    int arrival_time;
    int burst_time;
    int priority;
};

#endif // PROCESS_H

