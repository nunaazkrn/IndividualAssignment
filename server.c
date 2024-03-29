#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <signal.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netdb.h>

 /* alternative port for tftp=port69 */
#define PORT 6969
#define BACKLOG 5
#define LENGTH 512

void error(const char *msg)
{
perror(msg);
        exit(1);
}

int main ()
{
        /* Defining Variables */
        int sockfd;
        int nsockfd;
        int num;
        exit(1);
}

int main ()
{
        /* Defining Variables */
        int sockfd;
        int nsockfd;
        int num;
        int sin_size;
        
        /* define client addr */
        struct sockaddr_in client;
        /* define server addr */
        struct sockaddr_in server; 
        // Receiver buffer
        char revbuf[LENGTH]; 

        /* Get the Socket file descriptor */
        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
        {       
                 /* socket funtion to make connection between client and server */
                fprintf(stderr, "ERROR: Failed to obtain Socket Descriptor. (errno = %d)\n", errno);
                exit(1);
                
        /* client addr */
        struct sockaddr_in client;
        /* server addr */
        struct sockaddr_in server;
        // Receiver buffer
        char revbuf[LENGTH];


        /* Get the Socket file descriptor */
        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
        {
                fprintf(stderr, "ERROR: Failed to obtain Socket Descriptor. (errno = %d)\n", errno);
                exit(1);
        }
        else
                printf("[Server] Obtaining socket descriptor successfully.\n");

        /* Fill the client socket address struct */
        server.sin_family = AF_INET; // Protocol Family
        server.sin_port = htons(PORT); // Port number
        server.sin_addr.s_addr = INADDR_ANY; // AutoFill local address
        bzero(&(server.sin_zero), 8); // Flush the rest of struct

        /* Bind a special Port - bind socket to a particular address */
        if( bind(sockfd, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1 )
        {
                fprintf(stderr, "ERROR: Failed to bind Port. (errno = %d)\n", errno);
                exit(1);
        }
        else
                printf("[Server] Binded tcp port %d in addr 192.168.187.3  sucessfully.\n",PORT);

        /* Listen remote connect/calling */
        if(listen(sockfd,BACKLOG) == -1)
        {
                fprintf(stderr, "ERROR: Failed to listen Port. (errno = %d)\n", errno);
                exit(1);
        }
        else
                printf ("[Server] Listening the port %d successfully.\n", PORT);

        int success = 0;
        while(success == 0)
        {
                sin_size = sizeof(struct sockaddr_in);

                /* Wait a connection, and obtain a new socket file despriptor for single connection*/
                if ((nsockfd = accept(sockfd, (struct sockaddr *)&server, &sin_size)) == -1)
                {
                    fprintf(stderr, "ERROR: Obtaining new Socket Despcritor. (errno = %d)\n", errno);
                        exit(1);
                }
                else

                        printf("[Server] Server has got connected from 192.168.187.3\n", inet_ntoa(server.sin_addr));


                /*Receive File from Client */
                char* fr_name = "receive.txt";
                FILE *fr = fopen(fr_name, "w+");
                if(fr == NULL)
                        printf("File %s Cannot be opened file on server.\n", fr_name);

                else
                {
                       bzero(revbuf, LENGTH);
                        int fr_block_sz = 0;
                        while((fr_block_sz = recv(nsockfd, revbuf, LENGTH, 0)) > 0)
                        {
                            int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);
                                if(write_sz < fr_block_sz)
                            {
                                error("File write failed on server.\n");
                            }
                                bzero(revbuf, LENGTH);
                                if (fr_block_sz == 0 || fr_block_sz != 512)
                                {
                                        break;
                                }
                        }
                        if(fr_block_sz < 0)
                    {
                        if (errno == EAGAIN)
                        {
                        printf("recv() timed out.\n");
                    }
                    else
                    {
                        fprintf(stderr, "recv() failed due to errno = %d\n", errno);
                                        exit(1);
                    }
                }
                        printf("OK File %s received from client!\n", fr_name);
                        fclose(fr);
                }


        FILE *fdr,*fdw;
        char filename[25],ch,sendline[100];
        int op;
        printf("Enter yes[y] or no[n] to decrypt :");
        scanf("%s",filename);
        if ((strcmp(filename,"y")==0)||(strcmp(filename,"Y")==0)){
        fdr=fopen("receive.txt","r");
        fdw=fopen("decrypt.txt","w+");
        ch=fgetc(fdr);
        
        while(ch!=EOF){
                printf("%c",ch);
                op=(int)ch;
                        op=op+5;
                        fprintf(fdw,"%c",op);
                ch=fgetc(fdr);
                        }
        fclose(fdw);
        fclose(fdr);
        pclose;}
        else
                pclose;
        }


}




