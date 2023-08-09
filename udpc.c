#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char * argv[]) 
{
	int std;
	struct sockaddr_in server;
	int length=sizeof(server);
	std=socket(AF_INET,SOCK_DGRAM,0);
	if(std==-1)
	{
		printf("Error in socket creation\n");
		exit(0);
	}
	else
	{
		printf("Socket is created\n");
	}
	
	char msg[]="hello server";
	int lengthofmsg=strlen(msg);
	int sendMsg=sendto(std,msg,lengthofmsg,0,(const struct sockaddr*)&server,length);
	if(sendMsg==-1)
	{
		printf("Error in sending message\n");
		exit(0);
	}
	else
	{
		printf("Message is sent\n");
	}
	return 0;
}
