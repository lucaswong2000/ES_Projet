#include"linkLRU.h"
void linkLRU(int*arr,int memSize,int pageSize ){
	memPage*p=NULL;//used to go through the link
	memPage*head=NULL;//point to the head of the link
	memPage*pre=head;//save the pointer of the previous node of p
	memPage*rear=NULL;
	int count=0,i=0,nPageFault=0;
	for(i=0;i<pageSize;i++)
	{
		if(count==0)
		{
			p=(memPage*)malloc(sizeof(memPage));
			p->pageNum=arr[i];
			p->next=NULL;
			head=p;
			rear=p;
			++nPageFault;
			++count;		
		}
		else if(count<memSize)
		{
			p=head;
			pre=head;
			while(p!=NULL)
			{
				if(p->pageNum==arr[i])
				{
					if(head==p)
						break;
					else
					{
						pre->next=p->next;
						p->next=head;
						head=p;
						while(p->next!=NULL)
						{
							p=p->next;
						}
						rear=p;
						break;
					}
							
				}	
				pre=p;
				p=p->next;
			}
			if(p==NULL)
			{
				p=(memPage*)malloc(sizeof(memPage));
				p->pageNum=arr[i];
				p->next=head;
				head=p;
				++count;
				++nPageFault;				
			}
			
		}
		else
		{
			p=head;
			pre=head;
			while(p!=NULL)
			{
				if(p->pageNum==arr[i])
				{
					if(head==p)
						break;
					else
					{
						pre->next=p->next;
						p->next=head;
						head=p;
						while(p->next!=NULL)
						{
							p=p->next;
						}
						rear=p;
						break;
					}
							
				}	
				pre=p;
				p=p->next;
			}
			if(p==NULL)
			{
				p=(memPage*)malloc(sizeof(memPage));
				p->pageNum=arr[i];
				p->next=head;
				head=p;	
				while(p->next!=rear)
				{
					p=p->next;
				}
				p->next=NULL;
				//printf("%d\t",rear->pageNum);
				free(rear);
				rear=p;
				++nPageFault;				
			}
			
		}
	}
	printf("\n");
	printf("number of page faults:%d\n",nPageFault);
	p=head;
	pre=p;
	while(p!=NULL)
	{
		p=p->next;
		free(pre);
		pre=p;	
	}
}
