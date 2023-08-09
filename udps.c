#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main( int argc, char * argv[]) 
{
	int std;
	char buff[100];
	int maxsizeofbuff=100;
	struct sockaddr_in server,client;
	int length=sizeof(server);
	int len=sizeof(client);
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
	if(bind(std,(struct sockaddr*)&server,length)==-1)
	{
		printf("Error in bind()\n");
		exit(0);
	}
	else
	{
		printf("Bind Succesfull\n");
	}
	int recieveMsg=recvfrom(std,buff,maxsizeofbuff,0,(struct sockaddr*)&client,&len);
	if(recieveMsg==-1)
	{
		printf("Error in recieveing message\n");
		exit(0);
	}
	else
	{
		printf("Message is recieveing\n");
	}
return 0;
}
	

