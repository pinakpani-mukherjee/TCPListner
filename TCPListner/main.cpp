#include <iostream>
#include <string>

#include "TcpListener.h"

void Listener_MessageReceived(CTcpListener* listener, int client, std::string message);

void main() {

	CTcpListener server("127.0.0.1", 54010, Listener_MessageReceived);
	if (server.Init()) {

		std::cout << "Running Server" << std::endl;
		server.Run();
	}
}

void Listener_MessageReceived(CTcpListener* listener, int client, std::string message) {
	listener->Send(client, message);
}