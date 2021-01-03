#include <sstream>
#include "tcpsocket.hpp"

int main()
{
    TcpSocket lst_sock;
    CHECK_RET(lst_sock.Socket());
    CHECK_RET(lst_sock.Bind("0.0.0.0", 9000));
    CHECK_RET(lst_sock.Listen());
    while(1) {
        TcpSocket con_sock;
        lst_sock.Accept(&con_sock);

        std::string buf;
        con_sock.Recv(&buf);
        std::cout << "请求信息:[" << buf << "]\n";

        std::string body;
        body="<html><body><h1>李深昊好帅</h1></body></html>";

        std::string empty_line = "\r\n";

        std::stringstream header;
        header << "Content-Type: text/html\r\n";
        header << "Content-Length: " << body.size() << "\r\n";
        header << "Connection: close\r\n";
        header << "Location: http://www.taobao.com\r\n";

        std::string first_line;
        first_line = "HTTP/1.1 302 OK\r\n";

        con_sock.Send(first_line);
        con_sock.Send(header.str());
        con_sock.Send(empty_line);
        con_sock.Send(body);

        con_sock.Close();
    }
    lst_sock.Close();
    return 0;
}
