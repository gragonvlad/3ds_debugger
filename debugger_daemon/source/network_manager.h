#pragma once

#include <string>

class NetworkManager final {
public:
    NetworkManager() {}
    ~NetworkManager() {}

    /**
     * Configures the socket to start listening on the specified network port.
     * @param port The port on which to listen on.
     */
    void Listen(int port);

    /**
     * Blocks the caller until a client connects to the socket.
     */
    void Accept();

    /**
     * Whether or not a client is already connected to the socket.
     * @returns Whether a client is connected.
     */
    bool IsClientConnected();

    /**
     * Gets the IP of the connected client.
     * A client must already be connected.
     * @returns The IP of the connected client.
     */
    std::string GetClientIPStr();

    /**
     * Blocks the caller until enough network data is received to constitute a command.
     * A command is composed of an u32 length field and a sequence of printable ASCII bytes.
     * @returns The string of the received command.
     */
    std::string ReceiveCommand();

    /**
     * Sends a network packet to the connected client,
     * consisting of an u32 with the length of the string, and then the string.
     */
    void SendReply(std::string command);
};