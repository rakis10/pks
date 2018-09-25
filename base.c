#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#define LINE_LEN 12
	
/* run this progWram using the console pauser or add your own getch, system("pause") or input loop */
void dispatcher_handler(u_char *, const struct pcap_pkthdr *, const u_char *);
int main(int argc, char *argv[]) {
pcap_if_t *alldevs;
pcap_if_t *d;
		pcap_t *pfile;
		
		char *dev, errbuf[PCAP_ERRBUF_SIZE];
		pfile = pcap_open_offline("ol.pcap", errbuf);
		
		pcap_loop(pfile, 0, dispatcher_handler, NULL);
		
}



void dispatcher_handler(u_char *temp1, 
                        const struct pcap_pkthdr *header, const u_char *pkt_data){
    u_int i=0;

    /*
     * Unused variable
     */
    (VOID)temp1;

    /* print pkt timestamp and pkt len */
    printf("%ld:%ld (%ld)\n", header->ts.tv_sec, header->ts.tv_usec, header->len);          
    
    /* Print the packet */
    for (i=1; (i < header->caplen + 1 ) ; i++)
    {
        printf("%.2x ", pkt_data[i-1]);
        if ( (i % LINE_LEN) == 0) printf("\n");
    }
    
    printf("\n\n");     
    
}
	
//		dev = pcap_lookupdev(errbuf);
//		if (dev == NULL) {
//			fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
//			return(2);
//		}
//		printf("Device: %s lool \n", dev);
//		
		
//  pcap_t *handle;
//
//	 handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
//	 if (handle == NULL) {
//		 fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
//		 return(2);
//	}
//		//scanf("")

