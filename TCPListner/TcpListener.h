#pragma once
#include <WS2tcpip.h> // Header file for all Winsock funtions
#include <string>

#pragma comment (lib,"ws2_32.lib") // Winsock library files

#define MAX_BUFFER_SIZE (49152)

class CTcpListener;

typedef void(*MessageRecievedHandler)(CTcpListener* listener, int socketId, std::string msg);
class CTcpListener
{
public:
	CTcpListener(std::string ipAddress, int port, MessageRecievedHandler handler);

	~CTcpListener();

	// Send message to specified client
	void Send(int clientSocket, std::string msg);

	bool Init();

	void Run();

	void Cleanup();

private:

	SOCKET CreateSocket();

	SOCKET WaitForConnection(SOCKET listening);


	std::string				m_ipAddress;
	int						m_port;
	MessageRecievedHandler	MessageReceived;
};