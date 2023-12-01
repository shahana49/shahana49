#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
        struct node*prevlink;
	struct node*nextlink;
};
struct node *header=NULL;
struct node *temp=NULL;
void insert_at_front(int item)
{
	struct node *newnode;
    	newnode=(struct node*) malloc(sizeof(struct node));
    	newnode->data=item;
    	newnode->prevlink=NULL;
    	if(header==NULL)
	{
        	header=newnode;
        	temp=newnode;
        	newnode->nextlink=NULL;
		printf("Element Succesfully inserted at position 1 \n");
	}
	else
	{  
        	header->prevlink=newnode; 
        	newnode->nextlink=header;
        	header=newnode;
		printf("Element Succesfully inserted at position 1 \n");
	}	
}
void insert_at_end(int item)
{
        struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item;	
	newnode->nextlink=NULL;
	int count=1;
	if(header==NULL)
	{
		header=temp=newnode;
        	newnode->prevlink=NULL;
		printf("Element Succesfully inserted at position 1 \n");
	}
	else
	{	
		struct node *ptr=header;
		while(ptr->nextlink!=NULL)
		{
			ptr=ptr->nextlink;
			count++;	
		}
        	temp->nextlink=newnode;
        	newnode->prevlink=temp;
        	temp=newnode;
		printf("Element Succesfully inserted at position %d \n",count+1);
	}	
}
void insert_at_pos(int item, int key)
{
    	int count=1;
    	struct node *newnode;
    	newnode=(struct node*) malloc(sizeof(struct node));
    	newnode->data=item;
    	struct node *ptr;
    	ptr=header;
    	while(ptr->data!=key && ptr->nextlink!=NULL)
     	{
        	ptr=ptr->nextlink;  
        	count++; 
    	}
    	if((ptr->nextlink==NULL) && ( ptr->data==key))
    	{
      		newnode->nextlink=NULL;
      		newnode->prevlink=ptr;
      		ptr->nextlink=newnode;
      		temp=newnode;
      		printf("\n%d element insert at the  %d position ",newnode->data,count+1); 
    	}      
    	else if((ptr->nextlink==NULL)&&(ptr->data!=key))
     	{
       		printf("key not found");
    	}
     	else
     	{
       		newnode->nextlink = ptr->nextlink;
       		ptr->nextlink = newnode;      
       		newnode->prevlink = ptr;		
       		ptr = newnode->nextlink;   
       		ptr->prevlink = newnode;
       		printf("\n%d element insert at the  %d position ",newnode->data,count+1); 
     	}
}
void delete_at_front()
{   
	if (header==NULL)
    	{
        	printf("list is empty");
    	}
    	else if(header->nextlink==NULL)
    	{ 
		printf("\nElement deleted at 1 st position  \n");
        	free(header);
        	header=NULL;
        	temp=NULL;
    	}
    	else
    	{
        	struct node *ptr=header;
		printf("\nElement deleted at 1 st position  \n");
        	header=ptr->nextlink;
        	header->prevlink=NULL;
        	free(ptr);
    	}
}
void delete_at_end()
{
    	int count=0;
    	struct node *ptr=header;
	while(ptr->nextlink!=NULL)
	{
		ptr=ptr->nextlink;
		count++;	
	}
    	if (header==NULL)
    	{
        	printf("list is empty");
    	}
    	else if(header->nextlink == NULL)  
    	{  
        	printf("\nElement deleted %d at %d position\n",header->data,count+1);
        	free(header);
        	header=NULL;  
        	temp=NULL;
    	}  
    	else
    	{
       		struct node *ptr=temp;
        	printf("\nElement deleted %d %d position\n",temp->data,count+1);
        	temp=temp->prevlink;
        	temp->nextlink=NULL;
        	free(ptr);
    	}
}
void delete_at_pos(int key)
{
   	int count=0;
   	if (header==NULL)
    	{
        	printf("list is empty");
    	}
    	else
    	{
            	struct node *ptr1=header;
            	struct node *ptr2=header;
            	while((ptr1!=NULL) && (ptr1->data!=key))
            	{
                	ptr2 = ptr1;
                	ptr1 = ptr1->nextlink;
                	count++;
            	}
            	if(ptr1 == NULL)
            	{
                	printf("\nKey not found\n");
            	}
            	else
            	{      
                	if(ptr2->nextlink == NULL)
                	{
                    		printf("\nElement deleted %d at %d position \n",ptr2->data,count+2);
                    		free(ptr2);
                    		header = temp = NULL;
                	}
                	else
                	{
                    		printf("\nElement deleted %d  %d position\n",ptr1->data,count+1);
                    		if(ptr1 == header)
                   		{     
                        		header = ptr1->nextlink;
                        		header->prevlink=NULL;
                    		}
                    		else
                    		{
                        		ptr2->nextlink = ptr1->nextlink;
                        		ptr2 = ptr1->nextlink;
                        		if(ptr2 != NULL)
                        		{
                            			ptr2->prevlink = ptr1->prevlink;
                        		}
                        		else
                        		{
                            			temp = ptr1->prevlink;
                        		}
                    		}			
                    		free(ptr1);
                	}
	   	}
	}      
}
void search(int key)
{	
	int count=0;
	if(header==NULL)
	{
		printf("\n list is empty \n");	
	}
	else
	{
		struct node *ptr=header;
        	while((ptr->data!=key) && (ptr->nextlink!=NULL))
        	{
            		ptr=ptr->nextlink;	
	    		count++;
        	}	
        	if((ptr->nextlink==NULL) && (ptr->data!=key))
        	{
            		printf("key not found");
        	}
		else
	   	{
			printf("\nkey fount at position %d\n",count+1);		
	   	}
	}
}
void traverse()
{
  	struct node *ptr=header;
  	if(ptr!=NULL)
  	{
  		while(ptr!=NULL)
   		{
      			printf("%d\t ",ptr->data);
      			ptr=ptr->nextlink;
   		} 
 	} 
}
int main()
{ 	
	int item,key,choice;	
	printf("DOUBLE LINKED LIST OPERATIONS\n");
	while(1)   
    	{  
        	printf("\n\n1.Insert at front\n2.Insert at end\n3.Insert after position\n4.Delete at front\n5.Delete at end\n6.Delete node at any position\n7.Display Elements\n8.Search position of Element\n9.Exit");  
        	printf("\nSelect the options\n");         
        	scanf("%d",&choice);  
        	switch(choice)  
        	{  
            		case 1:  printf("\nenter the data to insert at front \n");
                    	scanf("%d",&item);
                    	insert_at_front(item);
                    	break;
            		case 2:  printf("\nenter the data to insert at end \n");
                    	scanf("%d",&item);
                    	insert_at_end(item);
                    	break;
            		case 3:  if(header==NULL)
            				{
	           				printf("\n list is empty \n");	
	           			}
	           			else
                   			{
                    				traverse();
                    				printf("\nselect the position\n");
                    				scanf("%d",&key);
                    				printf("\nenter the data to insert after the position \n");
                    				scanf("%d",&item);
                    				insert_at_pos(item,key);
                    			}
                    			break;
            		case 4:  delete_at_front();       
                    			break;  
            		case 5: if (header==NULL)
                       			{
                          			printf("list is empty");
                        		} 
                        		else
                      			{
                    				delete_at_end();
                    			}        
                   	 		break;  
            		case 6:  if(header==NULL)
	           			{
	           				printf("\n list is empty \n");	
	          			}
	           			else
                   			{
                    				traverse();
                    				printf("\nselect the position\n");
                    				scanf("%d",&key);  
                    				delete_at_pos(key);  
                    			}        
                    			break;  
            		case 7: if(header==NULL)
	           			{
	           				printf("\n list is empty \n");	
	           			}
	           			else
                   			{   
                    				traverse(); 
                   			}       
                    			break;  
            		case 8: printf("\nenter the key\n");
                    			scanf("%d",&key);  
                    			search(key);          
                    			break;  
	    		case 9:  printf("\nExited.");
                    		 	exit(0);  
                    			break;
            		default:  printf("invalid input");  
            	}
         }
         return 0;
}
