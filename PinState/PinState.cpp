#include "PinState.h"

PinState::PinState( std::map< std::string, int > pin_map ) : _pin_map( pin_map ) {}
PinState::~PinState() {}

int PinState::getPinState( std::string pin ) {
    if ( _translateConstant.get_translated_constant( std::stoi( pin ) ) == "ROTARY" ) {
        std::string pin_file_path = "pin_data/";
        std::cout << "translating pin: " << pin << "... " << std::endl;
        std::ifstream pin_file( pin_file_path + _translateConstant.get_translated_constant( std::stoi( pin ) ) + ".txt" );
        pin_file >> pin;
        pin_file.close();
        std::cout << "got pin " << pin << " from file" << std::endl;
        return std::stoi( pin );
    } else {
        std::cout << "translated constant: " << _translateConstant.get_translated_constant( std::stoi( pin ) ) << std::endl;
    }
    return _pin_map[ pin ];
}

void PinState::setPinState( std::string pin, int state ) {
    _pin_map[ pin ] = state;
    std::string pin_file_path = "pin_data/";
    std::ofstream pin_file( pin_file_path + _translateConstant.get_translated_constant( std::stoi( pin ) ) + ".txt" );
    pin_file << state;
    pin_file.close();
}

void PinState::clear() { _pin_map.clear(); }

std::map<std::string, int> PinState::getMap() { return _pin_map; }
