#include <stdio.h>
#include <stdlib.h>

void flagfunction (char pos[3],int *firstflag, int* secondflag, char letter[8], char digit[8])
{
    int i = 0;
    printf("%d", sizeof(digit));
    for (i=0; i<= sizeof(letter)*2-1; i++)
    {
        if(pos[0]==letter[i])
            {*firstflag=1;
           // printf("pos[0] == letter[i]!");
            break;}

        printf("%c",letter[i]);
    }

    for (i=0; i<= sizeof(digit)*2-1; i++)
    {
        if(pos[1]==digit[i])
            {*secondflag=1;
          //  printf("pos[1] == digit[i]!");
            break;}
        printf("%c",digit[i]);
    }
    return 0;
}

int main()
{
    system("chcp 1251");
    int i = 0;
    char pos_king[3], pos_ladya1[3], pos_ladya2[3], pos_ladya3[3];
    char letter[8] = "abcdefgh";
    char digit[8] = "12345678";
    int firstflag=0, secondflag=0;
    int rightannotationflag=0;

    // ����� ������ - 0 �� �������, 1 ������� �� ����� ����, ������� �� ����� ����
    int first_ladya_attack_flag=0;
    int second_ladya_attack_flag=0;
    int third_ladya_attack_flag=0;

    while(rightannotationflag!=1)
 {

    printf("������� ������� ������ ��������� ����������� ������, �������� e2\n");
    scanf("%s", pos_king);

     flagfunction(pos_king,&firstflag, &secondflag, letter, digit);

    if ((firstflag==1)&&(secondflag==1)&&(pos_king[2]=='\0'))
    {
        rightannotationflag=1;
        printf("���� ���������, ����������\n");
        printf("Third symbol is %c\n", pos_king[2]);
        firstflag = 0;
        secondflag = 0;
        rightannotationflag = 0;
        break;
    }
    else
        rewind(stdin);
}

     while(rightannotationflag!=1)
 {

    printf("������� ������� ������ �����, ��������� ����������� ������, �������� e2\n");
    scanf("%s", pos_ladya1);


    flagfunction(pos_ladya1,&firstflag, &secondflag, letter, digit);

    if ((firstflag==1)&&(secondflag==1)&&(pos_ladya1[2]=='\0'))
    {printf("������� ������ �����: %s\n", pos_ladya1);
        if((pos_king[0]==pos_ladya1[0])&&(pos_king[1]==pos_ladya1[1]))
        {
            printf("�� ����� � ��� �� ������ �� ����� ������ ��� ������\n");
            continue;
        }
        else{
            rightannotationflag=1;
            printf("���� ���������, ����������\n");
            printf("Third symbol is %c\n", pos_ladya1[2]);
            firstflag = 0;
            secondflag = 0;
            rightannotationflag = 0;
            break;
        }
    }
    else
        rewind(stdin);
}

     while(rightannotationflag!=1)
 {

    printf("������� ������� ������ �����, ��������� ����������� ������, �������� e2\n");
    scanf("%s", pos_ladya2);

    flagfunction(pos_ladya2,&firstflag, &secondflag, letter, digit);

    if ((firstflag==1)&&(secondflag==1)&&(pos_ladya2[2]=='\0'))
    {
        if(((pos_king[0]==pos_ladya2[0])&&(pos_king[1]==pos_ladya2[1]))||(((pos_ladya1[0])==pos_ladya2[0])&&(pos_ladya1[1]==pos_ladya2[1])))
        {
            printf("�� ����� � ��� �� ������ �� ����� ������ ��� ������\n");
            continue;
        }
        else{
            rightannotationflag=1;
            printf("���� ���������, ����������\n");
            printf("Third symbol is %c\n", pos_ladya2[2]);
            firstflag = 0;if(third_ladya_attack_flag==2)
    {
        printf("������ �����, ����������� �� ������� %s ������\n", pos_ladya3);
    }
            secondflag = 0;
            rightannotationflag = 0;
            break;
        }
    }
    else
        rewind(stdin);
}

     while(rightannotationflag!=1)
 {

    printf("������� ������� ������� �����, ��������� ����������� ������, �������� e2\n");
    scanf("%s", pos_ladya3);

    flagfunction(pos_ladya3,&firstflag, &secondflag, letter, digit);

    if ((firstflag==1)&&(secondflag==1)&&(pos_ladya3[2]=='\0'))
    {
        if(((pos_king[0]==pos_ladya3[0])&&(pos_king[1]==pos_ladya3[1]))||(((pos_ladya1[0])==pos_ladya3[0])&&(pos_ladya1[1]==pos_ladya3[1]))||(((pos_ladya2[0])==pos_ladya3[0])&&(pos_ladya2[1]==pos_ladya3[1])))
        {
            printf("�� ����� � ��� �� ������ �� ����� ������ ��� ������\n");
            continue;
        }
        else{
            rightannotationflag=1;
            printf("���� ���������, ����������\n");
            printf("Third symbol is %c\n", pos_ladya3[2]);
            firstflag = 0;
            secondflag = 0;
            rightannotationflag = 0;
            break;
        }
    }
    else
        rewind(stdin);
}


    printf("������� ������� ������: %s\n", pos_king);
    printf("������� ������ �����: %s\n", pos_ladya1);
    printf("������� ������ �����: %s\n", pos_ladya2);
    printf("������� ������� �����: %s\n", pos_ladya3);

    //����������� � ��������� ����� �����
    printf("������ ������� ����� \n");

    if (pos_king[0]==pos_ladya1[0])
        first_ladya_attack_flag=1;
    else if (pos_king[1]==pos_ladya1[1])
        first_ladya_attack_flag=2;
    else
        first_ladya_attack_flag=0;

    if (pos_king[0]==pos_ladya2[0])
        second_ladya_attack_flag=1;
    else if (pos_king[1]==pos_ladya2[1])
        second_ladya_attack_flag=2;
    else
        second_ladya_attack_flag=0;

    if (pos_king[0]==pos_ladya3[0])
        third_ladya_attack_flag=1;
    else if (pos_king[1]==pos_ladya3[1])
        third_ladya_attack_flag=2;
    else
        third_ladya_attack_flag=0;

    if (third_ladya_attack_flag==2&&second_ladya_attack_flag==2&&first_ladya_attack_flag==2)
       {
           printf("��� ��� ����� ����������� �� ����� ����� �� ������� ���� � ����� ������ �� ��� ������� ������\n");
           if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya2[0]&&pos_king[0]<pos_ladya3[0])
           {
                printf("��� ��� ��������� ����� ������ �� ������\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya2[0])
                   {
                       min = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

                if (min>pos_ladya3[0])
                {
                    min = pos_ladya3[0];
                    second_ladya_attack_flag=0;
                }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya2[0]&&pos_king[0]>pos_ladya3[0])
           {
                printf("��� ��� ��������� ����� ����� �� ������\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya2[0])
                   {
                       max = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

                if (max<pos_ladya3[0])
                {
                    max = pos_ladya3[0];
                    second_ladya_attack_flag=0;
                }
                else
                    third_ladya_attack_flag=0;
           }

           else if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya2[0]&&pos_king[0]>pos_ladya3[0])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya2[0])
                   {
                       min = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;
           }

           else if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya3[0]&&pos_king[0]>pos_ladya2[0])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya3[0])
                   {
                       min = pos_ladya3[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[0]<pos_ladya2[0]&&pos_king[0]<pos_ladya3[0]&&pos_king[0]>pos_ladya1[0])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int min = pos_ladya2[0];
                if (min>pos_ladya3[0])
                   {
                       min = pos_ladya3[0];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }

           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya2[0]&&pos_king[0]<pos_ladya3[0])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya2[0])
                   {
                       max = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;
           }

           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya3[0]&&pos_king[0]<pos_ladya2[0])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya3[0])
                   {
                       max = pos_ladya3[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[0]>pos_ladya2[0]&&pos_king[0]>pos_ladya3[0]&&pos_king[0]<pos_ladya1[0])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int max = pos_ladya2[0];
                if (max>pos_ladya3[0])
                   {
                       max = pos_ladya3[0];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
       }

    else if (first_ladya_attack_flag==2&&second_ladya_attack_flag==2)
       {
        printf("��� ����� ����������� �� ����� ����� �� ������� ���� � ����� ������ �� ��� ������� ������\n");
           if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya2[0])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya2[0])
                   {
                       min = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;


           }

           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya2[0])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya2[0])
                   {
                       max = pos_ladya2[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

           }
           else
            printf("��� ��������� ����� ����������� �� ��� ������� �� ������\n");
       }

       else if (first_ladya_attack_flag==2&&third_ladya_attack_flag==2)
       {
        printf("��� ����� ����������� �� ����� ����� �� ������� ���� � ����� ������ �� ��� ������� ������\n");
           if (pos_king[0]<pos_ladya1[0]&&pos_king[0]<pos_ladya3[0])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int min = pos_ladya1[0];
                if (min>pos_ladya3[0])
                   {
                       min = pos_ladya3[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;


           }

           else if (pos_king[0]>pos_ladya1[0]&&pos_king[0]>pos_ladya3[0])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int max = pos_ladya1[0];
                if (max<pos_ladya3[0])
                   {
                       max = pos_ladya3[0];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;

           }
           else
            printf("��� ��������� ����� ����������� �� ��� ������� �� ������\n");
       }

       else if (second_ladya_attack_flag==2&&third_ladya_attack_flag==2)
       {
        printf("��� ����� ����������� �� ����� ����� �� ������� ���� � ����� ������ �� ��� ������� ������\n");
           if (pos_king[0]<pos_ladya2[0]&&pos_king[0]<pos_ladya3[0])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int min = pos_ladya2[0];
                if (min>pos_ladya3[0])
                   {
                       min = pos_ladya3[0];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;


           }

           else if (pos_king[0]>pos_ladya2[0]&&pos_king[0]>pos_ladya3[0])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int max = pos_ladya2[0];
                if (max<pos_ladya3[0])
                   {
                       max = pos_ladya3[0];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;

           }
           else
            printf("��� ��������� ����� ����������� �� ��� ������� �� ������\n");
       }

      if (third_ladya_attack_flag==1&&second_ladya_attack_flag==1&&first_ladya_attack_flag==1)
       {
           printf("��� ��� ����� ����������� �� ����� ����� �� ������� ���� � ����� ������ �� ��� ������� ������\n");
           if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya2[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("��� ��� ��������� ����� ������ �� ������\n");
                int max = pos_ladya1[1];
                if (max<pos_ladya2[1])
                   {
                       max = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

                if (max<pos_ladya3[1])
                {
                    max = pos_ladya3[1];
                    second_ladya_attack_flag=0;
                }
                else
                    third_ladya_attack_flag=0;
                    //ok
           }
           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya2[1]&&pos_king[1]<pos_ladya3[1])
           {
                printf("��� ��� ��������� ����� ����� �� ������\n");
                int min = pos_ladya1[1];
                if (min>pos_ladya2[1])
                   {
                       min = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

                if (min>pos_ladya3[1])
                {
                    min = pos_ladya3[1];
                    second_ladya_attack_flag=0;
                }
                else
                    third_ladya_attack_flag=0;
                    //ok
           }
// ������ �������������
           else if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya2[1]&&pos_king[1]<pos_ladya3[1])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int max = pos_ladya1[1];
                if (max<pos_ladya2[1])
                   {
                       max = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;
           }

           else if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya3[1]&&pos_king[1]<pos_ladya2[1])
           {
                printf("��� ��������� ����� ������ �� ������\n");


                int max = pos_ladya1[1];
                if (max<pos_ladya3[1])
                   {
                       max = pos_ladya3[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[1]>pos_ladya2[1]&&pos_king[1]>pos_ladya3[1]&&pos_king[1]<pos_ladya1[1])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int max = pos_ladya2[1];
                if (max<pos_ladya3[1])
                   {
                       max = pos_ladya3[1];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }

           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya2[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int min = pos_ladya1[1];
                if (min>pos_ladya2[1])
                   {
                       min = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;
           }

           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya3[1]&&pos_king[1]>pos_ladya2[1])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int min = pos_ladya1[1];
                if (min>pos_ladya3[1])
                   {
                       min = pos_ladya3[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else if (pos_king[1]<pos_ladya2[1]&&pos_king[1]<pos_ladya3[1]&&pos_king[1]>pos_ladya1[1])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int min = pos_ladya2[1];
                if (min>pos_ladya3[1])
                   {
                       min = pos_ladya3[1];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
       }


       else if (first_ladya_attack_flag==1&&second_ladya_attack_flag==1)
       {
        printf("��� ����� ����������� �� ����� ����� �� ������� ���� � ����� ������ �� ��� ������� ������\n");
           if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya2[1])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int max = pos_ladya1[1];
                if (max<pos_ladya2[1])
                   {
                       max = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;


           }

           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya2[1])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int min = pos_ladya1[1];
                if (min>pos_ladya2[1])
                   {
                       min = pos_ladya2[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    second_ladya_attack_flag=0;

           }
           else
            printf("��� ��������� ����� ����������� �� ��� ������� �� ������\n");
       }

       else if (first_ladya_attack_flag==1&&third_ladya_attack_flag==1)
       {
        printf("��� ����� ����������� �� ����� ����� �� ������� ���� � ����� ������ �� ��� ������� ������\n");
           if (pos_king[1]>pos_ladya1[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int max = pos_ladya1[1];
                if (max<pos_ladya3[1])
                   {
                       max = pos_ladya3[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;


           }

           else if (pos_king[1]<pos_ladya1[1]&&pos_king[1]<pos_ladya3[1])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int min = pos_ladya1[1];
                if (min<pos_ladya3[1])
                   {
                       min = pos_ladya3[1];
                       first_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;
           }
           else
            printf("��� ��������� ����� ����������� �� ��� ������� �� ������\n");
       }

       else if (second_ladya_attack_flag==1&&third_ladya_attack_flag==1)
       {
        printf("��� ����� ����������� �� ����� ����� �� ������� ���� � ����� ������ �� ��� ������� ������\n");
           if (pos_king[1]>pos_ladya2[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("��� ��������� ����� ������ �� ������\n");
                int max = pos_ladya2[1];
                if (max<pos_ladya3[1])
                   {
                       max = pos_ladya3[1];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;


           }

           else if (pos_king[1]>pos_ladya2[1]&&pos_king[1]>pos_ladya3[1])
           {
                printf("��� ��������� ����� ����� �� ������\n");
                int min = pos_ladya2[1];
                if (min<pos_ladya3[1])
                   {
                       min = pos_ladya3[1];
                       second_ladya_attack_flag=0;
                   }
                else
                    third_ladya_attack_flag=0;

           }
           else
            printf("��� ��������� ����� ����������� �� ��� ������� �� ������\n");
       }




    if(first_ladya_attack_flag==2)
    {
        printf("������ �����, ����������� �� ������� %s ������ �� �����������\n", pos_ladya1);
    }
    else if(first_ladya_attack_flag==1)
    {
        printf("������ �����, ����������� �� ������� %s ������ �� ���������\n", pos_ladya1);
    }
    if(second_ladya_attack_flag==2)
    {
        printf("������ �����, ����������� �� ������� %s ������ �� �����������\n", pos_ladya2);
    }
    else if(second_ladya_attack_flag==1)
    {
        printf("������ �����, ����������� �� ������� %s ������ �� ���������\n", pos_ladya2);
    }
    if(third_ladya_attack_flag==2)
    {
        printf("������ �����, ����������� �� ������� %s ������ �� �����������\n", pos_ladya3);
    }
    else if(third_ladya_attack_flag==1)
    {
        printf("������ �����, ����������� �� ������� %s ������ �� ���������\n", pos_ladya3);
    }


    printf("Hello world!\n");
    return 0;
}
