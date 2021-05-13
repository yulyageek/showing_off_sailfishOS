#include <iostream>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <mysql/mysql.h>

using namespace std;

int main(int argc, char *argv[]) {
int n = 0;
int listenfd = 0, connfd = 0;
struct sockaddr_in serv_addr;
listenfd = socket(AF_INET, SOCK_STREAM, 0);

memset(&serv_addr, '0', sizeof(serv_addr));

serv_addr.sin_family = AF_INET;

serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

serv_addr.sin_port = htons(5000);

bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
listen(listenfd, 10);

char Buff[1025];
 
while(1) {
connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
read(connfd, Buff, 1025);
close(connfd);
break;

}

MYSQL mysql, *connection;
mysql_init(&mysql);
connection = mysql_real_connect(&mysql, "172.17.0.2", "root", "mysql01","students_db",3306,0, 0);
if ( connection == NULL ) {
std::cout « mysql_error(&mysql) « std::endl;
return 1;
}
int query_state;
string query = "INSERT INTO anketa (name) VALUES ";
//string name = "anfisa";
query = query + "('" + Buff + "')";
std::cout « query « std::endl;
query_state = mysql_query(connection, query.c_str());
if (query_state !=0) {
std::cout « mysql_error(connection) « std::endl;
return 1;
}
}
