#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std ;

vector<string>avalue ;
vector<string>cvalue ;

int numberofobject = 0 ;

int findOccurance(string att, string cl)
{
    FILE *fptr;
    char a[100], c[100] ;
    int count = 0 ;
    if ((fptr = fopen("data.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    while (fscanf(fptr, "%s %s", a, c)!= EOF)
    {
        string s = "" ;
        string s2 = "" ;

        for(int i = 0 ; i < strlen(a) ; i++)
        {
            s += a[i] ;
        }
        for(int i = 0 ; i < strlen(c) ; i++)
        {
            s2 += c[i] ;
        }
        if(s == att && s2 == cl)
            count++ ;
    }
    fclose(fptr);
    return count ;
}


int findOccurance2(string cl)
{
    FILE *fptr;
    char a[100], c[100] ;
    int count = 0 ;
    if ((fptr = fopen("data.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    while (fscanf(fptr, "%s %s", a, c)!= EOF)
    {
        string s = "" ;
        string s2 = "" ;
        for(int i = 0 ; i < strlen(c) ; i++)
        {
            s2 += c[i] ;
        }
        if(s2 == cl)
            count++ ;
    }
    fclose(fptr);
    return count ;
}
int main()
{
    string test;
    float prior[10],likelihood[10];
    while(true)
    {
        cout<<"Press (1) for training"<<endl;
        cout<<"Press (2) for testing"<<endl;
        cout<<"Press (3) for exit"<<endl;
        int temp;
        cin>>temp;
        switch(temp)
        {
        case 3:
            if (temp==3)
                return 0;
        case 2:

            cout<<"Enter testing data: ";
            cin>>test;
            if(test!= "small" && test != "big")
                cout<<"Attribute not foune"<<endl;
            if(test=="small")
            {
                cout<<"in small"<<endl;
                FILE *fptr1;
                if ((fptr1 = fopen("prior.txt", "r")) == NULL)   /*file is read here*/
                {
                    printf("Error! opening file");
                    exit(1);
                }


                for(int i=0; i<cvalue.size()*2; i++)
                {
                    fscanf (fptr1, "%f", &prior[i]);
                }
                for(int i=0; i<cvalue.size()*2; i++)
                {
                    // cout<<prior[i]<<endl;
                }
                cout<<"Probablity of dog: "<<prior[0]<<endl;
                cout<<"Probablity of cat: "<<prior[3]<<endl;



                //    FILE *fptr1;
                if ((fptr1 = fopen("likelihood.txt", "r")) == NULL)   /*file is read here*/
                {
                    printf("Error! opening file");
                    exit(1);
                }


                for(int i=0; i<cvalue.size()*2; i++)
                {
                    fscanf (fptr1, "%f", &likelihood[i]);
                }
                for(int i=0; i<cvalue.size()*2; i++)
                {
                    //       cout<<"Likelihood: "<<likelihood[i]<<endl;
                }
                float answer;

                if((prior[0]*likelihood[1])> (prior[3] * likelihood[3]))
                {

                    answer=(prior[0]*likelihood[1]);

                    cout<<answer<<endl;
                    cout<<"DOg"<<endl;
                }
                if((prior[0]*likelihood[1])< (prior[3] * likelihood[3]))
                {

                    answer=(prior[3] * likelihood[3]);
                    cout<<answer<<endl;
                    cout<<"cat"<<endl;
                }



            }

            if(test=="big")
            {
                cout<<"in big"<<endl;
                FILE *fptr1;
                if ((fptr1 = fopen("prior.txt", "r")) == NULL)   /*file is read here*/
                {
                    printf("Error! opening file");
                    exit(1);
                }


                for(int i=0; i<cvalue.size()*2; i++)
                {
                    fscanf (fptr1, "%f", &prior[i]);
                }
                for(int i=0; i<cvalue.size()*2; i++)
                {
                    // cout<<prior[i]<<endl;
                }
                cout<<"Probablity of dog: "<<prior[0]<<endl;
                cout<<"Probablity of cat: "<<prior[3]<<endl;



                //    FILE *fptr1;
                if ((fptr1 = fopen("likelihood.txt", "r")) == NULL)   /*file is read here*/
                {
                    printf("Error! opening file");
                    exit(1);
                }


                for(int i=0; i<cvalue.size()*2; i++)
                {
                    fscanf (fptr1, "%f", &likelihood[i]);
                }
                for(int i=0; i<cvalue.size()*2; i++)
                {
                    //      cout<<"Likelihood: "<<likelihood[i]<<endl;
                }
                float answer;

                if((prior[0]*likelihood[0])> (prior[3] * likelihood[2]))
                {

                    answer=(prior[0]*likelihood[0]);
                    cout<<answer<<endl;
                    cout<<"DOg"<<endl;
                }
                if((prior[0]*likelihood[0])< (prior[3] * likelihood[2]))
                {

                    answer=(prior[3] * likelihood[2]);
                    cout<<"cat"<<endl;
                }



            }
            break;
        case 1:
            char a[100], c[100];
            FILE *fptr;
            if ((fptr = fopen("data.txt", "r")) == NULL)   /*file is read here*/
            {
                printf("Error! opening file");
                exit(1);
            }
            string s = "" ;
            while (fscanf(fptr, "%s %s", a, c)!= EOF)
            {
                //  printf("%s %s", a, c);
                //  printf("\n\n") ;
                numberofobject++ ;
                bool flag = false ;
                string s = "" ;
                for(int i = 0 ; i < strlen(a) ; i++)
                {
                    s += a[i] ;
                    /*char array is converted into string*/
                }
                for(int i = 0 ; i < avalue.size() ; i++)
                {
                    if(s == avalue[i])
                    {
                        flag = true ;
                        /*only hold the identical value of the attribute*/

                    }
                }
                if(!flag)
                    avalue.push_back(s) ;


                flag = false ;
                s = "" ;
                for(int i = 0 ; i < strlen(c) ; i++)
                {
                    s += c[i] ;
                }
                for(int i = 0 ; i < cvalue.size() ; i++)
                {
                    if(s == cvalue[i])
                    {
                        flag = true ;

                    }
                }
                if(!flag)
                    cvalue.push_back(s) ;



            }
            printf("Total data set: %d\n  ", numberofobject) ;

            for(int i = 0 ; i < avalue.size() ; i++)
            {

                //        cout<< avalue[i] << endl ;
            }

            for(int i = 0 ; i < cvalue.size() ; i++)
            {

                //      cout<< cvalue[i] << endl ;
            }


            for(int i = 0 ; i < cvalue.size() ; i++)
            {
                for(int j = 0 ; j < avalue.size() ; j++)
                {
                    int n = findOccurance(avalue[j], cvalue[i]) ;// A and B
                    int m = findOccurance2(cvalue[i]) ;// class
                    //    cout <<"probablity of: "<< cvalue[i] <<": " << (1.00*m) / numberofobject << endl ;
                    /*Prior knowledge*/
                    FILE *fp1,*fp2;
                    fp1 =fopen("prior.txt","a");
                    fprintf(fp1,"%1.2f\n",(1.00*m) / numberofobject);
                    fclose(fp1);


                    double prob = (1.00*n) / m ;
                    //   cout <<"Liklehood : "<< avalue[j] << "|" << cvalue[i] << " = "<< prob << endl ;
                    /*write the likelihood knowledge in likelihood.txt*/
                    fp2 =fopen("likelihood.txt","a");
                    fprintf(fp2,"%1.2f\n",prob);
                    fclose(fp2);

                }
            }

            fclose(fptr);
            break;

            // case 2:
//            string test;
//            cout<<"Enter testing data: ";
//            cin>>test;

        }
    }

    return 0;
}


