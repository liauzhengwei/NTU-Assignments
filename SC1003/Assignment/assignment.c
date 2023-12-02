#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Room
{
	int roomID;
	int status;
	char customerName[20];
} Room;

void listOccupiedRooms(struct Room[]);
void assignRoom(struct Room[]);
void removeRoom(struct Room[]);
int findCustomer(struct Room[]);
int getnum(int no);

void modify(char*str);

int num=0,bcount,a,i,result=0;
int assignment(){
printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n1: listOccupiedRooms()\n2: assignRoom()\n3: removeRoom()\n4: findCustomer()\n5: quit\n");

struct Room rm[5];

for(i=0;i<5;i++)
{
    rm[i].status = 0;
    rm[i].roomID = i+1;
    rm[i].customerName[0] = '\0';
}

while(num!=5)
{   
    int a;
    num = getnum(a);
    
    if(num ==1) 
    {   
        printf("listOccupiedRooms():  \n");
        listOccupiedRooms(rm);
        continue;
    }
    else if(num==2)
    {   
        printf("assignRoom(): \n");
        assignRoom(rm);
        continue;
    }
    else if(num==3)
    {      
        printf("removeRoom(): \n");
        removeRoom(rm);
        continue;
    
    }
    else if(num==4)
    {   
        printf("findCustomer(): \n");
        printf("Enter customer name: \n");
        result = findCustomer(rm);
        if(result == -1)
        {
            printf("The target customer name is not found \n");
        }
        else if(result!=0)
        {
            printf("The target customer name is found \n");
            printf("roomID: %d \n",rm[result].roomID);
            printf("customer name: %s \n",rm[result].customerName);
        }
        continue;
    }
}
if(num==5)         
{   
    exit(0);
}        
}

int getnum(int no)
{
    if(no>5 || no<1)
    {   
        printf("Enter your choice:  \n");
        scanf("\n");
        scanf("%d",&no);
        return no;        
    }    
}

void listOccupiedRooms(struct Room rm[]){
    int i,count=0;
    for(i=0;i<5;i++)
    {
        if(rm[i].status==1)
        {
            printf("roomID: %d\ncustomer name: %s\n",rm[i].roomID,rm[i].customerName);
        }
        else
            count+=1;
            if(count ==5)
            {
            printf("The hotel is empty \n");  
            }
    }
}

void assignRoom(struct Room rm[])
{   
    int ID,c;
    char name[20],*p;
    int i,j,bcount=0,full=0;
    for(i=0;i<5;i++)
    {
        if(rm[i].status==0)
        {
            continue;
        }
        else
            bcount+=1;
            if(bcount ==5)
            {
            full = 1;
            printf("The hotel is full \n");
            }
    }
    ID = 0;
    c=0;
    while(full==0) 
    {
        while(ID>5||ID<1)
        {
            printf("Enter a roomID between 1 and 5: \n");
            scanf("%d",&ID);
            if(0<ID<6)
            {
                for (j=0;j<5;j++)
                {
                    if(rm[j].roomID == ID)
                    {   
                        if(rm[j].status ==1)
                        {
                            printf("Occupied! Enter another roomID \n");
                            c=0;
                            full=0;
                            break;
                        }
                        else if(rm[j].status == 0)
                        {
                            printf("Enter customer name:  \n");
                            scanf("\n");
                            fgets(name,80,stdin);
                            if(p=strchr(name,'\n'))*p ='\0';
                            
                            rm[j].status = 1;
                            strcpy(rm[j].customerName,name);
                            printf("The room has been assigned successfully \n");
                            full=1;
                            c=1;
                            break;
                        }
                    }
                }
            }
        if(c==0)
        {
            ID = 0;
            continue;
        }
        else
            break;
        }   
    break;
    }
}

void removeRoom(struct Room rm[])
{   
    int ID,c;
    int i,j,bcount=0,empty=0;
    for(i=0;i<5;i++)
    {
        if(rm[i].status==1)
        {
            continue;
        }
        else
            bcount+=1;
            if(bcount ==5)
            {
            empty = 1;
            printf("All the rooms are empty \n");
            }
    }
    ID = 0;
    c=0;
    while(empty==0) 
    {
        while(ID>5||ID<1)
        {
            printf("Enter a roomID between 1 and 5: \n");
            scanf("%d",&ID);
            if(0<ID<6)
            {
                for (j=0;j<5;j++)
                {
                    if(rm[j].roomID == ID)
                    {   
                        if(rm[j].status ==0)
                        {
                            printf("Empty! Enter another roomID for removal \n");
                            c=0;
                            empty=0;
                            break;
                        }
                        else if(rm[j].status == 1)
                        {
                            rm[j].status = 0;
                            rm[j].customerName[0] = '\0';      
                            printf("Removal is successful \n");
                            empty=1;
                            c=1;
                            break;
                        }
                    }
                }
            }
        if(c==0)
        {
            ID = 0;
            continue;
        }
        else
            break;
        }   
    break;
    }
}

int findCustomer(struct Room *rm)
{   
    int i,j,len;
    char target[80], *p;
    char original[80];      //original

    scanf("\n");
    fgets(target,80,stdin);
    if(p=strchr(target,'\n'))*p='\0';

    modify(target);
    len=strlen(target);

    for(i=0;i<5;i++)
    {
        if(rm[i].status==1)
        {
            strcpy(original, rm[i].customerName);
    
            modify(original);
        
            if(strcmp(original,target)==0)
            { 
                return i;
            }
        }
    }
    return -1;
}

void modify(char*str)
{
    while(*str!='\0')
    {
        if(islower(*str))
            *str = toupper(*str);
        str++;
    }
}