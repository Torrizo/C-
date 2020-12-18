#include <signal.h>
#include <sys/wait.h>
#include "tcpsocket.hpp"

void sigcb(int signo)
{
	while (waitpid(-1, NULL, WNOHANG) > 0);
}
int main()
{
	signal(SIGCHLD, sigcb);
	TcpSocket lst_sock;//�����׽���
	//1. �����׽���
	CHECK_RET(lst_sock.Socket());
	//2. �󶨵�ַ��Ϣ
	CHECK_RET(lst_sock.Bind("0.0.0.0", 9000));
	//3. ��ʼ����
	CHECK_RET(lst_sock.Listen());
	while (1) {
		//4. ��ȡ�½�����
		TcpSocket con_sock;//��ָ���ͻ���ͨ�ŵ��׽���
		std::string cli_ip;
		int cli_port;
		bool ret = lst_sock.Accept(&con_sock, &cli_ip, &cli_port);
		if (ret == false) {
			continue;
		}
		pid_t pid = fork();
		if (pid < 0) {
			con_sock.Close();
			continue;
		}
		else if (pid == 0) {
			while (1) {
				std::string buf;
				ret = con_sock.Recv(&buf);
				if (ret == false) {
					con_sock.Close();
					continue;
				}
				printf("%s:%d say:%s\n", cli_ip.c_str(),
					cli_port, buf.c_str());

				std::cout << "server say:";
				std::cin >> buf;
				ret = con_sock.Send(buf);
				if (ret == false) {
					con_sock.Close();
				}
			}
			exit(0);
		}
		con_sock.Close();//���ӽ������ݶ���--���Ǹ����̲�ͨ��
	}
	//6. �ر��׽���
	lst_sock.Close();
	return 0;
}
