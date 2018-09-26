#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
	
/* run this progWram using the console pauser or add your own getch, system("pause") or input loop */
//void dispatcher_handler(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char *argv[]) {
		pcap_if_t *alldevs;
		pcap_if_t *d;
		pcap_t *pfile;
		
		struct pcap_pkthdr header;
		const u_char *pkt_data;
		
		const	struct pcap_pkthdr *headeer;
		const u_char *packet;

		
		char *dev, errbuf[PCAP_ERRBUF_SIZE];
		pfile = pcap_open_offline("ol.pcap", errbuf);
		int counter = 0;
		while(packet= pcap_next(pfile,&header)){

			vypis(counter, packet, &header);
		
			counter++;
			
		}

	
		pcap_close(pfile);
	
		
		
//		pfile = pcap_open_offline("ol.pcap", errbuf);
//		pcap_loop(pfile, 0, dispatcher_handler, NULL);
}					
void vypis(int max, const u_char *pkt_data,const struct pcap_pkthdr *header){
	int i;
//	int dlzka = header->len	;
		printf("Destination adress: %.02x %.02x %.02x %.02x %.02x %.02x\n",pkt_data[0], pkt_data[1], pkt_data[2],pkt_data[3],pkt_data[4],pkt_data[5]);
		printf("Source adress: %.02x %.02x %.02x %.02x %.02x %.02x\n", pkt_data[6],pkt_data[7],pkt_data[8],pkt_data[9],pkt_data[10],pkt_data[11]);
	 for (i=0; (i <header->caplen ) ; i++)
    {
       // printf("%.2x ", pkt_data[i-1]);
        if ( (i % 16) == 0) printf("\n");	
             printf("%0.2x ", pkt_data[i]);
    }
    printf("----------\n");
}
//
//void dispatcher_handler(u_char *temp1, 
//                        const struct pcap_pkthdr *header, const u_char *pkt_data){
//    u_int i=0;
//	
//		
//    /*
//     * Unused variable
//     */
//    (VOID)temp1;
//
//    /* print pkt timestamp and pkt len */
////    printf("%ld:%ld (%ld)\n", header->ts.tv_sec, header->ts.tv_usec, header->len);          
//        
//  printf("%ld\n",  header->len);  
//             	
//    /* Print the packet */
//    for (i=1; (i < header->caplen + 1 ) ; i++)
//    {
//       // printf("%.2x ", pkt_data[i-1]);
//        if ( (i % 16) == 0) printf("\n");	
//             printf("%0.2x ", pkt_data[i]);
//    }
//    
//    printf("\n\n");     
//    
//}

