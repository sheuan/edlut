//( cd_socket.hpp

#ifndef CD_SOCKET_H
#define CD_SOCKET_H

//socket includes
#include <sys/types.h>
#include <sys/socket.h> 
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h> // to set special server flags
#include <unistd.h> // misc symbolic constants and types
#include <netdb.h>
#include <netinet/tcp.h>
#define closesocket close

#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "./CommunicationDevice.h"

using namespace std;

#define CLIENT 0
#define SERVER 1

//( Cd_Socket

/*!
 * \brief A socket used to communicate with another program
 *
 * \author Christian Boucheny
 **/
class CdSocket : public CommunicationDevice {
public:
  /*!
   *
   * \brief Constructor for which parameters of the tcp connection are stored in an external file 
   * 
   * \param status CLIENT or SERVER 
   * \param server_address address of the server host
   * \param tcp_port tcp_port to connect
   *
   **/
  CdSocket(unsigned short status, string server_address,unsigned short tcp_port);

  /*!
   * \brief Default destructor
   *
   **/
  ~CdSocket();

  /*!
   *
   * \brief Send a block of data
   * 
   * \param   buffer       data to send. Need a cast to char*
   * \param   buffer_size  size of the packet
   *
   * \return  the error signal 
   *
   **/
  int sendBuffer(void* buffer,int buffer_size);

  /*!
   *
   * \brief Receive a block of data
   * 
   * \param   buffer       data to send
   * \param   buffer_size  size of the packet
   *
   * \return  the error signal 
   *
   **/
  int receiveBuffer(void* buffer,int buffer_size);


protected:
  /*!
   *
   * initialize the socket connections with parameters defined in constructor 
   * 
   *
   **/
  void initializeSocket();

  /*!
   *
   * The socket itself
   * 
   **/
  int socket_fd;

  /*!
   *
   * host address of the server
   * 
   **/
  string serv_host_addr;

  /*!
   *
   * tcp port of the server
   * 
   **/
  unsigned short serv_tcp_port;

  /*!
   *
   * is it a client or server ? 0 = CLIENT / 1 = SERVER
   * 
   **/
  unsigned short status;

  /*!
   *
   * return value of called I-O functions 
   * 
   **/
  int ret_status;
}
;

//) Cd_Socket


#endif

//) cd_socket.hpp