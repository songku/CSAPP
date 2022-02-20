/* $begin hostinfo */
#include "csapp.h"

int main(int argc, char **argv) 
{
	struct addrinfo *p,*listp,hints;
	char buf[MAXLINE];
	int rc,flags;
	
	if(argc!=2){
		fprintf(stderr,"usage:%s <domain name>\n",argv[0]);
		exit(0);
	}
	
	/*get a list of addrinfo records*/
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family=AF_INET;/*IPV4*/
	hints.ai_socktype=SOCK_STREAM;/*connection only*/
	if((rc=getaddrinfo(argv[1],NULL,&hints,&listp))!=0){
		fprintf(stderr,"getaddrinfo error:%s\n",gai_strerror(rc));
		exit(1);
	}
	
	/*walk the list and display each IP address*/
	flags=NI_NUMERICHOST;//display address string instead of domain name
	for(p=listp;p;p=p->ai_next)
	{
		getnameinfo(p->ai_addr,p->ai_addrlen,buf,MAXLINE,NULL,0,flags);
		printf("%s\n",buf);
	}
	
	/*clean up*/
	freeaddrinfo(listp);
	
	exit(0);	
/*
    char **pp;
    struct in_addr addr;
    struct hostent *hostp;

    if (argc != 2) {
	fprintf(stderr, "usage: %s <domain name or dotted-decimal>\n", 
		argv[0]);
	exit(0);
    }

    if (inet_aton(argv[1], &addr) != 0) 
	hostp = Gethostbyaddr((const char *)&addr, sizeof(addr), AF_INET); 
    else                                
	hostp = Gethostbyname(argv[1]);

    printf("official hostname: %s\n", hostp->h_name);

    for (pp = hostp->h_aliases; *pp != NULL; pp++)
	printf("alias: %s\n", *pp);

    for (pp = hostp->h_addr_list; *pp != NULL; pp++) {
	addr.s_addr = ((struct in_addr *)*pp)->s_addr;
	printf("address: %s\n", inet_ntoa(addr));
    }
    exit(0);
*/
}
/* $end hostinfo */
