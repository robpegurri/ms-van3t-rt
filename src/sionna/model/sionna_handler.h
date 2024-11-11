#ifndef SIONNA_HANDLER_H
#define SIONNA_HANDLER_H

#include <ns3/core-module.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace ns3;

extern int sionna_port;
extern int sionna_socket;
extern struct sockaddr_in sionna_addr;
extern struct in_addr sionna_destIPaddr;
extern bool is_socket_created;

struct Position {
    std::string x;
    std::string y;
    std::string z;
    std::string angle;
};

extern std::map<std::string, Position> vehiclePositions;

void connect_now();
void checkConnection();
int sendString2sionna_UDP(const std::string& str);
std::string getFromSionna_UDP();
void updateLocationSionna(std::string veh, std::string x, std::string y, std::string z, std::string angle);
double getRxPowerFromSionna(Vector a_position, Vector b_position);
double getPropagationDelayFromSionna(Vector a_position, Vector b_position);
std::string getLOSStatusFromSionna(Vector a_position, Vector b_position);
void LogProgress(int piece, std::string chunk);

#endif /* SIONNA_HANDLER_H */