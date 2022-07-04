#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int z=15;  //Number of element in array
char book[500][50]= {"Spider-man","knight","hero","small","oxen","will","knit","block","guest","Kamehameha","Yearbook","Yes Man:The Untold Story of Rana Kapoor","The Little Book Of Encourafement","Whereabouts","Ayodhya"}; //Book database yet to bo initilized
char auth[500][50]={"Stan Lee","Jeff","Larry Lieber","Kishimoto","Joseph Murphy","Ash","Misty","Brock","Naruto","Goku","Seth Rogen","Pavan C.Lall","Dalai Lama","Jhumpa Lahiri","Madhav Bhandari"};
int yr[500]={1964,2000,1990,1978,1976,2012,2000,2020,2007,2000,2021,2021,2021,2021,2020};
long long int isbnarr[500]={1454131321547,2425632148975,3154789632456,4214753968541,5223214541669,6457896354214,7555668745214,8897547821456,1234567890123,1010455478875,5465445646865,4545688625347,6549841213465,5486464544546,1111245565456}; //Initialize all the values of isbn here, give atleast 15 values
int name();
void isbn(long long int);
int author();
int year(int);
int open();
int final(int);
void main()
{
    printf("Welcome to the library.\n");
    printf("How do you want to seacrh for the book.\n");
    printf("1. ISBN number\n2. Name of author\n3. Year of Publication\n4. Name of the books\n5. Open the compelete library catalog\n");
    printf("Enter your choice \n");
    int ch=0,pub;     //ch input for choice, pub is for publication year,
    scanf("%d",&ch);
    long long int i;   //isbn input
    switch(ch)
    {
        case 1:
        printf("Enter ISBN-13 number : ");
        scanf("%lld",&i);
        isbn(i);
        break;
        case 2:
        final(author());
        break;
        case 3:
        printf("Enter the year of publication : ");
        scanf("%d",&pub);
        final(year(pub));
        break;
        case 4:
        final(name());
        break;
        case 5:
        final(open());
        break;
        default:
        printf("Invalid Entry!!");
    }
}
void isbn(long long int n)
{
    int i;
    for(i=0;i<z;i++)
    {
        if(n==isbnarr[i])
        {
            printf("%s by %s\n",book[i],auth[i]);
            break;
        }
    }
    if(i==z)
    printf("\nBook not found !");
    else
    final(i);
}
int name()
{
    int i;
    char str[50];
    printf("Enter the name of book you want to search. ");
    scanf("%s",str);
    for (i = 0; i < z; ++i)
    {
        if (!strcasecmp(str, book[i])) 
        {
            break;
        }
	}
    if (i != 50) 
    {
		printf("%s is present in the library at index %d", str, i);
        return i;
	}
	else 
    {
		printf("%s is not present in the library", str);
        return 0;
	}
}
int author()
{
    bool check=false;
    int i,idx[z],id;
    char str[50];
    printf("Enter the name of the author book you want to search. ");
    scanf("%s",str);
    for (i = 0; i < z; ++i)
    {
        idx[i]=0;
        if (!strcmp(str, auth[i])) 
        {
            idx[i]=i;
        }
	}
    for(i=0;i<z;i++)
    {
        if(idx[i]!=0)
        {
            check=true;
            printf("%d. %s by %s\n",i+1,book[i],auth[i]);
        }
    }
    if(check==false)
    {
        printf("\nThere is no book avaliable with this credentials.");
        return 0;
    }
    printf("\nEnter the index of the book if avaliable or else enter 0. ");
    scanf("%d",&id);
    if(id==0)
    return 0;
    else
    return (id-1);
}
int year(int y)
{
    int i,yid[z],idx=0;
    bool check=false;
    for(i=0;i<z;i++)
    {
        if(y==yr[i])
        {
            yid[i]=i;
            check=true;
        }
        else
        yid[i]=-1;
    }
    if(check==true)
    {
        printf("\nBooks published in the year %d present in the library are :\n",y);
        for(i=0;i<z;i++)
        {
            if(yid[i]>-1)
            printf("%d. %s by %s\n",i+1,book[i],auth[i]);
        }
        if(check==true)
        {
            printf("\nEnter the the index of the book if avaliavle or enter 0 to exit. ");
            scanf("%d",&idx);
        }
    }
    else
    printf("\nThere is no books avaliable with entered years. \n");
    if(idx==0)
    return 0;
    else
    return (idx-1);
}
int open()
{
    int idx;
    printf("All books present in the library are : \n");
    int i;
    for(i=0;i<z;i++)
    {
        printf("%d. %s by %s\n",i+1,book[i],auth[i]);
    }
    printf("Enter the the index of the book if avaliavle or enter 0 to exit. ");
    scanf("%d",&idx);
    if(idx==0)
    return 0;
    else
    return (idx-1);
}
int final(int n)
{
    if(n!=0)
    {
        printf("\nYou have choosen %s by %s published in %d with ISBN %lld.",book[n],auth[n],yr[n],isbnarr[n]);
        char c;
        int ch;
        printf("\nEnter anything to confirm or n cancel. \n");
        scanf(" %c",&c);
        if(c=='n')
        {
            printf("\nThanks you !\n");
            return 0;
        }
        printf("\nWhat would you like to do?\n");
        printf("\n1. Read here\n2. Rent\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Please collect your book through counter.\nThank you!");
            break;
            case 2:
            printf("Please collect your book along with the slip through counter.\n");
            printf("\n\n***PLEASE NOTE***\n");
            printf("This book can only be rented for 7 days and 14 days for standerd members and premium members respectively.\nIf failed to return on time then fine will be charged accordingly.");
            break;
            default:
            printf("\nInvalid input!");
        }
    }
    else
    {
        printf("Do you want to order the book ?\nY/N\n");
        char ch;
        scanf(" %c",&ch);
        long long int isbn;
        char name[50],auth[50];
        int year;
        switch(ch)
        {
            case 'y':
            case 'Y':
            printf("Please enter the following credentials to order the book. Enter 0 if the credential is unknown. \n");
            printf("ISBN : ");
            scanf("%lld",&isbn);
            printf("Name : ");
            scanf(" %s",name);
            printf("Author : ");
            scanf(" %s",auth);
            printf("Year of publication : ");
            scanf(" %d",year);
            break;
            case 'n':
            case 'N':
            printf("You have chosen not to order book.");
            break;
            default:
            printf("Invalid input!");
        }
        printf("\nThank you!");
    }
}