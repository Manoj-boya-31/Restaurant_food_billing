#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items
{
    char item[100];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

enum etype{
    display = 0,
    store = 1
};

//functions to generate bills
void generateBillHeader(char name[50],char date[30], enum etype type, FILE *fp)
{
    if(type == display)
    {
    printf("\n\n");
        printf("\tMANOJ'S FAMILY RESTAURANT");
        printf("\n\t  --------------------------");
        printf("\nDate:%s",date);
        printf("\n");
        printf("-----------------------------------------------------------------------\n");
        printf("Items                            \t\t");
        printf("       Total\t\t");
        printf("\n-----------------------------------------------------------------------");
        printf("\n\n");
    }
    else if(type == store)
    {
        fprintf(fp,"\nDate:%s",date);
        fprintf(fp,"\n");
        fprintf(fp,"---------------------------------------\n");
        fprintf(fp,"Items\t\t");
        fprintf(fp,"Total\t\t");
        fprintf(fp,"\n---------------------------------------");
        fprintf(fp,"\n\n");
    }
}

void generateBillBody(char item[30],int qty, float price, enum etype type, FILE *fp)
{
    if(type == display)
    {
    printf("%s\t\t",item); 
        printf("%d\t\t",qty); 
        printf("%.2f\t\t",qty * price); 
        printf("\n");
    }
    else if(type == store)
    {
        fprintf(fp,"%s\t\t",item); 
        fprintf(fp,"%d\t\t",qty); 
        fprintf(fp,"%.2f\t\t",qty * price); 
        fprintf(fp,"\n");
    }
}

void generateBillFooter(float total,enum etype type, FILE *fp)
{
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;//netTotal + cgst + sgst
    if(type == display)
    {
        printf("\n");
        float dis = 0.1*total;
        float netTotal=total-dis;
        float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;//netTotal + cgst + sgst
        printf("---------------------------------------\n");
        printf("Sub Total\t\t\t%.2f",total);
        printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
        printf("\n\t\t\t\t-------");
        printf("\nNet Total\t\t\t%.2f",netTotal);
        printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
        printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
        printf("\n---------------------------------------");
        printf("\nGrand Total\t\t\t%.2f",grandTotal);
        printf("\n---------------------------------------\n");
    }
    else if(type == store)
    {
        fprintf(fp,"\n");
        fprintf(fp,"---------------------------------------\n");
        fprintf(fp,"Sub Total\t\t\t%.2f",total);
        fprintf(fp,"\nDiscount @10%s\t\t\t%.2f","%",dis);
        fprintf(fp,"\n\t\t\t\t-------");
        fprintf(fp,"\nNet Total\t\t\t%.2f",netTotal);
        fprintf(fp,"\nCGST @9%s\t\t\t%.2f","%",cgst);
        fprintf(fp,"\nSGST @9%s\t\t\t%.2f","%",cgst);
        fprintf(fp,"\n---------------------------------------");
        fprintf(fp,"\nGrand Total\t\t\t%.2f",grandTotal);
        fprintf(fp,"\n---------------------------------------\n");
    }
}
int main()
{
    
    int opt,n,choose;
    struct orders ord;
    struct orders order;
    char saveBill = 'y',contFlag = 'y';
    char name[50];
    FILE *fp;
       //dashboard
while(contFlag == 'y')
{
    system("clear");
    float total = 0;
    int invoiceFound = 0;
    printf("\t============MANOJ'S FAMILY RESTAURANT============");
    printf("\n\nPlease select your prefered operation");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Show all Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);
    switch(opt)
    {
        case 1:
        system("clear");
        printf("\nPlease enter the name of the customer:\t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1] = 0;
        strcpy(ord.date,_DATE_);
        printf("1.Chinese egg noodles with schezwan masala\n");
        printf("2.Panner 65 with butter nann\n");
        printf("3.South-Indian mushroom fry\n");
        printf("4.Chicken fillet burger=Rs:120\n");
        printf("5.Peppy paneer pizza=Rs:90\n");                
        printf("6.Margherita pizza=Rs:135\n");
        printf("7.Mexican green wave pizza=Rs:145\n");
        printf("8.Chettinad Prawn fry=Rs:190\n");
        printf("9.BBQ chicken roast=Rs:230\n");
        printf("10.Hyderabadi Bawarchi Mutton dum biryani=Rs:330\n");
        printf("11.Tangdi kebab=Rs:250\n");
        printf("12.BBQ Chicken Biryani=Rs:280\n");
        printf("13.Marinated Grilled Flank Steak=Rs:215\n");
        printf("14.KFC smoke grilled chicken=Rs:185\n");
        printf("15.Maple-Glazed Salmon=Rs:245\n");
        printf("any other number to exit\n");
        n = 0;
        for(;;)
        {
            fgetc(stdin);
            printf("\n\n");
           // printf("Please enter the item %d:\t",i+1);
           // fgets(ord.itm[i].item,20,stdin);
           // ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
           printf("please enter choice of your item %d\t",n+1);
            scanf("%d",&choose);
            if (choose < 1 || choose > 15) 
            {
                ord.numOfItems = n;
                break;
            }
            switch (choose)
            {
            case 1 : ord.itm[n].price=1365;
					 memcpy(&ord.itm[n].item[0],"crotch blue wear jeans skinny         1365",30);
                      break;
            case 2 : ord.itm[n].price=973;
                     memcpy(&ord.itm[n].item[0],"showoff t-shirt white typography      973",30);
                       break;
            case 3 : ord.itm[n].price=841;
                     memcpy(&ord.itm[n].item[0],"D-look jeans denim fit fashion        841",30);
                    break;
            case 4 : ord.itm[n].price=120;
                     memcpy(&ord.itm[n].item[0],"Chicken fillet burger",30);
                    break;
            case 5 : ord.itm[n].price=90;
                     memcpy(&ord.itm[n].item[0],"Peppy paneer pizza",30);
                     break;
            case 6 : ord.itm[n].price=135;
                     memcpy(&ord.itm[n].item[0],"Margherita pizza",30);
                      break;
            case 7 : ord.itm[n].price=145;
                     memcpy(&ord.itm[n].item[0],"Mexican green wave pizza",30);
                       break;
            case 8 : ord.itm[n].price=190;
                     memcpy(&ord.itm[n].item[0],"Chettinad Prawn fry",30);
                        break;
            case 9 : ord.itm[n].price=230;
                     memcpy(&ord.itm[n].item[0],"BBQ chicken roast",30);
                        break;
            case 10 : ord.itm[n].price=330;
                     memcpy(&ord.itm[n].item[0],"Hyderabadi Bawarchi Mutton dum biryani",30);
                        break;
            case 11 : ord.itm[n].price=250;
                     memcpy(&ord.itm[n].item[0],"Tangdi kebab",30);
                        break;
            case 12 : ord.itm[n].price=280;
                     memcpy(&ord.itm[n].item[0],"BBQ Chicken Biryani",30);
                        break;
            case 13 : ord.itm[n].price=215;
                     memcpy(&ord.itm[n].item[0],"Marinated Grilled Flank Steak",30);
                        break;
            case 14 : ord.itm[n].price=185;
                     memcpy(&ord.itm[n].item[0],"KFC smoke grilled chicken",30);
                        break;
            case 15 : ord.itm[n].price=245;
                     memcpy(&ord.itm[n].item[0],"Maple-Glazed Salmon",30);
                        break;
            default:
                break;
            }
             printf("Please enter the quantity:\t");
             scanf("%d",&ord.itm[n].qty);
            fgetc(stdin);
            total += ord.itm[n].qty * ord.itm[n].price;
            n++;
        }
        generateBillHeader(ord.customer,ord.date, display, fp);
        for(int i=0;i<ord.numOfItems;i++)
        {
           generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price, display, fp);
        }
        generateBillFooter(total,display,fp);
        printf("\nDo you want to save the invoice [y/n]:\t");
        scanf("%s",&saveBill);
        if(saveBill == 'y')
        {
            fp = fopen("Restaurant2.txt","a");
            generateBillHeader(ord.customer,ord.date, store, fp);
            for(int i=0;i<ord.numOfItems;i++)
            {
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price, store, fp);
            }
            generateBillFooter(total,store,fp);
            fprintf(fp,"%s-ThankYou\n",ord.customer);
            if(fprintf != 0)
            printf("\nSuccessfully saved");
            else 
            printf("\nError saving");
            fclose(fp);
        }
        break;
        case 2:
        system("clear");
        fp = fopen("Restaurant2.txt","r");
        printf("\n  Your Previous Invoices\n");
        int numbytes;
        fseek(fp, 0L, SEEK_END);
        numbytes = ftell(fp);
        fseek(fp, 0L, SEEK_SET); 
        char *buf = (char *)malloc(numbytes*sizeof(char));
        if(fscanf(fp,"%[^\0]",buf))
        {
            printf("\n %s \n", buf);
        }
        free(buf);
        fclose(fp);
        break;
        case 3:
        printf("Enter the name of the customer:\t");
        //fgetc(stdin);
        fgets(name,50,stdin);
        name[strlen(name)-1] = 0;
        system("clear");
        fp = fopen("Restaurant2.txt","r");
        printf("\t*Invoice of %s*",name);
        int numbytes1;
        fseek(fp, 0L, SEEK_END);
        numbytes1 = ftell(fp);
        fseek(fp, 0L, SEEK_SET); 
        char *buf1 = (char *)malloc(numbytes1*sizeof(char));
        if(fscanf(fp,"%[^\0]",buf1))
        {
            char* token = strstr(buf1, name);
            if(token != NULL)
            {
            char* startPtr = token;
            sprintf(name,"%s-ThankYou",name);
            token = strstr(buf1, name);
            *token= '\0';
            printf("\n %s", startPtr);
            invoiceFound = 1;
            }
            else{
                invoiceFound = 0;
            }
        }
        if(!invoiceFound)
        {

            printf("Sorry the invoice for %s doesnot exists",name);
        }
        free(buf1);
        fclose(fp);
        break;
          case 4:
          printf("\n\t\t Bye Bye :)\n\n");
          exit(0);
          break;
          default:
          printf("Sorry invalid option");
          break;
    }
         printf("\nDo you want to perform another operation?[y/n]:\t");
         scanf("%s",&contFlag);
}
    printf("\n\t\t Bye Bye :)\n\n");
    printf("\n\n");
    return 0; 
}
