#ifndef Logger_h
#define Logger_h
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include "../GameTimer/GameTimer.h"

class Logger {
public:
    Logger( std::string constructor_name );
    ~Logger();
    void logUpdate( std::string message, std::string caller );
    decltype( std::chrono::seconds().count() ) _get_seconds_since_epoch();
    int _get_random_number();
    bool inArray( int supposed_random_number );

private:
    std::string _constructor_name;
    std::ofstream _log_file;
    std::vector<int> _used_random_numbers;
};
#endif  // Logger_h
